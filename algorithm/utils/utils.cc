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

std::wstring StringToWString(std::string &s) {
    std::wstring tmp(s.length(), L' ');
    std::copy(s.begin(), s.end(), tmp.begin());
    return tmp;
}

std::wstring GetFileOfCurrentDir(const char *filename) {
    wchar_t module_name[MAX_PATH];
    GetModuleFileName(NULL, module_name, MAX_PATH);
    std::wstring file(module_name);
    std::wstring::size_type last_backslash =
        file.rfind('\\', file.size());
    if (last_backslash != std::wstring::npos) {
        file.erase(last_backslash + 1);
    }
    file.append(StringToWString(std::string(filename)));

    return file;
}