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
#include "item3/item3.h"

TEST(EFFECTIVE_CXX, ITEM3) {
    item3_test();
}

TEST(EFFECTIVE_CXX, ITEM3_2) {
    TextBlock tb("hello");
    ASSERT_EQ(tb[0], 'h');

    // modify a copy of tb[0]
    tb[0] = 'H';

    const TextBlock ctb("const hello");
    ASSERT_EQ(ctb[0], 'c');
    // error
    // ctb[0] = 'C';
}

TEST(EFFECTIVE_CXX, ITEM3_NonConstMemberFunction) {
    // When a function is declared as const, it can be called on any type of object.
    // Non-const functions can only be called by non-const objects.
    const NonConstMemberFunction constObject(10);

    //std::cout << constObject.getValue();
}

TEST(EFFECTIVE_CXX, ITEM3_ConstMemberFunction) {
    ConstMemberFunction nonConstObject;
    nonConstObject.getValue();
}