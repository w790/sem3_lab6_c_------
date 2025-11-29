//
// Created by pasha on 26.11.2025.
//

#pragma once
#include <memory>
#include "primitive.h"

class Controller;

class View {
private:
    Controller* controller;
public:
    View(Controller* contr);
    void render(const std::vector<std::shared_ptr<Primitive>> & primitives);
};
