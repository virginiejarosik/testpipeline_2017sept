Drupal.behaviors.agencyAutCom = {
  attach : function(context, settings) {
    if (typeof($) == "undefined") {
      $ = jQuery;
    }
    /*if(typeof($("#search") != "undefined") && $("#search").length) {
      $("#search").autocomplete({
        appendTo: '#menu-container',
        source : function(request, response) {
          $.getJSON("/search/json", {
            'filter' : request.term
          }, function(json) {
            response($.map(json.nodes, function(item) {
              return {label : __highlight(item.node.title, request.term), value : item.node.title, path : item.node.path };
            }));
          });
        },
        minLength : 2,
        select: function(e, ui) {
          location.href = ui.item.path;
        },
        open : function(e, ui) {
          $(this).removeClass("ui-corner-all").addClass("ui-corner-top");
        },
        close : function() {
          $(this).removeClass("ui-corner-top").addClass("ui-corner-all");
        }
      }).data("autocomplete")._renderItem = function(ul, item) {
        return $("<li></li>").data("item.autocomplete", item).append("<a href='" + item.path + "' title='" + item.value + "'>" + item.label + "</a>").appendTo(ul);
      };
    }*/
  }
};

function __highlight(s, t) {
  var matcher = new RegExp("(" + $.ui.autocomplete.escapeRegex(t) + ")", "ig");
  return s.replace(matcher, "<strong>$1</strong>");
}