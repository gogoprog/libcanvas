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
    }
};

autoAddDeps(LibraryCanvas, '$Canvas');
mergeInto(LibraryManager.library, LibraryCanvas);
