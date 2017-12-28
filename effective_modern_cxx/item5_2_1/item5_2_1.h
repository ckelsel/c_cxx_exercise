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

#ifndef __ITEM_5_2_1_H__
#define __ITEM_5_2_1_H__
// std::shared_ptr

#include <Windows.h>

#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <cstdio>

class FileDeleter {
public:
    explicit FileDeleter(const std::string &in) :name_(in) {
    }

    // why override ()?
    void operator() (std::ofstream *fp) {
        std::cout << "delete file " << std::endl;
        fp->close();
        std::remove(name_.c_str());
    }

    // NOTE:: need follow ctor
    //void operator=(const FileDeleter &);

private:
    std::string name_;    
};

class ShareMemory {
public:
    ShareMemory(int size) : handle_(NULL), buffer_(NULL) {
        handle_ = CreateFileMapping(INVALID_HANDLE_VALUE,    // use paging file
                                    NULL,                    // default security
                                    PAGE_READWRITE,          // read/write access
                                    0,                       // maximum object size (high-order DWORD)
                                    size,                // maximum object size (low-order DWORD)
                                    L"share_memory");                 // name of mapping object

        if (handle_ != NULL) {
            buffer_ = (char *) MapViewOfFile(handle_,   // handle to map object
                                            FILE_MAP_ALL_ACCESS, // read/write permission
                                            0,
                                            0,
                                            size);
            if (buffer_ == NULL) {
                CloseHandle(handle_);
                handle_ = NULL;
            }
        }
    }

    char* GetBuffer() {
        return buffer_;
    }

    ~ShareMemory() {
        if (buffer_ != NULL) {
            UnmapViewOfFile(buffer_);
        }

        if (handle_ != NULL) {
            CloseHandle(handle_);
        }
    }

private:
    ShareMemory(const ShareMemory &);
    void operator=(const ShareMemory &);

    HANDLE handle_;
    char *buffer_;
};

#endif // __ITEM_5_2_1_H__