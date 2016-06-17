jQuery(document).ready(function($) {
  jQuery.Mason.settings.isRTL = Drupal.settings.isRTL;
  jQuery.Mason.settings.gutterWidth = 6; 
  var $container = $('.blogs');
  jQuery('#contributors li').hover(
    function () {
      var self = $(this);
      var image = self.find('img');
      image.attr('src', image.attr('src').replace('authors_small_image_bw', 'authors_small_image'));
      var clone = self.find('.conToolTip').clone();
      var scroll = jQuery('#contributors').data('jsp').getPercentScrolledY();
      self.parents('.blogsRightBoxInner').append(clone.css('display', 'block'));
      var counter = self.prevAll().length % 4;
      var position = self.position();
      var rtl_pos = Drupal.settings.isRTL ? 'right' : 'left';
      
      jQuery('.blogsRightBoxInner > .conToolTip').css('top', position.top + 67);
      switch(counter) {
        case 1:
          jQuery('.blogsRightBoxInner > .conToolTip .popupArrowUp').css(rtl_pos, '42px');
          break;
        case 2:
          jQuery('.blogsRightBoxInner > .conToolTip .popupArrowUp').css(rtl_pos, '96px');
          break;
        case 3:
          jQuery('.blogsRightBoxInner > .conToolTip .popupArrowUp').css(rtl_pos, '150px');
          break;
      }
    },
    function () {
      var image = $(this).find('img');
      image.attr('src', image.attr('src').replace('authors_small_image/', 'authors_small_image_bw/'));
      jQuery('.blogsRightBoxInner > .conToolTip').remove();
    }
  );
  
  jQuery.each(jQuery('.blogArticle .file-blog-entry-content-image'), function (i, item) {
    var item = jQuery(item);
    var regex = /blogArticleLink_(.*)/;
    var color = regex.exec(jQuery('.blogArticleLink').attr('class'))[1];
    item.parent().append('<span>' + item.attr('title') + '</span>').addClass('imageCaption imageCaption_' + color);
  });
  
  jQuery('.playBtn').click(function(event) {
    var id = jQuery(this).attr('data-href').replace('youtube://v/', '');
    var size = jQuery(this).attr('data-size').split('x');
    jQuery(this).after('<div class="videoframe"><iframe width="' + size[0] + '" height="' + size[1] + '" src="http://www.youtube.com/embed/' + id + '?autoplay=1&autohide=1&controls=0&wmode=opaque" frameborder="0" allowfullscreen></iframe></div>');
    jQuery('#articleGallery').data('AnythingSlider').options.resumeDelay = jQuery('#articleGallery').data('AnythingSlider').options.delay = 99999999;
    jQuery('#articleGallery').data('AnythingSlider').endAnimation();
    jQuery('#articleGallery').data('AnythingSlider').clearTimer();
    jQuery('#articleGallery').data('AnythingSlider').startStop();
    event.preventDefault();
    return false;
  });
  
  $('#search_submit').click(function() {
    location.href = Drupal.settings.basePath + 'search/' + $('#search').val();
  });
  
  $('.pager-load-more a').live('click', function() {
    var element = $(this);
    var path = element.attr('href');
    var parent = element.parents('.item-list');
    var target = parent.prev();
    var target_class = target.attr('class').split(/\s+/);
    $.get(path, function(data) {
      var blog_elements = $(data).find('.' + target_class[0]);
      var $elements = blog_elements.children();
      parent.html(blog_elements.next().html());
      target.append($elements);
      target.masonry('appended', $elements, true);
      setTimeout(blogs, 1);
      FB.XFBML.parse(jQuery('.blogs').get(0));
    });
    return false;
  });
  
  $('#languages').change(function() {
    // set the window's location property to the value of the option the user has selected
    window.location = $(this).val();
  });
  
  // Start - Search Autocomplete
  $(function() {
    $("#search").autocomplete({
      ///source: Drupal.settings.basePath + 'search/json/?response_type=json',
      source: function( request, response ) {
        $.ajax({
          url: Drupal.settings.basePath + 'search/json/' + encodeURIComponent(request.term) + '?response_type=json',
          dataType: "json",
          success: function( data ) {
            $("#search").data('search-result', data.nodes);
            response($.map( data.nodes, function( node ) {
              return {
                label: node.node.title,
                value: node.node.title
              };
            }));
          },
        });
      },
      minLength: 3,
      select: function( event, ui ) {
        if (ui.item.label) {
          var data = $("#search").data('search-result');
          $.each(data, function(i, element) {
            if (element.node.title == ui.item.value) {
              location.href = element.node.path;
              return false;
            }
          });
        }
      }
    });
  });
  // End - Search Autocomplete

  // Start - More Posts
  $('.moreBlogsBtn').bind('click', function() {
    $('.morePosts').slideDown('slow');
  });
  // End - More Posts

  function blogs() {
    var blogs = $('.blogs').find('article');
    $.each(blogs, function(i) {
      if ($(this).css('left') == '362px') {
        $(this).css('margin-left', '6px');
      }
    });
  }
  
  $('.blogs').masonry({
    itemSelector : 'article'
  });
  blogs();
  
  $('.moreBlogsBtn').bind('click', function() {
    var $newElems = $('.moreBlogs').children("article");
    $(".blogs").append($newElems);
    $('.moreBlogs').remove();
    $container.masonry('appended', $newElems, true);
    blogs();
  });
});

jQuery(function() {
  jQuery('#contributors, #categories').jScrollPane({
    scrollbarWidth : 6,
    scrollbarMargin : 8
  });
});

jQuery(function() {
  jQuery('select#languages').selectmenu({
    style : 'dropdown'
  });
});

jQuery(function() {
  jQuery('#articleGallery').anythingSlider({
      easing: 'swing',
      autoPlayLocked: true,
      hashTags:false,
      delay: 15000,
      toggleArrows: true,
      onInitialized: function (e, slider) {
          var anythingSliderWidth = jQuery('.anythingSlider').width() / 2;
          var anythingControlsWidth = jQuery('.anythingControls').width() / 2;
          jQuery('.anythingControls').css('right', anythingSliderWidth - anythingControlsWidth);
      },
      onSlideInit: function (e, slider) {
          jQuery('.carouselCaption span, .carouselCaption p').fadeOut("normal").hide();
      },
      onSlideComplete: function (slider) {
          jQuery('.carouselCaption span, .carouselCaption p').fadeIn("normal").show();
      }
  });
});

function closeSubscribe() {
  jQuery( '#dialog').dialog( 'destroy');
}

function GetSubscribe(nid) {
  jQuery('#dialog').dialog({
    height: 240,
    width: 656,
    modal: true,
    resizable: false,
    draggable: false,
    open:  function() {
      jQuery('#subscribe').append('<a href="javascript:closeSubscribe()" class="closeModal"></a><iframe src="' + Drupal.settings.basePath + 'subscribe/?response_type=embed&foo='+ nid + '" frameborder="0" height="200" width="630" scrolling="no"></iframe>');
    },
    close: function() {
      jQuery( "#dialog" ).dialog( "destroy" );
    }
  });
}

function agencyCommentUpdate() {
  jQuery.each(jQuery('.fb-comments-count'), function (i, element) {
    element = jQuery(element);
    if (parseInt(element.text(), 10) != 0) {
      element.removeClass('hidden');
      element.prev().removeClass('hidden');
    }
  });
}
