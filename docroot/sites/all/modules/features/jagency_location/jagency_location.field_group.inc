<?php
/**
 * @file
 * jagency_location.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jagency_location_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_settings|node|content_location|form';
  $field_group->group_name = 'group_location_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'content_location';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location Settings',
    'weight' => '2',
    'children' => array(
      0 => 'field_location',
      1 => 'field_content_reference',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Location Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Where to display content, can be managed by URL or content reference',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_location_settings|node|content_location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_view_settings|node|content_location|form';
  $field_group->group_name = 'group_view_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'content_location';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Views settings',
    'weight' => '1',
    'children' => array(
      0 => 'field_block',
      1 => 'field_content_list',
      2 => 'group_block_settings',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Views settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'You can choose what to display,
1) Block
2) Views (Content list)',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_view_settings|node|content_location|form'] = $field_group;

  return $export;
}
