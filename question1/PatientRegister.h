#ifndef PATIENTREGISTER_H
#define PATIENTREGISTER_H

#include "Patient.h"
#include <unordered_map>

class PatientRegister {
public:
    PatientRegister();
    ~PatientRegister();

    void addPatient(Patient* patient);
    void removePatient(int regNumber);
    bool hasPatient(int regNumber) const;
    Patient* getPatient(int regNumber) const;

    Patient* operator[](int regNumber) const;

private:
    std::unordered_map<int, Patient*> patients;
};

#endif // PATIENTREGISTER_H
