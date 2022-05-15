#include "interface.h"
#include <algorithm>

using namespace std;

Interface::Interface(
        Data_base p_db,
        Date p_current_date,
        Date p_stop_date)
        : db(p_db), current_date(p_current_date), stop_date(p_stop_date) {}

Date Interface::getStopDate() const
{
    return stop_date;
}

Date Interface::getCurrentDate() const
{
    return current_date;
}


int Interface::menu()
{
    int options[6] = {1, 2, 3, 4, 5, 6};
    int choice;
    cout << "MENU - " << "CURRENT DATE: " << current_date << endl;
    cout << "1. Buy first class ticket" << endl;
    cout << "2. Buy second class ticket" << endl;
    cout << "3. Print all flights" << endl;
    cout << "4. Find passanger by pesel" << endl;
    cout << "5. Next day" << endl;
    cout << "6. QUIT" << endl;
    cout << "Your choice: ";
    cin >> choice;
    cout << endl;
    if (std::find(std::begin(options), std::end(options), choice) != std::end(options))
    {
        return choice;
    }
    throw InvalidInput();
}


void Interface::addFirstClass()
{
    cout << "brak implemtacji" << endl << endl;
}

void Interface::addSecondClass()
{
    cout << "brak implemtacji" << endl << endl;
}

void Interface::printFlights()
{
    cout << "brak implemtacji" << endl << endl;
}

void Interface::findByPesel()
{
    cout << "brak implemtacji" << endl << endl;
}

void Interface::nextDay()
{
    cout << endl <<"date changed FROM: " << current_date << " TO: " << ++current_date << endl << endl;    
}


