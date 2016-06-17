<?php

/**
 * @file
 * Cacheflush admin for list presets.
 */

/**
 * Callback function after drupal_get_form().
 */
function cacheflush_list_preset_form($form, &$form_state) {

  // Get the preset list.
  $form_state['cacheflush_preset_list'] = $cache_presets = variable_get('cacheflush_preset_list', array());

  // Table header.
  $rows = $default_value = array();
  $header = array(
    'title' => array(
      'data' => t('Title'),
      'style' => 'width:100%;',
    ),
    'operations' => t('Operations'),
  );

  // Table rows.
  foreach ($cache_presets as $key => $value) {
    $operations = '';
    if (!isset($value['#editable'])) {
      $operations = l(t('Edit'), "admin/config/development/cacheflush/preset/$key") . ' | ' . l(t('Delete'), "admin/config/development/cacheflush/preset/delete/$key");
    }
    $rows[$key] = array(
      'title' => $value['#name'],
      'operations' => $operations,
    );
    $default_value[$key] = $value['#enabled'];
  }

  // The table form element.
  $form['preset_list'] = array(
    '#type' => 'tableselect',
    '#title' => t('Preset List'),
    '#header' => $header,
    '#options' => $rows,
    '#multiple' => TRUE,
    '#default_value' => $default_value,
    '#empty' => t('No content available.'),
    '#js_select' => FALSE,
    '#attributes' => array('id' => 'cachefulsher_preset_list'),
  );

  // Submit button.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Implements hook_preprocess_table().
 */
function cacheflush_preprocess_table(&$variables) {

  // Changing the checkbox header to Status string.
  if (isset($variables['attributes']['id']) && $variables['attributes']['id'] == 'cachefulsher_preset_list') {
    $variables['header'][0] = t('Status');
  }
}

/**
 * Implements hook_formID_submit().
 */
function cacheflush_list_preset_form_submit(&$form, &$form_state) {

  // Update the presets status.
  foreach ($form_state['values']['preset_list'] as $key => $value) {
    $form_state['cacheflush_preset_list'][$key]['#enabled'] = $value;
  }

  // Save the result.
  variable_set('cacheflush_preset_list', $form_state['cacheflush_preset_list']);
  drupal_set_message(t('Preset list enabled/disabled.'), 'status');

  // Rebuild Menu.
  node_types_rebuild();
  menu_rebuild();
}
