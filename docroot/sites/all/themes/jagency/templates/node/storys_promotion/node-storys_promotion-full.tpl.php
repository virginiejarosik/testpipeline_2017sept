<div class="wrapper">
  <h4><?php print $title; ?></h4>
  <ul class="bwGallery">
    <?php print strip_tags(render($content['field_story']), "<img><div><a><li>"); ?>
  </ul>
</div>