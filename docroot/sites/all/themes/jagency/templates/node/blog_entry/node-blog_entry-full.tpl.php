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
<div class="wrapper">
<?php
if ($content['images']) {
  print '<ul id="articleGallery" class="articleGallery">' . $content['images'] . '</ul>';
}
?>
<div class="blogArticle col730">
  <?php print l($category->name, 'blog/' . $content['blog_reference'][0]['#markup'] .'/category/' . $category->tid, array('attributes' => array('class' => array('blogArticleLink', 'blogArticleLink_' . $color)))); ?>
  <h4><?php print render($node->title); ?></h4>
  <p class="intro"><?php print strip_tags(render($content['field_sub_title']),'<strong><b><i><u><span><ul><li>'); ?></p>
  <article>
    <div>
    <?php
      print $content['body']; 
    ?>
    </div>
  </article>
  
  <div class="blogArticleFooter">
      <span class="footnote">
          <span><?php print format_date($node->created, 'blog'); ?> / <?php print convert_jew_date($node->created); ?></span>
          <?php print theme('image', array('path' => path_to_theme() . '/images/blogFooterComment.png')); ?>
          <strong class="fb-comments-count" data-href="<?php print url( 'node/' . $node->nid, array('absolute' => true)); ?>">0</strong>
      </span>
      <?php //print render($content['links']); ?>
      <ul>
          <li><div class="fb-like" data-send="false" data-layout="button_count" data-show-faces="false"></div></li>
          <li class="share-blog-text"><span><?php print t('Share'); ?></span></li>
          <li><?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterFacebook.png')), 'http://www.facebook.com/sharer.php?u=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?></li>
          <li><?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterTwitter.png')), 'https://twitter.com/intent/tweet?text=' . rawurlencode(render($node->title)) . '&url=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?></li>
          <li><?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterGoogle.png')), 'https://plusone.google.com/_/+1/confirm?url=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))) .'&title=' . rawurlencode(render($node->title)), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?></li>
          <li><span>&nbsp;&nbsp;<?php print t('Print'); ?>&nbsp;&nbsp;</span>
          <?php
            if (isset($content['links']['print_html'])) {
              print l(theme('image', array('path' => path_to_theme() . '/images/printIcon.png')), $content['links']['print_html']['#links']['print_html']['href'], array('attributes' => array('class' => 'print-icon', 'target' => '_new'), "html" => TRUE));
            } else {
              print l(theme('image', array('path' => path_to_theme() . '/images/printIcon.png')), 'print/' . $node->nid, array('attributes' => array('class' => 'print-icon', 'target' => '_new'), "html" => TRUE));
            }
          ?>
          </li>
      </ul>
  </div>
  <?php
    module_load_include('module', 'jagency_users');
    print jagency_authors_custom_user_block($node->uid);
  ?>
</div>
<?php
  if ($node->comment == 2) : 
  ?>
  <section class="facebookComments">
    <a id="facebook-comments"></a>
    <fb:comments href="<?php print url( 'node/' . $node->nid, array('absolute' => true)); ?>"  num_posts="10"  width="100%"  colorscheme="light" ></fb:comments>
  </section>
<?php endif; ?>
</div>