
<!--/fixedWrapper -->
<div class="wrapper storyIntro">
  <?php if (user_access('administer nodes')) : ?>
  <ul class="tabs primary">
    <li class="active"><?php print l(t('View'), 'node/' . $node->nid); ?></li>
    <li><?php print l(t('Edit'), 'node/' . $node->nid . '/edit'); ?></li>
    <li><?php print l(t('Node clone'), 'node/' . $node->nid . '/clone'); ?></li>
  </ul>
  <?php endif; ?>
  <figure>
    <?php if ($content['field_main_image_video']) : ?>
      <div class="play playBtn" data-size="980x518" data-href="<?php print $content['field_main_image_video']; ?>"></div>
    <?php endif; ?>
    <?php print render($content['field_main_image']); ?><?php print get_copyright('field_main_image', $node->nid); ?></figure>
  <div class="text">
    <div class="fLeft">
      <?php if(isset($content['field_quote'])) { ?><h4>“<?php print strip_tags(render($content['field_quote'])); ?>”</h4><?php } ?>
    </div>
    <div class="fRight">
      <?php print render($content['field_program_description']);
        if(isset($content['field_link'])) {
          print render($content['field_link']);
        }
       ?>
    </div>
  </div>
</div>
<!--/storyIntro -->
<?php if(isset($content['field_photo_carousel'])) { ?>
  <div class="fsGallery" style="text-align:center; padding:50px 0; clear: both;">
    <?php print render($content['field_photo_carousel']); ?>
  </div>
<?php } ?>
<!--/ -->
<div class="fsPicWrapper">
  <figure class="fsPic">
    <?php if ($content['field_featured_image_video']) : ?>
      <div class="play playBtn" data-size="1400x789" data-href="<?php print $content['field_featured_image_video']; ?>"></div>
    <?php endif; ?>
    <?php print render($content['field_featured_image']); ?><?php print get_copyright('field_featured_image', $node->nid); ?></figure>
</div>
<!--/fsPicWrapper -->
<?php
$q_and_a = render($content['field_q_and_a']);
if(strlen(strip_tags($q_and_a))) { ?>
<div class="wrapper qaBox">
  <h4><?php print t('Q&amp;A'); ?></h4>
  <?php print strip_tags($q_and_a, "<h5><h1><a>"); ?>
</div>
<!--/qaBox -->
<?php } ?>
<div class="shareStory">
  <?php  if(isset($content['field_part2_title']) OR isset($content['field_part3_description'])) { ?>
  <div class="wrapper">
    <div class="text">
      <h4><?php print strip_tags(render($content['field_part2_title'])); ?></h4>
      <p><?php print strip_tags(render($content['field_part3_description'])); ?></p>
    </div>
    <?php if(isset($content['field_2_images'])) { ?>
      <figure><div class="firstimage"><?php print render($content['field_2_images']); ?></div></figure>
    <?php } ?>
    </div>
    <?php } ?>
  <div class="share">
    <h5><?php print t('Share My Story'); ?></h5>          
      <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterFacebook.png')), 'http://www.facebook.com/sharer.php?u=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
      <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterTwitter.png')), 'https://twitter.com/intent/tweet?text=' . rawurlencode(render($node->title)) . '&url=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
      <?php print l(theme('image', array('path' => path_to_theme() . '/images/blogFooterGoogle.png')), 'https://plusone.google.com/_/+1/confirm?url=' . rawurlencode(url('node/' . $node->nid, array('absolute' => true))) .'&title=' . rawurlencode(render($node->title)), array('html' => true, 'external' => true, 'attributes' => array('target' => '_blank'))); ?>&nbsp; &nbsp;
      <div class="fb-like" data-send="false" data-layout="button_count" data-show-faces="false"></div>
  </div>
</div>
<!--/shareStory -->
<?php print render($content['field_more_participant_storys']); ?>
