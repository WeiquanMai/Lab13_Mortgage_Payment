/*
CSC-237- C++
Project Name: Mortgage Payment
Student: Weiquan Mai
Date: April 3, 2025
Description: Program asks for mortgage information, and calculates monthly payment as well as total amount paid over the lifetime of the loan.
Program also outputs the information into an output file. 
The mortgage class' member functions are declared in Mortgage.h file and defined in Mortgage.cpp file.
Program should be compiled with Mortgage.cpp and Mortgage.h files.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Mortgage.h"
using namespace std;

int main()
{
	// Variables
	double loanAmount, annualInterestRate;
	int years;
	char keepRunning;
	string fileName;

	do
	{
		// Ask user for output file name
		cout << "Enter output file name: ";
		cin >> fileName;

		// Obtain loan information from user
		cout << "Enter the amount of the loan: ";
		cin >> loanAmount;
		cout << "Enter the annual interest rate in decimal form (example 0.075): ";
		cin >> annualInterestRate;
		cout << "Enter the length of the loan in years: ";
		cin >> years;

		// Create mortgage object with obtained information
		Mortgage mortgage(loanAmount, annualInterestRate, years);

		// Display mortgage information
		mortgage.displayMortgageInfo();

		// Write mortgage information to output file
		mortgage.outputPaymentSchedule(loanAmount, annualInterestRate / 12, mortgage.getMonthlyPayment(), fileName);

		// Ask if user wants to continue
		cout << "Do you wish to process another loan? ";
		cin >> keepRunning;
	} while (keepRunning == 'y' || keepRunning == 'Y');

	return 0;
}
