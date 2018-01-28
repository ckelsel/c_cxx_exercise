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
#include "item5_2_2/item5_2_2.h"

#include <memory>
#include <string>
#include <vector>
#include <iostream>

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_2) {
    std::shared_ptr<int> ref1(new int);
    std::weak_ptr<int> weak(ref1);

    ASSERT_EQ(weak.use_count(), 1);
    ASSERT_EQ(ref1.use_count(), 1);

    std::shared_ptr<int> ref2(ref1);
    ASSERT_EQ(weak.use_count(), 2);
    ASSERT_EQ(ref1.use_count(), 2);
    ASSERT_EQ(ref2.use_count(), 2);

    ref2.reset();
    ASSERT_EQ(weak.use_count(), 1);
    ASSERT_EQ(ref1.use_count(), 1);
    ASSERT_EQ(ref2.use_count(), 0);

    std::shared_ptr<int> ref3(weak);
    ASSERT_EQ(weak.use_count(), 2);
    ASSERT_EQ(ref1.use_count(), 2);
    ASSERT_EQ(ref2.use_count(), 0);
    ASSERT_EQ(ref3.use_count(), 2);

    ref3.reset();
    ASSERT_EQ(weak.use_count(), 1);
    ASSERT_EQ(ref1.use_count(), 1);
    ASSERT_EQ(ref2.use_count(), 0);
    ASSERT_EQ(ref3.use_count(), 0);

    ref1.reset();
    ASSERT_EQ(weak.use_count(), 0);
    ASSERT_EQ(ref1.use_count(), 0);
    ASSERT_EQ(ref2.use_count(), 0);
    ASSERT_EQ(ref3.use_count(), 0);

    ASSERT_TRUE(weak.expired());
}

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_2_circle_reference) {
    std::shared_ptr<PersonCircleReference> person(initFamily("jack"));

    ASSERT_EQ(person.use_count(), 3);
    ASSERT_EQ(person->dad_.use_count(), 1);
    ASSERT_EQ(person->mon_.use_count(), 1);
}

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_2_circle_reference_weakptr) {
    std::shared_ptr<PersonCircleReferenceWeakPtr> person(initFamilyWeakPtr("jack_weakptr"));

    ASSERT_EQ(person.use_count(), 1);
    ASSERT_EQ(person->dad_.use_count(), 1);
    ASSERT_EQ(person->mon_.use_count(), 1);
}

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_2_circle_reference2) {
    std::shared_ptr<CircleReference> m(new CircleReference);
    std::shared_ptr<CircleReference> n(new CircleReference);

    ASSERT_EQ(m.use_count(), 1);
    ASSERT_EQ(n.use_count(), 1);

    m->m_ = n;
    ASSERT_EQ(n.use_count(), 2);

    n->n_ = m;
    ASSERT_EQ(m.use_count(), 2);
    
    // error, both m and n leak resource
}

TEST(EFFECTIVE_MODERN_CXX, ITEM5_2_2_circle_reference_a_b) {
    std::shared_ptr<CircleReferenceA> a(new CircleReferenceA);
    std::shared_ptr<CircleReferenceB> b(new CircleReferenceB);

    ASSERT_EQ(a.use_count(), 1);
    ASSERT_EQ(b.use_count(), 1);

    a->b_ = b;
    ASSERT_EQ(b.use_count(), 2);

    b->a_ = a;
    ASSERT_EQ(a.use_count(), 2);

    // error, both a and b leak resource
}