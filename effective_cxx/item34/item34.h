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
#ifndef __ITEM34_H__
#define __ITEM34_H__
//Item 34: Differentiate between inheritance of interface and inheritance of implementation

#include <string>

class Shape {
public:
    Shape() : objectID_(0) {

    }

    // interface only
    virtual void draw() const = 0;

    // interface and a default implementation
    virtual void error(const std::string &msg);

    // interface and a mandatory implementation
    int objectID() const;

protected:
    // draw() is const member function
    mutable int objectID_;
};

class Rectangle : public Shape {
public:
    virtual void draw() const;

    virtual void error(const std::string &msg);
};

class Ellipse : public Shape {
public:
    virtual void draw() const;

    virtual void error(const std::string &msg);
};

//////////////////

class Airport {

};

class Airplane {
public:
    Airplane() : x_(0) {
    }

    int getX() const {
        return x_;
    }

    virtual void fly(const Airport &dest) = 0;

protected:
    // non-virtual
    void defaultFly(const Airport &dest);

    int x_;
};

class ModelA : public Airplane {
public:
    virtual void fly(const Airport &dest);
};

class ModelB : public Airplane {
public:
    virtual void fly(const Airport &dest);
};

class ModelDifferentFly : public Airplane {
public:
    virtual void fly(const Airport &dest);
};

#endif // __ITEM34_H__