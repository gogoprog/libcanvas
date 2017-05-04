#pragma once

extern "C"
{
    struct _Canvas;
    struct _Context;

    _Canvas * lcGetById(const char *name);
    _Context * lcCanvasGetContext(const _Canvas *canvas, const char *name);
    void lcCanvasSetPropertyString(const _Canvas *canvas, const char *name, const char *value);
    void lcCanvasSetPropertyInt(const _Canvas *canvas, const char *name, const int value);
    void lcContextSetPropertyString(const _Context *context, const char *name, const char *value);
    void lcContextSetPropertyInt(const _Context *context, const char *name, const int value);
    void lcContextClearRect(const _Context *context, const int x, const int y, const int w, const int h);
    void lcContextFillRect(const _Context *context, const int x, const int y, const int w, const int h);
    void lcContextStrokeRect(const _Context *context, const int x, const int y, const int w, const int h);
    void lcContextFillText(const _Context *context, const char *text, const int x, const int y, const int maxWidth);
    void lcContextStrokeText(const _Context *context, const char *text, const int x, const int y, const int maxWidth);
    void lcContextMeasureText(const _Context *context, const char *text);
    void lcContextBeginPath(const _Context *context);
    void lcContextClosePath(const _Context *context);
    void lcContextMoveTo(const _Context *context, const float x, const float y);
    void lcContextLineTo(const _Context *context, const float x, const float y);
    void lcContextBezierCurveTo(const _Context *context, const float cp1x, const float cp1y, const float cp2x, const float cp2y, const float x, const float y);
    void lcContextQuadraticCurveTo(const _Context *context, const float cp1x, const float cp1y, const float x, const float y);
    void lcContextArc(const _Context *context, const float x, const float y, const float radius, const float startAngle, const float endAngle, const bool anticlockwise);
    void lcContextArcTo(const _Context *context, const float x1, const float y1, const float x2, const float y2, const float radius);
    void lcContextEllipse(const _Context *context, const float x, const float y, const float radiusX, const float radiusY, const float rotation, const float startAngle, const float endAngle, const bool anticlockwise);
    void lcContextRect(const _Context *context, const float x, const float y, const float width, const float height);
    void lcContextFill(const _Context *context);
    void lcContextStroke(const _Context *context);
    bool lcContextIsPointInPath(const _Context *context, const float x, const float y);
    bool lcContextIsPointInStroke(const _Context *context, const float x, const float y);
}

class Context
{
    friend class Canvas;

public:
    inline void setFillStyle(const char *name)
    {
        lcContextSetPropertyString(_context, "fillStyle", name);
    }

    inline void setStrokeStyle(const char *name)
    {
        lcContextSetPropertyString(_context, "strokeStyle", name);
    }

    inline void setFont(const char *name)
    {
        lcContextSetPropertyString(_context, "font", name);
    }

    inline void setTextAlign(const char *value)
    {
        lcContextSetPropertyString(_context, "textAlign", value);
    }

    inline void setTextBaseLine(const char *value)
    {
        lcContextSetPropertyString(_context, "textBaseLine", value);
    }

    inline void setDirection(const char *value)
    {
        lcContextSetPropertyString(_context, "direction", value);
    }

    inline void clearRect(const int x, const int y, const int w, const int h)
    {
        lcContextClearRect(_context, x, y, w, h);
    }

    inline void fillRect(const int x, const int y, const int w, const int h)
    {
        lcContextFillRect(_context, x, y, w, h);
    }

    inline void strokeRect(const int x, const int y, const int w, const int h)
    {
        lcContextStrokeRect(_context, x, y, w, h);
    }

    inline void fillText(const char *text, const int x, const int y, const int maxWidth)
    {
        lcContextFillText(_context, text, x, y, maxWidth);
    }

    inline void strokeText(const char *text, const int x, const int y, const int maxWidth)
    {
        lcContextStrokeText(_context, text, x, y, maxWidth);
    }

    inline void measureText(const char *text) // todo: return TextMetrics
    {
        lcContextMeasureText(_context, text);
    }

    inline void beginPath()
    {
        lcContextBeginPath(_context);
    }

    inline void closePath()
    {
        lcContextClosePath(_context);
    }

    inline void moveTo(const float x, const float y)
    {
        lcContextMoveTo(_context, x, y);
    }

    inline void lineTo(const float x, const float y)
    {
        lcContextLineTo(_context, x, y);
    }

    inline void bezierCurveTo(const float cp1x, const float cp1y, const float cp2x, const float cp2y, const float x, const float y)
    {
        lcContextBezierCurveTo(_context, cp1x, cp1y, cp2x, cp2y, x, y);
    }

    inline void quadraticCurveTo(const float cp1x, const float cp1y, const float x, const float y)
    {
        lcContextQuadraticCurveTo(_context, cp1x, cp1y, x, y);
    }

    inline void arc(const float x, const float y, const float radius, const float startAngle, const float endAngle, const bool anticlockwise = false)
    {
        lcContextArc(_context, x, y, radius, startAngle, endAngle, anticlockwise);
    }

    inline void arcTo(const float x1, const float y1, const float x2, const float y2, const float radius)
    {
        lcContextArcTo(_context, x1, y1, x2, y2, radius);
    }

    inline void ellipse(const float x, const float y, const float radiusX, const float radiusY, const float rotation, const float startAngle, const float endAngle, const bool anticlockwise = false)
    {
        lcContextEllipse(_context, x, y, radiusX, radiusY, rotation, startAngle, endAngle, anticlockwise);
    }

    inline void rect(const float x, const float y, const float width, const float height)
    {
        lcContextRect(_context, x, y, width, height);
    }

    inline void fill()
    {
        lcContextFill(_context);
    }
    
    inline void stroke()
    {
        lcContextStroke(_context);
    }

    inline bool isPointInPath(const float x, const float y)
    {
        return lcContextIsPointInPath(_context, x, y);
    }

    inline bool isPointInStroke(const float x, const float y)
    {
        return lcContextIsPointInStroke(_context, x, y);
    }

private:
    Context() = default;
    _Context *_context{nullptr};
};

class Canvas
{
public:
    Canvas(const char *id)
    {
        _canvas = lcGetById(id);
    }

    Context getContext(const char *name)
    {
        Context result;
        result._context = lcCanvasGetContext(_canvas, name);
        return result;
    }

    void setWidth(const int value)
    {
        lcCanvasSetPropertyInt(_canvas, "width", value);
    }

    void setHeight(const int value)
    {
        lcCanvasSetPropertyInt(_canvas, "height", value);
    }

private:
    _Canvas *_canvas{nullptr};
};
