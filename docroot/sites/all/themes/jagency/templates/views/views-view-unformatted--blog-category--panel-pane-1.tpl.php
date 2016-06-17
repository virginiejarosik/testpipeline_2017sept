<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$menuitem = menu_get_item();
$term = isset($menuitem['page_arguments'][2]) ? jagency_taxonomy_translate($menuitem['page_arguments'][2]->data->tid, $menuitem['page_arguments'][2]->data->name) : '';
if (is_array($rows) && count($rows) && !isset($_GET['page'])) {
  $first = array_shift($rows);
  print $first;
}
?>
<div class="allPosts">
<?php if (!isset($_GET['page'])) : ?>
<h3><?php print t('All Posts in @term', array('@term' => $term)); ?></h3>
<ul>
<?php endif ;?>
<?php foreach ($rows as $id => $row): ?>
  <li <?php if ($classes_array[$id]) { print 'class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </li>
<?php endforeach; ?>
</ul>
</div>