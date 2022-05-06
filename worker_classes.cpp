#include "worker_classes.h"

using namespace std;

Worker::Worker(std::string name, std::string surname, std::string pesel, const Price& salary) //domyslna wyplata
: Person(name, surname, pesel), salary(salary) {}


Worker::~Worker() {}

Price Worker::getPrice() const
{
    return salary;
}

void Worker::setPrice(const Price& price)
{
    salary = price;
}


std::ostream &operator<<(std::ostream& out, const Worker& worker)
{
    out << "Worker: " << worker.getSpeciality() << endl << worker.getName() << " " << worker.getSurname() << endl << "PESEL: " << worker.getPesel() << endl;
    out << "Passangers amount per this worker: " << worker.passengersPerWorker();
    return out; 
}


Stewardess::Stewardess(std::string name, std::string surname, std::string pesel, const Price& salary) //domyslna wyplata
: Worker(name, surname, pesel, salary) {}


unsigned int Stewardess::passengersPerWorker() const
{
    return 20;
}
std::string Stewardess::getSpeciality() const
{
    return "stewardess";
}

Pilot::Pilot(std::string name, std::string surname, std::string pesel, const Price& salary)
: Worker(name, surname, pesel, salary) {}


unsigned int Pilot::passengersPerWorker() const
{
    return 100;                      
}
std::string Pilot::getSpeciality() const
{
    return "Pilot";
}


LuggageMan::LuggageMan(std::string name, std::string surname, std::string pesel, const Price& salary) 
: Worker(name, surname, pesel, salary) {}


unsigned int LuggageMan::passengersPerWorker() const
{
    return 50;                      
}
std::string LuggageMan::getSpeciality() const
{
    return "LuggageMan";
}


Other::Other(std::string name, std::string surname, std::string pesel, const Price& salary) 
: Worker(name, surname, pesel, salary) {}


unsigned int Other::passengersPerWorker() const
{
    return 100;                      //<-- tu to chyba damy jak nam bedzie wygodniej w przyslosci, pewnie gdzies tak zeby na kazdy lot byl jeden pracownik inny
}
std::string Other::getSpeciality() const
{
    return "Other";
}
