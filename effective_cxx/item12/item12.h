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

#ifndef __ITEM12_H__
#define __ITEM12_H__
//Item 12: Copy all parts of an object

#include <string>

int GetItem12Reference();
void SetItem12Reference(int value);

class Date {
public:
    Date() : year_(0) {
    }

    Date(const Date &rhs) : year_(rhs.year_) {
    }

    Date& operator=(const Date &rhs) {
        year_ = rhs.year_;
        return *this;
    }
private:
    int year_;
};

class Customer {
public:
    Customer() { }
    Customer(const Customer &rhs);
    Customer& operator=(const Customer &rhs);

private:
    std::string name_;

    // deal with Date manual
    Date date_;
};

class PriorityCustomer : public Customer {
public:
    PriorityCustomer();
    PriorityCustomer(const PriorityCustomer &rhs);
    PriorityCustomer& operator=(const PriorityCustomer &rhs);

private:
    int priority_;
};

#endif // __ITEM12_H__