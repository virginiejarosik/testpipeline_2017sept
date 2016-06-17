<?php
/**
 * @file
 * jagency_custom_menu.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jagency_custom_menu_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'menu_location';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Menu Location';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
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
  /* Contextual filter: Content: Location (field_location) */
  $handler->display->display_options['arguments']['field_location_value']['id'] = 'field_location_value';
  $handler->display->display_options['arguments']['field_location_value']['table'] = 'field_data_field_location';
  $handler->display->display_options['arguments']['field_location_value']['field'] = 'field_location_value';
  $handler->display->display_options['arguments']['field_location_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_location_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_location_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_location_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_location_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_location_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_location_value']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Content Reference (field_content_reference) */
  $handler->display->display_options['arguments']['field_content_reference_target_id']['id'] = 'field_content_reference_target_id';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['table'] = 'field_data_field_content_reference';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['field'] = 'field_content_reference_target_id';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['break_phrase'] = TRUE;
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
    'custom_menu' => 'custom_menu',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: By Content */
  $handler = $view->new_display('panel_pane', 'By Content', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Content Reference (field_content_reference) */
  $handler->display->display_options['arguments']['field_content_reference_target_id']['id'] = 'field_content_reference_target_id';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['table'] = 'field_data_field_content_reference';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['field'] = 'field_content_reference_target_id';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_content_reference_target_id']['break_phrase'] = TRUE;

  /* Display: By Location */
  $handler = $view->new_display('panel_pane', 'By Location', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Location (field_location) */
  $handler->display->display_options['arguments']['field_location_value']['id'] = 'field_location_value';
  $handler->display->display_options['arguments']['field_location_value']['table'] = 'field_data_field_location';
  $handler->display->display_options['arguments']['field_location_value']['field'] = 'field_location_value';
  $handler->display->display_options['arguments']['field_location_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_location_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_location_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_location_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_location_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_location_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_location_value']['break_phrase'] = TRUE;

  /* Display: By Content & Location */
  $handler = $view->new_display('panel_pane', 'By Content & Location', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['menu_location'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('By Content'),
    t('View panes'),
    t('By Location'),
    t('By Content & Location'),
  );
  $export['menu_location'] = $view;

  return $export;
}
