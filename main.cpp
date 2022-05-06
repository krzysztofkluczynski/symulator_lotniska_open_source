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


using namespace std;

double geo_distance(string city1, string city2) {
    // do mapy podajemy liczby w nastepujacym formacie:
    // Warszawa ma wspolrzedne 52°15′N 21°00′E
    // podajemy 52, 15, 21, 0
    // jesli zamiast N jest S to podajemy -52 i analogicznie dla E i W

    // tu tez trzeba bedzie zrobic liste dostepnych miast i wyjatek jakby ktos podal zle
    
    typedef array<double, 4> Fourth;
    map<string, Fourth> city_map;
    city_map["Wroclaw"] = {51, 6, 17, 2};
    city_map["Warszawa"] = {52, 15, 21, 0};
    Fourth city_1 = city_map[city1];
    Fourth city_2 = city_map[city2];
    double x1_degree = city_1[0];
    double x1_min = city_1[1];
    double y1_degree = city_1[2];
    double y1_min = city_1[3];
    double x2_degree = city_2[0];
    double x2_min = city_2[1];
    double y2_degree = city_2[2];
    double y2_min = city_2[3];

    x1_min = x1_min*5/3;
    x2_min = x2_min*5/3;
    y1_min = y1_min*5/3;
    y2_min = y2_min*5/3;
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
    //cout << geo_distance("Wroclaw", "Warszawa");
    // Light_plane light("alpha");
    // Medium_plane medium("beta");
    // Flight flight(light);
    // flight.set_plane(medium);
    string a = "aaaa";
    string b = "aaaaa";
    if (a == b) {
        cout << "sasasa";
    }
    return 0;
}