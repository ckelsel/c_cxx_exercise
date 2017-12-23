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
#include "item33/item33.h"

#include <memory>

TEST(EFFECTIVE_CXX, ITEM33) {
    std::tr1::shared_ptr<DerivedOverrideBase> derived(new DerivedOverrideBase);    

    derived->VirtualFunction1();
    // error, override
    //derived->VirtualFunction1(1);

    derived->VirtualFunction2();

    
    derived->Function3();
    // error, override
    //derived->Function3(1);

    derived->Function4();
}

TEST(EFFECTIVE_CXX, ITEM33_2) {
    std::tr1::shared_ptr<DerivedCallBase> derived(new DerivedCallBase);

    derived->VirtualFunction1();
    derived->VirtualFunction1(1);

    derived->VirtualFunction2();

    
    derived->Function3();
    derived->Function3(1);

    derived->Function4();
}