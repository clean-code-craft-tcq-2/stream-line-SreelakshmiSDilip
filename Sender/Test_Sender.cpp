#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../Test/catch.hpp"
#include "Sender.h"

TEST_CASE("To check if the sender reads data from input file") 
{
  SenderInputType InVal = FileInput ; 
  REQUIRE(InputValue(InVal) == e_PASS); 
}


TEST_CASE("To check if sender prints data to console") 
{
  SenderOutputType OutVal = PrintToConsole ;
  REQUIRE(OutputValue(OutVal)== e_PASS);
  
}

TEST_CASE("To check if output format is correct")
{
  REQUIRE(GetStringOutputForConsole(24,60) == "Temperature value == 24.000000	 ChargeRate value == 60.000000");
  
}
