<li>
  <?php print strip_tags(render($content['field_main_image']), "<img><a>"); ?>
  <?php print l(html_entity_decode($title, ENT_QUOTES), 'node/' . $node->nid); ?>
  <p><?php print render($content['field_quote']); ?></p>
</li>