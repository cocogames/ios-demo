//
//  BUSKAdNetworkModel.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/8/13.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CSJAdSKAdImpressionProtocol <NSObject>
/// The App Store item identifier for the source app.
@property (nonatomic, strong) NSNumber *sourceAppStoreItemIdentifier;
/// The App Store item identifier for the app being advertised.
@property (nonatomic, strong) NSNumber *advertisedAppStoreItemIdentifier;
/// The identifier for the ad network.
@property (nonatomic, strong) NSString *adNetworkIdentifier;
/// The ad campaign identifier.
@property (nonatomic, strong) NSNumber *adCampaignIdentifier;
/// The nonce used to generate the signature.
@property (nonatomic, strong) NSString *adImpressionIdentifier;
/// The type of ad being presented.
@property (nonatomic, strong, nullable) NSString *adType;
/// The description of the ad.
@property (nonatomic, strong, nullable) NSString *adDescription;
/// Name of entity that purchased the ad being presented.
@property (nonatomic, strong, nullable) NSString *adPurchaserName;
/// The timestamp of the start and end call.
@property (nonatomic, strong) NSNumber *timestamp;
/// The signature of the impression.
@property (nonatomic, strong) NSString *signature;
/// The version of SKAdNetwork being used.
@property (nonatomic, strong) NSString *version;
@end

// network id, string
extern NSString *const CSJSKAdNetworkIdentifier;

// version 1.0 | 2.0 ,string
extern NSString *const CSJSKAdNetworkVersion;

// compaign id, string
extern NSString *const CSJSKAdNetworkCampaignToken;

// app id, string
extern NSString *const CSJSKAdNetworkITunesItemIdentifier;

// nonce NSUUID
extern NSString *const CSJSKAdNetworkNonce;

// source app id, string
extern NSString *const CSJSKAdNetworkSourceAppStoreIdentifier;

// timestamp, unit ms, number
extern NSString *const CSJSKAdNetworkTimestamp;

// signature, string
extern NSString *const CSJSKAdNetworkSignature;

@interface CSJSKANStoreProductModel : NSObject <NSCoding>

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (nullable NSDictionary *)dictionaryValue;

- (NSString *)skanInfoSearalizaitonValue;

@property (nonatomic, strong) NSNumber *itunce_item_id;

@property (nonatomic, copy) NSString *version;

@property (nonatomic, copy) NSString *ad_network_id;

@property (nonatomic, strong) NSNumber *campaign_id;

@property (nonatomic, strong) NSNumber *source_app_id;

@property (nonatomic, copy) NSString *nonce;

@property (nonatomic, strong) NSNumber *timestamp;

@property (nonatomic, copy) NSString *signature;

@property (nonatomic, assign, readonly, getter=isValid) BOOL valid;

@end


extern NSString *const CSJSKAdNetworkADCampaignID;
extern NSString *const CSJSKAdNetworkAdvertisedAppID;
extern NSString *const CSJSKAdNetworkADImpressionID;
extern NSString *const CSJSKAdNetworkImpressionSignature;

@interface CSJSKANADImpressionModel : NSObject <NSCoding>
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@property (nonatomic, copy) NSString *version;

@property (nonatomic, copy) NSString *ad_network_id;

@property (nonatomic, strong) NSNumber *ad_campaign_id;

@property (nonatomic, strong) NSNumber *advertised_app_id;

@property (nonatomic, copy) NSString *ad_impression_id;

@property (nonatomic, strong) NSNumber *source_app_id;

@property (nonatomic, strong) NSNumber *timestamp;

@property (nonatomic, copy) NSString *signature;

@property (nonatomic, assign, readonly, getter=isValid) BOOL valid;

@property (nonatomic, strong) NSObject<CSJAdSKAdImpressionProtocol> *adImpression;

@end

@interface CSJSKANADImpressionObject : NSObject <NSCoding>

@property (atomic, strong) NSDate * __nullable impressionDate;

@property (nonatomic, strong) CSJSKANADImpressionModel *skan_Impression_item;
//
//@property (nonatomic, strong) NSObject *adImpression API_AVAILABLE(ios(14.5));

@end


NS_ASSUME_NONNULL_END
