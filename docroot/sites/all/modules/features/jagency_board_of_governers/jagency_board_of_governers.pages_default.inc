<?php
/**
 * @file
 * jagency_board_of_governers.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function jagency_board_of_governers_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'bog_members';
  $page->task = 'page';
  $page->admin_title = 'BOG Members';
  $page->admin_description = '';
  $page->path = 'board-of-governors-members';
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
  $handler->name = 'page_bog_members_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'bog_members';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'bog_members',
    'css' => '#bog_members{
margin-bottom: 20px;
width: 980px;
margin: auto;
-moz-box-sizing: border-box;
-webkit-box-sizing: border-box;
box-sizing: border-box;
clear: both;
}
#bog_members .panels-flexible-region-first {
margin-left: 0px !important;
}
#bog_members .panels-flexible-region {
margin: 0 20px;
width: 210px;
}
#bog_members h5{
padding-top: 0px !important;
margin-top: 0px !important;
margin-bottom: 15px 1important;
}',
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
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'wrapper',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '1',
          1 => '2',
          2 => '3',
          3 => '4',
        ),
        'parent' => 'main',
        'class' => 'wrapper',
      ),
      1 => array(
        'type' => 'region',
        'title' => '1',
        'width' => '25.512702785430058',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      2 => array(
        'type' => 'region',
        'title' => '2',
        'width' => '49.48729721456994',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      3 => array(
        'type' => 'region',
        'title' => '3',
        'width' => 12.5,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      4 => array(
        'type' => 'region',
        'title' => '4',
        'width' => 12.5,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      1 => NULL,
      2 => NULL,
      3 => NULL,
      4 => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '  Members of the Jewish Agency Board of Governors';
  $display->uuid = '8c8a9827-0235-4a8f-bde5-304863a1c069';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-61cf6fb9-0209-43be-9b0a-da7f94f00580';
    $pane->panel = '1';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'bog_members_1_column',
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
    $pane->uuid = '61cf6fb9-0209-43be-9b0a-da7f94f00580';
    $display->content['new-61cf6fb9-0209-43be-9b0a-da7f94f00580'] = $pane;
    $display->panels['1'][0] = 'new-61cf6fb9-0209-43be-9b0a-da7f94f00580';
    $pane = new stdClass();
    $pane->pid = 'new-a2b14d3d-65e2-49cc-a280-442bc851a6e8';
    $pane->panel = '2';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'bog_members_2_column',
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
    $pane->uuid = 'a2b14d3d-65e2-49cc-a280-442bc851a6e8';
    $display->content['new-a2b14d3d-65e2-49cc-a280-442bc851a6e8'] = $pane;
    $display->panels['2'][0] = 'new-a2b14d3d-65e2-49cc-a280-442bc851a6e8';
    $pane = new stdClass();
    $pane->pid = 'new-c881f4ff-36d1-4622-8419-1cdfcfb37c5e';
    $pane->panel = '3';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'bog_members_3_column',
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
    $pane->uuid = 'c881f4ff-36d1-4622-8419-1cdfcfb37c5e';
    $display->content['new-c881f4ff-36d1-4622-8419-1cdfcfb37c5e'] = $pane;
    $display->panels['3'][0] = 'new-c881f4ff-36d1-4622-8419-1cdfcfb37c5e';
    $pane = new stdClass();
    $pane->pid = 'new-0f8faa17-5b2b-4541-866e-921fd1ec9472';
    $pane->panel = '4';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'bog_members_4_column',
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
    $pane->uuid = '0f8faa17-5b2b-4541-866e-921fd1ec9472';
    $display->content['new-0f8faa17-5b2b-4541-866e-921fd1ec9472'] = $pane;
    $display->panels['4'][0] = 'new-0f8faa17-5b2b-4541-866e-921fd1ec9472';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['bog_members'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'executive_members';
  $page->task = 'page';
  $page->admin_title = 'Board of governors';
  $page->admin_description = '';
  $page->path = 'board-of-governors';
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
  $handler->name = 'page_executive_members_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'executive_members';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Executive Members',
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
        'class' => 'wrapper',
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
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col730 fRight',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'fLeft col230',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'inside_the_jewish_agency' => NULL,
      'left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Executive Members';
  $display->uuid = 'aebf7fa2-19a1-4b92-a5ed-b9783fb8d1dd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2db29480-0f19-4c54-a9df-5d79744cb66a';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'inside_the_jewish_agency';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
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
    $pane->uuid = '2db29480-0f19-4c54-a9df-5d79744cb66a';
    $display->content['new-2db29480-0f19-4c54-a9df-5d79744cb66a'] = $pane;
    $display->panels['center'][0] = 'new-2db29480-0f19-4c54-a9df-5d79744cb66a';
    $pane = new stdClass();
    $pane->pid = 'new-5127009d-6477-47c7-b7c2-247175e92918';
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
    $pane->uuid = '5127009d-6477-47c7-b7c2-247175e92918';
    $display->content['new-5127009d-6477-47c7-b7c2-247175e92918'] = $pane;
    $display->panels['left'][0] = 'new-5127009d-6477-47c7-b7c2-247175e92918';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['executive_members'] = $page;

  return $pages;

}
