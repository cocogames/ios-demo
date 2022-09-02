//
//  CSJLocalStringModel.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/6/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * BULocalLanguageType;

FOUNDATION_EXTERN BULocalLanguageType const CSJLocalJapaneseLanguage;     // 日语
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalEnglishLanguage;      // 英语
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalKoreanLanguage;       // 韩语
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalZHHantLanguage;       // 繁体中文
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalSimplifiedZHLanguage; // 简体中文
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalThaiLanguage;         // 泰语
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalVietnameseLanguage;   // 越南语
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalIndonesianLanguage;   // 印尼语
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalRussianLanguage;      // 俄语
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalArabLanguage;         // 阿拉伯
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalFrenchLanguage;       // 法语
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalGermanLanguage;       // 德语
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalItalyLanguage;        // 意大利
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalSpainLanguage;        // 西班牙
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalHindiLanguage;        // 印第语
FOUNDATION_EXTERN BULocalLanguageType const CSJLocalPortugalLanguage;     // 葡萄牙

@interface CSJLocalStringModel : NSObject

+ (NSDictionary *)localLanguageDic;

+ (BOOL)containsLanguage:(NSString *)language;

+ (BULocalLanguageType)vaildLanguage;

+ (BULocalLanguageType)vaildLanguageUsedForLocalPath;

+ (void)bu_saveForceLanguangeFromServerWithLanguage:(NSString *)language;

+ (BULocalLanguageType)bu_getForceLanguageFromCache;

@end

NS_ASSUME_NONNULL_END
