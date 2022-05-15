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

    string name, surname, pesel;

    while (file >> name) {
        file >> surname;
        file >> pesel;
        Person peop(name, surname, pesel);
        people.push_back(peop);
    }

    // string name, surname, pesel, departure, arrival, day, month, year, clas, flight_num;
    // while (file >> name) {
    //     file >> surname;
    //     file >> pesel;
    //     file >> departure;
    //     file >> arrival;
    //     file >> day;
    //     file >> month;
    //     file >> year;
    //     file >> clas;
    //     file >> flight_num;
    //     Date date(stoi(day), stoi(month), stoi(year));
    //     City arri_city(arrival);
    //     City dep_city(departure);
    //     //tutaj moze trzeba bedzie przydzielic pasazera do lotu
    //     if (clas=="1") {
    //         FirstClassTicket ticket(dep_city, arri_city, date, stoul(flight_num));
    //         FirstClass passenger(name, surname, pesel, ticket);
    //         first.push_back(passenger);
    //     }
    //     else if (clas=="2") {
    //         SecondClassTicket ticket(dep_city, arri_city, date, stoul(flight_num));
    //         SecondClass passenger(name, surname, pesel, ticket);
    //         second.push_back(passenger);
    //     }
    //     else {
    //         throw InvalidClass();
    //     }
    // }
    file.close();
}

void Data_base::import_workers() {
    fstream file;
    file.open(workers_path, ios::in);
    if (!file.good()) throw "invalid file";
    string name, surname, pesel, type;
    unsigned int flight_num;
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

unique_ptr<Planes> Data_base::create_plane(std::string p_type, std::string p_name){
        if (p_type=="0") {
            std::unique_ptr<Light_plane> plane = std::make_unique<Light_plane>(p_name);
            return plane;
        }
        else if (p_type=="1") {
            std::unique_ptr<Small_plane> plane = std::make_unique<Small_plane>(p_name);
            return plane;
        }
        else if (p_type=="2") {
            std::unique_ptr<Medium_plane> plane = std::make_unique<Medium_plane>(p_name);
            return plane;
        }
        else if (p_type=="3") {
            std::unique_ptr<Big_plane> plane = std::make_unique<Big_plane>(p_name);
                return plane;
        }
        else {
            throw InvalidPlaneType();
        }
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
        // if (p_type=="0") {
        //     Light_plane plane(p_name);
        // }
        // else if (p_type=="1") {
        //     Small_plane plane(p_name);
        // }
        // else if (p_type=="2") {
        //     Medium_plane plane(p_name);
        // }
        // else if (p_type=="3") {
        //     Big_plane plane(p_name);
        // }
        // else {
        //     throw InvalidPlaneType();
        // }
        //Planes& plane = *(create_plane(p_type, p_name)); 
        // City dep(departure);
        // City ari(arrival);
        // Date date(stoi(day), stoi(month), stoi(year));
        Flight flight(stoul(id), Date(stoi(day), stoi(month), stoi(year)), City(departure), City(arrival), *(create_plane(p_type, p_name)));

        for (auto stew : stewardess) {
            if (flight.get_id() == stew.get_flight_num()) {
                flight.add_stewardess(stew);
            }
        }

        for (auto pil : pilot) {
            if (flight.get_id() == pil.get_flight_num()) {
                flight.add_pilot(pil);
            }
        }

        for (auto lugg : luggage_man) {
            if (flight.get_id() == lugg.get_flight_num()) {
                flight.add_luggage_man(lugg);
            }
        }

        for (auto oth : other) {
            if (flight.get_id() == oth.get_flight_num()) {
                flight.add_other(oth);
            }
        }

        for (auto firs : first) {
            if (flight.get_id() == firs.getTicket().getNumber()) {
                flight.add_first_class(firs);
            }
        }

        for (auto sec : second) {
            if (flight.get_id() == sec.getTicket().getNumber()) {
                flight.add_second_class(sec);
            }
        }

        flights.push_back(flight);

    }
    file.close();
}

void Data_base::assignPassengers()
{
    for (auto flight : flights)
    {
        random_device rd1;
        mt19937 mt1(rd1());
        uniform_real_distribution<> dist1(2, flight.get_plane().get_sitting_places()); //losowy numer od 2 do ilosci miejsc siedzacych
        int random = dist1(mt1);
        for(int i = 0; i < random; i++)
        {
            random_device rd2;      //losowanie klasy (1/2) dla pasazera
            mt19937 mt2(rd2());
            uniform_real_distribution<> dist2(1, 2); //losowy numer od 2 do ilosci miejsc siedzacych
            int random2 = dist2(mt2);            

            Person random_person = people[rand() % people.size()];

            for( std::vector<Person>::iterator iter = people.begin(); iter != people.end(); ++iter ) //usuwanie czlowieka o danym peselu, moze mozna latwiej
            {
                if( (*iter).getPesel() == random_person.getPesel())
                {
                    people.erase(iter);
                    break;
                }
}

            if (random2 == 1)
            {
                FirstClassTicket ticket(flight.get_departure(), flight.get_arrival(), flight.get_date(), flight.get_id());
                FirstClass passenger(random_person.getName(), random_person.getSurname(), random_person.getPesel(), ticket);

                flight.add_first_class(passenger);

                std::shared_ptr<FirstClass> passager = std::make_shared<FirstClass>(random_person.getName(), random_person.getSurname(), random_person.getPesel(), ticket);
                passengers.push_back(std::move(passager));
            }
            else if (random2 == 1)
            {
                SecondClassTicket ticket(flight.get_departure(), flight.get_arrival(), flight.get_date(), flight.get_id());
                SecondClass passenger(random_person.getName(), random_person.getSurname(), random_person.getPesel(), ticket);

                flight.add_second_class(passenger);

                std::shared_ptr<SecondClass> passager = std::make_shared<SecondClass>(random_person.getName(), random_person.getSurname(), random_person.getPesel(), ticket);
                passengers.push_back(std::move(passager));
            }
              
        }

    }
}
