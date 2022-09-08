#include "utils.h"

using namespace std;

string utils::readFile(const string filename) {
    ifstream ifs(filename);
    string line;
    getline(ifs, line);
    string message = line;

    // read in entries
    while (ifs.good()) {
        getline(ifs, line);
        message += '\n' + line;
    }
    return message;
}

void utils::writeFile(const string filename, const string message) {
    ofstream ofs(filename);
    ofs << message;
    ofs.close();
}