#include "Patient.h"

Patient::Patient(const std::string& name, const std::string& dob, int regNumber)
    : name(name), dob(dob), regNumber(regNumber) {}

Patient::~Patient() {
    for (Admission* admission : admissions) {
        delete admission;
    }
}

std::string Patient::getName() const {
    return name;
}

std::string Patient::getDob() const {
    return dob;
}

int Patient::getRegNumber() const {
    return regNumber;
}

const std::vector<Admission*>& Patient::getAdmissions() const {
    return admissions;
}

void Patient::addAdmission(const std::string& admissionDate, const std::string& ward) {
    Admission* admission = new Admission{admissionDate, "", ward};
    admissions.push_back(admission);
}

void Patient::dischargeLastAdmission(const std::string& dischargeDate) {
    if (!admissions.empty() && admissions.back()->dischargeDate.empty()) {
        admissions.back()->dischargeDate = dischargeDate;
    }
}

std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << "Patient Name: " << patient.name << "\n";
    os << "DOB: " << patient.dob << "\n";
    os << "Registration Number: " << patient.regNumber << "\n";
    os << "Admission History:\n";
    for (const Admission* admission : patient.admissions) {
        os << "  - Admission Date: " << admission->admissionDate << ", Ward: " << admission->ward
           << ", Discharge Date: " << (admission->dischargeDate.empty() ? "N/A" : admission->dischargeDate) << "\n";
    }
    return os;
}
