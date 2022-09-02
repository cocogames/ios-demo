//
//  CSJ_App.h
//  Article
//
//  Created by muhuai on 2017/5/19.
//
//

#import <Foundation/Foundation.h>




@interface CSJ_App : BUDynamicPlugin

BU_EXPORT_HANDLER(isAppInstalled)
BU_EXPORT_HANDLER(copyToClipboard)
BU_EXPORT_HANDLER(appInfo)
BU_EXPORT_HANDLER(config)


#pragma mark - Class Method
+ (NSDictionary *)appInfoDictionary;

@end
