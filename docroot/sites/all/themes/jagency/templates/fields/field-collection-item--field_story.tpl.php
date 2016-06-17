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
<?php print render($content['field_sp_image']); ?>
<div class="tTip" style="display: none; opacity: 0;">
  <?php if(isset($content['field_quote']) OR isset($content['field_apply_link']) OR isset($content['field_short_description'])) { ?>
  <div class="text">
    <div class="textIn">
     <?php 
       if(isset($content['field_apply_link'])) {
        $button_class = 'cs1';
        $button_class = strip_tags(render($content['field_link_color']));
        if($button_class == '_none') { $button_class = 'cs1'; }
        print l(t('See My Story'), strip_tags(render($content['field_apply_link'])), array('attributes' => array('class' => $button_class)));
       }
     ?>
     <?php if(isset($content['field_quote'])) { print '<div class="quote">' . strip_tags(render($content['field_quote'])) . '</div>'; } ?>
     <?php if(isset($content['field_short_description'])) { print '<div class="desc">' . strip_tags(render($content['field_short_description'])) . '<br />' . '</div>'; } ?>
   </div>
  </div>
  <?php } ?>
</div>