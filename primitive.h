//
// Created by pasha on 26.11.2025.
//
#pragma once
#include <iostream>
//класс для всех приметивов
class Primitive {
public:
    virtual void draw() = 0;//абстрактный метод
    virtual ~Primitive() = default;
};
//double x, double y, double radius
//Rectangle(double x, double y, double width, double height)
//line(double x1, double y1, double x2, double y2)


class Shape: public Primitive{
private:
    double x;
    double y;
public:
    Shape(double x, double y);
    ~Shape();
    double getx();
    double gety();

};

class Circle: public Shape {
private:
    double radius;
public:
    double getradius();
    Circle(double x , double y , double radius);
    ~Circle() ;
    void draw () override;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double x , double y , double width, double height);
    ~Rectangle();
    double getwidth();
    double getheight();
    void draw () override;
};

class Line : public Shape {
private:
    double x2, y2;

public:
    Line(double x1, double y1, double x2, double y2);

    double getx2();
    double gety2();
    void draw() override;
};