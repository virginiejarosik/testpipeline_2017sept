<div id="card-<?php print $node->nid; ?>" class="card <?php print 'cs' . $class; ?>">
  <div class="top">
    <button class="prev"><?php print t('previous'); ?></button>
    <div class="year_container">
      <span class="year"><?php print render($content['field_years']); ?></span>
    </div>
    <button class="next"><?php print t('next'); ?></button>
  </div>
  <?php if(isset($content['field_main_image'])) { ?><figure><?php print render($content['field_main_image']); ?></figure><?php } ?>
  <strong><?php print render($content['field_stats']); ?></strong>
  <p><?php print strip_tags(render($content['body']), '<strong><b><i><u><span><ul><li>'); ?></p>
  <?php 
    if(isset($content['field_event_button']) && isset($content['field_button_reference'])) {
      print l(render($content['field_event_button']), 'node/' . render($content['field_button_reference']), array('attributes' => array('class' => 'donate')));
    }
  ?>
</div>