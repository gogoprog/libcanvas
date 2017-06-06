#include "../lib/libcanvas.h"
#include <iostream>

int main()
{
    auto canvas = Canvas::getById("canvas");

    canvas.setWidth(512);
    canvas.setHeight(512);

    auto context = canvas.getContext("2d");

    context.setGlobalAlpha(0.5f);
    
    context.setFillStyle("red");
    context.fillRect(10, 10, 100, 100);
    context.clearRect(32, 32, 32, 32);
    context.setStrokeStyle("cyan");
    context.strokeRect(300, 10, 100, 100);

    context.setGlobalAlpha(1.0f);

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

    context.rect(10, 10, 100, 100);
    context.stroke();

    std::cout << "isPointInPath? " << context.isPointInPath(10, 10) << std::endl;

    auto textMetrics = context.measureText("Foobar");

    std::cout << textMetrics.width << std::endl;

    context.scale(2, 2);
    context.translate(0, 100);

    context.rect(10, 10, 100, 100);
    context.stroke();

    auto otherCanvas = Canvas();
    auto otherContext = otherCanvas.getContext("2d");
    otherContext.setFont("12px serif");
    otherContext.setFillStyle("white");
    otherContext.fillText("Other canvas", 32, 32, 256);

    context.setTransform(1, 0, 0, 1, 0, 0);
    context.drawImage(otherCanvas, 128, 128);

    return 0;
}