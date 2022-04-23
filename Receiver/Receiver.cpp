#include "Receiver.h"
#include <limits>

bool tclReceiver::bReadConsoleOutputFromFileIntoVector()
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

float tclReceiver::fDetermineMinTemperatureValuesFromSenderStream()
{
   float fminTemperature = std::numeric_limits<float>::max();
   for (int Index = 0; Index < (int)m_BatteryValues.size(); ++Index)
   {
      if (m_BatteryValues.at(Index).temperature < fminTemperature)
      {
         fminTemperature = m_BatteryValues.at(Index).temperature;
      }
   }

   return fminTemperature;
}

float tclReceiver::fDetermineMinChargeRateValuesFromSenderStream()
{
   float fminChargeRate = std::numeric_limits<float>::max();
   for (int Index = 0; Index < (int)m_BatteryValues.size(); ++Index)
   {
      if (m_BatteryValues.at(Index).temperature < fminChargeRate)
      {
         fminChargeRate = m_BatteryValues.at(Index).temperature;
      }
   }
   return fminChargeRate;
}

float tclReceiver::fGetMinOfBatteryParamterFromSenderStream(teBatteryParameter oBatteryValue)
{
   if (oBatteryValue == EN_TEMPERATURE)
   {
      return fDetermineMinTemperatureValuesFromSenderStream();
   }
   else
   {
      return fDetermineMinChargeRateValuesFromSenderStream();
   }
}

vector<stBatteryValues> tclReceiver::vGetBatteryValues()
{
   return m_BatteryValues;
}
