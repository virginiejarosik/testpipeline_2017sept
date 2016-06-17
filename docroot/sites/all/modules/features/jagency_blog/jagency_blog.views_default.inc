<?php
/**
 * @file
 * jagency_blog.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jagency_blog_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blog_category';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog Category';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['waypoint']['infinite'] = 0;
  $handler->display->display_options['pager']['options']['more_button_text'] = 'MORE BLOG POST';
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
  /* Sort criterion: Content: Featured Item (field_featured_item) */
  $handler->display->display_options['sorts']['field_featured_item_value']['id'] = 'field_featured_item_value';
  $handler->display->display_options['sorts']['field_featured_item_value']['table'] = 'field_data_field_featured_item';
  $handler->display->display_options['sorts']['field_featured_item_value']['field'] = 'field_featured_item_value';
  $handler->display->display_options['sorts']['field_featured_item_value']['order'] = 'DESC';
  /* Sort criterion: Weight: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'weight_weights';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Blog (field_blog) */
  $handler->display->display_options['arguments']['field_blog_target_id']['id'] = 'field_blog_target_id';
  $handler->display->display_options['arguments']['field_blog_target_id']['table'] = 'field_data_field_blog';
  $handler->display->display_options['arguments']['field_blog_target_id']['field'] = 'field_blog_target_id';
  $handler->display->display_options['arguments']['field_blog_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_blog_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Terms (field_tag) */
  $handler->display->display_options['arguments']['field_tag_tid']['id'] = 'field_tag_tid';
  $handler->display->display_options['arguments']['field_tag_tid']['table'] = 'field_data_field_tag';
  $handler->display->display_options['arguments']['field_tag_tid']['field'] = 'field_tag_tid';
  $handler->display->display_options['arguments']['field_tag_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_tag_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tag_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tag_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tag_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_tag_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_tag_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_tag_tid']['validate_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
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

  /* Display: Blog Category */
  $handler = $view->new_display('panel_pane', 'Blog Category', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'field_blog_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Blog (field_blog)',
    ),
    'field_tag_tid' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Content: Tags (field_tag)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Blog Category by User */
  $handler = $view->new_display('panel_pane', 'Blog Category by User', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['waypoint']['infinite'] = 0;
  $handler->display->display_options['pager']['options']['more_button_text'] = 'MORE BLOG POST';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Blog (field_blog) */
  $handler->display->display_options['arguments']['field_blog_target_id']['id'] = 'field_blog_target_id';
  $handler->display->display_options['arguments']['field_blog_target_id']['table'] = 'field_data_field_blog';
  $handler->display->display_options['arguments']['field_blog_target_id']['field'] = 'field_blog_target_id';
  $handler->display->display_options['arguments']['field_blog_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_blog_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'field_blog_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Blog (field_blog)',
    ),
    'uid' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Content: Author uid',
    ),
  );

  /* Display: Blog Category RSS */
  $handler = $view->new_display('feed', 'Blog Category RSS', 'feed_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss/blog/%/tag/%';

  /* Display: Blog Category by User RSS */
  $handler = $view->new_display('feed', 'Blog Category by User RSS', 'feed_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Blog (field_blog) */
  $handler->display->display_options['arguments']['field_blog_target_id']['id'] = 'field_blog_target_id';
  $handler->display->display_options['arguments']['field_blog_target_id']['table'] = 'field_data_field_blog';
  $handler->display->display_options['arguments']['field_blog_target_id']['field'] = 'field_blog_target_id';
  $handler->display->display_options['arguments']['field_blog_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_blog_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'rss/blog/%/user/%';

  /* Display: Blog Main Category */
  $handler = $view->new_display('panel_pane', 'Blog Main Category', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Blog (field_blog) */
  $handler->display->display_options['arguments']['field_blog_target_id']['id'] = 'field_blog_target_id';
  $handler->display->display_options['arguments']['field_blog_target_id']['table'] = 'field_data_field_blog';
  $handler->display->display_options['arguments']['field_blog_target_id']['field'] = 'field_blog_target_id';
  $handler->display->display_options['arguments']['field_blog_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_blog_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Category (field_category) */
  $handler->display->display_options['arguments']['field_category_tid']['id'] = 'field_category_tid';
  $handler->display->display_options['arguments']['field_category_tid']['table'] = 'field_data_field_category';
  $handler->display->display_options['arguments']['field_category_tid']['field'] = 'field_category_tid';
  $handler->display->display_options['arguments']['field_category_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_category_tid']['validate_options']['vocabularies'] = array(
    'jewish_agency' => 'jewish_agency',
  );
  $handler->display->display_options['argument_input'] = array(
    'field_blog_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Blog (field_blog)',
    ),
    'field_category_tid' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Content: Category (field_category)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '0';
  $translatables['blog_category'] = array(
    t('Master'),
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
    t('Blog Category'),
    t('View panes'),
    t('Blog Category by User'),
    t('Blog Category RSS'),
    t('Blog Category by User RSS'),
    t('Blog Main Category'),
  );
  $export['blog_category'] = $view;

  $view = new view();
  $view->name = 'blog_loby';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog Loby';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '0';
  $handler->display->display_options['pager']['options']['waypoint']['infinite'] = 1;
  $handler->display->display_options['pager']['options']['more_button_text'] = 'MORE BLOG POSTS';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'blog';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Weight: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'weight_weights';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Blog (field_blog) */
  $handler->display->display_options['arguments']['field_blog_target_id']['id'] = 'field_blog_target_id';
  $handler->display->display_options['arguments']['field_blog_target_id']['table'] = 'field_data_field_blog';
  $handler->display->display_options['arguments']['field_blog_target_id']['field'] = 'field_blog_target_id';
  $handler->display->display_options['arguments']['field_blog_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_blog_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blog_target_id']['summary_options']['items_per_page'] = '25';
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
    'quote' => 'quote',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
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

  /* Display: Blog Lobby */
  $handler = $view->new_display('panel_pane', 'Blog Lobby', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Blog Lobby RSS */
  $handler = $view->new_display('feed', 'Blog Lobby RSS', 'feed_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss/blog/%';
  $translatables['blog_loby'] = array(
    t('Master'),
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
    t('Blog Lobby'),
    t('View panes'),
    t('Blog Lobby RSS'),
  );
  $export['blog_loby'] = $view;

  $view = new view();
  $view->name = 'taxonomy_color_filter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Taxonomy Color Filter';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'jewish_agency' => 'jewish_agency',
  );
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = '0';

  /* Display: Taxonomy Color Filter */
  $handler = $view->new_display('entityreference', 'Taxonomy Color Filter', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['taxonomy_color_filter'] = array(
    t('Master'),
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
    t('Taxonomy Color Filter'),
  );
  $export['taxonomy_color_filter'] = $view;

  return $export;
}
