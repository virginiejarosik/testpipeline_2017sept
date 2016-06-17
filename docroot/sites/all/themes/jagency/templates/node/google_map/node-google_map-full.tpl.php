<div class="map" id="map-<?php print $node->nid; ?>">
  <?php print l(render($content['field_header_title']), render($content['field_header_link']), array('attributes' => array('class' => 'mapGI'))); ?>
    <div id="map-canvas"></div>
    <div class="cards">
      <?php print render($content['field_events']); ?>
    </div>
  </div>
</div>