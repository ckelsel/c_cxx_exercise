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
#include "dynamic_planning/poj1163.h"


TEST(ALGORITHM, POJ1163) {
    ReadData("poj1163.in");

    //MaxSum(1,1);
    int sum = MaxSum_2(1, 1);
    EXPECT_EQ(30, sum);

    sum = MaxSum_3(1, 1);
    EXPECT_EQ(30, sum);
}
