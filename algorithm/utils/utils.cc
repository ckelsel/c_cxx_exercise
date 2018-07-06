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
#include <regex>

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
    std::fstream in(filepath, std::ios::binary | std::ios::in | std::ios::ate);
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
    std::string content1 = GetFileContent(file1);
    std::string content2 = GetFileContent(file1);

    std::regex_replace(content1, std::regex("\r\n"), "\r");
    std::regex_replace(content2, std::regex("\r\n"), "\r");

    std::cout << "----" << std::endl << file1 << ":" << std::endl;
    std::cout << content1 << std::endl;

    std::cout << "----" << std::endl << file2 << ":" << std::endl;
    std::cout << content2 << std::endl;

    return content1 == content2;
}