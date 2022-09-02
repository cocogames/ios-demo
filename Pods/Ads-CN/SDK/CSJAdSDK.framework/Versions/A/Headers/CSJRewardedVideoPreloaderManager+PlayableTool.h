//
//  CSJRewardedVideoPreloaderManager+PlayableTool.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/7/23.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "CSJRewardedVideoPreloaderManager.h"
#import "CSJMaterialMeta.h"

@interface CSJRewardedVideoPreloaderManager (PlayableTool)

- (BOOL)needHandelPlayableTool;

- (void)handelPlayableToolWithSlot:(CSJAdSlot *)slot sucess:(successGetMateria)success failure:(failureGetMateria)failure successLoadVideo:(successLoadVideo)videoSucess;

- (void)logUse_playable_test_tool_error:(NSError *)error url:(NSString *)url;

@end

