#include <iostream>
#include "graph.h"
#include "date.h"

using namespace std;


int main() {
    int year, month, day, hour, minutes, sec;
    cout << "Enter a new date\n [day]/[month]/[year]/[hour]/[minutes]/[sec]\n";
    cin >> day >> month >> year >> hour >> minutes >> sec;
    Date newDate1(year, month, day, hour, minutes, sec);
    cout << newDate1;

    cout << "Enter a new date\n [day]/[month]/[year]/[hour]/[minutes]/[sec]\n";
    cin >> day >> month >> year >> hour >> minutes >> sec;
    Date newDate2(year, month, day, hour, minutes, sec);
    cout << newDate2;

    Odds odd = newDate1 - newDate2;
    cout << odd;
    newDate1 += odd;
    cout << newDate1;
    newDate1 -= odd;
    cout << newDate1;

    return 0;
}