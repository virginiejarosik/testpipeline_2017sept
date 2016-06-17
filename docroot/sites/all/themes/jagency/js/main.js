//static variables
var agentlist = [];
var video_playing = false;

Drupal.behaviors.agencyTop = {
  attach : function(context, settings) {
    
    // fix bookList for executive-members/{params}
    jQuery('.bookList').find('li').addClass('col-sm-4');

    if (typeof($) == "undefined") {
      $ = jQuery;
    }
    jQuery.Mason.settings.isRTL = Drupal.settings.isRTL;
    jQuery.Mason.settings.gutterWidth = 6;
    
    if ($('.newsList').length) {
     if ($('.newsList').width() <= 480) {
       $('.newsList').addClass('newsList-small');
     } 
    }
    
    $('.view-agency-views-field-dynamic-view .feed-icon').bind('click', function() {
      location.href = $(this).find('a').attr('href');
    });
    
    if ($('#views-exposed-form-opportunities-page').length) {
      $('#views-exposed-form-opportunities-page #edit-keys').unbind('keyup');
    }
    if ($('#panels-createnode-content-type-edit-form').length) {
      var loadCSS = function(href) {
        var cssLink = jQuery("<link rel='stylesheet' type='text/css' data='createnode-fix' href='"+href+"'>");
        jQuery("head").append(cssLink); 
      };
      var unloadCSS = function(href) {
        var cssLink = jQuery("<link rel='stylesheet' type='text/css' href='"+href+"'>");
        jQuery("head").append(cssLink); 
      };
      loadCSS('/sites/all/libraries/select2/select2.css');
      loadCSS('/sites/all/modules/external/select2widget/css/select2widget.css');
      loadCSS('/themes/seven/style.css');
      loadCSS('/themes/seven/vertical-tabs.css');
    } else {
      jQuery('link[data="createnode-fix"]').remove();
    }
    
    
    if ($('.picList480.splitList').length && $('.picList480.splitList').width() < 960) {
      $('.picList480.splitList').addClass('splitListFix');
    }
    //disable on enter submit for content filter form
    $('.fRight.view-filters  form').live("keypress", function(e) {
      var code = e.keyCode || e.which; 
      if (code  == 13) {
        $('.fRight.view-filters form input[type="submit"]').trigger('click');
        e.preventDefault();
        return false;
      }
    });
    
    //aliyahServices with free geoip service
    if ($('.aliyahServices').length) {
      if ($('.aliyahServices').width() != 980) {
        $('.aliyahServices .fRight').hide();
        $('.aliyahServices .fLeftWrapper').css({"width": "85%", "margin": "15px 0"});
        $('#aliyahservices_center, #aliyahservices_manager').css('display', 'block');
        $('#moving-menu').css('width', 'auto !important');
      } else {
        $('#moving-menu').addClass('width480');
      }
      $('#moving').change(function() {
        var mycountry = $(this).val().toLowerCase();
        if (typeof(agentlist.agents) == "object") {
            $.each(agentlist.agents, function(i, agent) {
              if (mycountry == agent.City.toLowerCase()) {
                $('#aliyahservices_manager').html('<strong>' + agent.title + '</strong> | <a href="mailto:' + agent.Email + '">' + agent.Email + '</a>');
                $('#aliyahservices_center').html('<strong>' + agent.Help_phone + '</strong> | <a href="mailto:' + agent.Help_email + '">' + agent.Help_email + '</a>');
              }
            });
          } else {
            $.getJSON(Drupal.settings.basePath + 'ajax/aliyahservices/all', function(data) {
              agentlist = data;
              $.each(agentlist.agents, function(i, agent) {
                if (mycountry === agent.Country.toLowerCase()) {
                  $('#aliyahservices_manager').html('<strong>' + agent.title + '</strong> | <a href="mailto:' + agent.Email + '">' + agent.Email + '</a>');
                  $('#aliyahservices_center').html('<strong>' + agent.Help_phone + '</strong> | <a href="mailto:' + agent.Help_email + '">' + agent.Help_email + '</a>');
                }
              });
            });
          }
      });
      
      //lets found country of visitior
      $.getJSON("http://freegeoip.net/json/",
        function(data){
          var dataflag = false;
          var mycountry = data.country_name.toLowerCase();
          //$('#moving optgroup[label!=' + data.country_name + ']').remove();
          $('#moving').selectmenu();
          $('#moving').next('#moving-button').find('.ui-selectmenu-text').text(data.country_name);
          if (typeof(agentlist.agents) == "object") {
            $.each(agentlist.agents, function(i, agent) {
              if (mycountry === agent.Country.toLowerCase()) {
                dataflag = true;
                $('#aliyahservices_manager').html('<strong>' + agent.title + '</strong> | <a href="mailto:' + agent.Email + '">' + agent.Email + '</a>');
                $('#aliyahservices_center').html('<strong>' + agent.Help_phone + '</strong> | <a href="mailto:' + agent.Help_email + '">' + agent.Help_email + '</a>');
              }
            });
          } else {
            $.getJSON('/ajax/aliyahservices/all', function(data) {
              agentlist = data;
              $.each(agentlist.agents, function(i, agent) {
                if (mycountry === agent.Country.toLowerCase()) {
                  dataflag = true;
                  $('#aliyahservices_manager').html('<strong>' + agent.title + '</strong> | <a href="mailto:' + agent.Email + '">' + agent.Email + '</a>');
                  $('#aliyahservices_center').html('<strong>' + agent.Help_phone + '</strong> | <a href="mailto:' + agent.Help_email + '">' + agent.Help_email + '</a>');
                }
              });
            });
          }
          if (dataflag == false) {
            $('#aliyahservices_manager').html('');
            $('#aliyahservices_center').html('');
          }
      });
    }
        
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
    
    if ($('aside > .region-sidebar-first').length) {
      var position = $('#block-system-main .wrapper').offset();
      if (position != undefined) {
        $('#main').css('position', 'relative');
        if (Drupal.settings.isRTL) {
          $('aside > .region-sidebar-first').css({'position': 'absolute', 'top': 0, 'right': position.left + 750 + 'px'});
        } else {
          $('aside > .region-sidebar-first').css({'position': 'absolute', 'top': 0, 'left': position.left + 750 + 'px'});
        }
      }
    }
        
    jQuery('#contributors, #categories').jScrollPane({
      scrollbarWidth : 6,
      scrollbarMargin : 8,
      scrollToRight: Drupal.settings.isRTL
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
        if (target.data('masonry') != "undefined") {
          target.masonry('appended', $elements, true);
          setTimeout(blogs, 1);
          FB.XFBML.parse(jQuery('.blogs').get(0));
        }
      });
      return false;
    });
    
    if($('.opportunityConfigWrapper .fLeft').height() < $('.opportunityConfigWrapper .fRight').height()){      
      var calHeight = $('.opportunityConfigWrapper .fRight').height() - $('.opportunityConfigWrapper .fLeft dl').height();
      $('.opportunityConfigWrapper .stickyWrapper').height(calHeight - 20);  
    }
    
    $('.toTop').stickyfloat();
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
  
    if ($('.opportunityConfigWrapper').length) {
      $.each($('.form-item-field-what-do-you-want-to-do-target-id .form-item input:checkbox'), function(i, elem) {
        if ($(elem).attr('checked') && $(elem).next('label').length) {
          $(elem).next('label').addClass('active');
        }
      });
    }
    
    if ($('#views-exposed-form-opportunities-page .form-item-term-node-tid-depth').length) {
      if ($('#custom_special_interest').length == 0) {
        $('#views-exposed-form-opportunities-page .form-item-term-node-tid-depth').hide();
        $('#views-exposed-form-opportunities-page .form-item-term-node-tid-depth').after('<div><input type="text" id="custom_special_interest"></div>');
      }
    }
    
    $('#Sort_by_opp_new').html($('#edit-sort-by').clone());
    $('#Sort_by_opp_new .form-select').val($('#edit-sort-by').val());
    $('#Sort_by_opp_new select').selectmenu();
    $('#Sort_by_opp').hide();
    
    $('#Sort_by_opp_new .form-select').change(function() {
      $("#Sort_by_opp .form-select").val($(this).val());
      $("#Sort_by_opp .form-select").change();
    });
    
    $('.edit-term-node-tid-depth ul.keywords li button').click(function() {
      var val = $(this).siblings('a').attr('rel');
      $('.edit-term-node-tid-depth input:checkbox[value=' + val + ']').removeAttr('checked', 'checked').change();
      $(this).parent('li').remove();
     return false;
    });
    if ($('.edit-term-node-tid-depth .ui-helper-hidden-accessible').length) {
      var text_special_interest = $('.form-item-edit-term-node-tid-depth-' + $('.edit-term-node-tid-depth .ui-helper-hidden-accessible').text()).find('label').text();
      $('#custom_special_interest').attr('placeholder', text_special_interest).data('placeholder', text_special_interest);
      $('#custom_special_interest').bind('focus', function () {
          $('#custom_special_interest').attr('placeholder', '');
      });
      $('#custom_special_interest').bind('blur', function () {
          if ($('#custom_special_interest').data('placeholder')) {
            $('#custom_special_interest').attr('placeholder', $('#custom_special_interest').data('placeholder'));
          }
      });
      if ($('#custom_special_interest').is(':focus')) {
        $('#custom_special_interest').blur();
      }
    }
    function imAutocompleteJSONParse() {
        var result = [];
        $.each($('.bef-checkboxes', $('.edit-term-node-tid-depth')).children(), function(index, elem) {
          result.push({value: $(elem).find('input[type="checkbox"]').val(), label: $(elem).find('label.option').text()});
        });
        return result;
    }
    
   if(typeof($("#custom_special_interest") != "undefined") && $("#custom_special_interest").length) {
     $("#custom_special_interest").autocomplete({
          source: imAutocompleteJSONParse(),
          focus: function( event, ui ) {
            $( ".edit-term-node-tid-depth #custom_special_interest" ).val( ui.item.label );
            return false;
          },
          select: function (event, ui) {
            if($('.edit-term-node-tid-depth ul.keywords li a[rel=' + ui.item.value + ']').length === 0) {
              $('.edit-term-node-tid-depth input:checkbox[value=' + ui.item.value + ']').attr('checked', 'checked').change();
              $('.edit-term-node-tid-depth ul.keywords').append('<li><a href="#" rel="' + ui.item.value + '">' + ui.item.label + '</a><button></button></li>');
            }
            $('.edit-term-node-tid-depth #custom_special_interest').val('');
            event.preventDefault();
          }
      });
   }

   $('#clear_all_keywords').click(function() {
     $('.edit-term-node-tid-depth input:checkbox').removeAttr('checked', 'checked').change();
     $('.edit-term-node-tid-depth ul.keywords').html('');
     $(".opportunityConfig dd .edit-edit-term-node-tid-depth label").removeClass("active");
     $(".opportunityConfig dd .edit-edit-term-node-tid-depth input[type='checkbox']").attr('checked', false).trigger('change');
     return false;
   });
   /* $(".opportunityConfig dd .edit-term-node-tid-depth #clear_all_keywords").click(function() {
      $(".opportunityConfig dd .edit-term-node-tid-depth label").removeClass("active");
      $(".opportunityConfig dd .edit-term-node-tid-depth input[type='checkbox']").attr('checked', false).trigger('change');
      return false;*/

/* $(".opportunityConfig dd .edit-field-age-group-target-id #age_group_clear").click(function() {
 $(".opportunityConfig dd .edit-field-age-group-target-id label").removeClass("active");
 $(".opportunityConfig dd .edit-field-age-group-target-id input[type='checkbox']").attr('checked', false).trigger('change');
 return false;
 });*/


    $(function () {
      
      $(".membersList .toggleText").click(function() {
        var txt = $(this).text() == 'Read More' ? 'Close' : 'Read More';
        $(this).toggleClass("active").text(txt);
        var pos = $(this).parent().parent().offset().top;
        var section = $(this).prev(".collapsibleText");
        var h = $(this).prev(".collapsibleText").height();
        var realH = $(section).css("height", "auto");
        if ($(section).height() != h) {
          //newHeight = $(section).data(realH);
          //$(section).animate({ height: newHeight }, "slow")
          //$(section).height(realH)
          $(section).animate({
            height : realH
          }, "fast");
        } else {
          $(section).animate({
            height : "92px"
          }, "fast");
          $('html, body').animate({
            scrollTop : pos
          }, 200);
        }
        return false;
      });
      
        $('#slider').movingBoxes({
            initAnimation: false,
            stopAnimation: true,
            speed: 400,
            delayBeforeAnimate: 300,
            startPanel: 2,
            wrap: false,
            buildNav: true
        });
    
        var sum = $('.mb-slider li').length;
        $('.carouselGallery .mb-wrapper').after('<p class="count"><span>of</span>&nbsp;&nbsp;&nbsp;<span>' + sum + '</span></p>');
    });
    if ($(window).width() > 768) {
      jQuery('#articleGallery').anythingSlider({
        easing: 'swing',
        autoPlayLocked: true,
        hashTags:false,
        delay: 15000,
        toggleArrows: true,
        isVideoPlaying: function (slider) {
            return window.video_playing;
        },
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
    }
    //button location fix
    $.each($('.playBtn'), function(counter, elem) {
      elem = $(elem);
      var parent = elem.parent();
      var left = parseInt((parent.width() / 2 - (elem.width() / 2)), 10);
      var top = parseInt((parent.height() / 2 - (elem.height() / 2)), 10);
      elem.css({'left': left + 'px', 'top': top + 'px'});
    });
    
    $('.playBtn').click(function(event) {
      var href = $(this).attr('data-href');
      var type = id = frame = '';
      var Controller = 0;
      var size = $(this).attr('data-size').split('x');
      if (href.match(/youtube\:\/\/v/i)) {
        id = href.replace('youtube://v/', '');
        if($(this).hasClass('controller')) {
          var Controller = 1;
        }
        frame = '<iframe width="' + size[0] + '" height="' + size[1] + '" src="http://www.youtube.com/embed/' + id + '?autoplay=1&autohide=1&controls=' + Controller + '&wmode=opaque" frameborder="0" allowfullscreen></iframe>';
      } else if (href.match(/vimeo\.com\//i)) {
        id = href.split('/');
        frame = '<iframe width="' + size[0] + '" height="' + size[1] + '" src="http://player.vimeo.com/video/' + id[3] + '?title=0&amp;byline=0&amp;portrait=0&amp;color=c9ff23&amp;autoplay=1" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';
      }
      $(this).after('<div class="videoframe">' + frame + '</div>');
      window.video_playing = true;
      event.preventDefault();
      return false;
    });
  
    //search
    $("input#search, input#search_page, input#edit-keys").focus(function() {
        $(this).val(''); 
    });

    $("input#search, input#search_page, input#edit-keys").blur(function() {
      if ($(this).val() == "") {
        $(this).val(Drupal.t("Search"));
      }
    });
    
    $("header .user button, header .languages button").unbind().click(function(e) {
      // event.preventDefault();
      var menu = $(this);
      if (menu.next("ul").css('display') == 'block'){
        console.log("yes");
        $(this).removeClass("active").next("ul").slideUp("slow");
      } 
      else{
        console.log(menu.next("ul").css('display'));
        $(this).addClass("active").next("ul").slideDown("slow");
      }

    });
    $("header .user button, header .languages button").blur(function() {
      setTimeout(function() {$("header .user button, header .languages button").removeClass("active").next("ul").slideUp('fast');}, 500);
      return false;
    });
    ///////////////////////
    if ($('#panels-createnode-content-type-edit-form').length == 0) {
      $('select').selectmenu();
    }
    ///////////////////////
    $(".qaList dt").click(function() {
      $(this).toggleClass("active").next("dd").slideToggle();

    });
    
    $('#search').keypress(function(event) {
        if (event.which == 13) {
            event.preventDefault();
            location.href = Drupal.settings.basePath + 'search/' + $('#search').val();
        }
    });
    
    $('#search_submit').click(function() {
      location.href = Drupal.settings.basePath + 'search/' + $('#search').val();
    });

    $('#search_page_submit').click(function() {
      location.href = Drupal.settings.basePath + 'search/' + $('#search_page').val();
    });
    
    /*$("#search").autocomplete({
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
              }
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
    });*/
  }
};

Drupal.behaviors.agencyInit = {
  attach : function(context, settings) {
    if ($(window).width() > 768) {
      $('#gallery').anythingSlider({
        easing : 'swing',
        autoPlayLocked : true,
        hashTags : false,
        delay : 5000,
        //toggleControls: true,
        toggleArrows : true,
        onInitialized : function(e, slider) {
          var anythingSliderWidth = $('.anythingSlider').width() / 2;
          var anythingControlsWidth = $('.anythingControls').width() / 2;
          $('.anythingControls').css('right', anythingSliderWidth - anythingControlsWidth);
          setupSwipe(slider);
        },
        isVideoPlaying: function (slider) {
            return window.video_playing;
        },
        onSlideInit : function(e, slider) {
          if ($(".gallery980").find(".picText.right").length) {
            $(".gallery980").find(".picText.right").animate({
              right : 10,
              opacity : 0
            }, 350).hide();
          }
          if ($(".gallery980").find(".picText.left").length) {
            $(".gallery980").find(".picText.left").animate({
              left : 10,
              opacity : 0
            }, 350).hide();
          }
          if ($(".gallery980").find(".text").length) {
            $(".gallery980").find(".text").animate({
              right : 10,
              opacity : 0
            }, 350).hide();
          }
          if ($(".gallery980").find(".photoCR").length) {
            $(".gallery980").find(".photoCR").animate({/* right: 0,*/
              opacity : 0
            }, 350).hide();
          }
        },
        onSlideComplete : function(slider) {
          if ($(".gallery980").find(".activePage").find(".picText.right").length) {
            $(".gallery980").find(".activePage").find(".picText.right").animate({
              right : 70,
              opacity : 1
            }, 400).show();
          }
          if ($(".gallery980").find(".activePage").find(".picText.left").length) {
            $(".gallery980").find(".activePage").find(".picText.left").animate({
              left : 70,
              opacity : 1
            }, 400).show();
          }
          if ($(".gallery980").find(".activePage").find(".text").length) {
            $(".gallery980").find(".activePage").find(".text").animate({
              right : 60,
              opacity : 1
            }, 400).show();
          }
          if ($(".gallery980").find(".activePage").find(".photoCR").length) {
            $(".gallery980").find(".activePage").find(".photoCR").animate({/*right: 17,*/
              opacity : 1
            }, 400).show();
          }
        }
      });
    }
    /***
     *
     * Time Line functions - Board of governors **
     *
     * */
    $('.col480 .moreContent').css('display', 'none');
    if ($('.timelineList').children('li').length > 2) {
      $('.timelineList').children('li').css('display', 'none');
      for (var i = 0; i < 3; i++) {
        $('.timelineList').children('li').eq(i).show();
      }
      $('.col480 .moreContent').show();
    }

    $('.col480 .moreContent').click(function() {
      $('.timelineList').children('li').show('slow');
      $('.col480 .moreContent').hide();
    });

    //lets check if we need to open menu
    $('aside .nav ul li').removeClass('active');
    var active_menu_item = $('aside .nav li a[href="'+location.href+'"]:last-child');
    active_menu_item.parent('li').addClass('active');
    active_menu_item.parents(".nav > li").find('ul').slideDown();
    active_menu_item.parents(".nav > li").addClass('active');

    // Sidebar - Expanding/collapsing side nav is not working
    //aside .nav li a.sub
    $("aside .nav li a.sub").click(function() {
      if ($(this).attr('href') == '') {
        $(this).next("ul").slideToggle();
        $(this).parent("li").toggleClass("active");
        return false;
      }
    });

    /////////////////////////////////fixedWrapper
    if ($("div").hasClass("fixedWrapper")) {
      var top = $(".fixedWrapper").offset().top - parseFloat($(".fixedWrapper").css('margin-top').replace(/auto/, 0));
      $(window).scroll(function(event) {
        // what the y position of the scroll is
        var y = $(this).scrollTop();

        // whether that's below the form
        if (y >= top) {
          // if so, ad the fixed class
          $(".fixedWrapper").addClass('fixed');
        } else {
          // otherwise remove it
          $(".fixedWrapper").removeClass('fixed');
          //console.log(top);
        }
      });
    }

    /////////////////////////////bwGallery
    $(".bwGallery img").each(function() {

      var std = $(this).attr("src");
      var other = $(this).attr("data-other-src");
      var hover = std.replace(std, other);
      $(this).clone().insertBefore(this).attr('src', other).css({
        position : 'absolute',
        left : 0,
        top : 0
      });
    });
    $(".bwGallery li").each(function() {
      var tip = $(this).find(".tTip");
      var thePic = $(this).find("img").eq(1);
      $(this).mouseenter(function() {
        $(thePic).stop().fadeTo(300, 0);
        $(tip).show().stop().fadeTo(300, 1);
      }).mouseleave(function() {
        $(thePic).stop().fadeTo(100, 1);
        $(tip).stop().fadeTo(100, 0).hide();
      });
    });
    
    if(typeof($("#HowLong") != "undefined") && $("#HowLong").length) {
      $("#HowLong").slider({
        range : true,
        orientation : "horizontal",
        min : 0,
        max : 116121600,
        step : 2419200,
        change : function(event, ui) {
          $('input#edit-field-how-long-value-min').val(ui.values[0]).trigger('keyup');
          $('input#edit-field-how-long-value-max').val(ui.values[1]).trigger('keyup');
          var valfirst = ui.values[0] / 2419200;
          var valsec = ui.values[1] / 2419200;
          $("#HowLong_amount").html(Drupal.t("Between @valfirst months and @valsec months", {'@valfirst': valfirst, '@valsec': valsec}));
        },
        slide : function(event, ui) {
          var valfirst = ui.values[0] / 2419200;
          var valsec = ui.values[1] / 2419200;
          $("#HowLong_amount").html(Drupal.t("Between @valfirst months and @valsec months", {'@valfirst': valfirst, '@valsec': valsec}));
        }
      });
      var valfirst = $("#HowLong").slider("values", 0) / 2419200;
      var valsec = $("#HowLong").slider("values", 1) / 2419200;
      if ($("#HowLong").slider("values", 1) == '') {
        $("#HowLong").slider({
          values : [0, 116121600]
        });
      }
      $("#HowLong_clear").click(function() {
        $("#HowLong").slider({
          values : [0, 116121600]
        });
        $('#HowLong').trigger('slidechange');
        return false;
      });
      var handle = $("#HowLong a.ui-slider-handle");
      $(handle).eq(0).addClass("firstHandle");
      $(handle).eq(1).addClass("secondHandle");
    }
    ///////////Total Cost silder/////////
    if(typeof($("#totalCost") != "undefined") && $("#totalCost").length) {
      $("#totalCost").slider({
        range : true,
        orientation : "horizontal",
        min : 0,
        max : 100000,
        step : 1000,
  
        change : function(event, ui) {
          $('input#edit-field-total-cost-value-min').val(ui.values[0]).trigger('keyup');
          $('input#edit-field-total-cost-value-max').val(ui.values[1]).trigger('keyup');
          $("#totalCost_amount").html("$" + ui.values[0] + " - $" + ui.values[1]);
        },
        slide : function(event, ui) {
          $("#totalCost_amount").html("$" + ui.values[0] + " - $" + ui.values[1]);
        }
      });
      if ($("#totalCost").slider("values", 1) == '') {
        $("#totalCost_amount").html(Drupal.t("$0 - Unlimited"));
      }
      $("#totalCost_clear").click(function() {
        $("#totalCost").slider({
          values : [0, 100000]
        });
        $('#totalCost').trigger('slidechange');
        return false;
      });
      $("#StartValue_clear").click(function() {
        $(".opportunityConfig dd #edit-field-start-date-value-value-date").val('');
        $(".opportunityConfig dd #edit-field-start-date-value-value-date").trigger('change');
        return false;
      });
      var handle = $("#totalCost a.ui-slider-handle");
      $(handle).eq(0).addClass("firstHandle");
      $(handle).eq(1).addClass("secondHandle");
      //
    }
    $(".opportunityConfig dd h5:not(.processed)", context).addClass('processed').click(function() {
      $(this).next(".drop").slideToggle();
      $(this).toggleClass("active");
    });

    $(".opportunityConfig dd .edit-field-where-do-you-want-togo-target-id #where_do_you_all, .opportunityConfig dd .edit-field-what-do-you-want-to-do-target-id #what_do_you_all").click(function() {
      $(".opportunityConfig dd .edit-field-where-do-you-want-togo-target-id label, .opportunityConfig dd .edit-field-what-do-you-want-to-do-target-id label").addClass("active");
      $(".opportunityConfig dd .edit-field-where-do-you-want-togo-target-id input[type='checkbox'], .opportunityConfig dd .edit-field-what-do-you-want-to-do-target-id input[type='checkbox']").attr('checked', true).trigger('change');
      return false;
    });

    $(".opportunityConfig dd .edit-field-where-do-you-want-togo-target-id #where_do_you_clear, .opportunityConfig dd .edit-field-what-do-you-want-to-do-target-id #what_do_you_clear").click(function() {
      $(".opportunityConfig dd .edit-field-where-do-you-want-togo-target-id label, .opportunityConfig dd .edit-field-what-do-you-want-to-do-target-id label").removeClass("active");
      $(".opportunityConfig dd .edit-field-where-do-you-want-togo-target-id input[type='checkbox'], .opportunityConfig dd .edit-field-what-do-you-want-to-do-target-id input[type='checkbox']").attr('checked', false).trigger('change');
      return false;
    });



    ////////////////////////////////////////////////////
    $(".opportunityConfig dd .edit-field-program-icons-value #includes_all").click(function() {
      $(".opportunityConfig dd .edit-field-program-icons-value label").addClass("active");
      $(".opportunityConfig dd .edit-field-program-icons-value input[type='checkbox']").attr('checked', true).trigger('change');
      return false;
    });

    $(".opportunityConfig dd .edit-field-program-icons-value #includes_clear").click(function() {
      $(".opportunityConfig dd .edit-field-program-icons-value label").removeClass("active");
      $(".opportunityConfig dd .edit-field-program-icons-value input[type='checkbox']").attr('checked', false).trigger('change');
      return false;
    });
    ////////////////////Choose All & Clear  button on language field////////////////////////
    $(".opportunityConfig dd .edit-field-language-target-id #language_all").click(function() {
      $(".opportunityConfig dd .edit-field-language-target-id label").addClass("active");
      $(".opportunityConfig dd .edit-field-language-target-id input[type='radio']").attr('checked', true).trigger('change');
      return false;
    });

    $(".opportunityConfig dd .edit-field-language-target-id #language_clear").click(function() {
      $(".opportunityConfig dd .edit-field-language-target-id label").removeClass("active");
      $(".opportunityConfig dd .edit-field-language-target-id input[type='radio']").attr('checked', false).trigger('change');
      return false;
    });


    ////////////////////////////////////////////////////
    $(".opportunityConfig dd .edit-field-time-of-year-value #time_of_year_all").click(function() {
      $(".opportunityConfig dd .edit-field-time-of-year-value label").addClass("active");
      $(".opportunityConfig dd .edit-field-time-of-year-value input[type='checkbox']").attr('checked', true).trigger('change');
      return false;
    });

    $(".opportunityConfig dd .edit-field-time-of-year-value #time_of_year_clear").click(function() {
      $(".opportunityConfig dd .edit-field-time-of-year-value label").removeClass("active");
      $(".opportunityConfig dd .edit-field-time-of-year-value input[type='checkbox']").attr('checked', false).trigger('change');
      return false;
    });

    $(".ageGroup li:not(.processed), .opportunityConfig dd .form-type-bef-checkbox label:not(.processed), .doWhere li:not(.processed)").addClass('processed').click(function() {
      $(this).toggleClass("active");
    });

    //!------------------------------ !  My Age clear button !------------------------------------------!//
    $(".opportunityConfig dd .edit-field-age-group-target-id #age_group_clear").click(function() {
      $(".opportunityConfig dd .edit-field-age-group-target-id label").removeClass("active");
      $(".opportunityConfig dd .edit-field-age-group-target-id input[type='checkbox']").attr('checked', false).trigger('change');
      return false;
    });

    $(".opportunityConfig dd .form-item-field-age-group-target-id label:not(.processed)").addClass('processed').click(function() {
      $(".opportunityConfig dd .form-item-field-age-group-target-id label").removeClass("active");
      $(".opportunityConfig dd .form-item-field-age-group-target-id input[type='checkbox']").attr('checked', false);
      $($(this).parent().children('input').attr('checked')).trigger('change');
      $(this).toggleClass("active");
    });

    
    $(".opportunityConfig dd .form-item-field-language-target-id label:not(.processed)").addClass('processed').click(function() {
      $(".opportunityConfig dd .form-item-field-language-target-id label").removeClass("active");
      $(".opportunityConfig dd .form-item-field-language-target-id input[type='radio']").attr('checked', false);
      $($(this).parent().children('input').attr('checked')).trigger('change');
      $(this).toggleClass("active");
    });
    ////!--------------Special Interest Clean ------------------!//
    $(".opportunityConfig dd #interest_clear").click(function(event) {
      event.preventDefault();
      var item =  $('.edit-term-node-tid-depth .form-item label:contains(' + $(".opportunityConfig dd #custom_special_interest").attr('placeholder') + ')');
      if(item.length != 0) {
        $(".opportunityConfig dd #custom_special_interest").val('').attr('placeholder', '');
        $('.edit-term-node-tid-depth .ui-helper-hidden-accessible').text('');
        $('#' + item.attr('for')).attr('checked', false).change();
      }
      return false;
    });

    ////////////////////////////////////////////

//////Search clean//////////////////////////////////
    $(".opportunityConfig dd .edit-keys #search_clear").click(function(event) {
      event.preventDefault();
      var placeholder = '';
      $(".opportunityConfig dd #edit-keys").val('').attr('placeholder', 'Search');
       return false;
    });


/////////////////////////

    $(".opportunityConfig dd #search_submit").click(function(event) {
      event.preventDefault();
      return false;
    });

    if (jQuery.browser.msie == true && jQuery.browser.version == '8.0') {
      $('#views-exposed-form-opportunities-page input:checkbox').css({
        'display' : 'block',
        'height' : '1px',
        'width' : '1px',
        'position' : 'absolute',
        'top' : '-1000px'
      });
    }

    if($('.lpGallery .lightbox-processed').length) {
      $('.lpGallery a.lightbox-processed').each(function( index, value ) {        
        var gal_name = $(this).find('img').attr('title');
        $(this).attr('title', gal_name);
      });
    }
    
    if(typeof($("#edit-field-start-date-value-value-date") != "undefined") && $("#edit-field-start-date-value-value-date").length) {
      $("#edit-field-start-date-value-value-date").datepicker({
        showOn : "both",
        buttonImage : Drupal.settings.pathToTheme + "/images/calendar.gif",
        buttonImageOnly : true,
        dateFormat : "d-m-yy",
        beforeShow : function(textbox, instance) {
          var offsetWidth = textbox.offsetWidth;
          instance.dpDiv.css({
            //marginTop: textbox.offsetHeight + 'px',
            marginLeft : (2 + offsetWidth + 'px')
          }).addClass("doWhen-datepicker");
        }
      });
    }
    
    if ($('ul.picList230:not(.single) li').length) {
      $.each($('ul.picList230:not(.single)'), function(i, elem) {
        var max_height = 0;
        var tmp_height = 0;
        $.each($('li', $(elem)), function(i, element) {
            tmp_height = element.scrollHeight;
            if (tmp_height > max_height) {
              max_height = tmp_height;
            }
        });
        $('li', $(elem)).height(max_height);
      });
    }

    $(".sponsorshipsItems li").click(function() {
      $(".sponsorshipsItems li").removeClass("active");
      $(this).addClass("active").find("input").focus();
      $(".sponsor").slideDown();
    });
    
    if($("#edit-field-date-career-value-value-date").val() != null) {
      $("#career_time option[value=" + $("#edit-field-date-career-value-value-date").val() + "]").attr("selected", "selected");
    }
    
    $("#career_time").change(function() {
      $("#edit-field-date-career-value-value-date").val($("#career_time option:selected").val());
    });
    
    $('#search_page').keypress(function (e) { 
      if (e.which == 13) {
        $('#search_page_submit').click();
      }
    });
    
    $('.opportunityConfig .drop').each(function(i, val) {
      if($(val).height() > '205') {
        $(val).find('.bef-select-as-checkboxes').addClass('agencyScroller');
        $(val).find('.bef-select-as-radios').addClass('agencyScroller');
        $(val).find('.widget_filter_box').addClass('agencyScroller');
      }
    });


  }
};

function closeSubscribe(id) {
  jQuery('#dialog').dialog( 'destroy');
  
}
function closeForm() {
  jQuery('#short_form').dialog('destroy');
}

function GetSubscribe(nid) {
  jQuery('#dialog').dialog({
    height: 240,
    width: 656,
    modal: true,
    resizable: false,
    draggable: false,
    open:  function() {
      jQuery('#subscribe').append('<a href="javascript:closeSubscribe()" class="closeModal"></a><iframe src="' + Drupal.settings.basePath + 
      'subscribe/?response_type=embed&foo='+ nid + '" frameborder="0" height="200" width="630" scrolling="no"></iframe>');
    },
    close: function() {
      jQuery( "#dialog" ).dialog( "destroy" );
    }
  });
}

function Mailto(id) {
  if ($(window).width() > 768) {
    jQuery('#short_form').dialog({
      height: 590,
      width: 510,
      modal: true,
      resizable: false,
      draggable: false,
      open:  function() {
        jQuery('#short_form').append('<a href="javascript:closeForm()" class="closeModal"></a><iframe style="overflow:hidden;" src="' + 
        Drupal.settings.basePath + 'content/' + Drupal.settings.basePath.substr(1,2) + 'contact-form/?response_type=embed&short_contact_nid='+ id + 
        '" frameborder="0" height="590" width="510" scrolling="no"></iframe>');
      },
      close: function() {
        jQuery( "#short_form").dialog( "destroy" );
      }
    });
  } else {
    jQuery('#short_form').dialog({
      modal: true,
      resizable: false,
      draggable: false,
      open:  function() {
        jQuery('#short_form').append('<a href="javascript:closeForm()" class="closeModal"></a>' + 
        '<iframe style="overflow:hidden;" src="' + Drupal.settings.basePath + 'content/' + 
        Drupal.settings.basePath.substr(1,2) + 'contact-form/?response_type=embed&short_contact_nid='+ id + 
        '" frameborder="0" height="465" width="275" scrolling="no"></iframe>');
      },
      close: function() {
        jQuery( "#short_form").dialog( "destroy" );
      }
    });
  }
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


