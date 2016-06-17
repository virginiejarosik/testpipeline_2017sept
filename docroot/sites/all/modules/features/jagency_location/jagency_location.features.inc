<?php
/**
 * @file
 * jagency_location.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jagency_location_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function jagency_location_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function jagency_location_node_info() {
  $items = array(
    'content_location' => array(
      'name' => t('Content Location'),
      'base' => 'node_content',
      'description' => t('Use <em>Content Location</em> this content currently not in use'),
      'has_title' => '1',
      'title_label' => t('Title (not visible)'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function jagency_location_weight_features_default_settings() {
  $settings = array();

  $settings['content_location'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
