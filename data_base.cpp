#include "data_base.h"

using namespace std;

Data_base::Data_base(
    string people_path, 
    string workers_path,
    string flights_path) :
    people_path(people_path),
    workers_path(workers_path),
    flights_path(flights_path) {
        import_passengers();
        import_workers();
        import_flights();
    }

void Data_base::import_passengers() {
    fstream file;
    file.open(people_path, ios::in);
    if (!file.good()) throw "invalid file";
    string name, surname, pesel, departure, arrival, day, month, year, clas, flight_num;
    while (file >> name) {
        file >> surname;
        file >> pesel;
        file >> departure;
        file >> arrival;
        file >> day;
        file >> month;
        file >> year;
        file >> clas;
        file >> flight_num;
        Date date(stoi(day), stoi(month), stoi(year));
        City arri_city(arrival);
        City dep_city(departure);
        if (clas=="1") {
            FirstClassTicket ticket(dep_city, arri_city, date, stoul(flight_num));
            FirstClass passenger(name, surname, pesel, ticket);
            first.push_back(passenger);
        }
        else if (clas=="2") {
            SecondClassTicket ticket(dep_city, arri_city, date, stoul(flight_num));
            SecondClass passenger(name, surname, pesel, ticket);
            second.push_back(passenger);
        }
        else {
            throw InvalidClass();
        }
    }
    file.close();
}

void Data_base::import_workers() {
    fstream file;
    file.open(workers_path, ios::in);
    if (!file.good()) throw "invalid file";
    string name, surname, pesel, flight_num, type;
    while (file >> name) {
        file >> surname;
        file >> pesel;
        file >> flight_num;
        file >> type;
        if (type=="1") {
            Stewardess stew(name, surname, pesel, flight_num);
            stewardess.push_back(stew);
        }
        else if (type=="2") {
            Pilot pil(name, surname, pesel, flight_num);
            pilot.push_back(pil);
        }
        else if (type=="3") {
            LuggageMan luggage(name, surname, pesel, flight_num);
            luggage_man.push_back(luggage);
        }
        else if (type=="4") {
            Other oth(name, surname, pesel, flight_num);
            other.push_back(oth);
        }
        else {
            throw InvalidClass();
        }
    }
    file.close();
}

void Data_base::import_flights() {
    fstream file;
    file.open(flights_path, ios::in);
    if (!file.good()) throw "invalid file";
    string id, day, month, year, departure, arrival, p_name, p_type;
    while (file >> id) {
        file >> day;
        file >> month;
        file >> year;
        file >> departure;
        file >> arrival;
        file >> p_name;
        file >> p_type;
        Light_plane plane(p_name);
        if (p_type=="0") {
            Light_plane plane(p_name);
        }
        else if (p_type=="1") {
            Small_plane plane(p_name);
        }
        else if (p_type=="2") {
            Medium_plane plane(p_name);
        }
        else if (p_type=="3") {
            Big_plane plane(p_name);
        }
        else {
            throw InvalidPlaneType();
        }
        City dep(departure);
        City ari(arrival);
        Date date(stoi(day), stoi(month), stoi(year));
        Flight flight(stoul(id), date, dep, ari, plane);

        for (auto stew : stewardess) {
            if (flight.get_id() == stew.get_flight_num()) {
                flight.add_stewardess(Stewardess stew);
            }
        }

        for (auto pil : pilot) {
            if (flight.get_id() == pil.get_flight_num()) {
                flight.add_pilot(Pilot pil);
            }
        }

        for (auto lugg : luggage_man) {
            if (flight.get_id() == lugg.get_flight_num()) {
                flight.add_luggage_man(LuggageMan lugg);
            }
        }

        for (auto oth : other) {
            if (flight.get_id() == oth.get_flight_num()) {
                flight.add_other(Other oth);
            }
        }

        for (auto firs : first) {
            if (flight.get_id() == firs.get_ticket().getNumber()) {
                flight.add_first_class(FirstClass firs);
            }
        }

        for (auto sec : second) {
            if (flight.get_id() == sec.get_ticket().getNumber()) {
                flight.add_second_class(SecondClass sec);
            }
        }

        flights.push_back(flight);

    }
    file.close();
}