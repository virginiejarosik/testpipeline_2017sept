<div class="fRight">
  <div class="picIntro">
    <figure>
      <?php if (isset($content['field_main_image_video'])) : ?>
        <div class="play playBtn" data-size="730x548" data-href="<?php print $content['field_main_image_video']; ?>"></div>
      <?php endif; ?>
      <?php print render($content['field_main_image']); ?>
      <?php print isset($content['field_copyright']) ? $content['field_copyright']: ''; ?>
    </figure>
    <?php if(isset($content['field_image_description'])) { ?> <figcaption class="s11"> <?php print render($content['field_image_description']); ?> </figcaption> <?php } ?>
  </div>
  <!--/picIntro -->
  <?php
    if (isset($content['field_source_link'])) {
      print '<p>' . l(render($content['field_source_image']), render($content['field_source_link']), array('html' => true)) . '</p>';
    } elseif (isset($content['field_source_image'])) {
      print '<p>' . render($content['field_source_image']) . '</p>';
    }
  ?>
</div>