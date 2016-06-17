<?php
/**
 * @file
 * jagency_locations.features.inc
 */

/**
 * Implements hook_node_info().
 */
function jagency_locations_node_info() {
  $items = array(
    'locations' => array(
      'name' => t('Locations'),
      'base' => 'node_content',
      'description' => t('Use <em>Locations</em> content currently no in use'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
