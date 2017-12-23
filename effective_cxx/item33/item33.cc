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
#include "item33.h"

int item33_x;

void func() {
    // use item33_x (double)
    double item33_x;
}

/////////////////

void Base::VirtualFunction1() {

}

void Base::VirtualFunction1(int x) {
    x_ = x;
}

void Base::VirtualFunction2() {
    x_ = 2;
}

void Base::Function3() {
    x_ = 3;
}
void Base::Function3(int x) {
    x_ = x;
    
}

///////////////////

void DerivedOverrideBase::VirtualFunction1() {
    x_ = 11;
}

void DerivedOverrideBase::Function3() {
    x_ = 33;
}

void DerivedOverrideBase::Function4() {
    x_ = 44; 
}

///////////////


void DerivedCallBase::VirtualFunction1() {
    x_ = 111;
}

void DerivedCallBase::Function3() {
    x_ = 333;
}

void DerivedCallBase::Function4() {
    x_ = 444;
}