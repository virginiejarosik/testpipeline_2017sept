<?php
/**
 * @file
 * jagency_facebook.features.inc
 */

/**
 * Implements hook_node_info().
 */
function jagency_facebook_node_info() {
  $items = array(
    'facebook_groups' => array(
      'name' => t('Facebook groups'),
      'base' => 'node_content',
      'description' => t('Use <em>Facebook groups</em> content used to create Facebook groups on Program page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
