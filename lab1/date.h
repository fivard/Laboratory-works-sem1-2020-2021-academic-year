//
// Created by Admin on 27.09.2020.
//

#ifndef LAB1_DATE_H
#define LAB1_DATE_H

#include "graph.h"

using namespace std;


class Odds{
public:
    int day;
    int month;
    int year;
    int hour;
    int minutes;
    int sec;
    Odds()= default;
    friend ostream& operator<<(std::ostream& os, const Odds& odd) {
        cout << "year: " << odd.year << endl;
        cout << "month: " << odd.month << endl;
        cout << "day: " << odd.day << endl;
        cout << "hour: " << odd.hour << endl;
        cout << "minutes: " << odd.minutes << endl;
        cout << "sec: " << odd.sec << endl;
        return os;
    }
};

class Date{
    int day;
    int month;
    int year;
    int hour;
    int minutes;
    int sec;

    int numberTheDayAtWeek;
    int numberTheDayAtYear;
    int numberTheWeekAtYear;
    bool leapYear;

    bool isLeap(int)const;
    int maxDay()const;
    void countNumberTheDayAtWeek();
    void countNumberTheDayAtYear();
    void countNumberTheWeekAtYear();

public:
    Date(int year,int month,int day, int hour, int minutes, int sec);
    Date(int year,int month,int day);
    Date()= default;
    long long countSecForData()const;
    void createNewDataBySec(long long newSec);
    
    Date& operator=(const Date& right)= default;
    friend bool operator==(const Date& left, const Date& right){
        return (left.year == right.year && left.month == right.month && left.day == right.day
                && left.hour == right.hour && left.minutes == right.minutes &&left.sec == right.sec);
    }
    friend bool operator>(const Date& left, const Date& right){
        if (left == right)
            return false;

        if (left.year != right.year)
            return left.year > right.year;

        if (left.month != right.month)
            return left.month > right.month;

        if (left.day != right.day)
            return left.day > right.day;

        if (left.hour != right.hour)
            return left.hour > right.hour;

        if (left.minutes != right.minutes)
            return left.minutes > right.minutes;

        return left.sec > right.sec;
    }
    friend Odds operator-(const Date& left, const Date& right) {

        Odds result{};
        if (right > left) {
            cout << "First date is less then second date\n";
            return result;
        }

        long long leftSec = left.numberTheDayAtYear * 24 * 60 * 60 + left.hour * 60 * 60 + left.minutes * 60 + left.sec;
        long long rightSec = right.numberTheDayAtYear * 24 * 60 * 60 + right.hour * 60 * 60 + right.minutes * 60 + right.sec;

        for (int i = 1; i < left.year; i++){
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
                if (i < right.year)
                    rightSec += 366 * 24 * 60 * 60;
                leftSec += 366 * 24 * 60 * 60;
            } else {
                if (i < right.year)
                    rightSec += 365 * 24 * 60 * 60;
                leftSec += 365 * 24 * 60 * 60;
            }
        }

        result.sec = leftSec - rightSec;
        result.minutes = result.sec/60;
        result.hour = result.minutes / 60;
        result.day = result.hour / 24;
        result.month = result.day / 31;
        result.year = result.month / 12;
        return result;
    }
    friend Date& operator+=(Date& date, const Odds& odd) {
        long long leftSec = date.countSecForData();
        long long newSec = leftSec + odd.sec;
        Date newDate{};
        newDate.createNewDataBySec(newSec);
        date = newDate;
        return date;
    }
    friend Date& operator-=(Date& date, const Odds& odd) {
        long long leftSec = date.countSecForData();
        long long newSec = leftSec - odd.sec;
        Date newDate{};
        newDate.createNewDataBySec(newSec);
        date = newDate;
        return date;
    }

    friend ostream& operator<<(std::ostream& os, const Date& date){
        string monthName[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
        string dayName[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        os << date.day << "." << monthName[date.month-1] << "." << date.year << "  " << dayName[date.numberTheDayAtWeek] << " ";
        if (date.hour < 10)
            cout << 0;
        cout << date.hour << ":";
        if (date.minutes < 10)
            cout << 0;
        cout << date.minutes << ":" ;
        if (date.sec < 10)
            cout << 0;
        cout << date.sec;

        cout << " " << date.numberTheWeekAtYear << "th week\n";
        return os;
    }
};


#endif //LAB1_DATE_H