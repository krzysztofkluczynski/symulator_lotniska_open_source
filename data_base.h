#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <fstream>
#include <string>

#include "flight.h"

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

        std::vector<Flight> flights;
        void import_passengers();
        void import_workers();
        void import_planes();
        void import_flights();

    public: 
        Data_base(
        std::string people_path, 
        std::string workers_path,
        std::string planes_path, 
        std::string flights_path);
};



#endif