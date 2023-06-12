#include <iostream>
#include <fstream>
#include <string>

// Define a CentralSystem class.
class CentralSystem {
public:
    // Method to read and display vital signs data from a file.
    void displayVitals(std::string filename) {
        std::ifstream file(filename);
        std::string line;

        if (file.is_open()) {
            std::cout << "Displaying patient's vital signs...\n";

            while (std::getline(file, line)) {
                std::cout << line << '\n';
            }

            file.close();
        }
        else {
            std::cout << "Unable to open file.\n";
        }
    }
};

int main() {
    // Create an instance of the CentralSystem class.
    CentralSystem system;

    // Display the vital signs data from "vitals.txt".
    system.displayVitals("vitals.txt");

    return 0;
}
