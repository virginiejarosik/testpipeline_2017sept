<?php

function jagency_mediafix() {
  
  $medialist = explode(',', 'thumbnail,medium,large,image730x548,authors_51x51,authors_big_image,authors_small_image,image515x495,image72x111,image730x386,image138x46,image240x144,image376x278,image930x518,image402x300,program_lobby_big,program_lobby_small,image130x117,image50x50,230x138,78x60,authors_small_image_bw,big_slider_image,blog_category,blog_loby,blog_side,blog_slider,crop_blog_loby,crop_blog_slider,menu_image,1200x755,293x290,355x286,480x292,980x230,980x462,image230x172,image480x270,image730x411,image112x85,image1400x789,image192x110,image192x110_bw,image389x225,image389x225_bw,image394x291,image586x340,image586x340_bw,image980x518,original,media_thumbnail,image980x386');
  foreach ($medialist as $media) {
    db_insert('file_display')
      ->fields(array(
        'name' => 'image__' . $media . '__file_field_colorbox',
        'weight' => '0',
        'status' => '0',
        'settings' => 'a:6:{s:19:\"colorbox_node_style\";s:0:\"\";s:20:\"colorbox_image_style\";s:0:\"\";s:16:\"colorbox_gallery\";s:4:\"post\";s:23:\"colorbox_gallery_custom\";s:0:\"\";s:16:\"colorbox_caption\";s:4:\"auto\";s:23:\"colorbox_caption_custom\";s:0:\"\";}',
        )
      )
      ->execute();
      
    db_insert('file_display')
      ->fields(array(
        'name' => 'image__' . $media . '__file_field_file_default',
        'weight' => '0',
        'status' => '0',
        'settings' => 'N;',
        )
      )
      ->execute();
    
    db_insert('file_display')
      ->fields(array(
        'name' => 'image__' . $media . '__file_field_file_download_link',
        'weight' => '0',
        'status' => '0',
        'settings' => 'a:1:{s:4:\"text\";s:20:\"Download [file:name]\";}',
        )
      )
      ->execute();
    
    db_insert('file_display')
      ->fields(array(
        'name' => 'image__' . $media . '__file_field_file_table',
        'weight' => '0',
        'status' => '0',
        'settings' => 'N;',
        )
      )
      ->execute();
    
    db_insert('file_display')
      ->fields(array(
        'name' => 'image__' . $media . '__file_field_file_url_plain',
        'weight' => '0',
        'status' => '0',
        'settings' => 'N;',
        )
      )
      ->execute();
      
    db_insert('file_display')
      ->fields(array(
        'name' => 'image__' . $media . '__file_field_image',
        'weight' => '0',
        'status' => '1',
        'settings' => 'a:2:{s:11:\"image_style\";s:' . strlen($media) . ':\"' . $media . '\";s:10:\"image_link\";s:0:\"\";}',
        )
      )
      ->execute();
    
    db_insert('file_display')
      ->fields(array(
        'name' => 'image__' . $media . '__file_field_lightbox2',
        'weight' => '0',
        'status' => '0',
        'settings' => 'a:4:{s:4:\"type\";s:8:\"lightbox\";s:11:\"image_style\";s:8:\"original\";s:14:\"lightbox_style\";s:8:\"original\";s:7:\"caption\";s:6:\"hidden\";}',
        )
      )
      ->execute();
      
    db_insert('file_display')
      ->fields(array(
        'name' => 'image__' . $media . '__file_field_media_large_icon',
        'weight' => '0',
        'status' => '0',
        'settings' => 'N;',
        )
      )
      ->execute();
      
    db_insert('file_display')
      ->fields(array(
        'name' => 'image__' . $media . '__lightbox2_iframe',
        'weight' => '0',
        'status' => '0',
        'settings' => 'N;',
        )
      )
      ->execute();
      
    db_insert('file_display')
      ->fields(array(
        'name' => 'image__' . $media . '__lightbox2_image',
        'weight' => '0',
        'status' => '0',
        'settings' => 'N;',
        )
      )
      ->execute();
  }
  drupal_set_message('Media types updated successfully');
}

function jagency_pages_redirect_import_form($form, &$form_state) {
  $form['#tree'] = TRUE;
  $form['#attributes']['enctype'] = 'multipart/form-data';
  $form['upload']['file'] = array(
    '#type' => 'file',
    '#description' => t('Please use this format for csv file: source, redirect, type(301,302) or other, by default 301 will be used'),
    '#title' => t('File to import'),
  );
  $form['upload']['submit'] = array('#type' => 'submit', '#value' => t('Submit'));
  return $form;
}

function jagency_pages_redirect_import_form_submit($form, &$form_state) {
  if ($_FILES['files']['tmp_name']['upload']) {
    $items = explode("\n", file_get_contents($_FILES['files']['tmp_name']['upload']));
    $counter = 0;
    foreach ($items as $item) {
      $item = explode(',', '');
      //redirect section
      $redirect = new stdClass();
      redirect_object_prepare($redirect);
      $redirect->source = $item[0];
      $redirect->redirect = $item[1];
      $redirect->status_code = (isset($item[2]) && $item[2] ? $item[2] : 301);
      $redirect->language = LANGUAGE_NONE;
      // Check if the redirect exists before saving.
      $hash = redirect_hash($redirect);
      if (!redirect_load_by_hash($hash)) {
        redirect_save($redirect);
        $counter++;
      }
    }
    drupal_set_message('We succefully created ' . $counter . ' redirects');
  } else {
    drupal_set_message('Sorry there some problem with file, please use right format');
  }
}

function jagency_simpleviews_fix() {
  $fields = array('field_block_view', 'field_experiances', 'field_more_about', 'field_featured_stories');
  foreach ($fields as $field) {
    print '<strong>Choosed field <i>' . $field . '</i><br />';
    $sql_query = db_select('field_data_' . $field, 's');
    $sql_query->fields('s');
    $sql_query2 = db_select('field_revision_' . $field, 's');
    $sql_query2->fields('s');
    $raw_data = $sql_query->execute()->fetchAll();
    $raw_data2 = $sql_query2->execute()->fetchAll();
    foreach ($raw_data as $item) {
      $_field = $field . '_value';
      $tmp = unserialize($item->$_field);
      if ($tmp['filters']['term'] == 'all') {
        $vid = $tmp['filters']['vocabulary'];
        $terms = taxonomy_get_tree($vid);
        $tids = array();
        foreach ($terms as $term) {
          $tids[] = array('' => $term->tid);
        }
        $tmp['filters']['term'] = $tids;
        print 'Update field ('.'field_data_' . $field.') for ' . $item->revision_id . '<br />';
        flush();
        db_update('field_data_' . $field) // Table name no longer needs {}
          ->fields(array(
            $_field => serialize($tmp)))
          ->condition('revision_id', $item->revision_id, '=')
          ->execute();
      }
    }
    foreach ($raw_data2 as $item) {
      $_field = $field . '_value';
      $tmp = unserialize($item->$_field);
      if ($tmp['filters']['term'] == 'all') {
        $vid = $tmp['filters']['vocabulary'];
        $terms = taxonomy_get_tree($vid);
        $tids = array();
        foreach ($terms as $term) {
          $tids[] = array('' => $term->tid);
        }
        $tmp['filters']['term'] = $tids;
        print 'Update field revision for ' . $item->revision_id . '<br />';
        flush();
        db_update('field_revision_' . $field) // Table name no longer needs {}
          ->fields(array(
            $_field => serialize($tmp)))
          ->condition('revision_id', $item->revision_id, '=')
          ->execute();
      }
    }
  }
}

function jagency_translate_seek_screen($string) {
  $string = str_replace('"', "&quot;", base64_decode($string));
  drupal_add_css(drupal_get_path('module', 'jagency_pages') . '/media/menu_hide.css');
  $sql_query = db_select('locales_source', 's');
  $sql_query->fields('s', array('source', 'location', 'context', 'lid', 'textgroup'));
  $condition = db_or()->condition('s.source', $string, '=');
  $sql_query->condition($condition);
  $locales = $sql_query->execute()->fetchAll();
  $lid = 0;
  if (is_array($locales) && isset($locales[0]->lid)) {
    $lid = $locales[0]->lid;
  }  
  if ($lid != 0) {
    module_load_include('inc', 'locale', 'locale.admin');
    $elements = drupal_get_form('locale_translate_edit_form', array($lid));
    $output = drupal_render($elements);
  } else {
    module_load_include('inc', 'locale', 'locale.admin');
    drupal_add_css(drupal_get_path('module', 'locale') . '/locale.css');
    $_SESSION['locale_translation_filter']['string'] = $string;
    
    $elements = drupal_get_form('locale_translation_filter_form');
    $output = drupal_render($elements);
    $output .= _locale_translate_seek();
  }
  return $output;
}

function jagency_pages_menu_edit_item($form, &$form_state, $type, $item, $menu) {
  if ($type == 'add' || empty($item)) {
    // This is an add form, initialize the menu link.
    $item = array('link_title' => '', 'mlid' => 0, 'plid' => 0, 'menu_name' => $menu['menu_name'], 'weight' => 0, 'link_path' => '', 'options' => array(), 'module' => 'menu', 'expanded' => 0, 'hidden' => 0, 'has_children' => 0);
  }
  else {
    // Get the human-readable menu title from the given menu name.
    $titles = menu_get_menus();
    $current_title = $titles[$item['menu_name']];

    // Get the current breadcrumb and add a link to that menu's overview page.
    $breadcrumb = menu_get_active_breadcrumb();
    $breadcrumb[] = l($current_title, 'admin/structure/menu/manage/' . $item['menu_name']);
    drupal_set_breadcrumb($breadcrumb);
  }
  $form['actions'] = array('#type' => 'actions');
  $form['link_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Menu link title'),
    '#default_value' => $item['link_title'],
    '#description' => t('The text to be used for this link in the menu.'),
    '#required' => TRUE,
  );
  foreach (array('link_path', 'mlid', 'module', 'has_children', 'options') as $key) {
    $form[$key] = array('#type' => 'value', '#value' => $item[$key]);
  }
  // Any item created or edited via this interface is considered "customized".
  $form['customized'] = array('#type' => 'value', '#value' => 1);
  $form['original_item'] = array('#type' => 'value', '#value' => $item);

  $path = $item['link_path'];
  if (isset($item['options']['query'])) {
    $path .= '?' . drupal_http_build_query($item['options']['query']);
  }
  if (isset($item['options']['fragment'])) {
    $path .= '#' . $item['options']['fragment'];
  }
  if ($item['module'] == 'menu') {
    $form['link_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Path'),
      '#maxlength' => 255,
      '#default_value' => $path,
      '#description' => t('The path for this menu link. This can be an internal Drupal path such as %add-node or an external URL such as %drupal. Enter %front to link to the front page.', array('%front' => '<front>', '%add-node' => 'node/add', '%drupal' => 'http://drupal.org')),
      '#required' => TRUE,
    );
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#access' => $item['mlid'],
      '#submit' => array('menu_item_delete_submit'),
      '#weight' => 10,
    );
  }
  else {
    $form['_path'] = array(
      '#type' => 'item',
      '#title' => t('Path'),
      '#description' => l($item['link_title'], $item['href'], $item['options']),
    );
  }
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => isset($item['options']['attributes']['title']) ? $item['options']['attributes']['title'] : '',
    '#rows' => 1,
    '#description' => t('Shown when hovering over the menu link.'),
  );
  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => !$item['hidden'],
    '#description' => t('Menu links that are not enabled will not be listed in any menu.'),
  );
  $form['expanded'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show as expanded'),
    '#default_value' => $item['expanded'],
    '#description' => t('If selected and this menu link has children, the menu will always appear expanded.'),
  );

  // Generate a list of possible parents (not including this link or descendants).
  $options = menu_parent_options(menu_get_menus(), $item);
  $default = $item['menu_name'] . ':' . $item['plid'];
  if (!isset($options[$default])) {
    $default = 'navigation:0';
  }
  $form['parent'] = array(
    '#type' => 'select',
    '#title' => t('Parent link'),
    '#default_value' => $default,
    '#options' => $options,
    '#description' => t('The maximum depth for a link and all its children is fixed at !maxdepth. Some menu links may not be available as parents if selecting them would exceed this limit.', array('!maxdepth' => MENU_MAX_DEPTH)),
    '#attributes' => array('class' => array('menu-title-select')),
  );
  $form['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#delta' => 50,
    '#default_value' => $item['weight'],
    '#description' => t('Optional. In the menu, the heavier links will sink and the lighter links will be positioned nearer the top.'),
  );
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save'));

  return $form;
}

/**
 * Validate form values for a menu link being added or edited.
 */
function jagency_pages_menu_edit_item_validate($form, &$form_state) {
  $item = &$form_state['values'];
  $normal_path = drupal_get_normal_path($item['link_path']);
  if ($item['link_path'] != $normal_path) {
    drupal_set_message(t('The menu system stores system paths only, but will use the URL alias for display. %link_path has been stored as %normal_path', array('%link_path' => $item['link_path'], '%normal_path' => $normal_path)));
    $item['link_path'] = $normal_path;
  }
  if (!url_is_external($item['link_path'])) {
    $parsed_link = parse_url($item['link_path']);
    if (isset($parsed_link['query'])) {
      $item['options']['query'] = drupal_get_query_array($parsed_link['query']);
    }
    else {
      // Use unset() rather than setting to empty string
      // to avoid redundant serialized data being stored.
      unset($item['options']['query']);
    }
    if (isset($parsed_link['fragment'])) {
      $item['options']['fragment'] = $parsed_link['fragment'];
    }
    else {
      unset($item['options']['fragment']);
    }
    if (isset($parsed_link['path']) && $item['link_path'] != $parsed_link['path']) {
      $item['link_path'] = $parsed_link['path'];
    }
  }
  //disable validation
  /*if (!trim($item['link_path']) || !drupal_valid_path($item['link_path'], TRUE)) {
    //form_set_error('link_path', t("The path '@link_path' is either invalid or you do not have access to it.", array('@link_path' => $item['link_path'])));
  }*/
}

/**
 * Process menu and menu item add/edit form submissions.
 */
function jagency_pages_menu_edit_item_submit($form, &$form_state) {
  $item = &$form_state['values'];
  
  // The value of "hidden" is the opposite of the value
  // supplied by the "enabled" checkbox.
  $item['hidden'] = (int) !$item['enabled'];
  unset($item['enabled']);

  $item['options']['attributes']['title'] = $item['description'];
  list($item['menu_name'], $item['plid']) = explode(':', $item['parent']);
  if (!$mlid = menu_link_save($item)) {
    drupal_set_message(t('There was an error saving the menu link.'), 'error');
  }
  else {
    drupal_set_message(t('Your configuration has been saved.'));
  }
  
  if (!trim($item['link_path']) || !drupal_valid_path($item['link_path'], TRUE)) {
    if ($mlid) {
      db_update('menu_links')
      ->fields(array(
        'external' => 1,
      ))
      ->condition('mlid', $mlid)
      ->execute();
    }
  }
  $form_state['redirect'] = 'admin/structure/menu/manage/' . $item['menu_name'];
}


/** 
 * Form builder. 
 * 
 * @ingroup forms 
 * @see system_settings_form(). 
 */ 
function jagency_pages_admin_settings_form($form, &$form_state) {
  $form['fb_application_id'] = array( 
    '#type' => 'textfield', 
    '#title' => t('Facebook Application Id'), 
    '#description' => t('Enter facebook application id, will affect on all website(comments,comments counters)'), 
    '#default_value' => variable_get('fb_application_id', '')
  );
  
  $form['fb_trending_link'] = array( 
    '#type' => 'textfield', 
    '#title' => t('Trending Facebook Link'), 
    '#description' => t('Link that will be displayed on facebook trending block'), 
    '#default_value' => variable_get('fb_trending_link', '')
  );
  
  $form['fb_trending_website'] = array( 
    '#type' => 'textfield', 
    '#title' => t('Trending Facebook Website'), 
    '#description' => t('All activity will be fetched by this website'), 
    '#default_value' => variable_get('fb_trending_website', '')
  );
  
  /*$form['fb_trending'] = array( 
    '#type' => 'textarea', 
    '#title' => t('Trending Facebook code'), 
    '#description' => t('Enter facebook Code.'), 
    '#default_value' => variable_get('fb_trending', '')
  );*/
  return system_settings_form($form);
}

function jagency_footerhtml_admin_settings_form($form, &$form_state) {
  $domain = domain_get_domain();
  $form['footer_content'] = array( 
    '#type' => 'textarea', 
    '#title' => t('Footer HTML conent'),
    '#rows' => '12',
    '#description' => t('Enter HTML Code.'), 
    '#default_value' => domain_conf_variable_get($domain['domain_id'], "footer_content")
  );
  return system_settings_form($form);
}
/**
 * Social Netwroks Submit
 */
function jagency_pages_admin_settings_form_submit($form, &$form_state) {
  drupal_set_message(t('Submitting succsessfuly updated!'));
  variable_set('fb_application_id', $form_state['values']['fb_application_id']);
  variable_set('fb_trending_website', $form_state['values']['fb_trending_website']);
  variable_set('fb_trending_link', $form_state['values']['fb_trending_link']);
  variable_set('fb_trending', $form_state['values']['fb_trending']);
}

function jagency_footerhtml_admin_settings_form_submit($form, &$form_state) {
  $domain = domain_get_domain();
  drupal_set_message(t('Submitting succsessfuly updated!'));
  domain_conf_variable_set($domain['domain_id'], "footer_content", $form_state['values']['footer_content']);
  //variable_set('footer_content', $form_state['values']['footer_content']);
}