//
// Created by ayabedair on 05/03/25.
//

#include "FileIO.h"
#include <fstream>

#include "Contacts.h"
#include <iostream>
#include <vector>
#include <sstream>

void saveContact(Contacts &contact) {
    std::ofstream out;
    out.open("Contacts.txt", std::ios::app);
    out << "First name: " << contact.getFirstName() << ", Last Name: " << contact.getLastName() <<
            ", Primary Number: " << contact.getPrimaryNumber() << ", Secondary Number: " << contact.getSecondaryNumber() <<
                ", Email: " << contact.getEmail() << ", Address: " << contact.getAddress() << ", Company: " << contact.getCompany() <<
                    ", Group: " << contact.getGroup() << std::endl;
    out.close();
}

std::vector<std::string> split(const std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to load contacts from a file
std::vector<Contacts> loadContacts(const std::string &filename) {
    std::vector<Contacts> contacts;
    std::ifstream in(filename);

    if (!in) {
        std::cerr << "Error: Unable to open file " << filename << " for reading.\n";
        return contacts;
    }

    std::string line;
    while (std::getline(in, line)) {
        size_t pos = line.find("First name: ");
        if (pos == std::string::npos) continue;
        line = line.substr(pos);

        std::vector<std::string> pairs = split(line, ',');
        if (pairs.size() != 8) continue;

        std::string firstName = pairs[0].substr(pairs[0].find(": ") + 2);
        std::string lastName = pairs[1].substr(pairs[1].find(": ") + 2);
        std::string primaryNumber = pairs[2].substr(pairs[2].find(": ") + 2);
        std::string secondaryNumber = pairs[3].substr(pairs[3].find(": ") + 2);
        std::string email = pairs[4].substr(pairs[4].find(": ") + 2);
        std::string address = pairs[5].substr(pairs[5].find(": ") + 2);
        std::string company = pairs[6].substr(pairs[6].find(": ") + 2);
        int group = std::stoi(pairs[7].substr(pairs[7].find(": ") + 2));

        Contacts c;
        c.setFirstName(firstName);
        c.setLastName(lastName);
        c.setPrimaryNumber(primaryNumber);
        c.setSecondaryNumber(secondaryNumber);
        c.setEmail(email);
        c.setAddress(address);
        c.setCompany(company);
        c.setGroup(static_cast<Groups>(group));

        contacts.push_back(c);
    }

    in.close();
    return contacts;
}

void clearFile() {
    std::ofstream ofs("Contacts.txt", std::ios::trunc);
    ofs.close();
}