<?php
/**
 * @file
 * jagency_lobby.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function jagency_lobby_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'aliyah';
  $page->task = 'page';
  $page->admin_title = 'Aliyah';
  $page->admin_description = '';
  $page->path = 'aliyah';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_aliyah_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'aliyah';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'experience_israel_main',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => 'intro wrapper',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col730',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'wrapper',
        ),
        'parent' => 'main',
        'class' => 'grey',
      ),
      'wrapper' => array(
        'type' => 'region',
        'title' => 'Wrapper',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'wrapper',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'wrapper' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Aliyah';
  $display->uuid = '4eaffe71-952e-44e1-8ed7-01ec151991ea';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-746084dd-3c05-4f01-9b5d-1a682e040fe0';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'aliyah_top_image_wide',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '746084dd-3c05-4f01-9b5d-1a682e040fe0';
    $display->content['new-746084dd-3c05-4f01-9b5d-1a682e040fe0'] = $pane;
    $display->panels['center'][0] = 'new-746084dd-3c05-4f01-9b5d-1a682e040fe0';
    $pane = new stdClass();
    $pane->pid = 'new-493b6258-19c9-46de-8e13-d277ee2491b6';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'aliyah_content',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '493b6258-19c9-46de-8e13-d277ee2491b6';
    $display->content['new-493b6258-19c9-46de-8e13-d277ee2491b6'] = $pane;
    $display->panels['left'][0] = 'new-493b6258-19c9-46de-8e13-d277ee2491b6';
    $pane = new stdClass();
    $pane->pid = 'new-7b1b85bb-13ae-4e5b-a43e-1b25bc043495';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'find_an_oportunity_aliyah',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7b1b85bb-13ae-4e5b-a43e-1b25bc043495';
    $display->content['new-7b1b85bb-13ae-4e5b-a43e-1b25bc043495'] = $pane;
    $display->panels['right'][0] = 'new-7b1b85bb-13ae-4e5b-a43e-1b25bc043495';
    $pane = new stdClass();
    $pane->pid = 'new-f7a0d55e-ac8c-470e-9bbd-5ae292300538';
    $pane->panel = 'wrapper';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'aliyah_services',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f7a0d55e-ac8c-470e-9bbd-5ae292300538';
    $display->content['new-f7a0d55e-ac8c-470e-9bbd-5ae292300538'] = $pane;
    $display->panels['wrapper'][0] = 'new-f7a0d55e-ac8c-470e-9bbd-5ae292300538';
    $pane = new stdClass();
    $pane->pid = 'new-771330e9-7bab-433d-9f0b-1199540d4043';
    $pane->panel = 'wrapper';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'aliyah_programs',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '771330e9-7bab-433d-9f0b-1199540d4043';
    $display->content['new-771330e9-7bab-433d-9f0b-1199540d4043'] = $pane;
    $display->panels['wrapper'][1] = 'new-771330e9-7bab-433d-9f0b-1199540d4043';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['aliyah'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'experience_israel';
  $page->task = 'page';
  $page->admin_title = 'Experience Israel';
  $page->admin_description = '';
  $page->path = 'experience-israel';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_experience_israel_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'experience_israel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'experience_israel_main',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => 'intro wrapper',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col730',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'wrapper',
        ),
        'parent' => 'main',
        'class' => 'grey',
      ),
      'wrapper' => array(
        'type' => 'region',
        'title' => 'Wrapper',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'wrapper',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'wrapper' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Experience Israel';
  $display->uuid = '483d1458-3a8b-4499-a6bc-4bf95e0fe87b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-79757307-98b4-4c43-98fe-f005842da627';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'experience_israel_top_image_wide',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '79757307-98b4-4c43-98fe-f005842da627';
    $display->content['new-79757307-98b4-4c43-98fe-f005842da627'] = $pane;
    $display->panels['center'][0] = 'new-79757307-98b4-4c43-98fe-f005842da627';
    $pane = new stdClass();
    $pane->pid = 'new-bf77fd5f-ac12-4d0b-a13a-ab87b8a77128';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'experience_israel_text',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bf77fd5f-ac12-4d0b-a13a-ab87b8a77128';
    $display->content['new-bf77fd5f-ac12-4d0b-a13a-ab87b8a77128'] = $pane;
    $display->panels['left'][0] = 'new-bf77fd5f-ac12-4d0b-a13a-ab87b8a77128';
    $pane = new stdClass();
    $pane->pid = 'new-2d61f451-6301-4e6c-8ea6-31a79aca2a31';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'experience_israel_find_an_oportunity_search',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2d61f451-6301-4e6c-8ea6-31a79aca2a31';
    $display->content['new-2d61f451-6301-4e6c-8ea6-31a79aca2a31'] = $pane;
    $display->panels['right'][0] = 'new-2d61f451-6301-4e6c-8ea6-31a79aca2a31';
    $pane = new stdClass();
    $pane->pid = 'new-c0aa039b-78d8-41ed-a5e1-7cf32961bde5';
    $pane->panel = 'wrapper';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'experience_israel_programs',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c0aa039b-78d8-41ed-a5e1-7cf32961bde5';
    $display->content['new-c0aa039b-78d8-41ed-a5e1-7cf32961bde5'] = $pane;
    $display->panels['wrapper'][0] = 'new-c0aa039b-78d8-41ed-a5e1-7cf32961bde5';
    $pane = new stdClass();
    $pane->pid = 'new-ef966fda-df84-4a35-9d9f-35b2872f5cbf';
    $pane->panel = 'wrapper';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'experience_israel_find_opportunities_by_life_stage',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ef966fda-df84-4a35-9d9f-35b2872f5cbf';
    $display->content['new-ef966fda-df84-4a35-9d9f-35b2872f5cbf'] = $pane;
    $display->panels['wrapper'][1] = 'new-ef966fda-df84-4a35-9d9f-35b2872f5cbf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['experience_israel'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'inside_the_jewish_agency';
  $page->task = 'page';
  $page->admin_title = 'Inside The Jewish Agency';
  $page->admin_description = '';
  $page->path = 'insideja';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_inside_the_jewish_agency_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'inside_the_jewish_agency';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'experience_israel_main',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => 'intro wrapper',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'fLeft col230',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col730 fRight',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'wrapper',
        ),
        'parent' => 'main',
        'class' => 'grey',
      ),
      'wrapper' => array(
        'type' => 'region',
        'title' => 'Wrapper',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'wrapper',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'wrapper' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Inside The Jewish Agency';
  $display->uuid = '6f330ec8-fff1-4a35-bfac-1541e64f2e49';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bbe2951f-7801-4340-9453-0321236614c7';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'jagency_pages-jagency_menu_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bbe2951f-7801-4340-9453-0321236614c7';
    $display->content['new-bbe2951f-7801-4340-9453-0321236614c7'] = $pane;
    $display->panels['left'][0] = 'new-bbe2951f-7801-4340-9453-0321236614c7';
    $pane = new stdClass();
    $pane->pid = 'new-8cf3492c-b295-49c4-af6a-69ac7745635d';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'insideja_top',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8cf3492c-b295-49c4-af6a-69ac7745635d';
    $display->content['new-8cf3492c-b295-49c4-af6a-69ac7745635d'] = $pane;
    $display->panels['right'][0] = 'new-8cf3492c-b295-49c4-af6a-69ac7745635d';
    $pane = new stdClass();
    $pane->pid = 'new-35aa2c9e-58ac-4d46-8f9f-016f0c084a34';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'insideja_boxes',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '35aa2c9e-58ac-4d46-8f9f-016f0c084a34';
    $display->content['new-35aa2c9e-58ac-4d46-8f9f-016f0c084a34'] = $pane;
    $display->panels['right'][1] = 'new-35aa2c9e-58ac-4d46-8f9f-016f0c084a34';
    $pane = new stdClass();
    $pane->pid = 'new-d51431f9-392f-4f00-b37b-db0594bc78a6';
    $pane->panel = 'wrapper';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'insideja_programs',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd51431f9-392f-4f00-b37b-db0594bc78a6';
    $display->content['new-d51431f9-392f-4f00-b37b-db0594bc78a6'] = $pane;
    $display->panels['wrapper'][0] = 'new-d51431f9-392f-4f00-b37b-db0594bc78a6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['inside_the_jewish_agency'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'israel_in_your_community';
  $page->task = 'page';
  $page->admin_title = 'Israel In Your Community';
  $page->admin_description = '';
  $page->path = 'israel-in-your-community';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_israel_in_your_community_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'israel_in_your_community';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'experience_israel_main',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => 'intro wrapper',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col730',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'wrapper',
        ),
        'parent' => 'main',
        'class' => 'grey',
      ),
      'wrapper' => array(
        'type' => 'region',
        'title' => 'Wrapper',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'wrapper',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'wrapper' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Israel In Your Community';
  $display->uuid = '9f7cc47b-17c1-4673-b387-69d7b551a02e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ffe1805a-1603-4377-b728-5c225efbf3a6';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'israel_community_top_image_wide',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ffe1805a-1603-4377-b728-5c225efbf3a6';
    $display->content['new-ffe1805a-1603-4377-b728-5c225efbf3a6'] = $pane;
    $display->panels['center'][0] = 'new-ffe1805a-1603-4377-b728-5c225efbf3a6';
    $pane = new stdClass();
    $pane->pid = 'new-d0e56af7-aac3-4b4a-8e24-124d1a284255';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'israel_community_israel_text',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd0e56af7-aac3-4b4a-8e24-124d1a284255';
    $display->content['new-d0e56af7-aac3-4b4a-8e24-124d1a284255'] = $pane;
    $display->panels['left'][0] = 'new-d0e56af7-aac3-4b4a-8e24-124d1a284255';
    $pane = new stdClass();
    $pane->pid = 'new-ac7a3cab-4777-4683-a9e9-0274bdf1a4ed';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'israel_community_oportunity_search',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ac7a3cab-4777-4683-a9e9-0274bdf1a4ed';
    $display->content['new-ac7a3cab-4777-4683-a9e9-0274bdf1a4ed'] = $pane;
    $display->panels['right'][0] = 'new-ac7a3cab-4777-4683-a9e9-0274bdf1a4ed';
    $pane = new stdClass();
    $pane->pid = 'new-e5707b5a-5cd2-4bce-9af5-d5f72d8d741a';
    $pane->panel = 'wrapper';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'israel_community_programs',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e5707b5a-5cd2-4bce-9af5-d5f72d8d741a';
    $display->content['new-e5707b5a-5cd2-4bce-9af5-d5f72d8d741a'] = $pane;
    $display->panels['wrapper'][0] = 'new-e5707b5a-5cd2-4bce-9af5-d5f72d8d741a';
    $pane = new stdClass();
    $pane->pid = 'new-eebec35f-d375-4c80-8cdd-b82d092d48a3';
    $pane->panel = 'wrapper';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'israel_community_find_opportunities_by_life_stage',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'eebec35f-d375-4c80-8cdd-b82d092d48a3';
    $display->content['new-eebec35f-d375-4c80-8cdd-b82d092d48a3'] = $pane;
    $display->panels['wrapper'][1] = 'new-eebec35f-d375-4c80-8cdd-b82d092d48a3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['israel_in_your_community'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'jewish_social_action';
  $page->task = 'page';
  $page->admin_title = 'Jewish Social Action';
  $page->admin_description = '';
  $page->path = 'jewish-social-action';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_jewish_social_action_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'jewish_social_action';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'experience_israel_main',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => 'intro wrapper',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col730',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'wrapper',
        ),
        'parent' => 'main',
        'class' => 'grey',
      ),
      'wrapper' => array(
        'type' => 'region',
        'title' => 'Wrapper',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'wrapper',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'wrapper' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Jewish Social Action';
  $display->uuid = '667101a5-968d-4cd7-81b9-7888670009ae';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1c8b208d-ffc5-43b9-a8d7-8fab1a13a53d';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'jewish_social_top_image_wide',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1c8b208d-ffc5-43b9-a8d7-8fab1a13a53d';
    $display->content['new-1c8b208d-ffc5-43b9-a8d7-8fab1a13a53d'] = $pane;
    $display->panels['center'][0] = 'new-1c8b208d-ffc5-43b9-a8d7-8fab1a13a53d';
    $pane = new stdClass();
    $pane->pid = 'new-39e826a5-40c9-4247-8d43-5b71f0428162';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'jewish_social_action_content',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '39e826a5-40c9-4247-8d43-5b71f0428162';
    $display->content['new-39e826a5-40c9-4247-8d43-5b71f0428162'] = $pane;
    $display->panels['left'][0] = 'new-39e826a5-40c9-4247-8d43-5b71f0428162';
    $pane = new stdClass();
    $pane->pid = 'new-9f64319f-7580-4ac3-8e73-35a71db96cc6';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'jewish_social_find_an_oportunity',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9f64319f-7580-4ac3-8e73-35a71db96cc6';
    $display->content['new-9f64319f-7580-4ac3-8e73-35a71db96cc6'] = $pane;
    $display->panels['right'][0] = 'new-9f64319f-7580-4ac3-8e73-35a71db96cc6';
    $pane = new stdClass();
    $pane->pid = 'new-d403a1dc-4772-48aa-9f28-64cd9059ddcc';
    $pane->panel = 'wrapper';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'jewish_social_action_programs',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd403a1dc-4772-48aa-9f28-64cd9059ddcc';
    $display->content['new-d403a1dc-4772-48aa-9f28-64cd9059ddcc'] = $pane;
    $display->panels['wrapper'][0] = 'new-d403a1dc-4772-48aa-9f28-64cd9059ddcc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['jewish_social_action'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'leadership_board';
  $page->task = 'page';
  $page->admin_title = 'Leadership & Board';
  $page->admin_description = '';
  $page->path = 'leadership';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_leadership_board_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'leadership_board';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'experience_israel_main',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
          3 => 3,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => 'intro wrapper',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'fLeft col230',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col730 fRight',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'wrapper',
        ),
        'parent' => 'main',
        'class' => 'wrapper',
      ),
      'wrapper' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'wrapper',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
        ),
        'parent' => 'main',
        'class' => 'grey borderd',
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Center Wrapper',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => 'wrapper',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'wrapper' => NULL,
      'center_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Leadership, Board & Staff';
  $display->uuid = 'ce86e8dc-5046-4139-9c14-f9e60af8088d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7a089d1e-3ea0-4cb7-bc0c-224688c6ac07';
    $pane->panel = 'center_';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'leadership_programs',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col730 fLeft',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7a089d1e-3ea0-4cb7-bc0c-224688c6ac07';
    $display->content['new-7a089d1e-3ea0-4cb7-bc0c-224688c6ac07'] = $pane;
    $display->panels['center_'][0] = 'new-7a089d1e-3ea0-4cb7-bc0c-224688c6ac07';
    $pane = new stdClass();
    $pane->pid = 'new-5cddc727-2f28-4b2e-a822-cc019520b6a7';
    $pane->panel = 'center_';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'leadership_events',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'aside',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5cddc727-2f28-4b2e-a822-cc019520b6a7';
    $display->content['new-5cddc727-2f28-4b2e-a822-cc019520b6a7'] = $pane;
    $display->panels['center_'][1] = 'new-5cddc727-2f28-4b2e-a822-cc019520b6a7';
    $pane = new stdClass();
    $pane->pid = 'new-751f99c7-9622-4624-963b-a0493775ce78';
    $pane->panel = 'center_';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'leadership_resources',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'memberResources',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '751f99c7-9622-4624-963b-a0493775ce78';
    $display->content['new-751f99c7-9622-4624-963b-a0493775ce78'] = $pane;
    $display->panels['center_'][2] = 'new-751f99c7-9622-4624-963b-a0493775ce78';
    $pane = new stdClass();
    $pane->pid = 'new-716e1c5b-7be9-4192-9e48-caa488340ceb';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'jagency_pages-jagency_menu_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '716e1c5b-7be9-4192-9e48-caa488340ceb';
    $display->content['new-716e1c5b-7be9-4192-9e48-caa488340ceb'] = $pane;
    $display->panels['left'][0] = 'new-716e1c5b-7be9-4192-9e48-caa488340ceb';
    $pane = new stdClass();
    $pane->pid = 'new-e90662fa-0fc4-49e8-8497-86d7ec3f4be7';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'leadership_top',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e90662fa-0fc4-49e8-8497-86d7ec3f4be7';
    $display->content['new-e90662fa-0fc4-49e8-8497-86d7ec3f4be7'] = $pane;
    $display->panels['right'][0] = 'new-e90662fa-0fc4-49e8-8497-86d7ec3f4be7';
    $pane = new stdClass();
    $pane->pid = 'new-67052b7f-afac-4399-8c2f-46c93741a056';
    $pane->panel = 'wrapper';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'leadership_board',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '67052b7f-afac-4399-8c2f-46c93741a056';
    $display->content['new-67052b7f-afac-4399-8c2f-46c93741a056'] = $pane;
    $display->panels['wrapper'][0] = 'new-67052b7f-afac-4399-8c2f-46c93741a056';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['leadership_board'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'partnership_2_gether';
  $page->task = 'page';
  $page->admin_title = 'Partnership 2 Gether';
  $page->admin_description = '';
  $page->path = 'partnership2gether';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_partnership_2_gether_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'partnership_2_gether';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => '',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => TRUE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
        'class' => 'wrapper',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
        ),
        'parent' => 'main',
        'class' => 'wrapper',
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center__',
        ),
        'parent' => 'main',
        'class' => 'grey',
      ),
      'center__' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'wrapper',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'center_' => NULL,
      'center__' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Partnership2Gether';
  $display->uuid = '5f84b8d2-0ed5-4a53-bfb2-f6a39c52df3c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-702cc160-fee2-4eaa-8b3a-c07db8a652ef';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'p2gBannerIntro',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '702cc160-fee2-4eaa-8b3a-c07db8a652ef';
    $display->content['new-702cc160-fee2-4eaa-8b3a-c07db8a652ef'] = $pane;
    $display->panels['center'][0] = 'new-702cc160-fee2-4eaa-8b3a-c07db8a652ef';
    $pane = new stdClass();
    $pane->pid = 'new-6b626b01-adb5-434d-949b-fe9119cc9fb7';
    $pane->panel = 'center_';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'partnership2gether_programs',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6b626b01-adb5-434d-949b-fe9119cc9fb7';
    $display->content['new-6b626b01-adb5-434d-949b-fe9119cc9fb7'] = $pane;
    $display->panels['center_'][0] = 'new-6b626b01-adb5-434d-949b-fe9119cc9fb7';
    $pane = new stdClass();
    $pane->pid = 'new-0a1e3519-5a16-47db-a88f-80a6e3fb0e14';
    $pane->panel = 'center__';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'partnership2gether_regions',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0a1e3519-5a16-47db-a88f-80a6e3fb0e14';
    $display->content['new-0a1e3519-5a16-47db-a88f-80a6e3fb0e14'] = $pane;
    $display->panels['center__'][0] = 'new-0a1e3519-5a16-47db-a88f-80a6e3fb0e14';
    $pane = new stdClass();
    $pane->pid = 'new-f5d3675f-f463-4c47-a8de-b416bccb9a43';
    $pane->panel = 'center__';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'partnership2gether_newsevents',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'aside',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f5d3675f-f463-4c47-a8de-b416bccb9a43';
    $display->content['new-f5d3675f-f463-4c47-a8de-b416bccb9a43'] = $pane;
    $display->panels['center__'][1] = 'new-f5d3675f-f463-4c47-a8de-b416bccb9a43';
    $pane = new stdClass();
    $pane->pid = 'new-9be716a0-e7b4-441a-bd30-bb7f7790d60e';
    $pane->panel = 'center__';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'partnership2gether_moreabout',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col730',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9be716a0-e7b4-441a-bd30-bb7f7790d60e';
    $display->content['new-9be716a0-e7b4-441a-bd30-bb7f7790d60e'] = $pane;
    $display->panels['center__'][2] = 'new-9be716a0-e7b4-441a-bd30-bb7f7790d60e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['partnership_2_gether'] = $page;

  return $pages;

}
