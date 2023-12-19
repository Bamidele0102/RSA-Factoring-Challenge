#include "header.h"

class SimpleNumberFactorizer {
public:
    SimpleNumberFactorizer(const char *fileName) : file(fileName) {}

    void run() {
        processFile();
    }

private:
    void factorizeLargeNumber(const std::string& line);
    void factorizeSmallNumber(const std::string& line);
    void processFile();

    std::ifstream file;
};

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    SimpleNumberFactorizer factorizer(argv[1]);
    factorizer.run();

    return 0;
}
