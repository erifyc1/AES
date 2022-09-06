#include <string>
#include <fstream>
#include <istream>
#include <ostream>

using namespace std;
struct utils {
    static string readFile(const string filename);
    static void writeFile(const string filename, const string message);
};