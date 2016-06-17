<?php
/**
 * @file
 * jagency_careers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jagency_careers_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = '_careers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = ' Careers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = ' Careers';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_taxonomy_region_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'All locations',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_date_career_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['waypoint']['infinite'] = 0;
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
    'career' => 'career',
  );
  /* Filter criterion: Content: Region (field_taxonomy_region) */
  $handler->display->display_options['filters']['field_taxonomy_region_target_id']['id'] = 'field_taxonomy_region_target_id';
  $handler->display->display_options['filters']['field_taxonomy_region_target_id']['table'] = 'field_data_field_taxonomy_region';
  $handler->display->display_options['filters']['field_taxonomy_region_target_id']['field'] = 'field_taxonomy_region_target_id';
  $handler->display->display_options['filters']['field_taxonomy_region_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_taxonomy_region_target_id']['expose']['operator_id'] = 'field_taxonomy_region_target_id_op';
  $handler->display->display_options['filters']['field_taxonomy_region_target_id']['expose']['operator'] = 'field_taxonomy_region_target_id_op';
  $handler->display->display_options['filters']['field_taxonomy_region_target_id']['expose']['identifier'] = 'field_taxonomy_region_target_id';
  $handler->display->display_options['filters']['field_taxonomy_region_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Date (field_date_career) */
  $handler->display->display_options['filters']['field_date_career_value']['id'] = 'field_date_career_value';
  $handler->display->display_options['filters']['field_date_career_value']['table'] = 'field_data_field_date_career';
  $handler->display->display_options['filters']['field_date_career_value']['field'] = 'field_date_career_value';
  $handler->display->display_options['filters']['field_date_career_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_career_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_career_value']['expose']['operator_id'] = 'field_date_career_value_op';
  $handler->display->display_options['filters']['field_date_career_value']['expose']['operator'] = 'field_date_career_value_op';
  $handler->display->display_options['filters']['field_date_career_value']['expose']['identifier'] = 'field_date_career_value';
  $handler->display->display_options['filters']['field_date_career_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_date_career_value']['form_type'] = 'date_text';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'careers';
  $translatables['_careers'] = array(
    t('Master'),
    t(' Careers'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Page'),
  );
  $export['_careers'] = $view;

  return $export;
}
