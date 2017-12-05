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

#ifndef __ITEM6_H__
#define __ITEM6_H__

#define DISALLOW_COPY_AND_ASSIGN(cls) \
    cls(const cls &);                 \
    cls& operator=(const cls &)

class HomeForSale {
public:
    HomeForSale() {}

private:
    DISALLOW_COPY_AND_ASSIGN(HomeForSale);
};

class Uncopyable {
public:
    Uncopyable() {}
    ~ Uncopyable() {}
private:
    Uncopyable(const Uncopyable &);
    Uncopyable& operator=(const Uncopyable &);
};
#endif // __ITEM6_H__