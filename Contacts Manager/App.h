//
// Created by ayabedair on 05/03/25.
//

#ifndef APP_H
#define APP_H
#include <vector>
#include "Contacts.h"

void welcomePage();
const int getChoice();

Contacts createContact();
void sortByFistName(std::vector<Contacts> &contacts);
void sortByLastName(std::vector<Contacts> &contacts);
std::string fisrtNameUsingPrimaryNumber(const std::string &primaryNumber);
void displayCompanyContacts(const std::string &companyName);
void displayGroupContacts(const std::string &groupName);
void searchByName(const std::string &name);
int displayCount(const std::string &company);
void clearContacts();

void displayContacts();
#endif //APP_H