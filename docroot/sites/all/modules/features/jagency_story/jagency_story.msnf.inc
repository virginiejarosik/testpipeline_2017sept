<?php
/**
 * @file
 * jagency_story.msnf.inc
 */

/**
 * Implements hook_msnf_step_info().
 */
function jagency_story_msnf_step_info() {
  $export = array();

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_part_1|node|storys';
  $msnf->step_name = 'step_part_1';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'storys';
  $msnf->data = array(
    'label' => 'Part 1',
    'weight' => '1',
    'children' => array(
      0 => 'field_category',
      1 => 'field_link',
      2 => 'field_main_image',
      3 => 'field_program',
      4 => 'field_program_description',
      5 => 'field_quote',
      6 => 'field_tags',
      7 => 'domain',
      8 => 'domain_path',
      9 => 'title',
      10 => 'additional_settings',
      11 => 'group_apply_button',
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
  $export['step_part_1|node|storys'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_part_2|node|storys';
  $msnf->step_name = 'step_part_2';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'storys';
  $msnf->data = array(
    'label' => 'Part 2',
    'weight' => '2',
    'children' => array(
      0 => 'field_featured_image',
      1 => 'field_gallery',
      2 => 'field_q_and_a',
      3 => 'field_photo_carousel',
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
  $export['step_part_2|node|storys'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_part_3|node|storys';
  $msnf->step_name = 'step_part_3';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'storys';
  $msnf->data = array(
    'label' => 'Part 3',
    'weight' => '3',
    'children' => array(
      0 => 'field_2_images',
      1 => 'field_part2_title',
      2 => 'field_part3_description',
      3 => 'field_more_participant_storys',
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
  $export['step_part_3|node|storys'] = $msnf;

  return $export;
}
