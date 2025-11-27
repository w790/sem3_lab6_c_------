//
// Created by pasha on 26.11.2025.
//
#include <fstream>
#include <iostream>
#include "ExportImport.h"
#include <sstream> //для std::istringstream
#include <memory> //для dynamic_pointer_cast

ExportImport::ExportImport(){}

ExportImport::~ExportImport(){}

// Берем данные ИЗ программы и сохраняем В файл
void ExportImport::exportDocument(Document* doc,std::string& filename) {
    std::ofstream file(filename);//объект для записи в файл

    if (!file.is_open()) {
        std::cout<<"Error open" << std::endl;
        return;
    }

    const std::vector<std::shared_ptr<Primitive>>& documents = doc->getPrimitives();
    for (int i =0;i<documents.size();i++) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(documents[i]) ) {
            file << "Circle " << circle->getx() << " " << circle->gety()
                 << " " << circle->getradius() << std::endl;
        }
        else if (auto rectangle = std::dynamic_pointer_cast<Rectangle>(documents[i])) {
            file << "Rectangle " << rectangle->getx() << " " << rectangle->gety()
                 << " " << rectangle->getwidth() << " " << rectangle->getheight() << std::endl;
        }
        else if (auto line = std::dynamic_pointer_cast<Line>(documents[i])) {
            file << "Line " << line->getx() << " " << line->gety()
                 << " " << line->getx2() << " " << line->gety2() << std::endl;
        }
        else {
            std::cout << "Неизвестный примитив" << std::endl;
        }
    }
    file.close();

    std::cout << "Данные записаны в файл!" << std::endl;

}
// Берем данные ИЗ файла и загружаем В программу
void ExportImport::importDocument(Document* doc,std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout<<"Error open" << std::endl;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);

        std::string type;
        iss >> type;
        if (type == "Circle") {
            double x1,y1,r;
            iss >> x1 >> y1 >> r;
            doc->addPrimitiveCircle(x1,y1,r);
        }
        else if (type == "Rectangle") {
            double x , y, width, height;
            iss >> x >> y >>width>>height;
            doc->addPrimitiveRectangle(x,y,width,height);
        }
        else {
            double x1,y1,x2,y2;
            iss >> x1 >> y1 >> x2 >> y2;
            doc->addPrimitiveLine(x1, y1, x2 ,y2);
        }
    }
    file.close();

}