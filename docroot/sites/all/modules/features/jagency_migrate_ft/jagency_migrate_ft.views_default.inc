<?php
/**
 * @file
 * jagency_migrate_ft.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jagency_migrate_ft_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agency_migrate_history_result';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'migration_history';
  $view->human_name = 'Agency Migrate History Result';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'original' => 'original',
    'website' => 'website',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'original' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'website' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Counter';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Migrate History: Original Url */
  $handler->display->display_options['fields']['original']['id'] = 'original';
  $handler->display->display_options['fields']['original']['table'] = 'migration_history';
  $handler->display->display_options['fields']['original']['field'] = 'original';
  $handler->display->display_options['fields']['original']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['original']['alter']['path'] = '[original]';
  $handler->display->display_options['fields']['original']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['original']['alter']['target'] = '_blank';
  /* Field: Migrate History: Url */
  $handler->display->display_options['fields']['website']['id'] = 'website';
  $handler->display->display_options['fields']['website']['table'] = 'migration_history';
  $handler->display->display_options['fields']['website']['field'] = 'website';
  $handler->display->display_options['fields']['website']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['website']['alter']['text'] = '<a href="/[website]" target="_blank">[website]</a>';
  $handler->display->display_options['fields']['website']['alter']['path'] = '[website]';
  $handler->display->display_options['fields']['website']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['website']['alter']['target'] = '_blank';
  /* Filter criterion: Migrate History: Original Url */
  $handler->display->display_options['filters']['original']['id'] = 'original';
  $handler->display->display_options['filters']['original']['table'] = 'migration_history';
  $handler->display->display_options['filters']['original']['field'] = 'original';
  $handler->display->display_options['filters']['original']['operator'] = 'contains';
  $handler->display->display_options['filters']['original']['exposed'] = TRUE;
  $handler->display->display_options['filters']['original']['expose']['operator_id'] = 'original_op';
  $handler->display->display_options['filters']['original']['expose']['label'] = 'Original Url';
  $handler->display->display_options['filters']['original']['expose']['operator'] = 'original_op';
  $handler->display->display_options['filters']['original']['expose']['identifier'] = 'original';
  $handler->display->display_options['filters']['original']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Migrate History: Url */
  $handler->display->display_options['filters']['website']['id'] = 'website';
  $handler->display->display_options['filters']['website']['table'] = 'migration_history';
  $handler->display->display_options['filters']['website']['field'] = 'website';
  $handler->display->display_options['filters']['website']['exposed'] = TRUE;
  $handler->display->display_options['filters']['website']['expose']['operator_id'] = 'website_op';
  $handler->display->display_options['filters']['website']['expose']['label'] = 'Url';
  $handler->display->display_options['filters']['website']['expose']['operator'] = 'website_op';
  $handler->display->display_options['filters']['website']['expose']['identifier'] = 'website';
  $handler->display->display_options['filters']['website']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $translatables['agency_migrate_history_result'] = array(
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
    t('Counter'),
    t('Original Url'),
    t('Url'),
    t('<a href="/[website]" target="_blank">[website]</a>'),
  );
  $export['agency_migrate_history_result'] = $view;

  $view = new view();
  $view->name = 'agency_migrate_result';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'migration';
  $view->human_name = 'Agency Migrate Result';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Agency Migrate Result';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'url' => 'url',
    'hash_1' => 'hash_1',
    'http_status' => 'http_status',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'url' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'hash_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'http_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Counter';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Migrate: Url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'migration';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  /* Field: Migrate: Hash */
  $handler->display->display_options['fields']['hash_1']['id'] = 'hash_1';
  $handler->display->display_options['fields']['hash_1']['table'] = 'migration';
  $handler->display->display_options['fields']['hash_1']['field'] = 'hash';
  /* Field: Migrate: Http Status */
  $handler->display->display_options['fields']['http_status']['id'] = 'http_status';
  $handler->display->display_options['fields']['http_status']['table'] = 'migration';
  $handler->display->display_options['fields']['http_status']['field'] = 'http_status';
  /* Field: Migrate: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'migration';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Filter criterion: Migrate: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'migration';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $translatables['agency_migrate_result'] = array(
    t('Master'),
    t('Agency Migrate Result'),
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
    t('Counter'),
    t('Url'),
    t('Hash'),
    t('Http Status'),
    t('Status'),
    t('.'),
    t(','),
    t('Content pane'),
    t('View panes'),
  );
  $export['agency_migrate_result'] = $view;

  return $export;
}
