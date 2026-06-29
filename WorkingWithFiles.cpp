// CS210 Module 5.2
// 
// Author: Sergio J. Vargas
// Date: 06/05/2026
// 
// Purpose: Read and write text files

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// convert degrees fahrenheit to celcius
// @param fahrenheit in integers
// @returns double celius values
double fahrenheitToCelcius(int fahrenheit) {
  return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
  int storedTemp;
  string storedCity;
  double newTemp;

  // open existing file
  ifstream readTempF;
  readTempF.open("FahrenheitTemperature.txt");

  // exit program if file could not be opened
  if (!readTempF.is_open()) {
    cout << "Could not open the file!" << endl;
    return 1;
  }

  // open new file to write to memory
  ofstream writeTempC;
  writeTempC.open("CelsiusTemperature.txt");

  // read fahrenheit values and save as c values
  while(readTempF >> storedCity >> storedTemp) {
    // store converted value
    newTemp = fahrenheitToCelcius(storedTemp);

    // write text file to memory
    writeTempC << storedCity << " " << newTemp << endl;
  }

  // close files
  readTempF.close();
  writeTempC.close();

  return 0;
}
