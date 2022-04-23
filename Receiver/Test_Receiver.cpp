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
