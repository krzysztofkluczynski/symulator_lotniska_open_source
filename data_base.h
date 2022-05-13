#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <fstream>
#include <string>
#include <memory>
#include <list>
#include "flight.h"
#include "passenger_classes.h"
#include <random>


class Data_base 
{
    private:
        std::string people_path;
        std::string workers_path;
        std::string planes_path;
        std::string flights_path;
        
        std::vector<Other> other;
        std::vector<LuggageMan> luggage_man;
        std::vector<Stewardess> stewardess;
        std::vector<Pilot> pilot;

        std::vector<FirstClass> first;          //TE DWA WEKTORY CHHYBA BEDA DO USUNIECIA W TAKIM RAZIE I ZASTAPI JE WEKTOR PEOPLE
        std::vector<SecondClass> second;

        std::vector<Person> people;

        std::list<std::shared_ptr<Person>> passengers;  // <-- to lista wszystkich pasazerow bedzie, potrzebna potem do losowania


        std::vector<Flight> flights;

        void import_passengers();   //<- TO TEZ PEWNIE BEDZIE NA ZASADZIE IMPORT PEOPLE
        void import_workers();
        void import_flights();

        std::unique_ptr<Planes> create_plane(std::string p_type, std::string p_name);
        void assignPassengers();

    public: 
        Data_base(
        std::string people_path, 
        std::string workers_path, 
        std::string flights_path);

        std::vector<Flight> get_flights();
};



#endif