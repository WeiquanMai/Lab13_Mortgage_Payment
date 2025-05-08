// Implementation file for the Mortgage class
#include "Mortgage.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

// Define setter functions
void Mortgage::setMonthlyPayment(double loanAmount, double annualInterestRate, int totalYears)
{
	double monthlyInterestRate = annualInterestRate / 12;
	int numberOfPayments = totalYears * 12;
	double powerFactor = pow((1 + monthlyInterestRate), numberOfPayments);
	monthlyPayment = (loanAmount * monthlyInterestRate * powerFactor) / (powerFactor - 1);
}

void Mortgage::setTotalPayback(double monthlyPayment, int totalYears)
{
	int numberOfPayments = totalYears * 12;
	totalPayBack = monthlyPayment * numberOfPayments;
}

// Void display functions
void Mortgage::displayMortgageInfo() 
{
	cout << endl;
	cout << "Loan Amount: $" << fixed << setprecision(2) << getLoanAmount() << endl;
	cout << "Annual Interest Rate: " << setprecision(5) << getAnnualInterestRate() << endl;
	cout << "Years to repay: " << setprecision(0) << getTotalYears() << endl;
	cout << "Monthly Payment: $" << setprecision(2) << getMonthlyPayment() << endl;
	cout << "Total Pay Back: $" << getTotalPayBack() << endl << endl;
}
void Mortgage::outputPaymentSchedule(double loanAmount, double monthlyInterestRate, double monthlyPayment, string fileName)
{
	double remainingBalance = loanAmount;
	double interest;
	double contribToPrinciple;
	int fieldwidth = 18;
	ofstream outputFile;
	outputFile.open(fileName);
	outputFile << fixed << right << setprecision(2);

	// Display column headings
	outputFile << setw(5) << "Pmt#" << setw(fieldwidth) << "Payment Amount" << setw(fieldwidth) << "Interest" << setw(25) << "Contrib to principle" << setw(fieldwidth) << "Remaining balance" << endl;

	// Loop through to display each payment 
	for (int i = 1; remainingBalance > 0; i++)
	{
		interest = monthlyInterestRate * remainingBalance;
		contribToPrinciple = monthlyPayment - interest;
		remainingBalance = remainingBalance - contribToPrinciple;
		outputFile << setw(5) << i << setw(fieldwidth) << monthlyPayment << setw(fieldwidth) << interest << setw(25) << contribToPrinciple << setw(fieldwidth) << remainingBalance << endl;
	}
	outputFile.close();
}
// Define getter functions
double Mortgage::getLoanAmount() const
{
	return loanAmount;
}
double Mortgage::getAnnualInterestRate() const
{
	return annualInterestRate;
}
double Mortgage::getTotalYears() const
{
	return totalYears;
}
double Mortgage::getMonthlyPayment() const
{
	return monthlyPayment;
}
double Mortgage::getTotalPayBack() const
{
	return totalPayBack;
}
