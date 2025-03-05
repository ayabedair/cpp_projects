#include <iostream>
#include <vector>

#include "Contacts.h"
#include "App.h"
#include "FileIO.h"

std::vector<Contacts> contacts;

int main() {
    // Welcome message
    std::cout << "🌟 Welcome to your contacts! 🌟" << std::endl << std::endl;
    std::cout << "Choose one of the following features:" << std::endl;

    contacts = loadContacts("Contacts.txt");
    bool running = true;
    while (running) {
        int choice = -1;
        while (choice == -1) {
            welcomePage();
            choice = getChoice();
        }
        switch (choice) {
            case 1: {
                Contacts c = createContact();
                contacts.push_back(c);
                saveContact(c);
                break;
            }
            case 2: {
                sortByFistName(contacts);
                displayContacts();
                break;
            }
            case 3: {
                sortByLastName(contacts);
                displayContacts();
                break;
            }
            case 4: {
                std::cout << "Primary number: ";
                std::string primaryNumber;
                std::cin >> primaryNumber;
                std::string ret = fisrtNameUsingPrimaryNumber(primaryNumber);
                std::cout << ret << std::endl;
                break;
            }
            case 5: {
                std::cout << "Company name: ";
                std::string companyName;
                std::cin >> companyName;
                displayCompanyContacts(companyName);
                break;
            }
            case 6: {
                std::cout << "Group name: ";
                std::string groupName;
                std::cin >> groupName;
                displayGroupContacts(groupName);
                break;
            }
            case 7: {
                std::cout << "Name: ";
                std::string name;
                std::cin >> name;
                searchByName(name);
                break;
            }
            case 8: {
                std::cout << "Are you sure you want to clear ALL contacts?(yes|no) ";
                std::string answer;
                std::cin >> answer;
                if (answer == "yes") {
                    clearContacts();
                }
                break;
            }
            default:
                break;
        }
        std::cout << "Exit?(y|n) ";
        char response;
        std::cin >> response;
        if (response == 'y') {
            running = false;
            std::cout << "Exiting..." << std::endl;
        }
    }

    return 0;
}