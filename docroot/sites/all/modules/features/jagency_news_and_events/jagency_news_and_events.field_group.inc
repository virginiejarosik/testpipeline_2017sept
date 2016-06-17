<?php
/**
 * @file
 * jagency_news_and_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jagency_news_and_events_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date|node|event|form';
  $field_group->group_name = 'group_date';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and Time',
    'weight' => '4',
    'children' => array(
      0 => 'field_date',
      1 => 'field_time',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-date field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_date|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_settings|node|event|form';
  $field_group->group_name = 'group_location_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location Settings',
    'weight' => '5',
    'children' => array(
      0 => 'field_address_collection',
      1 => 'field_geo_location',
      2 => 'field_address_event',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-location-settings field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_location_settings|node|event|form'] = $field_group;

  return $export;
}
