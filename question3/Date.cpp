#include "Date.h"
#include <exception>

Date::Date():
    year(1970), month(1), day(1)
{    
}

Date::Date(unsigned int year, unsigned int month, unsigned int day):
                        year(year), month(month), day(day)
{    
}

Date::Date(const Date& other){
    year = other.year;
    month = other.month;
    day = other.day;
}

Date::Date(Date&& other){
    year = other.year;
    month = other.month;
    day = other.day;
}

Date::~Date(){
    
}

unsigned int Date::getDay(){
    return day;
}

unsigned int Date::getMonth(){
    return month;
}

unsigned int Date::getYear(){
    return year;
}


unsigned long Date::getDayNumber() const{
    unsigned long m = ((unsigned long)month + 9) % 12;
    unsigned long y = (unsigned long)year - ((unsigned long)month/10);
    return 365*y + y/4 - y/100 + y/400 
                + (m*306 + 5)/10 + ( (unsigned long)day - 1 );
}

void Date::setDate(unsigned long dayNumber){
    unsigned long y = (10000*((unsigned long)dayNumber) + 14780)/3652425;
    unsigned long ddd = (unsigned long)dayNumber - (365*y + y/4 - y/100 + y/400);
    if (ddd < 0){
        y = y - 1;
        ddd = (unsigned long)dayNumber - (365*y + y/4 - y/100 + y/400);
    }
    unsigned long mi = (100*ddd + 52)/3060;
    unsigned long mm = (mi + 2)%12 + 1;
    y = y + (mi + 2)/12;
    unsigned long dd = ddd - (mi*306 + 5)/10 + 1;

    this->day = (unsigned int)dd;
    this->month = (unsigned int)mm;
    this->year = (unsigned int)y;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day){
    this->day = day;
    this->month = month;
    this->year = year;
}


Date::Date(unsigned long dayNumber){
    this->setDate(dayNumber);
}

/*                                           */
/* YOU MAY ADD YOUR MODIFICATIONS HERE       */
/*                                           */

// Helper function to get the number of days in a month
unsigned int getDaysInMonth(unsigned int year, unsigned int month) {
    if (month == 2) {
        // Leap year check
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    }
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

// Arithmetic Operators
Date Date::operator+(unsigned long days) const {
    Date result(*this);
    result.setDate(result.getDayNumber() + days);
    return result;
}

Date Date::operator-(unsigned long days) const {
    Date result(*this);
    result.setDate(result.getDayNumber() - days);
    return result;
}

unsigned long Date::operator-(const Date& other) const {
    return this->getDayNumber() - other.getDayNumber();
}

// Comparison Operators
bool Date::operator==(const Date& other) const {
    return this->getDayNumber() == other.getDayNumber();
}

bool Date::operator!=(const Date& other) const {
    return this->getDayNumber() != other.getDayNumber();
}

bool Date::operator<(const Date& other) const {
    return this->getDayNumber() < other.getDayNumber();
}

bool Date::operator>(const Date& other) const {
    return this->getDayNumber() > other.getDayNumber();
}

// Increment/Decrement Operators
// Date& Date::operator++() {
//     *this = *this + 1;
//     return *this;
// }

// Date Date::operator++(int) {
//     Date temp(*this);
//     ++(*this);
//     return temp;
// }

// Helper function to get the number of days in a month
unsigned int Date::getDaysInMonth(unsigned int year, unsigned int month) const {
    if (month == 2) {
        // Leap year check
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    }
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

// // Prefix increment (i.e., ++date)
Date& Date::operator++() {
    unsigned int day = this->getDay();  // Change to unsigned int
    unsigned int month = this->getMonth();  // Change to unsigned int
    unsigned int year = this->getYear();   // Change to unsigned int

    // Increment the day
    day++;

    // Check for month-end
    if (day > getDaysInMonth(year, month)) {
        day = 1;
        month++;
        // Check for year-end
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    // Set the updated date
    this->setDate(year, month, day);
    return *this;
}


// Postfix increment (i.e., date++)
Date Date::operator++(int) {
    Date temp = *this; // Save the current state
    ++(*this);         // Use the prefix increment to increment the current object
    return temp;       // Return the saved state
}



Date& Date::operator--() {
    *this = *this - 1;
    return *this;
}

Date Date::operator--(int) {
    Date temp(*this);
    --(*this);
    return temp;
}

// Array-like Access Operator
unsigned int& Date::operator[](const std::string& field) {
    if (field == "year") {
        return year;
    } else if (field == "month") {
        return month;
    } else if (field == "day") {
        return day;
    } else {
        throw std::out_of_range("Invalid field name");
    }
}

// Copy Assignment Operator
Date& Date::operator=(const Date& other) {
    if (this != &other) { // Check for self-assignment
        year = other.year;
        month = other.month;
        day = other.day;
    }
    return *this;
}


// Output Stream Operator
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.getConstDay() << '/' << date.getConstMonth() << '/' << date.getConstYear();
    return os;
}

// New const accessors
unsigned int Date::getConstDay() const {
    return day;
}

unsigned int Date::getConstMonth() const {
    return month;
}

unsigned int Date::getConstYear() const {
    return year;
}

Date& Date::operator+=(unsigned long days) {
    // Convert the current date to dayNumber
    unsigned long currentDayNumber = this->getDayNumber();
    
    // Add days to the dayNumber
    unsigned long newDayNumber = currentDayNumber + days;
    
    // Update the date using the new dayNumber
    this->setDate(newDayNumber);
    
    return *this;
}