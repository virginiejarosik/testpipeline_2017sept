<?php
/**
 * @file
 * jagency_blog.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function jagency_blog_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['jagency_pages-jagency_topcontent'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'jagency_topcontent',
    'module' => 'jagency_pages',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'jagency' => array(
        'region' => 'topcontent',
        'status' => 1,
        'theme' => 'jagency',
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
