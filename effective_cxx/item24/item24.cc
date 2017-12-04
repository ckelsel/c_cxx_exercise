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

#include "item24.h"

Rational::Rational(int numerator, int denomination) {
    numerator_ = numerator;
    denomination_ = denomination;
}

// error!!!
// int Rational::numerator() {
//    return numerator_;
// }

int Rational::numerator() const {
    return numerator_;
}

int Rational::denomination() const {
    return denomination_;
}

const Rational Rational::operator*(const Rational &rhs) const {
    return Rational(numerator_ * rhs.numerator(), 
                    denomination_ * rhs.denomination());
}


//////////////////////////////////

Rational2::Rational2(int numerator, int denomination) {
    numerator_ = numerator;
    denomination_ = denomination;
}

int Rational2::numerator() const {
    return numerator_;
}

int Rational2::denomination() const {
    return denomination_;
}

const Rational2 operator*(const Rational2 &lhs, const Rational2 &rhs) {
    return Rational2(lhs.numerator() * rhs.numerator(), 
                     lhs.denomination() * rhs.denomination());
}