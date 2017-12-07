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
#include <iostream>
#include "item9.h"

std::string item9_unittest_string;

TransactionWithVirtual::TransactionWithVirtual() {
    Init();
    LogTransactionWithVirtual();
}

void TransactionWithVirtual::Init() {
    LogTransactionWithVirtual();
}

void TransactionWithVirtual::LogTransactionWithVirtual() const {
    item9_unittest_string = "TranscationWithVirtual";
    std::cout << item9_unittest_string << std::endl;
}

void BuyTransactionWithVirtual::LogTransactionWithVirtual() const {
    item9_unittest_string = "BuyTranscationWithVirtual";
    std::cout << item9_unittest_string << std::endl;
}

////////////////////

Transaction::Transaction(const std::string &loginfo) {
    LogTransaction(loginfo);
}

void Transaction::LogTransaction(const std::string &loginfo) const {
    item9_unittest_string = loginfo;
    std::cout << item9_unittest_string << std::endl;
}