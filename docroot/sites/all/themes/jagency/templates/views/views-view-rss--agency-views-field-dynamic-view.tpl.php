<?php

/**
 * @file
 * Default template for feed displays that use the RSS style.
 *
 * @ingroup views_templates
 */
if (isset($variables['view']->args[10]) && $variables['view']->args[10]) {
  $node = node_load($variables['view']->args[10]);
  if (isset($node->nid) && in_array($node->type, array('content_filter', 'article', 'content_view_block', 'program_details'))) {
    $title = $node->title;
  }
}
?>
<?php print "<?xml"; ?> version="1.0" encoding="utf-8" <?php print "?>"; ?>
<rss version="2.0" xml:base="<?php print $link; ?>"<?php print $namespaces; ?>>
  <channel>
    <title><?php print $title; ?></title>
    <link><?php print $link; ?></link>
    <description><?php print $description; ?></description>
    <language><?php print $langcode; ?></language>
    <?php print $channel_elements; ?>
    <?php print $items; ?>
  </channel>
</rss>