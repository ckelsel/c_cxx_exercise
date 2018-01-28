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
#include "item5_2_1/item5_2_1.h"

#include <memory>
#include <string>
#include <vector>
#include <iostream>

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_1_std_string) {
    std::shared_ptr<std::string> pNico(new std::string("nico"));

    // custom delete, use lambda
    std::shared_ptr<std::string> pJutta(new std::string("jutta"),
                                        [](std::string *p) {
                                            std::cout << "delete " << *p << std::endl;
                                            delete p;
                                        });

    ASSERT_EQ(pNico.use_count(), 1);

    std::vector<std::shared_ptr<std::string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pNico);
    ASSERT_EQ(pNico.use_count(), 2);
    whoMadeCoffee.push_back(pNico);
    ASSERT_EQ(pNico.use_count(), 3);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);


    for (unsigned int i = 0; i < whoMadeCoffee.size(); ++i) {
        if (i <= 1) {
            ASSERT_STREQ(whoMadeCoffee[i]->c_str(), "nico");
        } else {
            ASSERT_STREQ(whoMadeCoffee[i]->c_str(), "jutta");
        }
    }

    ASSERT_EQ(pJutta.use_count(), 5);
    ASSERT_EQ(pNico.use_count(), 3);
}

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_1_array) {
    // one
    std::shared_ptr<int> array(new int[10], [](int *p) {
        std::cout << "delete array" << std::endl;
        delete[] p;
    });

    // second
    std::shared_ptr<int> array2(new int[10], std::default_delete<int[]>());
}


TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_1_file) {
    // FileDeleter use assign ctor
    std::shared_ptr<std::ofstream> fp(new std::ofstream("tmp.txt"),
                                      FileDeleter("tmp.txt"));
}

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_1_share_memory) {
    std::shared_ptr<ShareMemory> sharememory(new ShareMemory(100));

    char *buffer = sharememory->GetBuffer();
    buffer[0] = 'X';
}