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
#include "item3_1_10/item3_1_10.h"

TEST(EFFECTIVE_MODERN_CXX, ITEM3_1_10) {
    std::vector<int> v1 = {1, 2, 3};
    func3(v1);
    ASSERT_EQ(v1[0], -1);
    ASSERT_EQ(v1[1], -2);
    ASSERT_EQ(v1[2], -3);

    std::vector<double> v2 = {0.1};
    func4(v2);
    ASSERT_GT(v2[0], 0.09);
    ASSERT_LE(v2[0], 0.11);

    func5(v2, 0.01);
    ASSERT_GT(v2[0], 0.09);
    ASSERT_LE(v2[0], 0.11);
}

TEST(EFFECTIVE_MODERN_CXX, ITEM3_1_10_func) {
    int x = 0;
    int y = 11;
    auto func = [x, &y] {
        ++y;
    };

    func();
    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 12);
    
    func();
    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 13);
}