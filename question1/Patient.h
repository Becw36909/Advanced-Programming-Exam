#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include <iostream>

struct Admission {
    std::string admissionDate;
    std::string dischargeDate;
    std::string ward;
};

class Patient {
public:
    Patient(const std::string& name, const std::string& dob, int regNumber);
    ~Patient();

    std::string getName() const;
    std::string getDob() const;
    int getRegNumber() const;
    const std::vector<Admission*>& getAdmissions() const;

    void addAdmission(const std::string& admissionDate, const std::string& ward);
    void dischargeLastAdmission(const std::string& dischargeDate);

    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);

private:
    std::string name;
    std::string dob;
    int regNumber;
    std::vector<Admission*> admissions;
};

#endif // PATIENT_H
