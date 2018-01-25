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
#include <windows.h>
#include "utils.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>

std::wstring StringToWString(std::string &s) {
    std::wstring tmp(s.length(), L' ');
    std::copy(s.begin(), s.end(), tmp.begin());
    return tmp;
}

std::string WStringToString(std::wstring &s) {
    std::string tmp(s.length(), ' ');
    std::copy(s.begin(), s.end(), tmp.begin());
    return tmp;
}

std::string GetFileOfCurrentDir(const char *filename) {
    wchar_t module_name[MAX_PATH];
    GetModuleFileName(NULL, module_name, MAX_PATH);
    std::wstring file(module_name);
    std::wstring::size_type last_backslash =
        file.rfind('\\', file.size());
    if (last_backslash != std::wstring::npos) {
        file.erase(last_backslash + 1);
    }
    file.append(StringToWString(std::string(filename)));

    return WStringToString(file);
}


std::string GetFileContent(const char *file) {
    std::string filepath = GetFileOfCurrentDir(file);
    std::fstream in(filepath, std::ios::binary | std::ios::ate);
    if (in.is_open()) {
        auto size = in.tellg();
        std::string str(size, '\0');
        in.seekg(0);
        in.read(&str[0], size);
        in.close();

        return str;
    }

    return "";
}

#define BUFFER_LENGTH 256
bool CompareOutput(const char *file1, const char *file2) {
    std::string f1 = GetFileOfCurrentDir(file1);
    std::string f2 = GetFileOfCurrentDir(file2);

    std::ifstream if1(f1, std::ios::binary);
    if (!if1.is_open()) {
        return false;
    }

    std::ifstream if2(f2, std::ios::binary);
    if (!if2.is_open()) {
        if1.close();
        return false;
    }

    char buf1[BUFFER_LENGTH] = {0};
    char buf2[BUFFER_LENGTH] = {0};

    if1.read(buf1, BUFFER_LENGTH);
    if2.read(buf2, BUFFER_LENGTH);

    if (memcmp(buf1, buf2, BUFFER_LENGTH) != 0) {
        if1.close();
        if2.close();
        return false;
    }

    if1.close();
    if2.close();
    return true;
}