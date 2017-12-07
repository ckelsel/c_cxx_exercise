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
#include "item10/item10.h"

TEST(EFFECTIVE_CXX, ITEM10) {
    TimeDelta ten(10);
    TimeDelta one(1);

    ten *= one;
    if (ten == TimeDelta(10)) {
        SUCCEED();
    } else {
        FAIL();
    }

    ten /= one;
    if (ten == TimeDelta(10)) {
        SUCCEED();
    } else {
        FAIL();
    }

    ten += one;
    if (ten == TimeDelta(11)) {
        SUCCEED();
    } else {
        FAIL();
    }

    ten -= one;
    if (ten == TimeDelta(10)) {
        SUCCEED();
    } else {
        FAIL();
    }

    TimeDelta tmp = ten;
    if (tmp == TimeDelta(10)) {
        SUCCEED();
    } else {
        FAIL();
    }
}