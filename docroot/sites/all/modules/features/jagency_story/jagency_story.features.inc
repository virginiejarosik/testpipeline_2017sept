<?php
/**
 * @file
 * jagency_story.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jagency_story_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "msnf" && $api == "msnf") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function jagency_story_image_default_styles() {
  $styles = array();

  // Exported image style: image112x85.
  $styles['image112x85'] = array(
    'name' => 'image112x85',
    'label' => 'image112x85',
    'effects' => array(
      21 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 112,
          'height' => 85,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 0,
          'downscaling' => 1,
          'aspect_ratio' => 'KEEP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
      ),
      22 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 112,
          'height' => 85,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: image1400x789.
  $styles['image1400x789'] = array(
    'name' => 'image1400x789',
    'effects' => array(
      40 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 1400,
          'height' => 789,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 0,
          'downscaling' => 1,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
      ),
      41 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1400,
          'height' => 789,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'image1400x789',
  );

  // Exported image style: image192x110.
  $styles['image192x110'] = array(
    'name' => 'image192x110',
    'label' => 'image192x110',
    'effects' => array(
      37 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 192,
          'height' => 110,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image192x110_bw.
  $styles['image192x110_bw'] = array(
    'name' => 'image192x110_bw',
    'label' => 'image192x110_bw',
    'effects' => array(
      35 => array(
        'label' => 'Desaturate',
        'help' => 'Desaturate converts an image to grayscale.',
        'effect callback' => 'image_desaturate_effect',
        'dimensions passthrough' => TRUE,
        'module' => 'image',
        'name' => 'image_desaturate',
        'data' => array(),
        'weight' => 1,
      ),
      36 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 192,
          'height' => 110,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: image389x225.
  $styles['image389x225'] = array(
    'name' => 'image389x225',
    'label' => 'image389x225',
    'effects' => array(
      34 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 389,
          'height' => 225,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image389x225_bw.
  $styles['image389x225_bw'] = array(
    'name' => 'image389x225_bw',
    'label' => 'image389x225_bw',
    'effects' => array(
      32 => array(
        'label' => 'Desaturate',
        'help' => 'Desaturate converts an image to grayscale.',
        'effect callback' => 'image_desaturate_effect',
        'dimensions passthrough' => TRUE,
        'module' => 'image',
        'name' => 'image_desaturate',
        'data' => array(),
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
          'width' => 389,
          'height' => 225,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: image394x291.
  $styles['image394x291'] = array(
    'name' => 'image394x291',
    'label' => 'image394x291',
    'effects' => array(
      25 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 394,
          'height' => 291,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 0,
          'downscaling' => 1,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
      ),
      26 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 394,
          'height' => 291,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: image586x340.
  $styles['image586x340'] = array(
    'name' => 'image586x340',
    'label' => 'image586x340',
    'effects' => array(
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
          'width' => 586,
          'height' => 340,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image586x340_bw.
  $styles['image586x340_bw'] = array(
    'name' => 'image586x340_bw',
    'label' => 'image586x340_bw',
    'effects' => array(
      28 => array(
        'label' => 'Desaturate',
        'help' => 'Desaturate converts an image to grayscale.',
        'effect callback' => 'image_desaturate_effect',
        'dimensions passthrough' => TRUE,
        'module' => 'image',
        'name' => 'image_desaturate',
        'data' => array(),
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
          'width' => 586,
          'height' => 340,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: image980x518.
  $styles['image980x518'] = array(
    'name' => 'image980x518',
    'effects' => array(
      38 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 980,
          'height' => 518,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 0,
          'downscaling' => 1,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 1,
        ),
        'weight' => 1,
      ),
      39 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 980,
          'height' => 518,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'image980x518',
  );

  // Exported image style: original.
  $styles['original'] = array(
    'name' => 'original',
    'label' => 'original',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function jagency_story_node_info() {
  $items = array(
    'storys' => array(
      'name' => t('Storys'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'storys_promotion' => array(
      'name' => t('Storys promotion'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
