#ifndef FILEREADER_H
#define FILEREADER_H

#include "../common/Array.hpp"

namespace domain {
    class Location;
}

using domain::Array;
using domain::Location;

/**
 * @namespace file_reader
 * @brief Contains functionality for reading files.
 */
namespace file_reader {
    /**
     * @brief Reads a file from the given path.
     * @param path The path to the file.
     */
    Array<Location>* read_file(const char* path);
} // file_reader

#endif //FILEREADER_H
