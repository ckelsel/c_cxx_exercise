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
#include "item4_22/item4_22.h"
using namespace item4_22;

TEST(EFFECTIVE_MODERN_CXX, ITEM4_22) {
    Widget422 w;

    Widget422UniquePtr w2;

    // must implement copy ctor
    auto w3(std::move(w2));

    w2 = std::move(w3);
}