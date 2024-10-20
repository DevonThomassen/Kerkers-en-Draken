#include "../../domain/filereader/FileReader.h"
#include "../lib/tinyxml2.h"

namespace file_reader {

    void read_file(const char* path) {
        tinyxml2::XMLDocument doc;
        tinyxml2::XMLError eResult = doc.LoadFile(path);
        if (eResult != tinyxml2::XML_SUCCESS) {
//            std::cerr << "Error loading file: " << eResult << std::endl;
            return;
        }

        tinyxml2::XMLElement* root = doc.RootElement();
        if (root == nullptr) {
//            std::cerr << "Error: No root element." << std::endl;
            return;
        }

        for (tinyxml2::XMLElement* locatie = root->FirstChildElement("locatie");
             locatie != nullptr; locatie = locatie->NextSiblingElement("locatie")) {
            const char* id = locatie->Attribute("id");
            const char* noord = locatie->Attribute("noord");
            const char* oost = locatie->Attribute("oost");
            const char* zuid = locatie->Attribute("zuid");
            const char* west = locatie->Attribute("west");
            const char* vijand = locatie->Attribute("vijand");
            const char* objectenverborgen = locatie->Attribute("objectenverborgen");
            const char* objectenzichtbaar = locatie->Attribute("objectenzichtbaar");
            const char* naam = locatie->GetText();
            tinyxml2::XMLElement* beschrijving = locatie->FirstChildElement("beschrijving");
            const char* beschrijvingText = beschrijving ? beschrijving->GetText() : "";

        }
    }

}
