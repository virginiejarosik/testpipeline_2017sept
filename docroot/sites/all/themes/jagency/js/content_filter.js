var global_content_filter_redirect = true; 
Drupal.behaviors.ContentFilterInit = {
  attach : function(context, settings) {
    if (typeof($) == "undefined") {
      $ = jQuery;
    }

    if($('.opportunityConfigWrapper .' + Drupal.settings.ToTop_side2).height() < $('.opportunityConfigWrapper .' + Drupal.settings.ToTop_side1).height()){      
      var calHeight = $('.opportunityConfigWrapper  .' + Drupal.settings.ToTop_side1).height() - $('.opportunityConfigWrapper .' + Drupal.settings.ToTop_side2 + ' dl').height();
      $('.opportunityConfigWrapper .stickyWrapper').height(calHeight - 20);  
    }
    
    $('.toTop').stickyfloat();
    
    if ($('.opportunityConfigWrapper').length) {
      $.each($('.opportunityConfig .widget_filter_checkbox .checkbox_div input:checkbox, .opportunityConfig .widget_filter_list .listbox_div input:checkbox'), function(i, elem) {
        if ($(elem).attr('checked') && $(elem).next('label').length) {
          $(elem).next('label').addClass('active');
        }
      });
    }

    /**$('#edit-field-program-tags-target-id').change(function(event) {
      var label = $('#edit-field-program-tags-target-id :selected');
      var tags_array = {};
      var arr = [];
      
      $.each(label, function(i, elem) {
        elem = $(elem);
        CLname = elem.val();
        BLname = elem.parent().attr('label');
        if (typeof(tags_array[BLname]) == "undefined") {
          tags_array[BLname] = new Array;
          tags_array[BLname].push(CLname);
        } else {
          tags_array[BLname].push(CLname);
        }
      });
      $.each(tags_array, function(i, elem) {
          arr.push(elem.join('+'));
      });
      var str = '';
      Object.keys(Drupal.settings.views.ajaxViews).forEach(function (key) {

      if(Drupal.settings.views.ajaxViews[key]['view_args']) {
        var str = Drupal.settings.views.ajaxViews[key]['view_args'];
        var pos = str.lastIndexOf('/');
        if(Drupal.settings.query_type) {
          var str = str.substring(0,pos) + '/the_tags' + arr.join();
        } else {
          var str = str.substring(0,pos) + '/' + arr.join();
        }
        Drupal.settings.views.ajaxViews[key]['view_args'] = str;
      }
      });
    }); */

 
    $(".opportunityConfig dd h5:not(.processed)", context).addClass('processed').click(function() {
      $(this).next(".drop").slideToggle();
      $(this).toggleClass("active");
    });

    $(".opportunityConfig .widget_filter_checkbox #Check_all").click(function(event) {
      event.preventDefault();
      var SelectedID = $('#Check_all').attr('class');
      $(".opportunityConfig .widget_filter_checkbox ." + SelectedID + " .checkbox_div label").addClass("active");
      $(".opportunityConfig .widget_filter_checkbox ." + SelectedID + "  .checkbox_div input[type='checkbox']").attr('checked', true);
      $.each($(".widget_filter_box." + SelectedID).children('.widget_filter'), function(i, elem) {
        $(elem).children('label').addClass("active");
      });
      $("#edit-field-program-tags-target-id").trigger('change');
    });
    
     $(".opportunityConfig .Clear_all").click(function(event) {
      event.preventDefault();
      var SelectedID = $(this).attr('id');
      $.each($(".widget_filter_box." + SelectedID).find('.widget_filter input'), function(i, elem) {
        $(elem).attr('checked', false);
        $("#edit-field-program-tags-target-id option[value='" + $(elem).val() + "']").attr("selected", false);
        $(elem).parent().find('label').removeClass("active");
      });
      $("#edit-field-program-tags-target-id").trigger('change');
    });
    
    $(".opportunityConfig .select_all").click(function(event) {
      event.preventDefault();
      var SelectedID = $(this).attr('id').replace('select_all_','');
      $.each($(".widget_filter_box." + SelectedID).find('.widget_filter input'), function(i, elem) {
        $(elem).attr('checked', "checked");
        $("#edit-field-program-tags-target-id option[value='" + $(elem).val() + "']").attr("selected", true);
        $(elem).parent().find('label').addClass("active");
      });
      $("#edit-field-program-tags-target-id").trigger('change');
      return false;
    });

     /*$(".opportunityConfig .widget_filter_checkbox ul li").click(function(event) {
      event.preventDefault();
      $.each($(this).find('input:checked'), function(i, elem) {
        $(elem).parent().find('label').addClass("active");
      });
      $("#edit-field-program-tags-target-id").trigger('change');
    });*/

    $(".opportunityConfig .widget_filter_dropdown select").addClass('processed').change(function() {
      var SelectedID = $(".opportunityConfig .widget_filter_dropdown select option:selected").val();
      $.each($("#edit-field-program-tags-target-id option[value='" + SelectedID + "']").parent().children(), function(i, elem) {
        $(elem).attr("selected", false);
      });
      $("#edit-field-program-tags-target-id option[value='" + SelectedID + "']").attr("selected", "selected").trigger('change');
      $(this).toggleClass("active");
    });

    $(".opportunityConfig .widget_filter_radiobox .radiobox_div label:not(.processed)").addClass('processed').click(function() {
      var SelectedID = $('#' + $(this).attr('for')).val();
      $(".opportunityConfig .widget_filter_radiobox .radiobox_div label").removeClass("active");
      $.each($("#edit-field-program-tags-target-id option[value='" + SelectedID + "']").parent().children(), function(i, elem) {
        $(elem).attr("selected", false);
      });
      $(".opportunityConfig .widget_filter_radiobox .radiobox_div input[type='radio']").attr('checked', false);
      $("#edit-field-program-tags-target-id option[value='" + SelectedID + "']").attr("selected", "selected").trigger('change');
      $(this).toggleClass("active");
    });


    $(".opportunityConfig .widget_filter_checkbox .checkbox_div label:not(.processed), .opportunityConfig .widget_filter_list .listbox_div label:not(.processed)").addClass('processed').click(function() {
      var SelectedID = $('#' + $(this).attr('for')).val();
      if($("#edit-field-program-tags-target-id option[value='" + SelectedID + "']:selected").length) {
        $("#edit-field-program-tags-target-id option[value='" + SelectedID + "']").attr("selected", false).trigger('change');
      } else {
        $("#edit-field-program-tags-target-id option[value='" + SelectedID + "']").attr("selected", "selected").trigger('change');
      }
      $(this).toggleClass("active");
    });

    /*$('.opportunityConfig .widget_filter_box input[value="ALL"]').change(function() {
      var SelectedID = $(this).attr('name');
      $(".widget_filter_box#" + SelectedID).find('.widget_filter input[value!="ALL"]').attr('checked', "checked").parent().find('label').addClass("active");
      $.each($(".widget_filter_box#" + SelectedID).find('.widget_filter input[value!="ALL"]'), function(i, elem) {
        $("#edit-field-program-tags-target-id option[value='" + $(elem).val() + "']").attr("selected", true);
      });
      $("#edit-field-program-tags-target-id").trigger('change');
    });*/
   
   $(".opportunityConfig .select_all_inside").click(function(event) {
      var SelectedID = $(this).prev().attr('name');
      $(".widget_filter_box#" + SelectedID).find('.widget_filter input[value!="ALL"]').attr('checked', "checked").parent().find('label').addClass("active");
      $.each($(".widget_filter_box#" + SelectedID).find('.widget_filter input[value!="ALL"]'), function(i, elem) {
        $("#edit-field-program-tags-target-id option[value='" + $(elem).val() + "']").attr("selected", true);
      });
      $("#edit-field-program-tags-target-id").trigger('change');
      return false;
    });
    
    $(".opportunityConfig .widget_filter_freetext #free_search_content").keyup(function(event) {
      $(".view-opportunities #edit-keys, .view-content-filter #edit-keys").val($(".opportunityConfig .widget_filter_freetext #free_search_content").val());
      if (event.keyCode == '13') {
        $(".view-opportunities #edit-keys, .view-content-filter #edit-keys").trigger('change');
      }
    });
    
    $('#Sort_by_opp_new').html($('#edit-sort-by').clone());
    $('#Sort_by_opp_new .form-select').val($('#edit-sort-by').val());
    $('#Sort_by_opp_new select').selectmenu();
    $('#Sort_by_opp').hide();
    
    $('#Sort_by_opp_new .form-select').change(function() {
      $("#Sort_by_opp .form-select").val($(this).val());
      $("#Sort_by_opp .form-select").change();
    });
    if ($(".view-content-filter #edit-keys").val()) {
      $('#free_search_content').val($(".view-content-filter #edit-keys").val());
    }
    /*$.urlParam = function(name) {
      var results = new RegExp('[\?&]' + name + '=([^&#]*)').exec(window.location.href);
      if (results==null) {
        return null;
      } else {
        return results[1] || 0;
      }
    };
    
    if (global_content_filter_redirect) {
      var flagtoupdate = false;
      $.each(window.location.search.replace('?', '').split('&'), function(i, item) {
        var element = item.split('=');
        if (element[0].indexOf('vocabluary_id_') != -1 && element[1] != 0) {
          if ($("#edit-field-program-tags-target-id option[value='" + element[1] + "']").attr("selected") != "selected") {
            $("#edit-field-program-tags-target-id option[value='" + element[1] + "']").attr("selected", "selected");
            $("#" + element[0] + " option[value='" + element[1] + "']").attr("selected", "selected");
            flagtoupdate = true;
          }
        }
      });
      
      if ($.urlParam('free_search_content') && $(".view-opportunities #edit-keys, .view-content-filter #edit-keys").val() != decodeURIComponent($.urlParam('free_search_content'))) {
        $(".opportunityConfig .widget_filter_freetext #free_search_content").val(decodeURIComponent($.urlParam('free_search_content')));
        $(".view-opportunities #edit-keys, .view-content-filter #edit-keys").val($(".opportunityConfig .widget_filter_freetext #free_search_content").val());
        $(".view-opportunities #edit-keys, .view-content-filter #edit-keys").trigger('change');
        flagtoupdate = false;
      }
      
      if (flagtoupdate) {
        $("#edit-field-program-tags-target-id").trigger('change');
      }
      global_content_filter_redirect = false;
    }*/
    if (jQuery.browser.msie == true && jQuery.browser.version == '8.0') {
      $('.opportunityConfig .widget_filter_checkbox .checkbox_div input:checkbox').css({
        'display' : 'block',
        'height' : '1px',
        'width' : '1px',
        'position' : 'absolute',
        'top' : '-1000px'
      });
    }
  }
};
