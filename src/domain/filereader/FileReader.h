#ifndef FILEREADER_H
#define FILEREADER_H

namespace domain {
    class Location;
}

using domain::Location;

namespace file_reader {
    /**
     * @brief Reads a file from the given path.
     * @param path The path to the file.
     */
     Location* read_file(const char* path);
} // file_reader

#endif //FILEREADER_H
