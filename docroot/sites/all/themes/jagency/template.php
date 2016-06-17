<?php
/**
 * Hook theme
 */
function jagency_theme() {
  $theme_path = path_to_theme();
  return array(
    'jagency_main_menu_link' => array(
      'variables' => array('item' => NULL, 'counter' => NULL, 'menu_content' => NULL),
      'path' => $theme_path . '/templates/custom',
      'template' => 'jagency_main_menu_link'
    ),
    'field_collection_view' => array(
      'render element' => 'element',
      'path' => $theme_path . '/templates/custom',
      'template' => 'jagency_field_collection_view'
    ),
    'image_formatter_link' => array(
      'variables' => array('item' => NULL, 'path' => NULL, 'image_style' => NULL),
    ),
  );
}

/**
 * Implementation of hook_html_head_alter
 */
function jagency_html_head_alter(&$head_elements) {
  $header = drupal_get_http_header();
  if (isset($header['status']) && $header['status'] == '403 Forbidden') {
    unset($head_elements['metatag_canonical']);
    foreach ($head_elements as $key => $element) {
      if (strpos($key, 'metatag_og') !== false) {
        unset($head_elements[$key]); 
      }
    }
  }
}

function get_copyright($field_name, $nid, $class = 'cr') {
  if(isset($nid) && isset($field_name)) {
    $Wrapper = entity_metadata_wrapper('node', $nid);
    $image = $Wrapper->$field_name->value();
    $output = array();
    $file_wrapper = entity_metadata_wrapper('file', $image['fid']);
    if(isset($file_wrapper->field_copyright) && trim($file_wrapper->field_copyright->value()) != NULL) {
      $output[] = $file_wrapper->field_copyright->value() . ' ©';
    }
    if(isset($file_wrapper->field_photographer) && trim($file_wrapper->field_photographer->value()) != NULL) {
      $output[] = $file_wrapper->field_photographer->value();
    }
    return '<span class="' . $class . '">' . join(', ', $output) . '</span>';
  }
}

/**
 * Override of theme_breadcrumb().
 */
function jagency_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $output = '';
  $title = drupal_get_title();
  if (!empty($title)) {
    $breadcrumb[] = '<span>' . $title . '</span>';
  }
  if (count($breadcrumb) == 1) {
    return '';
  }
  if (!empty($breadcrumb)) {
    $breadcrumb[0] = l('<strong>' . t('The Jewish Agency') . '</strong>', '', array('html' => true, 'absolute' => true));
    $output .= implode('<span>&nbsp;&nbsp;&nbsp;/&nbsp;&nbsp;&nbsp;</span>', $breadcrumb);
    return $output;
  }
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function jagency_preprocess_node(&$vars, $hook) {
  jagency_theme_load_include('inc', 'jagency', 'preprocess/node.preprocess');
  $function = __FUNCTION__ . '_' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Override or insert variables into the user templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function jagency_preprocess_user_profile(&$vars) {
  jagency_theme_load_include('inc', 'jagency', 'preprocess/user.preprocess');
  $function = __FUNCTION__ . '_' . $vars['elements']['#view_mode'];
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Implements jew date converter
 */
function convert_jew_date($date) {
  $date = explode('/', jdtojewish(gregoriantojd( date('m', $date), date('d', $date), date('Y', $date)), false , CAL_JEWISH_ADD_ALAFIM));
  $month = array(1 => "Tishrei", 2 => "Heshvan", 3 => "Kislev", 4 => "Tevet", 5 => "Shevat", 6 => "Adar", 7 => "Adar II", 8 => "Nisan", 9 => "Iyar", 10 => "Sivan", 11 => "Tamuz", 12 => "Av", 13 => "Elul");
  $date[0] = $month[$date[0]];
  
  return implode(' ', array($date[1], $date[0], $date[2]));
}

/**
 * Include file
 */
function jagency_theme_load_include($type, $module, $name = NULL) {
  if (!isset($name)) {
    $name = $module;
  }

  if (function_exists('drupal_get_path')) {
    $file = DRUPAL_ROOT . '/' . drupal_get_path('theme', $module) . "/$name.$type";
    if (is_file($file)) {
      require_once $file;
      return $file;
    }
  }
  return FALSE;
}

/**
 * Hook preproccess page
 */
function jagency_preprocess_page(&$variables) {
  global $da_site;
  
  $settings = array(
    "isRTL" => $da_site == 'he' ? true : false,
  );

  drupal_add_js($settings, "setting");
  $menuitems = menu_get_item();
  if ($menuitems['page_callback'] == 'page_manager_page_execute') {
    if (count($menuitems['load_functions']) == 1 && count($menuitems['page_arguments']) > 1) {
      drupal_goto(variable_get('site_404', '404'));
    }
  }
  $breadcrumb = array();
  $breadcrumb[] = l('<strong>' . t('The Jewish Agency') . '</strong>', '', array('html' => true, 'absolute' => true));
  switch ($menuitems['path']) {        
    case 'opportunities':
      $breadcrumb[] = l(t('Find an Opportunity'), 'opportunities');
      drupal_set_breadcrumb($breadcrumb);
      break;   
    case 'board-of-governors':
    case 'executive-members':
      $breadcrumb[] = l(t('Inside The Jewish Agency'), 'insideja');
      drupal_set_breadcrumb($breadcrumb);
      break;
    case 'node/%':  
      switch($menuitems['page_arguments'][0]->type) {
        case 'career':
          $breadcrumb[] = l(t('Career'), 'careers');
          drupal_set_breadcrumb($breadcrumb);
          break;
          
        case 'blog_entry':
          $path = explode('/', request_uri());
          if (isset($path[2])) {
            $wraper = entity_metadata_wrapper('node', intval($path[2]));
            if ($wraper->title) {
              $breadcrumb[] = l($wraper->title->value(), 'node/' . intval($path[2]));
            }
          }
          drupal_set_breadcrumb($breadcrumb);
          break;
        case 'program_details':
          $wraper = entity_metadata_wrapper('node', $menuitems['page_arguments'][0]->nid);
          $field_main_category = $wraper->field_main_category->value();
          if (isset($field_main_category->tid)) {
            $main_parent = taxonomy_get_parents_all($field_main_category->tid);
            if(isset($main_parent)) {
              $field_main_category = $main_parent;
            }
            if ($wraper->field_main_category) {
              $field_main_category = array_reverse($field_main_category);
              foreach ($field_main_category as $key => $value) {
                if($value->name != NULL) {
                  $term = str_replace(' ', '-', strtolower($value->name));
                  $value->name = jagency_taxonomy_translate($value->tid, $value->name);
                  $breadcrumb[] = l('<strong>' . $value->name . '</strong>', $term, array('html' => true, 'absolute' => true));
                }
              }
            }
            if ($wraper->field_program) {
              $program = array_pop($wraper->field_program->value());
              if (isset($program->nid)) {
                $url = 'node/' . $program->nid;
                $breadcrumb[] = l('<strong>' . $program->title . '</strong>', $url, array('html' => true, 'absolute' => true));
              }
            }
            drupal_set_breadcrumb($breadcrumb);
          }
          break;
        default:
          $wraper = entity_metadata_wrapper('node', $menuitems['page_arguments'][0]->nid);
          if(isset($wraper->field_main_category) && $wraper->field_main_category->value() != NULL) {
            $field_main_category = $wraper->field_main_category->value();
            $main_parent = taxonomy_get_parents_all($field_main_category->tid);
            if(isset($main_parent)) {
              $field_main_category = $main_parent;
            }
            if ($wraper->field_main_category) {
              $field_main_category = array_reverse($field_main_category);
              foreach ($field_main_category as $key => $value) {
                if($value->name != NULL) {
                  $term = str_replace(' ', '-', strtolower($value->name));
                  $value->name = jagency_taxonomy_translate($value->tid, $value->name);
                  $breadcrumb[] = l('<strong>' . $value->name . '</strong>', $term, array('html' => true, 'absolute' => true));
                }
              }
            }
            drupal_set_breadcrumb($breadcrumb);
            }
          break;
      }
      break;
    case 'blog/%/tag/%':
    case 'blog/%/category/%':
      $breadcrumb[] = l('<strong>' . t($menuitems['page_arguments'][1]->data->title) . '</strong>', 'node/' . $menuitems['page_arguments'][1]->data->nid, array('html' => true, 'absolute' => true));
      drupal_set_breadcrumb($breadcrumb);
      drupal_set_title(jagency_taxonomy_translate($menuitems['page_arguments'][2]->data->tid, $menuitems['page_arguments'][2]->data->name));
      break;
    case 'blog/%/user/%':
      $breadcrumb[] = l('<strong>' . t($menuitems['page_arguments'][1]->data->title) . '</strong>', 'node/' . $menuitems['page_arguments'][1]->data->nid, array('html' => true, 'absolute' => true));
      $name = field_view_field('user', $menuitems['page_arguments'][2]->data, 'field_profile_name');
      $breadcrumb[] = $name[0]['#markup'];
      drupal_set_breadcrumb($breadcrumb);
      break;
  }
  
  //---Calling to Bottom links---////
  $social_networks = module_invoke('views', 'block_view', 'geo_bottom_links-social_networks');
  $variables['social_networks'] = $social_networks;
  
  $phone_number = module_invoke('views', 'block_view', 'geo_bottom_links-phone_number');
  $variables['phone_number'] = $phone_number;
  
  ////---Embed content without theme---->
  if (isset($_GET['response_type']) && $_GET['response_type'] == 'embed') {
    $variables['theme_hook_suggestions'][] = 'page__embed';
  }
  if ((isset($_GET['response_type']) && $_GET['response_type'] == 'json') || arg(0) == 'ajax') {
    $variables['theme_hook_suggestions'][] = 'page__json';
  }
}

/**
 * Hook preproccess html
 */
function jagency_preprocess_html(&$variables, $suggestions) {
  //drupal_add_css(path_to_theme() . '/css/style-ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE', '!IE' => FALSE), 'preprocess' => FALSE));
  if (isset($_GET['response_type']) && $_GET['response_type'] == 'embed') {
    $variables['theme_hook_suggestions'][] = 'html__embed';
      // Populate the page template suggestions.
    //$variables['theme_hook_suggestions'] = $suggestions;
  }
  if ((isset($_GET['response_type']) && $_GET['response_type'] == 'json') || arg(0) == 'ajax') {
    $variables['theme_hook_suggestions'][] = 'html__json';
      // Populate the page template suggestions.
  }
}

/**
 * Main menu render
 */
function jagency_main_menu() {
  $domain = domain_get_domain();
  $type = domain_conf_variable_get($domain['domain_id'], 'menu_main_links_source');
  if (!$type) {
    $type = 'main-menu'; 
  }
  $items = menu_tree_all_data($type, $link = NULL, $max_depth = 2);
  $output = '';
  $counter = 1;
  foreach($items as $key => $value) {
    if ($value['link']['hidden'] == 0) {
      $items = '';
      if (isset($value['link']['options']['attributes']['term'])) {
        $items = views_embed_view('main_menu_items', 'default', $value['link']['options']['attributes']['term']);
      }
      $output .= theme('jagency_main_menu_link', array('item' => $value, 'counter' => $counter, 'menu_content' => $items));
      $counter++;
    }
  }
  return $output;
}

/**
 * Output custom footer content
 */
function jagency_footer_content() {
  $domain = domain_get_domain();
  if(domain_conf_variable_get($domain['domain_id'], "footer_content")) {
    print domain_conf_variable_get($domain['domain_id'], "footer_content"); 
  }
}

/**
 * Languages menu
 */
function jagency_menu_languages() {
  $items = menu_tree_all_data('menu-languages', $link = NULL, $max_depth = 1);
  $currdomain = url('', array('absolute' => true));
  $currlanguage = '';
  $langlist = '';
  foreach($items as $key => $value)  {
    if ($currdomain == $value['link']['link_path']) {
      $currlanguage = $value['link']['link_title'];
    }
    if ($value['link']['hidden'] == 0) {
      $langlist .= '<li>' .  l($value['link']['link_title'], $value['link']['link_path']) . '</li>';
    }
  }
  return '<button class="">' . $currlanguage . ' </button><ul>' . $langlist . '</ul>';
}

/**
 * Footer menu render
 */
function jagency_footer_top_menu() {
  $domain = domain_get_domain();
  $type = domain_conf_variable_get($domain['domain_id'], 'menu_secondary_links_source');
  if (!$type) {
    $type = 'menu-footer-top'; 
  }
  $items = menu_tree_all_data($type, $link = NULL, $max_depth = 2);
  $output = '';
  foreach($items as $item) {
    $output .= '<dl><dt>' . l(t($item['link']['link_title'], array(), array('context' => 'item:' . $item['link']['mlid'] . ':title')), $item['link']['link_path'], array('html' => true)) . '</dt>';
    foreach ($item['below'] as $subitem) {
      $output .= '<dd>' . l(t($subitem['link']['link_title'], array(), array('context' => 'item:' . $item['link']['mlid'] . ':title')), $subitem['link']['link_path'], array('html' => true)) . '</dd>';
    }
    $output .= '</dl>';
  }
  return $output;
}

/**
 * Return css color id by tid
 */
function jagency_get_color_by_term($color) {
  switch ($color) {
    case 'turquoise':
      return 1;
      break;
      
    case 'green':
      return 2;
      break;
      
    case 'yellow':
      return 3;
      break;
      
    case 'orange':
      return 4;
      break;
      
    default:
      return 5;
  }
}

/**
 * Return css color id by tid
 */
function jagency_get_color_recursive($tid) {
  $parents = taxonomy_get_parents($tid);
  if (is_array($parents) && count($parents)) {
    $tid = $parents[key($parents)] -> tid;
  }
  switch ($tid) {
    case '1':
    case '2':
    case '3':
    case '4':
      return $tid;
      break;
      
    default:
      return 5;
  }
}

/**
 * Return css color id by tid
 */
function jagency_get_color_by_tid($tid) {
  switch ($tid) {
    case '1':
    case '2':
    case '3':
    case '4':
      return $tid;
      break;
      
    default:
      return 5;
  }
}

/**
 * Video field builder
 */
function jagency_video_builder(&$vars, $field, $style = NULL) {
  $vars['content'][$field] = field_view_field('node', $vars['node'], $field, array('label' => 'hidden', 'settings' => array('image_style' => $style)));
  if (isset($vars['content'][$field][0]['#item']) && $vars['content'][$field][0]['#item']['type'] == 'video') {
    module_load_include('inc', 'media_youtube', '/includes/media_youtube.formatters.inc');
    $display = array('settings' => array('image_style' => $style));
    $file = file_load($vars['content'][$field][0]['#item']['fid']);
    $vars['content'][$field] = media_youtube_file_formatter_image_view($file, $display, LANGUAGE_NONE);
    $vars['content'][$field . '_video'] = $file->uri;
    $vars['content']['video'] = $file->uri;
  }
}

/**
 * Video field builder
 */
function jagency_video_image_builder(&$vars, $field, $style = NULL) {
  $vars['content'][$field] = field_view_field('node', $vars['node'], $field, array('label' => 'hidden', 'settings' => array('image_style' => $style)));
  if (isset($vars['content'][$field][0]['#item']) && $vars['content'][$field][0]['#item']['type'] == 'video') {
    module_load_include('inc', 'media_youtube', '/includes/media_youtube.formatters.inc');
    $display = array('settings' => array('image_style' => $style));
    $file = file_load($vars['content'][$field][0]['#item']['fid']);
    $vars['content'][$field] = media_youtube_file_formatter_image_view($file, $display, LANGUAGE_NONE);
  }
}

/**
 * Returns HTML for an image.
 *
 * @param $variables
 *   An associative array containing:
 *   - path: Either the path of the image file (relative to base_path()) or a
 *     full URL.
 *   - width: The width of the image (if known).
 *   - height: The height of the image (if known).
 *   - alt: The alternative text for text-based browsers. HTML 4 and XHTML 1.0
 *     always require an alt attribute. The HTML 5 draft allows the alt
 *     attribute to be omitted in some cases. Therefore, this variable defaults
 *     to an empty string, but can be set to NULL for the attribute to be
 *     omitted. Usually, neither omission nor an empty string satisfies
 *     accessibility requirements, so it is strongly encouraged for code
 *     calling theme('image') to pass a meaningful value for this variable.
 *     - http://www.w3.org/TR/REC-html40/struct/objects.html#h-13.8
 *     - http://www.w3.org/TR/xhtml1/dtds.html
 *     - http://dev.w3.org/html5/spec/Overview.html#alt
 *   - title: The title text is displayed when the image is hovered in some
 *     popular browsers.
 *   - attributes: Associative array of attributes to be placed in the img tag.
 */
function jagency_image($variables) {
  $attributes = $variables['attributes'];
  $attributes['src'] = file_create_url($variables['path']);

  foreach (array('width', 'height', 'alt', 'title') as $key) {
    switch($key) {
      case 'alt':
      case 'title':
        if (isset($variables[$key]) && $variables[$key]) {
          $attributes[$key] = t($variables[$key]);
        }
        break;
      default:
        if (isset($variables[$key])) {
          $attributes[$key] = $variables[$key];
        }
        break;
    }
  }
  return '<img' . drupal_attributes($attributes) . ' />';
}


/**
 * Implements hook_library_alter().
 */
function jagency_css_alter(&$css) {
  global $da_site;
  
  unset($css['misc/ui/jquery.ui.core.css']);
  unset($css['misc/ui/jquery.ui.theme.css']);
  unset($css['misc/ui/jquery.ui.datepicker.css']);
  unset($css['misc/ui/jquery.ui.slider.css']);
  
}

/**
 * Implements hook_library_alter().
 */
function jagency_js_alter(&$js) {

  if (isset($js['misc/jquery.form.js'])) {
    $js['misc/jquery.form.js']['data'] = 'sites/all/modules/external/jquery_update/replace/misc/jquery.form.js';
    $js['misc/jquery.form.js']['version'] = '2.69';
  }

  if (isset($js['misc/jquery.js'])) {
    //unset($js['misc/jquery.js']);
    $js['misc/jquery.js']['data'] = path_to_theme() . '/js/jquery-1.8.3.min.js'; 
    unset($js['misc/ui/jquery.ui.core.min.js']);
    unset($js['misc/ui/jquery.ui.widget.min.js']);
    unset($js['misc/ui/jquery.ui.mouse.min.js']);
    unset($js['misc/ui/jquery.ui.slider.min.js']);
    unset($js['misc/ui/jquery.ui.mouse.min.js']);
    unset($js['misc/ui/jquery.ui.draggable.min.js']);
    unset($js['misc/ui/jquery.ui.droppable.min.js']);
    unset($js['misc/ui/jquery.ui.sortable.min.js']);
  }

  /*module_load_include('module', 'jagency_update', 'jagency_update');
  if (function_exists('jquery_update_library_alter')) {
    $replace = array();
    jquery_update_library_alter($replace, 'system');
    foreach ($replace as $key => $value) {
      if (isset($value['js'])) {
        foreach ($value['js'] as $id => $data) {
          if (isset($js[$id])) {
            $js[$id]['data'] = $data['data'];
          }
        }
      }
    }
  }*/
}

/**
 * Render Block
 */
function jagency_block_render($module, $block_id) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  $build = _block_get_renderable_array($block_content);
  $block_rendered = drupal_render($build);
  return $block_rendered;
}

/**
 * Helper function to get specific element
 */
function jagency_theme_get_element_bytag($html, $tag, $id = 0) {
  $document = new DOMDocument();
  libxml_use_internal_errors(true);
  $document->loadHTML(mb_convert_encoding($html, 'HTML-ENTITIES', "UTF-8"));
  $lst = $document->getElementsByTagName($tag);
  return $document->saveXML($lst->item($id));
}

/**
 * Helper function to get specific element
 */
function jagency_theme_get_element_byclass($html, $class, $id = 0) {
  $document = new DOMDocument();
  libxml_use_internal_errors(true);
  $document->loadHTML(mb_convert_encoding($html, 'HTML-ENTITIES', "UTF-8"));
  $xpath = new DomXPath($document);
  $lst = $xpath->query('//*[@class="'.$class.'"]');
  return $document->saveXML($lst->item($id));
}

/**
 * Helper function to get specific element
 */
function jagency_theme_get_element_byid($html, $tagid, $id = 0) {
  $document = new DOMDocument();
  libxml_use_internal_errors(true);
  $document->loadHTML(mb_convert_encoding($html, 'HTML-ENTITIES', "UTF-8"));
  $item = $document->getElementById($tagid);
  return $document->saveXML($item);
}

function widget_filter_box($voc = '', $widget, $AnyOption = 0, $default_values = array()) {
  global $language;
  $output = '';
  if($voc != NULL) {
    $taxonomy_terms = array();
    if($AnyOption == 1) {
      $taxonomy_terms['ALL'] = t("ANY");
    }
    foreach(taxonomy_get_tree($voc) as $key => $value) {
      $taxonomy_terms[$value->tid] = jagency_taxonomy_translate($value->tid, $value->name);
      //ARRAY FOR TREE
      if(isset($value->parents) && $value->parents[0] != 0) {
        $taxonomy_tree_terms['parent'][$value->parents[0]][$value->tid] = jagency_taxonomy_translate($value->tid, $value->name);
      } else {
        $taxonomy_tree_terms['main'][$value->tid] = jagency_taxonomy_translate($value->tid, $value->name);
      }
    }
  }
  
  switch ($widget) {
    case 'drop_down':
      $output .= '<div class="widget_filter_box widget_filter_dropdown vocabluary_id_' . $voc . '" id="vocabluary_id_' . $voc . '">';
      $output .= '<select name="vocabluary_id_' . $voc . '" id="vocabluary_id_' . $voc . '" class="drop_down">';
      $output .= '<option value="0">' . t('Please select') . '</option>';
      foreach($taxonomy_terms as $key => $tax_name) {
        $output .= '<option value="' . $key . '"'.(in_array($key, $default_values) ? ' selected="selected"' : '').'>' . $tax_name . '</option>';
      }
      $output .= '</select>';
      $output .= '</div>';
      break;
      
    case 'radio_box':
      $output .= '<div class="widget_filter_box widget_filter_radiobox vocabluary_id_' . $voc . '" id="vocabluary_id_' . $voc . '">';
      foreach($taxonomy_terms as $key => $tax_name) {
        $output .= '<div class="radiobox_div widget_filter">';
        $output .= '<input type="radio" id="term_id_' . $key . '" name="vocabluary_id_' . $voc . '" value="' . $key . '"'.(in_array($key, $default_values) ? ' checked="checked"' : '').'>';
        $output .= '<label class="option'.($key == 'ALL' ? ' select_all_inside':'').'" for="term_id_' . $key . '">' . $tax_name . '</label>';
        $output .= '</div>';
      }
      $output .= '</div>'; 
      break;
      
    case 'list':
      $output .= '<div class="widget_filter_box widget_filter_list vocabluary_id_' . $voc . '" id="vocabluary_id_' . $voc . '">';
      foreach($taxonomy_terms as $key => $tax_name) {
        $output .= '<div class="listbox_div widget_filter">';
        $output .= '<input type="checkbox" id="term_id_' . $key . '" name="vocabluary_id_' . $voc . '" value="' . $key . '"'.(in_array($key, $default_values) ? ' checked="checked"' : '').'>';
        $output .= '<label class="option'.($key == 'ALL' ? ' select_all_inside':'').'" for="term_id_' . $key . '">' . $tax_name . '</label>';
        $output .= '</div>';
      }   
      $output .= '</div>';
      $output .= '<div class="clear"><a href="#" class="select_all" id="select_all_vocabluary_id_' . $voc . '">'.t('All').'</a>&nbsp;&nbsp;&nbsp;<a href="#" class="Clear_all" id="vocabluary_id_' . $voc . '">' . t('Clear') . '</a></div>';
      break;
      
    case 'check_box_tree':
      drupal_add_js("(function() {
        jQuery('#tree" . $voc . "').checkboxTree({
            onCheck: {
                ancestors: 'uncheck',
                descendants: 'uncheck'
            },
            onUncheck: {
                ancestors: 'uncheck'
            },
            collapseImage: '/". drupal_get_path('theme', 'jagency') . "/css/images/minus_icon.gif',
            expandImage: '/". drupal_get_path('theme', 'jagency') . "/css/images/plus_icon.gif',
        });}());", array('type' => 'inline', 'scope' => 'footer', 'weight' => 99));
        
      $output .= '<div class="widget_filter_box widget_filter_checkbox vocabluary_id_' . $voc . '" id="vocabluary_id_' . $voc . '">';
      $output .= '<ul id="tree' . $voc . '">';
      foreach($taxonomy_tree_terms['main'] as $key => $tax_name) {
        $output .= '<li class="checkbox_div widget_filter">';
        $output .= '<input type="checkbox" id="term_id_' . $key . '" name="vocabluary_id_' . $voc . '" value="' . $key . '">';
        $output .= '<label class="option'.($key == 'ALL' ? ' select_all_inside':'').'" for="term_id_' . $key . '">' . $tax_name . '</label>';
        if(isset($taxonomy_tree_terms['parent'][$key])) {
          $output .= '<ul style="display: none;">';
          foreach($taxonomy_tree_terms['parent'][$key] as $key2 => $value2) {
            $output .= '<li class="checkbox_div widget_filter"><input type="checkbox" id="term_id_' . $key2 . '" name="vocabluary_id_' . $voc . '" value="' . $key2 . '">';
            $output .= '<label class="option" for="term_id_' . $key2 . '">' . $value2 . '</label></li>';
          }
          $output .= '</ul>';
        }
        $output .= '</li>';
      }
      $output .= '</ul>';
      $output .= '</div>';
      $output .= '<div class="clear"><a href="#" class="select_all" id="select_all_vocabluary_id_' . $voc . '">'.t('All').'</a>&nbsp;&nbsp;&nbsp;<a href="/" class="Clear_all" id="vocabluary_id_' . $voc . '">' . t('Clear') . '</a></div>';

      break;
      
    case 'check_box':
      $output .= '<div class="widget_filter_box widget_filter_checkbox vocabluary_id_' . $voc . '" id="vocabluary_id_' . $voc . '">';
      foreach($taxonomy_terms as $key => $tax_name) {
        $output .= '<div class="checkbox_div widget_filter">';
        $output .= '<input type="checkbox" id="term_id_' . $key . '" name="vocabluary_id_' . $voc . '" value="' . $key . '">';
        $output .= '<label class="option'.($key == 'ALL' ? ' select_all_inside':'').'" for="term_id_' . $key . '">' . $tax_name . '</label>';
        $output .= '</div>';
      }
      $output .= '</div>';
      $output .= '<div class="clear"><a href="#" class="select_all" id="select_all_vocabluary_id_' . $voc . '">'.t('All').'</a>&nbsp;&nbsp;&nbsp;<a href="/" class="Clear_all" id="vocabluary_id_' . $voc . '">' . t('Clear') . '</a></div>';
      break;
      
    case 'free_text':
      $output .= '<div class="widget_filter_box widget_filter_freetext">';
      $output .= '<div class="freetext_div widget_filter">';
      $output .= '<input type="text" id="free_search_content" name="free_search_content"><button id="search_submit"></button>';
      $output .= '</div>';
      break;
  }
  print $output;
}

function jagency_taxonomy_translate($tid, $name) {
  global $language;
  $translate = i18n_string_textgroup('taxonomy')->context_translate(array('taxonomy', $tid, 'name'), $name);
  if (isset($translate->translations[$language->language]) && $translate->translations[$language->language]) {
    $name = $translate->translations[$language->language];
  } else {
    $translate2 = i18n_string_textgroup('taxonomy')->context_translate(array('term', $tid, 'name'), $name);
    if (isset($translate2->translations[$language->language]) && $translate2->translations[$language->language]) {
      $name = $translate2->translations[$language->language];
    }
  }
  return $name;
}

function jagency_pages_widget_output($args) {
  $html = drupal_render(node_view(node_load($args),'teaser'));
  return array('html'=>'callbackfunc( {' . $html . '} )');
}

/**
 * Returns HTML for an image field formatter.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: Associative array of image data, which may include "uri", "alt",
 *     "width", "height", "title" and "attributes".
 *   - image_style: An optional image style.
 *   - path: An array containing the link 'path' and link 'options'.
 *
 * @ingroup themeable
 */
function jagency_image_formatter_link($variables) {
  $item = $variables['item'];
  $image = array(
    'path' => $item['uri'],
  );
  
  if (isset($item['field_file_image_alt_text'][LANGUAGE_NONE])) {
    $image['alt'] = $item['field_file_image_alt_text'][LANGUAGE_NONE][0]['value'];
    $image['title'] = $item['field_file_image_title_text'][LANGUAGE_NONE][0]['value'];
  }

  if (isset($item['attributes'])) {
    $image['attributes'] = $item['attributes'];
  }

  if (isset($item['width']) && isset($item['height'])) {
    $image['width'] = $item['width'];
    $image['height'] = $item['height'];
  }

  // Do not output an empty 'title' attribute.
  if (isset($item['title']) && drupal_strlen($item['title']) > 0) {
    $image['title'] = $item['title'];
  }

  if (isset($item['#style_name']) && $item['#style_name']) {
    $image['style_name'] = $item['#style_name'];
    $output = theme('image_style', $image);
  }
  else {
    $output = theme('image', $image);
  }
  // The link path and link options are both optional, but for the options to be
  // processed, the link path must at least be an empty string.
  if (isset($variables['item']['field_link'][LANGUAGE_NONE]) && $variables['item']['field_link'][LANGUAGE_NONE][0]['url'] != "") {
    $path = $variables['item']['field_link'][LANGUAGE_NONE][0]['url'];
    $options = array('attributes' => array('title' => (isset($item['field_file_image_title_text'][LANGUAGE_NONE])? $item['field_file_image_title_text'][LANGUAGE_NONE][0]['value'] : '')));
    // When displaying an image inside a link, the html option must be TRUE.
    $options['html'] = TRUE;
    $output = l($output, $path, $options);
  }
  return $output;
}