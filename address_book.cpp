#include <cstdlib>
#include "addressBook.h"

Person *Address_Book::check_present(Person *person)
{
    for (Person *temp_person : address_book)
        if (temp_person->get_first_name() == person->get_first_name() && temp_person->get_last_name() == person->get_last_name())
            return temp_person;
    return nullptr;
}

void Address_Book::add_person(Person *person)
{
    address_book.push_back(person);
}

void Address_Book::edit_person(Person *preson, int edit_param, string changed_value)
{
    enum edit_params
    {
        ADDRESS = 1,
        CITY,
        STATE,
        ZIP,
        PHONE
    };
    switch (edit_param)
    {
    case ADDRESS:
        preson->set_address(changed_value);
        break;
    case CITY:
        preson->set_city(changed_value);
        break;
    case STATE:
        preson->set_state(changed_value);
        break;
    case ZIP:
        preson->set_zip(changed_value);
        break;
    case PHONE:
        preson->set_phone_number(changed_value);
        break;
    }
    cout << "\nEditing successful !!!";
}

// void Address_Book::edit_person(string first_name, string last_name)
// {
//     enum edit_params
//     {
//         ADDRESS = 1,
//         CITY,
//         STATE,
//         ZIP,
//         PHONE
//     };
//     if (check_present(new Person(first_name, last_name)))
//     {
//         for (Person *person : address_book)
//         {
//             if (person->get_first_name() == first_name && person->get_last_name() == last_name)
//             {
//                 int edit_choice;
//                 bool stop_flag = false;
//                 while (!stop_flag)
//                 {
//                     cout << "\nEnter edit choice\n1. Address"
//                          << "\n2. City\n3. State"
//                          << "\n4. Zip\n5. Phone Number"
//                          << "\n6. Exit Editing\nChoice: ";
//                     cin >> edit_choice;
//                     switch (edit_choice)
//                     {
//                     case ADDRESS:
//                     {
//                         string address;
//                         cout << "Address: ";
//                         cin >> address;
//                         person->set_address(address);
//                         break;
//                     }
//                     case CITY:
//                     {
//                         string city;
//                         cout << "City: ";
//                         cin >> city;
//                         person->set_city(city);
//                         break;
//                     }
//                     case STATE:
//                     {
//                         string state;
//                         cout << "State: ";
//                         cin >> state;
//                         person->set_state(state);
//                         break;
//                     }
//                     case ZIP:
//                     {
//                         string zip;
//                         cout << "Zip: ";
//                         cin >> zip;
//                         person->set_zip(zip);
//                         break;
//                     }
//                     case PHONE:
//                     {
//                         string phone_number;
//                         cout << "Phone Number: ";
//                         cin >> phone_number;
//                         person->set_phone_number(phone_number);
//                         break;
//                     }
//                     case 6:
//                         stop_flag = true;
//                         break;
//                     default:
//                         cout << "\nInvalid choice !!!";
//                         break;
//                     }
//                 }
//                 cout << "\nEditing successful !!!";
//                 break;
//             }
//         }
//     }
//     else
//     {
//         cout << "\nNo such person exists !!!";
//     }
// }

void Address_Book::delete_person(string first_name, string last_name)
{
    if (check_present(new Person(first_name, last_name)))
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
    enum sort_params
    {
        NAME = 1,
        CITY,
        STATE,
        ZIP
    };
    if (address_book.size() != 0)
        switch (sort_param)
        {
        case NAME:
            address_book.sort([](Person *lhs, Person *rhs) {
                return lhs->get_first_name() < rhs->get_first_name();
            });
            break;
        case CITY:
            address_book.sort([](Person *lhs, Person *rhs) {
                return lhs->get_city() < rhs->get_city();
            });
            break;
        case STATE:
            address_book.sort([](Person *lhs, Person *rhs) {
                return lhs->get_state() < rhs->get_state();
            });
            break;
        case ZIP:
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