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
#ifndef __S513_H__
#define __S513_H__

/// 如果一个字符串可以由某个长度为k的字符串重复多次得到，则该串以k为周期
/// 例如，ababab以2为最小周期
/// 输入一个字符串，求最小周期
/// 输入： ababab
/// 输出:  2
int GetMinCycle(const char *data);

#endif // __S513_H__
