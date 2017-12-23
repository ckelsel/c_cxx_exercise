/* Copyright 2017 kunming.xie
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __ITEM4_H__
#define __ITEM4_H__
//Item 4: Make sure that objects are initialized before they're used

#include <string>
#include <list>
#include <iostream>

class PhoneNumber {
public:
    PhoneNumber() : number_("") {
        std::cout << "ctor: PhoneNumber::PhoneNumber()" << std::endl;
    }

    PhoneNumber(const std::string &number) : number_ (number) {
        std::cout << "ctor: PhoneNumber::PhoneNumber(const std::string &number)" << std::endl;
    }

    PhoneNumber(const PhoneNumber &phoneNumber) {
        number_ = phoneNumber.number_;
        std::cout << "copy ctor: PhoneNumber::PhoneNumber(const PhoneNumber &phoneNumber)" << std::endl;
    }

    PhoneNumber operator=(const PhoneNumber &phoneNumber) {
        std::cout << "Enter = ctor: PhoneNumber operator=(const PhoneNumber &phoneNumber)" << std::endl;
        PhoneNumber thePhoneNumber;
        thePhoneNumber.number_ = phoneNumber.number_;
        std::cout << "Leave = ctor: PhoneNumber operator=(const PhoneNumber &phoneNumber)" << std::endl;

        return thePhoneNumber;
    }

private:    
    std::string number_;
};

// ctor
// = ctor
class AddressBookEntry {
public:
    AddressBookEntry (const std::string &name,  const std::string address,
                      const PhoneNumber &phones) {
                          name_ = name;
                          address_ = address;
                          // call PhoneNumber()
                          // call operator=
                          phones_ = phones;
                          numTimesConsulted = 0;
                      }

private:
    std::string name_;
    std::string address_;
    PhoneNumber phones_;
    int numTimesConsulted;
};



// more efficient:
// copy ctor
class AddressBookEntry2 {
public:
    AddressBookEntry2 (const std::string &name,  const std::string address,
                      const PhoneNumber &phones)
                      : name_ (name)
                      , address_ (address)
                      , phones_ (phones)
                      , numTimesConsulted (0) {
                      }

private:
    std::string name_;
    std::string address_;
    PhoneNumber phones_;
    int numTimesConsulted;
};

#endif // __ITEM4_H__