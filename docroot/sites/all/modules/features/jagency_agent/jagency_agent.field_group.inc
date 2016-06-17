<?php
/**
 * @file
 * jagency_agent.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jagency_agent_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agent|node|agents_list|form';
  $field_group->group_name = 'group_agent';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'agents_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Agent',
    'weight' => '4',
    'children' => array(
      0 => 'field_email',
      1 => 'field_phone',
      2 => 'field_email_form',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-agent field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_agent|node|agents_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_helpcenter|node|agents_list|form';
  $field_group->group_name = 'group_helpcenter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'agents_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Help Center',
    'weight' => '5',
    'children' => array(
      0 => 'field_help_center_phone',
      1 => 'field_help_center_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-helpcenter field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_helpcenter|node|agents_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|agents_list|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'agents_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '3',
    'children' => array(
      0 => 'field_address',
      1 => 'field_taxonomy_city',
      2 => 'field_taxonomy_country',
      3 => 'field_aliah_country',
      4 => 'field_aliah_city',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-location field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_location|node|agents_list|form'] = $field_group;

  return $export;
}
