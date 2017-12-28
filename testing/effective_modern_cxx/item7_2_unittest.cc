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
#include "item7_2/item7_2.h"

#include <array>
#include <string>

TEST(EFFECTIVE_MODERN_CXX, ITEM7_2) {
    std::array<int, 3> array3 = {};
    std::for_each(array3.cbegin(), array3.cend(), [](const int v) {
        ASSERT_EQ(v, 0); });
    ASSERT_EQ(array3.size(), 3);


    std::array<int, 5> array5 = {1, 2, 3, 4, 5};
    // ERROR! size() of array is different
    //array3.swap(array5);

    // C2679
    //array3 = std::move(array5);


    std::array<int, 3> array3_2 = {1, 2, 3};
    array3.swap(array3_2);
    std::for_each(array3.cbegin(), array3.cend(), [](const int v) {
        static int i = 0; ASSERT_EQ(v, ++i); });


    std::array<std::string, 3> str3 = {"a", "b", "c"};
    std::array<std::string, 3> STR3 = {"A", "B", "C"};
    str3 = std::move(STR3);
    //str3.swap(STR3);
    ASSERT_STREQ(str3[0].c_str(), "A");
    ASSERT_STREQ(str3[1].c_str(), "B");
    ASSERT_STREQ(str3[2].c_str(), "C");
}