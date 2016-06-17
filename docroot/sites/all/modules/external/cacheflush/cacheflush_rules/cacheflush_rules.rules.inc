<?php

/**
 * @file
 * Cacheflush Rules action include.
 */

/**
 * Implements hook_rules_event_info().
 */
function cacheflush_rules_rules_event_info() {
  return array(
    'cacheflush_before' => array(
      'label' => t('Before clearing a preset'),
      'group' => t('Cacheflush'),
      'variables' => array(
        'preset_id' => array(
          'type' => 'integer',
        ),
      ),
    ),
    'cacheflush_after' => array(
      'label' => t('After clearing a preset'),
      'group' => t('Cacheflush'),
      'variables' => array(
        'preset_id' => array(
          'type' => 'integer',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function cacheflush_rules_rules_condition_info() {
  return array(
    'cacheflush_rules_condition_compare' => array(
      'label' => t('Presets'),
      'parameter' => array(
        'preset_id' => array(
          'type' => 'list<integer>',
          'label' => t('Presets'),
          'options list' => 'cacheflush_rules_get_preset_list',
          'description' => t('Multiple value allowed to.'),
        ),
      ),
      'group' => t('Cacheflush'),
    ),
  );
}

/**
 * Implements hook_rules_action_info().
 */
function cacheflush_rules_rules_action_info() {
  return array(
    'cacheflush_debug' => array(
      'base' => 'cacheflush_rules_clear_cache',
      'label' => t('Clear cache by presets Id.'),
      'group' => t('Cacheflush'),
      'parameter' => array(
        'preset_id' => array(
          'type' => 'list<integer>',
          'label' => t('Presets'),
          'options list' => 'cacheflush_rules_get_preset_list',
          'description' => t('Multiple value allowed to.'),
        ),
      ),
    ),
  );
}
