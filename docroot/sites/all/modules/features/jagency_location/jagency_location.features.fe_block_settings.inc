<?php
/**
 * @file
 * jagency_location.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function jagency_location_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['jagency_pages-jagency_super_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'jagency_super_block',
    'module' => 'jagency_pages',
    'node_types' => array(),
    'pages' => 'blog/*
voices',
    'roles' => array(),
    'themes' => array(
      'jagency' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'jagency',
        'weight' => -16,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
