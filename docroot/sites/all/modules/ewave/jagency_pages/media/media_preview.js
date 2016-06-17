Drupal.behaviors.JagencyMediaUpdate = {
  attach : function(context, settings) {
    if ( typeof ($) == "undefined") {
      $ = jQuery;
    }
    xOffset = -20;
    yOffset = 40;   
    
    $(".media-thumbnail img").live({
        mouseenter: function (e) {
          this.t  = this.alt;
          this.title = "";
          var pathimage = $(this).attr('src').replace('styles/media_thumbnail/public/', '');
          var c = (this.t != "") ? "<br/>" + this.t : "";
          $("body").append("<p id='preview' style='width:30%;display: none;position:absolute;border:3px solid #ccc;background:#333;padding:5px;color:#fff;box-shadow: 4px 4px 3px rgba(103, 115, 130, 1);'><img width='100%' style='display: block' src='"+ pathimage +"'/>"+ c +"</p>");
          $("#preview").css("top",(e.pageY - xOffset) + "px").css("left",(e.pageX + yOffset) + "px").fadeIn("slow");
        },
        mouseleave: function (e) {
          this.title = this.t;
          $("#preview").remove();
        }
    });
    $("a.preview").mousemove(function(e){
      $("#preview")
        .css("top",(e.pageY - xOffset) + "px")
        .css("left",(e.pageX + yOffset) + "px");
    });
  }
}