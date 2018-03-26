//
//  MMHandshakeResponse.h
//  MMAdSDK
//
//  Created by Tom Poland on 11/2/15.
//  Copyright © 2015 Millennial Media. All rights reserved.
//
//  IMPORTANT: The Apps Team must be notified if the content of this file or any of the referenced headers changes.
//
//  This header and those referenced in the MMAdSDK+TestAppInterface folder define for the formal interface to MMAdSDK that is available to the Test App.
//
//  This confluence page provides background documentation and has a link to MMAdSDK git repo master version of the MMAdSDK+TestAppInterface folder:
//  https://confluence.corp.millennialmedia.com/pages/viewpage.action?spaceKey=SCRUM&title=MMAdSDK+Test+App+Interface

#import <Foundation/Foundation.h>

@class MMHandshakeNativeAdConfig;
@class MMHandshakePlaylistServer;

extern NSString *const kMMHandshakeResponseReportingBatchFrequency;
extern NSString *const kMMHandshakeResponseNativeAdConfig;
extern NSString *const kMMHandshakeResponseHandshakeVersion;
extern NSString *const kMMHandshakeResponseReportingBatchSize;
extern NSString *const kMMHandshakeResponseHandshakeTtl;
extern NSString *const kMMHandshakeResponsePlaylistServer;
extern NSString *const kMMHandshakeResponseMinInlineRefreshRate;
extern NSString *const kMMHandshakeResponseInterstitialExpirationDuration;
extern NSString *const kMMHandshakeResponseNativeExpiration;
extern NSString *const kMMHandshakeResponseInlineTimeout;
extern NSString *const kMMHandshakeResponseInterstitialTimeout;
extern NSString *const kMMHandshakeResponseNativeTimeout;
extern NSString *const kMMHandshakeResponseClientMediationTimeout;
extern NSString *const kMMHandshakeResponseServerMediationTimeout;
extern NSString *const kMMHandshakeResponseExchangeTimeout;
extern NSString *const kMMHandshakeResponseSDKEnabled;
extern NSString *const kMMHandshakeResponseVASTSkipOffsetMax;
extern NSString *const kMMHandshakeResponseVASTSkipOffsetMin;
extern NSString *const kMMHandshakeResponseVPAID;
extern NSString *const kMMHandshakeResponseVPAIDStartAdTimeout;
extern NSString *const kMMHandshakeResponseVPAIDSkipAdTimeout;
extern NSString *const kMMHandshakeResponseVPAIDAdUnitTimeout;
extern NSString *const kMMHandshakeResponseVPAIDHTMLEndCardTimeout;
extern NSString *const kMMHandshakeResponseHandshakeBaseURL;
extern NSString *const kMMHandshakeResponseReportingBaseURL;
extern NSString *const kMMHandshakeResponseConfig;
extern NSString* const kMMHandshakeResponseMoatEnabled;
extern NSString* const kMMHandshakeResponseMinImpressionViewabilityPercent;
extern NSString* const kMMHandshakeResponseMinImpressionDurationMilliseconds;
extern NSString *const kMMHandshakeResponseSuperAuctionCacheTimeout;

@interface MMHandshakeResponse : NSObject

@property (nonatomic, assign) NSInteger reportingBatchFrequency;
@property (nonatomic, strong) MMHandshakeNativeAdConfig *nativeAdConfig;
@property (nonatomic, strong) NSString *handshakeVersion;
@property (nonatomic, assign) NSInteger reportingBatchSize;
@property (nonatomic, assign) NSInteger handshakeTtl;
@property (nonatomic, assign) NSInteger minInlineRefreshRate;
@property (nonatomic, assign) NSInteger interstitialExpirationDuration;
@property (nonatomic, assign) BOOL sdkEnabled;
@property (nonatomic, strong) MMHandshakePlaylistServer *playlistServer;
@property (nonatomic, assign) NSInteger nativeExpirationDuration;
@property (nonatomic, assign) NSInteger inlineTimeout;
@property (nonatomic, assign) NSInteger interstitialTimeout;
@property (nonatomic, assign) NSInteger nativeTimeout;
@property (nonatomic, assign) NSInteger clientMediationTimeout;
@property (nonatomic, assign) NSInteger serverMediationTimeout;
@property (nonatomic, assign) NSInteger exchangeTimeout;
@property (nonatomic, assign) NSInteger vastSkipOffsetMax;
@property (nonatomic, assign) NSInteger vastSkipOffsetMin;
@property (nonatomic, assign) NSInteger vpaidStartAdTimeout;
@property (nonatomic, assign) NSInteger vpaidSkipAdTimeout;
@property (nonatomic, assign) NSInteger vpaidAdUnitTimeout;
@property (nonatomic, assign) NSInteger vpaidHtmlEndCardTimeout;
@property (nonatomic, strong) NSString *handshakeBaseURL;
@property (nonatomic, strong) NSString *reportingBaseURL;
@property (nonatomic, strong) NSString *config;
@property (nonatomic, assign) BOOL moatEnabled;
@property (nonatomic, assign) NSInteger minImpressionViewabilityPercent;
@property (nonatomic, assign) NSInteger minImpressionDurationMilliseconds;
@property (nonatomic, assign) NSInteger superAuctionCacheTimeout;
//TODO: remove SmartYield functionality MIK-1686
@property (nonatomic, assign) NSInteger smartYieldTimeout;

@end
