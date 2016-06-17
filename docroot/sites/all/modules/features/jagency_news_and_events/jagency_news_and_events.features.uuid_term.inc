<?php
/**
 * @file
 * jagency_news_and_events.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function jagency_news_and_events_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Aliyah',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'b9aa0bc6-f662-49dd-a689-42a36d87cdf9',
    'vocabulary_machine_name' => 'jewish_agency',
    'field_color' => array(
      'und' => array(
        0 => array(
          'value' => 'orange',
          'format' => NULL,
          'safe_value' => 'orange',
        ),
      ),
    ),
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'jewish-agency/aliyah',
        'language' => 'und',
      ),
    ),
  );
  return $terms;
}
