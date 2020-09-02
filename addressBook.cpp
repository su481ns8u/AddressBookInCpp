#include "addressBook.h"

void Address_Book::add_person(Person *person)
{
    if (!check_present(person->get_first_name(), person->get_last_name()))
        address_book.push_back(person);
    else
        cout << "Person already exists !!!";
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
        cout << "No such person exists !!!";
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
        cout << "No such person exists !!!";
}

void Address_Book::display_records()
{
    for (Person *person : address_book)
        cout << person->to_string();
}

bool Address_Book::check_present(string first_name, string last_name)
{
    for (Person *person : address_book)
        if (person->get_first_name() == first_name && person->get_last_name() == last_name)
            return true;
    return false;
}
