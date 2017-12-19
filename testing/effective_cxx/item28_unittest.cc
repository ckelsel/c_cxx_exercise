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
#include "item28/item28.h"

TEST(EFFECTIVE_CXX, ITEM28) {
    Point p1(0, 0);
    Point p2(100, 100);

    const Rectangle rect(p1, p2);
    // error, we can modify x
    rect.leftTop().setX(10);
}

TEST(EFFECTIVE_CXX, ITEM28_2) {
    GUIObject obj;

    // error, right_bottom referenct to undefined
    const Point *right_bottom = &(boundingBox(obj).rightBottom());
}