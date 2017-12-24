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
#include "item35.h"

int GameCharacterNVI::doHealthValue() const {
    return 0;
}

int BadGuyNVI::doHealthValue() const {
    return 10;
}

int defaultHealthCalc(const GameCharacterFunctionPointer &gamecharacter) {
    return 20;
}

int loseHealthQuickly(const GameCharacterFunctionPointer &gamecharacter) {
    return 40;
}

int defaultHealthCalc2(const GameCharacterTR1Function &gamecharacter) {
    return 30;
}

short calcHealth(const GameCharacterTR1Function &) {
    return 25;
}

HealthValueCalc defaultHealthValue;