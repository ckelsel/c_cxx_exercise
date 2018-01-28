 /*
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

#ifndef __EFFECT_MODERN_CXX_ITEM4_18_H__
#define __EFFECT_MODERN_CXX_ITEM4_18_H__
// Item 18: Use std::unique_ptrfor exclusive-ownership resource management.

#include <memory>

class Investment {
public:
    enum TYPE { STOCK, BOND, REAL_ESTATE };
    virtual TYPE Type() const = 0;
    ~Investment() { }
};

class Stock : public Investment {
public:
    TYPE Type() const {
        return STOCK;
    }
};

class Bond : public Investment {
public:
    TYPE Type() const {
        return BOND;
    }
};

class RealEstate : public Investment {
public:
    TYPE Type() const {
        return REAL_ESTATE;
    }
};

std::unique_ptr<Investment> makeInvestment(Investment::TYPE type);

#endif // __EFFECT_MODERN_CXX_ITEM4_18_H__