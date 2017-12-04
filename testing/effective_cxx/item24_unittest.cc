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
#include "item24/item24.h"

TEST(EFFECTIVE_CXX, ITEM24) {
    Rational oneEighth(1, 8);
    Rational oneHalf(1, 2);

    Rational result = oneHalf * oneEighth;

    result = result * result;

    // ctor is not explicit
    result = oneHalf * 2;

    // operator * is member function
    // error ! 1th member function, 2th non-member function
    // -> result = operator *(2, oneHalf);
    // result = 2 * oneHalf;
}

TEST(EFFECTIVE_CXX, ITEM24_2) {
    Rational2 oneEighth(1, 8);
    Rational2 oneHalf(1, 2);

    Rational2 result = oneHalf * oneEighth;

    result = result * result;

    // ctor is not explicit
    result = oneHalf * 2;

    // operator * is non-member function
    result = 2 * oneHalf;
}