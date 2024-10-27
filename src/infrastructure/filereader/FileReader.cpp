#include "../../domain/filereader/FileReader.h"
#include "../lib/tinyxml2.h"

#include "../../domain/factories/LocationFactory.h"

namespace file_reader {

    namespace constants {
        static constexpr const auto LOCATION = "locatie";
        static constexpr const auto DESCRIPTION = "beschrijving";
    } // constants

    Location* read_file(const char* path) {
        tinyxml2::XMLDocument doc;
        tinyxml2::XMLError eResult = doc.LoadFile(path);
        if (eResult != tinyxml2::XML_SUCCESS) {
//            std::cerr << "Error loading file: " << eResult << std::endl;
            return nullptr;
        }

        tinyxml2::XMLElement* root = doc.RootElement();
        if (root == nullptr) {
//            std::cerr << "Error: No root element." << std::endl;
            return nullptr;
        }

        const auto element_count = root->ChildElementCount(constants::LOCATION);
        const factories::LocationFactory factory;

        for (tinyxml2::XMLElement* locatie = root->FirstChildElement(constants::LOCATION);
             locatie != nullptr; locatie = locatie->NextSiblingElement(constants::LOCATION)) {

            const char* id = locatie->Attribute("id");
            const char* noord = locatie->Attribute("noord");
            const char* oost = locatie->Attribute("oost");
            const char* zuid = locatie->Attribute("zuid");
            const char* west = locatie->Attribute("west");
            const char* vijand = locatie->Attribute("vijand");
            const char* objectenverborgen = locatie->Attribute("objectenverborgen");
            const char* objectenzichtbaar = locatie->Attribute("objectenzichtbaar");
            const char* naam = locatie->GetText();
            tinyxml2::XMLElement* beschrijving = locatie->FirstChildElement(constants::DESCRIPTION);
            const char* beschrijvingText = beschrijving ? beschrijving->GetText() : "";

        }
        return nullptr;
    }
} // file_reader
