<?php
/**
 * @file
 * jagency_article.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function jagency_article_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Article',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '2e9a5236-7e4e-4b0a-8cb8-a293bb7d6e08',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'aticle_types',
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'aticle-types/article',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'News',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '48678da8-7b93-4228-8785-e6446b0699d4',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'aticle_types',
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'aticle-types/news',
        'language' => 'und',
      ),
    ),
  );
  return $terms;
}
