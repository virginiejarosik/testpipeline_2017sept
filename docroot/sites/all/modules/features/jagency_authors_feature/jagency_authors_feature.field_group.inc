<?php
/**
 * @file
 * jagency_authors_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jagency_authors_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_display|user|user|form';
  $field_group->group_name = 'group_display';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Display settings',
    'weight' => '13',
    'children' => array(
      0 => 'field_profile_featured',
      1 => 'field_profile_weight',
      2 => 'field_blog',
      3 => 'field_exclude_from_block',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-display field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_display|user|user|form'] = $field_group;

  return $export;
}
