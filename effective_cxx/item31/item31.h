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

#ifndef __ITEM31_H__
#define __ITEM31_H__
//Item31: Minimize compilation dependencies between files.

#include <memory>
#include <string>


// forward decl
class PersionImpl;

class Persion {
public:
    Persion(const std::string &name) : name_(name){

    }

private:
    std::string name_;

    std::tr1::shared_ptr<PersionImpl> impl_;
};

#endif // __ITEM31_H__