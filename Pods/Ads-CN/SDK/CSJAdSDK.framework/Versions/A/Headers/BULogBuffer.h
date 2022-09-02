// Tencent is pleased to support the open source community by making Mars available.
// Copyright (C) 2016 THL A29 Limited, a Tencent company. All rights reserved.

// Licensed under the MIT License (the "License"); you may not use this file except in 
// compliance with the License. You may obtain a copy of the License at
// http://opensource.org/licenses/MIT

// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
// either express or implied. See the License for the specific language governing permissions and
// limitations under the License.

/*
 * log_buffer.h
 *
 *  Created on: 2015-7-28
 *      Author: yanguoyue
 */

#ifndef BU_LOGBUFFER_H_
#define BU_LOGBUFFER_H_

#include <zlib.h>
#include <string>
#include <stdint.h>

#include "BUPtrBuffer.h"
#include "BUAutoBuffer.h"

class BULogCrypt;

class BULogBuffer {
public:
    BULogBuffer(void* _pbuffer, size_t _len, bool _is_compress, const char* _pubkey);
    ~BULogBuffer();
    
public:
    static bool GetPeriodLogs(const char* _log_path, int _begin_hour, int _end_hour, unsigned long& _begin_pos, unsigned long& _end_pos, std::string& _err_msg);

public:
    BUPtrBuffer& GetData();
    
    void Flush(BUAutoBuffer& _buff);
    bool Write(const void* _data, size_t _inputlen, BUAutoBuffer& _out_buff);
    bool Write(const void* _data, size_t _length);
    const char * First_log_Date(const void* _data, char* _log_date);
private:
    
    bool __Reset();
    void __Flush();
    void __Clear();
    
    void __Fix();

private:
    BUPtrBuffer buff_;
    bool is_compress_;
    z_stream cstream_;
    
    class BULogCrypt* log_crypt_;
    size_t remain_nocrypt_len_;

};


#endif /* LOGBUFFER_H_ */
