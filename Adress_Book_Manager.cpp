#include "addressBook.h"

class Address_Book_Manager
{
    Address_Book address_book;

public:
    void add_person()
    {
        system("clear");
        string first_name, last_name, address, city, state, zip, phone_number;
        cout << "Enter Information to add\nEnter First Name: ";
        cin >> first_name;
        cout << "Enter Last Name: ";
        Person person(first_name, last_name);
        if (!address_book.check_present(&person))
        {
            cin >> last_name;
            cout << "Enter Address: ";
            cin >> address;
            cout << "Enter City: ";
            cin >> city;
            cout << "Enter State: ";
            cin >> state;
            cout << "Enter Zip: ";
            cin >> zip;
            cout << "Enter Phone Number: ";
            cin >> phone_number;
            person.set_address_and_phone(address, phone_number);
            person.set_location(city, state, zip);
            address_book.add_person(&person);
        }
        else
        {
            cout << "Person already exists !!!";
        }
    }
};