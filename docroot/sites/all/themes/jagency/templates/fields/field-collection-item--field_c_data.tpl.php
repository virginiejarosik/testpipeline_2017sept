<?php

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
 ?>
 <li>
 <?php
 if(!isset($content['field_image'])) : 
  print '<h6>' . strip_tags(render($content['field_c_title'])) . '</h6>';
  print render($content['field_link']); 
 endif; 
 ?>
 <?php if(isset($content['field_image'])) : print strip_tags(render($content['field_image']), "<img>"); ?>
 <?php if(isset($content['field_c_title'])) : ?><h6><?php print render($content['field_c_title']); ?></h6><?php endif;  endif; ?>
 <?php if(isset($content['field_short_description'])) : ?><p><?php print render($content['field_short_description']); ?></p><?php endif; ?>
 <?php if(isset($content['field_date'])) : ?><div class="meta"><?php print format_date(strtotime(render($content['field_date'])), 'blog'); ?> / <?php print convert_jew_date(strtotime(render($content['field_date']))); ?></div><?php endif; ?>
 <?php if(isset($content['field_image'])) : print render($content['field_link']); endif; ?>
 </li>