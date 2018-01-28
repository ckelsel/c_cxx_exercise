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

#ifndef __EFFECT_MODERN_CXX_ITEM4_22_H__
#define __EFFECT_MODERN_CXX_ITEM4_22_H__
// Item 22: When using the Pimpl Idiom, define special
// member functions in the implementation file.

#include <vector>
#include <string>
#include <memory>

namespace item4_22 {
struct Widget422Impl;
class Widget422 {
public:
    Widget422();
    ~Widget422();

private:
    Widget422Impl *impl_;
};


class Widget422UniquePtr {
public:
    Widget422UniquePtr();
    ~Widget422UniquePtr();

    Widget422UniquePtr (const Widget422UniquePtr &rhs);

    Widget422UniquePtr& operator=(const Widget422UniquePtr &rhs);
private:
    std::unique_ptr<Widget422Impl> impl_;
};
}
#endif // __EFFECT_MODERN_CXX_ITEM4_22_H__