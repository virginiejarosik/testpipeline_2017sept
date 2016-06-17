<?php
/**
 * @file
 * jagency_iframes.features.inc
 */

/**
 * Implements hook_node_info().
 */
function jagency_iframes_node_info() {
  $items = array(
    'frames' => array(
      'name' => t('Iframe'),
      'base' => 'node_content',
      'description' => t('Use <em>Iframe</em> content to create iframe'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
