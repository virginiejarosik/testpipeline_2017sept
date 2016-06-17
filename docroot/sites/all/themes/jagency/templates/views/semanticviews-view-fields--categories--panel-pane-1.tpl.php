<?php
/**
 * @file semanticviews-view-fields.tpl.php
 * Default simple view template to display all the fields as a row. The template
 * outputs a full row by looping through the $fields array, printing the field's
 * HTML element (as configured in the UI) and the class attributes. If a label
 * is specified for the field, it is printed wrapped in a <label> element with
 * the same class attributes as the field's HTML element.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output
 *     safe.
 *   - $field->element_type: The HTML element wrapping the field content and
 *     label.
 *   - $field->attributes: An array of attributes for the field wrapper.
 *   - $field->handler: The Views field handler object controlling this field.
 *     Do not use var_export to dump this object, as it can't handle the
 *     recursion.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @see template_preprocess_semanticviews_view_fields()
 * @ingroup views_templates
 * @todo Justify this template. Excluding the PHP, this template outputs angle
 * brackets, the label element, slashes and whitespace.
 */
$menuitem = menu_get_item();
$path = '';
module_load_include('module', 'jagency_pages');
switch ($menuitem['path']) {
  case 'blog/%/tag/%':
  case 'blog/%/user/%':
    $path = url('', array('absolute' => true)) . 'blog/' . jagency_pages_get_nid($menuitem['page_arguments'][1]->data) . '/tag/' . $fields['tid']->raw;
    break;
  case 'node/%':
    $path = url('', array('absolute' => true)) . 'blog/' . jagency_pages_get_nid($menuitem['page_arguments'][0]) . '/tag/' . $fields['tid']->raw;
    break;
}
//print '<li>'. l($fields['name']->raw, $path, array('alias' => true)) . '</li>';
print '<li><a href="'.$path.'">'. jagency_taxonomy_translate($fields['tid']->raw, $fields['name']->raw) . '</a></li>';
?>