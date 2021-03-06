#pragma once

#define CANVAS_PROPERTY(camelCaseName, PascalCaseName, Type) \
    inline void set##PascalCaseName(types::Type value) \
    {\
        lcCanvasSetProperty##Type(_canvas, #camelCaseName, value);\
    }\
    inline types::Type get##PascalCaseName()\
    {\
        return lcCanvasGetProperty##Type(_canvas, #camelCaseName);\
    }

#define CONTEXT_PROPERTY(camelCaseName, PascalCaseName, Type) \
    inline void set##PascalCaseName(types::Type value) \
    {\
        lcContextSetProperty##Type(_context, #camelCaseName, value);\
    }\
    inline types::Type get##PascalCaseName()\
    {\
        return lcContextGetProperty##Type(_context, #camelCaseName);\
    }

namespace types
{
    using String = const char *;
    using Float = float;
    using Int = int;
}

struct TextMetrics
{
    float width;
};

extern "C"
{
    struct _Canvas;
    struct _Context;

    _Canvas * lcGetById(const char *name);
    _Canvas * lcGetPreloadedImage(const char *name);
    _Canvas * lcNewCanvas();
    _Context * lcCanvasGetContext(const _Canvas *canvas, const char *name);
    void lcCanvasSetPropertyString(const _Canvas *canvas, const char *name, const char *value);
    void lcCanvasSetPropertyInt(const _Canvas *canvas, const char *name, const int value);
    int lcCanvasGetPropertyInt(const _Canvas *canvas, const char *name);
    void lcCanvasGLTexImage2D(const _Canvas *canvas, const int target, const int level, const int internalformat, const int format, const int type);
    void lcContextSetPropertyString(const _Context *context, const char *name, const char *value);
    void lcContextSetPropertyInt(const _Context *context, const char *name, const int value);
    void lcContextSetPropertyFloat(const _Context *context, const char *name, const float value);
    const char *lcContextGetPropertyString(const _Context *context, const char *name);
    int lcContextGetPropertyInt(const _Context *context, const char *name);
    float lcContextGetPropertyFloat(const _Context *context, const char *name);
    void lcContextClearRect(const _Context *context, const int x, const int y, const int w, const int h);
    void lcContextFillRect(const _Context *context, const int x, const int y, const int w, const int h);
    void lcContextStrokeRect(const _Context *context, const int x, const int y, const int w, const int h);
    void lcContextFillText(const _Context *context, const char *text, const int x, const int y, const int maxWidth);
    void lcContextStrokeText(const _Context *context, const char *text, const int x, const int y, const int maxWidth);
    void lcContextMeasureText(const _Context *context, const char *text, TextMetrics *ptr);
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
    void lcContextRotate(const _Context *context, const float angle);
    void lcContextScale(const _Context *context, const float x, const float y);
    void lcContextTranslate(const _Context *context, const float x, const float y);
    void lcContextTransform(const _Context *context, const float a, const float b, const float c, const float d, const float e, const float f);
    void lcContextSetTransform(const _Context *context, const float a, const float b, const float c, const float d, const float e, const float f);
    void lcContextResetTransform(const _Context *context);
    void lcContextDrawImage(const _Context *context, const _Canvas *canvas, const float x, const float y);
    void lcContextDrawImage2(const _Context *context, const _Canvas *canvas, const float x, const float y, const float w, const float h);
    void lcContextDrawImage3(const _Context *context, const _Canvas *canvas, const float sx, const float sy, const float sw, const float sh, const float x, const float y, const float w, const float h);
}

class Canvas;

class Context
{
    friend class Canvas;

public:

    CONTEXT_PROPERTY(fillStyle, FillStyle, String);
    CONTEXT_PROPERTY(strokeStyle, StrokeStyle, String);
    CONTEXT_PROPERTY(font, Font, String);
    CONTEXT_PROPERTY(textAlign, TextAlign, String);
    CONTEXT_PROPERTY(textBaseLine, TextBaseLine, String);
    CONTEXT_PROPERTY(direction, Direction, String);
    CONTEXT_PROPERTY(globalAlpha, GlobalAlpha, Float);
    CONTEXT_PROPERTY(globalCompositeOperation, GlobalCompositeOperation, String);

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

    inline TextMetrics measureText(const char *text)
    {
        TextMetrics result;
        lcContextMeasureText(_context, text, &result);
        return result;
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

    inline void fill(const char *canvasWindingRules)
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

    inline void rotate(const float angle)
    {
        lcContextRotate(_context, angle);
    }

    inline void scale(const float x, const float y)
    {
        lcContextScale(_context, x, y);
    }

    inline void translate(const float x, const float y)
    {
        lcContextTranslate(_context, x, y);
    }

    inline void transform(const float a, const float b, const float c, const float d, const float e, const float f)
    {
        lcContextTransform(_context, a, b, c, d, e, f);
    }

    inline void setTransform(const float a, const float b, const float c, const float d, const float e, const float f)
    {
        lcContextSetTransform(_context, a, b, c, d, e, f);
    }

    inline void resetTransform()
    {
        lcContextResetTransform(_context);
    }

    void drawImage(const Canvas & canvas, const float x, const float y);
    void drawImage(const Canvas & canvas, const float x, const float y, const float w, const float h);
    void drawImage(const Canvas & canvas, const float sx, const float sy, const float sw, const float sh, const float x, const float y, const float w, const float h);

private:
    Context() = default;
    _Context *_context{nullptr};
};

class Canvas
{
    friend class Context;

public:
    Canvas()
    {
        _canvas = lcNewCanvas();
    }

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

    CANVAS_PROPERTY(width, Width, Int);
    CANVAS_PROPERTY(height, Height, Int);

    void glTexImage2D(const int target, const int level, const int internalFormat, const int format, const int type)
    {
        lcCanvasGLTexImage2D(_canvas, target, level, internalFormat, format, type);
    }

    static Canvas getById(const char *id)
    {
        return Canvas(id);
    }

    static Canvas getPreloadedImage(const char *id)
    {
        return Canvas(lcGetPreloadedImage(id));
    }

private:

    Canvas(_Canvas *canvas)
    {
        _canvas = canvas;
    }

    _Canvas *_canvas{nullptr};
};

inline void Context::drawImage(const Canvas & canvas, const float x, const float y)
{
    lcContextDrawImage(_context, canvas._canvas, x, y);
}

inline void Context::drawImage(const Canvas & canvas, const float x, const float y, const float w, const float h)
{
    lcContextDrawImage2(_context, canvas._canvas, x, y, w, h);
}

inline void Context::drawImage(const Canvas & canvas, const float sx, const float sy, const float sw, const float sh, const float x, const float y, const float w, const float h)
{
    lcContextDrawImage3(_context, canvas._canvas, sx, sy, sw, sh, x, y, w, h);
}

#undef CANVAS_PROPERTY
#undef CONTEXT_PROPERTY

