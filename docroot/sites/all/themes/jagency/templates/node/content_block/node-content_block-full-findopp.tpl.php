<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
$settings = isset($node->field_content_block_settings[LANGUAGE_NONE]) ? unserialize($node->field_content_block_settings[LANGUAGE_NONE][0]['value']) : '';
if (!is_array($settings)) {
  print '<center><strong>Sorry there no settings for this block</strong></center>';
  return;
}
?>
<?php if (user_access('access administration pages')) : ?>
   <?php print l('Edit', 'node/' . $node->nid . '/edit', array('attributes' => array('class' => array('contextual-links-trigger', 'showme')))); ?>
<?php endif ;?>

<aside class="opportunityConfigWrapper opportunity <?php print $content['field_block_class']; ?>">
  <h4><?php print render($title); ?></h4>
  <form action="<?php print url('opportunities'); ?>" method="get"> 
    <div class="opportunityConfig">
      <?php
        //$view = views_get_view_('opportunities', 'page');
        $view = views_get_view('opportunities');
        $view->set_display('page');
        $view->init_handlers(); //initialize display handlers
        $form_state = array(
          'view' => $view,
          'display' => $view->display_handler->display,
          'exposed_form_plugin' => $view->display_handler->get_plugin('exposed_form'), //exposed form plugins are used in Views 3
          'method' => 'get',
          'rerender' => TRUE,
          'no_redirect' => TRUE,
        );
        $form = drupal_build_form('views_exposed_form', $form_state);
        unset($form['#info']['filter-keys']);
        unset($form['keys']);
        foreach ($form['#info'] as $key => $item) {
          if (!in_array(str_replace('filter-', '', $key), $settings)) {
            unset($form['#info'][$key]);
            unset($form[str_replace('filter-', '', $key)]);
          }
        }
        foreach ($form['#info'] as $key => $item) {
          if (isset($form[$item['value']]['#options'])) {
            foreach($form[$item['value']]['#options'] as $key => $value) {
              $form[$item['value']]['#options'][$key] = jagency_taxonomy_translate($key, $value);
            }
          }
        }
        print render($form);
      ?>
      <div class="opportunityFilter">
        <button type="submit"><?php print t('Submit'); ?></button>
      </div>
    </div>
  </form>
</aside>