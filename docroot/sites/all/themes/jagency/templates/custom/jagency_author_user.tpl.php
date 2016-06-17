<div class="blogAuthor">
  <?php print strip_tags(render($image), '<img>'); ?>
  <p><?php print l('<strong>' . strip_tags(render($firstname)) . '</strong>', $link, array("html" => TRUE)); ?> <?php print strip_tags(render($bio), '<span><strong><b><i><u>'); ?></p>
  <br class="clearfix"/>
</div>