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

#include "item25.h"


// copy-swap
Widget25& Widget25::operator=(const Widget25 &rhs) {
    Widget25 tmp(rhs);
    swap(tmp);
    return *this;
}

void Widget25::swap(Widget25 &other) {
    using std::swap;
    swap(impl_, other.impl_);

    // std::swap(impl_, other_impl_)
    // Dont't use above, because it only use std::swap
    // may be it has another non-member swap function
}

void swap(Widget25& a, Widget25& b) {
    a.swap(b);
}
