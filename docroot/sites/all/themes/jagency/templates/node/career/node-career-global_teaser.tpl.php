<li>
  <?php if(isset($content['field_main_image'])) { ?><figure><?php print render($content['field_main_image']); ?></figure><?php } ?>
  <div class="text">
    <h3><?php print l($title, 'node/' . $node->nid, array('html' => true)); ?></h3>
    <p><?php print render($content['field_program_short_description']); ?></p>
  </div>
</li>