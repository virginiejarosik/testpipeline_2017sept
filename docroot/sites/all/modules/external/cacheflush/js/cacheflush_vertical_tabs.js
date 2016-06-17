/**
 * @file
 * Cacheflush Tabs update JS.
 */

(function ($) {
/**
 * Update the summary for the cacheflush module vertical tab.
 */
Drupal.behaviors.vertical_tabs = {
  attach: function (context) {
    $('.page-admin-config-development-cacheflush-preset fieldset', context).drupalSetSummary(function (context) {
      var rez = '';
      var inc = 0;
      if ($(context).attr('id') == 'edit-vertical-tabs-advance') {
        var rows = $('#cacheflush-advanced-settings-table tbody tr', context);
        $.each (rows,function(inx,value){
          if($('input[type="text"]',this).val().trim() && $('select',this).val() != 0) {
            rez = (inc + 1) + ' custom row(s) defined';
            inc++;
          }
        });
      }
      else {
        var inputs = $('input', context);
        var comma = '';
        $.each(inputs,function(i,val){
          if ($(this).attr('checked')) {
            if (inc === 1) {
              comma = ', ';
            }
            rez = rez + comma + $(this).parent().children('label').html().trim();
            inc++;
          }
        });
      }
      if(rez){
        return Drupal.checkPlain(rez, context);
      }
      return Drupal.t('Nothing selected.');
    });
  }
};

})(jQuery);
