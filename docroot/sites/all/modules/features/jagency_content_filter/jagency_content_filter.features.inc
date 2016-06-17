<?php
/**
 * @file
 * jagency_content_filter.features.inc
 */

/**
 * Implements hook_views_api().
 */
function jagency_content_filter_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function jagency_content_filter_node_info() {
  $items = array(
    'content_filter' => array(
      'name' => t('Content Filter'),
      'base' => 'node_content',
      'description' => t('Use <em>Content Filter</em> to create custom page with content filter'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
