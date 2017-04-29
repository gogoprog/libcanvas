var LibraryCanvas = {
    $Canvas: {
        canvasList: [],
        contextList: [],
        activeCanvas: null,
        activeContext: null,
        ratio: 1,
        imageList: []
    },
    canvas_add_canvas__deps: ['$SDL'],
    canvas_add_canvas: function(canvasName) {
        canvasName = Pointer_stringify(canvasName);
        var element = document.getElementById(canvasName);
        ['touchstart', 'touchend', 'touchmove', 'mousedown', 'mouseup', 'mousemove', 'DOMMouseScroll', 'mousewheel', 'wheel', 'mouseout'].forEach(function(event) {
            element.addEventListener(event, SDL.receiveEvent, true);
        });
        Canvas.canvasList.push(element);
        Canvas.contextList.push(element.getContext('2d'));


        return Canvas.canvasList.length - 1;
    },
    canvas_set_active_canvas: function(index) {
        Canvas.activeContext = Canvas.contextList[index];
        Canvas.activeCanvas = Canvas.canvasList[index];
        Module.canvas = Canvas.activeCanvas;
    },
    canvas_set_size__deps: ['$Browser'],
    canvas_set_size: function(width, height, pixel_ratio) {
        var backingStoreRatio = Canvas.activeContext.webkitBackingStorePixelRatio ||
                           Canvas.activeContext.mozBackingStorePixelRatio ||
                           Canvas.activeContext.msBackingStorePixelRatio ||
                           Canvas.activeContext.oBackingStorePixelRatio ||
                           Canvas.activeContext.backingStorePixelRatio || 1;

        var ratio = pixel_ratio / backingStoreRatio;
        if ( ratio > 2 ) {
            ratio = 2;
        }

        Canvas.ratio = ratio;
        Canvas.activeCanvas.width = width * ratio;
        Canvas.activeCanvas.height = height * ratio;
        Canvas.activeCanvas.style.width = width + 'px';
        Canvas.activeCanvas.style.height = height + 'px';
    },
    canvas_set_global_alpha: function(value) {
        Canvas.activeContext.globalAlpha = value;
    },
    canvas_set_transform: function(scaleX, skewX, skewY, scaleY, translationX, translationY) {
        Canvas.activeContext.setTransform(scaleX * Canvas.ratio , skewX * Canvas.ratio, skewY * Canvas.ratio, scaleY * Canvas.ratio, translationX * Canvas.ratio, translationY * Canvas.ratio);
    },
    canvas_clear_rect: function(x, y, w, h) {
        Canvas.activeContext.clearRect(x, y, w, h);
    },
    canvas_rotate: function(angle) {
        Canvas.activeContext.rotate(angle);
    },
    canvas_load_image: function(filename) {
        filename = PATH.resolve(Pointer_stringify(filename));
        var raw = Module.preloadedImages[filename];

        if(raw) {
            Canvas.imageList.push(raw);
            return Canvas.imageList.length;
        }

        Runtime.warnOnce('Cannot find preloaded image ' + filename);

        return 0;
    },
    canvas_draw_image: function(imageHandle, x, y, width, height) {
        var image = Canvas.imageList[imageHandle - 1];

        Canvas.activeContext.drawImage(image, x, y, width, height);
    },
    canvas_draw_image_clipped: function(imageHandle, sx, sy, sw, sh, x, y, width, height) {
        var image = Canvas.imageList[imageHandle - 1];

        Canvas.activeContext.drawImage(image, sx, sy, sw, sh, x, y, width, height);
    },
    canvas_get_image_width: function(imageHandle) {
        return Canvas.imageList[imageHandle - 1].width;
    },
    canvas_get_image_height: function(imageHandle) {
        return Canvas.imageList[imageHandle - 1].height;
    },
    canvas_is_image_valid: function(imageHandle) {
        return imageHandle !== 0;
    },
    canvas_get_size: function( width_ptr, height_ptr ) {
        {{{ makeSetValue('width_ptr', '0', 'Canvas.activeCanvas.clientWidth', 'i32') }}};
        {{{ makeSetValue('height_ptr', '0', 'Canvas.activeCanvas.clientHeight', 'i32') }}};
    },
    canvas_is_visible: function( canvas_index ) {
        if ( window === undefined ) {
            return false;
        }
        var computed_style = window.getComputedStyle( Canvas.canvasList[canvas_index] );
        return computed_style.visibility === 'visible' && computed_style.display !== 'none';
    }
};

autoAddDeps(LibraryCanvas, '$Canvas');
mergeInto(LibraryManager.library, LibraryCanvas);
