#include "Receiver.h"

bool tclReceiver::bReadConsoleOutputFromFileIntoVector(vector<stBatteryValues> &m_BatteryValues)
{
   bool bReturnVal = false;
   ifstream indata;
   indata.open("./Receiver/consoleOutput.txt");
   
   if (indata)
   {
      std::string line;
      while (std::getline(indata, line))
      {
         stringstream oLineStream(line);
         std::string IndividualWord;
         int digitcount = 1;
         stBatteryValues oBatteryValues;
         while (oLineStream >> IndividualWord)
         {
            float number;  //extract temperature and ChargeRate value.
            if (stringstream(IndividualWord) >> number)
            {
               if (digitcount == 1)
               {
                  // first word is a temperature
                  oBatteryValues.temperature = number;
               }
               else
               {
                  oBatteryValues.chargeRate = number;
               }
               ++digitcount;
            }
         }
         m_BatteryValues.push_back(oBatteryValues);
      }
      indata.close();
      bReturnVal = true;
   }
   
   return bReturnVal;
}

