#pragma once
extern "C" {
    struct canvas;
    struct image;

    canvas * canvas_add_canvas( const char * name );
    void canvas_set_active_canvas( const canvas * c );
    void canvas_set_size( const int width, const int height, const float pixel_ratio );
    void canvas_set_global_alpha( const float value );
    void canvas_set_transform( const float scaleX, const float skewX, const float skewY, const float scaleY, const float translationX, const float translationY );
    void canvas_clear_rect( const float x, const float y, const float w, const float h );
    void canvas_rotate( const float angle );
    const image * canvas_load_image( const char * filename );
    void canvas_draw_image( const image * imageHandle, const float x, const float y, const float w, const float h );
    void canvas_draw_image_clipped( const image * imageHandle, const float sx, const float sy, const float sw, const float sh, const float x, const float y, const float w, const float h );
    int canvas_get_image_width( const image * imageHandle );
    int canvas_get_image_height( const image * imageHandle );
    int canvas_is_image_valid( const image * imageHandle );
    void canvas_get_size( int * width, int * height );
    bool canvas_is_visible( const canvas * c );
}