<div class="fixedWrapper">
  <div class="storyHead">
    <h1><?php print $title; ?></h1>          
          <div class="share"><span><?php print t('Share'); ?></span>&nbsp; &nbsp;          
          <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterFacebook.png')), 
                        'http://www.facebook.com/sharer.php?u=' . rawurlencode(url('node/' . $node_id, array('absolute' => true))), 
                        array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
          <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterTwitter.png')), 
                        'https://twitter.com/intent/tweet?text=' . rawurlencode(render($title)) . '&url=' . rawurlencode(url('node/' . $node->nid, 
                        array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
          <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterGoogle.png')), 
                        'https://plusone.google.com/_/+1/confirm?url=' . rawurlencode(url('node/' . $node_id, array('absolute' => true))) .'&title=' . rawurlencode(render($title)), 
                        array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
          <div class="fb-like" data-send="false" data-layout="button_count" data-show-faces="false"></div>
      </div>
    <div class="action"><?php print $program; ?>
      <div class="cs1">
      <?php 
        if(isset($apply_button) && $apply_button != NULL) {
          print l(t('Apply'), strip_tags($apply_button));
        }
        if(isset($sponsor_button) && $sponsor_button != NULL) {
          print l(t('Sponsor'), strip_tags($sponsor_button));
        }
        ?>
       </div>
     </div>
  </div>
</div>