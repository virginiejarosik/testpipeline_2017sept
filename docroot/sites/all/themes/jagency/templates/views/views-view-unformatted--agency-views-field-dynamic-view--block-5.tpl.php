<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$counter = 0;
?>
<ul class="<?php print (isset($_REQUEST['page']) && $_REQUEST['page'] > 0 ? 'picList230' : 'picList480'); ?> splitList">
<?php foreach ($rows as $id => $row): ?>
  <?php if ($counter == 2 && !isset($_REQUEST['page'])): ?></ul><ul class="picList230 splitListSmall"><?php endif; ?> 
  <li<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; $counter++;?>
  </li>
<?php endforeach; ?>
</ul>