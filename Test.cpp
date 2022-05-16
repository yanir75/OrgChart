#include <iostream>
#include <stdexcept>
#include <vector>

#include "doctest.h"
#include "OrgChart.hpp"
using namespace ariel;
TEST_CASE("good input"){
    OrgChart organization;
    for(int i=0;i<100;i++){
        organization.add_root("test");
    }
    int count=0;
    for(std::string node:organization){
        CHECK_EQ(node,"test");
        count++;
    }
    CHECK_EQ(count,100);
    OrgChart organization1;
    organization1.add_root("test");
    for(int i=0;i<100;i++){
        organization1.add_sub("test","tester");
    }
    count=0;
    for(std::string node:organization1){
        if(count==0) {
                    CHECK_EQ(node, "test");
        }
        else{
                    CHECK_EQ(node, "tester");
        }
        count++;
    }
    CHECK_EQ(count,101);


    OrgChart organization2;
    organization2.add_root("test");
    for(int i=0;i<100;i++){
        std::string add="tester";
        add+=i;
        organization2.add_sub("test",add);
    }
    count=0;
    for (auto it=organization2.begin_reverse_order(); it!=organization2.reverse_order(); ++it) {
        std::string add="tester";
        add+=count;
        if(count==100) {
            add="test";
        }
        CHECK_EQ(*it, add);
        count++;
    }
}

TEST_CASE("bad input"){
    OrgChart tester;
    //tester.add_root("weird");
    CHECK_THROWS(tester.add_sub("test","test"));
    tester.add_root("weird");
    CHECK_THROWS(tester.add_sub("test","test"));
    for(int i=0;i<100;i++){
        CHECK_THROWS(tester.add_sub("test","test"));
        CHECK_NOTHROW(tester.add_sub("weird","weirdtest"));
    }
}