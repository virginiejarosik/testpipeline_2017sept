<?php
/**
 * @file
 * jagency_board_of_governers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jagency_board_of_governers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function jagency_board_of_governers_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function jagency_board_of_governers_image_default_styles() {
  $styles = array();

  // Exported image style: image515x495.
  $styles['image515x495'] = array(
    'name' => 'image515x495',
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
          'width' => 515,
          'height' => 495,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 0,
          'downscaling' => 0,
          'aspect_ratio' => 'KEEP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'image515x495',
  );

  // Exported image style: image72x111.
  $styles['image72x111'] = array(
    'name' => 'image72x111',
    'label' => 'image72x111',
    'effects' => array(
      42 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 72,
          'height' => 111,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image730x386.
  $styles['image730x386'] = array(
    'name' => 'image730x386',
    'effects' => array(
      29 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 730,
          'height' => 386,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 0,
          'downscaling' => 1,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
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
          'width' => 730,
          'height' => 386,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'image730x386',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function jagency_board_of_governers_node_info() {
  $items = array(
    'board_of_governors' => array(
      'name' => t('Board of governors'),
      'base' => 'node_content',
      'description' => t('Use <em>Board of governors</em> to create bog content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
