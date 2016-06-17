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
<div>
  <div class="fRight">
    <div class="picIntro">
      <figure>
        <?php if (isset($content['field_main_image_video'])) : ?>
          <div class="play playBtn" data-size="730x548" data-href="<?php print $content['field_main_image_video']; ?>"></div>
        <?php endif; ?>
        <?php print render($content['field_main_image']); ?>
        <?php print $content['field_copyright']; ?>
      </figure>
      <?php if(isset($content['field_image_description'])) { ?> <figcaption class="s11"> <?php print render($content['field_image_description']); ?> </figcaption> <?php } ?>
    </div>
    <!--/picIntro -->
    <p>
      <?php
        if (isset($content['field_source_link'])) {
          print l(render($content['field_source_image']), render($content['field_source_link']), array('html' => true));
        } else {
          print render($content['field_source_image']);
        }
      ?>
    </p>
  </div>
  <!--/col730 fRight -->
  <!--/clearOpposite -->
  <div class="jaArticle Sul">
    <?php if(isset($content['field_sub_title'])) { ?><h2><?php print render($content['field_sub_title']); ?></h2> <?php } ?>
    <?php if(isset($content['field_short_description'])) { ?><h3 class="subTitle"><?php print render($content['field_short_description']); ?></h3><?php } ?>
    <?php print render($content['field_description']); ?>
    <p>&nbsp;</p>
    <p>
    <?php
      if(isset($content['field_contact_us_for_more_link'])) {
        print l(t('Read more on @title',array('@title' => $title)), strip_tags(render($content['field_contact_us_for_more_link'])));
      }
    ?>
    
    <?php 
      if(isset($content['field_program_mailto'])) {
        print '<p>' . l(t('Contact us for more information'), '', 
                        array('html' => true, 
                              'attributes' => array(
                                'title' => t('Contact us for more information'), 
                                'onclick' => 'Mailto(' . $node->nid . ');return false;'))) . 
              '</p>';
      }
    ?>
    </p>
    <p>&nbsp;</p>
  </div>
  <!--/col480 jaArticle --> 
  <div class="fRight shareArticleDiv">
    <?php
      if (render($content['field_more_about_status']) != 'disabled') {
        if (isset($content['field_more_about_link'])) {
          global $language;
          $abouttitle = render($content['field_more_about_title']);
          $aboutlink = render($content['field_more_about_link']);
          if (isset($language->language) && $language->language == 'he') {
            $icon = theme('image', array('alt' => $abouttitle, 'path' => path_to_theme() . '/images/arrow11he.png'));
          } else {
            $icon = theme('image', array('alt' => $abouttitle, 'path' => path_to_theme() . '/images/arrow11.png'));
          }
          print '<h3>' . l($abouttitle . $icon, $aboutlink, array('html' => true, 'attributes' => array('title' => $abouttitle))) . '</h3>';
        } else if (isset($content['field_more_about_title'])) {
          print '<h3>' . render($content['field_more_about_title']) . '</h3>';
        }
        print render($content['field_more_about']);
      }
    ?>
    <div class="shareArticle">
      <div class="fRight">
          <?php 
          if ((isset($content['field_facebook_icon']) && isset($content['field_facebook_icon'][0]['#markup']) && $content['field_facebook_icon'][0]['#markup'] == 'yes') ||
             (isset($content['field_twitter_icon']) && isset($content['field_twitter_icon'][0]['#markup']) && $content['field_twitter_icon'][0]['#markup'] == 'yes') ||
             (isset($content['field_google_icon']) && isset($content['field_google_icon'][0]['#markup']) && $content['field_google_icon'][0]['#markup'] == 'yes') ||
             (isset($content['field_print_icon']) && isset($content['field_print_icon'][0]['#markup']) && $content['field_print_icon'][0]['#markup'] == 'yes')) {
              print t('Share') . '&nbsp;';
          } 
          ?>
          <?php 
          if (isset($content['field_facebook_icon']) && isset($content['field_facebook_icon'][0]['#markup']) && $content['field_facebook_icon'][0]['#markup'] == 'yes') {
            print '&nbsp; &nbsp;' . l(theme('image', array('path' => path_to_theme() . '/images/blogFooterFacebook.png')), 
                                      'http://www.facebook.com/sharer.php?u=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))), 
                                        array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank')));
          }
          if (isset($content['field_twitter_icon']) && isset($content['field_twitter_icon'][0]['#markup']) && $content['field_twitter_icon'][0]['#markup'] == 'yes') {
            print '&nbsp; &nbsp;' . l(theme('image', array('path' => path_to_theme() . '/images/blogFooterTwitter.png')), 
                                      'https://twitter.com/intent/tweet?text=' . rawurlencode(render($node->title)) . '&url=' . rawurlencode(url('node/' . $node->nid, 
                                      array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank')));
          }
          if (isset($content['field_google_icon']) && isset($content['field_google_icon'][0]['#markup']) && $content['field_google_icon'][0]['#markup'] == 'yes') {
            print '&nbsp; &nbsp;' . l(theme('image', array('path' => path_to_theme() . '/images/blogFooterGoogle.png')), 
                                    'https://plusone.google.com/_/+1/confirm?url=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))) .
                                      '&title=' . rawurlencode(render($node->title)), 
                                    array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank')));
          }
          if (isset($content['field_print_icon']) && isset($content['field_print_icon'][0]['#markup']) && $content['field_print_icon'][0]['#markup'] == 'yes') {
            print '&nbsp; &nbsp;' . t('PRINT') . '&nbsp; &nbsp;';
            if (isset($content['links']['print_html'])) {
              print l(theme('image', array('path' => path_to_theme() . '/images/printIcon.png')), $content['links']['print_html']['#links']['print_html']['href'], array('attributes' => array('target' => '_new'), "html" => TRUE));
            } else {
              print l(theme('image', array('path' => path_to_theme() . '/images/printIcon.png')), 'print/' . $node->nid, array('attributes' => array('target' => '_new'), "html" => TRUE));
            }
          }
          ?>
          </div>
      <?php if(isset($content['field_date_with_time'])) { ?> 
      <span class="meta"><?php print render($content['field_date_with_time']); ?></span>
      <?php } else { ?>
      <span class="meta"><?php print format_date($node->created, 'blog'); ?> / <?php print convert_jew_date($node->created); ?></span>
      <?php } ?>
      <span class="fb-comments-count"><?php print theme('image', array('path' => path_to_theme() . '/images/blogFooterComment.png')); ?>
      <strong class="fb-comments-count" data-href="<?php print url( 'node/' . $node->nid, array('absolute' => true)); ?>">0</strong></span>
    </div>
    <?php
    if ($node->comment == 2) : 
    ?>
    <section class="facebookComments">
      <a id="facebook-comments"></a>
      <fb:comments href="<?php print url( 'node/' . $node->nid, array('absolute' => true)); ?>"  num_posts="10"  width="730"  colorscheme="light" ></fb:comments>
    </section>
      <p>&nbsp;</p>
    <?php endif; ?>
    <!--/shareArticle -->
    <!--/picList230 single noBorder-bottom -->
  </div>
  <!--/ -->
  <p>&nbsp;</p>
</div>
<!--/wrapper -->


