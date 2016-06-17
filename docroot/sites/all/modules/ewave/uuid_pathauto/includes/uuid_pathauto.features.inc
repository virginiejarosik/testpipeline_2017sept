<?php
/**
 * @file
 * Features hooks for the uuid_pathauto features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_pathauto_features_export_options() {
  $options = array();

  $query = 'SELECT name, value
    FROM {variable}
    WHERE name LIKE (\'pathauto%\')';
  $results = db_query($query);
  foreach ($results as $item) {
    $options[$item->name] = $item->name;
  }
  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_pathauto_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['pathauto'] = 'pathauto';
  $export['dependencies']['uuid'] = 'uuid';
  $export['dependencies']['uuid_features'] = 'uuid_features';
  foreach ($data as $uuid) {
    uuid_pathauto_features_get_dependencies($export, $uuid);
  }
  return array();
}

/**
 * Adds pathauto items to the export.
 */
function uuid_pathauto_features_get_dependencies(&$export, $uuid) {
  $item = variable_get($uuid, '');
  if ($item) {
    $export['features']['uuid_pathauto'][$uuid] = $uuid;
    $export['features']['pathauto'][$uuid] = base64_encode($item);
  }
}

/**
 * Implements hook_features_export_render().
 */
function uuid_pathauto_features_export_render($module = 'foo', $data) {
  $translatables = $code = array();

  $code[] = '  $pathauto = array();';
  foreach ($data as $uuid) {
    $item = variable_get($uuid);
    $code[] = '  $pathauto["' . $uuid . '"] = ' . features_var_export($item, '  ') . ';';
  }
  $code[] = '  return $pathauto;';
  $code = implode("\n", $code);
  return array('uuid_features_default_pathauto' => $code);
}

/**
 * Implements hook_features_revert().
 */
function uuid_pathauto_features_revert($module) {
  uuid_pathauto_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 * Rebuilds pathauto items based on UUID from code defaults.
 */
function uuid_pathauto_features_rebuild($module) {
  $items = module_invoke($module, 'uuid_features_default_pathauto');
  if (!empty($items)) {
    foreach ($items as $uuid => $data) {
      variable_set($uuid, $data);
    }
  }
}
