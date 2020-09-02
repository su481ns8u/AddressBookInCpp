#include "addressBook.h"

bool Address_Book::check_present(string first_name, string last_name)
{
    for (Person *person : address_book)
        if (person->get_first_name() == first_name && person->get_last_name() == last_name)
            return true;
    return false;
}

void Address_Book::add_person(Person *person)
{
    if (!check_present(person->get_first_name(), person->get_last_name()))
        address_book.push_back(person);
    else
        cout << "\nPerson already exists !!!";
}

void Address_Book::edit_person(string first_name, string last_name)
{
    if (check_present(first_name, last_name))
    {
        for (Person *person : address_book)
        {
            if (person->get_first_name() == first_name && person->get_last_name() == last_name)
            {
                int edit_choice;
                bool stop_flag = false;
                while (!stop_flag)
                {
                    cout << "\nEnter edit choice\n1. Address"
                         << "\n2. City\n3. State"
                         << "\n4. Zip\n5. Phone Number"
                         << "\n6. Exit Editing\nChoice: ";
                    cin >> edit_choice;
                    switch (edit_choice)
                    {
                    case 1:
                    {
                        string address;
                        cout << "Address: ";
                        cin >> address;
                        person->set_address(address);
                        break;
                    }
                    case 2:
                    {
                        string city;
                        cout << "City: ";
                        cin >> city;
                        person->set_city(city);
                        break;
                    }
                    case 3:
                    {
                        string state;
                        cout << "State: ";
                        cin >> state;
                        person->set_state(state);
                        break;
                    }
                    case 4:
                    {
                        string zip;
                        cout << "Zip: ";
                        cin >> zip;
                        person->set_zip(zip);
                        break;
                    }
                    case 5:
                    {
                        string phone_number;
                        cout << "Phone Number: ";
                        cin >> phone_number;
                        person->set_phone_number(phone_number);
                        break;
                    }
                    case 6:
                        stop_flag = true;
                        break;
                    default:
                        cout << "\nInvalid choice !!!";
                        break;
                    }
                }
            }
            cout << "\nEditing successful !!!";
            break;
        }
    }
    else
    {
        cout << "\nNo such person exists !!!";
    }
}

void Address_Book::delete_person(string first_name, string last_name)
{
    if (check_present(first_name, last_name))
        for (Person *person : address_book)
        {
            if (first_name == person->get_first_name() && last_name == person->get_last_name())
            {
                address_book.remove(person);
                cout << "\nRecord deleted successfully !!!";
                break;
            }
        }
    else
        cout << "\nNo such person exists !!!";
}

void Address_Book::display_records()
{
    if (address_book.size() != 0)
        for (Person *person : address_book)
            cout << person->to_string();
    else
        cout << "\nNo records found!!!";
}

void Address_Book::sort_by_param(int sort_param)
{
    if (address_book.size() != 0)
        switch (sort_param)
        {
        case 1:
            address_book.sort([](Person *lhs, Person *rhs) {
                return lhs->get_first_name() < rhs->get_first_name();
            });
            break;
        case 2:
            address_book.sort([](Person *lhs, Person *rhs) {
                return lhs->get_city() < rhs->get_city();
            });
            break;
        case 3:
            address_book.sort([](Person *lhs, Person *rhs) {
                return lhs->get_state() < rhs->get_state();
            });
            break;
        case 4:
            address_book.sort([](Person *lhs, Person *rhs) {
                return lhs->get_zip() < rhs->get_zip();
            });
            break;
        default:
            cout << "\nInvalid Choice !!!";
            break;
        }
    else
        cout << "\nNo records found to sort!!!";
}

void Address_Book::view_by_city_and_state(string city, string state)
{
    bool view_flag = false;
    for (Person *person : address_book)
        if (person->get_city() == city && person->get_state() == state)
        {
            cout << person->to_string();
            view_flag = true;
        }
    if (!view_flag)
        cout << "\nNo records found !!!";
}

void Address_Book::view_by_city_or_state(string param)
{
    bool view_flag = false;
    for (Person *person : address_book)
        if (person->get_city() == param || person->get_state() == param)
        {
            cout << person->to_string();
            view_flag = true;
        }
    if (!view_flag)
        cout << "\nNo records found !!!";
}