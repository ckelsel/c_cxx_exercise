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
#include "item12/item12.h"

TEST(EFFECTIVE_CXX, ITEM12) {
    Customer customer1;
    Customer customer2 = customer1;

    ASSERT_EQ(GetItem12Reference(), 1);

    Customer customer3(customer1);
    ASSERT_EQ(GetItem12Reference(), 2);

    SetItem12Reference(0);
}

TEST(EFFECTIVE_CXX, ITEM12_2) {
    PriorityCustomer customer1;
    PriorityCustomer customer2 = customer1;

    ASSERT_EQ(GetItem12Reference(), 2);

    PriorityCustomer customer3(customer1);
    ASSERT_EQ(GetItem12Reference(), 4);

    SetItem12Reference(0);
}