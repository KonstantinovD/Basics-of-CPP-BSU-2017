#include "TackInclude.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>




bool checkBissextile(int year) //Check is year have 365 or 366 days
{
    bool result = false;

    if (0 == year % 4)
    {
        result = true;
        if (0 == year % 100)
        {
            result = false;
            if (0 == year % 400)
            {
                result = true;
            }
        }
    }
    return result;
}

bool checkIsCorrectDate(int dayBirth, int dayNow, int monthBirth, int monthNow, int yearBirth, int yearNow) //Check if we input correct date
{
    if (yearNow < 0 || yearBirth < 0) return false;
    if ((monthBirth < 1 || monthBirth>12) || (monthNow < 1 || monthNow>12)) return false;

    int arrMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//So, now check if we input the correct number of days

    if (true == checkBissextile(yearBirth)) arrMonth[1] = 29; //if year is bissextile, february has 29 days
    if (dayBirth<1 || dayBirth>arrMonth[monthBirth - 1]) return false;
    arrMonth[1] = 28;
    if (true == checkBissextile(yearNow)) arrMonth[1] = 29;
    if (dayNow<1 || dayNow>arrMonth[monthNow - 1]) return false;

    //check if now date is smaller than birth
    if (yearBirth > yearNow) return false;
    else if (yearBirth == yearNow){
        if (monthBirth > monthNow) return false;
        else if (monthBirth == monthNow){
            if (dayBirth > dayNow) return false;
        }
    }

    return true;
}

int subtractExtraDays(int day1, int day2, int month1, int month2, int year1, int year2)
{
    int arrMonth[] = { 12, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int resultSubtr = 0;
    if (true == checkBissextile(year2)) arrMonth[2] = 29;
    for (int i = 12; i >= month2; i--)//iterate from the last month to the nowadays
    {
        resultSubtr -= arrMonth[i];
    }
    resultSubtr += day2;//and add current days of month, because they don't need to be subtracted
    arrMonth[2] = 28;//return for Febriary its initial days 


    if (true == checkBissextile(year1)) arrMonth[2] = 29;
    for (int i = 1; i < month1; i++)//iterate from the first month to the month of the birth
    {
        resultSubtr -= arrMonth[i];
    }
    resultSubtr -= day1;//and subtract days of month user was born

    //so, now the value of the resultSubtr is all the days

    return resultSubtr;
}

int countDaysOfLife(int day1, int day2, int month1, int month2, int year1, int year2)
{
    const int DAYS_IN_YEAR = 365;


    int resultSum = 0;

    for (int i = year1; i <= year2; i++)//count if we live for full years
    {
        resultSum += DAYS_IN_YEAR;
        if (true == checkBissextile(i)) resultSum += 1;
    }
    resultSum = resultSum + subtractExtraDays(day1, day2, month1, month2, year1, year2);

    return resultSum;
}




void integerArithmetic_5(std::ifstream& FIN)
{
    FIN.open("integerArithmetic_5.txt");
    int numberOfTests;
    FIN >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++)
    {
        int day1, day2, month1, month2, year1, year2;

        FIN >> day1 >> month1 >> year1 >> day2 >> month2 >> year2;

        if (true == checkIsCorrectDate(day1, day2, month1, month2, year1, year2))
        {
            int sumOfDaysOfLife = countDaysOfLife(day1, day2, month1, month2, year1, year2);
            std::cout << "You are living for " << sumOfDaysOfLife << " days" << std::endl;

            std::cout << "tack 1: ";
            integerArithmetic_1(FIN, sumOfDaysOfLife);
            std::cout << "tack 2: ";
            integerArithmetic_2(FIN, sumOfDaysOfLife);
            std::cout << "tack 4: ";
            integerArithmetic_4(FIN, sumOfDaysOfLife);
        }
        else
        {
            std::cout << "Incorrect date" << std::endl;
        }
        std::cout << "----------------------------------------------------------" << std::endl;
    }

}