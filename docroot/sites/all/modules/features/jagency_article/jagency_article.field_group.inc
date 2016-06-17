<?php
/**
 * @file
 * jagency_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jagency_article_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_about|node|article|form';
  $field_group->group_name = 'group_more_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More about',
    'weight' => '8',
    'children' => array(
      0 => 'field_more_about',
      1 => 'field_more_about_status',
      2 => 'field_more_about_title',
      3 => 'field_more_about_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-more-about field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_more_about|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resource|node|article|form';
  $field_group->group_name = 'group_resource';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Resource',
    'weight' => '6',
    'children' => array(
      0 => 'field_source_image',
      1 => 'field_source_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-resource field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_resource|node|article|form'] = $field_group;

  return $export;
}
