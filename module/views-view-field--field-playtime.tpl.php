<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
  /*
  $row->field_field_playtime[0]['raw'] contains the UTF version of the start and end time.
  format like this: 00:11:11 to 00:15:12
  */
  dpm($output);
  if($output) {
    dsm($row);
    $data = $row->{$field->field_alias};
    dsm($data);
    //dsm($field);
    if (!empty($row->field_field_playtime[0]['raw'])) {
      $raw = $row->field_field_playtime[0]['raw'];
      dpm($raw);
      $hhmmss = array();
      $hhmmss[] = array_pop(explode(' ', $raw['value']));
      $hhmmss[] = 'to';
      $hhmmss[] = array_pop(explode(' ', $raw['value2']));
      dpm($hhmmss);
      $startend = implode(' ', $hhmmss);
      dpm($startend);
      $output = $startend;
      print $output;
    }
  }

?>
