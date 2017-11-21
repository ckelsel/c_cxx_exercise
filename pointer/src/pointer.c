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

// 1) ... = ch;   -> value，取值
// 2) ch  = ...;  -> address, 给地址赋值
// 3) ... = &ch;  -> address
// 4) &ch = ...;  -> illegal
// -->> 2) and 3) are both get address
void ch()
{
    L_ENTER("ch");

    char ch = 'a';

    printf("char ch = 'a';\n");
    printf("\n");

    // ... = ch;
    printf("[rvalue]\n");
    printf("char tmp = ch;\n");
    printf("ch: %c\n", ch);
    printf("rvalue: %c -> value of ch\n", ch);
    printf("\n");

    // ch = ...;
    printf("[lvalue]\n");
    printf("ch = 'b';\n");
    printf("ch: 0x%p\n", &ch);
    printf("lvalue: 0x%p -> address of ch\n", &ch);
    printf("\n");
}

// ... = &ch;  -> address of ch
// &ch = ...;  -> illegal
void _ch()
{
    L_ENTER("&ch");

    char ch = 'a';

    // &ch actor as rvalue
    char *cp = &ch;

    printf("char ch = 'a';\n");
    printf("\n");

    // ... = &ch;
    printf("char *cp = &ch;\n");
    printf("rvalue: 0x%p -> address of ch\n", &ch);
    printf("\n");

    // address of &ch is undefined
    // &ch = ...;
    printf("lvalue: illegal\n");
    printf("\n");
}

// 右值：值
// 左值：地址
void cp()
{
    L_ENTER("cp");

    char ch = 'a';
    char *cp = &ch;

    printf("char ch = 'a';\n");
    printf("char *cp = &ch;\n");
    printf("\n");

    // ... = cp;
    char *cp2 = cp;
    printf("char *cp2 = cp;\n");
    printf("cp2: 0x%p\n", cp2);
    printf("cp: 0x%p\n", cp);
    printf("&ch: 0x%p\n", &ch);
    printf("rvalue: 0x%p -> address of cp\n", cp);
    printf("\n");

    // cp = ...;
    printf("&cp: 0x%p\n", &cp);
    printf("lvalue: 0x%p -> address of cp\n", &cp);
    printf("\n");
}

void _cp()
{
    L_ENTER("&cp");

    char ch = 'a';
    char *cp = &ch;

    printf("&ch: 0x%p\n", &ch);
    printf("rvalue cp: 0x%p\n", cp);
    printf("\n");

    // char **cpp = &cp;
    char **cpp = &cp;
    printf("&cp: 0x%p\n", &cp);
    printf("rvalue: 0x%p\n", cpp);
    printf("\n");

    // &cp = ...;
    // &cp actor as lvalue is illegal
    printf("lvalue: illegal\n");
    printf("\n");
}

void x_cp()
{
    L_ENTER("*cp");

    char ch = 'a';
    char *cp = &ch;

    // *cp -> *&ch -> ch
    // ... = *cp;
    printf("rvalue: *cp = %c\n", *cp);
    printf("\n");

    // *cp -> *&ch -> ch
    // *cp = ...;
    *cp = 'b';
    printf("a -> %c\n", *cp);
    printf("lvalue: 0x%p\n", &ch);
    printf("\n");
}

void x_cp_add_1()
{
    L_ENTER("*cp + 1");

    char ch = 'a';
    char *cp = &ch;

    // *cp -> *&ch -> ch
    // ... = *cp + 1;
    printf("rvalue: *cp + 1 = %c\n", *cp + 1);
    printf("\n");

    // *cp -> *&ch -> ch
    // *cp + 1 = ...;
    printf("lvalue: illegal\n");
    printf("\n");
}
