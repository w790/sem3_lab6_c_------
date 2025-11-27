//
// Created by pasha on 26.11.2025.
//
#include <iostream>
#include "primitive.h"

Shape::Shape(double x, double y): x(x), y(y) {}

Shape::~Shape(){};

double Shape::getx(){
    return x;
}

double Shape::gety(){
    return y;
}


Circle::Circle(double x , double y , double radius): Shape(x,y), radius(radius) {}
Circle::~Circle() {}
double Circle::getradius() {
    return radius;
}
void Circle::draw () {
    std::cout<<"Отрисовал круг с координатами и радиусом соотвенственно: x = "<<getx()<<" y = "<<gety()<<" radius = "<<radius<<std::endl;
}

Rectangle::Rectangle(double x , double y , double width, double height): Shape(x,y), width(width),height(height){}
Rectangle::~Rectangle() {}
double Rectangle::getwidth() {
    return width;
}
double Rectangle::getheight() {
    return height;
}
void Rectangle::draw () {
    std::cout<<"Отрисовал прямоугольник с координатами,шириной и высотой соотвенственно: x = "<<getx()<<" y = "<<gety() <<" width = "<<width << " height = "<<height<< std::endl;
}

Line::Line(double x1, double y1, double x2, double y2)
    : Shape(x1,y1), x2(x2), y2(y2) {}
double Line::getx2() {
    return x2;
}
double Line::gety2() {
    return y2;
}

void Line::draw() {
    std::cout << "Отрисовал линию  (" << getx() << ", " << gety() << ") to (" << x2 << ", " << y2 << ")" << std::endl;
}