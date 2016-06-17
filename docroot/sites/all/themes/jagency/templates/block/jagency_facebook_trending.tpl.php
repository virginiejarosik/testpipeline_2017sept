<h2>
    <?php print t('Trending'); ?>
    <?php
      $link = variable_get('fb_trending_link', '');
      if ($link) {
        print l(theme('image', array('path' => path_to_theme() . '/images/facebookIcon.jpg')), $link, array('html' => true));
      } 
    ?>
</h2>
<div class="blogsRightBoxInner">
  <ul class="trending">
    <?php 
      if (is_array($fb_trending)) {
        foreach($fb_trending as $item) {
          print '<li>' . $item . '</li>';
        }
      }
    ?>
  </ul>
</div>