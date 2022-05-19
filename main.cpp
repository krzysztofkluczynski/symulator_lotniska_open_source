#include <iostream>
#include <math.h>
#include <map>

#include "date.h"
#include "price.h"
#include "person.h"
#include "passenger_classes.h"
#include "worker_classes.h"
#include "planes.h" //dodalem te dwa pliki do testow
#include "flight.h" //dopisz sobie w launch.json
#include "interface.h"


using namespace std;


int main() {
    DataBase db("people.txt", "workers.txt", "flights.txt");
    Interface interface(db);
    interface.run();

    // cout << db.get_passengers()[0]->getDestinationCity().getName() << endl;


    return 0;
}