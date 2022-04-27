#ifndef PLANES_H
#define PLANES_H
#include <string>
#include <iostream>

class Planes {
    protected:
        std::string plane_name;
        unsigned int sitting_places; //wszystkie miejsca siedzace

    public:
        Planes(std::string plane_name, int sitting_places);
        void print() const;
        virtual ~Planes();
        virtual double calculate_price(int taken_seats)=0;

        std::string get_plane_name();
        unsigned int get_sitting_places();
        
        void set_plane_name(std::string);
        void set_sitting_places(unsigned int);
};

class Light_plane : public Planes {
    protected:
        float price_multiplier;
    public:
        Light_plane(std::string plane_name, int sitting_places=30, float price_multiplier=1.02);
        virtual double calculate_price(int taken_seats);// do zdefiniowania
        void print() const;

        float get_price_multiplier();
        void set_price_multiplier(float);
};

class Small_plane : public Planes {
    protected:
        float price_multiplier;
    public:
        Small_plane(std::string plane_name, int sitting_places=70, float price_multiplier=1.018);
        virtual double calculate_price(int taken_seats);
        void print() const;

        float get_price_multiplier();
        void set_price_multiplier(float);
};

class Medium_plane : public Planes {
    protected:
        float price_multiplier;
    public:
        Medium_plane(std::string plane_name, int sitting_places=120, float price_multiplier=1.013);
        virtual double calculate_price(int taken_seats);
        void print() const;

        float get_price_multiplier();
        void set_price_multiplier(float);
};

class Big_plane : public Planes {
    protected:
        float price_multiplier;
    public:
        Big_plane(std::string plane_name, int sitting_places=200, float price_multiplier=1.01);
        virtual double calculate_price(int taken_seats);
        void print() const;

        float get_price_multiplier();
        void set_price_multiplier(float);
};


#endif