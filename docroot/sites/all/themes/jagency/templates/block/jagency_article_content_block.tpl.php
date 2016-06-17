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