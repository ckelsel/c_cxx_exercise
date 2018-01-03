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

#include <functional>
#include <map>

TEST(DISPATCHER_TABLE, test) {
    std::map<const char, std::function<int(int, int)>> math_table {
        {'+', [](int a, int b) { return a + b; }},
        {'-', [](int a, int b) { return a - b; }},
    };

    ASSERT_EQ(2, math_table['+'](1, 1));
    ASSERT_EQ(0, math_table['-'](1, 1));
}