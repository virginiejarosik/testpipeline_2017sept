<li>
  <?php print l('<figure>
    <figcaption>' . date('M', strtotime(render($content['field_date']))) .' <strong>' . date('d', strtotime(render($content['field_date']))) .'</strong></figcaption>
  </figure>', 'node/' . $node->nid, array('html' => true)); ?>
  <div class="text">
    <h6><?php print t('Event'); ?></h6>
    <h3><?php print l($title, 'node/' . $node->nid); ?></h3>
    <p><?php print render($content['field_teaser']); ?></p>
    <div class="meta"><?php print format_date(strtotime(render($content['field_date'])), 'blog') . ' / ' . convert_jew_date(strtotime(render($content['field_date']))); ?>
      <?php print l(theme('image', array('path' => path_to_theme() . '/images/commentIcon.png')), 'node/' . $node->nid, array('fragment' => 'facebook-comments', 'html' => true, 'attributes' => array('class' => array('fb-comments-count-image', 'hidden')))); ?><strong class="fb-comments-count hidden" data-href="<?php print url('node/' . $node->nid, array('absolute' => true)); ?>">0</strong>
      </div>
  </div>
</li>