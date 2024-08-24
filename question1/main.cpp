#include <iostream>
#include "Patient.h"
#include "PatientRegister.h"
#include "WaitingList.h"

int main() {
    // Create some patients
    Patient* patient1 = new Patient("John Doe", "10-2-1965", 1234567);
    Patient* patient2 = new Patient("Jane Smith", "20-5-1980", 2345678);
    Patient* patient3 = new Patient("Alice Johnson", "15-8-1975", 3456789);

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

    // Check if a patient is in the register and retrieve them
    if (patientRegister.hasPatient(2345678)) {
        Patient* retrievedPatient = patientRegister[2345678];
        std::cout << "Retrieved Patient Info: " << *retrievedPatient << std::endl;
    }

    // Create a waiting list and add patients to it
    WaitingList waitingList;
    waitingList.addPatient(patient1);
    waitingList.addPatient(patient2);
    waitingList.addPatient(patient3);

    // Process the waiting list
    while (waitingList.getRemainingPatients() > 0) {
        Patient* nextPatient = waitingList.getNextPatient();
        std::cout << "Next patient for surgery: " << *nextPatient << std::endl;
        waitingList.removeNextPatient();
    }

    // Cleanup dynamically allocated memory
    delete patient1;
    delete patient2;
    delete patient3;

    return 0;
}
