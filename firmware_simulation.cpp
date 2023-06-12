#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>

// Define a base PatientCondition class
class PatientCondition {
public:
    virtual void generateVitals(std::ofstream &file) = 0; // Pure virtual function
};

// Define a Resting class that inherits from PatientCondition
class Resting : public PatientCondition {
public:
    // Override generateVitals method for the resting condition
    void generateVitals(std::ofstream &file) override {
        int heartRate = rand() % 21 + 60; // heart rate between 60 and 80
        float bodyTemp = (float)(rand() % 11 + 361) / 10.0; // body temp between 36.1 and 37.1
        int oxygenSat = rand() % 5 + 95; // oxygen saturation between 95 and 99

        file << "Resting - " << "Heart Rate: " << heartRate << ", Body Temperature: " << bodyTemp << ", Oxygen Saturation: " << oxygenSat << "\n";
    }
};

// Define a Exercising class that inherits from PatientCondition
class Exercising : public PatientCondition {
public:
    // Override generateVitals method for the exercising condition
    void generateVitals(std::ofstream &file) override {
        int heartRate = rand() % 21 + 160; // heart rate between 160 and 180
        float bodyTemp = (float)(rand() % 6 + 375) / 10.0; // body temp between 37.5 and 38.0
        int oxygenSat = rand() % 6 + 90; // oxygen saturation between 90 and 95

        file << "Exercising - " << "Heart Rate: " << heartRate << ", Body Temperature: " << bodyTemp << ", Oxygen Saturation: " << oxygenSat << "\n";
    }
};

// Define the PatientMonitoringDevice class
class PatientMonitoringDevice {
public:
    // Constructor to seed the random number generator
    PatientMonitoringDevice() {
        srand(time(NULL));
    }

    // Generate vitals for different conditions
    void generateVitalsForConditions() {
        // Vector of unique_ptr of PatientCondition to hold different conditions
        std::vector<std::unique_ptr<PatientCondition>> conditions;

        // Populate the vector with different conditions
        conditions.push_back(std::make_unique<Resting>());
        conditions.push_back(std::make_unique<Exercising>());
        conditions.push_back(std::make_unique<Resting>());

        // Open a file to store the vital signs data
        std::ofstream file;
        file.open("vitals.txt");

        // Generate and store vitals for each condition
        if (file.is_open()) {
            for(const auto& condition : conditions) {
                condition->generateVitals(file);
            }
            file.close();
        } else {
            std::cout << "Unable to open the file.";
        }
    }
};

// Main function
int main() {
    // Create an instance of the PatientMonitoringDevice class
    PatientMonitoringDevice device;

    // Generate and store vitals for different conditions
    device.generateVitalsForConditions();

    return 0;
}

