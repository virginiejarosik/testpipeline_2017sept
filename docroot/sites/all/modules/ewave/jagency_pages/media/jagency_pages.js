Drupal.behaviors.JagencyPages = {
  attach : function(context, settings) {
    if ( typeof ($) == "undefined") {
      $ = jQuery;
    }
    if ($('.status_coordinates').length) {
      $('.status_coordinates_long').text($('#edit-field-longitude input').val());
      $('.status_coordinates_lat').text($('#edit-field-latitude input').val());
      $('.update_coordinates').on('click', function(event) {
        event.preventDefault();
        if ($('#edit-field-address-und-0-value').val() == "") {
          alert('Adress cant be empty');
          return;
        }
        var geocoder;
        geocoder = new google.maps.Geocoder();
        geocoder.geocode({
          'address' : $('#edit-field-address-und-0-value').val()
        }, function(results, status) {
          var lat = results[0].geometry.location.lat();
          var lon = results[0].geometry.location.lng();
          $('#edit-field-latitude input').val(lat);
          $('#edit-field-longitude input').val(lon);
          $('.status_coordinates_long').text(lon);
          $('.status_coordinates_lat').text(lat);
        });
        event.preventDefault();
        return false;
      });
    }
    
    if ($('#edit-field-block-type-und').length) {
      switch($('#edit-field-block-type-und').val()) {
        case 'taxonomy':
          var settings = $('#field-content-block-settings-add-more-wrapper input').val() ? unserialize($('#field-content-block-settings-add-more-wrapper input').val()) : [];
          $.each(settings, function(i, val) {
            if (typeof val.type == "object") {
              $('#content_type_list').val(val.type);
            } else if (typeof val.tags == "object") {
              $('#edit-field-program-tags-und').val(val.tags);
              $('#edit-field-program-tags-und').select2();
            }
          });
          $('.taxonomy_filter fieldset .fieldset-wrapper').append($('.field-name-field-program-tags'));
          $('#content_type_list').select2();
          $('.taxonomy_filter').show();
          break;
        case 'findopp':
          var settings = $('#field-content-block-settings-add-more-wrapper input').val() ? unserialize($('#field-content-block-settings-add-more-wrapper input').val()) : [];
          var html = '<div class="custom-settings field-type-list-text field-name-field-block-type field-widget-options-select form-wrapper"><div class="form-item form-type-select">';
            html += '<label>' + Drupal.t('Find an Opportunity Components') + '</label><small>' + Drupal.t('Plase choose components to be displayed') + '</small>';
            html += '<br /><input class="insert_hidden"' + ($.inArray('field_what_do_you_want_to_do_target_id', settings) != -1 ? ' checked="checked"' : '') + ' type="checkbox" name="findopp_select[]" value="field_what_do_you_want_to_do_target_id" /> ' + Drupal.t('What do you want to do');
            html += '<br /><input class="insert_hidden"' + ($.inArray('field_age_group_target_id', settings) != -1 ? ' checked="checked"' : '') + ' type="checkbox" name="findopp_select[]" value="field_age_group_target_id" /> ' + Drupal.t('What is your age group');
            html += '<br /><input class="insert_hidden"' + ($.inArray('field_how_long_value', settings) != -1 ? ' checked="checked"' : '') + ' type="checkbox" name="findopp_select[]" value="field_how_long_value" /> ' + Drupal.t('For how long');
            html += '<br /><input class="insert_hidden"' + ($.inArray('field_where_do_you_want_togo_target_id', settings) != -1 ? ' checked="checked"' : '') + ' type="checkbox" name="findopp_select[]" value="field_where_do_you_want_togo_target_id" /> ' + Drupal.t('Where do you want to go');
            html += '<br /><input class="insert_hidden"' + ($.inArray('term_node_tid_depth', settings) != -1 ? ' checked="checked"' : '') + ' type="checkbox" name="findopp_select[]" value="term_node_tid_depth" /> ' + Drupal.t('Any special interests');
            html += '<br /><input class="insert_hidden"' + ($.inArray('field_program_icons_value', settings) != -1 ? ' checked="checked"' : '') + ' type="checkbox" name="findopp_select[]" value="field_program_icons_value" /> ' + Drupal.t('Includes');
            html += '<br /><input class="insert_hidden"' + ($.inArray('field_language_target_id', settings) != -1 ? ' checked="checked"' : '') + ' type="checkbox" name="findopp_select[]" value="field_language_target_id" /> ' + Drupal.t('Program Language');
            html += '<br /><input class="insert_hidden"' + ($.inArray('field_time_of_year_value', settings) != -1 ? ' checked="checked"' : '') + ' type="checkbox" name="findopp_select[]" value="field_time_of_year_value" /> ' + Drupal.t('Time of year');
            html += '<br /><input class="insert_hidden"' + ($.inArray('field_total_cost_value', settings) != -1 ? ' checked="checked"' : '') + ' type="checkbox" name="findopp_select[]" value="field_total_cost_value" /> ' + Drupal.t('Total cost');
            html += '</div></div>';
            $('#edit-field-block-type').after(html);
          break;
      }
      $('#edit-field-block-type-und').change(function() {
        var selected = $(this).val();
        $('.custom-settings').remove();
        $('.taxonomy_filter').hide();
        switch (selected) {
          case 'taxonomy':
            var settings = $('#field-content-block-settings-add-more-wrapper input').val() ? unserialize($('#field-content-block-settings-add-more-wrapper input').val()) : [];
            $('.taxonomy_filter fieldset .fieldset-wrapper').append($('.field-name-field-program-tags'));
            $('#content_type_list').select2();
            $('.taxonomy_filter').show();
            break;
            
          case 'findopp':
            var html = '<div class="custom-settings field-type-list-text field-name-field-block-type field-widget-options-select form-wrapper"><div class="form-item form-type-select">';
            html += '<label>' + Drupal.t('Find an Opportunity Components') + '</label><small>' + Drupal.t('Plase choose components to be displayed') + '</small>';
            html += '<br /><input class="insert_hidden" type="checkbox" name="findopp_select[]" value="field_what_do_you_want_to_do_target_id" /> ' + Drupal.t('What do you want to do');
            html += '<br /><input class="insert_hidden" type="checkbox" name="findopp_select[]" value="field_age_group_target_id" /> ' + Drupal.t('What is your age group');
            html += '<br /><input class="insert_hidden" type="checkbox" name="findopp_select[]" value="field_how_long_value" /> ' + Drupal.t('For how long');
            html += '<br /><input class="insert_hidden" type="checkbox" name="findopp_select[]" value="field_where_do_you_want_togo_target_id" /> ' + Drupal.t('Where do you want to go');
            html += '<br /><input class="insert_hidden" type="checkbox" name="findopp_select[]" value="term_node_tid_depth" /> ' + Drupal.t('Any special interests');
            html += '<br /><input class="insert_hidden" type="checkbox" name="findopp_select[]" value="field_program_icons_value" /> ' + Drupal.t('Includes');
            html += '<br /><input class="insert_hidden" type="checkbox" name="findopp_select[]" value="field_language_target_id" /> ' + Drupal.t('Program Language');
            html += '<br /><input class="insert_hidden" type="checkbox" name="findopp_select[]" value="field_time_of_year_value" /> ' + Drupal.t('Time of year');
            html += '<br /><input class="insert_hidden" type="checkbox" name="findopp_select[]" value="field_total_cost_value" /> ' + Drupal.t('Total cost');
            html += '</div></div>';
            $('#edit-field-block-type').after(html);
            break;
        }
      });
      if ($('#panels-createnode-content-type-edit-form').length) {
        $('#panels-createnode-content-type-edit-form #edit-return').click(function() {
          var values = [];
          $.each($('.insert_hidden:checked'), function(i, elem) {
            values.push($(elem).val());
          });
          if ($('#content_type_list').val()){
            var temp = {type: $('#content_type_list').val()};
            values.push(temp);
          }
          if ($('#edit-field-program-tags-und').val()){
            var temp = {tags: $('#edit-field-program-tags-und').val()};
            $('#edit-field-program-tags-und').val('');
            values.push(temp);
          }
          $('#field-content-block-settings-add-more-wrapper input').val(serialize(values));
        });
      } else {
        $('#content-block-node-form, #panels-createnode-content-type-edit-form').submit(function() {
          var values = [];
          $.each($('.insert_hidden:checked'), function(i, elem) {
            values.push($(elem).val());
          });
          if ($('#content_type_list').val()){
            var temp = {type: $('#content_type_list').val()};
            values.push(temp);
          }
          if ($('#edit-field-program-tags-und').val()){
            var temp = {tags: $('#edit-field-program-tags-und').val()};
            $('#edit-field-program-tags-und').val('');
            values.push(temp);
          }
          $('#field-content-block-settings-add-more-wrapper input').val(serialize(values));
        });
      }
    }
    
    setTimeout(function(){$('#edit-vid-wrapper select').trigger("change");},500);
    if ($('#article-node-form').length) {
        $('#article-node-form #edit-submit').click(function() {
          if ($('#edit-field-date-with-time-und-0-value-timeEntry-popup-1').val() == '') {
            $('#edit-field-date-with-time-und-0-value-timeEntry-popup-1').val('00:01').hide();
          }
        });
    }
    
    if ($('.view-admin-views-node #edit-tid-raw').length) {
      if ($('#edit-tid-raw-clone').html() == null) {
        var clone = $('.view-admin-views-node #edit-tid-raw').clone().hide();
        clone.attr('id', 'edit-tid-raw-clone');
        $('.view-admin-views-node #edit-tid-raw').after(clone);
        $('.view-admin-views-node #edit-tid-raw option[value!=""]').remove();
      } else {
        $('.view-admin-views-node #edit-tid-raw').val($('.view-admin-views-node #edit-tid-raw-clone').val());
      }
      
      $('.view-admin-views-node #edit-tid-raw').change(function(){
        $('.view-admin-views-node #edit-tid-raw-clone').val($(this).val());
      });
      
      $('.view-admin-views-node  #edit-vid').change(function(){
        $('.view-admin-views-node #edit-tid-raw option[value!=""]').remove();
        var clone_elements = $('.view-admin-views-node #edit-tid-raw-clone option[data=' + $(this).val() + ']').clone();
        $('.view-admin-views-node #edit-tid-raw').append(clone_elements);
      });
      
      $.each($('.view-admin-views-node #edit-tid-raw-clone option'), function(i, elem) {
        var eltext = $(elem).text();
        if (eltext.search('::') != -1) {
          var split = eltext.split('::');
          $(elem).attr('data', split[0]).text(split[1]);
        }
      });
    }

    if ($('#edit-field-file-image-title-text-und-0-value').length) {
      var x = screen.width / 2 - 700 / 2;
      var y = screen.height / 2 - 750 / 2;
      var params = 'height=750, width=700, location=0, menubar=0, resizable=0, scrollbars=0, status=0, titlebar=0, left=' + x + ', top=' + y;
      var url = Drupal.settings.basePath + 'admin/config/jagency/translater/';
      if ($('#edit-field-file-image-title-text-und-0-value').val()) {
        link = url + B64.encode($('#edit-field-file-image-title-text-und-0-value').val());
        $('#edit-field-file-image-title-text-und-0-value').after(' <a class="button" href="" onclick="window.open(\'' + link + '\',\'translate\', \'' + params + '\'); return false;" target="_blank">' + Drupal.t('Translate') + '</a>');
      }
      if ($('#edit-field-file-image-alt-text-und-0-value').val()) {
        link = url + B64.encode($('#edit-field-file-image-alt-text-und-0-value').val());
        $('#edit-field-file-image-alt-text-und-0-value').after(' <a class="button" href="" onclick="window.open(\'' + link + '\',\'translate2\', \'' + params + '\'); return false;" target="_blank">' + Drupal.t('Translate') + '</a>');
      }
      if ($('#edit-field-copyright-und-0-value').val()) {
        link = url + B64.encode($('#edit-field-copyright-und-0-value').val());
        $('#edit-field-copyright-und-0-value').after(' <a class="button" href="" onclick="window.open(\'' + link + '\',\'translate3\', \'' + params + '\'); return false;" target="_blank">' + Drupal.t('Translate') + '</a>');
      }
      if ($('#edit-field-photographer-und-0-value').val()) {
        link = url + B64.encode($('#edit-field-photographer-und-0-value').val());
        $('#edit-field-photographer-und-0-value').after(' <a class="button" href="" onclick="window.open(\'' + link + '\',\'translate4\', \'' + params + '\'); return false;" target="_blank">' + Drupal.t('Translate') + '</a>');
      }
    }
    if ($('body').hasClass('page-node-add-agents-list')) {
      if ($('#edit-field-aliah-country-und').length) {
        var content = '<option value="_none">' + Drupal.t('- None -') + '</option>';
        if ($('.field_aliah_city select').val() == '_none') {
          $('.field_aliah_city select').find('option').remove().end().append(content);
        }
  
        $('#edit-field-aliah-country-und').change(function() {
          var country = $(this).val();
          $(this).parent().addClass('loading');
          $.getJSON(Drupal.settings.basePath + 'ajax/aliah-location/' + country + '?response_type=json', function(data) {
            var content = '<option value="_none">' + Drupal.t('- None -') + '</option>';
            $.each(data.terms, function(key, item) {
              content += '<option value="' + item.id + '">' + item.name + '</option>';
            });
            $('.field_aliah_city select').find('option').remove().end().append(content);
            $('#edit-field-aliah-country-und').parent().removeClass('loading');
          });
        });
      }
    } else {
      if ($('#edit-field-taxonomy-country-und').length) {
        var content = '<option value="_none">' + Drupal.t('- None -') + '</option>';
        if ($('.field_taxonomy_region select').val() == '_none') {
          $('.field_taxonomy_region select').find('option').remove().end().append(content);
        }
        if ($('.field_taxonomy_city select').val() == '_none') {
          $('.field_taxonomy_city select').find('option').remove().end().append(content);
        }
  
        $('#edit-field-taxonomy-country-und').change(function() {
          var country = $(this).val();
          $(this).parent().addClass('loading');
          $.getJSON(Drupal.settings.basePath + 'ajax/location/' + country + '?response_type=json', function(data) {
            var content = '<option value="_none">' + Drupal.t('- None -') + '</option>';
            $.each(data.terms, function(key, item) {
              content += '<option value="' + item.id + '">' + item.name + '</option>';
            });
            //$('.field_taxonomy_region option').remove();
            $('.field_taxonomy_region select').find('option').remove().end().append(content);
            $('#edit-field-taxonomy-country-und').parent().removeClass('loading');
          });
        });
  
        $('#edit-field-taxonomy-region-und').change(function() {
          var region = $(this).val();
          $(this).parent().addClass('loading');
          $.getJSON(Drupal.settings.basePath + 'ajax/location/' + region + '?response_type=json', function(data) {
            var content = '<option value="_none">' + Drupal.t('- None -') + '</option>';
            $.each(data.terms, function(key, item) {
              content += '<option value="' + item.id + '">' + item.name + '</option>';
            });
            $('.field_taxonomy_city select').find('option').remove().end().append(content);
            $('#edit-field-taxonomy-region-und').parent().removeClass('loading');
          });
        });
      }
    }
    
    if ($('#edit-field-content-type-und-0-value').val() != null) {
      var content_types =  $('#edit-field-content-type-und-0-value').val().split("+");
      $.each(content_types, function( index, value ) {
        $("#content_type_list option[value='" + value + "']").attr("selected", "selected");
      });
    }

    $('#content_type_list').change(function() {
      var content_types_new_array = [];
      $('#content_type_list option:selected').each(function() {
        content_types_new_array.push($(this).val());
      });
      $('#edit-field-content-type-und-0-value').val((content_types_new_array.join('+')));
    });
  }
};

/*
Copyright Vassilis Petroulias [DRDigit]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
var B64 = {
    alphabet: 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=',
    lookup: null,
    ie: /MSIE /.test(navigator.userAgent),
    ieo: /MSIE [67]/.test(navigator.userAgent),
    encode: function (s) {
        var buffer = B64.toUtf8(s),
            position = -1,
            len = buffer.length,
            nan0, nan1, nan2, enc = [, , , ];
        if (B64.ie) {
            var result = [];
            while (++position < len) {
                nan0 = buffer[position];
                nan1 = buffer[++position];
                enc[0] = nan0 >> 2;
                enc[1] = ((nan0 & 3) << 4) | (nan1 >> 4);
                if (isNaN(nan1))
                    enc[2] = enc[3] = 64;
                else {
                    nan2 = buffer[++position];
                    enc[2] = ((nan1 & 15) << 2) | (nan2 >> 6);
                    enc[3] = (isNaN(nan2)) ? 64 : nan2 & 63;
                }
                result.push(B64.alphabet.charAt(enc[0]), B64.alphabet.charAt(enc[1]), B64.alphabet.charAt(enc[2]), B64.alphabet.charAt(enc[3]));
            }
            return result.join('');
        } else {
            var result = '';
            while (++position < len) {
                nan0 = buffer[position];
                nan1 = buffer[++position];
                enc[0] = nan0 >> 2;
                enc[1] = ((nan0 & 3) << 4) | (nan1 >> 4);
                if (isNaN(nan1))
                    enc[2] = enc[3] = 64;
                else {
                    nan2 = buffer[++position];
                    enc[2] = ((nan1 & 15) << 2) | (nan2 >> 6);
                    enc[3] = (isNaN(nan2)) ? 64 : nan2 & 63;
                }
                result += B64.alphabet[enc[0]] + B64.alphabet[enc[1]] + B64.alphabet[enc[2]] + B64.alphabet[enc[3]];
            }
            return result;
        }
    },
    decode: function (s) {
        if (s.length % 4)
            throw new Error("InvalidCharacterError: 'B64.decode' failed: The string to be decoded is not correctly encoded.");
        var buffer = B64.fromUtf8(s),
            position = 0,
            len = buffer.length;
        if (B64.ieo) {
            var result = [];
            while (position < len) {
                if (buffer[position] < 128) 
                    result.push(String.fromCharCode(buffer[position++]));
                else if (buffer[position] > 191 && buffer[position] < 224) 
                    result.push(String.fromCharCode(((buffer[position++] & 31) << 6) | (buffer[position++] & 63)));
                else 
                    result.push(String.fromCharCode(((buffer[position++] & 15) << 12) | ((buffer[position++] & 63) << 6) | (buffer[position++] & 63)));
            }
            return result.join('');
        } else {
            var result = '';
            while (position < len) {
                if (buffer[position] < 128) 
                    result += String.fromCharCode(buffer[position++]);
                else if (buffer[position] > 191 && buffer[position] < 224) 
                    result += String.fromCharCode(((buffer[position++] & 31) << 6) | (buffer[position++] & 63));
                else 
                    result += String.fromCharCode(((buffer[position++] & 15) << 12) | ((buffer[position++] & 63) << 6) | (buffer[position++] & 63));
            }
            return result;
        }
    },
    toUtf8: function (s) {
        var position = -1,
            len = s.length,
            chr, buffer = [];
        if (/^[\x00-\x7f]*$/.test(s)) while (++position < len)
            buffer.push(s.charCodeAt(position));
        else while (++position < len) {
            chr = s.charCodeAt(position);
            if (chr < 128) 
                buffer.push(chr);
            else if (chr < 2048) 
                buffer.push((chr >> 6) | 192, (chr & 63) | 128);
            else 
                buffer.push((chr >> 12) | 224, ((chr >> 6) & 63) | 128, (chr & 63) | 128);
        }
        return buffer;
    },
    fromUtf8: function (s) {
        var position = -1,
            len, buffer = [],
            enc = [, , , ];
        if (!B64.lookup) {
            len = B64.alphabet.length;
            B64.lookup = {};
            while (++position < len)
                B64.lookup[B64.alphabet.charAt(position)] = position;
            position = -1;
        }
        len = s.length;
        while (++position < len) {
            enc[0] = B64.lookup[s.charAt(position)];
            enc[1] = B64.lookup[s.charAt(++position)];
            buffer.push((enc[0] << 2) | (enc[1] >> 4));
            enc[2] = B64.lookup[s.charAt(++position)];
            if (enc[2] == 64) 
                break;
            buffer.push(((enc[1] & 15) << 4) | (enc[2] >> 2));
            enc[3] = B64.lookup[s.charAt(++position)];
            if (enc[3] == 64) 
                break;
            buffer.push(((enc[2] & 3) << 6) | enc[3]);
        }
        return buffer;
    }
};

function serialize(mixed_value) {
  //  discuss at: http://phpjs.org/functions/serialize/
  // original by: Arpad Ray (mailto:arpad@php.net)
  // improved by: Dino
  // improved by: Le Torbi (http://www.letorbi.de/)
  // improved by: Kevin van Zonneveld (http://kevin.vanzonneveld.net/)
  // bugfixed by: Andrej Pavlovic
  // bugfixed by: Garagoth
  // bugfixed by: Russell Walker (http://www.nbill.co.uk/)
  // bugfixed by: Jamie Beck (http://www.terabit.ca/)
  // bugfixed by: Kevin van Zonneveld (http://kevin.vanzonneveld.net/)
  // bugfixed by: Ben (http://benblume.co.uk/)
  //    input by: DtTvB (http://dt.in.th/2008-09-16.string-length-in-bytes.html)
  //    input by: Martin (http://www.erlenwiese.de/)
  //        note: We feel the main purpose of this function should be to ease the transport of data between php & js
  //        note: Aiming for PHP-compatibility, we have to translate objects to arrays
  //   example 1: serialize(['Kevin', 'van', 'Zonneveld']);
  //   returns 1: 'a:3:{i:0;s:5:"Kevin";i:1;s:3:"van";i:2;s:9:"Zonneveld";}'
  //   example 2: serialize({firstName: 'Kevin', midName: 'van', surName: 'Zonneveld'});
  //   returns 2: 'a:3:{s:9:"firstName";s:5:"Kevin";s:7:"midName";s:3:"van";s:7:"surName";s:9:"Zonneveld";}'

  var val, key, okey,
    ktype = '',
    vals = '',
    count = 0,
    _utf8Size = function (str) {
      var size = 0,
        i = 0,
        l = str.length,
        code = '';
      for (i = 0; i < l; i++) {
        code = str.charCodeAt(i);
        if (code < 0x0080) {
          size += 1;
        } else if (code < 0x0800) {
          size += 2;
        } else {
          size += 3;
        }
      }
      return size;
    },
  _getType = function (inp) {
    var match, key, cons, types, type = typeof inp;

    if (type === 'object' && !inp) {
      return 'null';
    }
    
    if (type === 'object') {
      if (!inp.constructor) {
        return 'object';
      }
      cons = inp.constructor.toString();
      match = cons.match(/(\w+)\(/);
      if (match) {
        cons = match[1].toLowerCase();
      }
      types = ['boolean', 'number', 'string', 'array'];
      for (key in types) {
        if (cons == types[key]) {
          type = types[key];
          break;
        }
      }
    }
    return type;
  },
  type = _getType(mixed_value);

  switch (type) {
  case 'function':
    val = '';
    break;
  case 'boolean':
    val = 'b:' + (mixed_value ? '1' : '0');
    break;
  case 'number':
    val = (Math.round(mixed_value) == mixed_value ? 'i' : 'd') + ':' + mixed_value;
    break;
  case 'string':
    val = 's:' + _utf8Size(mixed_value) + ':"' + mixed_value + '"';
    break;
  case 'array':
  case 'object':
    val = 'a';
    /*
        if (type === 'object') {
          var objname = mixed_value.constructor.toString().match(/(\w+)\(\)/);
          if (objname == undefined) {
            return;
          }
          objname[1] = this.serialize(objname[1]);
          val = 'O' + objname[1].substring(1, objname[1].length - 1);
        }
        */

    for (key in mixed_value) {
      if (mixed_value.hasOwnProperty(key)) {
        ktype = _getType(mixed_value[key]);
        if (ktype === 'function') {
          continue;
        }

        okey = (key.match(/^[0-9]+$/) ? parseInt(key, 10) : key);
        vals += this.serialize(okey) + this.serialize(mixed_value[key]);
        count++;
      }
    }
    val += ':' + count + ':{' + vals + '}';
    break;
  case 'undefined':
    // Fall-through
  default:
    // if the JS object has a property which contains a null value, the string cannot be unserialized by PHP
    val = 'N';
    break;
  }
  if (type !== 'object' && type !== 'array') {
    val += ';';
  }
  return val;
}

function unserialize(data) {
  //  discuss at: http://phpjs.org/functions/unserialize/
  // original by: Arpad Ray (mailto:arpad@php.net)
  // improved by: Pedro Tainha (http://www.pedrotainha.com)
  // improved by: Kevin van Zonneveld (http://kevin.vanzonneveld.net)
  // improved by: Kevin van Zonneveld (http://kevin.vanzonneveld.net)
  // improved by: Chris
  // improved by: James
  // improved by: Le Torbi
  // improved by: Eli Skeggs
  // bugfixed by: dptr1988
  // bugfixed by: Kevin van Zonneveld (http://kevin.vanzonneveld.net)
  // bugfixed by: Brett Zamir (http://brett-zamir.me)
  //  revised by: d3x
  //    input by: Brett Zamir (http://brett-zamir.me)
  //    input by: Martin (http://www.erlenwiese.de/)
  //    input by: kilops
  //    input by: Jaroslaw Czarniak
  //        note: We feel the main purpose of this function should be to ease the transport of data between php & js
  //        note: Aiming for PHP-compatibility, we have to translate objects to arrays
  //   example 1: unserialize('a:3:{i:0;s:5:"Kevin";i:1;s:3:"van";i:2;s:9:"Zonneveld";}');
  //   returns 1: ['Kevin', 'van', 'Zonneveld']
  //   example 2: unserialize('a:3:{s:9:"firstName";s:5:"Kevin";s:7:"midName";s:3:"van";s:7:"surName";s:9:"Zonneveld";}');
  //   returns 2: {firstName: 'Kevin', midName: 'van', surName: 'Zonneveld'}

  var that = this,
    utf8Overhead = function (chr) {
      // http://phpjs.org/functions/unserialize:571#comment_95906
      var code = chr.charCodeAt(0);
      if (code < 0x0080) {
        return 0;
      }
      if (code < 0x0800) {
        return 1;
      }
      return 2;
    };
  error = function (type, msg, filename, line) {
    throw new that.window[type](msg, filename, line);
  };
  read_until = function (data, offset, stopchr) {
    var i = 2,
      buf = [],
      chr = data.slice(offset, offset + 1);

    while (chr != stopchr) {
      if ((i + offset) > data.length) {
        error('Error', 'Invalid');
      }
      buf.push(chr);
      chr = data.slice(offset + (i - 1), offset + i);
      i += 1;
    }
    return [buf.length, buf.join('')];
  };
  read_chrs = function (data, offset, length) {
    var i, chr, buf;

    buf = [];
    for (i = 0; i < length; i++) {
      chr = data.slice(offset + (i - 1), offset + i);
      buf.push(chr);
      length -= utf8Overhead(chr);
    }
    return [buf.length, buf.join('')];
  };
  _unserialize = function (data, offset) {
    var dtype, dataoffset, keyandchrs, keys, contig,
      length, array, readdata, readData, ccount,
      stringlength, i, key, kprops, kchrs, vprops,
      vchrs, value, chrs = 0,
      typeconvert = function (x) {
        return x;
      };

    if (!offset) {
      offset = 0;
    }
    dtype = (data.slice(offset, offset + 1))
      .toLowerCase();

    dataoffset = offset + 2;

    switch (dtype) {
    case 'i':
      typeconvert = function (x) {
        return parseInt(x, 10);
      };
      readData = read_until(data, dataoffset, ';');
      chrs = readData[0];
      readdata = readData[1];
      dataoffset += chrs + 1;
      break;
    case 'b':
      typeconvert = function (x) {
        return parseInt(x, 10) !== 0;
      };
      readData = read_until(data, dataoffset, ';');
      chrs = readData[0];
      readdata = readData[1];
      dataoffset += chrs + 1;
      break;
    case 'd':
      typeconvert = function (x) {
        return parseFloat(x);
      };
      readData = read_until(data, dataoffset, ';');
      chrs = readData[0];
      readdata = readData[1];
      dataoffset += chrs + 1;
      break;
    case 'n':
      readdata = null;
      break;
    case 's':
      ccount = read_until(data, dataoffset, ':');
      chrs = ccount[0];
      stringlength = ccount[1];
      dataoffset += chrs + 2;

      readData = read_chrs(data, dataoffset + 1, parseInt(stringlength, 10));
      chrs = readData[0];
      readdata = readData[1];
      dataoffset += chrs + 2;
      if (chrs != parseInt(stringlength, 10) && chrs != readdata.length) {
        error('SyntaxError', 'String length mismatch');
      }
      break;
    case 'a':
      readdata = {};

      keyandchrs = read_until(data, dataoffset, ':');
      chrs = keyandchrs[0];
      keys = keyandchrs[1];
      dataoffset += chrs + 2;

      length = parseInt(keys, 10);
      contig = true;

      for (i = 0; i < length; i++) {
        kprops = _unserialize(data, dataoffset);
        kchrs = kprops[1];
        key = kprops[2];
        dataoffset += kchrs;

        vprops = _unserialize(data, dataoffset);
        vchrs = vprops[1];
        value = vprops[2];
        dataoffset += vchrs;

        if (key !== i)
          contig = false;

        readdata[key] = value;
      }

      if (contig) {
        array = new Array(length);
        for (i = 0; i < length; i++)
          array[i] = readdata[i];
        readdata = array;
      }

      dataoffset += 1;
      break;
    default:
      error('SyntaxError', 'Unknown / Unhandled data type(s): ' + dtype);
      break;
    }
    return [dtype, dataoffset - offset, typeconvert(readdata)];
  };

  return _unserialize((data + ''), 0)[2];
}