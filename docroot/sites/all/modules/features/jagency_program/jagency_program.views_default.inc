<?php
/**
 * @file
 * jagency_program.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jagency_program_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'faq_s';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FAQ\'s';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'FAQ\'s';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
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
  /* Contextual filter: Content: Experience (field_experience) */
  $handler->display->display_options['arguments']['field_experience_target_id']['id'] = 'field_experience_target_id';
  $handler->display->display_options['arguments']['field_experience_target_id']['table'] = 'field_data_field_experience';
  $handler->display->display_options['arguments']['field_experience_target_id']['field'] = 'field_experience_target_id';
  $handler->display->display_options['arguments']['field_experience_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_experience_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_experience_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_experience_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_experience_target_id']['summary_options']['items_per_page'] = '25';
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
    'question_and_answers' => 'question_and_answers',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['faq_s'] = array(
    t('Master'),
    t('FAQ\'s'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
  );
  $export['faq_s'] = $view;

  $view = new view();
  $view->name = 'more_about_program';
  $view->description = 'Teasers of Program details';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'More About program';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'More About program';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'program_lobby_small';
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
  /* Contextual filter: Content: Program (field_program) */
  $handler->display->display_options['arguments']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['arguments']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['arguments']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['arguments']['field_program_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_program_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_program_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_program_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_program_target_id']['validate_options']['types'] = array(
    'program' => 'program',
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
    'program_details' => 'program_details',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['more_about_program'] = array(
    t('Master'),
    t('More About program'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
  );
  $export['more_about_program'] = $view;

  $view = new view();
  $view->name = 'opportunities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Opportunities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Opportunities';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Load More opps';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'CLEAR ALL';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
    'keys' => array(
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
    'field_what_do_you_want_to_do_target_id' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
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
    'field_age_group_target_id' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
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
    'field_how_long_value' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '1',
        'bef_slider_max' => '50',
        'bef_slider_step' => '1',
        'bef_slider_animate' => 'normal',
        'bef_slider_orientation' => 'horizontal',
      ),
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
    'field_where_do_you_want_togo_target_id' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
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
    'term_node_tid_depth' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
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
    'field_program_icons_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
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
    'field_language_target_id' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
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
    'field_time_of_year_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
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
    'field_total_cost_value' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '10000',
        'bef_slider_step' => '1000',
        'bef_slider_animate' => 'slow',
        'bef_slider_orientation' => 'vertical',
      ),
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
  $handler->display->display_options['row_options']['view_mode'] = 'content_filter';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'Opportunities_footer';
  $handler->display->display_options['footer']['area']['content'] = 'FOR THE MOST UP TO DATE PRICING AND TIMING DETAILS, PLEASE CONTACT THE PROGRAMS DIRECTLY USING THE CONTACT INFORMATION PROVIDED.';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Can\'t find what you are looking for, <a href="http://www.jewishagency.org/">click here</a>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Total cost (field_total_cost) */
  $handler->display->display_options['sorts']['field_total_cost_value']['id'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value']['table'] = 'field_data_field_total_cost';
  $handler->display->display_options['sorts']['field_total_cost_value']['field'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_total_cost_value']['expose']['label'] = 'Cost (High to low)';
  /* Sort criterion: Content: Total cost (field_total_cost) */
  $handler->display->display_options['sorts']['field_total_cost_value_1']['id'] = 'field_total_cost_value_1';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['table'] = 'field_data_field_total_cost';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['field'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_total_cost_value_1']['expose']['label'] = 'Cost (Low to high)';
  /* Sort criterion: Content: How long (field_how_long) */
  $handler->display->display_options['sorts']['field_how_long_value']['id'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value']['table'] = 'field_data_field_how_long';
  $handler->display->display_options['sorts']['field_how_long_value']['field'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_how_long_value']['expose']['label'] = 'Duration (Short to Long)';
  /* Sort criterion: Content: How long (field_how_long) */
  $handler->display->display_options['sorts']['field_how_long_value_1']['id'] = 'field_how_long_value_1';
  $handler->display->display_options['sorts']['field_how_long_value_1']['table'] = 'field_data_field_how_long';
  $handler->display->display_options['sorts']['field_how_long_value_1']['field'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_how_long_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_how_long_value_1']['expose']['label'] = 'Duration (Long to Short)';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: View mode (field_view_mode) */
  $handler->display->display_options['filters']['field_view_mode_value']['id'] = 'field_view_mode_value';
  $handler->display->display_options['filters']['field_view_mode_value']['table'] = 'field_data_field_view_mode';
  $handler->display->display_options['filters']['field_view_mode_value']['field'] = 'field_view_mode_value';
  $handler->display->display_options['filters']['field_view_mode_value']['value'] = array(
    'program_with_sidemenu' => 'program_with_sidemenu',
    'program_without_sidemenu' => 'program_without_sidemenu',
  );
  $handler->display->display_options['filters']['field_view_mode_value']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Total cost (field_total_cost) */
  $handler->display->display_options['sorts']['field_total_cost_value_1']['id'] = 'field_total_cost_value_1';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['table'] = 'field_data_field_total_cost';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['field'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_total_cost_value_1']['expose']['label'] = 'Cost (Low to high)';
  /* Sort criterion: Content: Total cost (field_total_cost) */
  $handler->display->display_options['sorts']['field_total_cost_value']['id'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value']['table'] = 'field_data_field_total_cost';
  $handler->display->display_options['sorts']['field_total_cost_value']['field'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_total_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_total_cost_value']['expose']['label'] = 'Cost (High to low)';
  /* Sort criterion: Content: How long (field_how_long) */
  $handler->display->display_options['sorts']['field_how_long_value']['id'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value']['table'] = 'field_data_field_how_long';
  $handler->display->display_options['sorts']['field_how_long_value']['field'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_how_long_value']['expose']['label'] = 'Duration (Short to Long)';
  /* Sort criterion: Content: How long (field_how_long) */
  $handler->display->display_options['sorts']['field_how_long_value_1']['id'] = 'field_how_long_value_1';
  $handler->display->display_options['sorts']['field_how_long_value_1']['table'] = 'field_data_field_how_long';
  $handler->display->display_options['sorts']['field_how_long_value_1']['field'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_how_long_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_how_long_value_1']['expose']['label'] = 'Duration (Long to Short)';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'program_details' => 'program_details',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Free search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: What do you want to do (field_what_do_you_want_to_do) */
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['id'] = 'field_what_do_you_want_to_do_target_id';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['table'] = 'field_data_field_what_do_you_want_to_do';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['field'] = 'field_what_do_you_want_to_do_target_id';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['operator_id'] = 'field_what_do_you_want_to_do_target_id_op';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['label'] = 'What do you want to do?';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['operator'] = 'field_what_do_you_want_to_do_target_id_op';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['identifier'] = 'field_what_do_you_want_to_do_target_id';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Age Group (field_age_group) */
  $handler->display->display_options['filters']['field_age_group_target_id']['id'] = 'field_age_group_target_id';
  $handler->display->display_options['filters']['field_age_group_target_id']['table'] = 'field_data_field_age_group';
  $handler->display->display_options['filters']['field_age_group_target_id']['field'] = 'field_age_group_target_id';
  $handler->display->display_options['filters']['field_age_group_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_age_group_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['operator_id'] = 'field_age_group_target_id_op';
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['label'] = 'What is your age group?';
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['operator'] = 'field_age_group_target_id_op';
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['identifier'] = 'field_age_group_target_id';
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: How long (field_how_long) */
  $handler->display->display_options['filters']['field_how_long_value']['id'] = 'field_how_long_value';
  $handler->display->display_options['filters']['field_how_long_value']['table'] = 'field_data_field_how_long';
  $handler->display->display_options['filters']['field_how_long_value']['field'] = 'field_how_long_value';
  $handler->display->display_options['filters']['field_how_long_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_how_long_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_how_long_value']['value']['max'] = '116121600';
  $handler->display->display_options['filters']['field_how_long_value']['group'] = 1;
  $handler->display->display_options['filters']['field_how_long_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_how_long_value']['expose']['operator_id'] = 'field_how_long_value_op';
  $handler->display->display_options['filters']['field_how_long_value']['expose']['label'] = 'For how long?';
  $handler->display->display_options['filters']['field_how_long_value']['expose']['operator'] = 'field_how_long_value_op';
  $handler->display->display_options['filters']['field_how_long_value']['expose']['identifier'] = 'field_how_long_value';
  $handler->display->display_options['filters']['field_how_long_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_how_long_value']['group_info']['label'] = 'For how long?';
  $handler->display->display_options['filters']['field_how_long_value']['group_info']['identifier'] = 'field_how_long_value';
  $handler->display->display_options['filters']['field_how_long_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '1 Week',
      'operator' => '<=',
      'value' => array(
        'value' => '604800',
        'min' => '604800',
        'max' => '604800',
      ),
    ),
    2 => array(
      'title' => '3 Weeks',
      'operator' => '<=',
      'value' => array(
        'value' => '1814400',
        'min' => '604800',
        'max' => '1814400',
      ),
    ),
    3 => array(
      'title' => '1 Month',
      'operator' => '<=',
      'value' => array(
        'value' => '2592000',
        'min' => '604800',
        'max' => '7257600',
      ),
    ),
    4 => array(
      'title' => '3 Months',
      'operator' => '<=',
      'value' => array(
        'value' => '7776000',
        'min' => '604800',
        'max' => '21772800',
      ),
    ),
    5 => array(
      'title' => '6 Months',
      'operator' => '<=',
      'value' => array(
        'value' => '15552000',
        'min' => '604800',
        'max' => '31536000',
      ),
    ),
    6 => array(
      'title' => '1 Year',
      'operator' => '<=',
      'value' => array(
        'value' => '31104000',
        'min' => '604800',
        'max' => '31536000',
      ),
    ),
  );
  /* Filter criterion: Content: View mode (field_view_mode) */
  $handler->display->display_options['filters']['field_view_mode_value']['id'] = 'field_view_mode_value';
  $handler->display->display_options['filters']['field_view_mode_value']['table'] = 'field_data_field_view_mode';
  $handler->display->display_options['filters']['field_view_mode_value']['field'] = 'field_view_mode_value';
  $handler->display->display_options['filters']['field_view_mode_value']['value'] = array(
    'program_with_sidemenu' => 'program_with_sidemenu',
    'program_without_sidemenu' => 'program_without_sidemenu',
  );
  $handler->display->display_options['filters']['field_view_mode_value']['group'] = 1;
  /* Filter criterion: Content: Where do you want to go (field_where_do_you_want_togo) */
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['id'] = 'field_where_do_you_want_togo_target_id';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['table'] = 'field_data_field_where_do_you_want_togo';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['field'] = 'field_where_do_you_want_togo_target_id';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['operator_id'] = 'field_where_do_you_want_togo_target_id_op';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['label'] = 'Where do you want to go ';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['operator'] = 'field_where_do_you_want_togo_target_id_op';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['identifier'] = 'field_where_do_you_want_togo_target_id';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Any special interests?';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'interest_keywords';
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = FALSE;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Program icons (field_program_icons) */
  $handler->display->display_options['filters']['field_program_icons_value']['id'] = 'field_program_icons_value';
  $handler->display->display_options['filters']['field_program_icons_value']['table'] = 'field_data_field_program_icons';
  $handler->display->display_options['filters']['field_program_icons_value']['field'] = 'field_program_icons_value';
  $handler->display->display_options['filters']['field_program_icons_value']['group'] = 1;
  $handler->display->display_options['filters']['field_program_icons_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['operator_id'] = 'field_program_icons_value_op';
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['label'] = 'Includes';
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['operator'] = 'field_program_icons_value_op';
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['identifier'] = 'field_program_icons_value';
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Language (field_language) */
  $handler->display->display_options['filters']['field_language_target_id']['id'] = 'field_language_target_id';
  $handler->display->display_options['filters']['field_language_target_id']['table'] = 'field_data_field_language';
  $handler->display->display_options['filters']['field_language_target_id']['field'] = 'field_language_target_id';
  $handler->display->display_options['filters']['field_language_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_language_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_language_target_id']['expose']['operator_id'] = 'field_language_target_id_op';
  $handler->display->display_options['filters']['field_language_target_id']['expose']['label'] = 'Program Language';
  $handler->display->display_options['filters']['field_language_target_id']['expose']['operator'] = 'field_language_target_id_op';
  $handler->display->display_options['filters']['field_language_target_id']['expose']['identifier'] = 'field_language_target_id';
  $handler->display->display_options['filters']['field_language_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Time of year (field_time_of_year) */
  $handler->display->display_options['filters']['field_time_of_year_value']['id'] = 'field_time_of_year_value';
  $handler->display->display_options['filters']['field_time_of_year_value']['table'] = 'field_data_field_time_of_year';
  $handler->display->display_options['filters']['field_time_of_year_value']['field'] = 'field_time_of_year_value';
  $handler->display->display_options['filters']['field_time_of_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_time_of_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['operator_id'] = 'field_time_of_year_value_op';
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['label'] = 'Time of year';
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['operator'] = 'field_time_of_year_value_op';
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['identifier'] = 'field_time_of_year_value';
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Total cost (field_total_cost) */
  $handler->display->display_options['filters']['field_total_cost_value']['id'] = 'field_total_cost_value';
  $handler->display->display_options['filters']['field_total_cost_value']['table'] = 'field_data_field_total_cost';
  $handler->display->display_options['filters']['field_total_cost_value']['field'] = 'field_total_cost_value';
  $handler->display->display_options['filters']['field_total_cost_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_total_cost_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_total_cost_value']['value']['max'] = '100000';
  $handler->display->display_options['filters']['field_total_cost_value']['group'] = 1;
  $handler->display->display_options['filters']['field_total_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_total_cost_value']['expose']['operator_id'] = 'field_total_cost_value_op';
  $handler->display->display_options['filters']['field_total_cost_value']['expose']['label'] = 'Total cost';
  $handler->display->display_options['filters']['field_total_cost_value']['expose']['operator'] = 'field_total_cost_value_op';
  $handler->display->display_options['filters']['field_total_cost_value']['expose']['identifier'] = 'field_total_cost_value';
  $handler->display->display_options['filters']['field_total_cost_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  $handler->display->display_options['path'] = 'opportunities';

  /* Display: Page - Hebrew */
  $handler = $view->new_display('page', 'Page - Hebrew', 'page_2');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Total cost (field_total_cost) */
  $handler->display->display_options['sorts']['field_total_cost_value_1']['id'] = 'field_total_cost_value_1';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['table'] = 'field_data_field_total_cost';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['field'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_total_cost_value_1']['expose']['label'] = 'Cost (Low to high)';
  /* Sort criterion: Content: Total cost (field_total_cost) */
  $handler->display->display_options['sorts']['field_total_cost_value']['id'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value']['table'] = 'field_data_field_total_cost';
  $handler->display->display_options['sorts']['field_total_cost_value']['field'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_total_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_total_cost_value']['expose']['label'] = 'Cost (High to low)';
  /* Sort criterion: Content: How long (field_how_long) */
  $handler->display->display_options['sorts']['field_how_long_value']['id'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value']['table'] = 'field_data_field_how_long';
  $handler->display->display_options['sorts']['field_how_long_value']['field'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_how_long_value']['expose']['label'] = 'Duration (Short to Long)';
  /* Sort criterion: Content: How long (field_how_long) */
  $handler->display->display_options['sorts']['field_how_long_value_1']['id'] = 'field_how_long_value_1';
  $handler->display->display_options['sorts']['field_how_long_value_1']['table'] = 'field_data_field_how_long';
  $handler->display->display_options['sorts']['field_how_long_value_1']['field'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_how_long_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_how_long_value_1']['expose']['label'] = 'Duration (Long to Short)';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'program_details' => 'program_details',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'חיפוש חופשי';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: What do you want to do (field_what_do_you_want_to_do) */
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['id'] = 'field_what_do_you_want_to_do_target_id';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['table'] = 'field_data_field_what_do_you_want_to_do';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['field'] = 'field_what_do_you_want_to_do_target_id';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['operator_id'] = 'field_what_do_you_want_to_do_target_id_op';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['label'] = 'What do you want to do?';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['operator'] = 'field_what_do_you_want_to_do_target_id_op';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['identifier'] = 'field_what_do_you_want_to_do_target_id';
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_what_do_you_want_to_do_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Age Group (field_age_group) */
  $handler->display->display_options['filters']['field_age_group_target_id']['id'] = 'field_age_group_target_id';
  $handler->display->display_options['filters']['field_age_group_target_id']['table'] = 'field_data_field_age_group';
  $handler->display->display_options['filters']['field_age_group_target_id']['field'] = 'field_age_group_target_id';
  $handler->display->display_options['filters']['field_age_group_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_age_group_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['operator_id'] = 'field_age_group_target_id_op';
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['label'] = 'What is your age group?';
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['operator'] = 'field_age_group_target_id_op';
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['identifier'] = 'field_age_group_target_id';
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_age_group_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: How long (field_how_long) */
  $handler->display->display_options['filters']['field_how_long_value']['id'] = 'field_how_long_value';
  $handler->display->display_options['filters']['field_how_long_value']['table'] = 'field_data_field_how_long';
  $handler->display->display_options['filters']['field_how_long_value']['field'] = 'field_how_long_value';
  $handler->display->display_options['filters']['field_how_long_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_how_long_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_how_long_value']['value']['max'] = '116121600';
  $handler->display->display_options['filters']['field_how_long_value']['group'] = 1;
  $handler->display->display_options['filters']['field_how_long_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_how_long_value']['expose']['operator_id'] = 'field_how_long_value_op';
  $handler->display->display_options['filters']['field_how_long_value']['expose']['label'] = 'For how long?';
  $handler->display->display_options['filters']['field_how_long_value']['expose']['operator'] = 'field_how_long_value_op';
  $handler->display->display_options['filters']['field_how_long_value']['expose']['identifier'] = 'field_how_long_value';
  $handler->display->display_options['filters']['field_how_long_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_how_long_value']['group_info']['label'] = 'For how long?';
  $handler->display->display_options['filters']['field_how_long_value']['group_info']['identifier'] = 'field_how_long_value';
  $handler->display->display_options['filters']['field_how_long_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '1 Week',
      'operator' => '<=',
      'value' => array(
        'value' => '604800',
        'min' => '604800',
        'max' => '604800',
      ),
    ),
    2 => array(
      'title' => '3 Weeks',
      'operator' => '<=',
      'value' => array(
        'value' => '1814400',
        'min' => '604800',
        'max' => '1814400',
      ),
    ),
    3 => array(
      'title' => '1 Month',
      'operator' => '<=',
      'value' => array(
        'value' => '2592000',
        'min' => '604800',
        'max' => '7257600',
      ),
    ),
    4 => array(
      'title' => '3 Months',
      'operator' => '<=',
      'value' => array(
        'value' => '7776000',
        'min' => '604800',
        'max' => '21772800',
      ),
    ),
    5 => array(
      'title' => '6 Months',
      'operator' => '<=',
      'value' => array(
        'value' => '15552000',
        'min' => '604800',
        'max' => '31536000',
      ),
    ),
    6 => array(
      'title' => '1 Year',
      'operator' => '<=',
      'value' => array(
        'value' => '31104000',
        'min' => '604800',
        'max' => '31536000',
      ),
    ),
  );
  /* Filter criterion: Content: View mode (field_view_mode) */
  $handler->display->display_options['filters']['field_view_mode_value']['id'] = 'field_view_mode_value';
  $handler->display->display_options['filters']['field_view_mode_value']['table'] = 'field_data_field_view_mode';
  $handler->display->display_options['filters']['field_view_mode_value']['field'] = 'field_view_mode_value';
  $handler->display->display_options['filters']['field_view_mode_value']['value'] = array(
    'program_with_sidemenu' => 'program_with_sidemenu',
    'program_without_sidemenu' => 'program_without_sidemenu',
  );
  $handler->display->display_options['filters']['field_view_mode_value']['group'] = 1;
  /* Filter criterion: Content: Where do you want to go (field_where_do_you_want_togo) */
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['id'] = 'field_where_do_you_want_togo_target_id';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['table'] = 'field_data_field_where_do_you_want_togo';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['field'] = 'field_where_do_you_want_togo_target_id';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['operator_id'] = 'field_where_do_you_want_togo_target_id_op';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['label'] = 'Where do you want to go ?';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['operator'] = 'field_where_do_you_want_togo_target_id_op';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['identifier'] = 'field_where_do_you_want_togo_target_id';
  $handler->display->display_options['filters']['field_where_do_you_want_togo_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Any special interests?';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'interest_keywords';
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = FALSE;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Program icons (field_program_icons) */
  $handler->display->display_options['filters']['field_program_icons_value']['id'] = 'field_program_icons_value';
  $handler->display->display_options['filters']['field_program_icons_value']['table'] = 'field_data_field_program_icons';
  $handler->display->display_options['filters']['field_program_icons_value']['field'] = 'field_program_icons_value';
  $handler->display->display_options['filters']['field_program_icons_value']['value'] = array(
    'housing' => 'housing',
    'tuition' => 'tuition',
    'full board' => 'full board',
    'flights' => 'flights',
    'visits to additional countries' => 'visits to additional countries',
  );
  $handler->display->display_options['filters']['field_program_icons_value']['group'] = 1;
  $handler->display->display_options['filters']['field_program_icons_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['operator_id'] = 'field_program_icons_value_op';
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['label'] = 'Includes';
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['operator'] = 'field_program_icons_value_op';
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['identifier'] = 'field_program_icons_value';
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_icons_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Language (field_language) */
  $handler->display->display_options['filters']['field_language_target_id']['id'] = 'field_language_target_id';
  $handler->display->display_options['filters']['field_language_target_id']['table'] = 'field_data_field_language';
  $handler->display->display_options['filters']['field_language_target_id']['field'] = 'field_language_target_id';
  $handler->display->display_options['filters']['field_language_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_language_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_language_target_id']['expose']['operator_id'] = 'field_language_target_id_op';
  $handler->display->display_options['filters']['field_language_target_id']['expose']['label'] = 'Program Language';
  $handler->display->display_options['filters']['field_language_target_id']['expose']['operator'] = 'field_language_target_id_op';
  $handler->display->display_options['filters']['field_language_target_id']['expose']['identifier'] = 'field_language_target_id';
  $handler->display->display_options['filters']['field_language_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Time of year (field_time_of_year) */
  $handler->display->display_options['filters']['field_time_of_year_value']['id'] = 'field_time_of_year_value';
  $handler->display->display_options['filters']['field_time_of_year_value']['table'] = 'field_data_field_time_of_year';
  $handler->display->display_options['filters']['field_time_of_year_value']['field'] = 'field_time_of_year_value';
  $handler->display->display_options['filters']['field_time_of_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_time_of_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['operator_id'] = 'field_time_of_year_value_op';
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['label'] = 'Time of year';
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['operator'] = 'field_time_of_year_value_op';
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['identifier'] = 'field_time_of_year_value';
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_time_of_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Total cost (field_total_cost) */
  $handler->display->display_options['filters']['field_total_cost_value']['id'] = 'field_total_cost_value';
  $handler->display->display_options['filters']['field_total_cost_value']['table'] = 'field_data_field_total_cost';
  $handler->display->display_options['filters']['field_total_cost_value']['field'] = 'field_total_cost_value';
  $handler->display->display_options['filters']['field_total_cost_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_total_cost_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_total_cost_value']['value']['max'] = '100000';
  $handler->display->display_options['filters']['field_total_cost_value']['group'] = 1;
  $handler->display->display_options['filters']['field_total_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_total_cost_value']['expose']['operator_id'] = 'field_total_cost_value_op';
  $handler->display->display_options['filters']['field_total_cost_value']['expose']['label'] = 'Total cost';
  $handler->display->display_options['filters']['field_total_cost_value']['expose']['operator'] = 'field_total_cost_value_op';
  $handler->display->display_options['filters']['field_total_cost_value']['expose']['identifier'] = 'field_total_cost_value';
  $handler->display->display_options['filters']['field_total_cost_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  $handler->display->display_options['path'] = 'opportunitiesHeb';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'content_filter';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Total cost (field_total_cost) */
  $handler->display->display_options['sorts']['field_total_cost_value']['id'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value']['table'] = 'field_data_field_total_cost';
  $handler->display->display_options['sorts']['field_total_cost_value']['field'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_total_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_total_cost_value']['expose']['label'] = 'Cost (High to low)';
  /* Sort criterion: Content: Total cost (field_total_cost) */
  $handler->display->display_options['sorts']['field_total_cost_value_1']['id'] = 'field_total_cost_value_1';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['table'] = 'field_data_field_total_cost';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['field'] = 'field_total_cost_value';
  $handler->display->display_options['sorts']['field_total_cost_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_total_cost_value_1']['expose']['label'] = 'Cost (Low to high)';
  /* Sort criterion: Content: How long (field_how_long) */
  $handler->display->display_options['sorts']['field_how_long_value']['id'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value']['table'] = 'field_data_field_how_long';
  $handler->display->display_options['sorts']['field_how_long_value']['field'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_how_long_value']['expose']['label'] = 'Duration (Short to Long)';
  /* Sort criterion: Content: How long (field_how_long) */
  $handler->display->display_options['sorts']['field_how_long_value_1']['id'] = 'field_how_long_value_1';
  $handler->display->display_options['sorts']['field_how_long_value_1']['table'] = 'field_data_field_how_long';
  $handler->display->display_options['sorts']['field_how_long_value_1']['field'] = 'field_how_long_value';
  $handler->display->display_options['sorts']['field_how_long_value_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_how_long_value_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_how_long_value_1']['expose']['label'] = 'Duration (Long to Short)';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  $handler->display->display_options['arguments']['type']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Terms (field_program_tags) */
  $handler->display->display_options['arguments']['field_program_tags_target_id']['id'] = 'field_program_tags_target_id';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['table'] = 'field_data_field_program_tags';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['field'] = 'field_program_tags_target_id';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_program_tags_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Terms (field_program_tags) */
  $handler->display->display_options['filters']['field_program_tags_target_id']['id'] = 'field_program_tags_target_id';
  $handler->display->display_options['filters']['field_program_tags_target_id']['table'] = 'field_data_field_program_tags';
  $handler->display->display_options['filters']['field_program_tags_target_id']['field'] = 'field_program_tags_target_id';
  $handler->display->display_options['filters']['field_program_tags_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_tags_target_id']['expose']['operator_id'] = 'field_program_tags_target_id_op';
  $handler->display->display_options['filters']['field_program_tags_target_id']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_program_tags_target_id']['expose']['operator'] = 'field_program_tags_target_id_op';
  $handler->display->display_options['filters']['field_program_tags_target_id']['expose']['identifier'] = 'field_program_tags_target_id';
  $handler->display->display_options['filters']['field_program_tags_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_tags_target_id']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['keys']['remove_score'] = TRUE;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Terms (field_program_tags) */
  $handler->display->display_options['filters']['field_program_tags_target_id_1']['id'] = 'field_program_tags_target_id_1';
  $handler->display->display_options['filters']['field_program_tags_target_id_1']['table'] = 'field_data_field_program_tags';
  $handler->display->display_options['filters']['field_program_tags_target_id_1']['field'] = 'field_program_tags_target_id';
  $handler->display->display_options['filters']['field_program_tags_target_id_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_tags_target_id_1']['expose']['operator_id'] = 'field_program_tags_target_id_1_op';
  $handler->display->display_options['filters']['field_program_tags_target_id_1']['expose']['label'] = 'Tags (field_program_tags)';
  $handler->display->display_options['filters']['field_program_tags_target_id_1']['expose']['operator'] = 'field_program_tags_target_id_1_op';
  $handler->display->display_options['filters']['field_program_tags_target_id_1']['expose']['identifier'] = 'field_program_tags_target_id_1';
  $handler->display->display_options['filters']['field_program_tags_target_id_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_tags_target_id_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $translatables['opportunities'] = array(
    t('Master'),
    t('Opportunities'),
    t('Load More opps'),
    t('Apply'),
    t('CLEAR ALL'),
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
    t('Opportunities_footer'),
    t('FOR THE MOST UP TO DATE PRICING AND TIMING DETAILS, PLEASE CONTACT THE PROGRAMS DIRECTLY USING THE CONTACT INFORMATION PROVIDED.'),
    t('Can\'t find what you are looking for, <a href="http://www.jewishagency.org/">click here</a>'),
    t('Cost (High to low)'),
    t('Cost (Low to high)'),
    t('Duration (Short to Long)'),
    t('Duration (Long to Short)'),
    t('Page'),
    t('more'),
    t('Free search'),
    t('What do you want to do?'),
    t('What is your age group?'),
    t('For how long?'),
    t('Where do you want to go '),
    t('Any special interests?'),
    t('Includes'),
    t('Program Language'),
    t('Time of year'),
    t('Total cost'),
    t('Page - Hebrew'),
    t('חיפוש חופשי'),
    t('Where do you want to go ?'),
    t('Block'),
    t('All'),
    t('Tags'),
    t('Search Terms'),
    t('Tags (field_program_tags)'),
  );
  $export['opportunities'] = $view;

  return $export;
}
