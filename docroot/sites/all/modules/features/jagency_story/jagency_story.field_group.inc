<?php
/**
 * @file
 * jagency_story.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jagency_story_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apply_button|node|storys|form';
  $field_group->group_name = 'group_apply_button';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'storys';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header Buttons',
    'weight' => '8',
    'children' => array(
      0 => 'field_apply_link',
      1 => 'field_sponsor_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Header Buttons',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-apply-button field-group-fieldset',
        'description' => 'Apply and sponsor buttons',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_apply_button|node|storys|form'] = $field_group;

  return $export;
}
