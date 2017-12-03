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
#include <vector>
#include "item3.h"


char hello[] = "hello";

char greeting[] = "greeting";

char *non_const = greeting;

const char *const_data = greeting;

char * const const_pointer = greeting;

const char * const const_pointer_const_data = greeting;

// char *non_const = hello;
// non_const = ..; -> change pointer
// *non_const = ..; -> change data
void pointer_test()
{
    // change pointer
    non_const++;
    non_const = hello;
    // change data
    *non_const = 'a';


    const_data++;
    const_data = hello;
    //*const_data = 'a';


    // const pointer can't be changed
    // const_pointer++;
    // const_pointer = hello;
    *const_pointer = 'a';


    // const_pointer_const_data++;
    // const_pointer_const_data = hello;
    // *const_pointer_const_data = 'a';
}

void vector_test()
{
    std::vector<int> vec;
    vec.push_back(0);

    // T * const iter = vec.begin();
    const std::vector<int>::iterator const_pointer = vec.begin();
    *const_pointer = 1;
    // const_pointer++;

    std::vector<int>::const_iterator const_data = vec.begin();
    //*const_data = 1;
    const_data++;
}

void item3_test()
{
    pointer_test();

    vector_test();
}