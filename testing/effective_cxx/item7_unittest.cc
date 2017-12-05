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
#include "item7/item7.h"

TEST(EFFECTIVE_CXX, ITEM7) {
    TimeKeeperNonVirtual *timeKeeper;

    timeKeeper = getTimeKeeper();

    ASSERT_EQ(TimeKeeperReference, 2);
    delete timeKeeper;

    // ERROR! TimeKeeperReference should be 0
    ASSERT_EQ(TimeKeeperReference, 1);
}

TEST(EFFECTIVE_CXX, ITEM7_2) {
    ResetTimeKeeperReference();

    TimeKeeperVirtual *timeKeeper;

    timeKeeper = getTimeKeeper2();

    ASSERT_EQ(TimeKeeperReference, 2);
    delete timeKeeper;

    ASSERT_EQ(TimeKeeperReference, 0);
}