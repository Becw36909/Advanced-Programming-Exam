#ifndef COSC1076_A3_DATE_H
#define COSC1076_A3_DATE_H

#include <iostream>

class Date{
public:    
    
    // Constructors/DeConstructors
    Date();

    //dayNumber is the number of days since 1/3/0000 
    Date(unsigned long dayNumber);
    Date(const Date& other);
    Date(Date&& other);
    ~Date();

    //Contract: Year, Month, Day should be valid
    //          Year should be a positive number, 
    //          month should be a number in range [1,12], 
    //          date should be a numbers in range [1,31] and valid. 
    Date(unsigned int year, unsigned int month, unsigned int day);

    
    //Getters and setters
    unsigned int getDay();
    unsigned int getMonth();
    unsigned int getYear();
    unsigned long getDayNumber() const;

    void setDate(unsigned long dayNumber);

    //Contract: Year, Month, Day should be valid
    //          Year should be a positive number, 
    //          month should be a number in range [1,12], 
    //          date should be a numbers in range [1,31] and valid. 
    void setDate(unsigned int year, unsigned int month, unsigned int day);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

    // Copy Assignment Operator
    Date& operator=(const Date& other);

    // Overloaded Arithmetic Operators
    Date& operator+=(unsigned long days);
    Date operator+(unsigned long days) const;
    Date operator-(unsigned long days) const;
    unsigned long operator-(const Date& other) const;

    // Overloaded Comparison Operators
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;

    // Overloaded Increment/Decrement Operators
    Date& operator++();    // Prefix increment
    Date operator++(int);  // Postfix increment
    Date& operator--();    // Prefix decrement
    Date operator--(int);  // Postfix decrement

    // New Accessors
    unsigned int getConstDay() const;
    unsigned int getConstMonth() const;
    unsigned int getConstYear() const;

    // Overloaded Array-like Access Operator
    unsigned int& operator[](const std::string& field);

    // Friend function to output Date objects
    friend std::ostream& operator<<(std::ostream& os, const Date& date);

    // Helper function to get the number of days in a month
    unsigned int getDaysInMonth(unsigned int year, unsigned int month) const;

   private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    unsigned int year;
    unsigned int month;
    unsigned int day;
};


#endif //COSC1076_A3_DATE_H