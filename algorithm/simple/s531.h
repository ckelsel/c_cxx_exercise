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
#ifndef __S531_H__
#define __S531_H__
/// 有一个四位数，各个数字都不相同，把所有数字从大到小排序得到a，
/// 从小到大排序得到b，a-b替换原来的数，继续操作。
/// 输入一个n位数，输出操作序列，直到出现循环。
/// 输入: 1234
/// 输出: 1234->3087->8352->6174->6174

#include <vector>

namespace S531 {
    typedef std::vector<int> Result;

    int ToInt(Result value);
    Result ToResult(int value);
    void SmallBubbleSort(int *value, int length);
    void BigBubbleSort(int *value, int length);
    void Answer(Result &in, Result &result);
}

#endif // __S531_H__