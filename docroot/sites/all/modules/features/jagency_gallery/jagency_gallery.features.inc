<?php
/**
 * @file
 * jagency_gallery.features.inc
 */

/**
 * Implements hook_views_api().
 */
function jagency_gallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function jagency_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: image138x46.
  $styles['image138x46'] = array(
    'name' => 'image138x46',
    'effects' => array(
      28 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 138,
          'height' => 46,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'image138x46',
  );

  // Exported image style: image240x144.
  $styles['image240x144'] = array(
    'name' => 'image240x144',
    'effects' => array(
      34 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 240,
          'height' => 144,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 0,
          'downscaling' => 1,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
      ),
      35 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 240,
          'height' => 144,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'image240x144',
  );

  // Exported image style: image376x278.
  $styles['image376x278'] = array(
    'name' => 'image376x278',
    'effects' => array(
      32 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 376,
          'height' => 278,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'image376x278',
  );

  // Exported image style: image930x518.
  $styles['image930x518'] = array(
    'name' => 'image930x518',
    'effects' => array(
      32 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 930,
          'height' => 518,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 1,
          'downscaling' => 0,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
      ),
      33 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 930,
          'height' => 518,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'image930x518',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function jagency_gallery_node_info() {
  $items = array(
    'photo_gallery' => array(
      'name' => t('Photo gallery'),
      'base' => 'node_content',
      'description' => t('Use <em>Photo gallery</em> content in Program pages, to display photo collection'),
      'has_title' => '1',
      'title_label' => t('Gallery name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
