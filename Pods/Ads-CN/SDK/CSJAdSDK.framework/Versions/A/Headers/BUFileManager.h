//
//  file_manager.hpp
//  BUEfficientLog
//
//  Created by hopo on 2018/9/2.
//

#ifndef bu_alog_file_manager_hpp
#define bu_alog_file_manager_hpp

#include <stdio.h>
#ifdef __cplusplus
#include <string>
#endif /* __cplusplus */
#include "BULoggerManager.hpp"
#include <mutex>

//#ifdef __cplusplus
//extern "C" {
//#endif

void bu_logger_fileName(const timeval& _tv, const std::string& _logdir, const char* _prefix, const std::string& _fileext, char* _filepath, unsigned int _len, bool _newfile, const char * _file_date);
void bu_logger_getFilePaths_(long long fromTimeInterval, long long toTimeInterval, const std::string& _logdir, const char* _prefix, const std::string& _fileext, std::vector<std::string>& _filepath_vec);
void bu_logger_cleanLogIfNeed(kBUALogFileManagerType _file_manager_type, long long _maxsize, double outdateTimeInterval, const std::string& _logdir, const char* _prefix, const std::string& _fileext, pthread_mutex_t& _mutex);
void bu_logger_remove_file(const std::string& _filename, pthread_mutex_t& _mutex);
void bu_logger_find_mmap2_suffix(const char* _logdir, char* _mmap_path, bool& _mmap_cache, char* _old_mmap_path, std::string& _aid, pthread_mutex_t& _mutex);

std::string __bu_make_logfilenameprefix(const timeval& _tv, const char* _prefix, const char * filename_date);
std::string __bu_get_next_fileindex(const timeval& _tv, const std::string& _logdir, const std::string& _fileprefix, const std::string& _fileext, bool _newfile,const char * _file_date);
uint64_t __bu_max_file_size();
void __bu_get_filenames_by_prefix(const std::string& _logdir, const std::string& _fileprefix, const std::string& _fileext, std::vector<std::string>& _filename_vec);
long long __bu_sortedFilePaths(const std::string& _logdir, const std::string& _fileprefix, const std::string& _fileext, bool _filter, std::vector<std::string>& _filename_vec);
bool __bu_startsWith(const std::string& str, const std::string& substr);
bool __bu_endsWith(const std::string& str, const std::string& substr);
long __bu_filenameIndex(const std::string& _filename, const std::string& _fileprefix, const std::string& _fileext);
//#ifdef __cplusplus
//} // extern "C"
//#endif

#endif /* file_manager_hpp */
