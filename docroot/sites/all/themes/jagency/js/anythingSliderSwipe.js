
/******************************************
 Swipe Demo - without using jQuery Mobile

   ** Swipe across the navigation tabs **

******************************************/
var setupSwipe = function (slider) {
    var time = 1000,
        // allow movement if < 1000 ms (1 sec)
        range = 50,
        // swipe movement of 50 pixels triggers the slider
        x = 0,
        t = 0,
        touch = "ontouchend" in document,
        st = (touch) ? 'touchstart' : 'mousedown',
        mv = (touch) ? 'touchmove' : 'mousemove',
        en = (touch) ? 'touchend' : 'mouseup';

    slider.$window.add(slider.$controls)
        .bind(st, function (e) {
            // prevent image drag (Firefox)
            e.preventDefault();
            t = (new Date()).getTime();
            x = e.originalEvent.touches ? e.originalEvent.touches[0].pageX : e.pageX;
        })
        .bind(en, function (e) {
            t = 0;
            x = 0;
        })
        .bind(mv, function (e) {
            e.preventDefault();
            var newx = e.originalEvent.touches ? e.originalEvent.touches[0].pageX : e.pageX,
                r = (x === 0) ? 0 : Math.abs(newx - x),
                // allow if movement < 1 sec
                ct = (new Date()).getTime();
            if (t !== 0 && ct - t < time && r > range) {
                if (newx < x) {
                    if ($(this).hasClass('anythingControls')) {
                        slider.$controls.find('.next').trigger('click');
                    } else {
                        slider.goForward();
                    }
                    return false;
                }
                if (newx > x) {
                    if ($(this).hasClass('anythingControls')) {
                        slider.$controls.find('.prev').trigger('click');
                    } else {
                        slider.goBack();
                    }
                }
                t = 0;
                x = 0;
                return false;
            }
        });
};