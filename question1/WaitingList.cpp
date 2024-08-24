#include "WaitingList.h"

/**
 * @brief Constructs an empty WaitingList with the nextQueueNumber initialized
 * to 1.
 */
WaitingList::WaitingList() : nextQueueNumber(1) {}

/**
 * @brief Destructor.
 *
 * The destructor does not need to manually delete patients, as shared_ptr
 * handles memory management.
 */
WaitingList::~WaitingList() {}

/**
 * @brief Adds a patient to the waiting list.
 *
 * The patient is added to the end of the queue and assigned a queue number if
 * not already present.
 * @param patient A shared_ptr to the Patient object to be added.
 */
void WaitingList::addPatient(std::shared_ptr<Patient> patient) {
  int regNumber = patient->getRegNumber();
  if (queueNumbers.find(regNumber) == queueNumbers.end()) {
    queue.push_back(patient);  // std::list maintains the order of patients
    queueNumbers[regNumber] =
        nextQueueNumber++;  // std::map tracks queue numbers efficiently
  }
}

/**
 * @brief Removes the next patient from the waiting list.
 *
 * The patient at the front of the queue is removed. Shared_ptr handles memory
 * management.
 */
void WaitingList::removeNextPatient() {
  if (!queue.empty()) {
    int regNumber = queue.front()->getRegNumber();
    queue.pop_front();  // Efficient removal from the front of the list
    queueNumbers.erase(regNumber);  // Remove from map
  }
}

/**
 * @brief Retrieves the next patient in the waiting list.
 *
 * Returns a shared_ptr to the patient at the front of the queue, or nullptr if
 * the queue is empty.
 * @return A shared_ptr to the next Patient, or nullptr if the queue is empty.
 */
std::shared_ptr<Patient> WaitingList::getNextPatient() const {
  if (!queue.empty()) {
    return queue.front();  // Access the patient at the front of the list
  }
  return nullptr;
}

/**
 * @brief Gets the queue number of a given patient.
 *
 * Returns the queue number if the patient is in the list, or -1 if not found.
 * @param patient A shared_ptr to the Patient object whose queue number is to be
 * retrieved.
 * @return The queue number of the patient, or -1 if not found.
 */
int WaitingList::getQueueNumber(std::shared_ptr<Patient> patient) const {
  int regNumber = patient->getRegNumber();
  auto it = queueNumbers.find(regNumber);
  if (it != queueNumbers.end()) {
    return it->second;  // Retrieve queue number from the map
  }
  return -1;
}

/**
 * @brief Gets the number of remaining patients in the waiting list.
 * @return The number of patients currently in the queue.
 */
int WaitingList::getRemainingPatients() const {
  return queue
      .size();  // Size of the list gives the number of remaining patients
}
