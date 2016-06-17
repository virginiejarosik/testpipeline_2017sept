<dd>
  <?php 
    print l('<span class="eventDate">' . date('M', strtotime(render($content['field_date']))) . ' 
    <strong>' . date('d', strtotime(render($content['field_date']))) . '</strong></span> ' . $title, 'node/' . $node->nid ,array('html' => true, 'attribute' => array('title' => $title, 'target' => '_blank'))); 
  ?>
  <?php print render($content['field_address_collection']); ?>
</dd>