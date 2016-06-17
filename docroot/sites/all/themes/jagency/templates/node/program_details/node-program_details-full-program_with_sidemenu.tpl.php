<?php 
if(isset($content['field_p2g_promotion'])) {
  print render($content['field_p2g_promotion']);
}
?>
<div class="wrapper">
  <div style="margin-top:45px;" class="fRight">      
    <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterFacebook.png')), 'http://www.facebook.com/sharer.php?u=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
    <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterTwitter.png')), 'https://twitter.com/intent/tweet?text=' . rawurlencode(render($node->title)) . '&url=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
    <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterGoogle.png')), 'https://plusone.google.com/_/+1/confirm?url=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))) .'&title=' . rawurlencode(render($node->title)), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
    <div class="fb-like" data-send="false" data-layout="button_count" data-show-faces="false"></div>
  </div>
  <h1><?php print l(html_entity_decode($title, ENT_QUOTES), $program_link); ?></h1>
  <aside class="fLeft">
    <?php
      $block = jagency_block_render('jagency_pages', 'jagency_menu_block');
      print str_replace('nav', 'nav cs' . $content['color'], $block);
    ?>
   <?php
    if(in_array('contact_us', $content['block_list']) OR in_array('application_resources', $content['block_list'])) { ?>
      <br>
      <?php if(in_array('contact_us', $content['block_list'])) { ?>
        <div class="resources">
         <h5><?php print t('Contact us'); ?></h5>
         <?php
          if(isset($content['field_organizer']) && count($content['field_organizer']) > 0) { print render($content['field_organizer']) . '<br><br>'; }
          if(isset($content['field_program_mailto'])) { print t('Email: !link', array('!link' => render($content['field_program_mailto']))); }
          if(isset($content['field_program_phone'])) { print '<br><br>' . str_replace("&nbsp; | &nbsp;", "", render($content['field_program_phone'])); }
          if(isset($content['field_program_phone_2'])) { print '<br><br>' . str_replace("&nbsp; | &nbsp;", "", render($content['field_program_phone_2'])); }
          if(trim(render($content['field_organizer_website'])) != NULL) { print '<br><br>' . l(render($content['field_organizer_website']), render($content['field_organizer_website'])); }
         ?>
        </div>
      <?php } if(in_array('application_resources', $content['block_list']) && isset($content['field_application_resource_new'])) { ?>
      <div class="resources">
      <h5><?php print strip_tags(render($content['field_application_resources']), "<a>"); ?></h5>
      <?php print strip_tags(render($content['field_application_resource_new']), "<img><br><a><div>"); ?>
      </div>
      <?php } ?>
    <!--/aside -->
    <?php } ?>
  </aside> 
  <!--/ -->
    <div class="col730 fRight Sul">
    <?php if(isset($content['field_main_image']) OR isset($content['field_program_logo']) OR isset($content['field_short_description'])) { ?>
    <div class="picIntro">
        <figure>
            <?php if (isset($content['field_main_image_video'])) : ?>
                <div class="play playBtn" data-size="730x386" data-href="<?php print $content['field_main_image_video']; ?>"></div>
            <?php endif; ?>
            <?php print render($content['field_main_image']); ?><?php print get_copyright('field_main_image', $node->nid); ?>
        </figure>
         <?php if(isset($content['field_program_logo']) ||  isset($content['field_short_description'])) : ?>
        <figcaption>
          <table>
            <tr>
              <?php if(isset($content['field_program_logo'])) : ?>
                <td width="220" valign="top">
                  <?php if(isset($content['field_program_logo_link'])) {
                     print l(render($content['field_program_logo']), strip_tags(render($content['field_program_logo_link'])), array('html' => true, 'attributes' => array('target' => '_blank'))); 
                  } else {
                     print render($content['field_program_logo']); 
                  } ?>
                </td>
              <?php endif; ?>
              <td valign="top">
                 <?php print render($content['field_short_description']); ?>
              </td>
            </tr>
          </table>
        </figcaption>
      <?php endif; ?>
    </div>
    <?php } ?>
    <!--/picIntro -->
    <article class="clearfix noBorder-bottom">
    <?php print render($content['body']); ?>
    </article>
    <!--/article -->
    <?php if(in_array('apply_box', $content['block_list'])) { ?>
    <table class="programData">
      <tr>
        <td>
          <?php if(isset($prices)) { print '<h6>$' . $prices . '</h6>'; } ?>
          <?php 
            if(isset($cost_icons) && $cost_icons != NULL) {
              print t('INCLUDES !icons', array('!icons' => $cost_icons)); 
            }
          ?>
        </td>
        <td>
          <h6><?php print isset($time_duration) ? $time_duration : time_elapsed_A($time); ?></h6>
          <?php
          if(isset($content['field_start_time']) && $content['field_start_time']) {
            $date = format_date($content['field_start_time'], 'custom', 'M. j, Y');
            print t('STARTS @date', array('@date' => $date));
          }
          ?>
        </td>
        <td>
          <h6><?php print render($content['field_taxonomy_region']); ?></h6>
          <?php print strip_tags(render($content['field_taxonomy_city']) . ', ' . render($content['field_taxonomy_country'])); ?></td>
        <td>
          <?php
            if(isset($content['field_button_text']) && isset($content['field_see_my_story_link']) && isset($content['color'])) {
              $class = 'cs' . jagency_get_color_by_tid($content['color']);
              print l(strip_tags(render($content['field_button_text'])), strip_tags(render($content['field_see_my_story_link']), "<a>"), array("attributes" => array("class" => array("apply", $class))));
            }
            ?>
        </td>
      </tr>
    </table>
    <!--/ --> 
    <?php 
    }
      if(in_array('facebook_group', $content['block_list'])) {
        print render($content['field_facebook_group']);
      } 
    ?>
  <!--/grey -->
  <?php if(in_array('experiances', $content['block_list']) && isset($content['field_experiances'])) { ?>
  <p>&nbsp;</p>
    <div class="wrapper">
      <h3>
      <?php 
        if(isset($content['field_title_experiances'])) {
          if(isset($content['field_title_experiences_link'])) {
            global $language;
            $featured_stories_title = strip_tags(render($content['field_title_experiances']));
            $featured_stories_link = render($content['field_title_experiences_link']);
            if (isset($language->language) && $language->language == 'he') {
              $icon = theme('image', array('alt' => $featured_stories_title, 'path' => path_to_theme() . '/images/arrow11he.png'));
            } else {
              $icon = theme('image', array('alt' => $featured_stories_title, 'path' => path_to_theme() . '/images/arrow11.png'));
            }
            print l($featured_stories_title . $icon, $featured_stories_link, array('html' => true, 'attributes' => array('alt' => $featured_stories_title)));
          } else {
            print render($content['field_title_experiances']);
          } 
        }
        ?>
      </h3>
      <?php
        print render($content['field_experiances']);
      ?>
    </div>
  <?php } ?>
  <p>&nbsp;</p>
  <?php if(in_array('more_about', $content['block_list']) && isset($content['field_more_about'])) { ?>
    <h5 class="preTitle">
      <?php 
        if(isset($content['field_more_about_title'])) {
          if(isset($content['field_more_about_link']) && strip_tags(render($content['field_more_about_link'])) != null) {
              global $language;
              if (isset($language->language) && $language->language == 'he') {
                $icon = theme('image', array('alt' => $featured_stories_title, 'path' => path_to_theme() . '/images/arrow11he.png'));
              } else {
                $icon = theme('image', array('alt' => $featured_stories_title, 'path' => path_to_theme() . '/images/arrow11.png'));
              }
              $more_about_title = strip_tags(render($content['field_more_about_title'])) . '&nbsp' . $icon;
              print l($more_about_title, render($content['field_more_about_link']), array(
                'html' => true, 
                'attributes' => array('alt' => 'More about ' . strip_tags(render($content['field_more_about_title'])))));
          } else {
            print render($content['field_more_about_title']);
          } 
        }
        ?></h5>
      <?php print render($content['field_more_about']); ?>
  <?php } ?>
  <p>&nbsp;</p>
  
  <?php
   if(in_array('photos_from', $content['block_list'])) { 
     print render($content['field_gallery']);
     print render($content['field_product_video']);
   }
   
  if(in_array('location', $content['block_list'])) {
    print $program_map;
  }
  if(in_array('q_and_a', $content['block_list'])) { ?>
  <p class="clearfix">&nbsp;</p>
  <?php 
    print views_embed_view('faq_s', 'block');
   } 
   ?> 
   </div>
   <?php
   if(in_array('sponsors', $content['block_list']) && isset($content['field_sponsors'])) { ?>
      <!--/sponsor -->
  <div class="wrapper">
    <div class="sponserdBy">
      <table>
        <tr>
          <?php print strip_tags(render($content['field_sponsors']), "<a><img><td>"); ?>
        </tr>
      </table>
    </div>
  </div>
  <?php } ?>
</div>
<div class="wrapper">
  <?php print render($content['field_storys_promotion']); ?>
</div>