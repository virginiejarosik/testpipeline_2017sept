<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$menuitem = menu_get_item();
if (is_array($rows) && count($rows)) {
  //$first = array_shift($rows);
  //print $first;
}
?>
<div class="blogsRightBoxInner">
<ul id="contributors">
<?php foreach ($rows as $id => $row): ?>
  <li <?php if ($classes_array[$id]) { print 'class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </li>
<?php endforeach; ?>
</ul>
</div>