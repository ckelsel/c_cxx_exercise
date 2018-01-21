 /*
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
#ifndef __S522_H__
#define __S522_H__
/// 输入不超过1000的正整数n， 输出n!=1x2x3x..xn的结果
/// 输入: 2
/// 输出: 2

#include <vector>

namespace S522 {

typedef std::vector<int> Result;

void Answer(int n, Result &ans);

std::string AnswerToString(Result &ans);
}

#endif // __S522_H__
