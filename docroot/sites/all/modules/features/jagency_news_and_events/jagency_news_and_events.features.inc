<?php
/**
 * @file
 * jagency_news_and_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jagency_news_and_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function jagency_news_and_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_features_date_format_default().
 */
function jagency_news_and_events_features_date_format_default() {
  $fdf_config = array();

  $fdf_config[] = array(
    'dfid' => 37,
    'format' => 'F jS, Y',
    'type' => 'custom',
    'locked' => 0,
  );
  return $fdf_config;
}

/**
 * Implements hook_features_date_type_default().
 */
function jagency_news_and_events_features_date_type_default() {
  $fdt_config = array();

  $fdt_config[] = array(
    'is_new' => FALSE,
    'module' => '',
    'type' => 'event',
    'title' => 'Event',
    'locked' => 0,
  );
  return $fdt_config;
}

/**
 * Implements hook_node_info().
 */
function jagency_news_and_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Use <em>Event</em> used to create event content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news_events_loby' => array(
      'name' => t('News & Events lobby'),
      'base' => 'node_content',
      'description' => t('Use <em>News & Events lobby</em> to create lobby with ability to control amount of content and type of content to display'),
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
function jagency_news_and_events_weight_features_default_settings() {
  $settings = array();

  $settings['event'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
