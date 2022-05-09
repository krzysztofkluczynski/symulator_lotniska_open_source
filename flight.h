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
        std::vector<Stewardess> stewardess;
        std::vector<Pilot> pilot;
        std::vector<LuggageMan> luggage_man;
        std::vector<Other> other;
        std::vector<FirstClass> first_class;
        std::vector<SecondClass> second_class;
    public:
        Flight(Planes& plane,
        std::vector<Stewardess> stewardess = {},
        std::vector<Pilot> pilot = {},
        std::vector<LuggageMan> luggage_man = {},
        std::vector<Other> other = {},
        std::vector<FirstClass> first_class = {},
        std::vector<SecondClass> second_class = {});

        void set_plane(Planes& plane);

        Planes& get_plane();

        void add_stewardess(Stewardess); // tu pytanie czy to maja byc 4 metody czy jedna
        void add_pilot(Pilot); //latwiej zaimplementowac 4 
        void add_luggage_man(LuggageMan); // ale jako jedna tez pewnie sie da,
        void add_other(Other); // pytanie jak potrzebujemy potem do database

        bool add_first_class(FirstClass); // analogiczne pytanie jak wyzej
        bool add_second_class(SecondClass);

        int first_class_num();
        int second_class_num();
        int passengers_number(); // ilu pasazerow
        
        int stewardess_num();
        int pilot_num();
        int luggage_num();
        int other_num();
        int workers_number();

        void remove_passenger(std::string pesel); // usuwanie pasazera
        bool check_passenger(std::string pesel); // sprawdzenie czy pasazer juz ma bilet

};

#endif 