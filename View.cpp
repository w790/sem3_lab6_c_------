//
// Created by pasha on 26.11.2025.
//

#include "View.h"

View::View(Controller* contr, Document* doc): controller(contr), model(doc) {}

void View::render() {
    const auto& primitives = model->getPrimitives();
    for (const auto& primitive : primitives) {
        primitive->draw(); // Вызываем отрисовку каждого примитива
    }
}
