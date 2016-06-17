Drupal.behaviors.agencyMapList = {
  attach : function(context, settings) {
    if (typeof($) == "undefined") {
      $ = jQuery;
    }
    jQuery('div.holder').jPages({
      containerID : 'locations', 
      perPage: 5, 
      first : false, 
      previous : 'span.pagingArrowL', 
      next : 'span.pagingArrowR', 
      last : false,
      links : 'blank',
      callback : function( pages, items ) {
        $('#page_count').html(Drupal.t('Page @current of @total', {'@current': pages.current, '@total': pages.count}));
      } 
    });
  }
};