<?php

/**
 * @file
 * Cacheflush module add/edit form for presets.
 */

/**
 * Callback function after drupal_get_form().
 *
 * @param int $preset_id
 *   Preset id
 *
 * @return array
 *   Array with form elements.
 */
function cacheflush_preset_form($form, &$form_state, $preset_id) {

  // Getting cache table list.
  $form_state['cacheflush_table_list'] = $cache_tables  = _cacheflush_get_table_list();
  // Getting cache preset list.
  $form_state['cacheflush_preset_list'] = $cache_presets = variable_get('cacheflush_preset_list', array());
  // Is edit or add.
  $form_state['cacheflush_preset_is_edit'] = ($preset_id) ? TRUE : FALSE;

  // Checking if preset id is valid or is a predefined preset.
  if ($preset_id && (!isset($cache_presets[$preset_id]) || $preset_id < 5)) {
    drupal_set_message(t('Wrong preset id.'), 'error');
    return $form;
  }
  elseif (!$form_state['cacheflush_preset_is_edit']) {
    $preset_id = max(array_keys($cache_presets)) + 1;
  }

  $form_state['cacheflush_preset_id'] = $preset_id;

  // Form element for preset name.
  $form['cacheflush_preset_name'] = array(
    '#type' => "textfield",
    '#title' => t('Preset Name'),
    '#default_value' => ($form_state['cacheflush_preset_is_edit']) ? $cache_presets[$preset_id]['#name'] : '',
    '#weight' => 0,
    '#required' => TRUE,
  );

  // Form element, vertical tab parent.
  $form['cacheflush_vertical_tabs'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 50,
    '#attached' => array(
      'js' => array(
        'vertical-tabs' => drupal_get_path('module', 'cacheflush') . '/js/cacheflush_vertical_tabs.js',
      ),
    ),
  );

  // Vertical tabs.
  $form_state['cacheflush_vertical_tabs'] = array(
    'vertical_tabs_core' => t('Core cache tables'),
    'vertical_tabs_functions' => t('Other core cache options'),
    'vertical_tabs_custom' => t('Contrib cache tables'),
    'vertical_tabs_often' => t('Other contrib cache options'),
  );

  // Creating vertical tabs.
  $i = 0;
  foreach ($form_state['cacheflush_vertical_tabs'] as $key => $value) {
    $form[$key] = array(
      '#type' => 'fieldset',
      '#title' => check_plain($value),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#group' => 'cacheflush_vertical_tabs',
      '#tree' => TRUE,
      '#weight' => $i++,
    );
  }

  // Adding table elemnts to tabs.
  foreach ($cache_tables as $key => $value) {
    // Special tab element added only if there module are instaled.
    if ($value['category'] == 'often' && !module_exists($key)) {
      continue;
    }
    $form['vertical_tabs_' . $value['category']]["cacheflush_checkbox_$key"] = array(
      '#type' => "checkbox",
      '#title' => check_plain($key),
      '#default_value' => isset($cache_presets[$preset_id]['#cacheflush_preset_values'][$key]) ? 1 : 0,
      '#description' => check_plain($value['description']),
    );
    unset($cache_presets[$preset_id]['#cacheflush_preset_values'][$key]);
  }

  // Form element Submit button.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create'),
  );

  // If editing preset change Submit button name and add Delete button.
  if ($form_state['cacheflush_preset_is_edit']) {
    $form['actions']['submit']['#value'] = t('Update');
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('cacheflush_delete_preset_submit'),
    );
  }

  // Form element Cancel button.
  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), 'admin/config/development/cacheflush'),
  );

  _cacheflush_form_descriptions($form);

  return $form;
}

/**
 * Implements hook_formID_validate().
 */
function cacheflush_preset_form_validate(&$form, &$form_state) {

  // Create new preset.
  $form_state['cacheflush_preset_list'][$form_state['cacheflush_preset_id']]['#name'] = check_plain($form_state['values']['cacheflush_preset_name']);
  $form_state['cacheflush_preset_list'][$form_state['cacheflush_preset_id']]['#cacheflush_preset_values'] = array();
  $form_state['cacheflush_preset_list'][$form_state['cacheflush_preset_id']]['#enabled'] = TRUE;

  // Get all tabs checkboxes.
  $checkboxes = array();
  foreach ($form_state['cacheflush_vertical_tabs'] as $key => $value) {
    if (isset($form_state['values'][$key]) && $key != 'vertical_tabs_advance') {
      $checkboxes = array_merge($checkboxes, $form_state['values'][$key]);
    }
  }

  // Check the checkboxes value.
  foreach ($checkboxes as $key => $value) {
    if ($value == '1') {
      $pos = strpos($key, 'cacheflush_checkbox_');
      if ($pos !== FALSE) {
        list($null, $id) = explode('cacheflush_checkbox_', $key);
        $form_state['cacheflush_preset_list'][$form_state['cacheflush_preset_id']]['#cacheflush_preset_values'][$id] = $form_state['cacheflush_table_list'][$id];
      }
    }
  }

  // Check if any preset created.
  if ((count($form_state['cacheflush_preset_list'][$form_state['cacheflush_preset_id']]['#cacheflush_preset_values']) < 1)) {
    form_set_error(t('Presets'), t('You must select a table or create an advanced preset.'));
  }
}

/**
 * Implements hook_formID_submit().
 */
function cacheflush_preset_form_submit(&$form, &$form_state) {

  // Save preset list.
  variable_set('cacheflush_preset_list', $form_state['cacheflush_preset_list']);
  drupal_set_message(t('Preset successfully saved.'), 'status');

  // Rebuild menu.
  node_types_rebuild();
  menu_rebuild();
}

/**
 * Implements cacheflush_delete_preset_submit().
 */
function cacheflush_delete_preset_submit(&$form, &$form_state) {
  drupal_goto('admin/config/development/cacheflush/preset/delete/' . $form_state['cacheflush_preset_id']);
}

/**
 * Callback function after drupal_get_form().
 */
function cacheflush_delete_preset_form($form, &$form_state, $preset_id) {

  $desc = t('Are you sure you want to delete the preset? This action cannot be undone.');
  $ques = t('Are you sure?');
  $form_state['cacheflush_preset_id'] = $preset_id;
  return confirm_form($form, $ques, 'admin/config/development/cacheflush', $desc);
}

/**
 * Implements hook_formID_submit().
 */
function cacheflush_delete_preset_form_submit(&$form, &$form_state) {

  cacheflush_preset_form_delete($form_state['cacheflush_preset_id']);
}

/**
 * Function for deleting presets.
 *
 * @param array $id
 *   Preset ID.
 * @param array $cache_presets
 *   List of presets.
 */
function cacheflush_preset_form_delete($id, $cache_presets = array()) {

  // If delete called from list.
  if (empty($cache_presets)) {
    $cache_presets = variable_get('cacheflush_preset_list', array());
  }

  // Delete preset.
  unset($cache_presets[$id]);
  variable_set('cacheflush_preset_list', $cache_presets);
  drupal_set_message(t('Preset successfully deleted.'), 'status');

  // Rebuild menu.
  node_types_rebuild();
  menu_rebuild();
  drupal_goto("admin/config/development/cacheflush");
}

/**
 * Return a list of used cache tables on the curent Drupal instalation.
 * 
 * @return array
 *   List cache tables.
 */
function _cacheflush_get_table_list() {

  $core_tables = variable_get('cacheflush_global_config', array());
  $custome_tables = array_flip(module_invoke_all('flush_caches'));

  $tables_info = array();

  foreach ($custome_tables as $key => $value) {
    $schema = drupal_get_schema($key);
    $schema = drupal_get_schema_unprocessed($schema['module'], 'cache_bootstrap');
    $tables_info[$key] = array(
      'is_table' => TRUE,
      'description' => t($schema[$key]['description']),
      'category' => 'custom',
    );
  }

  return array_merge($core_tables, $tables_info);
}

/**
 * Update form tabs with Notes.
 */
function _cacheflush_form_descriptions(&$form) {

  $form['cacheflush_form_mani_note'] = array(
    '#type' => 'item',
    '#title' => t('Cache sources'),
    '#weight' => 40,
    '#description' => t("Select below the different cache sources you wish to clear when your preset is executed. Don't be afraid to select them, all these are flushed when you normally clear all the caches. Select only those you need for better performance."),
  );

  $form['vertical_tabs_core']['note'] = array(
    '#type' => 'item',
    '#title' => t('Note'),
    '#description' => t("Select any of the cache database tables below, to be truncated when this preset is executed."),
    '#weight' => -10,
  );

  $form['vertical_tabs_functions']['note'] = array(
    '#type' => 'item',
    '#title' => t('Note'),
    '#description' => t("Select any of the below functions to be run when this preset is executed."),
    '#weight' => -10,
  );

  $form['vertical_tabs_custom']['note'] = array(
    '#type' => 'item',
    '#title' => t('Note'),
    '#description' => t("Select any of the tables defined by contributed modules to be flushed when this preset is executed."),
    '#weight' => -10,
  );

  $form['vertical_tabs_often']['note'] = array(
    '#type' => 'item',
    '#title' => t('Note'),
    '#description' => t('Some contrib modules have unique ways to store their cache, or to flush them.<br />These require custom configuration, so if you can`t find some of your contrib modules here, please submit us an issue on <a href="@url">http://drupal.org/project/cacheflush/issues/</a><br />
Select any from the list below to clear when this preset is executed.', array('@url' => url('http://drupal.org/project/cacheflush/issues/'))),
    '#weight' => -10,
  );

}
