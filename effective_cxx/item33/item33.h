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
#ifndef __ITEM33_H__
#define __ITEM33_H__
//Item 33: Avoid hiding inherited names

class Base {
public:
    virtual void VirtualFunction1() = 0;
    virtual void VirtualFunction1(int x);

    //Now, the compiler, to resolve the correct overloaded method,
    //looks at method name and arguments but NO at the return value
    //virtual int VirtualFunction1(int x);

    virtual void VirtualFunction2();

    void Function3();
    void Function3(int x);

private:
    int x_;
};

class DerivedOverrideBase : public Base {
public:
    virtual void VirtualFunction1();

    void Function3();

    void Function4();
};


class DerivedCallBase : public Base {
public:
    using Base::VirtualFunction1;
    using Base::Function3;

    virtual void VirtualFunction1();

    void Function3();

    void Function4();
};

#endif // __ITEM33_H__