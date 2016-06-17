<?php
/**
 * @file
 * jagency_agent.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jagency_agent_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function jagency_agent_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function jagency_agent_node_info() {
  $items = array(
    'agents_list' => array(
      'name' => t('Agent'),
      'base' => 'node_content',
      'description' => t('Use <em>Agent</em> content used in personal Aliyah block'),
      'has_title' => '1',
      'title_label' => t('Full name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
