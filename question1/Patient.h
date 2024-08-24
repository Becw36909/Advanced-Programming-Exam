#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @struct Admission
 * @brief Represents an admission record for a patient.
 *
 * Stores the admission date, discharge date (if any), and the ward where the
 * patient was admitted. Using a struct for Admission to keep the data
 * lightweight and simple.
 * It is used privately within the Patient class and not exposed outside,
 * ensuring encapsulation.
 */
struct Admission {
  std::string admissionDate;  // Date of admission
  std::string dischargeDate;  // Date of discharge (empty if not discharged)
  std::string ward;           // Ward where the patient was admitted
};

/**
 * @class Patient
 * @brief Manages patient information and admission history.
 *
 * This class uses a dynamic container (std::vector) to manage a list of
 * admissions. Each admission is a separate object, allowing detailed tracking
 * of each admission's date and ward. The vector provides dynamic sizing,
 * efficient random access, and simplifies insertion and deletion operations.
 * The Patient class encapsulates patient details such as name, date of birth,
 * registration number, and admission records. Private data members and methods
 * ensure that internal details are hidden from outside access. Public methods
 * provide controlled access to this data, allowing modifications and queries in
 * a controlled manner.
 * 
 * Defensive Programming Considerations:
 * - Handles dynamic memory management using raw pointers and manual deletion to
 * avoid memory leaks.
 * - Methods check for valid states, such as ensuring the last admission can be
 * discharged before attempting to discharge it.
 */
class Patient {
 public:
  /**
   * @brief Constructs a Patient with the given name, date of birth, and
   * registration number.
   *
   * @param name The patient's name.
   * @param dob The patient's date of birth.
   * @param regNumber The patient's registration number.
   */
  Patient(const std::string& name, const std::string& dob, int regNumber);

  /**
   * @brief Destructor that deletes all admission records to free allocated
   * memory.
   */
  ~Patient();

  /**
   * @brief Retrieves the patient's name.
   * @return The name of the patient.
   */
  std::string getName() const;

  /**
   * @brief Retrieves the patient's date of birth.
   * @return The date of birth of the patient.
   */
  std::string getDob() const;

  /**
   * @brief Retrieves the patient's registration number.
   * @return The registration number of the patient.
   */
  int getRegNumber() const;

  /**
   * @brief Retrieves a list of the patient's admissions.
   * @return A constant reference to the vector of admissions.
   */
  const std::vector<Admission*>& getAdmissions() const;

  /**
   * @brief Adds a new admission to the patient's record.
   *
   * Creates a new Admission object and adds it to the patient's list of
   * admissions.
   * @param admissionDate The date of admission.
   * @param ward The ward where the patient was admitted.
   */
  void addAdmission(const std::string& admissionDate, const std::string& ward);

  /**
   * @brief Updates the discharge date for the most recent admission.
   *
   * Sets the discharge date for the last admission if it is currently empty.
   * @param dischargeDate The date of discharge.
   */
  void dischargeLastAdmission(const std::string& dischargeDate);

  /**
   * @brief Outputs patient details to the given stream.
   *
   * Includes name, date of birth, registration number, and admission history.
   * @param os The output stream.
   * @param patient The patient to output.
   * @return The output stream.
   */
  friend std::ostream& operator<<(std::ostream& os, const Patient& patient);

 private:
  std::string name;  // The patient's name
  std::string dob;   // The patient's date of birth
  int regNumber;     // The patient's registration number
  std::vector<Admission*>
      admissions;  //List of admissions (dynamically allocated)
};

#endif  // PATIENT_H
