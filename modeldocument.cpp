//
// Created by pasha on 26.11.2025.
//
#pragma once
#include "modeldocument.h"


void Document::addPrimitiveCircle(double x, double y, double r) {
    primitives.push_back(std::make_shared<Circle>(x, y, r));
}

void Document::addPrimitiveRectangle(double x,double y,double width,double height) {
    primitives.push_back(std::make_shared<Rectangle>(x,y,width,height));
}
void Document::addPrimitiveLine(double x1, double y1, double x2,double y2) {
    primitives.push_back(std::make_shared<Line>(x1, y1, x2, y2));
}


const std::vector<std::shared_ptr<Primitive>>& Document::getPrimitives() {
    return primitives;
}//тут надо вернуть объекты primitives