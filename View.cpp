//
// Created by pasha on 26.11.2025.
//

#include "View.h"
#include "controller.h"

View::View(Controller* contr): controller(contr) {}

void View::render(const std::vector<std::shared_ptr<Primitive>> & primitives) {
    for (const auto& primitive : primitives) {
        primitive->draw(); // Вызываем отрисовку каждого примитива
    }
}
