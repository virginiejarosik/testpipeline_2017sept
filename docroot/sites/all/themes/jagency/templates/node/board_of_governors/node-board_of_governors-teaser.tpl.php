<li>
  <?php print l(render($content['field_image']) . $title, 'node/' . $node->nid, array('html' => true)); ?>
    <p><?php print render($content['field_profile_short_bio']); ?></p>
</li>