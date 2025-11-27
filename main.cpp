//ВСЕ обработчики GUI здесь + main()

//Controller - это "мозг" приложения, который должен жить все время работы программы и хранить состояние
#include "controller.h"
#include "ExportImport.h"
#include <fstream>
#include <iostream>
#include <string>

//один контроллер для всего приложения
Controller appController;

void buttoncreateCircle (){
    appController.createCircle(20,30,6);
}


void buttoncreateRectangle() {
    appController.createRectangle(10,20,30,40);
}


void buttoncreateLine() {
    appController.createLine(10,15,20,25);
}

void buttonexport() {
    auto exporter= ExportImport();
    std::string filename = "export.txt";
    exporter.exportDocument(appController.getModel(),filename);

}

void buttonimport() {
    auto importer= ExportImport();
    std::string filename = "import.txt";
    importer.importDocument(appController.getModel(),filename);
}



void showPrimitives() {
    const std::vector<std::shared_ptr<Primitive>>& documents = appController.getModel()->getPrimitives();
    for (int i =0;i<documents.size();i++) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(documents[i]) ) {
            std::cout << "Circle " << circle->getx() << " " << circle->gety()
                 << " " << circle->getradius() << std::endl;
        }
        else if (auto rectangle = std::dynamic_pointer_cast<Rectangle>(documents[i])) {
            std::cout << "Rectangle " << rectangle->getx() << " " << rectangle->gety()
                 << " " << rectangle->getwidth() << " " << rectangle->getheight() << std::endl;
        }
        else if (auto line = std::dynamic_pointer_cast<Line>(documents[i])) {
            std::cout << "Line " << line->getx() << " " << line->gety()
                 << " " << line->getx2() << " " << line->gety2() << std::endl;
        }
        else {
            std::cout << "Неизвестный примитив" << std::endl;
        }
    }
}
//показать содержимое файла
void showFileContent(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Файл " << filename << " не существует или пустой!" << std::endl;
        return;
    }

    std::cout << "=== СОДЕРЖИМОЕ " << filename << " ===" << std::endl;
    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        count++;
    }
    file.close();
    std::cout << "=== ВСЕГО СТРОК: " << count << " ===" << std::endl;
}


//Пользователь нажимает кнопку "Добавить круг"
//Controller получает событие (в реальном GUI) или вызывается напрямую (в нашем макете)
//Controller создает объект Circle
//Controller вызывает model->addPrimitive(circle)
//Model добавляет примитив в свой вектор
//Controller вызывает view->render()
//View запрашивает у Model все примитивы
//View вызывает primitive->draw() для каждого примитива
//Пользователь видит результат
int main(){
    std::cout << "Графический векторный редактор" << std::endl;
    std::cout << "Создание объекта круг" << std::endl;
    buttoncreateCircle();
    std::cout << "Создание объекта прямоугольник" << std::endl;
    buttoncreateRectangle();
    std::cout << "Создание объекта линия" << std::endl;
    buttoncreateLine();

    // 2. Показываем что создали
    std::cout << "\n2. ЧТО В ПРОГРАММЕ ДО экспорта:" << std::endl;
    showPrimitives();

    // 3. Экспортируем
    std::cout << "\n3. ЭКСПОРТ В ФАЙЛ:" << std::endl;
    buttonexport();

    // 4. Проверяем что записалось в файл
    std::cout << "\n4. ПРОВЕРЯЕМ ФАЙЛ export.txt:" << std::endl;
    showFileContent("export.txt");

    // 5. Проверяем import.txt до импорта
    std::cout << "\n5. ПРОВЕРЯЕМ ФАЙЛ import.txt ДО импорта:" << std::endl;
    showFileContent("import.txt");

    // 6. Импортируем
    std::cout << "\n6. ИМПОРТ ИЗ ФАЙЛА:" << std::endl;
    buttonimport();

    // 7. Показываем что стало в программе ПОСЛЕ импорта
    std::cout << "\n7. ЧТО В ПРОГРАММЕ ПОСЛЕ импорта:" << std::endl;
    showPrimitives();

}