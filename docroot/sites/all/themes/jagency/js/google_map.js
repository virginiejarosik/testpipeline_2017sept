(function($) {
  Drupal.behaviors.agencyMap = {
    attach : function(context, settings) {
      var geocoder;
      var markers = [];
      var map_zoom = Drupal.settings.jafi_pages.map_zoom;
      
      function initialize() {
        geocoder = new google.maps.Geocoder();
        var featureOpts = [{
          featureType: 'landscape.natural.landcover',
          stylers: [{
            color: '#FAFAFA'
          }, {
            visibility: 'simplified'
          }]
        }, {
          featureType: 'administrative',
          elementType: 'labels.text',
          stylers: [{
            visibility: 'on'
          }, {
            color: '#CFCFCF'
          }, {
            lightness: '-35'
          }, {
            weight: '0.1'
          }]
        }, {
          featureType: 'water',
          stylers: [{
            color: '#DEE5ED'
          }]
        }, {
          featureType: 'road',
          elementType: 'labels',
          stylers: [{
            visibility: 'off'
          }]
        }, {
          featureType: 'poi.park',
          elementType: 'labels',
          stylers: [{
            visibility: 'off'
          }]
        }];
        
        var JAFI_MAP = 'jafi_map_style';
        var mapOptions = {
          zoom : parseInt(map_zoom),
          center : new google.maps.LatLng(0, 0),
          mapTypeControlOptions : {
            mapTypeIds : [google.maps.MapTypeId.TERRAIN, JAFI_MAP]
          },
          minZoom : 2,
          maxZoom : 18,
          draggable : false,
          disableDefaultUI : true,
          scrollwheel : false,
          disableDoubleClickZoom : true,
          streetViewControl : false,
          panControl : true,
          zoomControl : true,
          zoomControlOptions : {
            style : google.maps.ZoomControlStyle.SMALL,
          },
          mapTypeId : JAFI_MAP
        };
        var map = new google.maps.Map(document.getElementById('map-canvas'), mapOptions);
        var styledMapOptions = {
          name : 'jafi_map_style'
        };

        var customMapType = new google.maps.StyledMapType(featureOpts, styledMapOptions);

        map.mapTypes.set(JAFI_MAP, customMapType);
        if (Drupal.settings.jafi_pages.address != null) {
          var map_address = Drupal.settings.jafi_pages.address;
          geocoder.geocode({
            'address' : map_address
          }, function(results, status) {
            if (status == google.maps.GeocoderStatus.OK) {
              map.setCenter(results[0].geometry.location);
            } else {
              alert('Geocode was not successful for the following reason: ' + status);
            }
          });
        }
        var maplocations = Drupal.settings.jafi_pages.maplocations;
        window.maps = map;
        setMarkers(map, maplocations);
      }

      // Sets the map on all markers in the array.
      function setAllMap(map) {
        for (var i = 0; i < markers.length; i++) {
          markers[i].setMap(map);
        }
      }

      // Removes the markers from the map, but keeps them in the array.
      function clearMarkers() {
        setAllMap(null);
      }

      // Shows any markers currently in the array.
      function showMarkers() {
        setAllMap(map);
      }

      // Deletes all markers in the array by removing references to them.
      function deleteMarkers() {
        if (markers != null) {
          clearMarkers();
          markers = [];
          setMarkers(maps, Drupal.settings.jafi_pages.maplocations);
        }
      }

      function setMarkers(map, locations) {
        if (locations != null) {
          var active = $('.map .cards div.card:visible').attr('id').replace('card-', '');
          $.each(locations, function(key, value) {
            if (value.id == active) {
              var image = {
                url : '/sites/all/themes/jagency/images/b-marker-cs' + value.color + '.png',
                size : new google.maps.Size(54, 45),
                origin : new google.maps.Point(0, 0),
                anchor : new google.maps.Point(16, 45)
              };
            } else {
              var image = {
                url : '/sites/all/themes/jagency/images/marker-cs' + value.color + '.png',
                size : new google.maps.Size(28, 33),
                origin : new google.maps.Point(0, 0),
                anchor : new google.maps.Point(10, 30)
              };
            }
            if (value.longitude && value.latitude) {
              var valuelocation = new google.maps.LatLng(value.latitude, value.longitude);
              var marker = new google.maps.Marker({
                map : map,
                position : valuelocation,
                icon : image
              });
              google.maps.event.addListener(marker, 'click', function() {
                $.each(markers, function(i, elem) {
                  var icon = elem.getIcon();
                  if (icon.url) {
                    icon = icon.url.replace('b-', '');
                  } else {
                    icon = icon.replace('b-', '');
                  }
                  elem.setIcon(icon);
                  elem.setZIndex(1);
                });
                map.setZoom(parseInt(map_zoom));
                map.panTo(marker.getPosition());
                //map.setCenter(marker.getPosition());
                marker.setIcon('/sites/all/themes/jagency/images/b-marker-cs' + value.color + '.png');
                marker.setZIndex(10);
                $('.map .cards div.card:visible').hide();
                var card = $('#card-' + value.id);
                card.show();
              });
              marker.agency_id = value.id;
              markers.push(marker);
            } else {
              geocoder.geocode({
                'address' : value.location
              }, function(results, status) {
                if (status == google.maps.GeocoderStatus.OK) {
                  var marker = new google.maps.Marker({
                    map : map,
                    position : results[0].geometry.location,
                    icon : image
                  });
                  google.maps.event.addListener(marker, 'click', function() {
                    $.each(markers, function(i, elem) {
                      var icon = elem.getIcon();
                      if (icon.url) {
                        icon = icon.url.replace('b-', '');
                      } else {
                        icon = icon.replace('b-', '');
                      }
                      elem.setIcon(icon);
                      elem.setZIndex(1);
                    });
                    map.setZoom(parseInt(map_zoom));
                    map.panTo(marker.getPosition());
                    //map.setCenter(marker.getPosition());
                    marker.setIcon('/sites/all/themes/jagency/images/b-marker-cs' + value.color + '.png');
                    marker.setZIndex(10);
                    $('.map .cards div.card:visible').hide();
                    var card = $('#card-' + value.id);
                    card.show();
                  });
                  marker.agency_id = value.id;
                  markers.push(marker);
                }
              });
            }
          });
        }
      }

      var numberofevents = $('.map .cards .card').length;
      var CardsBox = $('.map .cards .card');
      if (numberofevents > 0) {
        $('.map .cards div.card:first').show();
        if (numberofevents == 1) {
          $('.map .cards div.card:first .next').hide();
          $('.map .cards div.card .prev').hide();
        }
      }

      $('.map .cards .card .prev').on('click', function(e) {
        var active = $('.map .cards div.card:visible');
        var prev = $('.map .cards div.card:visible').prev();
        if (active.is(':first-child')) {
          prev = $('.map .cards div.card:last-child');
        }
        var id = prev.attr('id').replace('card-', '');
        $.each(markers, function(i, marker) {
          if (marker.agency_id == id) {
            google.maps.event.trigger(marker, 'click');
          }
        });
        return false;
      });

      $('.map .cards .card .next').on('click', function(e) {
        var active = $('.map .cards div.card:visible');
        var next = $('.map .cards div.card:visible').next();
        if (active.is(':last-child')) {
          next = $('.map .cards div.card:first-child');
        }
        var id = next.attr('id').replace('card-', '');
        $.each(markers, function(i, marker) {
          if (marker.agency_id == id) {
            google.maps.event.trigger(marker, 'click');
          }
        });
        return false;
      });

      google.maps.event.addDomListener(window, 'load', initialize);
    }
  };
})(jQuery); 