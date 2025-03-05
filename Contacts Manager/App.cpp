//
// Created by ayabedair on 05/03/25.
//

#include "App.h"

#include <algorithm>
#include <iostream>
#include <vector>

#include "Contacts.h"
#include "FileIO.h"
extern std::vector<Contacts> contacts;

const int getChoice() {
    std::cout << "Enter the number of the feature: ";
    int choice;
    std::cin >> choice;
    if (choice > 8 || choice < 1) {
        std::cout << "Invalid option. Please enter a number between 1 and 8.\n\n";
        return -1;
    }
    return choice;
}

void welcomePage() {
    std::cout << "1. Create new contact." << std::endl;
    std::cout << "2. Display all contacts sorted by first name." << std::endl;
    std::cout << "3. Display all contacts sorted by last name." << std::endl;
    std::cout << "4. Display only first name using primary number." << std::endl;
    std::cout << "5. Display contacts based on company name." << std::endl;
    std::cout << "6. Display contacts based on group type." << std::endl;
    std::cout << "7. Search by first or last name." << std::endl;
    std::cout << "8. Clear all contacts." << std::endl;
    std::cout << std::endl;
}

Contacts createContact() {
    Contacts contact;

    std::cout << "First name: ";
    std::string fisrtName;
    std::cin >> fisrtName;
    contact.setFirstName(fisrtName);

    std::cout << "Last name: ";
    std::string lastName;
    std::cin >> lastName;
    contact.setLastName(lastName);

    bool validNumber = false;
    while (!validNumber) {
        std::cout << "Primary number: ";
        std::string primaryNumber;
        std::cin >> primaryNumber;
        if (primaryNumber.length() == 11) {
            contact.setPrimaryNumber(primaryNumber);
            validNumber = true;
        } else {
            std::cout << "Invalid input. Please enter a real number.\n\n";
        }
    }

    std::cout << "Secondary number(Optional): ";
    std::string secondaryNumber;
    std::cin >> secondaryNumber;
    contact.setSecondaryNumber(secondaryNumber);

    std::cout << "Email(Optional): ";
    std::string email;
    std::cin >> email;
    contact.setEmail(email);

    std::cout << "Address(Optional): ";
    std::string address;
    std::cin >> address;
    contact.setAddress(address);

    std::cout << "Company name: ";
    std::string company;
    std::cin >> company;
    contact.setCompany(company);

    bool validGroup = false;
    while (!validGroup) {
        std::cout << "Group(Friends, Family, Coworker, Acquaintance): ";
        std::string group;
        std::cin >> group;
        if (group == "Friends" || group == "friends") {contact.setGroup(Friends); validGroup = true;}
        else if (group == "Family" || group == "family") {contact.setGroup(Family); validGroup = true;}
        else if (group == "Coworker" || group == "coworker") {contact.setGroup(Coworker); validGroup = true;}
        else if (group == "Acquaintance" || group == "acquaintance") {contact.setGroup(Acquaintance); validGroup = true;}
        else {
            std::cout << "Invalid input. Please enter a valid group.\n\n";
        }
    }

    return std::move(contact);
}

void sortByFistName(std::vector<Contacts> &contacts) {
    sort(contacts.begin(), contacts.end(), [](const Contacts &a, const Contacts &b) {
        return a.getFirstName() < b.getFirstName();
    });
}

void sortByLastName(std::vector<Contacts> &contacts) {
    sort(contacts.begin(), contacts.end(), [](const Contacts &a, const Contacts &b) {
        return a.getLastName() < b.getLastName();
    });
}

std::string fisrtNameUsingPrimaryNumber(const std::string &primaryNumber) {
    auto it = find_if(contacts.begin(), contacts.end(), [&](const Contacts &contact) {
        return contact.getPrimaryNumber() == primaryNumber;
    });
    if (it == contacts.end()) {
        return "Number not found.\n";
    } else {
        return it->getFirstName();
    }
}

void displayCompanyContacts(const std::string &companyName) {
    int cnt = 0;
    std::for_each(contacts.begin(), contacts.end(), [&](const Contacts &contact) {
        if (contact.getCompany() == companyName) {
            cnt++;
            std::cout << "First name: " << contact.getFirstName() << ", Last Name: " << contact.getLastName()
                      << ", Primary Number: " << contact.getPrimaryNumber() << ", Secondary Number: " << contact.getSecondaryNumber()
                      << ", Email: " << contact.getEmail() << ", Address: " << contact.getAddress()
                      << ", Company: " << contact.getCompany() << ", Group: " << contact.getGroup() << std::endl;
        }
    });
    if (!cnt) {
        std::cout << "No contacts found.\n\n";
    } else {
        std::cout << std::endl;
    }
}

void displayGroupContacts(const std::string &groupName) {
    int groupNumber = -1;
    if (groupName == "Friends" || groupName == "friends") {groupNumber = 0;}
    else if (groupName == "Family" || groupName == "family") {groupNumber = 1;}
    else if (groupName == "Coworker" || groupName == "coworker") {groupNumber = 2;}
    else if (groupName == "Acquaintance" || groupName == "acquaintance") {groupNumber = 3;}

    int cnt = 0;
    std::for_each(contacts.begin(), contacts.end(), [&](const Contacts &contact) {
        if (contact.getGroup() == groupNumber) {
            cnt++;
            std::cout << "First name: " << contact.getFirstName() << ", Last Name: " << contact.getLastName()
                      << ", Primary Number: " << contact.getPrimaryNumber() << ", Secondary Number: " << contact.getSecondaryNumber()
                      << ", Email: " << contact.getEmail() << ", Address: " << contact.getAddress()
                      << ", Company: " << contact.getCompany() << ", Group: " << contact.getGroup() << std::endl;
        }
    });
    if (!cnt) {
        std::cout << "No contacts found.\n\n";
    } else {
        std::cout << std::endl;
    }
}

void searchByName(const std::string &name) {
    int cnt = 0;
    std::for_each(contacts.begin(), contacts.end(), [&](const Contacts &contact) {
        if (contact.getFirstName() == name || contact.getLastName() == name) {
            cnt++;
            std::cout << "First name: " << contact.getFirstName() << ", Last Name: " << contact.getLastName()
                      << ", Primary Number: " << contact.getPrimaryNumber() << ", Secondary Number: " << contact.getSecondaryNumber()
                      << ", Email: " << contact.getEmail() << ", Address: " << contact.getAddress()
                      << ", Company: " << contact.getCompany() << ", Group: " << contact.getGroup() << std::endl;
        }
    });

    if (!cnt) {
        std::cout << "No contacts found.\n\n";
    } else {
        std::cout << std::endl;
    }
}

// int displayCount(const std::string &company) {
//     int cnt = std::count_if(contacts.begin(), contacts.end(), [&](const Contacts &contact) {
//         return contact.getCompany() == company;
//     });
//
//     return cnt;
// }

void clearContacts() {
    contacts.clear();
    clearFile();
}

void displayContacts() {
    for (const Contacts &contact : contacts) {
        std::cout << "First name: " << contact.getFirstName() << ", Last Name: " << contact.getLastName() <<
            ", Primary Number: " << contact.getPrimaryNumber() << ", Secondary Number: " << contact.getSecondaryNumber() <<
                ", Email: " << contact.getEmail() << ", Address: " << contact.getAddress() << ", Company: " << contact.getCompany() <<
                    ", Group: " << contact.getGroup() << std::endl;
    }
    std::cout << std::endl;
}