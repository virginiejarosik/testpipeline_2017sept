<div class="wrapper MapsLocations">
  <?php if($field_map_type == 'map730') { ?>
  <h3><?php print $title; ?></h3>
  <div id="map730"></div>
  <!--<p class="tRight s14"><?php //print l(theme('image', array('path' => path_to_theme() . '/images/link.png')) . 'View Entire Map', '', array('html' => true)); ?></p>-->
  <?php } elseif($field_map_type == 'map480') { ?>
  <h2><?php print $title; ?></h2>
  <div class="">
  <div class="fLeft" id="map480"></div>
  <div class="LocationSide fRight">
    <ul id="locations" class="locations">
      <?php print render($content['field_events']); ?>
    </ul>
    
<div class="holder"></div>
  <div class="paging">
    <span class="pagingArrowL"></span>
    <span id="page_count"></span>
    <span class="pagingArrowR"></span>
  </div>
  </div>
  </div>
  <?php } ?>
</div>