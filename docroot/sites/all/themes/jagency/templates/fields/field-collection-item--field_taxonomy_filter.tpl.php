<?php if(render($content['field_display_widget']) == 1) { ?>
  <dd>
    <h5><?php print render($content['field_filter_label']); ?></h5>
    <div class="drop">
      <?php
        $defaults = array();
        foreach($_GET as $key => $value) {
          if (strpos($key, 'vocabluary_id_') !== false) {
            if ($value) {
              $defaults[] = $value;
            }
          }
        }
        widget_filter_box($field_collection_item->field_vocabulary[LANGUAGE_NONE][0]['target_id'], render($content['field_widget']), render($content['field_any_option']), $defaults); ?>
    </div>
  </dd>
<?php 
  } else {
   //we should do this to hide unneeded staff
  print '<div style="display: none;">' . render($content) . '</div>'; 
  } 
?>