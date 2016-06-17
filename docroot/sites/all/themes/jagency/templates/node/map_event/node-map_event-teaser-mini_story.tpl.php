<div id="card-<?php print $node->nid; ?>" class="card <?php print 'cs' . $class; ?>">
  <div class="top">
    <button class="prev"><?php print t('previous'); ?></button>
    <div class="year_container">
      <span class="year"><?php print render($content['field_years']); ?></span>
    </div>
    <button class="next"><?php print t('next'); ?></button>
  </div>
  <div class="text">
    <?php if(isset($content['field_main_image'])) { ?><?php print render($content['field_main_image']); ?><?php } ?>
    <strong><?php print render($content['field_stats']); ?></strong>
    <?php print render($content['body']); ?>
    <div class="share">
      <?php print t('SHARE'); ?> &nbsp;
      <?php print l(theme('image', array('path' => path_to_theme() . '/images/facebook-G.png')), 'http://www.facebook.com/sharer.php?u=' . rawurlencode(url('node/' . $content['field_button_reference'], array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp; 
      <?php print l(theme('image', array('path' => path_to_theme() . '/images/twitter-G.png')), 'https://twitter.com/intent/tweet?text=' . rawurlencode($content['field_button_reference_title']) . '&url=' . rawurlencode(url('node/' . $content['field_button_reference'], array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp; 
      <?php print l(theme('image', array('path' => path_to_theme() . '/images/plus-G.png')), 'https://plusone.google.com/_/+1/confirm?url=' . rawurlencode(url('node/' . $content['field_button_reference'], array('absolute' => true))) .'&title=' . rawurlencode($content['field_button_reference_title']), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp; 
    </div>
  </div>
</div>