<div class="wrapper bogFull">
   
  <aside class="fLeft"> 
    <?php
    $block = jagency_block_render('jagency_pages', 'jagency_menu_block');
    if (isset($content['color'])) {
      print str_replace('nav', 'nav cs' . $content['color'], $block);
    } else {
      print $block;
    }
    ?>
  </aside>
  <!--/ -->
  <div class="col730 fRight bio">
     <div style="margin-top:60px;" class="fRight">      
    <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterFacebook.png')), 'http://www.facebook.com/sharer.php?u=' . rawurlencode(url('node/' . $node -> nid, array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
    <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterTwitter.png')), 'https://twitter.com/intent/tweet?text=' . rawurlencode(render($node -> title)) . '&url=' . rawurlencode(url('node/' . $node -> nid, array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
    <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterGoogle.png')), 'https://plusone.google.com/_/+1/confirm?url=' . rawurlencode(url('node/' . $node -> nid, array('absolute' => true))) . '&title=' . rawurlencode(render($node -> title)), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
    <div class="fb-like" data-send="false" data-layout="button_count" data-show-faces="false"></div>
  </div>
  <h1><?php print $title; ?> <span class="subTitle"><?php print implode(' and ', $roles); ?></span></h1>
    <div class="picIntro">
      <figure><?php print render($content['field_image']); ?>
        <div class="cr"><?php print $content['field_copyright']; ?></div>
      </figure>
    </div>
    <!--/picIntro -->
    
    <!--/aside -->
    <div class="col480">
     <?php if(isset($content['field_short_bio'])) { ?><h4><?php print render($content['field_short_bio']); ?></h4><?php } ?>
     <?php print render($content['field_description']); ?>      
      <!--/ -->
      <?php
      $time_line = render($content['field_time_line']);
       if(strlen(strip_tags($time_line))) { ?>
      <h3><?php print t('Timeline'); ?></h3>
      <ul class="timelineList">
        <?php print str_replace(array('class="field-collection-view clearfix view-mode-full"', 'class="field-collection-view clearfix view-mode-full field-collection-view-final"'), '', strip_tags($time_line, "<h5><p><li>")); ?>
      </ul>
      <!--/timelineList -->
      <div class="moreContent"><?php print t('READ FULL TIMELINE'); ?></div>
      <!--/ -->

      <aside class="col-sm-12 no-padding  ">
      <?php if(isset($content['field_quote'])) { ?>
      <div class="quoteBox">“<?php print strip_tags(render($content['field_quote'])); ?>”
        <?php
        if (isset($content['field_see_my_story_link'])) {
          print l(t('See my story'), strip_tags(render($content['field_see_my_story_link'])), array("attributes" => array("class" => "cs4")));
        }
        ?>
      </div>
      <?php } 
      print render($content['field_c_blocks']);
      ?>
    
      <!--/greyListBox --> 
      </aside>
      <?php } ?>
    </div>
    <!--/col480 --> 
  </div>
</div>