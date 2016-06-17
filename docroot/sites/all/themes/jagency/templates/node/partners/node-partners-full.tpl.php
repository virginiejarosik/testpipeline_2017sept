<div class="wrapper">
  <h1><?php print $title; ?></h1>
  <aside class="fLeft"> 
    <!-- Switches - cs1, cs2, cs3, cs4 or none for the tja blue-->
    <?php
     $block = jagency_block_render('jagency_pages', 'jagency_menu_block');
     print str_replace('nav', 'nav cs' . $content['color'], $block);
    ?>
  </aside>
  <!--/ -->
  <div class="col730 fRight">
    <?php if(isset($content['field_partners_logos'])) : ?>
    <div class="p2gsmallIntro">
      <div class="logosTbl">
        <?php print render($content['field_partners_logos']); ?>
      </div>
    </div>
    <?php endif; ?>
    <p>&nbsp;</p>
    <!--/ -->
    <aside>
      <?php print render($content['field_c_blocks']); ?>
    </aside>
    <!--/aside -->
    <div class="col480">
      <?php print render($content['field_links_box']); ?>
      <p>&nbsp;</p>
    </div>
    <!--/col480 --> 
  </div>
</div>