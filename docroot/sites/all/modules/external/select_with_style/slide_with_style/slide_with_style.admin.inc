<?php

/**
 * @file
 * slide_with_style.admin.inc
 *
 * Configuration options for Slide with Style module.
 */

/**
 * Menu callback for admin configuration settings.
 */
function slide_with_style_admin_configure() {
  $path = drupal_get_path('module', 'slide_with_style') . '/css';
  $form['slide_with_style_css_directory'] = array(
    '#type' => 'textfield',
    '#title' => t('Directory containing CSS styling files for sliders'),
    '#default_value' => variable_get('slide_with_style_css_directory', $path),
    '#description' => t('')
  );
  return system_settings_form($form);
}