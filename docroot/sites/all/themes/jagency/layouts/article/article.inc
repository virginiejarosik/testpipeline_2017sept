<?php
/**
 * Implementation of hook_panels_layouts()
 */
 
// Plugin definition.
$plugin = array(
  'title' => t('Article'),
  'category' => t('Jewish Agency'),
  'icon' => 'article.png',
  'theme' => 'article',
  'css' => 'article.css',
  'regions' => array(
    'reg_1' => t('Region 1'),
    'reg_2' => t('Region 2'),
    'reg_3' => t('Region 3'),
    'reg_4' => t('Region 4'),
    'reg_5' => t('Region 5'),
    'reg_6' => t('Region 6')
  ),
);
