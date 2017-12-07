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
#include <memory>
#include "gtest/gtest.h"
#include "item13/item13.h"

TEST(EFFECTIVE_CXX, ITEM13) {
    // C3927
    // std::auto_ptr<Investment> ptr.reset(CreateInvestment());

    std::auto_ptr<Investment> ptr(CreateInvestment());
    ptr.reset(CreateInvestment());

    std::auto_ptr<Investment> ptr2;
    ptr2.reset(new Investment());
}