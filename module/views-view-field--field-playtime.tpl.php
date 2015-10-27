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
<?php print $output;
  /* Your code goes here. */
  // $data = $row->{$field->field_alias};
  // $out = array('playtime' => $data);
  // dpm($out);
  dpm($output);
  if($output) {
    if (!empty($row->field_field_playtime[0]['raw'])) {
      $raw = $row->field_field_playtime[0]['raw'];
      dpm($raw);
      $hhmmss = array();
      $hhmmss[] = array_pop(explode(' ', $raw->value));
      $hhmmss[] = array_pop(explode(' ', $raw->value2));
      dpm($hhmmss);
      $startend = implode(' ', $hhmmss);
      dpm($startend);
    }
  }
  else {
    dpm('playtime tpl');
  }

?>
