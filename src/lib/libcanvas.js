var LibraryCanvas = {
    $Canvas: {
        canvasList: [],
        contextList: []
    },
    lcGetById: function(canvasName) {
        canvasName = Pointer_stringify(canvasName);
        var element = document.getElementById(canvasName);
        Canvas.canvasList.push(element);
        return Canvas.canvasList.length - 1;
    },
    lcCanvasGetContext: function(canvas, name) {
        canvas = Canvas.canvasList[canvas];
        name = Pointer_stringify(name);
        var context = canvas.getContext(name);
        Canvas.contextList.push(context);
        return Canvas.contextList.length - 1;
    },
    lcCanvasSetPropertyString: function(canvas, name, value) {
        canvas = Canvas.canvasList[canvas];
        name = Pointer_stringify(name);
        value = Pointer_stringify(value);
        canvas[name] = value;
    },
    lcCanvasSetPropertyInt: function(canvas, name, value) {
        canvas = Canvas.canvasList[canvas];
        name = Pointer_stringify(name);
        canvas[name] = value;
    },
    lcContextSetPropertyString: function(context, name, value) {
        context = Canvas.contextList[context];
        name = Pointer_stringify(name);
        value = Pointer_stringify(value);
        context[name] = value;
    },
    lcContextSetPropertyInt: function(context, name, value) {
        context = Canvas.contextList[context];
        name = Pointer_stringify(name);
        context[name] = value;
    },
    lcContextClearRect: function(context, x, y, w, h) {
        context = Canvas.contextList[context];
        context.clearRect(x, y, w, h);
    },
    lcContextFillRect: function(context, x, y, w, h) {
        context = Canvas.contextList[context];
        context.fillRect(x, y, w, h);
    },
    lcContextStrokeRect: function(context, x, y, w, h) {
        context = Canvas.contextList[context];
        context.strokeRect(x, y, w, h);
    },
    lcContextFillText: function(context, text, x, y, maxWidth) {
        context = Canvas.contextList[context];
        text = Pointer_stringify(text);
        context.fillText(text, x, y, maxWidth);
    },
    lcContextStrokeText: function(context, text, x, y, maxWidth) {
        context = Canvas.contextList[context];
        text = Pointer_stringify(text);
        context.strokeText(text, x, y, maxWidth);
    },
    lcContextBeginPath: function(context) {
        context = Canvas.contextList[context];
        context.beginPath();
    },
    lcContextClosePath: function(context) {
        context = Canvas.contextList[context];
        context.closePath();
    },
    lcContextMoveTo: function(context, x, y) {
        context = Canvas.contextList[context];
        context.moveTo(x, y);
    },
    lcContextLineTo: function(context, x, y) {
        context = Canvas.contextList[context];
        context.lineTo(x, y);
    },
    lcContextBezierCurveTo: function(context, cp1x, cp1y, cp2x, cp2y, x, y) {
        context = Canvas.contextList[context];
        context.bezierCurveTo(cp1x, cp1y, cp2x, cp2y, x, y);
    },
    lcContextQuadraticCurveTo: function(context, cp1x, cp1y, x, y) {
        context = Canvas.contextList[context];
        context.quadraticCurveTo(cp1x, cp1y, x, y);
    },
    lcContextArc: function(context, x, y, radius, startAngle, endAngle, anticlockwise) {
        context = Canvas.contextList[context];
        context.arc(x, y, radius, startAngle, endAngle, anticlockwise);
    },
    lcContextArcTo: function(context, x1, y1, x2, y2, radius) {
        context = Canvas.contextList[context];
        context.arcTo(x1, y1, x2, y2, radius);
    },
    lcContextEllipse: function(context, x, y, radiusX, radiusY, rotation, startAngle, endAngle, anticlockwise) {
        context = Canvas.contextList[context];
        context.ellipse(x, y, radiusX, radiusY, rotation, startAngle, endAngle, anticlockwise);
    },
    lcContextRect: function(context, x, y, width, height) {
        context = Canvas.contextList[context];
        context.rect(x, y, width, height);
    },
    lcContextFill: function(context) {
        context = Canvas.contextList[context];
        context.fill();
    },
    lcContextStroke: function(context) {
        context = Canvas.contextList[context];
        context.stroke();
    },
    lcContextIsPointInPath: function(context, x, y) {
        context = Canvas.contextList[context];
        return context.isPointInPath(x, y);
    },
    lcContextIsPointInStroke: function(context, x, y) {
        context = Canvas.contextList[context];
        return context.isPointInStroke(x, y);
    },
    lcContextMeasureText: function(context, text, ptr) {
        context = Canvas.contextList[context];
        var textMetrics = context.measureText(text);
        {{{ makeSetValue('ptr', '0', 'textMetrics.width', 'float') }}};
    }
};

autoAddDeps(LibraryCanvas, '$Canvas');
mergeInto(LibraryManager.library, LibraryCanvas);
