//
//  platform.h
//  BUEfficientLog
//
//  Created by hopo on 2018/8/29.
//

#import <Foundation/Foundation.h>
#include "buloggerbase.h"

void bu_logger_external_callback(const BULoggerInfo* _info, const char* _log, bool is_log_console);

const char* bu_appID();
