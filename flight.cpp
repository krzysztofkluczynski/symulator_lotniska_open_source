#include "flight.h"

using namespace std;

Flight::Flight(Planes& plane,
        list<unique_ptr<Person>> passenger,
        list<unique_ptr<Worker>> workers) :
        plane(plane), passenger(passenger), workers(workers) {}

// geeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeettttttttttteeeeeeeeeeerrrrrrsssssss


// sekcja dodawania pracownikow
void Flight::add_stewardess(const Stewardess& stewardess) {
    unique_ptr<Stewardess> added_stewardess = make_unique<Stewardess>(stewardess);
    workers.push_back(move(added_stewardess));
}

void Flight::add_pilot(const Pilot& pilot) {
    unique_ptr<Pilot> added_pilot = make_unique<Pilot>(pilot);
    workers.push_back(move(added_pilot));
}

void Flight::add_luggage_man(const LuggageMan& luggage_man) {
    unique_ptr<LuggageMan> added_luggage_man = make_unique<LuggageMan>(luggage_man);
    workers.push_back(move(added_luggage_man));
}

void Flight::add_other(const Other& other) {
    unique_ptr<Other> added_other = make_unique<Other>(other);
    workers.push_back(move(added_other));
}


// sekcja dodawania pasazerow
void Flight::add_first_class(const FirstClass& first_class) {
    unique_ptr<FirstClass> added_first_class = make_unique<FirstClass>(first_class);
    passenger.push_back(move(added_first_class));
}

void Flight::add_second_class(const SecondClass& second_class) {
    unique_ptr<SecondClass> added_second_class = make_unique<SecondClass>(second_class);
    passenger.push_back(move(added_second_class));
}

// setter samolotu to nie ma prawa dzialać ale testujemy
void Flight::set_plane(Planes& new_plane) {
    plane = new_plane;
}

void Flight::remove_passenger(string pesel) {
    int i = 0;
}

bool Flight::check_passenger(string pesel) {
    for(list<unique_ptr<Person>>::iterator i=passenger.begin(); i!=passenger.begin(); i++) {
        if ((*i)->getPesel() == pesel) {
            return true;
        }
    }
    return false;
}

int Flight::passengers_number() {
    return passenger.size();
}

int Flight::workers_number() {
    return workers.size();
}