<?php

/**
 * @file
 * Views definitions for kalturacuepoints module.
 */

/**
 * Implements hook_views_data().
 */
function kalturacuepoints_views_data() {
  $data = array();
  $data['node']['kaltura_embed'] = array(
    'title' => t('Kaltura Embed'),
    'help' => t('Renders a Kaltura Entry ID as a video embed.'),
    'field' => array(
      'handler' => 'kalturacuepoints_handler_kaltura_embed',
    ),
  );
  return $data;
}
