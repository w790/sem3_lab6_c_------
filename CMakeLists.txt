cmake_minimum_required(VERSION 3.14)
project(sem3_lab6_c--)

# Устанавливаем версию проекта (добавлено)
if(DEFINED ENV{PROJECT_VERSION_MAJOR})
    set(PROJECT_VERSION_MAJOR $ENV{PROJECT_VERSION_MAJOR})
    set(PROJECT_VERSION_MINOR $ENV{PROJECT_VERSION_MINOR})
    set(PROJECT_VERSION_PATCH $ENV{PROJECT_VERSION_PATCH})
else()
    set(PROJECT_VERSION_MAJOR 1)
    set(PROJECT_VERSION_MINOR 0)
    set(PROJECT_VERSION_PATCH 0)
endif()

#устанавливаем стандарт
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ЯВНО указываем где создавать исполняемый файл
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#основная программа (обновлен список файлов)
add_executable(main main.cpp controller.cpp controller.h ExportImport.cpp ExportImport.h modeldocument.cpp modeldocument.h primitive.cpp primitive.h View.cpp View.h)

#include директории
target_include_directories(main PRIVATE .)

# Добавляем CPack для создания пакетов (добавлено)
include(CPack)