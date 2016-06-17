<?php
/**
 * @file
 * jagency_maps.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jagency_maps_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events|node|google_map|form';
  $field_group->group_name = 'group_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'google_map';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Events Group',
    'weight' => '10',
    'children' => array(
      0 => 'field_events',
      1 => 'field_events_by_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-events field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_events|node|google_map|form'] = $field_group;

  return $export;
}
