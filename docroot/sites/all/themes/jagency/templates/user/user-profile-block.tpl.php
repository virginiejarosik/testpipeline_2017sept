<?php print l(strip_tags(render($content['image']), '<img>'), $content['link'], array('html' => true)); ?>
<span class="hide"><?php print strip_tags(render($content['image2']), '<img>'); ?></span>
<div class="conToolTip">
  <div class="relative">
    <div class="popupArrowUp"></div>
    <?php print $content['name']; ?>
    <span><?php print truncate_utf8($content['bio'], 80, true); ?></span>
    <div class="popupArrowDown"></div>
  </div>
</div>