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
#ifndef __ITEM37_H__
#define __ITEM37_H__
//Item 37: Never redefine a function's inherited default parameter value

class Shape37 {
public:
    enum ShapeColor { Red, Green, Blue };

    virtual void draw(ShapeColor color = Red) const = 0;

    ShapeColor getShapeColor() const {
        return color_;
    }

protected:
    mutable ShapeColor color_;
};

class Rectangle37 : public Shape37 {
public:
    virtual void draw(ShapeColor color = Green) const;
};

class Circle37 : public Shape37 {
public:
    virtual void draw(ShapeColor color) const;
};

///////////////////////////////////////

class Shape37NVI {
public:
    enum ShapeColor { Red, Green, Blue };

    // non-virtual interface(NVI)
    void draw(ShapeColor color = Red) const;

    ShapeColor getShapeColor() const {
        return color_;
    }

private:
    // avoid default parameters
    virtual void doDraw(ShapeColor color) const = 0;

protected:
    mutable ShapeColor color_;
};

class Rectangle37NVI : public Shape37NVI {
private:
    virtual void doDraw(ShapeColor color) const;
};

class Circle37NVI : public Shape37NVI {
private:
    virtual void doDraw(ShapeColor color) const;
};

#endif // __ITEM37_H__