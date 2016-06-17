<li class="cs<?php print $counter; ?>"><?php print l(t($item['link']['link_title'], array(), array('context' => 'item:' . $item['link']['mlid'] . ':title')), $item['link']['link_path'], array('html' => true)); ?>
  <div class="cs<?php print $counter; ?> drop">
    <dl>
      <dt><?php print isset($item['link']['options']['attributes']['title']) ? t($item['link']['options']['attributes']['title'], array(), array('context' => 'item:' . $item['link']['mlid'] . ':description')) : ''; ?></dt>
      <?php if (count($item['below'])) : ?>
        <?php foreach ($item['below'] as $subitem) : ?>
          <dd><?php print l($subitem['link']['link_title'], $subitem['link']['link_path'], array('html' => true)); ?></dd>
        <?php endforeach; ?>
      <?php endif; ?>
    </dl>
    <?php print $menu_content; ?>
  </div>
</li>