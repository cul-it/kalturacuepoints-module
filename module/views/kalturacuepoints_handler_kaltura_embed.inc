<?php

/**
 * @file
 * Definition of kalturacuepoints_handler_kaltura_embed.
 */

/**
 * Description of what my handler does.
 */
class kalturacuepoints_handler_kaltura_embed extends views_handler_field {
  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['field_video_nid'] = array(
      'table' => 'field_data_field_video_nid',
      'field' => 'field_video_nid_value',
    );
  }

  /**
   * Loads additional fields.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Default options form.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['option_a'] = array('default' => '');
    $options['option_b'] = array('default' => '');
    $options['kalturacuepoints_partnerid'] = array('default' => '');

    return $options;
  }

  /**
   * Creates the form item for the options added.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['option_a'] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => $this->options['option_a'],
      '#description' => t('Some description.'),
      '#weight' => -10,
    );

    $form['option_b'] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => $this->options['option_b'],
      '#description' => t('Some description.'),
      '#weight' => -9,
    );
     $form['kalturacuepoints_partnerid'] = array(
      '#type' => 'textfield',
      '#title' => t('Kaltura Partner ID'),
      '#size' => 60,
      '#description' => t('Kaltura Partner ID for the user eg. 111222.'),
      '#default_value' => variable_get('kalturacuepoints_partnerid',  ''),
    );
    $form['kalturacuepoints_subpartnerid'] = array(
      '#type' => 'textfield',
      '#title' => t('Kaltura Sub Partner ID'),
      '#size' => 60,
      '#description' => t('Kaltura Sub Partner ID for the user eg. 11122233.'),
      '#default_value' => variable_get('kalturacuepoints_subpartnerid',  ''),
    );
   $form['kalturacuepoints_playerid'] = array(
      '#type' => 'textfield',
      '#title' => t('Kaltura Player ID'),
      '#size' => 60,
      '#description' => t('Kaltura ID for the video player eg. 1112223.'),
      '#default_value' => variable_get('kalturacuepoints_playerid',  ''),
    );
   $form['kalturacuepoints_player_width'] = array(
      '#type' => 'textfield',
      '#title' => t('Player Width in pixels'),
      '#size' => 60,
      '#description' => t('For the width and media:width of the embed code.'),
      '#default_value' => variable_get('kalturacuepoints_player_width',  '400'),
    );
   $form['kalturacuepoints_player_height'] = array(
      '#type' => 'textfield',
      '#title' => t('Player Height in pixels'),
      '#size' => 60,
      '#description' => t('For the height and media:height of the embed code.'),
      '#default_value' => variable_get('kalturacuepoints_player_height',  '289'),
    );
   $form['kalturacuepoints_entry_id_field'] = array(
      '#type' => 'textfield',
      '#title' => t('Field name for Kalture Entry ID'),
      '#size' => 60,
      '#description' => t('Internal name for the field containing the Kaltura ID for a video.'),
      '#default_value' => variable_get('kalturacuepoints_entry_id_field',  'field_kaltura_entry_id'),
    );
   $form['kalturacuepoints_playtime_field'] = array(
      '#type' => 'textfield',
      '#title' => t('Field name for segment start/stop times'),
      '#size' => 60,
      '#description' => t('Internal name for a Date field where the begin and end times are used to start and stop the video playback.'),
      '#default_value' => variable_get('kalturacuepoints_playtime_field',  'field_playtime'),
    );
   $form['kalturacuepoints_segment_video_reference_field'] = array(
      '#type' => 'textfield',
      '#title' => t('Field name for segment video reference'),
      '#size' => 60,
      '#description' => t('Internal name for a Node Reference field that points to a video node from a segment node.'),
      '#default_value' => variable_get('kalturacuepoints_video_reference_field',  'field_seg_video'),
    );
   $form['kalturacuepoints_no_video_message_field'] = array(
      '#type' => 'textfield',
      '#title' => t('Message to display when there is no video'),
      '#size' => 120,
      '#description' => t('When the block can not find a video to display show this.'),
      '#default_value' => variable_get('kalturacuepoints_no_video_message_field', t('Configure kalturacuepoints block field names or hide this block!')),
    );
  }

  /**
   * Renders the field handler.
   */
  function render($values) {
    return format_string('<div class="@option_a" data-tag="@field_video_nid" data-follow_name="@option_b"></div>', array(
      '@field_video_nid' => $values->field_data_field_video_nid_field_video_nid_value,
      '@option_a' => $this->options['option_a'],
      '@option_b' => $this->options['option_b'],
    ));
  }
}
