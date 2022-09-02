//
//  BUAlog_.hpp
//  BUEfficientLog
//
//  Created by hopo on 2018/9/5.
//

#ifndef BUAlog_hpp
#define BUAlog_hpp

#include <stdio.h>
#include "buloggerbase.h"
#include <stdbool.h>

#ifdef __cplusplus
#include <string>
#include <vector>
#endif

#ifdef __FILE_NAME__
#define __BUALOG_FILE_NAME__ __FILE_NAME__
#else
#define __BUALOG_FILE_NAME__ __FILE__
#endif

#if !defined(BU_NO_TAIL_CALL)
#if __has_attribute(not_tail_called)
#define BU_NO_TAIL_CALL __attribute__((not_tail_called))
#else
#define BU_NO_TAIL_CALL
#endif
#endif

#ifdef __OBJC__
#import<Foundation/Foundation.h>

#define BUNSCHAR(format, ...) ([[NSString stringWithFormat:format, ##__VA_ARGS__, nil] UTF8String])

#pragma mark -  OC Method and its usage is same as 'NSLog'

//自定义level和tag
#define BUALog(level, tag, format, ...)\
@autoreleasepool {BU_ALOG(level, [tag UTF8String], BUNSCHAR(format, ##__VA_ARGS__))};

#endif


#ifdef __cplusplus
extern "C" {
#endif
    
#pragma mark - C and C++

#define BU_ALOG(_level, _tag, _format, ...)\
do{\
struct timeval tv;\
gettimeofday(&tv, NULL);\
BULoggerInfo _info;\
_info.filename = __BUALOG_FILE_NAME__;\
_info.tag = _tag;\
_info.level = _level;\
_info.line = __LINE__;\
_info.func_name = __FUNCTION__;\
_info.timeval = tv;\
_bu_alog_write_macro(&_info, _format, ##__VA_ARGS__);\
}while(0);\

#define BU_ALOG_C(_level, _tag, _format, ...)\
do{\
struct timeval tv;\
gettimeofday(&tv, NULL);\
BULoggerInfo _info;\
_info.filename = __BUALOG_FILE_NAME__;\
_info.tag = _tag;\
_info.level = _level;\
_info.line = __LINE__;\
_info.func_name = __FUNCTION__;\
_info.timeval = tv;\
bu_alog_write(&_info, _format, ##__VA_ARGS__);\
}while(0);\
    
    /**
     自定义初始化alog，如加密使用默认key pair加密

     @param _dir log文件存储路径
     @param _nameprefix log文件文件名前缀
     @param _maxsize 文件缓存最大值 e.g 50M = 50 *1024 *1024（byte）
     @param _outdate 文件有效期 e.g.七天 = 7 *24 *60 *60(s)
     */
    void bu_alog_open(const char* _dir, const char* _nameprefix, long long _maxsize, double _outdate);

    /**
     写入log

     @param _info log信息
     @param _format log内容
     */
    void bu_alog_write(const BULoggerInfo* _info, const char* _format, ...) BU_NO_TAIL_CALL;
        
    /**
     设置log level，低于该level的log不写入文件

     @param _level log level
     */
    void bu_alog_set_log_level(kBUALogLevel _level);

    /**
     异步将log flush到目标文件
     */
    void bu_alog_flush(void);

    /**
     同步将log flush到目标文件
     */
    void bu_alog_flush_sync(void);

    /**
     关闭alog，一般在-applicationWillTerminate调用
     */
    void bu_alog_close(void);
    
#ifdef __cplusplus
    /**
     * 获取某个时间段文件，time interval必须是UTC时间
     * fromTimeInterval = 0 & toTimeInterval > 0时返回toTimeInterval这个时间点之前的所有文件（0表示无边界）
     * toTimeInterval = 0 & fromTimeInterval > 0时返回从fromTimeInterval这个时间点之后的所有文件（0表示无边界）
     * toTimeInterval = 0 & fromTimeInterval = 0时返回所有文件（0表示无边界）
     
     @param fromTimeInterval 起始时间 e.g.三天前[NSDate dateWithTimeIntervalSince1970:[NSDate date].timeIntervalSince1970 - 3 *24 *60 * 60].timeIntervalSince1970
     @param toTimeInterval 结束时间
     @param _filepath_vec 文件列表，返回文件列表是根据文件创建时间排好序列表，列表第一个即为所传时间段内最近生成文件
     */
    void bu_alog_getFilePaths(long long fromTimeInterval, long long toTimeInterval, std::vector<std::string>& _filepath_vec);
#endif
    
    /**
     使用宏定义时必须调用此方法，否则可能会由于格式问题导致crash

     @param _info log信息
     @param _format log 内容
     @param ... 可变参数
     */
    void _bu_alog_write_macro(const BULoggerInfo* _info,const char* _format, ...);//__attribute__((sentinel));
    
#ifdef __cplusplus
} // extern "C"
#endif

#endif /* BUAlog__hpp */
