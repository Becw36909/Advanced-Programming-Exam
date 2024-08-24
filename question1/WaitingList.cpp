#include "WaitingList.h"

WaitingList::WaitingList() : nextQueueNumber(1) {}

WaitingList::~WaitingList() {}

void WaitingList::addPatient(Patient* patient) {
    int regNumber = patient->getRegNumber();
    if (queueNumbers.find(regNumber) == queueNumbers.end()) {
        queue.push_back(patient);
        queueNumbers[regNumber] = nextQueueNumber++;
    }
}

void WaitingList::removeNextPatient() {
    if (!queue.empty()) {
        int regNumber = queue.front()->getRegNumber();
        queue.pop_front();
        queueNumbers.erase(regNumber);
    }
}

Patient* WaitingList::getNextPatient() const {
    if (!queue.empty()) {
        return queue.front();
    }
    return nullptr;
}

int WaitingList::getQueueNumber(Patient* patient) const {
    int regNumber = patient->getRegNumber();
    auto it = queueNumbers.find(regNumber);
    if (it != queueNumbers.end()) {
        return it->second;
    }
    return -1; // Indicates that the patient is not in the queue
}

int WaitingList::getRemainingPatients() const {
    return queue.size();
}
