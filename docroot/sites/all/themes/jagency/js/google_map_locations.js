
var delay_map_location = 100;
(function($) {
  Drupal.behaviors.AgencyLocations = {
    attach : function(context, settings) {

      var geocoder;
      var markers = [];

      function initializeLocation() {
        geocoder = new google.maps.Geocoder();
        var featureOpts = [{
          'featureType' : 'landscape.natural.landcover',
          'stylers' : [{
            'color' : '#FAFAFA'
          }, {
            visibility : 'simplified'
          }]
        }, {
          'featureType' : 'administrative',
          'elementType' : 'labels.text',
          'stylers' : [{
            visibility : 'on'
          }, {
            'color' : '#CFCFCF'
          }, {
            'lightness' : '-35'
          }, {
            'weight' : '0.1'
          }]
        }, {
          'featureType' : 'water',
          'stylers' : [{
            'color' : '#DEE5ED'
          }]
        }, {
          featureType : 'road',
          elementType : 'geometry',
          stylers : [{
            color : '#C3D0D6'
          }]
        }, {
          featureType : 'road',
          elementType : 'labels',
          stylers : [{
            visibility : 'off',
            saturation : -100
          }, {
            color : '#99A6AF'
          }]
        }, {
          'featureType' : 'poi.park',
          'elementType' : 'labels',
          'stylers' : [{
            'visibility' : 'off'
          }]
        }];
        var JAFI_MAP = 'jafi_locations_style';
        var map_zoom = Drupal.settings.jafi_pages.map_zoom;
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

        //setting dynamic width
        var MapsHeight = $(".MapsLocations").width() / 2;
        $("#map480, .LocationSide").width(MapsHeight);

        //pageing
        if ($('#locations li').length < 6) {
          $('.paging').hide();
        }

        var locationsNUM = $(".LocationSide ul.locations li").length;
        var locationTotal = 1;
        var LocationMaxpage = Math.ceil(locationsNUM / locationTotal);
        $(".LocationSide #to_page").html(LocationMaxpage);
        if (LocationMaxpage > 1) {
          $(".LocationSide #pagingArrowR").show();
        }
        $(".LocationSide #pagingArrowR").click(function(event) {
          event.preventDefault();
        });
        var MapLocationtype = Drupal.settings.jafi_pages.maplocationtype;
        if (document.getElementById(MapLocationtype) == null) {
          return;
        }
        var map = new google.maps.Map(document.getElementById(MapLocationtype), mapOptions);

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
              map.setZoom(parseInt(map_zoom));
            } else {
              alert('Geocode was not successful for the following reason: ' + status);
            }
          });
        }
        var maplocations = Drupal.settings.jafi_pages.maplocations;
        window.maps = map;
        setMarkersLocation(map, maplocations);
      }

      // Sets the map on all markers in the array.
      function setAllMapLocation(map) {
        for (var i = 0; i < markers.length; i++) {
          markers[i].setMap(map);
        }
      }

      // Removes the markers from the map, but keeps them in the array.
      function clearMarkersLocation() {
        setAllMapLocation(null);
      }

      // Shows any markers currently in the array.
      function showMarkersLocation() {
        setAllMapLocation(map);
      }

      // Deletes all markers in the array by removing references to them.
      function deleteMarkersLocation() {
        if (markers != null) {
          clearMarkersLocation();
          markers = [];
          setMarkersLocation(maps, Drupal.settings.jafi_pages.maplocations);
        }
      }

      function setMarkersLocation(map, locations) {
        if (locations != null) {
          $.each(locations, function(key, value) {
            setTimeout(function() {
              createMarkerMapLocation(geocoder, map, markers, key, value);
            }, delay_map_location);
          });
        }
      }


      google.maps.event.addDomListener(window, 'load', initializeLocation);
    }
  };
})(jQuery);

function createMarkerMapLocation(geocoder, map, markers, key, value) {
  $(".locations #" + value.id + " .num").html(value.countNum);
  var image = {
    url : '/sites/all/themes/jagency/images/MNlocation/marker-cs5-' + value.countNum + '.png'
  };
  if (value.longitude && value.latitude) {
    var valuelocation = new google.maps.LatLng(value.latitude, value.longitude);
    var marker = new google.maps.Marker({
      map : map,
      position : valuelocation,
      icon : image,
      title : value.title
    });
    var contentHtml = "<div style='width:200px; height:150px; overflow:hidden;'><h3>" + value.titlelabel + "</h3>" + value.contenthtml + "</div>";
    var infowindow = new google.maps.InfoWindow({
      content : contentHtml
    });
    google.maps.event.addListener(marker, 'click', function() {
      $('.gm-style-iw').next().click();
      infowindow.open(map, marker);
    });

    marker.locid = key + 1;
    marker.infowindow = infowindow;
    markers[markers.length] = marker;
    /*google.maps.event.addListener(marker, 'click', function() {
     map.setZoom(5);
     map.panTo(marker.getPosition());
     //map.setCenter(marker.getPosition());
     marker.setIcon('/sites/all/themes/jagency/images/marker-cs5-' + value.countNum + '.png');
     marker.setZIndex(10);
     });*/
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
          icon : image,
          title : value.title
        });
        var contentHtml = "<div style='width:200px; height:150px; overflow:hidden;'><h3>" + value.titlelabel + "</h3>" + value.contenthtml + "</div>";
        var infowindow = new google.maps.InfoWindow({
          content : contentHtml
        });
        google.maps.event.addListener(marker, 'click', function() {
          $('.gm-style-iw').next().click();
          infowindow.open(map, marker);
        });
  
        marker.locid = key + 1;
        marker.infowindow = infowindow;
        markers[markers.length] = marker;
        /*google.maps.event.addListener(marker, 'click', function() {
         map.setZoom(5);
         map.panTo(marker.getPosition());
         //map.setCenter(marker.getPosition());
         marker.setIcon('/sites/all/themes/jagency/images/marker-cs5-' + value.countNum + '.png');
         marker.setZIndex(10);
         });*/
        marker.agency_id = value.id;
        markers.push(marker);
      } else if (status == google.maps.GeocoderStatus.OVER_QUERY_LIMIT) {
        delay_map_location += 100;
        var _this = this;
        setTimeout(function() {
          createMarkerMapLocation(geocoder, map, markers, key, value);
        }, delay_map_location);
      }
    });
  }
}