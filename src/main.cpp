/* 
 * File:   main.cpp
 * Author: Koncord
 *
 * Created on 20 Август 2014 г., 16:06
 */

#include "Reader.hpp"
#include <chrono>
#include <iostream>

using namespace std;

/*
 * 
 */


void speed_test(string esx) {
  auto start = chrono::high_resolution_clock::now();
  Reader read(esx);
  auto stop = chrono::high_resolution_clock::now();
  auto duration  = chrono::duration<double>(stop - start).count();
  cout << esx << " parsed! time: " << duration << endl;
}

int main(int argc, char** argv)
{
    //Reader read("Pip-Boy Remover.esp");
    //Reader read("ThePitt.esm");
    //Reader read("Fallout3.esm");
    //Reader read("weap.esp");
    
    speed_test("Fallout3.esm");
  
    return 0;
}

