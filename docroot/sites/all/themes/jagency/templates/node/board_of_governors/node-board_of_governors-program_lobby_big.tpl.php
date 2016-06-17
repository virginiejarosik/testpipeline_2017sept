<?php $display = strip_tags(render($content['field_display_as_teaser'])); ?>
<li>
  <figure><?php print render($content['field_image']); ?>
  </figure>
  <div class="text">
    <h6><?php print render($content['field_roles']); ?></h6>
    <h3><?php print $title; ?></h3>
    <?php if($display == 'display') { print '<div class="collapsibleText">'; }?>
    <p>
      <?php print render($content['field_profile_short_bio']); ?>
    </p>
    <?php
    if($display == 'display') {
      print '</div>';
      print l(t('Read More'), NULL, array('attributes' => array('class' => 'toggleText')));
    } else {
      print l(t('View profile'), 'node/' . $node->nid, array('attributes' => array('class' => 'toProfile'))); 
    }
    ?>
  </div>
</li>