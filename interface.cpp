#include "interface.h"
#include <algorithm>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;      // nanoseconds, system_clock, second

using namespace std;

Interface::Interface(
    const DataBase &p_db,
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

void Interface::ask()
{
    this->stop_date = current_date;
    int choice = 0;
    int counter = 0;
    int options[4] = {1, 3, 6, 9};
    cout << "How long do you want the simulation to take? Type 1, 3, 6, 9 for number of days" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if (std::find(std::begin(options), std::end(options), choice) != std::end(options))
    {
        for(; counter < choice; counter++)
        {
            this->stop_date++;
        }
    } else {
        throw InvalidInput();   
    }
}

// void Interface::change_seats()
// {
//     random_device rd;
//     mt19937 mt(rd());
//     for (auto flight : db.flights)
//     {
//     if(flight.get_date() == current_date)
//         {
//             std::uniform_int_distribution<int> distribution(0, flight.get_second_class().size() - 1);
//             int person_who_changed_seats = distribution(mt);
//             SecondClass random_person = flight.get_second_class()[person_who_changed_seats];
//             flight.remove_passenger(random_person.getPesel());
//             flight.add_first_class(FirstClass(random_person.getName(), random_person.getSurname(), random_person.getPesel(), FirstClassTicket(random_person.getSourceCity(), random_person.getDestinationCity(),random_person.getDate() ,random_person.getTicket().getNumber())));
//             cout << random_person.getName() << " " << random_person.getSurname() << " changed from second class to first class." << endl;
//             //sleep_for(1500ms);
//         }
//     }
// }

// void Interface::cancel()
// {
//     cout << endl;
//     random_device rd;
//     mt19937 mt(rd());

//     std::uniform_int_distribution<int> distribution1(0, 1);

//     for (auto flight : db.flights)
//     {
//     if(flight.get_date() == current_date)
//         {
//             int if_someone_cancelled = distribution1(mt);
//             if(if_someone_cancelled)
//             {
//             std::uniform_int_distribution<int> distribution2(0, flight.get_second_class().size() - 1);
//             std::uniform_int_distribution<int> distribution3(0, flight.get_first_class().size() - 1);
//             int person_who_changed_seats_first = distribution2(mt);
//             int person_who_changed_seats_second = distribution3(mt);
//             SecondClass cancel_second = flight.get_second_class()[person_who_changed_seats_second];
//             FirstClass cancel_first = flight.get_first_class()[person_who_changed_seats_first];
//             flight.remove_passenger(cancel_first.getPesel());
//             flight.remove_passenger(cancel_second.getPesel());
//             sleep_for(500ms);
//             cout << cancel_first.getName() << " " << cancel_first.getSurname() << " cancelled his/her flight." << endl;
//             sleep_for(1500ms);
//             cout << cancel_second.getName() << " " << cancel_second.getSurname() << " cancelled his/her flight." << endl;
//             sleep_for(2500ms);
//             }
//         }
//     }
// }

void Interface::run()
{
    while (current_date < stop_date)
    {
        cout << endl
             << "TODAY DATE: " << current_date << endl
             << endl;
        //sleep_for(1000ms);


        for (auto &passenger : db.passengers)
        {
            if (passenger->getDate() == current_date)
            {
                cout << passenger->getName() << " " << passenger->getSurname() << " buys ticket for flight with id: " << passenger->getFlightId() << " from " << passenger->getSourceCity().getName() << " to " << passenger->getDestinationCity().getName() << "." << endl;
                //sleep_for(300ms);
            }
        }
        cout << endl << endl;
        //sleep_for(1500ms);

        // change_seats();
        // cancel();

        cout << endl
             << endl
             << endl
             << "Flights this day: " << endl;

        for (auto flight : db.flights)
        {
            if (flight.get_date() == current_date)
            {
                cout << "Plane " << flight.get_plane().get_plane_name() << " took of from " << flight.get_departure().getName() << " to " << flight.get_arrival().getName() << endl;
                //sleep_for(1000ms);
                cout << "Capacity: " << flight.get_first_class().size() + flight.get_second_class().size() << " / " << flight.get_plane().get_sitting_places() << endl << endl;
                cout << "Base price of this flight: " << flight.get_second_class()[0].getTicket().getRealPrice();
                cout << "First class price of this flight: " << flight.get_first_class()[0].getTicket().getRealPrice();
                //sleep_for(3000ms);
                cout << "Workers on this flight:" << endl << "Stweardesses: ";
                for (auto person : flight.get_stewardess())
                {
                    cout << person.getName() << " " << person.getSurname() << ", ";
                    //sleep_for(50ms);
                }
                cout << endl <<"Luggage men: ";
                for (auto person : flight.get_luggage_man())
                {
                    cout << person.getName() << " " << person.getSurname() << ", ";
                    //sleep_for(50ms);
                }
                cout << endl <<"Pilots: ";
                for (auto person : flight.get_pilot())
                {
                    cout << person.getName() << " " << person.getSurname() << ", ";
                    //sleep_for(50ms);

                }
                cout << endl <<"Other: ";
                for (auto person : flight.get_other())
                {
                    cout << person.getName() << " " << person.getSurname() << ", ";
                    //sleep_for(50ms);

                }
                cout << endl << endl;
                //sleep_for(2000ms);
            }
        }
        current_date++;
        cout << endl;
        cout << "------------- END OF THE DAY ---------------" << endl;
        //sleep_for(500ms);
    }
}