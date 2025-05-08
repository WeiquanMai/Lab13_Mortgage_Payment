// Specification file for the Mortgage class
#ifndef MORTGAGE_H
#define MORTGAGE_H
#include <iostream>
using namespace std;

// Mortgage class declaration
class Mortgage
{
private:
	double loanAmount = 0;
	double annualInterestRate = 0;
	double monthlyPayment = 0;
	double totalPayBack = 0;
	int totalYears = 0;
public:
	// Default no-args constructor
	Mortgage(){}

	// Constructor with arguments
	Mortgage(double loan, double annualInterest, int totalYearsToRepay) {
		cout << "INFO: executing constructor for Mortgage class." << endl;
		loanAmount = loan;
		annualInterestRate = annualInterest;
		totalYears = totalYearsToRepay;
		setMonthlyPayment(loan, annualInterest, totalYearsToRepay);
		setTotalPayback(getMonthlyPayment(), totalYearsToRepay);
	}

	// Destructor
	~Mortgage() 
	{
		cout << "INFO: executing DESTRUCTOR for Mortgage class (loan amount = " << getLoanAmount() << ")." << endl;
	}

	// Setters
	void setMonthlyPayment(double loanAmount, double annualInterestRate, int totalYears);
	void setTotalPayback(double monthlyPayment, int totalYears);
	void displayMortgageInfo();
	void outputPaymentSchedule(double loanAmount, double monthlyInterestRate, double monthlyPayment, string fileName);

	// Getters
	double getLoanAmount() const;
	double getAnnualInterestRate() const;
	double getTotalYears() const;
	double getMonthlyPayment() const;
	double getTotalPayBack() const;

};
#endif
