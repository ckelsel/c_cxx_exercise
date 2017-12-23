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
#ifndef __ITEM36_H__
#define __ITEM36_H__
//Item 36: Never redefine an inherited non-virtual function

class Base36 {
public:
    Base36() : x_(0) {

    }

    void non_virtual_function();

    int getX() const {
        return x_;
    }

protected:
    int x_;
};

class DerivedNoRedefine : public Base36 {
public:
    DerivedNoRedefine() : Base36() {

    }
};

class DerivedRedefine : public Base36 {
public:
    DerivedRedefine() : Base36() {

    }

    void non_virtual_function();
};

#endif // __ITEM36_H__