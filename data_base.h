#ifndef DATA_BASE_H
#define DATA_BASE_H

#include "flight.h"
#include <memory>
#include <list>

class Data_base 
{
    private:
        // std::vector<Other> other;
        // std::vector<LuggageMan> LuggageMan;
        // std::vector<Stewardess> Stewardess;
        // std::vector<Pilot> pilot;

        std::vector<Flight> flights;
        void import_passengers();
        void import_workers();
        void import_planes();

    public: 
        Data_base(std::string people_path, std::string workers_path, std::string planes_path, std::string flights_path);
};



#endif