/// <reference path="jquery.min.js" />

//$(document).ready(function () {
jQuery(document).ready(function () {
    if (typeof ($) == "undefined") {
        $ = jQuery;
    }

    $('.gallery980 .button.cs5').on('click touchstart', function () {
        var href = $(this).attr('href');
        window.location.href = href;
    });

    if ($(window).width() <= 768) {
    //if (/Android|webOS|iPhone|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent)) {
    //if (window.screen.width < 420) {
        $('.headNav li:gt(1)').hide();

        if($('.logoAndSearch').length <= 0) {
            $('header').after('<div class="logoAndSearch"></div>');
            $('menu .logo').appendTo('.logoAndSearch');
            $('.logoAndSearch').append('<a class="searchBtn"></a>');
            $('.logoAndSearch').append('<div class="searchRow"></div>');
            $('.search.ui-widget').appendTo('.searchRow');
            $('.searchBtn').click(function() {
                $(this).toggleClass('searchBtnActive');
                $(this).siblings('.searchRow').toggle();
            });
        }

        $("header .languages button").empty();
        $('#search_submit').click(function() {
            $(this).parents('.searchRow').siblings('.searchBtn').removeClass('searchBtnActive');
            $(this).parents('.searchRow').hide();
        });

        $('#gallery li:gt(0), .articleGallery > li:gt(0)').hide();
        $('#gallery li .pic, .articleGallery > li > img').css('width', $(window).width());
        $('.gallery980 .pic, .articleGallery > li > img, .lpGallery > a > img, .blogs article .blogmeida > a > img, .picList230 li img, .lpGallery img, .lpVideoGallery img, .topBanner img, .blogs article > div img, .picIntro figure img, .blogsCategory > a > img, .picList480 li a img, .bwGallery li img').removeAttr('width');
        $('.gallery980 .pic, .articleGallery > li > img, .lpGallery > a > img, .blogs article .blogmeida > a > img, .picList230 li img, .lpGallery img, .lpVideoGallery img, .topBanner img, .blogs article > div img, .picIntro figure img, .blogsCategory > a > img, .picList480 li a img, .bwGallery li img').removeAttr('height');

        $('.bwGallery li img:nth-child(2)').remove();
        $('.bwGallery li').removeAttr('class');
        $('.bwGallery li > img').click(function () {
            $(this).siblings('.tTip').show();
        });
        $('.tTip .text').prepend("<span class='close'>X</span>");
        $('.tTip .text .close').click(function () {
            $(this).parents('.tTip').hide();
        });
        $('.bwGallery').parent('.wrapper').css('overflow', 'visible');
        
        $('.pager-next').before('<br /><br />');
        $('.pager-previous').after('<br /><br />');

        if ($('aside .nav').length) {
            $('h1 a').addClass('titleMenu');
            $('h1').append('<div class="board"><a>Menu</a></div>');
            $('body').on('click', '.board a', function () {
                $('aside .nav').slideToggle();
            });
        }

        $(".picIntro figcaption table tbody tr").after("<tr></tr>");
        $(".picIntro figcaption table tbody tr:nth-child(2)").prepend($(".picIntro figcaption table tbody tr:nth-child(1) td:nth-child(2)"));

        $("table[cellpadding='13'] tr:nth-child(4) td:nth-child(3)").remove();
        $("table[cellpadding='13']").replaceWith(function () {
            return $("<div class='countries'>" + $(this).html() + "</div>");
        });
        $('.countries span')
        .filter(function () {
            return $.trim($(this).text()) === '' && $(this).children().length == 0
        })
        .remove()
        $('.countries > span:nth-child(2n+1):lt(4)').css('clear', 'right');
        $('.countries > span:nth-child(2n+1)').append("<br\>");
        $('.countries img').remove();
        $(".countries b").replaceWith(function () {
            return $("<span>" + $(this).html() + "</span>");
        });
        $('.countries > span:nth-child(2n+1):gt(47):lt(54)').css('clear', 'right');

        //if (window.location.href.indexOf("http://www.lln.co.il/content/donate?_ga=1.235106818.241142405.1410090080") > -1) {
        //if (window.location.href.indexOf("http://www.jewishagency.org/content/donate") > -1) {
        //    $('iframe[src="https://donate.jewishagency.org/page/contribute/default"]').remove();
        //    $('#main').prepend("<p>Thank you! Please access our website from a computer in order to donate. Donations on mobile devices will be possible in the near future</p>");
        //}
        if (window.location.href.indexOf("http://www.lln.co.il/he/content/%D7%AA%D7%A8%D7%95%D7%9E%D7%95%D7%AA") > -1) {
            $('iframe').remove();
            $('#main').prepend("<p>בשלב זה, ניתן לתרום בגישה ממחשב בלבד. תרומה באמצעות טלפון חכם תתאפשר בקרוב</p>");
        }

    }

    window.addEventListener("orientationchange", function () {
        location.href = location.href;
        return;
    }, false);

});

jQuery(window).resize(function () {
    if (typeof ($) == "undefined") {
        $ = jQuery;
    }

    Drupal.behaviors.agencyTop.attach();

    $('.gallery980 .button.cs5').on('click touchstart', function () {
        var href = $(this).attr('href');
        window.location.href = href;
    });

    if ($(window).width() <= 768) {
        //if (/Android|webOS|iPhone|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent)) {
        //if (window.screen.width < 420) {
        $('.headNav li:gt(1)').hide();

        if ($('.logoAndSearch').length <= 0) {
            $('header').after('<div class="logoAndSearch"></div>');
            $('menu .logo').appendTo('.logoAndSearch');
            $('.logoAndSearch').append('<a class="searchBtn"></a>');
            $('.logoAndSearch').append('<div class="searchRow"></div>');
            $('.search.ui-widget').appendTo('.searchRow');
            $('.searchBtn').click(function () {
                $(this).toggleClass('searchBtnActive');
                $(this).siblings('.searchRow').toggle();
            });
            $("header .languages button").empty();
            $('#search_submit').click(function () {
                $(this).parents('.searchRow').siblings('.searchBtn').removeClass('searchBtnActive');
                $(this).parents('.searchRow').hide();
            });
        }

        $('#gallery li:gt(0), .articleGallery > li:gt(0)').hide();
        $('#gallery li .pic, .articleGallery > li > img').css('width', $(window).width());
        $('.gallery980 .pic, .articleGallery > li > img, .lpGallery > a > img, .blogs article .blogmeida > a > img, .picList230 li img, .lpGallery img, .lpVideoGallery img, .topBanner img, .blogs article > div img, .picIntro figure img, .blogsCategory > a > img, .picList480 li a img, .bwGallery li img').removeAttr('width');
        $('.gallery980 .pic, .articleGallery > li > img, .lpGallery > a > img, .blogs article .blogmeida > a > img, .picList230 li img, .lpGallery img, .lpVideoGallery img, .topBanner img, .blogs article > div img, .picIntro figure img, .blogsCategory > a > img, .picList480 li a img, .bwGallery li img').removeAttr('height');

        $('.bwGallery li img:nth-child(2)').remove();
        $('.bwGallery li').removeAttr('class');
        $('.bwGallery li > img').click(function () {
            $(this).siblings('.tTip').show();
        });
        $('.tTip .text').prepend("<span class='close'>X</span>");
        $('.tTip .text .close').click(function () {
            $(this).parents('.tTip').hide();
        });
        $('.bwGallery').parent('.wrapper').css('overflow', 'visible');

        $('.pager-next').before('<br /><br />');
        $('.pager-previous').after('<br /><br />');

        if ($('aside .nav').length) {
            $('h1 a').addClass('titleMenu');
            $('h1').append('<div class="board"><a>Menu</a></div>');
            $('body').on('click', '.board a', function () {
                $('aside .nav').slideToggle();
            });
        }

        $(".picIntro figcaption table tbody tr").after("<tr></tr>");
        $(".picIntro figcaption table tbody tr:nth-child(2)").prepend($(".picIntro figcaption table tbody tr:nth-child(1) td:nth-child(2)"));

        $("table[cellpadding='13'] tr:nth-child(4) td:nth-child(3)").remove();
        $("table[cellpadding='13']").replaceWith(function () {
            return $("<div class='countries'>" + $(this).html() + "</div>");
        });
        $('.countries span')
        .filter(function () {
            return $.trim($(this).text()) === '' && $(this).children().length == 0
        })
        .remove()
        $('.countries > span:nth-child(2n+1):lt(4)').css('clear', 'right');
        $('.countries > span:nth-child(2n+1)').append("<br\>");
        $('.countries img').remove();
        $(".countries b").replaceWith(function () {
            return $("<span>" + $(this).html() + "</span>");
        });
        $('.countries > span:nth-child(2n+1):gt(47):lt(54)').css('clear', 'right');

        //if (window.location.href.indexOf("http://www.lln.co.il/content/donate?_ga=1.235106818.241142405.1410090080") > -1) {
        //if (window.location.href.indexOf("http://www.jewishagency.org/content/donate") > -1) {
        //    $('iframe[src="https://donate.jewishagency.org/page/contribute/default"]').remove();
        //    $('#main').prepend("<p>Thank you! Please access our website from a computer in order to donate. Donations on mobile devices will be possible in the near future</p>");
        //}
        if (window.location.href.indexOf("http://www.lln.co.il/he/content/%D7%AA%D7%A8%D7%95%D7%9E%D7%95%D7%AA") > -1) {
            $('iframe').remove();
            $('#main').prepend("<p>בשלב זה, ניתן לתרום בגישה ממחשב בלבד. תרומה באמצעות טלפון חכם תתאפשר בקרוב</p>");
        }

    }
});