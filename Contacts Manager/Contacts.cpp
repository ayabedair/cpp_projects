//
// Created by ayabedair on 05/03/25.
//

#include "Contacts.h"

// Implementation of getters
const std::string &Contacts::getFirstName() const {
    return m_firstName;
}

const std::string &Contacts::getLastName() const {
    return m_lastName;
}

const std::string &Contacts::getPrimaryNumber() const {
    return m_primaryNumber;
}

const std::string &Contacts::getCompany() const {
    return m_company;
}

const std::string &Contacts::getEmail() const {
    return m_email;
}

const std::string &Contacts::getAddress() const {
    return m_address;
}

const std::string &Contacts::getSecondaryNumber() const {
    return m_secondaryNumber;
}

const Groups &Contacts::getGroup() const {
    return m_group;
}

//Implementation of setters
void Contacts::setFirstName(const std::string& firstName) {
    m_firstName = firstName;
}

void Contacts::setLastName(const std::string& lastName) {
    m_lastName = lastName;
}

void Contacts::setPrimaryNumber(const std::string& primaryNumber) {
    m_primaryNumber = primaryNumber;
}

void Contacts::setCompany(const std::string& company) {
    m_company = company;
}

void Contacts::setEmail(const std::string& email) {
    m_email = email;
}

void Contacts::setAddress(const std::string& address) {
    m_address = address;
}

void Contacts::setSecondaryNumber(const std::string& secondNumber) {
    m_secondaryNumber = secondNumber;
}

void Contacts::setGroup(Groups group) {
    m_group = group;
}