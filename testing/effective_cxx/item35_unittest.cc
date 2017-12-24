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
#include "item35/item35.h"

#include <memory>

TEST(EFFECTIVE_CXX, ITEM35_NVI) {
    std::tr1::shared_ptr<GameCharacterNVI> badguy(new BadGuyNVI);
    ASSERT_EQ(badguy->healthValue(), 10);
}

TEST(EFFECTIVE_CXX, ITEM35_FUNCTION_POINTER) {
    std::tr1::shared_ptr<GameCharacterFunctionPointer> badguy(new BadGuyFunctionPointer);
    ASSERT_EQ(badguy->healthValue(), 20);

    std::tr1::shared_ptr<GameCharacterFunctionPointer> lucklyguy(new BadGuyFunctionPointer(loseHealthQuickly));
    ASSERT_EQ(lucklyguy->healthValue(), 40);
}

TEST(EFFECTIVE_CXX, ITEM35_TR1_FUNCTION) {
    std::tr1::shared_ptr<GameCharacterTR1Function> badguy(new BadGuyTR1Function(calcHealth));
    ASSERT_EQ(badguy->healthValue(), 25);

    std::tr1::shared_ptr<GameCharacterTR1Function> badguy2(new BadGuyTR1Function(HealthCalculator()));
    ASSERT_EQ(badguy2->healthValue(), 10);

    using namespace std::placeholders;
    GameLevel gamelevel;
    std::tr1::shared_ptr<GameCharacterTR1Function> badguy3(new BadGuyTR1Function(
        std::tr1::bind(&GameLevel::health, gamelevel, _1)
    ));
    ASSERT_EQ(badguy3->healthValue(), 2);
}

TEST(EFFECTIVE_CXX, ITEM35_STRATEGY) {
    std::tr1::shared_ptr<HealthValueCalc> badguycalc(new BadGuyHealthValueCalc);
    std::tr1::shared_ptr<GameCharacterStrategy> guy(new GameCharacterStrategy(badguycalc.get()));
    ASSERT_EQ(guy->healthValue(), 30);
}