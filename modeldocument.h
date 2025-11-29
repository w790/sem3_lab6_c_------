//
// Created by pasha on 26.11.2025.
//
#pragma once

#include "primitive.h"
#include <vector>
#include <memory>

class Document {
private:
    std::vector<std::shared_ptr<Primitive>>  primitives;
public:
    void addPrimitiveCircle(double x, double y, double r);
    void addPrimitiveRectangle(double x,double y,double width,double height);
    void addPrimitiveLine(double x1, double y1, double x2,double y2);

    std::vector<std::shared_ptr<Primitive>>& getPrimitives();
};