//
// Created by pasha on 26.11.2025.
//
// Функционал для макетирования – следующий:
// 1) создание нового документа;
// 2) импорт документа из файла;
// 3) экспорт документа в файл;
// 4) создание графического примитива;
// 5) удаление графического примитива.

#pragma once
#include "controller.h"


Controller::Controller() {
    model = std::make_unique<Document>();
    view = std::make_unique<View>(this, model.get());
}

Controller::~Controller() = default;

Document* Controller::getModel() {
    return model.get();//.get() для unique_ptr
}

void Controller::createCircle(double x, double y, double r) {
    //{model.addPrimitive(double x, double y, double r)
    //view.render()  а в рендер этой функции у меня будет вызываться  getPrimitives и после этого у примитива будет вызываться draw()
    model->addPrimitiveCircle(x, y, r);
    view->render();
}

void Controller::createRectangle(double x , double y, double width, double height) {
    model->addPrimitiveRectangle(x, y , width, height);
    view->render();
}
void Controller::createLine(double x1, double y1, double x2, double y2) {
    model->addPrimitiveLine(x1, y1, x2, y2);
    view->render();
}
