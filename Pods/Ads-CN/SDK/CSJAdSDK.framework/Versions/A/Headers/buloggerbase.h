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
 ============================================================================
 ============================================================================
 */

#ifndef BU_ALOG_XLOGGERBASE_H_
#define BU_ALOG_XLOGGERBASE_H_

#include <sys/time.h>
#include <time.h>
#include <stdarg.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    kBUALogAll = 0,
    kBUALogVerbose = 0,
    kBUALogDebug = 1,    // Detailed information on the flow through the system.
    kBUALogInfo = 2,     // Interesting runtime events (startup/shutdown), should be cautious and keep to a minimum.
    kBUALogWarn = 3,     // Other runtime situations that are undesirable or unexpected, but not necessarily "wrong".
    kBUALogError = 4,    // Other runtime errors or unexpected conditions.
    kBUALogFatal = 5,    // Severe errors that cause premature termination.
    kBUALogNone = 10000,     // Special level used to disable all log messages.
} kBUALogLevel;

typedef enum {
    kBUALogFileManagerTypeCentralized,//集中式，所有log存在同一个directory下
    kBUALogFileManagerTypeDistributed,//分布式，log根据level存在对应level的directory下
}kBUALogFileManagerType;
    
typedef struct BULoggerInfo_t {
    kBUALogLevel level;
    const char* tag;
    const char* filename;
    const char* func_name;
    int line;

    struct timeval timeval;
    intmax_t pid;
    intmax_t tid;
    intmax_t maintid;
} BULoggerInfo;

    
extern intmax_t bulogger_pid(void);
extern intmax_t bulogger_tid(void);
extern intmax_t bulogger_maintid(void);
typedef void (*bulogger_appender_t)(const BULoggerInfo* _info, const char* _log);
extern const char* bulogger_dump(const void* _dumpbuffer, size_t _len);

//kBUALogLevel   bulogger_Level();
void bulogger_SetLevel(kBUALogLevel _level);
int  bulogger_IsEnabledFor(kBUALogLevel _level);
bulogger_appender_t bulogger_SetAppender(bulogger_appender_t _appender);

// no level filter
#ifdef __GNUC__
__attribute__((__format__(printf, 2, 0)))
#endif
void        bulogger_VPrint(const BULoggerInfo* _info, const char* _format, va_list _list);
#ifdef __GNUC__
__attribute__((__format__(printf, 2, 3)))
#endif
void        bulogger_Print(const BULoggerInfo* _info, const char* _format, ...);
void        bulogger_Write(const BULoggerInfo* _info, const char* _log);

#ifdef __cplusplus
}
#endif

#endif
