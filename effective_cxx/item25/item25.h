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

#ifndef __ITEM25_H__
#define __ITEM25_H__
#include <vector>

class WidgetImpl25 {
public:

private:
    int a_;
    std::vector<double> double_;
};


class Widget25 {
public:
    Widget25& operator=(const Widget25 &rhs);

    // 1. Offer a public swap member function that 
    // efficiently swaps the value of two objects of your type. 
    void swap(Widget25 &other);

private:
    WidgetImpl25 *impl_;
};


// 2. Offer a non-member swap in the same namespace as your class or template.
//   Have it call your swap member function.
void swap(Widget25& a, Widget25& b);


#if 0
FIXME: LNK2005:

// 3. If you're writing a class (not a class template),
// specialize std::swap for your class. Have it also call your
// swap member function.
namespace std {
template<>
void swap<Widget25>(Widget25& a, Widget25& b) {
    a.swap(b);
}
}
#endif

#endif // __ITEM25_H__
