#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include "Patient.h"
#include <deque>
#include <unordered_map>

class WaitingList {
public:
    WaitingList();
    ~WaitingList();

    void addPatient(Patient* patient);
    void removeNextPatient();
    Patient* getNextPatient() const;
    int getQueueNumber(Patient* patient) const;
    int getRemainingPatients() const;

private:
    std::deque<Patient*> queue;
    std::unordered_map<int, int> queueNumbers;
    int nextQueueNumber;
};

#endif // WAITINGLIST_H
