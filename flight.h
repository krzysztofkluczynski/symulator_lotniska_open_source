#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>
#include <string>
#include <memory>
#include <list>

#include "planes.h"
#include "passenger_classes.h"
#include "worker_classes.h"
#include "person.h"


class Flight {
    private:
        Planes& plane;
        std::list<std::unique_ptr<Person>> passenger;
        std::list<std::unique_ptr<Worker>> workers;
    public:
        Flight(Planes& plane,
        std::list<std::unique_ptr<Person>> passenger = {},
        std::list<std::unique_ptr<Worker>> workers = {});

        std::unique_ptr<Planes> get_plane();
        std::vector<FirstClass> get_first_class();
        std::vector<SecondClass> get_second_class();
        std::list<std::unique_ptr<Worker>> get_workers();

        void set_plane(Planes& plane);

        void add_stewardess(const Stewardess&); // tu pytanie czy to maja byc 4 metody czy jedna
        void add_pilot(const Pilot&); //latwiej zaimplementowac 4 
        void add_luggage_man(const LuggageMan&); // ale jako jedna tez pewnie sie da,
        void add_other(const Other&); // pytanie jak potrzebujemy potem do database

        void add_first_class(const FirstClass&); // analogiczne pytanie jak wyzej
        void add_second_class(const SecondClass&);

        int passengers_number(); // ilu pasazerow
        int workers_number();

        void remove_passenger(std::string pesel); // usuwanie pasazera
        bool check_passenger(std::string pesel); // sprawdzenie czy pasazer juz ma bilet


};

#endif 