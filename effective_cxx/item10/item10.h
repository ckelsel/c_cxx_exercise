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
#ifndef __ITEM10_H__
#define __ITEM10_H__
//Item 10: Have assignment operators return a reference to *this

#include <stdint.h>

// total 5 operators, =, +=, -=, *=, /=
// Have assignment operators return a reference to *this

class TimeDelta {
public:
    TimeDelta() : delta_(0) {
    }

    TimeDelta(int64_t delta) : delta_(delta) {
    }

    TimeDelta& operator=(const TimeDelta &other) {
        delta_ = other.delta_;
        return *this;
    }

    TimeDelta& operator+=(const TimeDelta &other) {
        delta_ += other.delta_;
        return *this;
    }

    TimeDelta& operator-=(const TimeDelta &other) {
        delta_ -= other.delta_;
        return *this;
    }

    TimeDelta& operator*=(const TimeDelta &other) {
        delta_ *= other.delta_;
        return *this;
    }

    TimeDelta& operator/=(const TimeDelta &other) {
        delta_ /= other.delta_;
        return *this;
    }

    bool operator==(const TimeDelta &rhs) {
        return delta_ == rhs.delta_;
    }
private:
    int64_t delta_;
};


#endif // __ITEM10_H__