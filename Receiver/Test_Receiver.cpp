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

