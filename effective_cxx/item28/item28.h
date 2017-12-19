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

#ifndef __ITEM28_H__
#define __ITEM28_H__
#include <memory>

class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {
    }

    Point(const Point &other) {
        x_ = other.x_;
        y_ = other.y_;
    }

    void setX(int x) {
        x_ = x;
    }

    void setY(int y) {
        y_ = y;
    }

private:
    int x_;
    int y_;
};

struct RectData {
    RectData(Point lt, Point rb) 
        : left_top(lt), right_bottom(rb) {
    }
    Point left_top;
    Point right_bottom;
};


class GUIObject {
};

class Rectangle {
public:
    Rectangle(const Point &left_top, const Point &right_bottom) {
        data_.reset(new RectData(left_top, right_bottom));
    }

    // seft-contradictory
    // return referenct but data_ is private
    Point& leftTop() const {
        return data_->left_top;
    }

    const Point& rightBottom() const {
        return data_->right_bottom;
    }

private:
    std::tr1::shared_ptr<RectData> data_;
};

// return by value, after dtor, rightBotton() or leftTop() will 
// reference to undefined
const Rectangle boundingBox(const GUIObject &obj);

#endif // __ITEM28_H__