//
// Created by ayabedair on 05/03/25.
//

#ifndef CONTACTS_H
#define CONTACTS_H

#include <string>

enum Groups{Friends, Family, Coworker, Acquaintance};

class Contacts {
    std::string m_firstName;
    std::string m_lastName;
    std::string m_primaryNumber;
    std::string m_secondaryNumber;
    std::string m_email;
    std::string m_address;
    std::string m_company;
    Groups m_group;
public:
    // Contacts(const std::string& firstName, const std::string& lastName, const std::string& primaryNumber,const std::string& company, Groups group, const std::string& secondNumber = "", const std::string& email = "", const std::string& address = "") {
    //     // Required info
    //     m_firstName = firstName;
    //     m_lastName = lastName;
    //     m_primaryNumber = primaryNumber;
    //     m_company = company;
    //     m_group = group;
    //     // Optional info
    //     m_email = email;
    //     m_address = address;
    //     m_secondaryNumber = secondNumber;
    // }

    // Getters
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPrimaryNumber() const;
    const std::string &getCompany() const;
    const std::string &getEmail() const;
    const std::string &getAddress() const;
    const std::string &getSecondaryNumber() const;
    const Groups &getGroup() const;

    // Setters
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setPrimaryNumber(const std::string& primaryNumber);
    void setCompany(const std::string& company);
    void setEmail(const std::string& email);
    void setAddress(const std::string& address);
    void setSecondaryNumber(const std::string& secondNumber);
    void setGroup(Groups group);

};



#endif //CONTACTS_H