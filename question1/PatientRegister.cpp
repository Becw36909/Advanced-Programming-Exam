#include "PatientRegister.h"

PatientRegister::PatientRegister() {}

PatientRegister::~PatientRegister() {
    for (auto& pair : patients) {
        delete pair.second;
    }
}

void PatientRegister::addPatient(Patient* patient) {
    int regNumber = patient->getRegNumber();
    if (!hasPatient(regNumber)) {
        patients[regNumber] = patient;
    }
}

void PatientRegister::removePatient(int regNumber) {
    if (hasPatient(regNumber)) {
        delete patients[regNumber];
        patients.erase(regNumber);
    }
}

bool PatientRegister::hasPatient(int regNumber) const {
    return patients.find(regNumber) != patients.end();
}

Patient* PatientRegister::getPatient(int regNumber) const {
    auto it = patients.find(regNumber);
    if (it != patients.end()) {
        return it->second;
    }
    return nullptr;
}

Patient* PatientRegister::operator[](int regNumber) const {
    return getPatient(regNumber);
}
