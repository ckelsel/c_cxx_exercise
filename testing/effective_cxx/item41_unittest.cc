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
#include "item41/item41.h"

TEST(EFFECTIVE_CXX, ITEM41) {
    Geeks obj1;
     
    // Which function is called will depend on the parameters passed
    // The first 'func' is called 
    obj1.func(7);
     
    // The second 'func' is called
    obj1.func(9.132);
     
    // The third 'func' is called
    obj1.func(85,64);
}

TEST(EFFECTIVE_CXX, ITEM41_2) {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"

    ASSERT_EQ(c3.getReal(), 12);
    ASSERT_EQ(c3.getImag(), 9);
}

TEST(EFFECTIVE_CXX, ITEM41_3) {
    //object of parent class
    Parent obj1;
     
    //object of child class
    Child obj2 = Child();

    obj1.func();
    ASSERT_EQ(obj1.getX(), 1);

    obj2.func();
    ASSERT_EQ(obj2.getX(), 2);
}

TEST(EFFECTIVE_CXX, ITEM41_4) {
    my_template<int> x;
    my_template<long> y;
    my_template<std::string> z;

    ASSERT_EQ(x.foo, 42);
    ASSERT_EQ(y.foo, 0);
    ASSERT_STREQ(z.foo.c_str(), "");
}