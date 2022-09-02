//
//  CSJPlayerTimeObserverModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2022/2/23.
//

#import <Foundation/Foundation.h>
#import "CSJAdInfoViewModel.h"



NS_ASSUME_NONNULL_BEGIN

@interface CSJPlayerTimeObserverModel : NSObject

@property (nonatomic, strong) BUPlayer *player;
@property (nonatomic, strong) CSJAdInfoViewModel *infoViewModel;


- (void)executeDynamicJsonTypeLogic;

@end

NS_ASSUME_NONNULL_END
