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
#include "item37/item37.h"

#include <memory>

TEST(EFFECTIVE_CXX, ITEM37) {
    std::tr1::shared_ptr<Shape37> circle(new Circle37);
    std::tr1::shared_ptr<Shape37> rect(new Rectangle37);

    circle->draw(Shape37::ShapeColor::Red);
    ASSERT_EQ(circle->getShapeColor(), Shape37::ShapeColor::Red);

    rect->draw(Shape37::ShapeColor::Red);
    ASSERT_EQ(rect->getShapeColor(), Shape37::ShapeColor::Red);

    // default parameters is Green
    // while virtual functions are dynamically bound, but default parameters are statically bound
    rect->draw();
    ASSERT_EQ(rect->getShapeColor(), Shape37::ShapeColor::Red);
}

TEST(EFFECTIVE_CXX, ITEM37_2) {
    std::tr1::shared_ptr<Shape37NVI> circle(new Circle37NVI);
    std::tr1::shared_ptr<Shape37NVI> rect(new Rectangle37NVI);

    circle->draw(Shape37NVI::ShapeColor::Red);
    ASSERT_EQ(circle->getShapeColor(), Shape37NVI::ShapeColor::Red);

    rect->draw(Shape37NVI::ShapeColor::Red);
    ASSERT_EQ(rect->getShapeColor(), Shape37NVI::ShapeColor::Red);
}