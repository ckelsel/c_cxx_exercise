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

    printf("char ch = 'a';\n");
    printf("\n");

    printf("[lvalue]\n");
    printf("ch = 'b';\n");
    printf("ch: %p\n", &ch);
    printf("lvalue: 0x%p -> address of ch\n", &ch);
    printf("\n");

    printf("[rvalue]\n");
    printf("char tmp = ch;\n");
    printf("ch: %c\n", ch);
    printf("rvalue: %c -> value of ch\n", ch);
    printf("\n");
}

void _ch()
{
    char ch = 'a';

    // &ch actor as rvalue
    char *cp = &ch;

    printf("char ch = 'a';\n");
    printf("\n");

    // address of &ch is undefined
    printf("lvalue: None\n");
    printf("\n");

    printf("char *cp = &ch;\n");
    printf("rvalue: %p -> address of &ch\n", &ch);
    printf("\n");
}

void cp()
{
    char ch = 'a';
    char *cp = &ch;

    printf("char ch = 'a';\n");
    printf("char *cp = &ch;\n");
    printf("\n");

    printf("ch: %p\n", &ch);
    printf("lvalue: %p -> address of ch\n", cp);
    printf("\n");

    char **cpp = &cp;
    printf("cpp: %p\n", cpp);
    printf("rvalue: %p -> address of cp\n", &cp);
    printf("\n");
}