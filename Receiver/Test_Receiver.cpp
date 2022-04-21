#include "../Test/catch.hpp"
#include "Receiver.h"


TEST_CASE("Test To check the retrieve of console ouput values") 
{
   tclReceiver oReceiver;
   vector<stBatteryValues> oBatteryValues;
   bool bSuccess = oReceiver.bReadConsoleOutputFromFileIntoVector(oBatteryValues);
   assert(bSuccess == true)
}

