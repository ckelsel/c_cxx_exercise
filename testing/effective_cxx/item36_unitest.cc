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
#include "item36/item36.h"

#include <memory>

TEST(EFFECTIVE_CXX, ITEM36) {
    DerivedNoRedefine nodefine;

    Base36 *base = &nodefine;
    base->non_virtual_function();
    ASSERT_EQ(base->getX(), 1);

    DerivedNoRedefine *derived = &nodefine;
    derived->non_virtual_function();
    ASSERT_EQ(derived->getX(), 1);
}

// The reason for this two-faced behavior is that non-virtual functions like Base::non_virtual_function and 
// DerivedRedefine::non_virtual_function are statically bound
// (see Item 37). That means that because base is declared to be of type pointer-to-Base, non-virtual functions invoked
// through base will always be those defined for class Base, even if base points to an object of a class derived from Base,
// as it does in this example.
TEST(EFFECTIVE_CXX, ITEM36_2) {
    DerivedRedefine redefine;

    Base36 *base = &redefine;
    base->non_virtual_function();
    ASSERT_EQ(base->getX(), 1);

    DerivedRedefine *derived = &redefine;
    derived->non_virtual_function();
    ASSERT_EQ(derived->getX(), 2);
}