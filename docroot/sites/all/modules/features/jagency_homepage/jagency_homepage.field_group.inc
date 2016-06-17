<?php
/**
 * @file
 * jagency_homepage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jagency_homepage_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video|node|slider_item|form';
  $field_group->group_name = 'group_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'slider_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '3',
    'children' => array(
      0 => 'field_video',
      1 => 'field_video_message_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Video',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-video field-group-fieldset',
        'description' => 'Available only at when slider type set to "video"',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_video|node|slider_item|form'] = $field_group;

  return $export;
}
