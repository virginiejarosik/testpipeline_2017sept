<?php
/**
 * Custom preproccess for node type custom menu
 */
function jagency_preprocess_node_custom_menu(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
  $vars['content']['links'] = array();
  foreach ($wrapper->field_menu_items->getIterator() as $delta => $item) {
    $vars['content']['links'][$delta] = $item -> field_link -> value();
    $vars['content']['links'][$delta]['children'] = $item -> field_sub_link -> value();
  }
}

function jagency_preprocess_node_event(&$vars) {
    switch ($vars['view_mode']) {
      case 'simple':
        $vars['content']['field_description'] = field_view_field('node', $vars['node'], 'field_teaser', array('label' => 'hidden', 'type' => 'plaintext'));
      break;
      case 'full' :
        $url = 'http://maps.googleapis.com/maps/api/geocode/json?latlng='.$vars['content']['field_geo_location']['#items'][0]['lat'].','.$vars['content']['field_geo_location']['#items'][0]['lng'].'&sensor=false';
        // Make the HTTP request
        $data = @file_get_contents($url);
        // Parse the json response
        $jsondata = json_decode($data,true);
        if (isset($jsondata['results'][0])) {
          $vars['content']['field_geo_location'][0]['#markup'] = $jsondata['results'][0]['formatted_address'];
        }
        $vars['content']['map_url'] = 'https://www.google.com/maps/place/' . $vars['content']['field_geo_location'][0]['#markup'] . '/@'.$vars['content']['field_geo_location']['#items'][0]['lat'].','.$vars['content']['field_geo_location']['#items'][0]['lng'].',13z&t=h';
        break;
    }
}

function jagency_preprocess_node_career(&$vars) {
  $vars['content']['field_copyright'] = get_copyright('field_main_image', $vars['node'] -> nid, 'cr');
  $vars['content']['field_date_career'] = date('j M Y', strtotime(strip_tags(render($vars['content']['field_date_career'])))) . ' / ' . convert_jew_date(strip_tags(render($vars['content']['field_date_career'])));
  
  if (!isset($vars['content']['field_program_short_description'])) {
    $vars['content']['field_program_short_description'] = field_view_field('node', $vars['node'], 'field_program_short_description', array('label' => 'hidden', 'type' => 'plaintext'));
  }
  if (!isset($vars['content']['field_main_image'])) {
    $vars['content']['field_main_image'] = field_view_field('node', $vars['node'], 'field_main_image', array('label' => 'hidden'));
  }
  switch ($vars['view_mode']) {
    case 'simple':
      $vars['content']['field_description'] = field_view_field('node', $vars['node'], 'field_program_short_description', array('label' => 'hidden', 'type' => 'plaintext'));
      break;
    case 'global_teaser' :
      $vars['content']['field_main_image'][0]['#image_style'] = 'blog_category';
      break;
    case 'global_teaser_big' :
      $vars['content']['field_main_image'][0]['#image_style'] = 'program_lobby_big';
      break;
  }
}

/**
 * Custom preproccess for node type news
 */
function jagency_preprocess_node_news(&$vars) {
  switch ($vars['view_mode']) {
    case 'news_small' :
      $vars['content']['field_image'] = field_view_field('node', $vars['node'], 'field_image', array('label' => 'hidden'));
      $vars['content']['field_image'][0]['#image_style'] = '78x60';
      $vars['content']['field_image'][0]['#item']['attributes'] = array('class' => array('pic'));
      break;
    case 'teaser' :
      $vars['content']['field_image'] = field_view_field('node', $vars['node'], 'field_image', array('label' => 'hidden'));
      $vars['content']['field_image'][0]['#image_style'] = '230x138';
      $vars['content']['field_image'][0]['#item']['attributes'] = array('class' => array('pic'));
      if (!isset($vars['content']['field_teaser'])) {
        $vars['content']['field_teaser'] = field_view_field('node', $vars['node'], 'field_teaser', array('label' => 'hidden', 'type' => 'plaintext'));
      }
      break;
  }
}

function jagency_preprocess_node_article(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
  if(isset($wrapper -> field_date)) {
    $vars['date'] = $wrapper->field_date->value();
  }
  if (!isset($vars['content']['field_main_image'])) {
    $vars['content']['field_main_image'] = field_view_field('node', $vars['node'], 'field_main_image', array('label' => 'hidden'));
  }
  if (isset($vars['content']['field_aticle_type']['#items'][0])) {
    $vars['content']['field_aticle_type']['#items'][0]['entity']->name = jagency_taxonomy_translate($vars['content']['field_aticle_type']['#items'][0]['entity']->tid, $vars['content']['field_aticle_type']['#items'][0]['entity']->name);
    $vars['content']['field_aticle_type'][0]['#markup'] = $vars['content']['field_aticle_type']['#items'][0]['entity']->name;
  }
  //d($vars['view_mode']);
  switch ($vars['view_mode']) {
    case 'fullcontent':
    case 'full':
      $vars['content']['color'] = $wrapper -> field_main_category -> value() -> tid;
      $vars['content']['field_copyright'] = get_copyright('field_main_image', $vars['node'] -> nid, 'cr');
      jagency_video_builder($vars, 'field_main_image', 'image730x548');
      $vars['video_size'] = '730x548';
      break;
    case 'global_teaser_big' :
      jagency_video_builder($vars, 'field_main_image', 'program_lobby_big');
      $vars['content']['field_main_image'][0]['#image_style'] = 'program_lobby_big';
      break;
    case 'news_small':
      jagency_video_image_builder($vars, 'field_main_image', '78x60');
      break;
    case 'program_lobby_big' :
    case 'program_lobby_small' :
      $display = $vars['view_mode'];
      $vars['content']['field_main_image'][0]['#image_style'] = $display;
      jagency_video_builder($vars, 'field_main_image', $display);
      $image = render($vars['content']['field_main_image']);
      $video = '';
      if ($vars['view_mode'] == 'program_lobby_small' && isset($vars['content']['video'])) {
        $video = '<div class="playBtn" data-size="230x138" data-href="' . $vars['content']['video'] . '"></div>';
      } else if (isset($content['video'])) {
        $video = '<div class="playBtn" data-size="480x280" data-href="' . $vars['content']['video'] . '"></div>';
      }
      $vars['content']['field_main_image'] = $video . $image;
      if (!isset($vars['content']['field_short_description'])) {
        $vars['content']['field_short_description'] = field_view_field('node', $vars['node'], 'field_short_description', array('label' => 'hidden'));
      }
      if (!isset($vars['content']['field_short_description'])) {
        $vars['content']['field_short_description'] = field_view_field('node', $vars['node'], 'field_short_description', array('label' => 'hidden'));
      }
      if (!isset($vars['content']['field_main_category'])) {
        $vars['content']['field_main_category'] = field_view_field('node', $vars['node'], 'field_main_category', array('label' => 'hidden'));
      }
      if (isset($vars['content']['field_main_category']['#items'][0])) {
        $vars['content']['field_main_category']['#items'][0]['entity']->name = jagency_taxonomy_translate($vars['content']['field_main_category']['#items'][0]['entity']->tid, $vars['content']['field_main_category']['#items'][0]['entity']->name);
        $vars['content']['field_main_category'][0]['#markup'] = $vars['content']['field_main_category']['#items'][0]['entity']->name;
      }
      break;
    case 'simple':
      $vars['content']['field_description'] = field_view_field('node', $vars['node'], 'field_short_description', array('label' => 'hidden'));
      break;
    case 'content_filter':
    case 'global_teaser':
    case 'teaser':
    default:
      jagency_video_image_builder($vars, 'field_main_image', 'image230x172');
      break;
  }
}

function jagency_preprocess_node_content_lobby(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);

  if (!isset($vars['content']['field_image'])) {
    $vars['content']['field_image'] = field_view_field('node', $vars['node'], 'field_image', array('label' => 'hidden'));
  }
  if (!isset($vars['content']['field_main_category'])) {
    $vars['content']['field_main_category'] = field_view_field('node', $vars['node'], 'field_main_category', array('label' => 'hidden'));
  }
  if (isset($vars['content']['field_main_category']['#items'][0])) {
    $vars['content']['field_main_category']['#items'][0]['entity']->name = jagency_taxonomy_translate($vars['content']['field_main_category']['#items'][0]['entity']->tid, $vars['content']['field_main_category']['#items'][0]['entity']->name);
    $vars['content']['field_main_category'][0]['#markup'] = $vars['content']['field_main_category']['#items'][0]['entity']->name;
  }
  if (!isset($vars['content']['field_description'])) {
    $vars['content']['field_description'] = field_view_field('node', $vars['node'], 'field_description', array('label' => 'hidden'));
  }
  switch ($vars['view_mode']) {
    case 'global_teaser_big' :
      jagency_video_builder($vars, 'field_image', 'program_lobby_big');
      $vars['content']['field_image'][0]['#image_style'] = 'program_lobby_big';
      break;
    case 'news_small':
      jagency_video_image_builder($vars, 'field_image', '78x60');
      break;
    case 'program_lobby_big' :
    case 'program_lobby_small' :
      $display = $vars['view_mode'];
      $vars['content']['field_image'][0]['#image_style'] = $display;
      jagency_video_builder($vars, 'field_image', $display);
      $image = render($vars['content']['field_image']);
      $video = '';
      if ($vars['view_mode'] == 'program_lobby_small' && isset($vars['content']['video'])) {
        $video = '<div class="playBtn" data-size="230x138" data-href="' . $vars['content']['video'] . '"></div>';
      } else if (isset($content['video'])) {
        $video = '<div class="playBtn" data-size="480x280" data-href="' . $vars['content']['video'] . '"></div>';
      }
      $vars['content']['field_image'] = $video . $image;
      break;
    case 'content_filter':
    case 'global_teaser':
    case 'teaser':
    default:
      jagency_video_image_builder($vars, 'field_image', 'image230x172');
      break;
  }
}

/**
 * Custom preproccess for node type photo gallery image
 */
function jagency_preprocess_node_news_events_loby(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
  $tag_args = array();
 
  $article_type = $wrapper -> field_aticle_type -> value();
  if (isset($article_type->tid)) {
    $tag_args['article_type'] = $article_type->tid; 
  } else {
    $tag_args['article_type'] = 'all';
  }
  
  $main_category = $wrapper -> field_main_category -> value();
  if (isset($main_category->tid)) {
    $tag_args['main_category'] = $main_category->tid; 
  } else {
    $tag_args['main_category'] = 'all';
  }
  
  $tags = $wrapper -> field_program_tags ->value();
  $main_category = $wrapper -> field_main_category -> value();
  foreach ($tags as $key => $value) {
    $tag_args['terms'][] = $value->tid;
  }

  if (is_array($tag_args) && count($tag_args)) {
    $tags = count($tag_args['terms']) ? implode('+', $tag_args['terms']) : 'all';
    $article_type = $tag_args['article_type'];
    $main_category = $tag_args['main_category'];
    $vars['content']['more_news_events'] = views_embed_view('more_news_events', 'block', $tags, $article_type, $main_category);
  } else {
    $vars['content']['more_news_events'] = '<div style="text-algin: center;">' . t('Nothing found') . '</div>';
  }
}
/**
 * Custom preproccess for node type photo gallery image
 */
function jagency_preprocess_node_content_filter(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
  $css = 'content_filter.css';
  if(isset($_SESSION['query_type'])) {
    unset($_SESSION['query_type']);
  }
  $_SESSION['Side_1'] = 'fLeft';
  $_SESSION['Side_2'] = 'fRight';
  $vars['Side_2'] = 'fLeft';
  $vars['Side_1'] = 'fRight';
  if (isset($wrapper->field_content_type)) {
    $vars['content_types'] = $wrapper -> field_content_type ->value();
  }
  if(isset($wrapper->field_display_sorting)) {
    if($wrapper->field_display_sorting->value() == 0) {
      $_SESSION['field_display_sorting'] = 'hidden';
    } else {
      unset($_SESSION['field_display_sorting']);
    }
  }
  /*if(isset($wrapper->field_query_type) && $wrapper->field_query_type->value() != null) {
    $_SESSION['query_type'] = $wrapper->field_query_type->value();
    drupal_add_js('jQuery.extend(Drupal.settings, { "query_type": "' . $_SESSION['query_type'] . '"});', 'inline');
  }*/
  if(isset($wrapper->field_filter_by_tags_content)) {
    //$filter_tags = array();
    $tags = $wrapper->field_filter_by_tags_content->value();
    if($tags != NULL) {
      //$all_tags = array();
      //$transfer_list = array();
      foreach ($tags as $key => $value) {
        $_GET['field_program_tags_target_id_1'][] = $value->tid;
        //$all_tags[$value->vid][] = $value->tid;
      }
      /*foreach ($all_tags as $key => $value) {
        $transfer_list[] = implode('+', $all_tags[$key]);
      }

      if(isset($_SESSION['query_type']) && isset($transfer_list)) {
        $vars['filter_by_tags'] = 'the_tags' . implode(',',$transfer_list);
      } else {
        $vars['filter_by_tags'] = implode('+',$transfer_list);
      }*/
    }
  }
  ///Language support
  if (isset($wrapper->field_content_filter_language)) {
    $language = $wrapper -> field_content_filter_language ->value();
    if($language == 'hebrew') {
      /*$_SESSION['Side_2'] = 'fLeft';
      $_SESSION['Side_1'] = 'fRight';
      $vars['Side_1'] = 'fLeft';
      $vars['Side_2'] = 'fRight';*/
      $css = 'content_filter_rtl.css';
    }
  }
  drupal_add_js(drupal_get_path('theme', 'jagency') . '/js/checkboxtree/jquery.checkboxtree.js', array('scope' => 'footer'));
  drupal_add_css(drupal_get_path('theme', 'jagency') . '/js/checkboxtree/jquery.checkboxtree.css');
  drupal_add_js('jQuery.extend(Drupal.settings, { "ToTop_side1": "' . $vars['Side_1'] . '", "ToTop_side2": "' . $vars['Side_2'] . '"});', 'inline');
  drupal_add_css(drupal_get_path('theme', 'jagency') . '/css/' . $css);
}

/**
 * Custom preproccess for node type Agency widget
 */
function jagency_preprocess_node_agency_widget(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
  $block_id = $wrapper->field_block_reference->value();
  drupal_add_js('jQuery.extend(Drupal.settings, { "widget_html": "' . node_view(node_load($block_id->nid),'teaser') . '"});', 'inline');
}
/**
 * Custom preproccess for node type photo gallery image
 */
function jagency_preprocess_node_photo_gallery(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
  switch ($vars['view_mode']) {
    case 'teaser' :
      $style = 'image376x278';
      $vars['content']['field_images'] = array();
      foreach ($wrapper->field_images->value() as $item) {
        $item['style_name'] = $style;
        $item['path'] = $item['uri'];
        $vars['content']['field_images'][] = $item;
      }
      break;
    case 'full' :
      foreach ($vars['content']['field_images'] as $key => $item) {
        if (is_numeric($key) && isset($item['file'])) {
          $vars['content']['field_images'][$key]['file']['#attributes'] = array('class' => array('pic'));
          $vars['content']['field_images'][$key]['file']['#link'] = file_create_url($item['file']['#path']);
          $vars['content']['field_images'][$key]['file']['#image_style'] = 'image240x144';
        }
      }
      break;
  }
}

/**
 * Custom preproccess for node type storys
 */
function jagency_preprocess_node_storys(&$vars) {
  if (!isset($vars['content']['field_program_description'])) {
    $vars['content']['field_program_description'] = field_view_field('node', $vars['node'], 'field_program_description', array('label' => 'hidden', 'type' => 'plaintext'));
  }
  if (!isset($vars['content']['field_quote'])) {
    $vars['content']['field_quote'] = field_view_field('node', $vars['node'], 'field_quote', array('label' => 'hidden', 'type' => 'plaintext'));
  }
  switch ($vars['view_mode']) {
    case 'global_teaser' :
    case 'content_filter':
      jagency_video_builder($vars, 'field_main_image', 'blog_category');
      $vars['content']['field_main_image'][0]['#image_style'] = 'blog_category';
      break;
    case 'global_teaser_big' :
      jagency_video_builder($vars, 'field_main_image', 'program_lobby_big');
      $vars['content']['field_main_image'][0]['#image_style'] = 'program_lobby_big';
      break;
    case 'full' :
      jagency_video_builder($vars, 'field_featured_image', 'image1400x789');
      jagency_video_builder($vars, 'field_main_image', 'image980x518');
      //$vars['content']['field_featured_image'] = field_view_field('node', $vars['node'], 'field_featured_image', array('label' => 'hidden'));
      //$vars['content']['field_main_image'] = field_view_field('node', $vars['node'], 'field_main_image', array('label' => 'hidden'));
      $vars['content']['field_featured_image'][0]['#item']['attributes'] = array('class' => array('pic'));
      $vars['content']['field_main_image'][0]['#item']['attributes'] = array('class' => array('pic'));
      break;
  }
}

/**
 * Custom preproccess for node type program video
 */
function jagency_preprocess_node_program_video(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);

  if (!isset($vars['content']['field_video'])) {
    $vars['content']['field_video'] = field_view_field('node', $vars['node'], 'field_video', array('label' => 'hidden'));
  }

  switch ($wrapper->field_video_size->value()) {
    case 'small' :
      jagency_video_builder($vars, 'field_video', 'image480x270');
      $vars['video_size'] = '480x270';
      break;
    case 'big' :
      jagency_video_builder($vars, 'field_video', 'image730x411');
      $vars['video_size'] = '730x411';
      break;
  }
}

/**
 * Custom preproccess for node type content block
 */
function jagency_preprocess_node_content_view_block(&$vars) {
  if (!isset($vars['content']['field_block_view'])) {
    $vars['content']['field_block_view'] = field_view_field('node', $vars['node'], 'field_block_view', array('label' => 'hidden'));
  }
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
  $vars['content']['size'] = '';
  if (isset($wrapper -> field_header_size)) {
    $vars['content']['size'] = $wrapper -> field_header_size -> value();
  }
  if (isset($wrapper -> field_content_references) && $wrapper -> field_content_references -> value() != NULL) {
    if (isset($wrapper -> field_display_for_content_refere) && $wrapper -> field_display_for_content_refere -> value() != NULL) {
      switch ($wrapper->field_display_for_content_refere->value()) {
        case 'full':
          $display = 'global_teaser';
          $vars['content']['splited_content']['full'] = array();
          foreach ($vars['content']['field_content_references'] as $key => $value) {
            if (is_numeric($key)) {
              foreach ($vars['content']['field_content_references'][$key]['node'] as $key2 => $value2) {
                if (is_numeric($key2)) {
                  $vars['content']['field_content_references'][$key]['node'][$key2]['#entity_view_mode']['view_mode'] = 'global_teaser';
                  $vars['content']['field_content_references'][$key]['node'][$key2]['#view_mode'] = 'global_teaser';
                  $vars['content']['field_content_references'][$key]['node'][$key2]['field_program']['#view_mode'] = $display;
                  $vars['content']['splited_content']['full'][] = $vars['content']['field_content_references'][$key]['node'][$key2];
                }
              }
            }
            $vars['content']['splited_content']['full'] = array_reverse($vars['content']['splited_content']['full']);
          }
          break;
        case 'teasers' :
          $display = 'global_teaser';
          $vars['content']['splited_content']['global_teaser'] = array();
          foreach ($vars['content']['field_content_references'] as $key => $value) {
            if (is_numeric($key)) {
              //d(count($vars['content']['field_content_references'][$key]['node']));
              foreach ($vars['content']['field_content_references'][$key]['node'] as $key2 => $value2) {
                if (is_numeric($key2)) {
                  $vars['content']['field_content_references'][$key]['node'][$key2]['#entity_view_mode']['view_mode'] = 'global_teaser';
                  $vars['content']['field_content_references'][$key]['node'][$key2]['#view_mode'] = 'global_teaser';
                  $vars['content']['field_content_references'][$key]['node'][$key2]['field_program']['#view_mode'] = $display;
                  $vars['content']['splited_content']['global_teaser'][] = $vars['content']['field_content_references'][$key]['node'][$key2];
                }
              }
            }
            $vars['content']['splited_content']['global_teaser'] = array_reverse($vars['content']['splited_content']['global_teaser']);
          }
          break;
        case 'splited' :
          $counter = 0;
          foreach ($vars['content']['field_content_references'] as $key => $value) {
            if (is_numeric($key)) {
              foreach ($vars['content']['field_content_references'][$key]['node'] as $key2 => $value2) {
                if (is_numeric($key2)) {
                  $display = 'global_teaser';
                  if ($counter < 3) {
                    $display = 'global_teaser_big';
                  }
                  if (!is_array($vars['content']['splited_content'][$display])) {
                    $vars['content']['splited_content'][$display] = array();
                  }
                  $vars['content']['field_content_references'][$key]['node'][$key2]['#entity_view_mode']['view_mode'] = $display;
                  $vars['content']['field_content_references'][$key]['node'][$key2]['#view_mode'] = $display;
                  $vars['content']['field_content_references'][$key]['node'][$key2]['field_program']['#view_mode'] = $display;
                  $vars['content']['splited_content'][$display][] = $vars['content']['field_content_references'][$key]['node'][$key2];
                }
                $counter++;
              }
            }
            if (!is_array($vars['content']['splited_content']['global_teaser'])) {
              $vars['content']['splited_content']['global_teaser'] = array_reverse($vars['content']['splited_content']['global_teaser']);
            }
            if (!is_array($vars['content']['splited_content']['global_teaser_big'])) {
              $vars['content']['splited_content']['global_teaser_big'] = array_reverse($vars['content']['splited_content']['global_teaser_big']);
            }
          }
          break;
      }
    }
  }
}

/**
 * Custom preproccess for node type content block
 */
function jagency_preprocess_node_content_block(&$vars) {
  switch ($vars['view_mode']) {
    case 'teaser' :
    case 'full' :
      $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
      $type = $wrapper -> field_block_type -> value();
      $vars['content']['field_block_content'] = $wrapper -> field_block_content -> value();
      $vars['content']['field_block_class'] = $wrapper -> field_block_class -> value();
      $vars['content']['field_image'] = field_view_field('node', $vars['node'], 'field_image', array('label' => 'hidden'));
      if (isset($wrapper -> field_content_reference)) {
        $field_content_reference = field_view_field('node', $vars['node'], 'field_content_reference', array('label' => 'hidden', 'type' => 'entityreference_entity_id'));
        if (isset($field_content_reference[0]) && $field_content_reference[0]['#markup']) {
          $node = node_load($field_content_reference[0]['#markup']);
          $view = node_view($node, 'full');
          $vars['content']['field_content_reference'] = drupal_render($view);
        }
      }
      $vars['content']['size'] = $wrapper -> field_header_size -> value();
      $vars['view_mode'] = 'teaser-' . $type;
      break;
  }
}

/**
 * Custom preproccess for node type slider
 */
function jagency_preprocess_node_slider(&$vars) {
  switch ($vars['view_mode']) {
    case 'full' :
      $wrapper = entity_metadata_wrapper('node', $vars['node']);
      foreach ($wrapper->field_slider_items_collection->getIterator() as $delta => $item) {
        $wrapper2 = entity_metadata_wrapper('node', $item -> value() -> field_slider_items[LANGUAGE_NONE][0]['entity']);
        $type = $wrapper2 -> field_slider_type -> value();
        if ($type == 'video') {
          $vars['content']['field_slider_items_collection'][$delta]['#attributes']['class'][] = $vars['content']['field_slider_items_collection'][$delta]['links']['#attributes']['class'][] = 'emergency';
        }
        $vars['content']['field_slider_items_collection'][$delta]['links'] = array();
      }
      $vars['content']['field_slider_items_collection']['#suffix'] = '';
      break;
  }
}

/**
 * Custom preproccess for node type slider
 */
function jagency_preprocess_node_storys_promotion(&$vars) {
  switch ($vars['view_mode']) {
    case 'full' :
    case 'global_teaser':
      if (!isset($vars['content']['field_story'])) {
        $vars['content']['field_story'] = field_view_field('node', $vars['node'], 'field_story', array('label' => 'hidden'));
      }
      $i = 1;
      $wrapper = entity_metadata_wrapper('node', $vars['node']);
      foreach ($wrapper->field_story->getIterator() as $delta => $item) {
        $uri = $item -> value() -> field_sp_image[LANGUAGE_NONE][0]['uri'];
        $key = key($vars['content']['field_story'][$delta]['entity']['field_collection_item']);
        $vars['content']['field_story'][$delta]['#attributes']['class'] = 'pic-' . $i;
        switch ($delta) {
          case '0' :
            $vars['content']['field_story'][$delta]['entity']['field_collection_item'][$key]['field_sp_image'] = theme_image_style(array('style_name' => 'image586x340_bw', 'path' => $uri, 'attributes' => array('data-other-src' => image_style_url('image586x340', $uri))));
            break;
          case '4' :
          case '3' :
          case '1' :
            $vars['content']['field_story'][$delta]['entity']['field_collection_item'][$key]['field_sp_image'] = theme_image_style(array('style_name' => 'image389x225_bw', 'path' => $uri, 'attributes' => array('data-other-src' => image_style_url('image389x225', $uri))));
            break;
          case '6' :
          case '7' :
          case '5' :
          case '2' :
            $vars['content']['field_story'][$delta]['entity']['field_collection_item'][$key]['field_sp_image'] = theme_image_style(array('style_name' => 'image192x110_bw', 'path' => $uri, 'attributes' => array('data-other-src' => image_style_url('image192x110', $uri))));
            break;
          default :
            $vars['content']['field_story'][$delta]['entity']['field_collection_item'][$key]['field_sp_image'] = theme_image_style(array('style_name' => 'image192x110_bw', 'path' => $uri, 'attributes' => array('data-other-src' => image_style_url('image192x110', $uri))));
            break;
        }
        $i++;
      }
      break;
  }
}

/**
 * Custom preproccess for node type slider item
 */
function jagency_preprocess_node_slider_item(&$vars) {
  switch ($vars['view_mode']) {
    case 'full' :
      $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
      $type = $wrapper -> field_slider_type -> value();
      switch($type) {
        case 'left' :
          $vars['content']['field_image'] = field_view_field('node', $vars['node'], 'field_image', array('label' => 'hidden'));
          $vars['content']['field_image'][0]['#image_style'] = 'big_slider_image';
          $vars['content']['field_image'][0]['#item']['attributes'] = array('class' => array('pic'));

          $target = $wrapper -> field_content_reference -> value();
          $color_term = $wrapper -> field_default_color -> value();
          $color_wrapper = entity_metadata_wrapper('taxonomy_term', $color_term -> tid);
          $color = $color_wrapper -> field_color -> value();
          if (isset($wrapper -> field_apply_link) && $wrapper -> field_apply_link -> value() != NULL) {
            $vars['content']['button'] = l($wrapper -> field_button_text -> value(), $wrapper -> field_apply_link -> value(), array('attributes' => array('class' => array('button', 'cs' . jagency_get_color_by_term($color)))));
          } else {
            $vars['content']['button'] = l($wrapper -> field_button_text -> value(), 'node/' . $target -> nid, array('attributes' => array('class' => array('button', 'cs' . jagency_get_color_by_term($color)))));
          }
          $vars['content']['button'] .= '<span class="info"><span>' . $wrapper -> field_author_name -> value() . '</span> ' . $wrapper -> field_author_title -> value() . '</span>';
          $vars['content']['photo_owner'] = '';
          if (isset($vars['content']['field_image'][0]['#item']['fid'])) {
            $vars['content']['photo_owner'] = get_copyright('field_image', $vars['node'] -> nid, 'photoCR');
          }
          $vars['view_mode'] = 'full-left';
          break;

        case 'video' :
          $vars['content']['field_video_message_type'] = field_view_field('node', $vars['node'], 'field_video_message_type', array('label' => 'hidden', 'type' => 'plaintext'));
          $vars['content']['field_image'] = field_view_field('node', $vars['node'], 'field_image', array('label' => 'hidden'));
          $vars['content']['field_image'][0]['#image_style'] = 'image402x300';
          $vars['content']['field_image'] = strip_tags(render($vars['content']['field_image']), '<img>');

          $target = $wrapper -> field_content_reference -> value();
          $color_term = $wrapper -> field_default_color -> value();
          $color_wrapper = entity_metadata_wrapper('taxonomy_term', $color_term -> tid);
          $color = $color_wrapper -> field_color -> value();

          if (isset($wrapper -> field_apply_link) && $wrapper -> field_apply_link -> value() != NULL) {
            $vars['content']['button'] = l($wrapper -> field_button_text -> value(), $wrapper -> field_apply_link -> value(), array('attributes' => array('class' => array('button', 'cs' . jagency_get_color_by_term($color)))));
          } else {
            $vars['content']['button'] = l($wrapper -> field_button_text -> value(), 'node/' . $target -> nid, array('attributes' => array('class' => array('button', 'cs' . jagency_get_color_by_term($color)))));
          }
          $vars['content']['button'] .= '<span class="info"><span>' . $wrapper -> field_author_name -> value() . '</span> ' . $wrapper -> field_author_title -> value() . '</span>';
          jagency_video_builder($vars, 'field_video', 'big_slider_image');
          $vars['view_mode'] = 'full-video';
          break;

        default :
          $vars['content']['field_image'] = field_view_field('node', $vars['node'], 'field_image', array('label' => 'hidden'));
          $vars['content']['field_image'][0]['#image_style'] = 'big_slider_image';
          $vars['content']['field_image'][0]['#item']['attributes'] = array('class' => array('pic'));

          $target = $wrapper -> field_content_reference -> value();
          $color_term = $wrapper -> field_default_color -> value();
          if (isset($color_term -> tid) && $color_term -> tid) {
            $color_wrapper = entity_metadata_wrapper('taxonomy_term', $color_term -> tid);
            $color = $color_wrapper -> field_color -> value();
          } else {
            $color = '';
          }
          if (isset($wrapper -> field_apply_link) && $wrapper -> field_apply_link -> value() != NULL) {
            $vars['content']['button'] = l($wrapper -> field_button_text -> value(), $wrapper -> field_apply_link -> value(), array('attributes' => array('class' => array('button', 'cs' . jagency_get_color_by_term($color)))));
          } else {
            $vars['content']['button'] = l($wrapper -> field_button_text -> value(), 'node/' . $target -> nid, array('attributes' => array('class' => array('button', 'cs' . jagency_get_color_by_term($color)))));
          }
          $vars['content']['button'] .= '<span class="info"><span>' . $wrapper -> field_author_name -> value() . '</span> ' . $wrapper -> field_author_title -> value() . '</span>';
          $vars['content']['photo_owner'] = '';
          if (isset($vars['content']['field_image'][0]['#item']['fid'])) {
            $vars['content']['photo_owner'] = get_copyright('field_image', $vars['node'] -> nid, 'photoCR');
          }
          $vars['view_mode'] = 'full-default';
          break;
      }
      break;
  }
}

/**
 * Custom preproccess for node type quote
 */
function jagency_preprocess_node_content_location(&$vars) {
  $block = blockreference_formatter_get_block(array('item' => array('bid' => $vars['node']->field_block[LANGUAGE_NONE][0]['bid'])));
  if ($block) {
    $vars['content']['field_block'] = '';
    $block_content = _block_render_blocks(array($block));
    $build = _block_get_renderable_array($block_content);
    $vars['content']['field_block']['#markup'] = drupal_render($build);
   }
}

function jagency_preprocess_node_menu_connector(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
  switch ($vars['view_mode']) {
    case 'teaser' :
      $vars['content']['field_logo_link'] = '';
      if (isset($wrapper -> field_logo_link)) {
        $vars['content']['field_logo_link'] = $wrapper -> field_logo_link -> value();
      }
      if (!isset($vars['content']['field_image'])) {
        $vars['content']['field_image'] = field_view_field('node', $vars['node'], 'field_image', array('label' => 'hidden'));
        $vars['content']['field_image'][0]['#image_style'] = 'menu_image';
      }
      if (!isset($vars['content']['field_teaser'])) {
        $vars['content']['field_teaser'] = field_view_field('node', $vars['node'], 'field_teaser', array('label' => 'hidden', 'type' => 'plaintext'));
      }
      break;
  }
}

function jagency_preprocess_node_program_details(&$vars) {
  $menuitem = menu_get_item();
  $vars['wrapper'] = entity_metadata_wrapper('node', $vars['node'] -> nid);
  $vars['program_link'] = 'node/' . $vars['node'] -> nid;
  $vars['program_link_target'] = '_self';
  if (isset($vars['wrapper'] -> field_logo_link) && $vars['wrapper'] -> field_logo_link -> value() != NULL) {
    $vars['program_link'] = $vars['wrapper'] -> field_logo_link -> value();
    $vars['program_link_target'] = '_blank';
  }
  $vars['masa_icon'] = '';
  if (isset($vars['wrapper'] -> field_masa_recognition) && $vars['wrapper'] -> field_masa_recognition -> value() == 'yes') {
    $vars['masa_icon'] = '&nbsp;&nbsp;' . theme('image', array('path' => drupal_get_path('theme', 'jagency') . '/images/masa_icon1.png'));
  }
  if (isset($vars['wrapper'] -> field_total_cost) && $vars['wrapper'] -> field_total_cost -> value() != 0) {
    $vars['prices'] = $vars['wrapper'] -> field_total_cost -> value();
  }
  if (!isset($vars['content']['field_organizer'])) {
    $vars['content']['field_organizer'] = field_view_field('node', $vars['node'], 'field_organizer', array('label' => 'hidden', 'type' => 'plaintext'));
  }
  if (!isset($vars['content']['field_organizer_website'])) {
    $vars['content']['field_organizer_website'] = field_view_field('node', $vars['node'], 'field_organizer_website', array('label' => 'hidden', 'type' => 'plaintext'));
  }
  if (isset($vars['wrapper'] -> field_program_icons)) {
    $icons = $vars['wrapper'] -> field_program_icons -> value();
    $vars['cost_icons'] = '';
    if (in_array('housing', $icons)) {
      $vars['cost_icons'] .= theme('image', array('path' => path_to_theme() . '/images/home.png'));
      $vars['cost_icons'] .= '&nbsp;';
    }
    if (in_array('full board', $icons)) {
      $vars['cost_icons'] .= theme('image', array('path' => path_to_theme() . '/images/meals.png'));
    }
    if (in_array('tuition', $icons)) {
      $vars['cost_icons'] .= theme('image', array('path' => path_to_theme() . '/images/edu.png'));
      $vars['cost_icons'] .= '&nbsp;';
    }
    if (in_array('flights', $icons)) {
      $vars['cost_icons'] .= theme('image', array('path' => path_to_theme() . '/images/flights.png'));
      $vars['cost_icons'] .= '&nbsp;';
    }
    if (in_array('medal', $icons)) {
      $vars['cost_icons'] .= theme('image', array('path' => path_to_theme() . '/images/medal.png'));
      $vars['cost_icons'] .= '&nbsp;';
    }
    if (in_array('visits to additional countries', $icons)) {
      $vars['cost_icons'] .= theme('image', array('path' => path_to_theme() . '/images/worldwide.png'));
    }
  }
  /** TIME START **/
  for ($i = 1; $i <= 4; $i++) {
    $start_date = 'field_start_date';
    if ($i != 1) {
      $start_date = 'field_start_date_' . $i;
      if ($vars['wrapper'] -> $start_date -> value() != NULL) {
        if($vars['wrapper'] -> $start_date -> value() > time()) {
          $vars['content']['field_start_time'][] = $vars['wrapper'] -> $start_date -> value();
        }
      }
    }
  }
  
  $timeobj = $vars['wrapper'] -> field_start_date -> value();
  if(isset($timeobj['value'])) {
    if ($vars['wrapper'] -> field_duration_type -> value()) {
      $vars['time_duration'] = $vars['wrapper'] -> field_duration_period -> value() . ' ' . str_replace('in', '', $vars['wrapper'] -> field_duration_type -> value());
    } else {
      $vars['time'] = strtotime($timeobj['value2']) - strtotime($timeobj['value']);
    }
    if(strtotime($timeobj['value']) > time()) {
      $vars['content']['field_start_time'][] = strtotime($timeobj['value']);
    }
  }
  
  if (isset($vars['content']['field_start_time'])) {
    $vars['content']['field_start_time'] = min($vars['content']['field_start_time']);
  } else {
    $vars['content']['field_start_time'] = 0;
  }
  /*****END*****/

  if ($vars['wrapper'] -> field_language -> value() != NULL) {
    $langs = $vars['wrapper'] -> field_language -> value();
    foreach ($langs as $key => $value) {
      $vars['content']['languages'][] = $value -> name;
    }
  }
  switch ($vars['view_mode']) {
    case 'simple':
      $vars['content']['field_description'] = field_view_field('node', $vars['node'], 'field_short_description', array('label' => 'hidden', 'type' => 'plaintext'));
      break;
    case 'content_filter':
      if (!isset($vars['content']['field_short_description'])) {
        $vars['content']['field_short_description'] = field_view_field('node', $vars['node'], 'field_short_description', array('label' => 'hidden'));
      }
      if (!isset($vars['content']['field_featured_image'])) {
        $vars['content']['field_featured_image'] = field_view_field('node', $vars['node'], 'field_featured_image', array('label' => 'hidden'));
      }
      if (!isset($vars['content']['field_featured_image'])) {
        $vars['content']['field_featured_image'] = field_view_field('node', $vars['node'], 'field_featured_image', array('label' => 'hidden'));
      }
      break;
    case 'global_teaser_big' :
      if (!isset($vars['content']['field_featured_image'])) {
        $vars['content']['field_featured_image'] = field_view_field('node', $vars['node'], 'field_featured_image', array('label' => 'hidden'));
      }
      $vars['content']['field_featured_image'][0]['#image_style'] = 'program_lobby_big';
      $vars['content']['field_featured_image'] = strip_tags(render($vars['content']['field_featured_image']), '<img>');
      break;
      
    case 'program_lobby_big' :
    case 'program_lobby_small' :
      if (!isset($vars['content']['field_featured_image'])) {
        $vars['content']['field_featured_image'] = field_view_field('node', $vars['node'], 'field_featured_image', array('label' => 'hidden'));
      }
      $display = $vars['view_mode'];
      $vars['content']['field_featured_image'][0]['#image_style'] = $display;
      jagency_video_builder($vars, 'field_featured_image', $display);
      $image = render($vars['content']['field_featured_image']);
      $video = '';
      if ($vars['view_mode'] == 'program_lobby_small' && isset($vars['content']['video'])) {
        $video = '<div class="playBtn" data-size="230x138" data-href="' . $vars['content']['video'] . '"></div>';
      } else if (isset($content['video'])) {
        $video = '<div class="playBtn" data-size="480x280" data-href="' . $vars['content']['video'] . '"></div>';
      }
      $vars['content']['field_featured_image'] = $video . $image;
      break;
      
    case 'global_teaser':
      if (!isset($vars['content']['field_featured_image'])) {
        $vars['content']['field_featured_image'] = field_view_field('node', $vars['node'], 'field_featured_image', array('label' => 'hidden'));
      }
      $vars['content']['field_featured_image'][0]['#image_style'] = 'blog_category';
      $vars['content']['field_featured_image'] = strip_tags(render($vars['content']['field_featured_image']), '<img>');
      break;
      
    case 'full' :
      $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
      
      /////LOCATIONS - GOOGLE MAP FUNCTION////////
      $path = parse_url($_SERVER['REQUEST_URI']);
      $path = substr(check_plain($path['path']), 1);
      $_path = explode('/', $path);
      $last_url = array();
      $arg1 = $arg2 = '';
      
      if (strlen($path) == 0) {
        $path = 'front';
      }
      $path_args = array('*', $path);
      
      //no need to run on admin
      if (isset($_path[0]) && $_path[0] == 'admin') {
        return;
      }
      
      //fetch items by path  
      for($i = 0; $i < count($_path); $i++) {
        if ($_path[$i]) {
          $last_url[] = $_path[$i];
          $path_args[] = implode('/', $last_url) . '/*';
        }
      }
      $arg1 = str_replace('/', '\\', implode('+', $path_args));
      //fetch by node reference
      switch($menuitem['path']) {
        case 'node/%':
          $nids = jagency_pages_get_nids($menuitem['map'][1]);
          if (is_array($nids)) {
            $arg2 = implode('+', $nids);
          }
          break;
      }
      if ($arg2) {
        $vars['program_map'] = trim(views_embed_view('map_locations', 'panel_pane_3', $arg1, $arg2));
      } else {
        $vars['program_map'] = trim(views_embed_view('map_locations', 'panel_pane_3', $arg1));
      }
      /////LOCATIONS - GOOGLE MAP FUNCTION - END////////
      
      $vars['content']['field_copyright'] = get_copyright('field_main_image', $vars['node'] -> nid);
      if ($wrapper -> field_logo_link -> value() != NULL) {
        drupal_goto('404-nothing-found');
      }
      if (isset($wrapper -> field_program)) {
        $program = $wrapper -> field_program -> value();
        //d($program[0]->nid);
        if (isset($program[0] -> nid)) {
          $ProgramWrapper = entity_metadata_wrapper('node', $program[0] -> nid);
          if (isset($ProgramWrapper -> field_program_logo)) {
            $program_logo = $ProgramWrapper -> field_program_logo -> value();
            if ($program_logo != NULL) {
              $vars['program_logo'] = theme('image', array('path' => ($program_logo['uri'])));
            }
          }
        }
      }

      $vars['content']['field_featured_image'][0]['#item']['attributes'] = array('class' => array('pic'));
      $vars['view_program_details'] = views_embed_view('more_about_program', 'block');
      $vars['content']['block_list'] = $wrapper -> field_blocks_list -> value();
      $type = $wrapper -> field_view_mode -> value();
      if (isset($type)) {
        $vars['view_mode'] = 'full-' . $type;
        $vars['content']['video'] = '';
        switch ($type) {
          case 'program_without_sidemenu' :
            $display = 'image980x518';
            $vars['content']['field_main_image'][0]['#image_style'] = 'image980x518';
            jagency_video_builder($vars, 'field_main_image', $display);
            break;
          case 'program_with_sidemenu' :
          case 'program_page_only' :
            $display = 'image730x386';
            $vars['content']['field_main_image'][0]['#image_style'] = 'image730x386';
            jagency_video_builder($vars, 'field_main_image', $display);
            break;
        }
        if (isset($vars['content']['field_program'])) {

        }
      } else {
        $vars['view_mode'] = 'full';
      }
      if (isset($wrapper -> field_main_category -> value() -> tid)) {
        $vars['content']['color'] = jagency_get_color_recursive($wrapper -> field_main_category -> value() -> tid);
      } else {
        $vars['content']['color'] = jagency_get_color_recursive(0);
      }
      //translation
      if (isset($vars['content']['field_taxonomy_city']['#items'][0])) {
        $vars['content']['field_taxonomy_city']['#items'][0]['entity']->name = jagency_taxonomy_translate($vars['content']['field_taxonomy_city']['#items'][0]['entity']->tid, $vars['content']['field_taxonomy_city']['#items'][0]['entity']->name);
        $vars['content']['field_taxonomy_city'][0]['#markup'] = $vars['content']['field_taxonomy_city']['#items'][0]['entity']->name;
      }
      if (isset($vars['content']['field_taxonomy_country']['#items'][0])) {
        $vars['content']['field_taxonomy_country']['#items'][0]['entity']->name = jagency_taxonomy_translate($vars['content']['field_taxonomy_country']['#items'][0]['entity']->tid, $vars['content']['field_taxonomy_country']['#items'][0]['entity']->name);
        $vars['content']['field_taxonomy_country'][0]['#markup'] = $vars['content']['field_taxonomy_country']['#items'][0]['entity']->name;
      }
      break;
  }
}

function jagency_preprocess_node_board_of_governors(&$vars) {
  global $language;
  if (isset($vars['content']['field_roles'])) {
    foreach ($vars['content']['field_roles'] as $key => $value) {
      if (is_numeric($key)) {
        $vars['content']['field_roles'][$key]['#markup'] = jagency_taxonomy_translate($vars['content']['field_roles']['#object']->field_roles[LANGUAGE_NONE][0]['target_id'], $value['#markup']);
      }
    }
  }
  switch ($vars['view_mode']) {
    case 'simple':
      $vars['content']['field_description'] = field_view_field('node', $vars['node'], 'field_profile_short_bio', array('label' => 'hidden', 'type' => 'plaintext'));
      break;
    case 'program_lobby_small' :
      $vars['content']['field_image'][0]['#image_style'] = '230x138';
      break;
    case 'full' :
      $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
      if(isset($vars['node']->field_roles)) {
        foreach ($vars['node']->field_roles[LANGUAGE_NONE] as $key => $value) {
          $vars['roles'][] = jagency_taxonomy_translate($value['entity']->tid, $value['entity']->name);
        }
      }
      $vars['content']['field_copyright'] = get_copyright('field_image', $vars['node'] -> nid);
      break;
  }
}

function jagency_preprocess_node_google_map(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
  $vars['address'] = '';
  /**We need to use that for preview situation*/
  if(isset($vars['content']['field_map_address']['#object']->field_map_address[LANGUAGE_NONE][0]['value'])) {
    $vars['address'] = $vars['content']['field_map_address']['#object']->field_map_address[LANGUAGE_NONE][0]['value'];
  }
  elseif(isset($wrapper->field_map_zoom) && $wrapper->field_map_address->value() != NULL) {
    $vars['address'] = $wrapper->field_map_address->value();
  }
  drupal_add_js('https://maps.googleapis.com/maps/api/js?key=AIzaSyAxdV973M6q4u-urF5enz6WbHrdLDnc21Q&sensor=false', 'external');
  //drupal_add_js(drupal_get_path('theme', 'jagency') . "/js/oms.min.js", array('type' => 'file', 'scope' => 'header'));
  drupal_add_js(drupal_get_path('theme', 'jagency') . "/js/google_map.js", array('type' => 'file', 'scope' => 'header'));
  drupal_add_js(drupal_get_path('theme', 'jagency') . "/js/google_map_locations.js", array('type' => 'file', 'scope' => 'header'));
  drupal_add_js(array('jafi_pages' => array('address' => $vars['address'])), 'setting');
  switch ($vars['view_mode']) {
    case 'full':
    case 'program_lobby_small' :
    case 'teaser' :
      /*Chacking for map type - used in preview situation*/
      if(isset($vars['content']['field_map_type']['#object']->field_map_type[LANGUAGE_NONE][0]['value']) && $vars['content']['field_map_type']['#object']->field_map_type[LANGUAGE_NONE][0]['value'] != 'footer') {
        $vars['view_mode'] = 'program_lobby_small';
      }
      
      $zoom = 2;
      /**We need to use that for preview situation*/
      if(isset($vars['content']['field_map_zoom']['#object']->field_map_zoom[LANGUAGE_NONE][0]['value'])) {
        $zoom = $vars['content']['field_map_zoom']['#object']->field_map_zoom[LANGUAGE_NONE][0]['value'];
      }
      elseif(isset($wrapper->field_map_zoom) && $wrapper->field_map_zoom->value() != NULL) {
        $zoom = $wrapper->field_map_zoom->value();
      }
      
      if (!isset($vars['content']['field_header_title'])) {
        $vars['content']['field_header_title'] = field_view_field('node', $vars['node'], 'field_header_title', array('label' => 'hidden', 'type' => 'plaintext'));
      }
      if (!isset($vars['content']['field_header_link'])) {
        $vars['content']['field_header_link'] = field_view_field('node', $vars['node'], 'field_header_link', array('label' => 'hidden', 'type' => 'plaintext'));
      }
      $maplocations = array();
      if (isset($wrapper -> field_events)) {
        $field_events = $wrapper -> field_events -> value();
        $maplocations = array();
        $vars['count_number'] = 0;
        foreach ($field_events as $key => $value) {
          if ($value->type == 'map_event' && isset($value -> field_event_main_category[LANGUAGE_NONE])) {
            $vars['count_number']++;
            $maplocations[] = array('location' => $value -> field_address[LANGUAGE_NONE][0]['value'],
                                    'longitude' => isset($value -> field_longitude[LANGUAGE_NONE]) ? $value -> field_longitude[LANGUAGE_NONE][0]['value'] : '',
                                    'latitude' => isset($value -> field_latitude[LANGUAGE_NONE]) ? $value -> field_latitude[LANGUAGE_NONE][0]['value'] : '',
                                    'color' => jagency_get_color_recursive($value -> field_event_main_category[LANGUAGE_NONE][0]['target_id']), 
                                    'id' => $value -> nid, 'countNum' => $vars['count_number'],
                                    'titlelabel' => (isset($value->field_button_reference[LANGUAGE_NONE]) ? l($value->title, 'node/' . $value->field_button_reference[LANGUAGE_NONE][0]['target_id']) : $value->title),
                                    'title' => $value->title,
                                    'contenthtml' => isset($value->body[LANGUAGE_NONE]) ? $value->body[LANGUAGE_NONE][0]['value'] : "");
          }
        }
      }
      if (isset($wrapper->field_events_by_tags)) {

      }
      /**We need to use that for preview situation*/
      if(isset($vars['content']['field_map_type']['#object']->field_map_type[LANGUAGE_NONE][0]['value'])) {
        $vars['field_map_type'] = $vars['content']['field_map_type']['#object']->field_map_type[LANGUAGE_NONE][0]['value'];
      }
      elseif(isset($wrapper->field_map_type) && $wrapper->field_map_type->value() != NULL) {
        $vars['field_map_type'] = $wrapper->field_map_type->value();
      }
      if($vars['field_map_type'] == 'map480') {
        drupal_add_js(drupal_get_path('theme', 'jagency') . "/js/jquery.pages.js", array('type' => 'file', 'scope' => 'header'));
        drupal_add_js(drupal_get_path('theme', 'jagency') . "/js/jquery.pages_map.js", array('type' => 'file', 'scope' => 'header'));
      }
      drupal_add_js(array('jafi_pages' => array('maplocationtype' => $vars['field_map_type'])), 'setting');
      drupal_add_js(array('jafi_pages' => array('maplocations' => $maplocations)), 'setting');
      drupal_add_js(array('jafi_pages' => array('map_zoom' => $zoom)), 'setting');
      break;
  }
}

function jagency_preprocess_node_map_event(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node'] -> nid);
  switch ($vars['view_mode']) {
    case 'teaser':
      $vars['class'] = jagency_get_color_recursive($vars['node']->field_event_main_category[LANGUAGE_NONE][0]['target_id']);
      $type = $wrapper -> field_event_type -> value();
      $vars['view_mode'] = 'teaser-' . $type;
      switch($type) {
        case 'mini_story':
          if (isset($vars['content']['field_button_reference'])) {
            $vars['content']['field_button_reference_title'] = $vars['content']['field_button_reference']['#object']->title;
            $vars['content']['field_button_reference'] = field_view_field('node', $vars['node'], 'field_button_reference', array('label' => 'hidden', 'type' => 'entityreference_entity_id'));
            $vars['content']['field_button_reference'] = $vars['content']['field_button_reference'][0]['#markup'];
          } else {
            $vars['content']['field_button_reference_title'] = '';
            $vars['content']['field_button_reference'] = '';
          }
          if(isset($vars['content']['field_main_image'])) {
            $vars['content']['field_main_image'][0]['#image_style'] = 'image50x50';
            $vars['content']['field_main_image'][0]['#item']['attributes'] = array('class' => array('pic'));
          }
          break;
        default:
          $vars['content']['field_main_image'][0]['#image_style'] = 'image130x117';
          break;
      }
  }
}

function jagency_preprocess_node_partners(&$vars) {
  switch ($vars['view_mode']) {
    case 'full' :
      foreach ($vars['content']['field_c_blocks'] as $key => $value) {
        if (is_array($value) && isset($value['#theme_wrappers'])) {
          unset($vars['content']['field_c_blocks'][$key]['#theme_wrappers']);
        }
      }
      foreach ($vars['content']['field_links_box'] as $key => $value) {
        if (is_array($value) && isset($value['#theme_wrappers'])) {
          unset($vars['content']['field_links_box'][$key]['#theme_wrappers']);
        }
      }
      break;
  }
}

/**
 * Custom preproccess for node type quote
 */
function jagency_preprocess_node_quote(&$vars) {
  switch ($vars['view_mode']) {
    case 'blog' :
      if (!isset($vars['content']['field_quote'])) {
        $vars['content']['field_quote'] = field_view_field('node', $vars['node'], 'field_quote', array('label' => 'hidden', 'type' => 'plaintext'));
      }
      if (!isset($vars['content']['field_quote_author'])) {
        $vars['content']['field_quote_author'] = field_view_field('node', $vars['node'], 'field_quote_author', array('label' => 'hidden', 'type' => 'plaintext'));
      }
      if (!isset($vars['content']['field_quote_reference'])) {
        $vars['content']['field_quote_reference'] = field_view_field('node', $vars['node'], 'field_quote_reference', array('label' => 'hidden', 'type' => 'entityreference_entity_id'));
        $vars['content']['field_quote_reference'] = $vars['content']['field_quote_reference'][0]['#markup'];
      }

      $vars['color'] = '';
      $vars['blog_color'] = '';

      $node = node_load($vars['content']['field_quote_reference']);
      if (!isset($node -> nid) || intval($node -> nid) == 0) {
        $vars['node'] -> status = 0;
        return;
        ///d($vars['node']);
      }
      $_user = user_load($node -> uid);
      $name = field_view_field('user', $_user, 'field_profile_name');
      $blog = field_view_field('node', $node, 'field_blog', array('label' => 'hidden', 'type' => 'entityreference_entity_id'));
      $vars['author'] = l($name[0]['#markup'], 'blog/' . $blog[0]['#markup'] . '/user/' . $vars['node'] -> uid);
      break;
  }
}

function jagency_preprocess_node_webform(&$vars) {
  $wrapper = entity_metadata_wrapper('node', $vars['node']);
  if ($wrapper -> field_machine_name -> value()) {
    $vars['view_mode'] = $wrapper -> field_machine_name -> value();
  }
}

/**
 * Custom preproccess for node type blog entry
 */
function jagency_preprocess_node_blog_entry(&$vars) {
  global $language;

  $menuitem = menu_get_item();
  switch ($vars['view_mode']) {
    case 'simple':
      $vars['content']['field_description'] = field_view_field('node', $vars['node'], 'field_teaser', array('label' => 'hidden', 'type' => 'plaintext'));
      break;
    case 'blog_category' :
    case 'blog_category_first' :
    case 'blog_category_site' :
    case 'global_teaser' :
    case 'program_lobby_small' :
    case 'global_teaser_big' :
    case 'content_filter':
      $vars['content']['video'] = '';
      if (!isset($vars['content']['field_frontpage_image'])) {
        $vars['content']['field_frontpage_image'] = field_view_field('node', $vars['node'], 'field_frontpage_image', array('label' => 'hidden'));
        switch($vars['view_mode']) {
          case 'blog_category_first' :
            $display = 'blog_slider';
            $vars['content']['field_frontpage_image'][0]['#image_style'] = 'blog_slider';
            jagency_video_builder($vars, 'field_frontpage_image', $display);
            break;
          case 'global_teaser_big' :
            $display = 'global_teaser_big';
            $vars['content']['field_frontpage_image'][0]['#image_style'] = 'program_lobby_big';
            jagency_video_image_builder($vars, 'field_frontpage_image', $display);
            break;
          case 'program_lobby_small' :
          case 'content_filter':
            $display = 'program_lobby_small';
            $vars['content']['field_frontpage_image'][0]['#image_style'] = 'program_lobby_small';
            jagency_video_image_builder($vars, 'field_frontpage_image', $display);
            break;
          case 'blog_category' :
            $display = 'blog_category';
            $vars['content']['field_frontpage_image'][0]['#image_style'] = 'blog_category';
            jagency_video_image_builder($vars, 'field_frontpage_image', $display);
            break;
          default :
            $display = 'blog_category';
            $vars['content']['field_frontpage_image'][0]['#image_style'] = 'blog_category';
            jagency_video_builder($vars, 'field_frontpage_image', $display);
            break;
        }
        $vars['content']['field_frontpage_image'] = strip_tags(render($vars['content']['field_frontpage_image']), '<img>');
      }
      if (!isset($vars['content']['field_teaser'])) {
        $vars['content']['field_teaser'] = field_view_field('node', $vars['node'], 'field_teaser', array('label' => 'hidden', 'type' => 'plaintext'));
      }

      $category = field_view_field('node', $vars['node'], 'field_category');
      $category = $category['#items'][0]['taxonomy_term'];
      $parents = taxonomy_get_parents($category -> tid);

      if (count($parents)) {
        $category = array_pop($parents);
      }

      $vars['color'] = $vars['blog_color'] = '';

      switch($menuitem['path']) {
        case 'blog/%/category/%' :
          $category = $menuitem['map'][3] -> data;
          $color = field_view_field('taxonomy_term', $category, 'field_color');
          $vars['color'] = isset($color['#items'][0]) ? $color['#items'][0]['value'] : '';
          $vars['blog_color'] = ' class=" ' . $vars['color'] . 'Bg"';
          break;

        default :
          $category = field_view_field('node', $vars['node'], 'field_default_color');
          if (isset($category['#items'][0]['entity'])) {
            $vars['category'] = $category['#items'][0]['entity'];
            $color = field_view_field('taxonomy_term', $category['#items'][0]['entity'], 'field_color');
            $color = $vars['color'] = isset($color['#items'][0]) ? $color['#items'][0]['value'] : '';
            if ($vars['color']) {
              $vars['blog_color'] = ' class=" ' . $vars['color'] . 'Bg"';
            }
          } else {
            $category = field_view_field('node', $vars['node'], 'field_category');
            $vars['category'] = $category['#items'][0]['taxonomy_term'];
          }
          break;
      }
      /*$color = field_view_field('taxonomy_term', $category, 'field_color');
       $vars['color'] = isset($color['#items'][0]) ? $color['#items'][0]['value'] : '';

       $vars['blog_color'] = '';
       if ($vars['color']) {
       $vars['blog_color'] = ' class=" ' . $vars['color'] . 'Bg"';
       }*/

      $_user = user_load($vars['node'] -> uid);
      $name = field_view_field('user', $_user, 'field_profile_name');
      $blog = field_view_field('node', $vars['node'], 'field_blog', array('label' => 'hidden', 'type' => 'entityreference_entity_id'));
      $vars['author'] = l($name[0]['#markup'], 'blog/' . $blog[0]['#markup'] . '/user/' . $vars['node'] -> uid);

      if ($vars['view_mode'] == 'blog_category') {
        $vars['content']['field_frontpage_image'] = str_replace('<img', '<img class="' . $vars['color'] . 'Border"', $vars['content']['field_frontpage_image']);
      }
      $vars['show_user_block'] = 0;
      if ($vars['view'] -> current_display == 'panel_pane_2') {
        $vars['show_user_block'] = 1;
      }
      break;

    case 'blog' :
    case 'teaser' :
      $vars['color'] = $vars['blog_color'] = $vars['content']['video'] = '';
      if (!isset($vars['content']['field_frontpage_image'])) {
        $vars['content']['field_frontpage_image'] = field_view_field('node', $vars['node'], 'field_frontpage_image', array('label' => 'hidden'));
        jagency_video_builder($vars, 'field_frontpage_image', 'blog_loby');
        $vars['content']['field_frontpage_image'][0]['#image_style'] = 'blog_loby';
      }
      if (!isset($vars['content']['field_teaser'])) {
        $vars['content']['field_teaser'] = field_view_field('node', $vars['node'], 'field_teaser', array('label' => 'hidden', 'type' => 'plaintext'));
      }
      $category = field_view_field('node', $vars['node'], 'field_default_color');
      if (isset($category['#items'][0]['entity'])) {
        $color = field_view_field('taxonomy_term', $category['#items'][0]['entity'], 'field_color');
        $vars['color'] = isset($color['#items'][0]) ? $color['#items'][0]['value'] : '';

        if ($vars['color']) {
          $vars['blog_color'] = ' class=" ' . $vars['color'] . 'Bg"';
        }
      }
      $_user = user_load($vars['node'] -> uid);
      $blog = field_view_field('node', $vars['node'], 'field_blog', array('label' => 'hidden', 'type' => 'entityreference_entity_id'));
      $user_wrapper = entity_metadata_wrapper('user', $vars['node'] -> uid);
      $name = $user_wrapper -> field_profile_name -> value();
      if (isset($blog[0])) {
        if ($name) {
          $vars['author'] = l($name, 'blog/' . $blog[0]['#markup'] . '/user/' . $vars['node'] -> uid);
        } else {
          $vars['author'] = l($_user -> name, 'blog/' . $blog[0]['#markup'] . '/user/' . $vars['node'] -> uid);
        }
      } else {
        $vars['author'] = l($name[0]['#markup'], 'blog/user/' . $vars['node'] -> uid);
      }

      break;

    case 'full' :
      $vars['color'] = $vars['blog_color'] = '';
      $category = field_view_field('node', $vars['node'], 'field_default_color');
      if (isset($category['#items'][0]['entity'])) {
        $vars['category'] = $category['#items'][0]['entity'];
        $color = field_view_field('taxonomy_term', $category['#items'][0]['entity'], 'field_color');
        $color = $vars['color'] = isset($color['#items'][0]) ? $color['#items'][0]['value'] : '';
        if ($vars['color']) {
          $vars['blog_color'] = ' class=" ' . $vars['color'] . 'Bg"';
        }
      } else {
        $category = field_view_field('node', $vars['node'], 'field_category');
        $vars['category'] = $category['#items'][0]['taxonomy_term'];
      }
      $vars['content']['blog_reference'] = field_view_field('node', $vars['node'], 'field_blog', array('label' => 'hidden', 'type' => 'entityreference_entity_id'));

      module_load_include('inc', 'media_youtube', '/includes/media_youtube.formatters.inc');
      $images = field_get_items('node', $vars['node'], 'field_slider_images');
      $vars['content']['images'] = '';
      if (count($images) && is_array($images)) {
        foreach ($images as $image) {
          $video = '';
          $field = field_view_value('node', $vars['node'], 'field_slider_images', $image);
          $field['#image_style'] = 'blog_slider';
          $text = isset($image['field_file_image_title_text'][LANGUAGE_NONE][0]['safe_value']) ? t($image['field_file_image_title_text'][LANGUAGE_NONE][0]['safe_value']) : '';
          $copyright = isset($image['field_copyright'][LANGUAGE_NONE][0]['safe_value']) ? t($image['field_copyright'][LANGUAGE_NONE][0]['safe_value']) : '';
          $photographer = isset($image['field_photographer'][LANGUAGE_NONE][0]['safe_value']) ? t($image['field_photographer'][LANGUAGE_NONE][0]['safe_value']) : '';
          if (isset($field['#item']) && $field['#item']['type'] == 'video') {
            $file = file_load($field['#item']['fid']);
            $display = array('settings' => array('image_style' => 'blog_slider'));
            $field = media_youtube_file_formatter_image_view($file, $display, LANGUAGE_NONE);
            $video = $file -> uri;
          }

          if (isset($field['#item']) && $field['#item']['title']) {
            //$tmp = t($field['#item']['title'], array(), array('langcode' => 'english'));
            $field['#item']['title'] = t($field['#item']['title']);
          }
          if (isset($field['#item']) && $field['#item']['alt']) {
            //$tmp = t($field['#item']['alt'], array(), array('langcode' => 'english'));
            $field['#item']['alt'] = t($field['#item']['alt']);
          }

          //d($field['#item']);
          $vars['content']['images'] .= '<li>' . ($video ? '<div class="playBtn" data-size="730x386" data-href="' . $video . '"></div>' : '') . strip_tags(render($field), '<img>');
          $vars['content']['images'] .= '<div class="carouselCaption carouselCaption_' . $vars['color'] . '"><p>' . truncate_utf8($text, 300) . '</p>';
          $vars['content']['images'] .= '<span class="cr">' . ($photographer ? $photographer : '') . ($copyright ? ', ' . $copyright . ' ©' : '') . '</span></div></li>';
        }
      }
      $vars['content']['body'] = preg_replace('#(<[a-z ]*)(style=("|\')(.*?)("|\'))([a-z ]*>)#', '\\1\\6', render($vars['content']['body']));
      $vars['content']['body'] = preg_replace('#<div>(.*?)</div>#', '<p>\0</p>', $vars['content']['body']);
      $vars['content']['body'] = strip_tags($vars['content']['body'], '<p><br><img><em><strong><b><i><ul><li><u><a><iframe>');
      break;
  }
}