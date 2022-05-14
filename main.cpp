/**
 * Demo file for the exercise on iterators
 *
 * @author Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/OrgChart.cpp"
using namespace ariel;

int main() {
    OrgChart tester;
//    tester.add_root("weird");
    tester.add_sub("test","test");
}