<div class="wrapper">
  <div class="fRight" style="margin-top:80px;"> <a href="#"><img src="images/facebook-G.png" alt=""></a> &nbsp; &nbsp; <a href="#"><img src="images/twitter-G.png" alt=""></a> &nbsp; &nbsp; <a href="#"><img src="images/plus-G.png" alt=""></a> &nbsp; &nbsp;
    <iframe scrolling="no" frameborder="0" src="//www.facebook.com/plugins/like.php?href=http%3A%2F%2Fwww.facebook.com%2FJewishAgency&amp;send=false&amp;layout=button_count&amp;width=75&amp;show_faces=true&amp;font&amp;colorscheme=light&amp;action=like&amp;height=21" style="border: medium none; overflow: hidden; width: 75px; height: 21px; vertical-align: middle;" allowtransparency="true"></iframe>
  </div>
  <h1><?php print $title; ?> <span class="subTitle"><?php print render($content['field_roles']); ?></span></h1>
  <aside class="fLeft"> 
    <?php
      $block = jagency_block_render('jagency_pages', 'jagency_menu_block');
      print str_replace('nav', 'nav cs' . (isset($content['color']) ? $content['color']: 0), $block);
    ?>
  </aside>
  <!--/ -->
  <div class="col730 fRight bio">
    <div class="picIntro">
      <figure><?php print render($content['field_image']); ?>
        <div class="cr"><?php print (isset($content['field_copyright']) ? $content['field_copyright'] : ''); ?></div>
      </figure>
    </div>
    <!--/picIntro -->
    <aside>
      <?php if(isset($content['field_quote'])) { ?>
      <div class="quoteBox">“<?php print strip_tags(render($content['field_quote'])); ?>”
      </div>
      <?php } ?>
      <!--/quoteBox -->
      </div>
      <!--/greyListBox --> 
    </aside>
    <!--/aside -->
  </div>
</div>