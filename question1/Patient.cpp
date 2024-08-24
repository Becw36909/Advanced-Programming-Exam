#include "Patient.h"

/**
 * @brief Constructs a Patient with the given name, date of birth, and
 * registration number.
 *
 * Initializes the patient's details and sets up an empty list of admissions.
 * @param name The patient's name.
 * @param dob The patient's date of birth.
 * @param regNumber The patient's registration number.
 */
Patient::Patient(const std::string& name, const std::string& dob, int regNumber)
    : name(name), dob(dob), regNumber(regNumber) {}

/**
 * @brief Destructor that deletes all admission records to free allocated
 * memory.
 *
 * Ensures that all dynamically allocated Admission objects are properly cleaned
 * up.
 */
Patient::~Patient() {
  for (Admission* admission : admissions) {
    delete admission;
  }
}

/**
 * @brief Retrieves the patient's name.
 * @return The name of the patient.
 */
std::string Patient::getName() const { return name; }

/**
 * @brief Retrieves the patient's date of birth.
 * @return The date of birth of the patient.
 */
std::string Patient::getDob() const { return dob; }

/**
 * @brief Retrieves the patient's registration number.
 * @return The registration number of the patient.
 */
int Patient::getRegNumber() const { return regNumber; }

/**
 * @brief Retrieves a list of the patient's admissions.
 * @return A constant reference to the vector of admissions.
 */
const std::vector<Admission*>& Patient::getAdmissions() const {
  return admissions;
}

/**
 * @brief Adds a new admission to the patient's record.
 *
 * Allocates a new Admission object and adds it to the list of admissions.
 * @param admissionDate The date of admission.
 * @param ward The ward where the patient was admitted.
 */
void Patient::addAdmission(const std::string& admissionDate,
                           const std::string& ward) {
  Admission* admission = new Admission{admissionDate, "", ward};
  admissions.push_back(admission);
}

/**
 * @brief Updates the discharge date for the most recent admission.
 *
 * If the most recent admission does not have a discharge date, it is set to the
 * provided date.
 * @param dischargeDate The date of discharge.
 */
void Patient::dischargeLastAdmission(const std::string& dischargeDate) {
  if (!admissions.empty() && admissions.back()->dischargeDate.empty()) {
    admissions.back()->dischargeDate = dischargeDate;
  }
}

/**
 * @brief Outputs patient details to the given stream.
 *
 * Includes the patient's name, date of birth, registration number, and
 * admission history.
 * @param os The output stream.
 * @param patient The patient to output.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Patient& patient) {
  os << "Patient Name: " << patient.name << "\n";
  os << "DOB: " << patient.dob << "\n";
  os << "Registration Number: " << patient.regNumber << "\n";
  os << "Admission History:\n";
  for (const Admission* admission : patient.admissions) {
    os << "  - Admission Date: " << admission->admissionDate
       << ", Ward: " << admission->ward << ", Discharge Date: "
       << (admission->dischargeDate.empty() ? "N/A" : admission->dischargeDate)
       << "\n";
  }
  return os;
}
