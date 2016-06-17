<?php
/**
 * @file
 * jagency_careers.features.inc
 */

/**
 * Implements hook_views_api().
 */
function jagency_careers_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function jagency_careers_node_info() {
  $items = array(
    'career' => array(
      'name' => t('Career'),
      'base' => 'node_content',
      'description' => t('Use <em>Career</em> to create career content'),
      'has_title' => '1',
      'title_label' => t('Career Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
