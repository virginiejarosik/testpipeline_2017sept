<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
$side_1 = $_SESSION['Side_2'];
$side_2 = $_SESSION['Side_1'];
?>
<?php print l('', '', array('attributes' => array('id' => 'top'))); ?>

<div class="col730 <?php print $side_2 . ' ' . $classes; ?>">
  <div class="filter">
    <div class="<?php print $side_1; ?>">
        <?php if($view->total_rows != 0) { ?>
            <div id="Sort_by_opp_new"></div>
        <?php } ?>
    </div>
    <?php print t('<strong>!total_rows</strong> items', array('!total_rows' => $view->total_rows)); ?>
  </div>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>
  <div class="content_filter_exposed">
    <?php print $exposed; ?>
  </div>
  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <ul class="opportunities view-content">
      <?php print $rows; ?>
    </ul>
   <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print t("Can't find what you are looking for, !click_here", array('!click_here' => l(t('click here'), 'http://www.jewishagency.org/'), array('external' => true))); ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>

    <?php print str_replace(t('Load More'), t('More opportunities'), $pager); ?>

  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
      <?php print $more; ?>
  <?php endif; ?>


    <div class="view-footer">
    </div>

  <?php if ($feed_icon && (isset($variables['view']->args[2]) && $variables['view']->args[2])) : ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */?>
