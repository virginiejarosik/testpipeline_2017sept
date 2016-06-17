<?php
/**
 * @file
 * jagency_custom_menu.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jagency_custom_menu_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_location|node|custom_menu|form';
  $field_group->group_name = 'group_menu_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'custom_menu';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Menu Location',
    'weight' => '2',
    'children' => array(
      0 => 'field_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_menu_location|node|custom_menu|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_links|field_collection_item|field_menu_items|form';
  $field_group->group_name = 'group_sub_links';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_menu_items';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sub Links',
    'weight' => '36',
    'children' => array(
      0 => 'field_sub_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sub_links|field_collection_item|field_menu_items|form'] = $field_group;

  return $export;
}
