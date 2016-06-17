<?php
/**
 * @file
 * content_lobby_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_lobby_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_lobby_feature_node_info() {
  $items = array(
    'content_lobby' => array(
      'name' => t('Content Lobby'),
      'base' => 'node_content',
      'description' => t('Use <em>Content Lobby</em> to create custom page with different content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
