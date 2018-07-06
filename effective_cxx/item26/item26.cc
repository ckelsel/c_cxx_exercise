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
#include "item26.h"
#include <stdexcept>

std::string encryptPasswordInsufficient(const std::string password) {
    std::string encrypted;

    if (password.length() <= 0) {
        // 1. paid for ctor and dtor if throw error
        throw std::logic_error("password is too short");
    }

    // 2. paid for copy assigned
    encrypted = password;

    return encrypted;
}

std::string encryptPassword(const std::string password) {
    if (password.length() <= 0) {
        throw std::logic_error("password is too short");
    }

    std::string encrypted(password);

    return encrypted;
}