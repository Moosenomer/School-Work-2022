#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	//welcome to slimhortons, what can I get started for you today?
	double coffeePrice = 4.99, doughnutsPrice = 1.99;
	int Coffee = 0, Doughnuts = 0;
	string numCoffee = "", numDoughnuts = "";
	double coffeeTotal = 0.0, doughnutsTotal = 0.0, subtotal = 0.0;

	//Take user input for the amount of coffee & doughnuts 
	cout << "Please enter the number of coffee's you woud like to order: " << endl;
	cin >> numCoffee; 
	cout << "Please endter the number of doughnuts you would like to order: " << endl;
	cin >> numDoughnuts;


	//logic to verify that the number the user inputed is in fact a number, and that it is greater or equal to zero
	if ((isdigit(numCoffee[0])) && (isdigit(numDoughnuts[0]))) {

		Coffee = stoi(numCoffee);
		Doughnuts = stoi(numDoughnuts);

		if ((Coffee >= 0) && (Doughnuts >= 0)) {
			//pass
		}
		else {
			cout << " (1) The number that you tried to enter was under 0, please try again" << endl;
			return 0;
		}
	}
	else {
		cout << " (2) The characters that you tried to enter where invalid, please try again" << endl;
		return 0;
	}

	//Calculating the PRICE of each item with HST and total included
	double priceCoffee = (Coffee * 4.99), priceDoughnuts = (Doughnuts * 1.99);
	double subTotal = (priceCoffee + priceDoughnuts);
	double HST = (subTotal * 0.13);
	double total = (subTotal+HST);

	//beginning of the recipt
	cout << endl << endl << endl;
	cout << "SimHortons" << endl << "Customer Recipt" << endl << "-----------------" << endl;

	//Storing the width required for each part of the line in the recipt
	int firstLineCoffee = 9, firstLineDoughnuts = 6;
	int secondLineCoffee = 10, secondLineDoughnuts = 10;
	int subtotalWidth = 18, HSTWidth = 9, totalWidth = 21;

	//Storing the number of digits in coffee for formatting
	int numberCoffee = Coffee, numberDoughnuts = Doughnuts;

	//Math to figure out spaces neccessary for the lines with the cost of coffe and doughnuts
	while (numberCoffee > 9) {
		numberCoffee = numberCoffee / 10;
		secondLineCoffee = secondLineCoffee - 1; 
	}

	while (numberDoughnuts > 9) {
		numberDoughnuts = numberDoughnuts / 10;
		secondLineDoughnuts = secondLineDoughnuts - 1;
	}

	//First two lines of information on the reciept
	cout << "Coffee" << setw(firstLineCoffee) << "x" << Coffee << setw(secondLineCoffee) << fixed << setprecision(2) << priceCoffee << endl;
	cout << "Doughnuts" << setw(firstLineDoughnuts) << "x" << Doughnuts << setw(secondLineDoughnuts) << fixed << setprecision(2) << priceDoughnuts << endl;

	cout << endl;

	//Printing the lines for the subtotal, HST and the total
	cout << "Subtotal" << setw(subtotalWidth) << fixed << setprecision(2) << subTotal << endl;
	cout << "HST" << "           %13" << setw(HSTWidth) << fixed << setprecision(2) << HST << endl;
	cout << "Total" << setw(totalWidth) << fixed << setprecision(2) << total << endl;
}