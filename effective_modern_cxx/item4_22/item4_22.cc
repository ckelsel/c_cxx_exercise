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

#include "item4_22.h"

namespace item4_22 {

struct Widget422Impl {
    std::string name_;
    std::vector<double> data_;
};

Widget422::Widget422() : impl_(new Widget422Impl) {

}

Widget422::~Widget422() {
    delete impl_;
}



Widget422UniquePtr::Widget422UniquePtr() 
: impl_(std::make_unique<Widget422Impl>()){

}

Widget422UniquePtr::~Widget422UniquePtr() {
}

Widget422UniquePtr::Widget422UniquePtr(const Widget422UniquePtr &rhs)
: impl_(std::make_unique<Widget422Impl>(*rhs.impl_)) {
}

Widget422UniquePtr& Widget422UniquePtr::operator=(const Widget422UniquePtr &rhs) {
    *impl_ = *rhs.impl_;
    return *this;
}

}