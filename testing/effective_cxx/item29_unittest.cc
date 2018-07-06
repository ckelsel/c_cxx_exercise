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

#ifdef _WIN32
#include "gtest/gtest.h"
#include "item29/item29.h"

TEST(EFFECTIVE_CXX, ITEM29) {
    std::istream nullimg(NULL);
    PrettyMenuException menu;
    EXPECT_THROW({
        try {
            menu.ChangeBackground(nullimg);
        } catch (const std::invalid_argument &e) {
            ASSERT_STREQ("invalid argument", e.what());

            // NULL for delete old image
            ASSERT_EQ(menu.GetImage(), (Image *)NULL);

            ASSERT_EQ(menu.GetChange(), 0);
            throw;
        }
    }, std::invalid_argument);
}

TEST(EFFECTIVE_CXX, ITEM29_2) {
    std::istream nullimg(NULL);
    PrettyMenu_Exception_RefactorMutex menu;
    EXPECT_THROW({
        try {
            menu.ChangeBackground(nullimg);
        } catch (const std::invalid_argument &e) {
            ASSERT_STREQ("invalid argument", e.what());

            // NULL for delete old image
            ASSERT_EQ(menu.GetImage(), (Image *)NULL);
            ASSERT_EQ(menu.GetChange(), 0);
            throw;
        }
    }, std::invalid_argument);
}

TEST(EFFECTIVE_CXX, ITEM29_3) {
    std::istream nullimg(NULL);
    PrettyMenu_BasicExceptionSafe_RefactorMutex_SmartPointer menu;
    EXPECT_THROW({
        try {
            menu.ChangeBackground(nullimg);
        } catch (const std::invalid_argument &e) {
            ASSERT_STREQ("invalid argument", e.what());

            ASSERT_NE(menu.GetImage(), (Image *)NULL);

            // new Image throw exception, ++change not run
            ASSERT_EQ(menu.GetChange(), 0);
            throw;
        }
    }, std::invalid_argument);

    menu.ChangeBackground(nullimg, false);
    ASSERT_NE(menu.GetImage(), (Image *)NULL);
    ASSERT_EQ(menu.GetChange(), 1);
}

TEST(EFFECTIVE_CXX, ITEM29_4) {
    std::istream nullimg(NULL);
    PrettyMenu_StrongExceptionSafe_RefactorMutex_SmartPointer menu;
    EXPECT_THROW({
        try {
            menu.ChangeBackground(nullimg);
        } catch (const std::invalid_argument &e) {
            ASSERT_STREQ("invalid argument", e.what());

            ASSERT_NE(menu.GetImage(), (Image *)NULL);

            // new Image throw exception, ++change not run
            ASSERT_EQ(menu.GetChange(), 0);
            throw;
        }
    }, std::invalid_argument);

    menu.ChangeBackground(nullimg, false);
    ASSERT_NE(menu.GetImage(), (Image *)NULL);
    ASSERT_EQ(menu.GetChange(), 1);
}

#endif // _WIN32
