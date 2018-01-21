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
#include "simple/s522.h"


TEST(S522, AnswerToString) {
    S522::Result result;

    result.push_back(1);
    result.push_back(2);
    ASSERT_STREQ("21", S522::AnswerToString(result).c_str());

    result.push_back(0);
    result.push_back(9);
    ASSERT_STREQ("9021", S522::AnswerToString(result).c_str());
}

TEST(S522, test_3) {
    S522::Result result;

    S522::Answer(3, result);
    const std::string correct_3("6");
    std::string ans = S522::AnswerToString(result);
    ASSERT_STREQ(correct_3.c_str(), ans.c_str());
}

TEST(S522, test_30) {
    S522::Result result;

    S522::Answer(30, result);
    const std::string correct_30("265252859812191058636308480000000");
    std::string ans = S522::AnswerToString(result);
    ASSERT_STREQ(correct_30.c_str(), ans.c_str());
}