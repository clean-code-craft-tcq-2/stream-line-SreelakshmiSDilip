#include "../Test/catch.hpp"
#include "Receiver.h"

TEST_CASE("Test To check the retrieve of console ouput values") 
{
   tclReceiver oReceiver;
   bool bSuccess = oReceiver.bReadConsoleOutputFromFileIntoVector();
   assert(bSuccess == true);
   assert(!oReceiver.vGetBatteryValues().empty() == true);
   vDisplayBatteryValues(oReceiver.vGetBatteryValues());
}

TEST_CASE("Test To check the correctness of min value calculation of Battery temperature") 
{
   tclReceiver oReceiver;
   bool bSuccess = oReceiver.bReadConsoleOutputFromFileIntoVector();
   assert(bSuccess == true);
   assert(!oReceiver.vGetBatteryValues().empty() == true);
   
   // test minimum value.
   float fExpectedMinTempValue = 10;
   float fCalculatedMinTempValue= oReceiver.fGetMinOfBatteryParamterFromSenderStream(teBatteryParameter::EN_TEMPERATURE);
   assert(fExpectedMinTempValue == fCalculatedMinTempValue);
}

TEST_CASE("Test To check the correctness of min value calculation of Battery charge rate") 
{
   tclReceiver oReceiver;
   bool bSuccess = oReceiver.bReadConsoleOutputFromFileIntoVector();
   assert(bSuccess == true);
   assert(!oReceiver.vGetBatteryValues().empty() == true);
   
   // test minimum value.
   float fExpectedMinChargeRateValue = 10;
   float fCalculatedMinChargeRateValue = oReceiver.fGetMinOfBatteryParamterFromSenderStream(teBatteryParameter::EN_CHARGERATE);
   assert(fExpectedMinChargeRateValue == fCalculatedMinChargeRateValue);
}

TEST_CASE("Test To check the correctness of max value calculation of Battery temperature") 
{
   tclReceiver oReceiver;
   bool bSuccess = oReceiver.bReadConsoleOutputFromFileIntoVector();
   assert(bSuccess == true);
   assert(!oReceiver.vGetBatteryValues().empty() == true);
   
   // test maximum value of temperature.
   float fExpectedMaxTempValue = 60;
   float fCalculatedMaxTempValue = oReceiver.fGetMaxOfBatteryParamterFromSenderStream(teBatteryParameter::EN_TEMPERATURE);
   assert(fExpectedMaxTempValue == fCalculatedMaxTempValue);
}

TEST_CASE("Test To check the correctness of max value calculation of Battery charge rate") 
{
   tclReceiver oReceiver;
   bool bSuccess = oReceiver.bReadConsoleOutputFromFileIntoVector();
   assert(bSuccess == true);
   assert(!oReceiver.vGetBatteryValues().empty() == true);
   
   // test maximum value of charge rate.
   float fExpectedMaxChargeRateValue = 50;
   float fCalculatedMaxChargeRateValue = oReceiver.fGetMaxOfBatteryParamterFromSenderStream(teBatteryParameter::EN_CHARGERATE);
   assert(fExpectedMaxChargeRateValue == fCalculatedMaxChargeRateValue);
}

TEST_CASE("Test moving average calculation of Battery temperature value") 
{
   tclReceiver oReceiver;
   bool bSuccess = oReceiver.bReadConsoleOutputFromFileIntoVector();
   assert(bSuccess == true);
   assert(!oReceiver.vGetBatteryValues().empty() == true);
   
   // test moving average of last 5 elements of temperature values.
   float fExpectedMovingAvgOfTempValues = 37.0f;
   int iNumberOfElements = 5;    //last 5 elements
   float fCalculatedMovingAvgOfTempValues = oReceiver.fGetMovingAverageOfBatteryParamFromSenderStream(teBatteryParameter::EN_TEMPERATURE, iNumberOfElements);
   assert(fExpectedMovingAvgOfTempValues == fCalculatedMovingAvgOfTempValues);
}
