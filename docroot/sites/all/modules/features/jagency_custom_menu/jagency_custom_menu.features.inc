<?php
/**
 * @file
 * jagency_custom_menu.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jagency_custom_menu_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function jagency_custom_menu_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function jagency_custom_menu_node_info() {
  $items = array(
    'custom_menu' => array(
      'name' => t('Custom menu'),
      'base' => 'node_content',
      'description' => t('Use <em>Custom menu</em> content to create and place custom menu on Article/Program/Lobby pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function jagency_custom_menu_weight_features_default_settings() {
  $settings = array();

  $settings['custom_menu'] = array(
    'enabled' => 0,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
