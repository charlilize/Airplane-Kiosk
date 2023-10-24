/*
    * Name: Charlize Angeles, 5007982234, 1006, Assignment 4
    * Description: A program that determines the cost of 
    airplane tickets depending on the ticket type
    * Input: ticket type wanted, amount of tickets,
    and whether to continue the program
    * Output: the different ticket types, total cost of the tickets
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // initialized variables
    // stores desired ticket type
    char selection = '\0';
    // price of each ticket type
    double firstClass = 750;
    double businessClass = 225;
    double economyClass = 150;
    // amount of available seats for each ticket type
    int firstClassTix = 15;
    int businessClassTix = 25;
    int economyClassTix = 50;
     // used to create a condition that keeps the loop going
    char valid = '\0'; 
    // amount of tickets the user wants
    int amount = 0;
    double total = 0.00;
    const double taxRate = 0.085;
    double salesTax = 0.00;
    double cost = 0.00;
    // whether the user wants to restart the program
    char shutDown = '\0';

    do {
        // ensure selection is available and is an actual ticket type
        do {

            // reset for next loop
            valid = '\0';

            // prompt user for the available ticket types
            if (firstClassTix > 0) {

                cout << "\n(F)irst\n";

            }

            if (businessClassTix > 0) {

                cout << "(B)usiness\n";

            }

            if (economyClassTix > 0) {

                cout << "(E)conomy\n";

            }

            // asks user to make a selection
            cout << "Enter a selection: ";
            cin >> selection;
            cout << '\n';

            // ensures that the ticket is a valid ticket type 
            // and there are still some of that type
            if ((selection == 'F' || selection == 'f')
            && firstClassTix > 0) {

                valid = 'y';

            } else if ((selection == 'B' || selection == 'b')
             && businessClassTix > 0) {

                valid = 'y';

            } else if ((selection == 'E' || selection == 'e')
             && economyClassTix > 0) {

                valid = 'y';

            } 


        // prompts again if no more tickets or wrong character input
        } while (valid != 'y'); 

        // reset for next loop
        valid = '\0';

        // prompts user for the ticket amount
        do {
            // ensures that it is a valid number
            if (!cin) {

                cin.clear();
                cin.ignore(256, '\n');

            }

            cout << "Enter amount: ";
            cin >> amount;

            // checks that the amount is less 
            // than the amount of available tickets
            if (amount > 0) {
                if ((selection == 'F' || selection == 'f')
                && amount <= firstClassTix) {

                    valid = 'y';

                } else if ((selection == 'B' || selection == 'b') 
                && amount <= businessClassTix) {

                    valid = 'y';

                } else if ((selection == 'E' || selection == 'e') 
                && amount <= economyClassTix) {

                    valid = 'y';

            }

        }

        // prompts again if invalid number, less than zero, 
        // or the amount is larger than the available amount of tickets
        } while(!cin || amount < 0 || valid != 'y');

            // calculate based on ticket type/amount of tickets
            if ((selection == 'F' || selection == 'f')
            && amount <= firstClassTix) {

                // decrease ticket amount
                firstClassTix = firstClassTix - amount;

                // calculate cost
                total = amount * firstClass;
                salesTax = total * taxRate;
                cost = total + salesTax;

                // display cost
                cout << fixed << setprecision(2) 
                << "\nCOST $ " << cost << '\n';

            } else if ((selection == 'B' || selection == 'b')
             && amount <= businessClassTix) {

                // decrease ticket amount
                businessClassTix = businessClassTix - amount;

                // calculate cost
                total = amount * businessClass;
                salesTax = total * taxRate;
                cost = total + salesTax;

                // display cost
                cout << fixed << setprecision(2)
                 << "\nCOST $ " << cost << '\n';

            } else if ((selection == 'E' || selection == 'e') 
            && amount <= economyClassTix) {
                
                // decrease ticket amount
                economyClassTix = economyClassTix - amount;

                // calculate cost
                total = amount * economyClass;
                salesTax = total * taxRate;
                cost = total + salesTax;

                // display cost
                cout << fixed << setprecision(2)
                 << "\nCOST $ " << cost << '\n';

            }

    do {
        // clear invalid input
        if (!cin) {

            cin.clear();
            cin.ignore(256, '\n');

        }
    
        // prompts user to shut down
        cout << "Shutdown? (Y/N): ";

        // user enters a choice
        cin >> shutDown;

    // loop again if user didn't put a valid option (Y/N)
    } while(shutDown != 'y' && shutDown != 'Y' 
      && shutDown != 'N' && shutDown != 'n');

    // if the user wants to shut down or there's no more tickets, end the program
    if (shutDown == 'y' || shutDown == 'Y' ||
    (firstClassTix == 0 && businessClassTix == 0 
    && economyClassTix == 0)) {

        return 0;

    }

    // if the user says no to shutdown reloop all over again
    } while (shutDown == 'N' || shutDown == 'n');
    
}
