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
#include <iostream>

#include "gtest/gtest.h"
#include "item8/item8.h"

TEST(EFFECTIVE_CXX, ITEM8) {
    DBConn dbc(DBConnection::Create());

    EXPECT_THROW({
        try {
            dbc.Close();
        } catch (const std::invalid_argument &e) {
            EXPECT_STREQ("invalid argument", e.what());
            throw;
        }
    }, std::invalid_argument);

    // dbc.Close always failing, we close it by hacking
    dbc.SetClose(true);
}