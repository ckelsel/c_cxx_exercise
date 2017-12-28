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
#include "item5_2_3/item5_2_3.h"

#include <memory>
#include <string>
#include <vector>
#include <iostream>

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_3) {
    // delete p twice
    // int *p = new int;
    // std::shared_ptr<int> ref1(p);
    // std::shared_ptr<int> ref2(p);

    std::shared_ptr<int> ref1(new int);
    std::shared_ptr<int> ref2(ref1);
}

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_3_kids) {
    std::shared_ptr<PersonCircleReferenceMisUse> mon(new PersonCircleReferenceMisUse("kid's mon"));
    std::shared_ptr<PersonCircleReferenceMisUse> dad(new PersonCircleReferenceMisUse("kid's dad"));
    std::shared_ptr<PersonCircleReferenceMisUse> kid(new PersonCircleReferenceMisUse("kid"));
    kid->SetParentsAndTheirKidsCorrect(kid, mon, dad);

    kid->SetParentsAndTheirKidsCorrect2(mon, dad);

    //kid->SetParentsAndTheirKidsError(mon, dad);
}