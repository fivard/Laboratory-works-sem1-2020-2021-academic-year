//
// Created by Admin on 27.09.2020.
//

#include "date.h"

Date::Date(int year,int month,int day, int hour, int minutes, int sec){
    leapYear = isLeap(year);

    this->year = year;

    if (month > 12 || month <= 0) {
        cout << "Incorrect month. Set 1th\n";
        this->month = 1;
    } else
        this->month = month;

    if (day > maxDay()) {
        cout << "Incorrect day. Set 1th\n";
        this->day = 1;
    } else
        this->day = day;

    if (hour >= 24 || hour < 0){
        cout << "Incorrect hour. Set 1th\n";
        this->hour = 1;
    } else
        this->hour = hour;

    if (minutes >= 60 || minutes < 0){
        cout << "Incorrect minutes. Set 1th\n";
        this->minutes = 1;
    }else
        this->minutes = minutes;

    if (sec >= 60 || sec < 0){
        cout << "Incorrect sec. Set 1th\n";
        this->sec = 1;
    }else
        this->sec = sec;

    countNumberTheDayAtWeek();
    countNumberTheDayAtYear();
    countNumberTheWeekAtYear();
}
Date::Date(int year, int month, int day) {
    leapYear = isLeap(year);

    this->year = year;

    if (month > 12 || month <= 0) {
        cout << "Incorrect month. Set 1th\n";
        this->month = 1;
    } else
        this->month = month;

    if (day > maxDay()) {
        cout << "Incorrect day. Set 1th\n";
        this->day = 1;
    } else
        this->day = day;

    hour = minutes = sec = 1;
    numberTheWeekAtYear = numberTheDayAtYear = 1;
    countNumberTheDayAtWeek();
}

void Date::countNumberTheDayAtWeek() {
    map<int, int> codeOfMonths{{1,1},
                              {2,4},
                              {3,4},
                              {4,0},
                              {5,2},
                              {6,5},
                              {7,0},
                              {8,3},
                              {9,6},
                              {10,1},
                              {11,4},
                              {12,6}};
    map<int,int> codeOfYears{{0,6},
                            {1,4},
                            {2,2},
                            {3,0}};

    int codeOfOurMonth = codeOfMonths[month];
    int codeOfOurYear = (codeOfYears[(year/100)%4] + year%100 + (year%100)/4)%7;
    if (leapYear && month <= 2)
        numberTheDayAtWeek = (day + codeOfOurMonth + codeOfOurYear +4) % 7;
    else
        numberTheDayAtWeek = (day + codeOfOurMonth + codeOfOurYear +5) % 7;
}
void Date::countNumberTheDayAtYear() {
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(leapYear)
        days[1]=29;
    int countOfDays = 0;
    for (int i = 0; i < month-1; i++)
        countOfDays += days[i];
    countOfDays += day;
    numberTheDayAtYear = countOfDays;
}
void Date::countNumberTheWeekAtYear() {
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(leapYear)
        days[1]=29;

    Date startYear(year,month,1);

    int countOfDays = 0;
    for (int i = 0; i < month-1; i++)
        countOfDays += days[i];

    countOfDays += day;

    int numberOfTheWeek = countOfDays/7 + 1;
    if (numberTheDayAtWeek < startYear.numberTheDayAtWeek)
        numberOfTheWeek++;
    numberTheWeekAtYear = numberOfTheWeek;
}

bool Date::isLeap(int y)const{
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}
int Date::maxDay()const{
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(leapYear)
        days[1]=29;
    return days[month-1];
}

long long Date::countSecForData()const {
        long long countSec = numberTheDayAtYear * 24 * 60 * 60 + hour * 60 * 60 + minutes * 60 + sec;
        for (int i = 1; i < year; i++) {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                countSec += 366 * 24 * 60 * 60;
            else
                countSec += 365 * 24 * 60 * 60;

        }
        return countSec;
}
void Date::createNewDataBySec(long long newSec){
    int i = 1;
    year = month = 1;
    while (newSec >= 365 * 24 * 60 * 60) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            newSec -= 366 * 24 * 60 * 60;
        else
            newSec -= 365 * 24 * 60 * 60;
        year++;
        i++;
    }
    leapYear = (i % 4 == 0 && i % 100 != 0) || i % 400 == 0;

    int countOfDays = newSec / 60 / 60 / 24;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leapYear)
        days[1] = 29;
    for (i = 0; countOfDays > days[i]; i++){
        month++;
        countOfDays -= days[i];
    }
    day = countOfDays;

    newSec -= numberTheDayAtYear*24*60*60;
    sec = newSec%60;
    newSec/=60;
    minutes = newSec%60;
    newSec/=60;
    hour = newSec%24;

    countNumberTheDayAtWeek();
    countNumberTheDayAtYear();
    countNumberTheWeekAtYear();
}