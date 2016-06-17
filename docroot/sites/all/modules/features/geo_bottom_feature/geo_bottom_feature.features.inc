<?php
/**
 * @file
 * geo_bottom_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function geo_bottom_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function geo_bottom_feature_node_info() {
  $items = array(
    'geo_phone_number' => array(
      'name' => t('Geo-Phone number'),
      'base' => 'node_content',
      'description' => t('Use to create phone number that displayed by geo location'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'geo_social_networks' => array(
      'name' => t('Geo-social networks'),
      'base' => 'node_content',
      'description' => t('Use to create social networks bottom links'),
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
function geo_bottom_feature_weight_features_default_settings() {
  $settings = array();

  $settings['geo_bottom'] = array(
    'enabled' => 0,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['geo_phone_number'] = array(
    'enabled' => 0,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['geo_social_networks'] = array(
    'enabled' => 1,
    'range' => 10,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
