<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['navigation']: Items for the navigation region, below the main menu (if any).
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['footer']: Items for the footer region.
 * - $page['bottom']: Items to appear at the bottom of the page below the footer.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
$fb_app_id = variable_get('fb_application_id', '');
if ($fb_app_id) :
?>
<div id="fb-root"></div>
<div class="hidden">
  <script type="text/javascript">
  /* <![CDATA[ */
  var google_conversion_id = 1032331925;
  var google_custom_params = window.google_tag_params;
  var google_remarketing_only = true;
  /* ]]> */
  </script>
  <script type="text/javascript" src="//www.googleadservices.com/pagead/conversion.js">
  </script>
  <noscript>
  <div style="display:inline;">
  <img height="1" width="1" style="border-style:none;" alt="" src="//googleads.g.doubleclick.net/pagead/viewthroughconversion/1032331925/?value=0&amp;guid=ON&amp;script=0"/>
  </div>
  </noscript>
</div>
<script>
  window.fbAsyncInit = function() {
    // init the FB JS SDK
    FB.init({
      appId      : <?php print $fb_app_id; ?>, // App ID from the App Dashboard
      status     : true, // check the login status upon init?
      cookie     : true, // set sessions cookies to allow your server to access the session?
      xfbml      : true  // parse XFBML tags on this page?
    });
    FB.Event.subscribe("xfbml.render", agencyCommentUpdate);
  };
  (function(d, debug){
     var js, id = 'facebook-jssdk', ref = d.getElementsByTagName('script')[0];
     if (d.getElementById(id)) {return;}
     js = d.createElement('script'); js.id = id; js.async = true;
     js.src = "//connect.facebook.net/en_US/all" + (debug ? "/debug" : "") + ".js";
     ref.parentNode.insertBefore(js, ref);
   }(document, /*debug*/ false));
</script>
<?php endif; ?>
<header>
  <?php print render($page['header']); ?>
    <div class="wrapper">
        <ul class="headNav">
          <?php
            $domain = domain_get_domain();
            $menutype = domain_conf_variable_get($domain['domain_id'], 'menu_top_links_source');
            if (!$menutype) {
              $menutype = 'menu-top-menu'; 
            }
            $items = menu_tree_all_data($menutype, $link = NULL, $max_depth = 1);
            foreach($items as $key => $value)  {
              print '<li>' .  l($value['link']['link_title'], $value['link']['link_path'], $value['link']['options']) . '</li>';
            }
          ?>
        </ul>
        
        <div class="search ui-widget">
            <input id="search" type="text" value="<?php print t('Search'); ?>" />
            <button id="search_submit"><?php print t('Search'); ?></button>
            <div id="menu-container" style="position:absolute; width: 170px;"></div>
        </div>
        
        <div class="languages"><?php print jagency_menu_languages(); ?></div>
    </div>
</header>
<?php print render($page['navigation']); ?>
<menu>
<?php if ($logo): ?>
  <?php print l(theme('image', array('path' => $logo)), '', array('html' => true, 'attributes' => array('title' => t('Home'), 'class' => 'logo', 'rel' => 'home'))); ?>
<?php endif; ?>
<ul><?php print jagency_main_menu(); ?></ul>
</menu>
  <!--/nav --> 
<!--/header -->
<?php if($breadcrumb) : ?>
  <div class="breadCrumbs">
  <?php print $breadcrumb; ?>
  </div>
  <!--/breadcrumbs -->
<?php endif; ?>

<?php print render($page['topcontent']); ?>

<div id="main">
  <div id="main-content" role="main">
    <?php print render($page['highlighted']); ?>
    <a id="main-content-anchor"></a>
    <?php print render($tabs); ?>
    <?php print render($page['help']); ?>
    <?php if ($action_links): ?>
      <ul class="action-links"><?php print render($action_links); ?></ul>
    <?php endif; ?>
    <section class="leftColumn">
    <?php print render($page['content']); ?>
    </section>
  </div>

  <?php if (render($page['sidebar_first']) || render($page['sidebar_second'])): ?>
    <aside>
      <?php print render($page['sidebar_first']); ?>
      <?php print render($page['sidebar_second']); ?>
    </aside>
  <?php endif; ?>
</div>
<?php print render($page['google_map']); ?>
<footer>
    <?php print render($page['footer']); ?>
    <div class="top">
      <div class="wrapper">
        <ul>
           <?php
           print render($social_networks['content']);
           ?>
           <li><div class="fb-like" data-href="<?php print url('', array('absolute' => true)); ?>" data-send="false" data-layout="button_count" data-width="450" data-show-faces="true"></div></li>
        </ul>
        <p class="contactUsFooter">
           <?php
           print strip_tags(render($phone_number['content']), "<span><strong><a><img>");
           ?>
        </p>
      </div>
    </div>
    
    <section class="nav">
      <?php print jagency_footer_top_menu(); ?>
    </section>
    
    <div class="bottom">
        <?php print jagency_footer_content(); ?>
        <ul class="link">
          <?php
          $items = menu_tree_all_data('menu-footer', $link = NULL, $max_depth = 1);
          foreach($items as $key => $value) :
            if ($value['link']['hidden'] == 0) {
              print '<li>'. l(t($value['link']['link_title']), $value['link']['link_path']) . '</li>';
            }
          endforeach;
          ?>
        </ul>
    </div>
    <?php print render($page['bottom']); ?>
  </div>
</footer>
<!--/footer --> 