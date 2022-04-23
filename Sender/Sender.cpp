/* **************************************************************************************************
* File Name   : Sender.cpp
* Author      : Sreelakshmi
* Objective   :Stream Temperature and Charge rate value to console after reading from a file.
* * ************************************************************************************************** */


/* **************************************** Local Header Files **************************************************** */
#include "Sender.h"

/* **************************************** Declarations **************************************************** */

int numberofLines = 0;
vector<float> Temperature;
vector<float> ChargeRate;

/* **************************************** Function Pointer Array **************************************************** */
Send_Status (*SenderDataRead[])()={ReadSenderData};
Send_Status(*SenderOutput[])(vector<float> Temperature,vector<float> ChargeRate)={OutputInConsole};


/* **************************************** Read Values from File **************************************************** */
Send_Status ReadSenderData()
{

	float TempVal,ChargeRateVal = 0;
	int Index = 0;
        string line;
	Send_Status ReadStatus= e_FAIL;
	ifstream inputDataHandler; 
	inputDataHandler.open("./Sender/Sender_Data.txt");

	if (!inputDataHandler) 
	{ 	
		puts("\t\t *** e_FAILURE!!data could not be read ***");
		ReadStatus= e_FAIL;  
	}
	else 
	{
		while ( getline(inputDataHandler , line)) 
		{
			stringstream   linestream(line);
			linestream >> TempVal >> ChargeRateVal;
			Temperature.push_back(TempVal);
			ChargeRate.push_back(ChargeRateVal);
			Index++;
			numberofLines=Index;
		}

		puts("\t\t**SUCCESS!! DATA READ*\t\t\n");
		ReadStatus= e_PASS;
	}
	inputDataHandler.close();
	return ReadStatus;
}


/* **************************************** Input BMS Values  **************************************************** */
Send_Status InputValue(SenderInputType InVal )
{
	Send_Status FileReadSuccess = e_FAIL;
	FileReadSuccess=(*SenderDataRead[InVal])();
	return FileReadSuccess;
}


/* **************************************** Output BMS Values **************************************************** */
Send_Status OutputValue(SenderOutputType OutVal)
{

	Send_Status WriteStatus = e_FAIL;
	WriteStatus=(*SenderOutput[OutVal])(Temperature,ChargeRate);
	return WriteStatus;

}

/* **************************************** Get the console output as String **************************************************** */

string GetStringOutputForConsole(float Temperature,float ChargeRate)
{
	string currentTempString       = to_string(Temperature);
	string currentChargeRateString = to_string(ChargeRate);
	string l_OutputtoConsole = "Temperature value == " + currentTempString+ "\t"+" ChargeRate value == "+ currentChargeRateString;
	return l_OutputtoConsole;
}

/* **************************************** Output to Console **************************************************** */

Send_Status OutputInConsole(vector<float> Temperature,vector<float> ChargeRate)
{
	for(int Index=0;Index<numberofLines;Index++)
	{
		cout <<"\n"<< GetStringOutputForConsole( Temperature.at(Index), ChargeRate.at(Index));

	}
	return e_PASS;
}
