<li>
  <figure class="event_image">
    <span class="eventDate">
      <?php print date('F', strtotime(render($content['field_date']))); ?><br />
      <strong><?php print date('d', strtotime(render($content['field_date']))); ?></strong>
    </span>
  </figure>
  <div class="text">
    <?php print l($title, 'node/' . $node->nid, array('html' => true)); ?>
    <p><?php print render($content['field_teaser']); ?></p>
  </div>
</li>