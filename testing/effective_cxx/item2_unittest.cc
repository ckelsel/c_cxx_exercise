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
#include "item2.h"

TEST(EFFECTIVE_CXX, ITEM2) {
    ASSERT_STREQ(authorName, "xiekm");
    ASSERT_STREQ(authorName2.c_str(), "xiekm");

    ASSERT_EQ(GamePlayer::NumTurns, 5);

    ASSERT_EQ(GamePlayer2::NumTurns2, 10);

    ASSERT_EQ(CostEstimate::FudgeFactor, 1.35);
}