<?php
/**
 * @file
 * jagency_location.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function jagency_location_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_block'
  $field_bases['field_block'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 0,
        'comment' => 0,
        'diff' => 0,
        'domain' => 0,
        'domain_alias' => 0,
        'domain_conf' => 0,
        'domain_nav' => 0,
        'facebook_comments_box' => 0,
        'jagency_pages' => 0,
        'locale' => 0,
        'menu' => 0,
        'node' => 0,
        'panels_mini' => 0,
        'profile' => 0,
        'search' => 0,
        'shortcut' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 0,
        'webform' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'banner' => 0,
        'content' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'footer' => 0,
        'header' => 0,
        'navigation' => 0,
        'postscript' => 0,
        'preface' => 0,
        'search' => 0,
        'sidebar_first' => 0,
        'sidebar_second' => 0,
        'topcontent' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 1,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_content_list'
  $field_bases['field_content_list'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_content_list',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'viewfield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'viewfield',
  );

  return $field_bases;
}
