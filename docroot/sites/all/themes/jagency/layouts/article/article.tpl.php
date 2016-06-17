<?php
/**
 *
 */
?>
<div class="panel-display panel-threecol-44-35-21-stacked clear-block" <?php if (!empty($css_id)) { print "id=\"$css_id\"";} ?>>
  
  <div class="panel-panel line">
    <div class="panel-panel panel-col-twenty-five unit header-left firstUnit">
      <div class="inside">
        <?php print $content['reg_1']; ?>
      </div>
    </div>
    <div class="panel-panel row panel-col-seventy-five-end">
      <div class="panel-panel panel-seventy-five-middle">
        <div class="inside">
          <?php print $content['reg_6']; ?>
        </div>
      </div>
    </div>
    <div class="panel-panel row panel-col-seventy-five-end">
      <div class="panel-panel panel-col-fifty-middle">
        <div class="inside">
          <?php print $content['reg_2']; ?>
        </div>
      </div>
      
      <div class="panel-panel panel-col-twenty-five-end">
        <div class="inside">
          <?php print $content['reg_3']; ?>
        </div>
      </div>
    </div>
    <div class="panel-panel panel-col-seventy-five-end firstUnit lastUnit">
      <div class="inside">
        <?php print $content['reg_4']; ?>
      </div>
    </div>
  </div>
  
  <div class="panel-panel line">
    <div class="panel-panel unit top-stack lastUnit">
      <div class="inside">
        <?php print $content['reg_5']; ?>
      </div>
    </div>
  </div>
</div>
<script type="text/javascript">
  Drupal.behaviors.articleFix = {
    attach : function(context, settings) {
      if (typeof($) == "undefined") {
        $ = jQuery;
      }
      if ($('.line .panel-col-seventy-five-end .panel-col-twenty-five-end .inside').length) {
        if ($('.line .panel-col-seventy-five-end .panel-col-twenty-five-end .inside .pane-content').length || $('.panels-ipe-region .panels-ipe-placeholder:visible').length) {
          $('.line .panel-col-seventy-five-end .panel-col-fifty-middle').css("width", "515px");
        } else {
          $('.line .panel-col-seventy-five-end .panel-col-fifty-middle').css("width", "730px");
        }
      }
    }
  }
</script>
