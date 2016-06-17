<li>
    <?php print l('<figure>
    <figcaption>' . date('M', strtotime(render($content['field_date']))) .' <strong>' . date('d', strtotime(render($content['field_date']))) .'</strong></figcaption>
  </figure>', 'node/' . $node->nid, array('html' => true)); ?>
    <h3><?php print l($title, 'node/' . $node->nid); ?></h3>
    <p><?php print render($content['field_teaser']); ?></p>
</li>