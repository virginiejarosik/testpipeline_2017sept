<?php

function jagency_preprocess_user_profile_block_first(&$vars) {
  $_user = $vars['elements'];
  
  $blog = field_view_field('user', $_user['#account'], 'field_blog', array('label'=>'hidden', 'type' => 'entityreference_entity_id'));
  $blog = isset($blog[0]['#markup']) ? $blog[0]['#markup'] : '';
  $vars['content']['name'] = field_view_field('user', $_user['#account'], 'field_profile_name', array('label'=>'hidden', 'type' => 'plaintext'));
  if ($blog) {
    $vars['content']['name'] = l('<strong>' . $vars['content']['name'][0]['#markup'] . '</strong>', 'blog/' . $blog . '/user/' . $_user['#account']->uid, array('html' => true));
    $vars['content']['link'] = 'blog/user/' . 'blog/' . $blog . '/user/' . $_user['#account']->uid;
  } else {
    $vars['content']['name'] = l('<strong>' . $vars['content']['name'][0]['#markup'] . '</strong>', 'blog/user/' . $_user['#account']->uid, array('html' => true));
    $vars['content']['link'] = 'blog/user/' . $_user['#account']->uid;
  }

  $vars['content']['bio'] = field_view_field('user', $_user['#account'], 'field_profile_short_bio', array('label'=>'hidden', 'type' => 'plaintext'));
  $vars['content']['bio'] = $vars['content']['bio'][0]['#markup'];

  $vars['content']['image'] = field_view_field('user', $_user['#account'], 'field_profile_image', array('label'=>'hidden'));
  $vars['content']['image'][0]['#image_style'] = 'authors_big_image';
  
  //$vars['image'] = $name[0]['#markup'];
}

function jagency_preprocess_user_profile_block(&$vars) {
  $_user = $vars['elements'];
  
  $vars['content']['name'] = field_view_field('user', $_user['#account'], 'field_profile_name', array('label'=>'hidden', 'type' => 'plaintext'));
  
  $vars['content']['bio'] = field_view_field('user', $_user['#account'], 'field_profile_short_bio', array('label'=>'hidden', 'type' => 'plaintext'));
  $vars['content']['bio'] = isset($vars['content']['bio'][0]) ? $vars['content']['bio'][0]['#markup'] : '';

  $vars['content']['image2'] = $vars['content']['image'] = field_view_field('user', $_user['#account'], 'field_profile_image', array('label'=>'hidden'));
  $vars['content']['image'][0]['#image_style'] = 'authors_small_image_bw';
  $vars['content']['image2'][0]['#image_style'] = 'authors_small_image';
  
  $blog = field_view_field('user', $_user['#account'], 'field_blog', array('label'=>'hidden', 'type' => 'entityreference_entity_id'));
  $blog = isset($blog[0]['#markup']) ? $blog[0]['#markup'] : '';
  if ($blog) {
    $vars['content']['name'] = l('<strong>' . $vars['content']['name'][0]['#markup'] . '</strong>', 'blog/' . $blog . '/user/' . $_user['#account']->uid, array('html' => true));
    $vars['content']['link'] = 'blog/' . $blog . '/user/' . $_user['#account']->uid;
  } else {
    $vars['content']['name'] = l('<strong>' . $vars['content']['name'][0]['#markup'] . '</strong>', 'blog/user/' . $_user['#account']->uid, array('html' => true));
    $vars['content']['link'] = 'blog/user/' . $_user['#account']->uid;
  }
  //$vars['image'] = $name[0]['#markup'];
}