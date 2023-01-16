#!/bin/sh

cd source
mkdir SmartCalc_dist
cp *.c SmartCalc_dist
cp *.h SmartCalc_dist
cp CMakeLists.txt.user SmartCalc_dist
cp *.txt SmartCalc_dist
cp *.cpp SmartCalc_dist
cp *.ui SmartCalc_dist
cp *.sh SmartCalc_dist
cp clang-format SmartCalc_dist
tar -czf SmartCalc.tar SmartCalc_dist/