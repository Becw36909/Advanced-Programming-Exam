#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <list>
#include <map>
#include <memory>

#include "Patient.h"

/**
 * @class WaitingList
 * @brief Manages a queue of patients waiting for a service.
 *
 * The WaitingList class  encapsulates the queue of patients using std::list to
 * maintain the order of patients waiting, and std::map to keep track of their
 * queue numbers. It ensures that patients are added and removed efficiently
 * while keeping the queue number tracking internal. Private data members ensure
 * that the internal state is not exposed or modified directly from outside.
 * Smart pointers (std::shared_ptr) are used for managing patient objects,
 * allowing shared ownership and automatic memory management.
 *
 * Defensive Programming Considerations:
 * - Ensures that patients are not added more than once to the queue by checking
 * if they are already present.
 * - Handles empty queue cases safely when removing or retrieving patients to
 * avoid crashes.
 * - Utilizes shared_ptr for automatic memory management, preventing memory
 * leaks.
 */
class WaitingList {
 public:
  /**
   * @brief Constructs an empty WaitingList with the nextQueueNumber
   * initialized.
   */
  WaitingList();

  /**
   * @brief Destructor.
   *
   * The destructor does not need to manually delete patients, as shared_ptr
   * handles memory management.
   */
  ~WaitingList();

  /**
   * @brief Adds a patient to the waiting list.
   *
   * The patient is added to the end of the queue and assigned a queue number if
   * not already present.
   * @param patient A shared_ptr to the Patient object to be added.
   */
  void addPatient(std::shared_ptr<Patient> patient);

  /**
   * @brief Removes the next patient from the waiting list.
   *
   * The patient at the front of the queue is removed. Shared_ptr handles memory
   * management.
   */
  void removeNextPatient();

  /**
   * @brief Retrieves the next patient in the waiting list.
   *
   * Returns a shared_ptr to the patient at the front of the queue, or nullptr
   * if the queue is empty.
   * @return A shared_ptr to the next Patient, or nullptr if the queue is empty.
   */
  std::shared_ptr<Patient> getNextPatient() const;

  /**
   * @brief Gets the queue number of a given patient.
   *
   * Returns the queue number if the patient is in the list, or -1 if not found.
   * @param patient A shared_ptr to the Patient object whose queue number is to
   * be retrieved.
   * @return The queue number of the patient, or -1 if not found.
   */
  int getQueueNumber(std::shared_ptr<Patient> patient) const;

  /**
   * @brief Gets the number of remaining patients in the waiting list.
   * @return The number of patients currently in the queue.
   */
  int getRemainingPatients() const;

 private:
  std::list<std::shared_ptr<Patient>>
      queue;  // List of patients in the waiting queue (order maintained)
  std::map<int, int>
      queueNumbers;     // Map of patient registration numbers to their queue
                        // positions (efficient tracking)
  int nextQueueNumber;  // The next queue number to be assigned
};

#endif  // WAITINGLIST_H
