<?php
/**
 * @file
 * content_lobby_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_lobby_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_components|node|article|form';
  $field_group->group_name = 'group_social_components';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Components',
    'weight' => '14',
    'children' => array(
      0 => 'field_facebook_icon',
      1 => 'field_twitter_icon',
      2 => 'field_google_icon',
      3 => 'field_print_icon',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-social-components field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_social_components|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_components|node|content_lobby|form';
  $field_group->group_name = 'group_social_components';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'content_lobby';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Components',
    'weight' => '43',
    'children' => array(
      0 => 'field_facebook_icon',
      1 => 'field_twitter_icon',
      2 => 'field_google_icon',
      3 => 'field_print_icon',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-social-components field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_social_components|node|content_lobby|form'] = $field_group;

  return $export;
}
