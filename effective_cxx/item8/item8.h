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
#ifndef __ITEM8_H__
#define __ITEM8_H__
#include <iostream>

class DBConnection {
public:
    static DBConnection& Create();

    // close connection;
    // throw an exception if closing failed
    void Close();

    ~DBConnection() {}

private:
    DBConnection() {}
};

#define LOG_FATAL(...)

class DBConn {
public:

    DBConn(const DBConnection &db) : db_ (db) 
                            , close_ (false) {}

    ~DBConn() {
        if (!close_) {
            try {
                db_.Close();
            } catch(...) {
                LOG_FATAL("Close DBConnection failed");
                std::abort();
            }
        }
    }

    // close connection;
    // throw an exception if closing failed
    void Close() {
        db_.Close();
        // Close always throw exception, close_ is always false
        close_ = true;
    }

    void SetClose(bool close) {
        close_ = close;
    }
private:
    DBConnection db_;

    bool close_;
};

#endif // __ITEM8_H__