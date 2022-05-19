#include <iostream>
#include <math.h>
#include <map>

#include "date.h"
#include "price.h"
#include "person.h"
#include "passenger_classes.h"
#include "worker_classes.h"
#include "planes.h"
#include "flight.h"
#include "interface.h"

using namespace std;

using namespace std::this_thread;
using namespace std::chrono; 

int main(int argc, char *argv[])
{
    string people_path = "people.txt";
    string workers_path = "workers.txt";
    string flights_path = "flights_path";

    if (argc == 3)
    {
        people_path = argv[1];
        workers_path = argv[2];
        flights_path = argv[3];
    }

    if (argc != 1 && argc != 3)
    {
        throw InvalidInput();
    }

    DataBase db("people.txt", "workers.txt", "flights.txt");
    Interface interface(db);
    try
    {
        interface.ask();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    cout << endl << "Simulation starting" << endl;
    sleep_for(100ms);
    cout << "-------------------------------------------------" << endl << endl;

    interface.run();

    return 0;
}