<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$menuitem = menu_get_item();
$_user = isset($menuitem['page_arguments'][2]) ? $menuitem['page_arguments'][2]->data : '';
$name = field_view_field('user', $_user, 'field_profile_name');
$name = isset($name[0]) ? $name[0]['#markup'] : $menuitem['page_arguments'][2]->data->name;
if (is_array($rows) && count($rows) && !isset($_GET['page'])) {
  $first = array_shift($rows);
  print $first;
}
?>
<div class="allPosts">
<?php if (!isset($_GET['page'])) : ?>
<h3><?php print t('All Posts By @name', array('@name' => $name)); ?></h3>
<?php endif; ?>
<ul>
<?php foreach ($rows as $id => $row): ?>
  <li <?php if ($classes_array[$id]) { print 'class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </li>
<?php endforeach; ?>
</ul>
</div>