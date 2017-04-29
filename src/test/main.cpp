#include <iostream>
#include "../lib/libcanvas.h"

int main()
{
    std::cout << "libcanvas" << std::endl;

    canvas * myCanvas = canvas_add_canvas("canvas");

    canvas_set_active_canvas(myCanvas);

    canvas_set_size(512, 512, 1);

    return 0;
}