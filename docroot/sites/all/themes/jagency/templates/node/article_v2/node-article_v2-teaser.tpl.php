<li>
  <?php if(isset($content['field_main_image'])) { ?><figure><?php print render($content['field_main_image']); ?></figure><?php } ?>
  <div class="text">
    <?php if(isset($content['field_aticle_type'])) { ?><h6><?php print render($content['field_aticle_type']); ?></h6><?php } ?>
    <h3><?php print l($title, 'node/' . $node->nid, array('html' => true)); ?></h3>
    <p><?php print render($content['field_short_description']); ?></p>
    <div class="meta"><?php print format_date($node->created, 'blog') . ' / ' . convert_jew_date($node->created); ?>
      <?php print l(theme('image', array('path' => path_to_theme() . '/images/commentIcon.png')), 'node/' . $node->nid, array('fragment' => 'facebook-comments', 'html' => true, 'attributes' => array('class' => array('fb-comments-count-image', 'hidden')))); ?><strong class="fb-comments-count hidden" data-href="<?php print url('node/' . $node->nid, array('absolute' => true)); ?>">0</strong>
    </div>
  </div>
</li>