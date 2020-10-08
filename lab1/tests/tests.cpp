//
// Created by Admin on 07.10.2020.
//

#include "../date.h"
#include "../graph.h"
#include "doctest.h"



TEST_CASE("Unit test"){
    Date date1{1, 1, 1,0,0,0};
    Odds odd{};
    odd.sec = 25;

    SUBCASE("Convert date in sec, operator +=, -="){
        CHECK(date1.countSecForData() == 86400);
        date1+=odd;
        CHECK(date1.countSecForData() == 86425);
        date1-=odd;
        CHECK(date1.countSecForData() == 86400);
    }

    Date date2{};
    date2.createNewDataBySec(86400);

    SUBCASE("Create date by sec"){
        CHECK(date1 == date2);
    }

    SUBCASE("operator <, >"){
        CHECK((date1 > date2) == 0);
        CHECK((date1 < date2) == 0);
        date1 += odd;
        CHECK((date1 > date2) == 1);
        CHECK((date1 < date2) == 0);
    }

    date1 += odd;
    SUBCASE("operator -"){
        odd = date1 - date2;
        CHECK(odd.sec == 25);
    }

};
