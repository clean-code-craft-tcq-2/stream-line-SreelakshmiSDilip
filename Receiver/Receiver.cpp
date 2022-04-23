#include "Receiver.h"
#include <limits>

vector<stBatteryValues> tclReceiver::vGetBatteryValues()
{
   return m_BatteryValues;
}

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
      if (m_BatteryValues.at(Index).chargeRate < fminChargeRate)
      {
         fminChargeRate = m_BatteryValues.at(Index).chargeRate;
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

float tclReceiver::fDetermineMaxTemperatureValuesFromSenderStream()
{
   float fMaxTemperature = std::numeric_limits<float>::min();
   for (int Index = 0; Index < (int)m_BatteryValues.size(); ++Index)
   {
      if (m_BatteryValues.at(Index).temperature > fMaxTemperature)
      {
         fMaxTemperature = m_BatteryValues.at(Index).temperature;
      }
   }

   return fMaxTemperature;
}

float tclReceiver::fDetermineMaxChargeRateValuesFromSenderStream()
{
   float fMaxChargeRate = std::numeric_limits<float>::min();
   for (int Index = 0; Index < (int)m_BatteryValues.size(); ++Index)
   {
      if (m_BatteryValues.at(Index).chargeRate > fMaxChargeRate)
      {
         fMaxChargeRate = m_BatteryValues.at(Index).chargeRate;
      }
   }

   return fMaxChargeRate;
}

float tclReceiver::fGetMaxOfBatteryParamterFromSenderStream(teBatteryParameter oBatteryValue)
{
   if (oBatteryValue == EN_TEMPERATURE)
   {
      return fDetermineMaxTemperatureValuesFromSenderStream();
   }
   else
   {
      return fDetermineMaxChargeRateValuesFromSenderStream();
   }
}

float tclReceiver::fDetermineMovingAvgOfTemperatureValuesFromSenderStream(const int iNumberOfElements)
{
   float fMovingAverage = 0;
   if (iNumberOfElements <= (int)m_BatteryValues.size())
   {
      float sum = 0;
      for (int Index = ((int)m_BatteryValues.size() - 1); Index > iNumberOfElements; --Index)
      {
         sum += m_BatteryValues.at(Index).temperature;
      }
      fMovingAverage = (sum / iNumberOfElements);
   }
   return fMovingAverage;
}

/*float tclReceiver::fDetermineMovingAvgOfChargerRateValuesFromSenderStream(const int iNumberOfElements)
{
   float fMovingAverage = 0;
   if (iNumberOfElements <= (int)m_BatteryValues.size())
   {
      float sum = 0;
      for (int Index = ((int)m_BatteryValues.size() - 1); Index > iNumberOfElements; --Index)
      {
         sum += m_BatteryValues.at(Index).chargeRate;
      }
      fMovingAverage = (sum / iNumberOfElements);
   }
   return fMovingAverage;
}*/

float tclReceiver::fGetMovingAverageOfBatteryParamFromSenderStream(teBatteryParameter oBatteryValue, const int iNumberOfElements)
{
   if (oBatteryValue == EN_TEMPERATURE)
   {
      return fDetermineMovingAvgOfTemperatureValuesFromSenderStream(iNumberOfElements);
   }
   else
   {
      return fDetermineMovingAvgOfChargerRateValuesFromSenderStream(iNumberOfElements);
   }
}
