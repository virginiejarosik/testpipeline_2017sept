<?php
/**
 * @file
 * Default print module template
 *
 * @ingroup print
 */
$theme_path = url(drupal_get_path('theme', 'jagency'));
//d(array_keys($print), $print ['css']);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $print['language']; ?>" xml:lang="<?php print $print['language']; ?>">
  <head>
    <?php print $print['head']; ?>
    <?php print $print['base_href']; ?>
    <title><?php print $print['title']; ?></title>
    <?php print $print['sendtoprinter']; ?>
    <?php print $print['robots_meta']; ?>
    <?php print $print['favicon']; ?>
    <?php print $print ['css']; ?>
    <style type="text/css" media="all">
      @import url("<?php print $theme_path; ?>/css/header.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/footer.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/theJewishAgency.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/nav.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/menu.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/anythingslider.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/jquery.jscrollpane.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/ui.selectmenu.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/leftColumn.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/popups.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/rightColumn.css?mh4s9g");
      @import url("<?php print $theme_path; ?>/css/jquery-ui-1.9.2.custom.css?mh4s9g");
    </style>
    <link rel="stylesheet" type="text/css" href="<?php print url($theme_path . '/css/style.css'); ?>">
  </head>
  <body>
<div class="wrapper print-wrapper" id="main">
  <div id="main-content" role="main">
    <div class="container">
    <?php if (!empty($print['message'])) {
      print '<div class="print-message">'. $print['message'] .'</div><p />';
    } ?>
    <div class="print-logo"><?php print $print['logo']; ?></div>
    <div class="print-site_name"><?php print $print['site_name']; ?></div>
    <p />
    <div class="print-breadcrumb"><?php print $print['breadcrumb']; ?></div>
    <hr class="print-hr" />
    <div class="blogArticle">
  <?php print l($category->name, 'term/' . $category->tid, array('attributes' => array('class' => array('blogArticleLink', 'blogArticleLink_' . $color)))); ?>
  <h4><?php print render($node->title); ?></h4>
  <p class="fs18"><?php print strip_tags(render($print['field_teaser']),'<strong><b><i><u><span><ul><li>'); ?></p>
  <article>
      <?php print $print['content']; ?>
  </article>
  
  <div class="blogArticleFooter">
      <span class="footnote">
          <?php print format_date($node->created, 'blog'); ?> / <?php print convert_jew_date($node->created); ?>
          <?php print theme('image', array('path' => $theme_path . '/images/blogFooterComment.png')); ?>
          <strong class="fb-comments-count" data-href="<?php print url( 'node/' . $node->nid); ?>">0</strong>
      </span>
      <?php //print render($print['links']); ?>
      <ul>
          <li><span><?php print t('Share'); ?></span></li>
          <li><?php print l(theme('image', array('path' => $theme_path . '/images/blogFooterFacebook.png')), '', array('html' => true)); ?></li>
          <li><?php print l(theme('image', array('path' => $theme_path . '/images/blogFooterTwitter.png')), '', array('html' => true)); ?></li>
          <li><?php print l(theme('image', array('path' => $theme_path . '/images/blogFooterGoogle.png')), '', array('html' => true)); ?></li>
      </ul>
  </div>
  <?php
    module_load_include('module', 'jagency_users');
    print jagency_authors_custom_user_block($node->uid);
  ?>
</div>
    <div class="print-footer"><?php print $print['footer_message']; ?></div>
    <hr class="print-hr" />
    <div class="print-source_url"><?php print $print['source_url']; ?></div>
</div>
</div>
</div>
    <?php print $print['footer_scripts']; ?>
    <script>
      window.print();
    </script>
  </body>
</html>
