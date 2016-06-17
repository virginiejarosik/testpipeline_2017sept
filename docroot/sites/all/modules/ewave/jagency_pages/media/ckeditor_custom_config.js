CKEDITOR.editorConfig = function( config ) {
  config.format_tags = 'h1;h2;h3;h4;h5;h6;p';
  config.format_h1 = { element: 'h1', attributes: { 'class': 'h1' } };
  config.format_h2 = { element: 'h2', attributes: { 'class': 'h2' } };
  config.format_h3 = { element: 'h3', attributes: { 'class': 'h3' } };
  config.format_h4 = { element: 'h4', attributes: { 'class': 'h4' } };
  config.format_h5 = { element: 'h5', attributes: { 'class': 'h5' } };
  config.format_h6 = { element: 'h6', attributes: { 'class': 'h6' } };
  config.format_p = { element: 'p', attributes: { 'class': 'text' } };
};
alert(1);
