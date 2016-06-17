<?php

function jagency_migrate_views_data() {

  $data['migration']['table']['group'] = t('Migrate');

  $data['migration']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Agency Migrate'),
    'help' => t("Agency Migrate table with migration content"),
    'weight' => -10,
  );

  $data['migration']['hash'] = array(
    'title' => t('Hash'),
    'help' => t('Unique hash field.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['migration']['url'] = array(
    'title' => t('Url'),
    'help' => t('Url of content.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['migration']['parent'] = array(
    'title' => t('Parent'),
    'help' => t('Refferer, from whate we came to get this url.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['migration']['http_status'] = array(
    'title' => t('Http Status'),
    'help' => t('Status that we recivied from url.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['migration']['content'] = array(
    'title' => t('Content'),
    'help' => t('Content that fetched from url.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['migration']['meta'] = array(
    'title' => t('Metatags'),
    'help' => t('Metatags that fetched from url.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // Example numeric text field.
  $data['migration']['status'] = array(
    'title' => t('Status'),
    'help' => t('Status of current migration object.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  /**
   * Migration History
   */
  $data['migration_history']['table']['group'] = t('Migrate History');

  $data['migration_history']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Agency Migrate History'),
    'help' => t("Agency Migrate History table with migration content"),
    'weight' => -10,
  );

  $data['migration_history']['original'] = array(
    'title' => t('Original Url'),
    'help' => t('Original url from jafi.org website'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['migration_history']['website'] = array(
    'title' => t('Url'),
    'help' => t('Url of content.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  return $data;

}