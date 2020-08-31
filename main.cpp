#include <iostream>

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
           string state, string zip, string phone_number)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->phone_number = phone_number;
    }

    string to_string()
    {
        return "\nFirst Name: " + this->first_name +
               "\tLast Name: " + this->last_name +
               "\nAddress: " + this->address +
               "\nCity: " + this->city +
               "\tState: " + this->state +
               "\tZip: " + this->zip +
               "\nPhone number: " + this->phone_number + "\n";
    }
};

int main(int argc, char const *argv[])
{
    Person person1("Sudhanshu", "Ghinmine", "Keshava", "Selu", "Maha", "431503", "8551973494");
    cout << "Welcone to address book";
    cout << person1.to_string();
    return 0;
}
