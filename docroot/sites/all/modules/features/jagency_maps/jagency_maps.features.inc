<?php
/**
 * @file
 * jagency_maps.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jagency_maps_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function jagency_maps_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function jagency_maps_image_default_styles() {
  $styles = array();

  // Exported image style: image130x117.
  $styles['image130x117'] = array(
    'name' => 'image130x117',
    'label' => 'image130x117',
    'effects' => array(
      30 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 130,
          'height' => 117,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 1,
          'downscaling' => 1,
          'aspect_ratio' => 'KEEP',
          'disable_if_no_data' => 1,
        ),
        'weight' => -10,
      ),
      29 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 130,
          'height' => 117,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: image50x50.
  $styles['image50x50'] = array(
    'name' => 'image50x50',
    'label' => 'image50x50',
    'effects' => array(
      28 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 50,
          'height' => 50,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 1,
          'downscaling' => 1,
          'aspect_ratio' => 'KEEP',
          'disable_if_no_data' => 1,
        ),
        'weight' => -10,
      ),
      27 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => -9,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function jagency_maps_node_info() {
  $items = array(
    'google_map' => array(
      'name' => t('Map'),
      'base' => 'node_content',
      'description' => t('Use <em>Map</em> content to create map with impact statment on it, can be displayed on footer or on program page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'map_event' => array(
      'name' => t('Impact Statement'),
      'base' => 'node_content',
      'description' => t('Use <em>Impact Statement</em> content used in personal Map'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
