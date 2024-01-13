/* cccrypt
 * Basic Geometry Dash CCGameManager.dat encoder/decoder.
 * Licensed under the GNU General Public License version 3.
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "CCData.hpp"

void printHelp() {
    std::cout << "usage: cccrypt [-i input] [-o output] [-e] [-d] [-h]\n";
}

int main(int argc, char** argv) {
    CCData::CCData data;

    std::string inFile{};
    std::string outFile{};
    bool mode = true; // default mode: decrypt

    for (int i{1}; i < argc; i++) {
        std::string arg = argv[i];

        if (!arg.compare("-d")) {
            mode = true;
        } else if (!arg.compare("-e")) {
            mode = false;
        } else if (!arg.compare("-i")) {
            inFile = argv[++i];
        } else if (!arg.compare("-o")) {
            outFile = argv[++i];
        } else if (!arg.compare("-h")) {
            printHelp();
            return 0;
        } else {
            printHelp();
            return 1;
        }
    }

    if (!inFile.compare("")) {
        std::cerr << "cccrypt: no input file was specified.\n";
        return 1;
    }

    std::ifstream file(inFile, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "cccrypt: failed to open input file\n";
        return 1;
    }

    std::vector<uint8_t> Data{};
    std::vector<uint8_t> fileContents(std::istreambuf_iterator<char>(file), {});

    file.close();

    if (mode == true) {
        Data = data.Decrypt(fileContents);
    } else {
        Data = data.Encrypt(fileContents);
    }

    if (!outFile.compare("")) {
        for (uint8_t it : Data) {
            std::cout << it;
        }
    } else {
        std::ofstream output;

        output.open(outFile);
        output.write(reinterpret_cast<const char*>(Data.data()), Data.size());
        output.close();
    }

    return 0;
}
