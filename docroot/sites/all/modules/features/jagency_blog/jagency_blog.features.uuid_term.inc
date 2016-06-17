<?php
/**
 * @file
 * jagency_blog.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function jagency_blog_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Jewish Social Action',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 60,
    'uuid' => '20709613-5cb5-4fbc-aa6a-3404142ab863',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'jewish_agency',
    'field_color' => array(
      'und' => array(
        0 => array(
          'value' => 'yellow',
          'format' => NULL,
          'safe_value' => 'yellow',
        ),
      ),
    ),
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'jewish-agency/jewish-social-action',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Israel In Your Community',
    'description' => '',
    'format' => 'full_html',
    'weight' => 59,
    'uuid' => '39ea6942-5a18-4f19-8bac-668fa247be55',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'jewish_agency',
    'field_color' => array(
      'und' => array(
        0 => array(
          'value' => 'green',
          'format' => NULL,
          'safe_value' => 'green',
        ),
      ),
    ),
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'jewish-agency/israel-your-community',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Aliyah',
    'description' => '',
    'format' => 'full_html',
    'weight' => 61,
    'uuid' => 'b9aa0bc6-f662-49dd-a689-42a36d87cdf9',
    'language' => 'und',
    'i18n_tsid' => 0,
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
        'alias' => 'jewish-agency/aliyah-0',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Experience Israel',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 57,
    'uuid' => 'cf877392-f20a-4b1e-9159-0b6f0e9e74fd',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'jewish_agency',
    'field_color' => array(
      'und' => array(
        0 => array(
          'value' => 'turquoise',
          'format' => NULL,
          'safe_value' => 'turquoise',
        ),
      ),
    ),
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'jewish-agency/experience-israel',
        'language' => 'und',
      ),
    ),
  );
  return $terms;
}
