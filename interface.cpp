#include "interface.h"
#include <algorithm>

    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, second

using namespace std;

Interface::Interface(
        const DataBase& p_db,
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


void Interface::run()
{
    while(current_date <= stop_date)
    {
        cout << endl << "TODAY DATE: " << current_date << endl << endl;
        sleep_for(1500ms);
        for(auto &passenger : db.passengers)
        {
            if(passenger->getDate() == current_date)
            {
                cout << passenger->getName() << " " << passenger->getSurname() << " buys ticket for flight with id: " << passenger->getFlightId() << " from " << passenger->getSourceCity().getName() << " to " << passenger->getDestinationCity().getName() << "." << endl;
                sleep_for(500ms);
            }
        }


        cout << endl << endl << endl << "Flights this day: " << endl;

        for(auto flight: db.flights)
        {
            if(flight.get_date() == current_date)
            {
                cout << "Plane " << flight.get_plane().get_plane_name() << " took of from " << flight.get_departure().getName() << " to " << flight.get_arrival().getName() << endl;
                cout << "Capacity: " << flight.get_first_class().size() + flight.get_second_class().size() << " / " << flight.get_plane().get_sitting_places() << endl << endl; 
                sleep_for(500ms);
            }
        }
        current_date++;
        cout << "-------------------------" << endl;
    }
}



// void Interface::nextDay()
// {
//     cout << endl <<"date changed FROM: " << current_date << " TO: " << ++current_date << endl << endl;    
// }


