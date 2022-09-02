//
//  CSJDynamicSDKAnalysisParser.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/6/18.
//

#import <Foundation/Foundation.h>
#import "CSJAdInfoViewModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicSDKAnalysisParser : NSObject

@property (nonatomic, strong) NSError *error;


- (NSDictionary *)h5_getLayoutInfo_dicitionary:(NSDictionary *)dict infoViewModel:(CSJAdInfoViewModel *)infoViewModel defaultDict:(NSDictionary *)defaultDict;

@end

NS_ASSUME_NONNULL_END
