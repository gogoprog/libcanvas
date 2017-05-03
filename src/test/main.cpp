#include "../lib/libcanvas.h"

int main()
{
    auto canvas = Canvas("canvas");

    canvas.setWidth(512);
    canvas.setHeight(512);

    auto context = canvas.getContext("2d");

    context.setFillStyle("red");
    context.fillRect(10, 10, 100, 100);
    context.clearRect(32, 32, 32, 32);
    context.setStrokeStyle("cyan");
    context.strokeRect(300, 10, 100, 100);

    context.setFont("12px serif");
    context.setFillStyle("white");
    context.fillText("libcanvas test application", 32, 32, 256);
    context.strokeText("libcanvas test application", 32, 256, 256);

    context.beginPath();
    context.setStrokeStyle("blue");
    context.moveTo(20, 20);
    context.lineTo(200, 20);
    context.stroke();

    context.beginPath();
    context.setStrokeStyle("green");
    context.moveTo(20, 20);
    context.lineTo(120, 120);
    context.stroke();

    return 0;
}