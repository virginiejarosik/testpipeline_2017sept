<?php
/**
 * @file
 * jagency_partners.features.inc
 */

/**
 * Implements hook_node_info().
 */
function jagency_partners_node_info() {
  $items = array(
    'partners' => array(
      'name' => t('Partners'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'partners_logos' => array(
      'name' => t('Partners logos'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Partner name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
