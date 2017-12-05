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

#include "gtest/gtest.h"
#include "item4/item4.h"

TEST(EFFECTIVE_CXX, ITEM4) {
    PhoneNumber phoneNumber("12345678");

    std::cout << "before AddressBookEntry addressBookEntry()" << std::endl;

    AddressBookEntry addressBookEntry("name", "address", phoneNumber);
}

TEST(EFFECTIVE_CXX, ITEM4_2) {
    PhoneNumber phoneNumber("12345678");

    std::cout << "before AddressBookEntry2 addressBookEntry2()" << std::endl;

    AddressBookEntry2 addressBookEntry2("name", "address", phoneNumber);
}