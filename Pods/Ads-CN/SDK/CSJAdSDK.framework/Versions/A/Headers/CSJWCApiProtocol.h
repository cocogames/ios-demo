//
//  CSJWCApiProtocol.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/6/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*! @brief 打印回调的block
 *
 */
typedef void(^CSJWCApiLogBolock)(NSString *log);

@protocol CSJWCApiProtocol <NSObject>
@optional
/*! @brief WXApi的成员函数，向微信终端程序注册第三方应用。
 *
 * 需要在每次启动第三方应用程序时调用。
 * @attention 请保证在主线程中调用此函数
 * @param appid 微信开发者ID
 * @param universalLink 微信开发者Universal Link
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)registerApp:(NSString *)appid universalLink:(NSString *)universalLink;


/*! @brief 获取当前微信SDK的版本号
 *
 * @return 返回当前微信SDK的版本号
 */
+ (NSString *)getApiVersion;


/*! @brief 发送请求到微信，等待微信返回onResp
 *
 * 函数调用后，会切换到微信的界面。第三方应用程序等待微信返回onResp。微信在异步处理完成后一定会调用onResp。支持以下类型
 * SendAuthReq、SendMessageToWXReq、PayReq等。
 * @param req 具体的发送请求。
 * @param completion 调用结果回调block
 */
+ (void)sendReq:(id)req completion:(void (^ __nullable)(BOOL success))completion;

+ (id)object;

/*! @brief WXApi的成员函数，接受微信的log信息。byBlock
    注意1:SDK会强引用这个block,注意不要导致内存泄漏,注意不要导致内存泄漏
    注意2:调用过一次startLog by block之后，如果再调用一次任意方式的startLoad,会释放上一次logBlock，不再回调上一个logBlock
 *
 *  @param level 打印log的级别
 *  @param logBlock 打印log的回调block
 */

+ (void)startLogByLevel:(NSInteger)level logBlock:(CSJWCApiLogBolock)logBlock;

/** 小程序username */
@property (nonatomic, copy) NSString *userName;

/** 小程序页面的路径
 * @attention 不填默认拉起小程序首页
 */
@property (nonatomic, copy, nullable) NSString *path;

/** 分享小程序的版本
 * @attention （0:正式，1:开发，2:体验）
 */
@property (nonatomic, assign) NSUInteger miniProgramType;

@end

NS_ASSUME_NONNULL_END
