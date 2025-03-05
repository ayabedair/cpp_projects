//
// Created by ayabedair on 05/03/25.
//

#ifndef FILEIO_H
#define FILEIO_H

#include "Contacts.h"
#include <vector>

void saveContact(Contacts &c);
std::vector<std::string> split(const std::string &str, char delimiter);
std::vector<Contacts> loadContacts(const std::string &filename);
void clearFile();

#endif //FILEIO_H