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
#include "item27/item27.h"

#include <vector>
#include <memory>

TEST(EFFECTIVE_CXX, ITEM27) {
    SpecialWindows windows;
    
    ASSERT_EQ(windows.getCount(), 1);
    windows.onResize();
    ASSERT_EQ(windows.getCount(), 2);

    ASSERT_EQ(windows.getCount2(), 1);
    windows.onResizeWrongWay();
    ASSERT_EQ(windows.getCount2(), 1);
}

typedef std::vector<std::tr1::shared_ptr<Windows> > windowsVector;

TEST(EFFECTIVE_CXX, ITEM27_2) {
    windowsVector vector;

    std::tr1::shared_ptr<Windows> windows(new SpecialWindows);
    vector.push_back(windows);

    for (windowsVector::iterator iter = vector.begin();
         iter != vector.end();
         ++iter) {
        if (SpecialWindows *windows = dynamic_cast<SpecialWindows*>(iter->get())) {
            windows->blink();
        }
    }
}