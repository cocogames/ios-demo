//
//  SSURLTracker.h
//  Article
//
//  Created by Zhang Leonardo on 13-4-2.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol CSJAd;

@interface CSJURLTracker : NSObject

+ (instancetype)shareURLTracker;

- (void)trackURL:(NSString *)urlString;
- (void)trackURLs:(NSArray<NSString *> *)URLs;

- (void)trackURL:(NSString *)urlString model:(id<CSJAd>)adBaseModel;
- (void)trackURLs:(NSArray<NSString *> *)URLs model:(id<CSJAd>)adBaseModel;

@end
