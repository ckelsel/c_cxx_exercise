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

#ifndef __ITEM9_H__
#define __ITEM9_H__
#include <string>

extern std::string item9_unittest_string;

class TransactionWithVirtual {
    TransactionWithVirtual();

    virtual void LogTransactionWithVirtual() const = 0;

    void Init();
};

class BuyTransactionWithVirtual : public TransactionWithVirtual {
public:
    virtual void LogTransactionWithVirtual() const;
};

/////////////

class Transaction {
public:
    explicit Transaction(const std::string &loginfo);

    // non-virtual
    void LogTransaction(const std::string &loginfo) const;
};

class BuyTransaction : public Transaction {
public:
    BuyTransaction(const std::string &loginfo)
    : Transaction(loginfo) {

    }

    // It is no necessary to declare this function again
    // void LogTransaction(const std::string &loginfo) const;
};

#endif // __ITEM9_H__