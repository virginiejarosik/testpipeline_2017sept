<div class="wrapper">
  <aside class="fLeft"> 
    <?php
      $block = jagency_block_render('jagency_pages', 'jagency_menu_block');
      print str_replace('nav', 'nav cs' . $content['color'], $block);
    ?>
  </aside>
  <!--/ -->
  <div class="col730 fRight jaEvent">
    <div class="introGrey">
      <h2><?php print $title; ?></h2>
      <?php if(isset($content['field_teaser'])) { ?><h4 class="subTitle"><?php print render($content['field_teaser']); ?></h4><?php } ?>
      <p><?php print render($content['body']); ?></p>
    </div>
    <!--/introGrey -->
    <?php if(isset($content['field_related_events'])) { ?>
    <aside>
      <dl class="picList">
        <dt><a href="#"><?php print t('Related Events'); ?> <?php print theme('image', array('path' => path_to_theme() . '/images/arrow11.png')); ?></a></dt>
        <?php print render($content['field_related_events']); ?>
      </dl>
      <!--/picList --> 
    </aside>
    <?php } ?>
    <!--/aside -->
    <div class="col480">
      <table class="jaEventTbl">
        <tr>
          <?php if(isset($content['field_date'])) { ?>
          <td>
            <h6><?php print t('Date'); ?></h6>
            <h3 class="subTitle"><?php print format_date(strtotime(render($content['field_date'])), 'blog'); ?></h3>
          </td>
          <?php }
          if(isset($content['field_time'])) { ?>
          <td>
            <h6><?php print t('Time'); ?></h6>
            <h3 class="subTitle"><?php print render($content['field_time']); ?></h3>
          </td>
          <?php } ?>
        </tr>
        <tr>
          <?php if(isset($content['field_address_event'])) { ?>
          <td>
            <h6><?php print t('Location'); ?></h6>
            <h3 class="subTitle"><?php print render($content['field_address_event']); ?></h3>
            <p><?php print render($content['field_geo_location']); ?></p>
            <?php print l(t('Map'), $content['map_url'], array('attributes' => array('target' => '_blank'))); ?>
          </td>
          <td>&nbsp;</td>
          <?php } ?>
        </tr>
      </table>
      <!--/jaEventTbl --> 
    </div>
    <!--/col480 -->
    <?php
      if ($node->comment == 2) : 
      ?>
    <section class="facebookComments">
     <a id="facebook-comments"></a>
     <fb:comments href="<?php print url( 'node/' . $node->nid, array('absolute' => true)); ?>"  num_posts="10"  width="730"  colorscheme="light" ></fb:comments>
    </section>    <!--/ -->
    <p>&nbsp;</p>
    <?php endif; ?>
  </div>
  <!--/col730 fRight -->
</div>