<?php
/**
 * @file
 * jagency_content_filter.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jagency_content_filter_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'content_filter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content Filter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content filter';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Load More opps';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
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
    'field_start_date_value' => array(
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
      'bef_format' => 'default',
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['waypoint']['infinite'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'content_filter';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Can\'t find what you are looking for, <a href="#">click here</a>';
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
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  $handler->display->display_options['filters']['current_all']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['current_all']['expose']['label'] = 'Available on current domain';
  $handler->display->display_options['filters']['current_all']['expose']['operator'] = 'current_all_op';
  $handler->display->display_options['filters']['current_all']['expose']['identifier'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Has taxonomy term (multiple vocabalaries) */
  $handler->display->display_options['filters']['tid_multi']['id'] = 'tid_multi';
  $handler->display->display_options['filters']['tid_multi']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_multi']['field'] = 'tid_multi';
  $handler->display->display_options['filters']['tid_multi']['group'] = 1;
  $handler->display->display_options['filters']['tid_multi']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_multi']['expose']['operator_id'] = 'tid_multi_op';
  $handler->display->display_options['filters']['tid_multi']['expose']['label'] = 'Has taxonomy term (multiple vocabalaries)';
  $handler->display->display_options['filters']['tid_multi']['expose']['operator'] = 'tid_multi_op';
  $handler->display->display_options['filters']['tid_multi']['expose']['identifier'] = 'field_program_tags_target_id';
  $handler->display->display_options['filters']['tid_multi']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['tid_multi']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['tid_multi']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid_multi']['type'] = 'select';
  $handler->display->display_options['filters']['tid_multi']['vocabulary'] = array(
    'age_groups' => 'age_groups',
    'aliyah_services_location' => 'aliyah_services_location',
    'aticle_types' => 'aticle_types',
    'contentcreationunit' => 'contentcreationunit',
    'entities' => 'entities',
    'facebook' => 'facebook',
    'interest_keywords' => 'interest_keywords',
    'jewish_agency' => 'jewish_agency',
    'language' => 'language',
    'locations' => 'locations',
    'media_folders' => 'media_folders',
    'months' => 'months',
    'news_type' => 'news_type',
    'organizations' => 'organizations',
    'p2g_locations' => 'p2g_locations',
    'p2gcatalog_main' => 'p2gcatalog_main',
    'p2gcatfieldsactivity' => 'p2gcatfieldsactivity',
    'p2gcatglobalprogram' => 'p2gcatglobalprogram',
    'p2gcatleadershipgroups' => 'p2gcatleadershipgroups',
    'p2gcatspecialgroups' => 'p2gcatspecialgroups',
    'p2ginfocenter' => 'p2ginfocenter',
    'p2gpartnerships' => 'p2gpartnerships',
    'p2gschoolaudiences' => 'p2gschoolaudiences',
    'p2gschoolcontent' => 'p2gschoolcontent',
    'p2gschoollengthofactivity' => 'p2gschoollengthofactivity',
    'p2gschoollessonorcontent' => 'p2gschoollessonorcontent',
    'p2gschoollessons' => 'p2gschoollessons',
    'p2gschoolnavigation' => 'p2gschoolnavigation',
    'p2gschooltypeofconnection' => 'p2gschooltypeofconnection',
    'program_category' => 'program_category',
    'roles' => 'roles',
    'tags' => 'tags',
    'type_of_program' => 'type_of_program',
    'type_of_resource' => 'type_of_resource',
    'what_do_you_want_to_do' => 'what_do_you_want_to_do',
    'where_do_you_want_to_go' => 'where_do_you_want_to_go',
    'years' => 'years',
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
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
  /* Filter criterion: Content: Has taxonomy term (multiple vocabalaries) */
  $handler->display->display_options['filters']['tid_multi_1']['id'] = 'tid_multi_1';
  $handler->display->display_options['filters']['tid_multi_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_multi_1']['field'] = 'tid_multi';
  $handler->display->display_options['filters']['tid_multi_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_multi_1']['expose']['operator_id'] = 'tid_multi_1_op';
  $handler->display->display_options['filters']['tid_multi_1']['expose']['label'] = 'Has taxonomy term (multiple vocabalaries)';
  $handler->display->display_options['filters']['tid_multi_1']['expose']['operator'] = 'tid_multi_1_op';
  $handler->display->display_options['filters']['tid_multi_1']['expose']['identifier'] = 'field_program_tags_target_id_1';
  $handler->display->display_options['filters']['tid_multi_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['tid_multi_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['tid_multi_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid_multi_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_multi_1']['vocabulary'] = array(
    'age_groups' => 'age_groups',
    'aliyah_services_location' => 'aliyah_services_location',
    'aticle_types' => 'aticle_types',
    'contentcreationunit' => 'contentcreationunit',
    'entities' => 'entities',
    'facebook' => 'facebook',
    'interest_keywords' => 'interest_keywords',
    'jewish_agency' => 'jewish_agency',
    'language' => 'language',
    'locations' => 'locations',
    'media_folders' => 'media_folders',
    'months' => 'months',
    'news_type' => 'news_type',
    'organizations' => 'organizations',
    'p2g_locations' => 'p2g_locations',
    'p2gcatalog_main' => 'p2gcatalog_main',
    'p2gcatfieldsactivity' => 'p2gcatfieldsactivity',
    'p2gcatglobalprogram' => 'p2gcatglobalprogram',
    'p2gcatleadershipgroups' => 'p2gcatleadershipgroups',
    'p2gcatspecialgroups' => 'p2gcatspecialgroups',
    'p2ginfocenter' => 'p2ginfocenter',
    'p2gpartnerships' => 'p2gpartnerships',
    'p2gschoolaudiences' => 'p2gschoolaudiences',
    'p2gschoolcontent' => 'p2gschoolcontent',
    'p2gschoollengthofactivity' => 'p2gschoollengthofactivity',
    'p2gschoollessonorcontent' => 'p2gschoollessonorcontent',
    'p2gschoollessons' => 'p2gschoollessons',
    'p2gschoolnavigation' => 'p2gschoolnavigation',
    'p2gschooltypeofconnection' => 'p2gschooltypeofconnection',
    'program_category' => 'program_category',
    'roles' => 'roles',
    'tags' => 'tags',
    'type_of_program' => 'type_of_program',
    'type_of_resource' => 'type_of_resource',
    'what_do_you_want_to_do' => 'what_do_you_want_to_do',
    'where_do_you_want_to_go' => 'where_do_you_want_to_go',
    'years' => 'years',
  );

  /* Display: Content Filter */
  $handler = $view->new_display('block', 'Content Filter', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'age_groups' => 0,
    'aliyah_services_location' => 0,
    'aticle_types' => 0,
    'contentcreationunit' => 0,
    'entities' => 0,
    'facebook' => 0,
    'interest_keywords' => 0,
    'jewish_agency' => 0,
    'language' => 0,
    'locations' => 0,
    'media_folders' => 0,
    'months' => 0,
    'news_type' => 0,
    'organizations' => 0,
    'p2g_locations' => 0,
    'p2gcatalog_main' => 0,
    'p2gcatfieldsactivity' => 0,
    'p2gcatglobalprogram' => 0,
    'p2gcatleadershipgroups' => 0,
    'p2gcatspecialgroups' => 0,
    'p2ginfocenter' => 0,
    'p2gpartnerships' => 0,
    'p2gschoolaudiences' => 0,
    'p2gschoolcontent' => 0,
    'p2gschoollengthofactivity' => 0,
    'p2gschoollessonorcontent' => 0,
    'p2gschoollessons' => 0,
    'p2gschoolnavigation' => 0,
    'p2gschooltypeofconnection' => 0,
    'program_category' => 0,
    'roles' => 0,
    'tags' => 0,
    'type_of_program' => 0,
    'type_of_resource' => 0,
    'what_do_you_want_to_do' => 0,
    'where_do_you_want_to_go' => 0,
    'years' => 0,
  );
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
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';

  /* Display: RSS */
  $handler = $view->new_display('feed', 'RSS', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '400';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'content/filter/rss';
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
  );
  $translatables['content_filter'] = array(
    t('Master'),
    t('Content filter'),
    t('Load More opps'),
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
    t('Can\'t find what you are looking for, <a href="#">click here</a>'),
    t('Cost (High to low)'),
    t('Cost (Low to high)'),
    t('Duration (Short to Long)'),
    t('Duration (Long to Short)'),
    t('Available on current domain'),
    t('Has taxonomy term (multiple vocabalaries)'),
    t('Search Terms'),
    t('Content Filter'),
    t('more'),
    t('term'),
    t('All'),
    t('RSS'),
  );
  $export['content_filter'] = $view;

  return $export;
}
