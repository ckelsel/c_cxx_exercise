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

#ifndef __ITEM_3_1_10_H__
#define __ITEM_3_1_10_H__
//https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11

//Lambda Expressions in C++
//https://msdn.microsoft.com/en-us/library/dd293608.aspx

// 3.1.10 Lambdas

// Cxx98
#include <algorithm>
#include <vector>

namespace {
    struct f{
        void operator()(int &v) {
           v = -v; 
        }
    };
};

void func(std::vector<int> &v) {
    f f;
    std::for_each(v.begin(), v.end(), f);
}

// Cxx11 Lambda
void func3(std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int &v) { v = -v; });
}

// Cxx11 Lambda
// Return types
// ->double
void func4(std::vector<double> &v) {
    std::transform(v.begin(), v.end(), v.begin(),
                   [](double d) -> double {
                       if (d < 0.00001) {
                           return 0;
                       } else {
                           return d;
                       }
                   });
}

// Cxx11 Lambda
// "Capturing" variables
// epsilon
void func5(std::vector<double> &v, const double &epsilon) {
    std::transform(v.begin(), v.end(), v.begin(),
                   [epsilon](double d) ->double {
                       if (d < epsilon) {
                           return 0;
                       } else {
                           return d;
                       }
                   });
}
#endif // __ITEM_3_1_10_H__