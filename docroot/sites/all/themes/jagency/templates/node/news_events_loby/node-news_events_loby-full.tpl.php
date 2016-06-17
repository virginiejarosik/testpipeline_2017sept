<div class="wrapper">
  <aside class="fLeft"> 
    <?php
      $block = jagency_block_render('jagency_pages', 'jagency_menu_block');
      print str_replace('nav', 'nav cs' . $content['color'], $block);
    ?>
  </aside>
  <!--/ -->
  <div class="col730 fRight">
    <div class="picIntro">
      <figure><?php print render($content['field_main_image']); ?>
        <?php print $content['field_copyright']; ?>
      </figure>
      <figcaption>
        <?php if(isset($content['field_sub_title'])) { print '<h3>' . render($content['field_sub_title']) . '</h3>'; } ?>
        <?php print render($content['field_description']); ?>
        <div class="meta"><?php print format_date(strtotime(render($content['field_date'])), 'blog') . ' / ' . convert_jew_date(strtotime(render($content['field_date']))); ?></div>
      </figcaption>
    </div>
    <p>&nbsp;</p>
  </div>
</div>
<!--/wrapper -->
<div class="wrapper">
  <aside class="fRight">
    <!--h3><?php print t('Twitter Mentions'); ?></h3>
    <ul class="tweets">
      <li> <img src="https://si0.twimg.com/profile_images/2885521085/e1adc0b7d2db6bc939d24786326a077b_normal.png" alt=""> <strong><a href="#">@DavidKatz</a></strong> <span class="timestamp">5 minutes ago</span><br>
        <a href="#">#JewishAgency</a> helps Netivot families whos homes were damaged by rocket fire<br>
        <a href="http://jew.ag/PXJ6yb">http://jew.ag/PXJ6yb</a></li>
      <li><img src="https://si0.twimg.com/profile_images/3172212959/fdf70a24e6ca5ecd1da7216519588d56_normal.jpeg" alt=""><strong><a href="#">@EmmaHoyles</a></strong> <span class="timestamp">15h</span><br>
        <a href="#">@dmnathan</a> Sounds like you're making some major life changes. Are you moving permanently? Have a safe journey. <a href="http://jew.ag/PXJ6yb">http://jew.ag/PXJ6yb</a></li>
      <li><img src="https://si0.twimg.com/profile_images/1147874459/DSC_3354-1_normal.JPG" alt=""><strong><a href="#">@Hadassah_Levy</a></strong> <span class="timestamp">14h</span><br>
        <a href="#">@dmnathan</a> Welcome to Israel!</li>
    </ul-->
    <!--/tweets -->
  </aside>
  <!--/ -->
  <?php print $content['more_news_events'];  ?>
  <!--/ -->
  <p>&nbsp;</p>
</div>