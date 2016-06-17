<div class="wrapper">
  <div class="subscribe">
    <?php 
      if (isset($rss_link)) {
        print l(theme('image', array('path' => drupal_get_path('theme', 'jagency') . '/images/subscribe-rss.png')), $rss_link, $rss_link_args); 
      } 
       if (isset($mail_link)) {
        print l(theme('image', array('path' => drupal_get_path('theme', 'jagency') . '/images/subscribe-mail.png')), $mail_link, $mail_link_args); ?><br /><?php print t('SUBSCRIBE');
       }
     ?>
  </div>
  <?php if (isset($title)) { ?>
  <h1>
  <?php
    if ($url) {
      print l($title, $url, array('attributes' => array('class' => array('logo'))));
    } else {
      print $title;
    }
  ?></h1>
  <?php 
    } if (isset($intro)) { print $intro; }
   ?>
</div>
<div id="dialog" title="Subscribe" style="display: none; overflow: hidden;">
  <div id="subscribe"></div>
</div>