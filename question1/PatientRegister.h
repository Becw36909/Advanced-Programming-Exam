#ifndef PATIENTREGISTER_H
#define PATIENTREGISTER_H

#include <map>
#include <memory>

#include "Patient.h"

/**
 * @class PatientRegister
 * @brief Manages a collection of patients using their registration numbers.
 *
 * The PatientRegister class encapsulates the storage and management of Patient
 * objects and uses std::map to efficiently map registration numbers to patient
 * records, ensuring that each patient is uniquely identified and easily
 * accessible. It utilizes std::shared_ptr for managing patient objects, which
 * simplifies memory management and supports shared ownership. The private data
 * member `patients` is hidden from external access, providing controlled
 * interactions through public methods.
 * 
 * Defensive Programming Considerations:
 * - Checks if a patient already exists before adding to prevent overwriting.
 * - Uses shared_ptr for automatic memory management to avoid leaks and dangling
 * pointers.
 * - Removes patients safely by ensuring the registration number exists before
 * attempting to remove.
 */
class PatientRegister {
 public:
  /**
   * @brief Constructs an empty PatientRegister.
   */
  PatientRegister();

  /**
   * @brief Destructor that relies on shared_ptr to handle memory management.
   */
  ~PatientRegister();

  /**
   * @brief Adds a patient to the register.
   *
   * The patient is added to the map if their registration number is not already
   * present.
   * @param patient A shared_ptr to the Patient object to be added.
   */
  void addPatient(std::shared_ptr<Patient> patient);

  /**
   * @brief Removes a patient from the register by registration number.
   *
   * The patient is removed from the map. Memory is managed by shared_ptr, so
   * manual deletion is not needed.
   * @param regNumber The registration number of the patient to be removed.
   */
  void removePatient(int regNumber);

  /**
   * @brief Checks if a patient with a given registration number exists in the
   * register.
   * @param regNumber The registration number to check.
   * @return True if the patient exists, false otherwise.
   */
  bool hasPatient(int regNumber) const;

  /**
   * @brief Retrieves a patient by registration number.
   *
   * Returns a shared_ptr to the patient if found, otherwise returns nullptr.
   * @param regNumber The registration number of the patient to retrieve.
   * @return A shared_ptr to the Patient object, or nullptr if not found.
   */
  std::shared_ptr<Patient> getPatient(int regNumber) const;

  /**
   * @brief Provides access to a patient by registration number using array
   * notation.
   *
   * This operator[] is a convenient way to access patient records.
   * @param regNumber The registration number of the patient to retrieve.
   * @return A shared_ptr to the Patient object, or nullptr if not found.
   */
  std::shared_ptr<Patient> operator[](int regNumber) const;

 private:
  std::map<int, std::shared_ptr<Patient>>
      patients;  // Map of registration numbers to patient records
};

#endif  // PATIENTREGISTER_H
