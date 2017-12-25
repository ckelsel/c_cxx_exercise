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
#ifndef __ITEM41_H__
#define __ITEM41_H__
//Item 41: Understand implicit interfaces and compile-time polymorphism

// 1)Compile time polymorphism: This type of polymorphism is achieved by function overloading or operator overloading.

// 1.1) C++ program for function overloading
 
#include<iostream>
#include <string>

using namespace std;

class Geeks
{
public:
     
    // function with 1 int parameter
    void func(int x)
    {
        cout << "value of x is " << x << endl;
    }
     
    // function with same name but 1 double parameter
    void func(double x)
    {
        cout << "value of x is " << x << endl;
    }
     
    // function with same name and 2 int parameters
    void func(int x, int y)
    {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};

// 1.2) Operator Overloading
  
class Complex {
private:
    int real_, imag_;
public:
    Complex(int r = 0, int i =0)  {real_ = r;   imag_ = i;}
      
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real_ = real_ + obj.real_;
         res.imag_ = imag_ + obj.imag_;
         return res;
    }

    int getReal() const {
        return real_;
    }

    int getImag() const {
        return imag_;
    }
};

// 1.3)template
template <class T>
struct my_template { 
    T foo;
    my_template() : foo(T()) {}
};

template <>
struct my_template<int> {
    enum { foo = 42 };
};

// 2)Runtime polymorphism: This type of polymorphism is achieved by Function Overriding.
// Base class
class Parent
{
protected:
    int x_;

public:
    Parent() : x_(0) {
    }

    int getX() const {
        return x_;
    }

    void func() {
        x_ = 1;
    }
};
 
// Derived class
class Child : public Parent
{
public:
    // definition of a member function already present in Parent
    void func() {
        x_ = 2;
    }
};
#endif // __ITEM41_H__
