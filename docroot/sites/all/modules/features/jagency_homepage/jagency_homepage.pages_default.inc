<?php
/**
 * @file
 * jagency_homepage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function jagency_homepage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = '';
  $page->path = 'home';
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
  $handler->name = 'page_homepage_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
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
        'class' => 'hompage-content',
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
          0 => 'left',
          1 => 'center',
        ),
        'parent' => 'main',
        'class' => 'intro wrapper',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'opportunity',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col730',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => 'grey',
      ),
      'left_' => array(
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
        'class' => 'wrapper aside-wrapper picList',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'bottom_homepage',
        ),
        'parent' => 'main',
        'class' => 'wrapper',
      ),
      'bottom_homepage' => array(
        'type' => 'region',
        'title' => 'Bottom Homepage',
        'width' => 100,
        'width_type' => 'px',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'left_' => NULL,
      'right' => NULL,
      'bottom_homepage' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0a1a8688-360b-47a7-b557-9a9dc040ba51';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7a1bcb03-ee15-458f-974f-7ab77be5931c';
    $pane->panel = 'bottom_homepage';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'homepage_bottom',
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
    $pane->uuid = '7a1bcb03-ee15-458f-974f-7ab77be5931c';
    $display->content['new-7a1bcb03-ee15-458f-974f-7ab77be5931c'] = $pane;
    $display->panels['bottom_homepage'][0] = 'new-7a1bcb03-ee15-458f-974f-7ab77be5931c';
    $pane = new stdClass();
    $pane->pid = 'new-a4ad77e4-efce-4609-b258-813516d042d6';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'homepage_opportunity',
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
    $pane->uuid = 'a4ad77e4-efce-4609-b258-813516d042d6';
    $display->content['new-a4ad77e4-efce-4609-b258-813516d042d6'] = $pane;
    $display->panels['center'][0] = 'new-a4ad77e4-efce-4609-b258-813516d042d6';
    $pane = new stdClass();
    $pane->pid = 'new-1980c76b-4af5-437c-a13b-4b8295e95651';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'about_homepage',
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
    $pane->uuid = '1980c76b-4af5-437c-a13b-4b8295e95651';
    $display->content['new-1980c76b-4af5-437c-a13b-4b8295e95651'] = $pane;
    $display->panels['left'][0] = 'new-1980c76b-4af5-437c-a13b-4b8295e95651';
    $pane = new stdClass();
    $pane->pid = 'new-a14ae79f-530c-4e48-9435-265d342e20e3';
    $pane->panel = 'left_';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'homepage_news_events_left',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a14ae79f-530c-4e48-9435-265d342e20e3';
    $display->content['new-a14ae79f-530c-4e48-9435-265d342e20e3'] = $pane;
    $display->panels['left_'][0] = 'new-a14ae79f-530c-4e48-9435-265d342e20e3';
    $pane = new stdClass();
    $pane->pid = 'new-a530de05-5832-4cbc-87cf-faa437f12c80';
    $pane->panel = 'left_';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'homepage_from_the_field_left',
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
    $pane->uuid = 'a530de05-5832-4cbc-87cf-faa437f12c80';
    $display->content['new-a530de05-5832-4cbc-87cf-faa437f12c80'] = $pane;
    $display->panels['left_'][1] = 'new-a530de05-5832-4cbc-87cf-faa437f12c80';
    $pane = new stdClass();
    $pane->pid = 'new-0d703def-7a91-494e-97f9-ae9efa6b7fe5';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_block_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_block_id_value' => 'homepage_news_events_right',
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
    $pane->uuid = '0d703def-7a91-494e-97f9-ae9efa6b7fe5';
    $display->content['new-0d703def-7a91-494e-97f9-ae9efa6b7fe5'] = $pane;
    $display->panels['right'][0] = 'new-0d703def-7a91-494e-97f9-ae9efa6b7fe5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  return $pages;

}
