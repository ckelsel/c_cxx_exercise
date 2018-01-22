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
#include "simple/s531.h"

TEST(S531, test_bubblesort) {
    #define N 5
    int a[N] = {2, 4, 5, 8, 1};

    int small[N] = {1, 2, 4, 5, 8};
    int big[N] = {8, 5, 4, 2, 1};

    S531::SmallBubbleSort(a, N);

    for (int i = 0; i < N; i++) {
        ASSERT_EQ(a[i], small[i]);
    }

    S531::BigBubbleSort(a, N);
    for (int i = 0; i < N; i++) {
        ASSERT_EQ(a[i], big[i]);
    }
}


TEST(S531, test_toxxx) {
    int value = 1234;

    S531::Result result = S531::ToResult(value);
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 2);
    ASSERT_EQ(result[2], 3);
    ASSERT_EQ(result[3], 4);

    int value2 = S531::ToInt(result);
    ASSERT_EQ(value, value2);
}

TEST(S531, test_1234) {
    S531::Result result;
    S531::Result in;
    in.push_back(1);
    in.push_back(2);
    in.push_back(3);
    in.push_back(4);

    S531::Result correct;
    correct.push_back(1234);
    correct.push_back(3087);
    correct.push_back(8352);
    correct.push_back(6174);
    correct.push_back(6174);

    S531::Answer(in, result);

    ASSERT_EQ(correct.size(), result.size());
    for (int i = 0; i < correct.size(); i++) {
        ASSERT_EQ(correct[i], result[i]);
    }
}


TEST(S531, test_86526432) {
    S531::Result result;
    S531::Result in = {8, 6, 5, 2, 6, 4, 3, 2};

    S531::Result correct;
    correct.push_back(86526432);
    correct.push_back(64308654);
    correct.push_back(83208762);
    correct.push_back(86526432);

    S531::Answer(in, result);

    ASSERT_EQ(correct.size(), result.size());
    for (int i = 0; i < correct.size(); i++) {
        ASSERT_EQ(correct[i], result[i]);
    }
}