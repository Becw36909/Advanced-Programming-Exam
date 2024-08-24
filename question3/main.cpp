/*                                           */
/* DO NOT MOFIFY ANY CODE IN THIS FILE       */
/*                                           */

#include <exception>
#include <iostream>
#include <memory>

#include "Date.h"


int main(){
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    
    std::cout << std::endl << "*** Q3 PART 1 ***" << std::endl;

    // Create a date object ptr: examDate and initialize it to 10/06/2021
    std::shared_ptr<Date> examDate = std::make_shared<Date>(2021, 6, 10);
    // Print the examDate and the "day number" for examDate
    std::cout << "Exam date: " << *examDate << " (" 
                        << examDate->getDayNumber() << ") " << std::endl;

    // Create a date object ptr: resultDate and initialize it to 12/07/2021
    std::shared_ptr<Date> resultDate = std::make_shared<Date>(2021, 7, 12);
    // Print the resultDate and the "day number" for resultDate
    std::cout << "Result release date: " << *resultDate << " (" 
                        << resultDate->getDayNumber() << ") "<< std::endl;

    //print days between resultDate and examDate
    std::cout << "Days to get results = " 
                    << *resultDate - *examDate << std::endl;

    // Compute exam end date. This is one day after examDate
    *examDate += 1;
    std::cout << "Exam end date: " << *examDate << std::endl;

    // Compute the results date next year: 365 days after this results date
    Date resultDateNextYear = *resultDate + 365;
    std::cout << "Result Date Next Year: " << resultDateNextYear << std::endl;  

    
    std::cout << std::endl << "*** Q3 PART 2 ***" << std::endl;

    // Create two date objects
    Date date1(1982, 6, 2);
    Date date2(2017, 12, 11);
    std::cout << "date1: " << date1 << ", date2: " << date2 << std::endl;

    //Compare the two dates and print
    if (date1 != date2){
        if (date1 > date2){
            std::cout << "date1 > date2" << std::endl;
        }else{
            std::cout << "date1 < date2" << std::endl;
        }
    }else{
        std::cout << "date1 == date2" << std::endl;
    }

    std::cout << std::endl << "*** Q3 PART 3 ***" << std::endl;
    
    // Create a date object
    Date date3(1918, 6, 20);
    std::cout << "date3: " << date3 << std::endl;

    // Print the next date from date1
    date3 = date3++;
    std::cout << "date3++: " << date3 << std::endl;

    // Print the previous date from date1
    date3 = date3--;
    std::cout << "date3--: " << date3 << std::endl;

    std::cout << std::endl << "*** Q3 PART 4 ***" << std::endl;
    //Update the year of date3
    std::cout << "date3: " << date3 << std::endl;

    try{
        date3["year"] = 2018;
        std::cout << "date3: " << date3["day"] 
                        << "-" << date3["month"] 
                        << "-" << date3["year"] << std::endl;
    }catch(std::exception& e) {
      std::cout << "*** caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}