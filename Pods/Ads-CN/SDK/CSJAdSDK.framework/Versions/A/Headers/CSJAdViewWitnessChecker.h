//
//  CSJAdViewWitnessChecker.h
//  CSJAdSDK
//
//  Created by chenren on 21/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJAdSDKDefines+Private.h"
#import "CSJViewTracker.h"

@interface CSJAdViewWitnessChecker : NSObject

+ (instancetype)sharedInstance;

+ (NSTimeInterval)getWitnessTimeForAd:(id<CSJAd>)materialMeta;

+ (void)setWitnessTimeForAd:(id<CSJAd>)materialMeta;

- (void)removeAd:(id<CSJAd>)ad;

- (void)addViewTracker:(id<CSJViewTracker>)tracker;

@end

