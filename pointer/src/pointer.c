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

#include <stdio.h>
#include "pointer.h"


#define L_ENTER(m)              \
    do {                        \
        printf("=========\n");    \
        printf("    %s\n", m);    \
        printf("=========\n");    \
    } while (0)

#define L_LEAVE()               \
    do {                        \
        printf("         \n");    \
        printf("         \n");    \
    } while (0)

void ch()
{
    char ch = 'a';

    printf("lvalue: 0x%p\n", &ch);
    printf("rvalue: %c\n", ch);
}

void cp()
{
    char ch = 'a';
    char *cp = &ch;
}