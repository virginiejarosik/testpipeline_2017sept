<?php
/**
 * @file
 * jagency_homepage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jagency_homepage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function jagency_homepage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function jagency_homepage_image_default_styles() {
  $styles = array();

  // Exported image style: image402x300.
  $styles['image402x300'] = array(
    'name' => 'image402x300',
    'effects' => array(
      44 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 402,
          'height' => 300,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 1,
          'downscaling' => 1,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 1,
        ),
        'weight' => -10,
      ),
      31 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 402,
          'height' => 300,
        ),
        'weight' => -9,
      ),
    ),
    'label' => 'image402x300',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function jagency_homepage_node_info() {
  $items = array(
    'content_block' => array(
      'name' => t('Content Block'),
      'base' => 'node_content',
      'description' => t('Use <em>Content Block</em> content to create custom block to show varient content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'content_view_block' => array(
      'name' => t('Content View Block'),
      'base' => 'node_content',
      'description' => t('Use <em>Content View Block</em> content to create list of content, with ability to control ammount and type of display'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'menu_connector' => array(
      'name' => t('Menu Connector'),
      'base' => 'node_content',
      'description' => t('Use <em>Menu Connector</em> content to create connection with Menu content and other entities'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'slider' => array(
      'name' => t('Slider'),
      'base' => 'node_content',
      'description' => t('Use <em>Slider</em> content to create slider with ability to reference slider items'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'slider_item' => array(
      'name' => t('Slider item'),
      'base' => 'node_content',
      'description' => t('Use <em>Slider item</em> content to create item that will be shown on slider'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function jagency_homepage_weight_features_default_settings() {
  $settings = array();

  $settings['content_block'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['content_view_block'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['news'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['slider'] = array(
    'enabled' => 0,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  $settings['slider_item'] = array(
    'enabled' => 0,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
