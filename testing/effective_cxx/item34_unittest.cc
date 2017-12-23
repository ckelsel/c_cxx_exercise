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
#include "item34/item34.h"

#include <memory>

TEST(EFFECTIVE_CXX, ITEM34) {
    std::tr1::shared_ptr<Rectangle> rect(new Rectangle);

    rect->draw();
    ASSERT_EQ(rect->objectID(), 11);

    std::tr1::shared_ptr<Ellipse> elli(new Ellipse);
    elli->draw();
    ASSERT_EQ(elli->objectID(), 22);
}

TEST(EFFECTIVE_CXX, ITEM34_2) {
    Airport airport;

    std::tr1::shared_ptr<ModelA> a(new ModelA);

    a->fly(airport);
    ASSERT_EQ(a->getX(), 1);

    std::tr1::shared_ptr<ModelB> b(new ModelB);

    b->fly(airport);
    ASSERT_EQ(b->getX(), 1);

    std::tr1::shared_ptr<ModelDifferentFly> diff(new ModelDifferentFly);

    diff->fly(airport);
    ASSERT_EQ(diff->getX(), 2);
}