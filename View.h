//
// Created by pasha on 26.11.2025.
//

#pragma once
#include "modeldocument.h"
#include <memory>
#include "primitive.h"

class Document;
class Controller;

class View {
private:
    Controller* controller;
    Document* model;
public:
    View(Controller* contr, Document* doc);
    void render();
};