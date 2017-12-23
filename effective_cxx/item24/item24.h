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
#ifndef __ITEM24_H__
#define __ITEM24_H__
//Item 24: Declare non-member functions when type conversions should apply to allparameters

// 合理的
class Rational {
public:
    Rational(int numerator = 0,      // ctor is deliberately not explicit
             int denomination = 1);  // allow implicit int-to-Rational coversions

    int numerator() const;

    int denomination() const;

    // declare as member function
    const Rational operator*(const Rational &rhs) const;

private:
    int numerator_;
    int denomination_;
};

//////////////////

class Rational2 {
public:
    Rational2(int numerator = 0,      // ctor is deliberately not explicit
             int denomination = 1);  // allow implicit int-to-Rational2 coversions

    int numerator() const;

    int denomination() const;

private:
    int numerator_;
    int denomination_;
};

// declare as non-member function
const Rational2 operator*(const Rational2 &lhs, const Rational2 &rhs);

#endif // __ITEM24_H__