#include "../../domain/filereader/FileReader.h"
#include "../lib/tinyxml2.h"
#include <iostream>
#include "../../domain/builder/DungeonBuilder.hpp"
#include "../../domain/common/Direction.hpp"
#include "../../domain/common/Location.hpp"

namespace file_reader {
    /*
     * Constants used in the XML file
     */
    namespace constants {
        static constexpr const auto ID = "id";
        static constexpr const auto LOCATION = "locatie";
        static constexpr const auto DESCRIPTION = "beschrijving";

        static constexpr const auto NORTH = "noord";
        static constexpr const auto EAST = "oost";
        static constexpr const auto SOUTH = "zuid";
        static constexpr const auto WEST = "west";

        static const char* directions[] = {constants::NORTH, constants::EAST, constants::SOUTH, constants::WEST};
        static Direction dirEnums[] = {Direction::North, Direction::East, Direction::South, Direction::West};
    } // constants

    [[nodiscard]] std::optional<int> static try_parse_int(const char* str) {
        if (str == nullptr) {
            return std::nullopt;
        }
        try {
            const auto parsed = std::stoi(str);
            return std::make_optional(parsed);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return std::nullopt;
        }
    }

    Array<Location>* read_file(const char* path) {
        tinyxml2::XMLDocument doc;
        tinyxml2::XMLError eResult = doc.LoadFile(path);
        if (eResult != tinyxml2::XML_SUCCESS) {
            std::cerr << "Error loading file: " << eResult << std::endl;
            return nullptr;
        }

        tinyxml2::XMLElement* root = doc.RootElement();
        if (root == nullptr) {
            std::cerr << "Error: No root element." << std::endl;
            return nullptr;
        }

        const auto element_count = root->ChildElementCount(constants::LOCATION);
        builder::DungeonBuilder builder(element_count);

        // Add all locations
        for (tinyxml2::XMLElement* location = root->FirstChildElement(constants::LOCATION);
             location != nullptr; location = location->NextSiblingElement(constants::LOCATION)) {

            const auto id_string = location->Attribute(constants::ID);
            const auto name = location->GetText();
            const auto descriptionElement = location->FirstChildElement(constants::DESCRIPTION);
            const auto description = descriptionElement ? descriptionElement->GetText() : "";
            const auto id = try_parse_int(id_string);
            if (!id.has_value()) {
                continue;
            }
            builder.add_location(id.value(), name, description);
        }

        for (tinyxml2::XMLElement* location = root->FirstChildElement(constants::LOCATION);
             location != nullptr; location = location->NextSiblingElement(constants::LOCATION)) {

            const auto id_string = location->Attribute(constants::ID);
            const auto id = try_parse_int(id_string);
            if (!id.has_value()) {
                continue;
            }

            // Directions
            for (int i = 0; i < 4; ++i) {
                const auto dir = location->Attribute(constants::directions[i]);
                if (dir != nullptr) {
                    const auto parsedDir = try_parse_int(dir);
                    if (parsedDir.has_value()) {
                        const auto result = builder.bind_locations(id.value(), parsedDir.value(),
                                                                   constants::dirEnums[i]);
                        if (result != 0) {
                            result == -1 ? std::cerr << "Source not found: " << id.value() << std::endl
                                         : std::cerr << "Destination not found: " << parsedDir.value() << std::endl;
                            std::cerr << "Error binding locations: " << result << std::endl;
                        }
                    }
                }
            }

            const char* vijand = location->Attribute("vijand");
            const char* objectenverborgen = location->Attribute("objectenverborgen");
            const char* objectenzichtbaar = location->Attribute("objectenzichtbaar");
        }

        return builder.get_locations();;
    }
} // file_reader
