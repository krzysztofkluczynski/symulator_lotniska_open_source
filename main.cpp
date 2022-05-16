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
#include "data_base.h"
#include "interface.h"


using namespace std;

double geo_distance(string city1, string city2) {
    // Wroclaw Warszawa Gdansk Kopenhaga Mediolan Barcelona Londyn Krakow <- miasta do bazy
    // do mapy podajemy liczby w nastepujacym formacie:
    // Warszawa ma wspolrzedne 52°15′N 21°00′E
    // podajemy 52, 15, 21, 0
    // jesli zamiast N jest S to podajemy -52 i analogicznie dla E i W

    // tu tez trzeba bedzie zrobic liste dostepnych miast i wyjatek jakby ktos podal zle
    
    typedef array<double, 4> Fourth;
    map<string, Fourth> city_map;
    city_map["Wroclaw"] = {51, 6, 17, 2};
    city_map["Warszawa"] = {52, 15, 21, 0};
    city_map["Gdansk"] = {54, 21, 18, 40};    
    city_map["Kopenhaga"] = {55, 40, 12, 34};
    city_map["Mediolan"] = {45, 27, 9, 11};
    city_map["Barcelona"] = {41, 23, 2, 9};
    city_map["Londyn"] = {51, 30, 0, 7};
    city_map["Krakow"] = {50, 3, 19, 56};

    Fourth city_1 = city_map[city1];
    Fourth city_2 = city_map[city2];
    double x1_degree = city_1[0];
    double x1_min = city_1[1]*5/3;
    double y1_degree = city_1[2];
    double y1_min = city_1[3]*5/3;
    double x2_degree = city_2[0];
    double x2_min = city_2[1]*5/3;
    double y2_degree = city_2[2];
    double y2_min = city_2[3]*5/3;

    double x1, y1, x2, y2;
    x1 = x1_degree+x1_min/100;
    x2 = x2_degree+x2_min/100;
    y1 = y1_degree+y1_min/100;       
    y2 = y2_degree+y2_min/100;
    double one = pow((x2-x1), 2);
    double two = pow(cos(x1*M_PI/180)*(y2-y1), 2);
    double ret = sqrt(one+two)*40075.704/360;
    return ret;
    }

int main() {
    Data_base db("people.txt", "workers.txt", "flights.txt");

    cout << db.get_passengers()[0]->getDestinationCity().getName() << endl;


    cout << "Symulacja skonczona" << endl;

    return 0;
}