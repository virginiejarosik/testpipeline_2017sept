<?php
/**
 * @file
 * jagency_program.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jagency_program_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_blocks|node|program_details|form';
  $field_group->group_name = 'group_app_blocks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'step_5';
  $field_group->data = array(
    'label' => 'Blocks control',
    'weight' => '52',
    'children' => array(
      0 => 'field_blocks_list',
      1 => 'field_facebook_group',
      2 => 'field_gallery',
      3 => 'field_locations',
      4 => 'field_sponsors',
      5 => 'field_product_video',
      6 => 'field_application_resources',
      7 => 'field_featured_stories',
      8 => 'field_title_featured_stories',
      9 => 'field_application_resource_new',
      10 => 'field_featured_stories_link',
      11 => 'field_storys_promotion',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-app-blocks field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_app_blocks|node|program_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_apply|node|program_details|form';
  $field_group->group_name = 'group_apply';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'step_1';
  $field_group->data = array(
    'label' => 'Apply button',
    'weight' => '21',
    'children' => array(
      0 => 'field_button_text',
      1 => 'field_see_my_story_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-apply field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_apply|node|program_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|program_details|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'step_2';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '32',
    'children' => array(
      0 => 'field_taxonomy_city',
      1 => 'field_taxonomy_country',
      2 => 'field_taxonomy_region',
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
  $export['group_location|node|program_details|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_program|node|program_details|form';
  $field_group->group_name = 'group_program';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program_details';
  $field_group->mode = 'form';
  $field_group->parent_name = 'step_1';
  $field_group->data = array(
    'label' => 'Program',
    'weight' => '18',
    'children' => array(
      0 => 'field_featured_image',
      1 => 'field_main_image',
      2 => 'field_program_logo',
      3 => 'field_program_logo_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-program field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_program|node|program_details|form'] = $field_group;

  return $export;
}
