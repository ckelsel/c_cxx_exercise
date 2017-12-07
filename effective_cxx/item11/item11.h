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
#ifndef __ITEM11_H__
#define __ITEM11_H__
// Item11: Handle assignment to self in operator =

class Bitmap {
};

class WidgetUnsafe {
public:
    WidgetUnsafe& operator=(const WidgetUnsafe &rhs) {
        delete bitmap_;
        bitmap_ = new Bitmap(*rhs.bitmap_);
        return *this;
    }

private:
    Bitmap *bitmap_;
};

class WidgetUnsafeTraditional {
public:
    WidgetUnsafeTraditional& operator=(const WidgetUnsafeTraditional &rhs) {
        // identity test
        if (this == &rhs) {
            return *this;
        }

        delete bitmap_;
        bitmap_ = new Bitmap(*rhs.bitmap_);
        return *this;
    }
private:
    Bitmap *bitmap_;
};

class WidgetSafeStorePointer {
public:
    WidgetSafeStorePointer& operator=(const WidgetSafeStorePointer &rhs) {
        // save original bitmap_
        Bitmap *orig = bitmap_;
        // copy bitmap
        bitmap_ = new Bitmap(*rhs.bitmap_);
        // delete orig after copy success
        delete orig;

        return *this;
    }
private:
    Bitmap *bitmap_;
};

class WidgetSafeSwap {
public:
    void Swap(WidgetSafeSwap &rhs);

    WidgetSafeSwap& operator=(const WidgetSafeSwap &rhs) {
        WidgetSafeSwap tmp(rhs);
        Swap(tmp);
        return *this;
    }
private:
    Bitmap *bitmap_;
};

#endif // __ITEM11_H__