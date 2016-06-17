<?php
/**
 * @file
 * jagency_subscribe_mailer.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function jagency_subscribe_mailer_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_machine_name'
  $field_bases['field_machine_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_machine_name',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'contact_us' => 'Contact us page',
        'short_contact_us' => 'Short contact us form',
        'newletter' => 'Newsletter Form',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
