#include <iostream>
#include <list>

using namespace std;

class Person
{
    string first_name;
    string last_name;
    string address;
    string city;
    string state;
    string zip;
    string phone_number;

public:
    Person(string first_name, string last_name,
           string address, string city,
           string state, string zip,
           string phone_number);
    
    string get_first_name();
    string get_last_name();

    string get_address();
    string get_city();
    string get_state();
    string get_zip();
    string get_phone_number();
    
    void set_address(string address);
    void set_city(string city);
    void set_state(string state);
    void set_zip(string zip);
    void set_phone_number(string phone_number);

    string to_string();
};

class Address_Book
{
    list<Person *> address_book;

public:
    void add_person(Person *person);
    void edit_person(string first_name, string last_name);
    void delete_person(string first_name, string last_name);
    void display_records();
    bool check_present(string first_name, string last_name);
    void sort_by_name();
};