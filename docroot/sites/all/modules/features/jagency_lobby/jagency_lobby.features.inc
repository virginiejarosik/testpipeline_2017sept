<?php
/**
 * @file
 * jagency_lobby.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jagency_lobby_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function jagency_lobby_image_default_styles() {
  $styles = array();

  // Exported image style: program_lobby_big.
  $styles['program_lobby_big'] = array(
    'name' => 'program_lobby_big',
    'label' => 'program_lobby_big',
    'effects' => array(
      33 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 480,
          'height' => 280,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 1,
          'downscaling' => 1,
          'aspect_ratio' => 'KEEP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
      ),
      34 => array(
        'label' => 'התאמת גודל וחיתוך',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 280,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: program_lobby_small.
  $styles['program_lobby_small'] = array(
    'name' => 'program_lobby_small',
    'label' => 'program_lobby_small',
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
          'width' => 230,
          'height' => 138,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 1,
          'downscaling' => 1,
          'aspect_ratio' => 'KEEP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
      ),
      30 => array(
        'label' => 'התאמת גודל וחיתוך',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 230,
          'height' => 138,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
