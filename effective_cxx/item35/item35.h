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
#ifndef __ITEM35_H__
#define __ITEM35_H__
//Item 35: Consider alternatives to virtual functions

#include <functional>

// Different GameCharacter has different healthValue
class GameCharacter {
public:
    virtual int healthValue() const;
};

// 1) The Template Method Pattern via the Non-Virtual Interface Idiom
class GameCharacterNVI {
public:
    int healthValue() const {
        return doHealthValue();
    }

private:
    virtual int doHealthValue() const;
};

class BadGuyNVI : public GameCharacterNVI {
public:

private:
    virtual int doHealthValue() const;
};

// 2) The Strategy Pattern via Function Pointers

class GameCharacterFunctionPointer;

int defaultHealthCalc(const GameCharacterFunctionPointer &gamecharacter);

int loseHealthQuickly(const GameCharacterFunctionPointer &gamecharacter);

class GameCharacterFunctionPointer {
public:
    typedef int (*HealthCalcFunc)(const GameCharacterFunctionPointer &gamecharacter);

    explicit GameCharacterFunctionPointer(HealthCalcFunc func = defaultHealthCalc)
        : healthCalc_ (func) {
    }

    int healthValue() const {
        return healthCalc_(*this);
    }

private:
    HealthCalcFunc healthCalc_;
};

class BadGuyFunctionPointer : public GameCharacterFunctionPointer {
public:
    explicit BadGuyFunctionPointer(HealthCalcFunc func = defaultHealthCalc)
        : GameCharacterFunctionPointer(func) {
        }
};

// 3) The Strategy Pattern via tr1::function

class GameCharacterTR1Function;
int defaultHealthCalc2(const GameCharacterTR1Function &gamecharacter);

short calcHealth(const GameCharacterTR1Function &);

struct HealthCalculator {
    int operator() (const GameCharacterTR1Function &) {
        return 10;
    }
};

class GameLevel {
public:
    float health(const GameCharacterTR1Function &) {
        return 2.0;
    }
};

class GameCharacterTR1Function {
public:
    typedef std::tr1::function<int (const GameCharacterTR1Function&)> HealthCalcFunc2;

    explicit GameCharacterTR1Function(HealthCalcFunc2 func = defaultHealthCalc2)
        : healthCalc_ (func) {
        }

    int healthValue() const {
        return healthCalc_(*this);
    }

private:
    HealthCalcFunc2 healthCalc_;
};

class BadGuyTR1Function : public GameCharacterTR1Function {
public:
    explicit BadGuyTR1Function(HealthCalcFunc2 func = defaultHealthCalc2)
        : GameCharacterTR1Function(func) {
        }
};

// 4) The "Classic" Strategy Pattern

class GameCharacterStrategy;

class HealthValueCalc {
public:
    virtual int calc(const GameCharacterStrategy &) const {
        return 10;
    }
};

extern HealthValueCalc defaultHealthValue;

class GameCharacterStrategy {
public:
    explicit GameCharacterStrategy(HealthValueCalc *value = &defaultHealthValue)
    : healthCalc_ (value) {

    }

    int healthValue() const {
        return healthCalc_->calc(*this);
    }

private:
    HealthValueCalc *healthCalc_;
};

class BadGuyHealthValueCalc : public HealthValueCalc {
public:
    virtual int calc(const GameCharacterStrategy &) const {
        return 30;
    }
};

#endif // __ITEM35_H__