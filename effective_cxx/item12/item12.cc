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
#include "item12.h"

static int item12_reference = 0;

int GetItem12Reference() {
    return item12_reference;
}

void SetItem12Reference(int value) {
    item12_reference = value;
}

Customer::Customer(const Customer &rhs)
    : name_(rhs.name_) 
    , date_(rhs.date_) {
    item12_reference++;
}

Customer& Customer::operator=(const Customer &rhs) {
    name_ = rhs.name_;
    date_ = rhs.date_;

    item12_reference++;
    return *this;
}

PriorityCustomer::PriorityCustomer()
    : Customer()
    , priority_(0) {
}

PriorityCustomer::PriorityCustomer(const PriorityCustomer &rhs)
    : Customer(rhs)
    , priority_(rhs.priority_) {
    item12_reference++;
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer &rhs) {
    Customer::operator=(rhs); 
    priority_ = rhs.priority_;

    item12_reference++;

    return *this;
}