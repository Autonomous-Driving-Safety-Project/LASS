//
// Created by violin on 2022/5/1.
//

#include <iostream>
#include <string>
#include <fstream>
#include "esmini/esminiLib.hpp"

using namespace std;

int main() {
    std::ifstream t("resources/xosc/merge.xosc");
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    SE_InitWithString(str.c_str(), 0, 1, 0, 0);
//    auto lass = Lass(str.c_str(), true);
    int time = 10;
    while(time--) {
        SE_StepDT(0.01f);
//        cout << time << endl;
    }
    SE_Close();
}