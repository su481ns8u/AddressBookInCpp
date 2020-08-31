#include <iostream>
#include <vector>

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

    string get_first_name()
    {
        return first_name;
    }

    string get_last_name()
    {
        return last_name;
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

    friend void edit_with_option(Person *person, int edit_choice, string changed_value);
};

class Address_Book
{
    vector<Person *> address_book;

public:
    void add_person(Person *person)
    {
        address_book.push_back(person);
    }

    void edit_person(string first_name, string last_name)
    {
        bool edit_flag = false;
        for (Person *person : address_book)
        {
            if (first_name == person->get_first_name() && last_name == person->get_last_name())
            {
                edit_with_option(person, 1, "Nagar");
                edit_flag = true;
                break;
            }
        }
        if (!edit_flag)
            cout << "\nNo such person exists !!!";
    }

    void display_records()
    {
        for (Person *person : address_book)
            cout << person->to_string();
    }
};

void edit_with_option(Person *person, int edit_choice, string changed_value)
{
    switch (edit_choice)
    {
    case 1:
        person->address = changed_value;
        break;
    case 2:
        person->city = changed_value;
        break;
    case 3:
        person->state = changed_value;
        break;
    case 4:
        person->zip = changed_value;
        break;
    case 5:
        person->phone_number = changed_value;
        break;
    default:
        break;
    }
    cout << "\nEditing successful !!!";
}

int main(int argc, char const *argv[])
{
    Person person1("Sudhanshu", "Ghinmine", "Keshava", "Selu", "Maha", "431503", "8551973494");
    Person person2("Shashank", "Joshi", "Keshava", "Murtizapur", "Maha", "431225", "9822917991");
    Address_Book address_book;

    cout << "Welcone to address book\n";

    address_book.add_person(&person1);
    address_book.add_person(&person2);

    address_book.display_records();
    address_book.edit_person("Sudhanshu", "Ghinmine");

    address_book.display_records();

    address_book.edit_person("Sha", "Ghinm");

    return 0;
}
