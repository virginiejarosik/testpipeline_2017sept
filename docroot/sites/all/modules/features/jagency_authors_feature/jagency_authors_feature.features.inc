<?php
/**
 * @file
 * jagency_authors_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jagency_authors_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function jagency_authors_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function jagency_authors_feature_image_default_styles() {
  $styles = array();

  // Exported image style: authors_51x51.
  $styles['authors_51x51'] = array(
    'name' => 'authors_51x51',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 51,
          'height' => 51,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'authors_51x51',
  );

  // Exported image style: authors_big_image.
  $styles['authors_big_image'] = array(
    'name' => 'authors_big_image',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 71,
          'height' => 71,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'authors_big_image',
  );

  // Exported image style: authors_small_image.
  $styles['authors_small_image'] = array(
    'name' => 'authors_small_image',
    'effects' => array(
      18 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 49,
          'height' => 49,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'authors_small_image',
  );

  return $styles;
}
