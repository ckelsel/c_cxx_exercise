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

#include "item34.h"

void Shape::error(const std::string &msg) {

}

int Shape::objectID() const {
   return objectID_; 
}

////////////////////

void Rectangle::draw() const {
    objectID_ = 11;
}

void Rectangle::error(const std::string &msg) {

}

////////////////////

void Ellipse::draw() const {
    objectID_ = 22;
}

void Ellipse::error(const std::string &msg) {

}

////////////////////

void Airplane::defaultFly(const Airport &dest) {
    x_ = 1;
}

////////////////////

void ModelA::fly(const Airport &dest) {
    Airplane::defaultFly(dest);
}

////////////////////

void ModelB::fly(const Airport &dest) {
    Airplane::defaultFly(dest);
}

////////////////////

void ModelDifferentFly::fly(const Airport &dest) {
    x_ = 2;
}