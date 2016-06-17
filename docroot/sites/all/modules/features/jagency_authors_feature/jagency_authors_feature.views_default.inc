<?php
/**
 * @file
 * jagency_authors_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jagency_authors_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'all_user_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All User Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All User Content';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['waypoint']['infinite'] = 0;
  $handler->display->display_options['pager']['options']['more_button_text'] = 'MORE BLOG POSTS';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node_split';
  $handler->display->display_options['row_options']['view_mode'] = 'blog_category';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['row_options']['first_settings'] = array(
    'first_x_value' => '1',
    'view_mode' => 'blog_category_first',
    'links' => 0,
    'comments' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog_entry' => 'blog_entry',
  );
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'blog/user/%';
  $translatables['all_user_content'] = array(
    t('Master'),
    t('All User Content'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('All'),
    t('Page'),
  );
  $export['all_user_content'] = $view;

  $view = new view();
  $view->name = 'authors_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Authors Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'user_split';
  $handler->display->display_options['row_options']['view_mode'] = 'block';
  $handler->display->display_options['row_options']['first_settings'] = array(
    'first_x_value' => '1',
    'view_mode' => 'block',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: User: Featured (field_profile_featured) */
  $handler->display->display_options['sorts']['field_profile_featured_value']['id'] = 'field_profile_featured_value';
  $handler->display->display_options['sorts']['field_profile_featured_value']['table'] = 'field_data_field_profile_featured';
  $handler->display->display_options['sorts']['field_profile_featured_value']['field'] = 'field_profile_featured_value';
  $handler->display->display_options['sorts']['field_profile_featured_value']['order'] = 'DESC';
  /* Sort criterion: User: Weight (field_profile_weight) */
  $handler->display->display_options['sorts']['field_profile_weight_value']['id'] = 'field_profile_weight_value';
  $handler->display->display_options['sorts']['field_profile_weight_value']['table'] = 'field_data_field_profile_weight';
  $handler->display->display_options['sorts']['field_profile_weight_value']['field'] = 'field_profile_weight_value';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Exclude from block (field_exclude_from_block) */
  $handler->display->display_options['filters']['field_exclude_from_block_value']['id'] = 'field_exclude_from_block_value';
  $handler->display->display_options['filters']['field_exclude_from_block_value']['table'] = 'field_data_field_exclude_from_block';
  $handler->display->display_options['filters']['field_exclude_from_block_value']['field'] = 'field_exclude_from_block_value';
  $handler->display->display_options['filters']['field_exclude_from_block_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_exclude_from_block_value']['value'] = array(
    'yes' => 'yes',
  );
  /* Filter criterion: Domain Editor: Domain ID */
  $handler->display->display_options['filters']['domain_id']['id'] = 'domain_id';
  $handler->display->display_options['filters']['domain_id']['table'] = 'domain_editor';
  $handler->display->display_options['filters']['domain_id']['field'] = 'domain_id';
  $handler->display->display_options['filters']['domain_id']['value'] = array(
    '***CURRENT_DOMAIN***' => '***CURRENT_DOMAIN***',
  );

  /* Display: Authors List */
  $handler = $view->new_display('panel_pane', 'Authors List', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['authors_block'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Authors List'),
    t('View panes'),
  );
  $export['authors_block'] = $view;

  $view = new view();
  $view->name = 'authors_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Authors_view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Authors_view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['group']['element_type'] = '';
  $handler->display->display_options['style_options']['group']['class'] = '';
  $handler->display->display_options['style_options']['row']['element_type'] = 'li';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['last_every_nth'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => 'authors_small_image',
    'image_link' => 'content',
  );
  /* Sort criterion: User: Weight (field_profile_weight) */
  $handler->display->display_options['sorts']['field_profile_weight_value']['id'] = 'field_profile_weight_value';
  $handler->display->display_options['sorts']['field_profile_weight_value']['table'] = 'field_data_field_profile_weight';
  $handler->display->display_options['sorts']['field_profile_weight_value']['field'] = 'field_profile_weight_value';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Featured (field_profile_featured) */
  $handler->display->display_options['filters']['field_profile_featured_value']['id'] = 'field_profile_featured_value';
  $handler->display->display_options['filters']['field_profile_featured_value']['table'] = 'field_data_field_profile_featured';
  $handler->display->display_options['filters']['field_profile_featured_value']['field'] = 'field_profile_featured_value';
  $handler->display->display_options['filters']['field_profile_featured_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: Weight (field_profile_weight) */
  $handler->display->display_options['filters']['field_profile_weight_value']['id'] = 'field_profile_weight_value';
  $handler->display->display_options['filters']['field_profile_weight_value']['table'] = 'field_data_field_profile_weight';
  $handler->display->display_options['filters']['field_profile_weight_value']['field'] = 'field_profile_weight_value';
  $handler->display->display_options['filters']['field_profile_weight_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Domain Editor: Domain ID */
  $handler->display->display_options['filters']['domain_id']['id'] = 'domain_id';
  $handler->display->display_options['filters']['domain_id']['table'] = 'domain_editor';
  $handler->display->display_options['filters']['domain_id']['field'] = 'domain_id';
  $handler->display->display_options['filters']['domain_id']['value'] = array(
    '***CURRENT_DOMAIN***' => '***CURRENT_DOMAIN***',
  );

  /* Display: All Authors */
  $handler = $view->new_display('block', 'All Authors', 'authors_all');
  $handler->display->display_options['display_description'] = 'show all Authors in block';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => 'authors_small_image',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="conToolTip">';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<strong>[name]</strong>';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Field: Short Bio */
  $handler->display->display_options['fields']['field_profile_short_bio']['id'] = 'field_profile_short_bio';
  $handler->display->display_options['fields']['field_profile_short_bio']['table'] = 'field_data_field_profile_short_bio';
  $handler->display->display_options['fields']['field_profile_short_bio']['field'] = 'field_profile_short_bio';
  $handler->display->display_options['fields']['field_profile_short_bio']['label'] = '';
  $handler->display->display_options['fields']['field_profile_short_bio']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_short_bio']['alter']['text'] = '<span>[field_profile_short_bio]</span>';
  $handler->display->display_options['fields']['field_profile_short_bio']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Featured (field_profile_featured) */
  $handler->display->display_options['filters']['field_profile_featured_value']['id'] = 'field_profile_featured_value';
  $handler->display->display_options['filters']['field_profile_featured_value']['table'] = 'field_data_field_profile_featured';
  $handler->display->display_options['filters']['field_profile_featured_value']['field'] = 'field_profile_featured_value';
  $handler->display->display_options['filters']['field_profile_featured_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Domain Editor: Domain ID */
  $handler->display->display_options['filters']['domain_id']['id'] = 'domain_id';
  $handler->display->display_options['filters']['domain_id']['table'] = 'domain_editor';
  $handler->display->display_options['filters']['domain_id']['field'] = 'domain_id';
  $handler->display->display_options['filters']['domain_id']['value'] = array(
    '***CURRENT_DOMAIN***' => '***CURRENT_DOMAIN***',
  );
  $handler->display->display_options['block_description'] = 'All Authors';

  /* Display: First Author */
  $handler = $view->new_display('block', 'First Author', 'first_author');
  $handler->display->display_options['display_description'] = 'show First Author in block';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['group']['element_type'] = '';
  $handler->display->display_options['style_options']['group']['class'] = '';
  $handler->display->display_options['style_options']['row']['element_type'] = '';
  $handler->display->display_options['style_options']['row']['first_class'] = '';
  $handler->display->display_options['style_options']['row']['last_class'] = '';
  $handler->display->display_options['style_options']['row']['last_every_nth'] = '';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => 'authors_big_image',
    'image_link' => '',
  );
  /* Field: User: Featured */
  $handler->display->display_options['fields']['field_profile_featured']['id'] = 'field_profile_featured';
  $handler->display->display_options['fields']['field_profile_featured']['table'] = 'field_data_field_profile_featured';
  $handler->display->display_options['fields']['field_profile_featured']['field'] = 'field_profile_featured';
  $handler->display->display_options['fields']['field_profile_featured']['label'] = '';
  $handler->display->display_options['fields']['field_profile_featured']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_featured']['element_default_classes'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name']['alter']['text'] = '<a href="/user/[name]"><strong>[field_profile_name]</strong></a>';
  $handler->display->display_options['fields']['field_profile_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_name']['type'] = 'text_plain';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<a href="/user/[name]"><strong>[field_profile_name]</strong></a>';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: Short Bio */
  $handler->display->display_options['fields']['field_profile_short_bio']['id'] = 'field_profile_short_bio';
  $handler->display->display_options['fields']['field_profile_short_bio']['table'] = 'field_data_field_profile_short_bio';
  $handler->display->display_options['fields']['field_profile_short_bio']['field'] = 'field_profile_short_bio';
  $handler->display->display_options['fields']['field_profile_short_bio']['label'] = '';
  $handler->display->display_options['fields']['field_profile_short_bio']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_short_bio']['alter']['text'] = '<span>[field_profile_short_bio]</span>';
  $handler->display->display_options['fields']['field_profile_short_bio']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'First Author';
  $translatables['authors_view'] = array(
    t('Master'),
    t('Authors_view'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All Authors'),
    t('show all Authors in block'),
    t('<div class="conToolTip">'),
    t('<strong>[name]</strong>'),
    t('<span>[field_profile_short_bio]</span>'),
    t('</div>'),
    t('First Author'),
    t('show First Author in block'),
    t('<a href="/user/[name]"><strong>[field_profile_name]</strong></a>'),
  );
  $export['authors_view'] = $view;

  return $export;
}
