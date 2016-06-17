<?php
?>
<div class="specialCon">
  <?php print strip_tags(render($content['image']), '<img>'); ?>
  <p><?php print t('Special Contributor'); ?></p>
  <?php print $content['name']; ?>
  <span><?php print truncate_utf8($content['bio'], 80, true); ?></span>
</div>
