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
$field_program = render($content['field_program']);
if (isset($content['field_organizer'])) {
  if (isset($content['field_organizer_website']) && trim(render($content['field_organizer_website']))) {
    $field_program = l(render($content['field_organizer']), render($content['field_organizer_website']), array('html' => TRUE, 'attributes' => array('target' => '_blank')));
  } else {
    $field_program = render($content['field_organizer']);
  }
}
$field_featured_image = render($content['field_featured_image']);
?>
<li class="program-<?php print $node->nid; ?>">
<?php print $field_featured_image ? '<figure>' . l(render($content['field_featured_image']), $program_link, array('html' => true, 'attributes' => array('target' => $program_link_target))) . '</figure>' : ''; ?>
<div class="text">
  <?php print $field_program ? '<h6>' . $field_program . '</h6>' : ''; ?>
  <h3><?php print l(html_entity_decode($title, ENT_QUOTES), $program_link, array('attributes' => array('target' => $program_link_target))) . $masa_icon; ?></h3>
  <p><?php print strip_tags(render($content['field_short_description'], '<strong><b><i><u><span><ul><li>')); ?></p>
  <table class="programData">
    <tr>
      <td>
        <h6><?php print render($content['field_taxonomy_region']); ?></h6>
        <?php 
          if(isset($content['field_taxonomy_city'])) { print strtoupper(strip_tags(render($content['field_taxonomy_city'])) . ', '); }
          if(isset($content['field_taxonomy_country'])) { print strtoupper(strip_tags(render($content['field_taxonomy_country']))); } 
        ?>
      </td>
      <td>
        <?php if(isset($prices)) { print '<h6>$' . $prices . '</h6>'; }?>
        <?php 
          if(isset($cost_icons) && $cost_icons != NULL) {
            print t('INCLUDES !icons', array('!icons' => $cost_icons)); 
          }
        ?>
      </td>
    </tr>
    <?php if(isset($content['field_start_time']) OR isset($time_duration)) { ?>
    <tr>
      <td colspan="2">
        <h6><?php print isset($time_duration) ? $time_duration : time_elapsed_A($time); ?></h6>
        <?php 
          if(isset($content['field_start_time']) && $content['field_start_time']) {
            $date = format_date($content['field_start_time'], 'custom', 'M. j, Y');
            print t('STARTS @date', array('@date' => $date));
          }
          ?>
      </td>
    </tr>
      <?php } if(isset($content['languages'])) { ?>
        <tr>
          <td colspan="2">
            <h6><?php print join('&nbsp; | &nbsp;', $content['languages']); ?></h6>
          </td>
        </tr>
      <?php } if(isset($content['field_program_mailto']) || isset($content['field_program_phone']) || isset($content['field_program_phone_2']) || isset($content['field_program_website'])) { ?>
      <tr>
        <td colspan="2">
          <h6><?php print t('Contact'); ?></h6>
          <?php 
            if(isset($content['field_program_mailto'])) {
              print render($content['field_program_mailto']) . '&nbsp; | &nbsp;'; 
            } 
            if(isset($content['field_program_phone'])) {
              print render($content['field_program_phone']); 
            }
            if(isset($content['field_program_phone_2'])) {
              print render($content['field_program_phone_2']); 
            }
            if(isset($content['field_program_website'])) {
              print l(render($content['field_program_website']), render($content['field_program_website'])); 
            }
          ?>
          </td>
      </tr>
      <?php } ?>
  </table>
</div>
</li>