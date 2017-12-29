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
#include "item5_2_5/item5_2_5.h"

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <functional>

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_5) {
    std::unique_ptr<std::string> ref1(new std::string("test"));
    std::unique_ptr<std::string> ref2(std::move(ref1));

    ref1 = nullptr;
    ref2.reset();
}

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_5_sink_source) {
    int val = 0;
    std::unique_ptr<std::string, std::function<void(std::string *p)>> ref(new std::string("sink"),
        [&val](std::string *p) {
            std::cout << "delete " << *p << std::endl;
            val = 1;
    });

    // ref delete after sink() return
    sink(std::move(ref));
    ASSERT_EQ(val, 1);

    std::unique_ptr<std::string, std::function<void(std::string *p)>> ref2(source(val));
    ASSERT_EQ(val, 1);
    ref2 = nullptr;
    ASSERT_EQ(val, 2);
}

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_5_class_member) {
    std::unique_ptr<Member> member(new Member);
    std::unique_ptr<Member> member2(std::move(member));

    // error
    //std::unique_ptr<Member> member3 = member2;
}

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_5_array) {
    // leak resource
    std::unique_ptr<int> array1(new int[10]);

    // 1. OK
    std::unique_ptr<int[]> array2(new int[10]);

    // 2. OK
    std::unique_ptr<int, std::default_delete<int[]>> array3(new int[10]);

    // 3. OK
    std::unique_ptr<int, std::function<void(int *)>> array4(new int [10], [](int *p) {
        delete[] p;
    });

    // 4. OK
    std::unique_ptr<int, void(*)(int *)> array5(new int [10], [](int *p) {
        delete[] p;
    });

    // 5. OK
    auto delete_int = [](int *p) {
        delete[] p;
    };
    std::unique_ptr<int, decltype(delete_int)> array6(new int [10], delete_int);
}