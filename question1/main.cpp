#include <iostream>
#include <memory>
#include "Patient.h"
#include "PatientRegister.h"
#include "WaitingList.h"

int main() {
    // Create some patients using shared_ptr
    auto patient1 = std::make_shared<Patient>("John Doe", "10-2-1965", 1234567);
    auto patient2 = std::make_shared<Patient>("Jane Smith", "20-5-1980", 2345678);
    auto patient3 = std::make_shared<Patient>("Alice Johnson", "15-8-1975", 3456789);
    auto duplicatePatient = std::make_shared<Patient>("Jane Smith", "20-5-1980", 2345678);

    // Add admissions for the patients
    patient1->addAdmission("01-01-2023", "ICU");
    patient1->dischargeLastAdmission("05-01-2023");

    patient2->addAdmission("10-03-2023", "General Ward");

    patient3->addAdmission("12-04-2023", "Surgical Unit");

    // Create a patient register and add patients to it
    PatientRegister patientRegister;
    patientRegister.addPatient(patient1);
    patientRegister.addPatient(patient2);
    patientRegister.addPatient(patient3);

    // Try to add the duplicate patient
    patientRegister.addPatient(duplicatePatient);

    // Check if the duplicate was added
    if (patientRegister.hasPatient(2345678)) {
        std::cout << "Duplicate patient (Jane Smith) was NOT added, as expected." << std::endl;
    } else {
        std::cout << "Duplicate patient (Jane Smith) was incorrectly added." << std::endl;
    }

    std::cout << "\n" << std::endl;

    // Check if a patient is in the register and retrieve them
    if (patientRegister.hasPatient(2345678)) {
        auto retrievedPatient = patientRegister[2345678];
        std::cout << "Retrieved Patient Info: " << std::endl;
        std::cout << *retrievedPatient << std::endl;
    }

    // Create a waiting list and add patients to it
    WaitingList waitingList;
    waitingList.addPatient(patient1);
        std::cout << "Queue Number: " << waitingList.getQueueNumber(patient1) << std::endl;

    std::cout << "Patient added to waiting list: " << *patient1 << std::endl;
    
    waitingList.addPatient(patient2);
            std::cout << "Queue Number: " << waitingList.getQueueNumber(patient2) << std::endl;

    std::cout << "Patient added to waiting list: " << *patient2 << std::endl;

    waitingList.addPatient(patient3);
                std::cout << "Queue Number: " << waitingList.getQueueNumber(patient3) << std::endl;

    std::cout << "Patient added to waiting list: " << *patient3 << std::endl;

    // Process the waiting list
    while (waitingList.getRemainingPatients() > 0) {
        auto nextPatient = waitingList.getNextPatient();
        std::cout << "Next patient for surgery: " << std::endl;
        std::cout << *nextPatient << std::endl;

        waitingList.removeNextPatient();
        std::cout << "Patient removed from waiting list: " << *nextPatient << std::endl;
    }

    return 0;
}
