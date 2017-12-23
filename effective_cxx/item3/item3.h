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
#ifndef __ITEM3_H__
#define __ITEM3_H__
//Item 3: Use constwhenever possible

#include <string>
#include <iostream>
#include <iterator> // std::size

void item3_test();


// const member function
class TextBlock {
public:
    TextBlock(std::string text) {
        text_ = text;
    }

    // #1
    const char& operator[](std::size_t position) const {
        std::cout << "const char& operator[](std::size position) const" << std::endl;
        return text_[position];
    }

    char& operator[](std::size_t position) {
        std::cout << "char& operator[](std::size position)" << std::endl;
        return text_[position];
    }

private:
    std::string text_;
};

/////////////////

class NonConstMemberFunction{
public:
    NonConstMemberFunction(int value = 0) { value_ = value; }

    // non-const member function
    int getValue() { return value_; }

private:
    int value_;
};

class ConstMemberFunction{
public:
    ConstMemberFunction(int value = 0) { value_ = value; }

    // non-const member function
    const int getValue() const { return value_; }

    // #2
    // const member function can't change member var
    // void resetValue() const { value_ = 0; }

private:
    int value_;
};


#endif // __ITEM3_H__