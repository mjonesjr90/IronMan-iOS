//
//  MMSmartYield.h
//  MMAdSDK
//
//  Created by Fedor Kudrys on 8/1/17.
//  Copyright © 2017 Millennial Media. All rights reserved.
//

#import <MMAdSDK/MMAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const MMDemandSourceClientDemandType;
extern NSString * const MMDemandSourceServerDemandType;
extern NSString * const MMDemandSourceContentType;

extern NSString * const MMSmartYieldDemandNotification;
extern NSString * const MMSmartYieldShownNotification;
extern NSString * const MMDemandSourceCallbackKey;

// Keys to the MMAdWrapperSmartYield / MMSmartYieldController parameter info
// keywords and their reespective value types.
extern NSString * const kSmartYieldKeywords;    // NSDictionary<NSString *, id>
extern NSString * const kSmartYieldKeywordBidPriceKey;  // NSString

// If placement is nil, then error should hold a valid result.
typedef void(^MMSmartYieldDemandSourceCallback)(MMAd * _Nullable placement, UIView * _Nullable demandSourceAdView, id smartYieldContext, NSError * _Nullable error);

@interface MMAd (SmartYield)

@property (nonatomic) BOOL smartYieldWin;

@end

NS_ASSUME_NONNULL_END
