<?php
/**
 * @file
 * jagency_pathauto.features.uuid_pathauto.inc
 */

/**
 * Implements hook_uuid_features_default_pathauto().
 */
function jagency_pathauto_uuid_features_default_pathauto() {
  $pathauto = array();
  $pathauto["pathauto_blog_pattern"] = 'blogs/[user:name]';
  $pathauto["pathauto_forum_pattern"] = '[term:vocabulary]/[term:name]';
  $pathauto["pathauto_node_blog_entry_pattern"] = 'blog/[node:field-blog:nid]/article/[node:nid]';
  $pathauto["pathauto_node_blog_pattern"] = 'blog/[node:nid]';
  $pathauto["pathauto_node_pattern"] = '[node:field_main_category]/content/[node:nid]';
  $pathauto["pathauto_node_program_details_pattern"] = '[node:field_main_category]/program/[node:nid]';
  $pathauto["pathauto_node_storys_pattern"] = '[node:field_category]/story/[node:nid]';
  $pathauto["pathauto_punctuation_hyphen"] = 1;
  $pathauto["pathauto_taxonomy_term_pattern"] = '[term:vocabulary]/[term:name]';
  $pathauto["pathauto_user_pattern"] = 'users/[user:uid]';
  return $pathauto;
}
