//
// Created by pasha on 26.11.2025.
//

#pragma once
#include "modeldocument.h"

class ExportImport {
public:
    ExportImport();
    ~ExportImport();
    void exportDocument(Document* doc,std::string& filename);
    void importDocument(Document* doc,std::string& filename);
};