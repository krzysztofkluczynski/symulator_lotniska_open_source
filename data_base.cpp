#include "data_base.h"

using namespace std;

Data_base::Data_base(
    string people_path, 
    string workers_path,
    string planes_path, 
    string flights_path) :
    people_path(people_path),
    workers_path(workers_path),
    planes_path(planes_path),
    flights_path(flights_path) {
        import_passengers();
        import_planes();
        import_workers();
        import_flights();
    }

void Data_base::import_passengers() {
    fstream file;
    file.open(people_path, ios::in);
    

    file.close();
}