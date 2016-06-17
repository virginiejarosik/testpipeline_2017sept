<?php
/**
 * @file
 * jagency_maps.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function jagency_maps_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['jagency_pages-jagency_google_map_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'jagency_google_map_block',
    'module' => 'jagency_pages',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'jagency' => array(
        'region' => 'google_map',
        'status' => 1,
        'theme' => 'jagency',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
