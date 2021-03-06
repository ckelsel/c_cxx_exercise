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
#ifndef __ITEM17_H__
#define __ITEM17_H__
//Item 17: Store newed objects in smart pointers in standalone statements.

#include <memory>

class Widget17 {
};

int Priority() {
    return 0;
}

void ProcessWidget(std::tr1::shared_ptr<Widget17> widget, int priority) {
}

#endif // __ITEM17_H__
