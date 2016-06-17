<?php
/**
 * Implementation of hook_panels_layouts()
 */
 
// Plugin definition.
$plugin = array(
  'title' => t('Lobby with menu'),
  'category' => t('Jewish Agency'),
  'icon' => 'lobbymenu.png',
  'theme' => 'lobbymenu',
  'css' => 'lobbymenu.css',
  'regions' => array(
    'reg_1' => t('Region 1'),
    'reg_2' => t('Region 2'),
    'reg_3' => t('Region 3'),
    'reg_4' => t('Region 4'),
    'reg_5' => t('Region 5'),
    'reg_6' => t('Region 6'),
    'reg_7' => t('Region 7'),
    'reg_8' => t('Region 8'),
    'reg_9' => t('Region 9'),
    'reg_10' => t('Region 10'),
    'reg_11' => t('Region 11')
  ),
);
