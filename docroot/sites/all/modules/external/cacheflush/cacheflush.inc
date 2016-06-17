<?php

/**
 * @file
 * Cacheflusher module inc file with dinamic clear cache functions.
 */

/**
 * Clear all caches function.
 */
function _cacheflush_clear_all() {

  // Clear all caches.
  drupal_flush_all_caches();
  drupal_set_message(t('All caches cleared.'));
  drupal_goto($_SERVER['HTTP_REFERER']);
}

/**
 * Call clear cache and send back.
 * 
 * @param int $preset_id
 *   Preset id to do clear cache for.
 */
function cacheflush_clear_preset_menu_callback($preset_id) {
  _cacheflush_clear_preset($preset_id);
  drupal_goto($_SERVER['HTTP_REFERER']);
}

/**
 * Based on settings decide witch clear cache function to be called.
 * 
 * @param int $preset_id
 *   Preset id to do clear cache for.
 */
function _cacheflush_clear_preset($preset_id) {

  // Get presets.
  $cache_presets = variable_get('cacheflush_preset_list', array());

  // Declare hook before cache cleared.
  module_invoke_all('cacheflush_clear_before', array('preset_id' => $preset_id, 'presets_list' => $cache_presets));

  // Decide if is table or function and call specifed function to clear cache.
  foreach ($cache_presets[$preset_id]['#cacheflush_preset_values'] as $key => $value) {
    if ($value['is_table']) {
      _cacheflush_clear_preset_clear_table($key, $value);
    }
    else {
      _cacheflush_clear_preset_clear_call_functions($value);
    }
  }

  drupal_set_message(t("@name preset caches cleared.", array('@name' => $cache_presets[$preset_id]['#name'])));

  // Declare hook after cache cleared.
  module_invoke_all('cacheflush_clear_after', array('preset_id' => $preset_id, 'presets_list' => $cache_presets));
}

/**
 * Function to clear cache from a specific table.
 * 
 * @param string $table
 *   Table name.
 * @param array $settings
 *   Preset setting with cache clear functions.
 */
function _cacheflush_clear_preset_clear_table($table, $settings) {

  // If is advanced preset clear by settings else clear all table.
  if (isset($settings['query'])) {
    cache_clear_all($settings['query']['cid'], $settings['query']['table'], ($settings['query']['wildcard']) ? TRUE : FALSE);
  }
  else {
    cache_clear_all('*', $table, TRUE);
  }
}

/**
 * Call predefined functions to clear cache.
 * 
 * @param array $settings
 *   Preset setting with cache clear functions.
 */
function _cacheflush_clear_preset_clear_call_functions($settings) {

  // Call every function declared in preset.
  foreach ($settings['functions'] as $value) {
    $value();
  }
}
