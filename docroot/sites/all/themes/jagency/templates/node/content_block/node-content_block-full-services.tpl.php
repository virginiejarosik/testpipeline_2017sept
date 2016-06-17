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
?>
<?php if (user_access('access administration pages')) : ?>
   <?php print l('Edit', 'node/' . $node->nid . '/edit', array('attributes' => array('class' => array('contextual-links-trigger', 'showme')))); ?>
<?php endif ;?>
<div class="aliyahServices <?php print $content['field_block_class']; ?>">
  <?php if (render($title)) : ?>
    <h<?php print $content['size']; ?>><?php print render($title); ?></h<?php print $content['size']; ?>>
  <?php endif ;?>
  <div class="fLeft fLeftWrapper">
    <h5><?php print t('For people moving from:'); ?></h5>
    <?php
      $terms = views_get_view_result('aliyah_services_location', 'entityreference_1');
      $items = array();
      foreach ($terms as $term) {
        if ($term->taxonomy_term_data_taxonomy_term_hierarchy_tid) {
          $items[$term->taxonomy_term_data_taxonomy_term_hierarchy_tid][] = $term;
        } else {
          $items[$term->tid]['term'] = $term;
        }
      }
      $options = array('<option value="">' . t('Please choose location') . '</option>');
      foreach ($items as $item) {
        $option = '';
        foreach ($item as $key => $child) {
          if (is_numeric($key)) {
            json_encode($option); 
            $option .= '<option value="' . jagency_taxonomy_translate($child->tid, $child->taxonomy_term_data_name) . '">' . jagency_taxonomy_translate($child->tid, $child->taxonomy_term_data_name) . '</option>';
            
          }
         
        }
       
        $options[] = '<optgroup label="' . jagency_taxonomy_translate($item['term']->tid, $item['term']->taxonomy_term_data_name) . '">' . t($option) . '</optgroup>';
         
          
      }
    ?>
    <select id="moving" name="moving">
      <?php print implode('', $options); ?>
    </select>
    <hr>
    <div class="contactsRep">
      <?php print t('Your local Aliyah manager:'); ?> &nbsp; <span id="aliyahservices_manager"><?php print t('loading...');?></span><br>
      <?php print t('The Global Service Center:'); ?> &nbsp; <span id="aliyahservices_center"><?php print t('loading...');?></span>
    </div>
  </div>
  <table class="col480 fRight">
      <tbody><tr>
        <th colspan="3"><?php print t('More information'); ?></th>
      </tr>
      <tr>
        <td>
        <?php print render($content['field_block_content']['value']); ?>
        </td>
      </tr>
    </tbody></table>
</div>
