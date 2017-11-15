#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>



bool CheckBissextile(int year)
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


bool checkDate(int& day, int& month, int limit)
{
    if (day > limit + 1) return false;
    else{
        day = 1;
        month += 1;
        return true;
    }
}


bool nextDate(int& day, int& month, int& year, bool isLeapYear)
{
    if (year < 0) return false;
    if (month < 1 || month > 12) return false;

	day = day + 1;


    bool correctDate = true;
	switch (month)
	{
    case 1: { if (day > 31) correctDate = checkDate(day, month, 31); break; }
	case 2: { 
		if (0 == isLeapYear){ //If the year isn't leap
            if (day > 28) correctDate = checkDate(day, month, 28); break;
		}
		else{ //If the year is leap
            if (day > 29) correctDate = checkDate(day, month, 29); break;
		}
	}
    case 3: { if (day > 31) correctDate = checkDate(day, month, 31); break; }
    case 4: { if (day > 30) correctDate = checkDate(day, month, 30); break; }
    case 5: { if (day > 31) correctDate = checkDate(day, month, 31); break; }
    case 6: { if (day > 30) correctDate = checkDate(day, month, 30); break; }
    case 7: { if (day > 31) correctDate = checkDate(day, month, 31); break; }
    case 8: { if (day > 31) correctDate = checkDate(day, month, 31); break; }
    case 9: { if (day > 30) correctDate = checkDate(day, month, 30); break; }
    case 10: { if (day > 31) correctDate = checkDate(day, month, 31); break; }
    case 11: { if (day > 30) correctDate = checkDate(day, month, 30); break; }
    case 12: { if (day > 31){
        if (day == 32)
        {
            day = 1;
            month = 1;
            year = year + 1;
        }
        else correctDate = false;
        break;
    }
	}
	}

    return correctDate;
}



void func_5(std::ifstream& FIN)
{
	FIN.open("test5.txt");
	int numberOfTests;
	FIN >> numberOfTests;

	for (int i = 0; i < numberOfTests; i++)
	{
		int day = 0, month = 0, year = 0;
		if (!FIN.eof())
		{
            FIN >> day >> month >> year;
            bool isLeapYear = CheckBissextile(year);
            bool CorrectInput = nextDate(day, month, year, isLeapYear);
            if (CorrectInput)
            {
                std::cout << std::setfill('0') << std::setw(2) << day << " ";
                std::cout << std::setfill('0') << std::setw(2) << month << " " << year << std::endl;
            }
            else
            {
                std::cout << "Incorrect date" << std::endl;
            }
            
			
		}               
		

	}
}