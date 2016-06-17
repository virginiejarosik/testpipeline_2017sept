<div class="wrapper opportunityConfigWrapper">
  <aside class="<?php print $Side_2; ?>">
    <dl class="opportunityConfig">
    <dt>
      <h4><?php print $title; ?></h4>
      <?php print render($content['field_description']); ?> 
    </dt>
    <?php print render($content['field_taxonomy_filter']); ?>
    </dl>
    <div class="stickyWrapper">
     <div class="toTop"><a href="#"><?php print t('BACK TO TOP'); ?></a></div>
    </div>
  </aside>
  <div class="col730 <?php print $Side_1; ?>">
    <?php
      $rss = isset($node->field_display_rss[LANGUAGE_NONE]) ? $node->field_display_rss[LANGUAGE_NONE][0]['value'] : 0;
      print views_embed_view('content_filter', 'block_1', $content_types, $node->nid, $rss); 
    ?>
  </div>
</div>