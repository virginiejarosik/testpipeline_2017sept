<?php
if(isset($content['field_p2g_promotion'])) {
  print render($content['field_p2g_promotion']);
}
?>
<div class="wrapper">
  <?php print render($content['field_new_gallery']); ?>
  <div style="margin-top:45px;" class="fRight">      
    <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterFacebook.png')), 'http://www.facebook.com/sharer.php?u=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
    <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterTwitter.png')), 'https://twitter.com/intent/tweet?text=' . rawurlencode(render($node->title)) . '&url=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
    <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterGoogle.png')), 'https://plusone.google.com/_/+1/confirm?url=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))) .'&title=' . rawurlencode(render($node->title)), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
    <div class="fb-like" data-send="false" data-layout="button_count" data-show-faces="false"></div>
  </div>
  <h1><?php print l(html_entity_decode($title, ENT_QUOTES), $program_link); ?></h1>
    <div class="picIntro clearfix">
      <figure>
        <?php if (isset($content['field_main_image_video'])) : ?>
          <div class="play playBtn" data-size="980x518" data-href="<?php print $content['field_main_image_video']; ?>"></div>
        <?php endif; ?>
        <?php print render($content['field_main_image']); ?><?php print get_copyright('field_main_image', $node->nid); ?>
      </figure>
    <?php if(isset($content['field_program_logo'])) {?>
    <aside class="fLeft"><br>
      <p style="text-align:center;"><?php if(isset($content['field_program_logo_link'])) { print l(render($content['field_program_logo']), strip_tags(render($content['field_program_logo_link'])), array('html' => true, 'attributes' => array('target' => '_blank'))); } else { print render($content['field_program_logo']); } ?>
            </aside>
    <?php
      $classes = "col730 fRight ";
      }
    ?>
    <article class="<?php print $classes; ?> noBorder-bottom noBorder-top ">
      
      <h4><?php print strip_tags(render($content['field_short_description'])); ?></h4>
     </article>
    <!--/artile -->
  </div>
  <!--/picIntro -->
  <?php
  if(in_array('contact_us', $content['block_list']) OR in_array('application_resources', $content['block_list'])) { ?>
    <aside><br>
      <?php if(in_array('contact_us', $content['block_list'])) { ?>
        <div class="resources">
         <h5><?php print t('Contact us'); ?></h5>
         <?php
          if(isset($content['field_organizer']) && count($content['field_organizer']) > 0) { print render($content['field_organizer']) . '<br><br>'; }
          if(isset($content['field_program_mailto'])) { print t('Email: !link', array('!link' => render($content['field_program_mailto']))); }
          if(isset($content['field_program_phone'])) { print '<br><br>' . str_replace("&nbsp; | &nbsp;", "", render($content['field_program_phone'])); }
          if(isset($content['field_program_phone_2'])) { print '<br><br>' . str_replace("&nbsp; | &nbsp;", "", render($content['field_program_phone_2'])); }
          if(isset($content['field_organizer_website'])) { print '<br><br>' . l(render($content['field_organizer_website']), render($content['field_organizer_website'])); }
         ?>
      </div>
    <?php } if(in_array('application_resources', $content['block_list']) && isset($content['field_application_resource_new'])) { ?>
    <div class="resources">
      <h5><?php print strip_tags(render($content['field_application_resources']), "<a>"); ?></h5>
      <?php print strip_tags(render($content['field_application_resource_new']), "<img><br><a><div>"); ?>
    </div>
    <?php } ?>
  </aside>
  <!--/aside -->
  <?php } if(isset($content['body']) && $content['body']) { ?>
  <div class="col730 Sul">
    <article class="clearfix noBorder-top noBorder-bottom">
    <?php print render($content['body']); ?>
    </article>
    <!--/article -->
    <?php } if(in_array('apply_box', $content['block_list'])) { ?>
    <table class="programData">
      <tr>
        <td>
          <h6><?php if(isset($prices)) { print '$' . $prices; } ?></h6>
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
    <!--/ --> 
    <?php } if(in_array('facebook_group', $content['block_list'])) {
            print render($content['field_facebook_group']);
          } 
      ?>
  </div>
  <!--/col730 --> 
</div>
<!--/wrapper -->
<?php if(in_array('experiances', $content['block_list']) && isset($content['field_experiances'])) { ?>
<p>&nbsp;</p>
<section class="grey borderd">
  <div class="wrapper">
    <?php
      $title_experiance = '';
      if(isset($content['field_title_experiances'])) {
        if(isset($content['field_title_experiences_link'])) {
          global $language;
          if (isset($language->language) && $language->language == 'he') {
            $icon = theme('image', array('alt' => $featured_stories_title, 'path' => path_to_theme() . '/images/arrow11he.png'));
          } else {
            $icon = theme('image', array('alt' => $featured_stories_title, 'path' => path_to_theme() . '/images/arrow11.png'));
          }
          $title_exp = strip_tags(render($content['field_title_experiances'])) . $icon;
          $link_exp = render($content['field_title_experiences_link']);
          $title_experiance = l($title_exp, $link_exp, array('html' => true, 'attributes' => array('alt' => strip_tags(render($content['field_title_experiances'])))));
        } else {
          $title_experiance = render($content['field_title_experiances']);
        }
      }
      if ($title_experiance) {
        print '<h3>' . $title_experiance . '</h3>';
      } else {
        print '<div style="min-height: 60px;"></div>';
      }
      ?>
    <?php
      print render($content['field_experiances']);
    ?>
  </div>
</section>
<?php } ?>
<!--/grey -->
<p>&nbsp;</p>
<?php if(in_array('more_about', $content['block_list']) OR in_array('stories', $content['block_list'])) { ?>
<div class="wrapper">
  <?php if(in_array('stories', $content['block_list']) && isset($content['field_featured_stories'])) {?>
  <aside>
    <h5 class="preTitle">
      <?php
        if(isset($content['field_title_featured_stories'])) {
          if(isset($content['field_featured_stories_link'])) {
            global $language;
            if (isset($language->language) && $language->language == 'he') {
              $icon = theme('image', array('alt' => $featured_stories_title, 'path' => path_to_theme() . '/images/arrow11he.png'));
            } else {
              $icon = theme('image', array('alt' => $featured_stories_title, 'path' => path_to_theme() . '/images/arrow11.png'));
            }
            $title_sto = strip_tags(render($content['field_title_featured_stories'])) . $icon;
            $link_sto = render($content['field_featured_stories_link']);
            print l($title_sto, $link_sto, array('html' => true));
          } else {
            print render($content['field_title_featured_stories']);
          }
        } else {
          print t('Featured Stories'); }
        ?>
        </h5>
    <div class="sidePics">
      <?php print strip_tags(render($content['field_featured_stories']), "<a><img>"); ?>
    </div>
    <!--/sidePics --> 
  </aside>
  <?php } 
    if(in_array('more_about', $content['block_list'])) {
  ?>
  <!--/aside -->
  <div>
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
          $title_more = strip_tags(render($content['field_more_about_title'])) . ' ' . $icon;
          $link_more = render($content['field_more_about_link']);
          print l($title_more, $link_more, array('html' => true, 'attributes' => array('alt' => 'More about ' . strip_tags(render($content['field_more_about_title'])))));
        } else {
          print render($content['field_more_about_title']);
        } 
      }
      ?>
    </h5>
    <?php 
    if(in_array('stories', $content['block_list'])) {
      print '<div class="moreabout_with_stories" style="width: 700px;">' . render($content['field_more_about']) . '</div>';
    } else {
      print render($content['field_more_about']);
    }  
    ?>
  </div>
  <?php } ?>
  <!--/col730 --> 
</div>
<?php } ?>
<!--/wrapper --> 

<!--/ -->
<?php
 if(in_array('photos_from', $content['block_list'])) {
   print '<div class="wrapper">'; 
   print render($content['field_gallery']);
   print render($content['field_product_video']);
   print '</div>'; 
 }
 
//if(in_array('location', $content['block_list']) && 0) {

?>
<!--/wrapper -->

<?php 
  if(in_array('location', $content['block_list'])) {
    print $program_map;
  }
?>

<!--/wrapper -->
 <?php //} ?>
 <div class="wrapper">
 <?php if(in_array('q_and_a', $content['block_list'])) {
    print views_embed_view('faq_s', 'block'); 
   } if(in_array('sponsors', $content['block_list']) && isset($content['field_sponsors'])) { ?>
    <!--/sponsor -->  
  <div class="sponserdBy">
    <table>
      <tr>
        <?php print strip_tags(render($content['field_sponsors']), "<a><img><td>"); ?>
      </tr>
    </table>
  </div>
  <?php } ?>
</div>
<div class="wrapper">
  <?php print render($content['field_storys_promotion']); ?>
</div>