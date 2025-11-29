    //
// Created by pasha on 26.11.2025.
//

#pragma once
#include "modeldocument.h"
#include "View.h"
#include <memory>

//Пользователь нажимает кнопку "Добавить круг"
//Controller получает событие (в реальном GUI) или вызывается напрямую (в нашем макете)
//Controller создает объект Circle
//Controller вызывает model->addPrimitive(circle)
//Model добавляет примитив в свой вектор
//Controller вызывает view->render()
//View запрашивает у Model все примитивы
//View вызывает primitive->draw() для каждого примитива
//Пользователь видит результат
class Controller{
private:
    std::unique_ptr<Document> model;
    std::unique_ptr<View> view;
public:
    Controller();
    ~Controller();

    Document* getModel();
    void createCircle(double x, double y, double r);
    void createRectangle(double x , double y, double width, double height);
    void createLine(double x1,double y1,double x2 ,double y2 );
};