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
