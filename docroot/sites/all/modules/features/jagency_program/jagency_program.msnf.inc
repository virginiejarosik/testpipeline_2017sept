<?php
/**
 * @file
 * jagency_program.msnf.inc
 */

/**
 * Implements hook_msnf_step_info().
 */
function jagency_program_msnf_step_info() {
  $export = array();

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_1|node|program_details';
  $msnf->step_name = 'step_1';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'program_details';
  $msnf->data = array(
    'label' => 'Step 1',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_experiances',
      2 => 'field_main_category',
      3 => 'field_program',
      4 => 'field_short_description',
      5 => 'field_view_mode',
      6 => 'field_logo_link',
      7 => 'field_title_experiances',
      8 => 'field_p2g_promotion',
      9 => 'field_program_tags',
      10 => 'field_title_experiences_link',
      11 => 'domain',
      12 => 'domain_path',
      13 => 'title',
      14 => 'additional_settings',
      15 => 'group_apply',
      16 => 'group_program',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'classes' => '',
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_1|node|program_details'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_2|node|program_details';
  $msnf->step_name = 'step_2';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'program_details';
  $msnf->data = array(
    'label' => 'Step 2',
    'weight' => '2',
    'children' => array(
      0 => 'field_age_group',
      1 => 'field_interest_keywords',
      2 => 'field_program_icons',
      3 => 'field_start_date',
      4 => 'field_total_cost',
      5 => 'field_what_do_you_want_to_do',
      6 => 'field_year',
      7 => 'field_duration_period',
      8 => 'field_duration_type',
      9 => 'field_language',
      10 => 'field_masa_recognition',
      11 => 'field_organizer',
      12 => 'field_organizer_website',
      13 => 'field_program_category',
      14 => 'field_program_mailto',
      15 => 'field_program_phone',
      16 => 'field_program_phone_2',
      17 => 'field_program_website',
      18 => 'field_start_date_2',
      19 => 'field_start_date_3',
      20 => 'field_start_date_4',
      21 => 'field_where_do_you_want_togo',
      22 => 'group_location',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'classes' => '',
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_2|node|program_details'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_5|node|program_details';
  $msnf->step_name = 'step_5';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'program_details';
  $msnf->data = array(
    'label' => 'Additional fields',
    'weight' => '4',
    'children' => array(
      0 => 'field_time_of_year',
      1 => 'field_type_of_program',
      2 => 'field_imported_program',
      3 => 'group_app_blocks',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Additional fields',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_5|node|program_details'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_more_about|node|program_details';
  $msnf->step_name = 'step_more_about';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'program_details';
  $msnf->data = array(
    'label' => 'More About',
    'weight' => '3',
    'children' => array(
      0 => 'field_more_about',
      1 => 'field_more_about_link',
      2 => 'field_more_about_title',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'classes' => '',
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_more_about|node|program_details'] = $msnf;

  return $export;
}
