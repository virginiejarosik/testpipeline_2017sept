/*
  Custom configuration for ckeditor.
 
  Configuration options can be set here. Any settings described here will be
  overridden by settings defined in the $settings variable of the hook. To
  override those settings, do it directly in the hook itself to $settings.
*/
//CKEDITOR.config.customConfig  = 'http://www.agency.dev/sites/all/modules/ewave/jagency_pages/media/ckeditor_custom_config.js';
//CKEDITOR.on( 'instanceReady', function( evt ) {
//  jQuery.each(jQuery('.cke_skin_kama'), function(i, item) {
    /*CKEDITOR.replace(jQuery(item).attr('id'), {
      //customConfig: '/sites/all/modules/ewave/jagency_pages/media/ckeditor_custom_config.js'
      format_tags: 'h1;h2;h3;h4;h5;h6;p'
    });*/
//  });
//});
CKEDITOR.config.fontSize_sizes = '12px; 14px; 16px; 18px; 20px';
CKEDITOR.config.font_names = 'Baskerville W01 Regular 927184; AvenirNextLTW01-Regular; Arial;';
CKEDITOR.config.contentsCss = 'fonts.css';
CKEDITOR.config.colorButton_colors = '0054A6,666666,737A7F,919191,224F7C,9AB1C8,1CBBB4,A3CC67,E9BA52,F26C4F,ffffff,F8F8F7,3F4E5E,26323F,DFDFDE';
CKEDITOR.stylesSet.add('default', [

    { name: 'H2', element: 'h2', styles: { 'color': '#666', 'font-size': '40px', 'font-family': 'Baskerville W01 Regular 927184, Times New Roman, Serif' } },
    { name: 'H3', element: 'h3', styles: { 'color': '#737A7F', 'font-size': '24px', 'font-family': 'Baskerville W01 Regular 927184, Times New Roman, Serif' } },
    { name: 'H4', element: 'h4', styles: { 'color': '#666', 'font-size': '18px', 'font-family': 'AvenirNextLTW01-Regular, Times New Roman, Serif' } },
    { name: 'H5', element: 'h5', styles: { 'color': '#666', 'font-size': '30px', 'font-family': 'AvenirNextLTW01-Regular, Times New Roman, Serif' } },
    { name: 'Copy', element: 'p', styles: { 'color': '#666', 'font-size': '30px', 'font-family': 'AvenirNextLTW01-Regular, Times New Roman, Serif' } },
    { name: 'Regular', element: 'p', styles: { 'color': '#737A7F', 'font-size': '20px', 'font-family': 'Arial, Helvetica, sans-serif' } },
    { name: 'Links', element: 'a', styles: { 'color': '#224F7C', 'font-size': '12px', 'font-family': 'Arial, Helvetica, sans-serif' } },
    { name: 'Quotes', element: 'span', styles: { 'color': '#fff', 'font-size': '40px', 'font-family': 'Baskerville W01 Regular 927184, Arial, Helvetica, sans-serif' } },
    { name: 'Intro ', element: 'span', styles: { 'color': '#737A7F', 'font-size': '26px', 'font-family': 'AvenirNextLTW01-Regular, Arial, Helvetica, sans-serif' } },

    // Object Styles
    {
        name: 'Image on Left',
        element: 'img',
        attributes: {
            style: 'padding: 5px; margin-right: 5px',
            border: '2',
            align: 'left'
        }
    }
]);

CKEDITOR.on('instanceReady', function (ev) {
    ev.editor.on('paste', function (evt) {
        if (typeof (evt.data['html']) !== 'undefined' && evt.data['html'] != null) {
            //remove all html tags but whitelisted tags
            //evt.data['html'] = (evt.data['html']).replace(/<(?!\/?(p|br|ul|li|b|i|sub|sup|strike|em|strong|span|table|caption|tbody|tr|td)(>|\s))[^<]+?>/g, '');
            // remove font-family, font-size, line-height from style
            //evt.data['html'] = (evt.data['html']).replace(/font-family\:[^;]+;?|font-size\:[^;]+;?|line-height\:[^;]+;?/g, '');
            // remove if style is empty, e.g. style="" || style="   "
            evt.data['html'] = (evt.data['html']).replace(/style\="\s*?"/, '');
            // remove empty tags, e.g. <p></p>
            evt.data['html'] = (evt.data['html']).replace(/<[^\/>][^>]*><\/[^>]+>/, '');

            //remove all styles from tags
            evt.data['html'] = (evt.data['html']).replace(/(<[^>]+) style=".*?"/i, '');
        }
    }, null, null, 9);
});
