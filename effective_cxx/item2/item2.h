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

#ifndef __ITEM_2_H__
#define __ITEM_2_H__

//Prefer consts,enums,and inlines to #defines

#include <string>

const char *const authorName = "xiekm";

const std::string authorName2("xiekm");


// first way
class GamePlayer {
public:
    static const int NumTurns = 5; // declaration
    int scores[NumTurns];
};

// second way
class CostEstimate {
public:
    static const double FudgeFactor; // declaration
};

class GamePlayer2 {
public:
    enum { NumTurns2 = 10 };
    int scores2[NumTurns2];
};

#endif // __ITEM_2_H__
