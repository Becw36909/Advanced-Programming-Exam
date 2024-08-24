#include "PatientRegister.h"

#include "Patient.h"

/**
 * @brief Constructs an empty PatientRegister.
 */
PatientRegister::PatientRegister() {}

/**
 * @brief Destructor that relies on shared_ptr to handle memory management.
 *
 * The shared_ptr automatically cleans up resources, so no manual deletion of
 * patients is necessary.
 */
PatientRegister::~PatientRegister() {
  // No need to manually delete patients, as shared_ptr handles memory
  // management
}

/**
 * @brief Adds a patient to the register.
 *
 * The patient is added to the map if their registration number is not already
 * present.
 * @param patient A shared_ptr to the Patient object to be added.
 */
void PatientRegister::addPatient(std::shared_ptr<Patient> patient) {
  int regNumber = patient->getRegNumber();
  if (!hasPatient(regNumber)) {
    patients[regNumber] = patient;
  }
}

/**
 * @brief Removes a patient from the register by registration number.
 *
 * The patient is removed from the map. Shared_ptr handles memory management, so
 * manual deletion is not needed.
 * @param regNumber The registration number of the patient to be removed.
 */
void PatientRegister::removePatient(int regNumber) {
  if (hasPatient(regNumber)) {
    patients.erase(regNumber);  // No need to delete, shared_ptr handles it
  }
}

/**
 * @brief Checks if a patient with a given registration number exists in the
 * register.
 * @param regNumber The registration number to check.
 * @return True if the patient exists, false otherwise.
 */
bool PatientRegister::hasPatient(int regNumber) const {
  return patients.find(regNumber) != patients.end();
}

/**
 * @brief Retrieves a patient by registration number.
 *
 * Returns a shared_ptr to the patient if found, otherwise returns nullptr.
 * @param regNumber The registration number of the patient to retrieve.
 * @return A shared_ptr to the Patient object, or nullptr if not found.
 */
std::shared_ptr<Patient> PatientRegister::getPatient(int regNumber) const {
  auto it = patients.find(regNumber);
  if (it != patients.end()) {
    return it->second;
  }
  return nullptr;
}

/**
 * @brief Provides access to a patient by registration number using array
 * notation.
 *
 * This operator[] is a convenient way to access patient records.
 * @param regNumber The registration number of the patient to retrieve.
 * @return A shared_ptr to the Patient object, or nullptr if not found.
 */
std::shared_ptr<Patient> PatientRegister::operator[](int regNumber) const {
  return getPatient(regNumber);
}
