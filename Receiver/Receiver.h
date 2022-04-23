/*
This file holds the declaration of Receiver class.
The input to this receiver is in the below form of floats (from Sender Console Output)
Temperature value == 24.000000   ChargeRate value == 60.000000
Currently the output of console is assumed to be stored in a file named consoleOutput.txt
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<vector>
using namespace std;

enum teBatteryParameter
{
   EN_TEMPERATURE = 0,
   EN_CHARGERATE
};

struct stBatteryValues
{
   float temperature;
   float chargeRate;
};

static void vDisplayBatteryValues(const vector<stBatteryValues> &m_BatteryValues)
{
   cout << "\n\n******Received Values From Sender******\n";

   for (int index = 0; index < (int)m_BatteryValues.size(); ++index)
   {
      cout << m_BatteryValues[index].temperature << "\t" << m_BatteryValues[index].chargeRate << "\n";
   }
}

class tclReceiver    //tcl -> type class
{
public:

   vector<stBatteryValues> vGetBatteryValues();

   /*
   Notes:
   Reads console output from Sender. Currently the output of console is assumed to be stored in a file
   named consoleOutput.txt
   */
   bool bReadConsoleOutputFromFileIntoVector();
   float fGetMinOfBatteryParamterFromSenderStream(teBatteryParameter oBatteryValue);
   float fGetMaxOfBatteryParamterFromSenderStream(teBatteryParameter oBatteryValue);
   float fDetermineMovingAverageOfBatteryParamFromSenderStream(teBatteryParameter oBatteryValue);

private:
   vector<stBatteryValues> m_BatteryValues;
};
