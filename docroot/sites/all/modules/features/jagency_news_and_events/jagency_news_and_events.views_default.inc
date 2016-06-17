<?php
/**
 * @file
 * jagency_news_and_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jagency_news_and_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'more_news_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'More News & Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'More News & Events';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['waypoint']['infinite'] = 0;
  $handler->display->display_options['pager']['options']['more_button_text'] = 'More News & Events';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
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
  /* Contextual filter: Content: Terms (field_program_tags) */
  $handler->display->display_options['arguments']['field_program_tags_target_id']['id'] = 'field_program_tags_target_id';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['table'] = 'field_data_field_program_tags';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['field'] = 'field_program_tags_target_id';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['specify_validation'] = TRUE;
  /* Contextual filter: Content: Article Type (field_aticle_type) */
  $handler->display->display_options['arguments']['field_aticle_type_target_id']['id'] = 'field_aticle_type_target_id';
  $handler->display->display_options['arguments']['field_aticle_type_target_id']['table'] = 'field_data_field_aticle_type';
  $handler->display->display_options['arguments']['field_aticle_type_target_id']['field'] = 'field_aticle_type_target_id';
  $handler->display->display_options['arguments']['field_aticle_type_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_aticle_type_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_aticle_type_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_aticle_type_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Main category (field_main_category) */
  $handler->display->display_options['arguments']['field_main_category_target_id']['id'] = 'field_main_category_target_id';
  $handler->display->display_options['arguments']['field_main_category_target_id']['table'] = 'field_data_field_main_category';
  $handler->display->display_options['arguments']['field_main_category_target_id']['field'] = 'field_main_category_target_id';
  $handler->display->display_options['arguments']['field_main_category_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_main_category_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_main_category_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_main_category_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Main category (field_main_category) */
  $handler->display->display_options['filters']['field_main_category_target_id']['id'] = 'field_main_category_target_id';
  $handler->display->display_options['filters']['field_main_category_target_id']['table'] = 'field_data_field_main_category';
  $handler->display->display_options['filters']['field_main_category_target_id']['field'] = 'field_main_category_target_id';
  $handler->display->display_options['filters']['field_main_category_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_main_category_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_main_category_target_id']['expose']['operator_id'] = 'field_main_category_target_id_op';
  $handler->display->display_options['filters']['field_main_category_target_id']['expose']['operator'] = 'field_main_category_target_id_op';
  $handler->display->display_options['filters']['field_main_category_target_id']['expose']['identifier'] = 'field_main_category_target_id';
  $handler->display->display_options['filters']['field_main_category_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Article Type (field_aticle_type) */
  $handler->display->display_options['filters']['field_aticle_type_target_id']['id'] = 'field_aticle_type_target_id';
  $handler->display->display_options['filters']['field_aticle_type_target_id']['table'] = 'field_data_field_aticle_type';
  $handler->display->display_options['filters']['field_aticle_type_target_id']['field'] = 'field_aticle_type_target_id';
  $handler->display->display_options['filters']['field_aticle_type_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_aticle_type_target_id']['expose']['operator_id'] = 'field_aticle_type_target_id_op';
  $handler->display->display_options['filters']['field_aticle_type_target_id']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_aticle_type_target_id']['expose']['operator'] = 'field_aticle_type_target_id_op';
  $handler->display->display_options['filters']['field_aticle_type_target_id']['expose']['identifier'] = 'field_aticle_type_target_id';
  $handler->display->display_options['filters']['field_aticle_type_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['more_news_events'] = array(
    t('Master'),
    t('More News & Events'),
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
    t('Category'),
    t('Block'),
  );
  $export['more_news_events'] = $view;

  return $export;
}
