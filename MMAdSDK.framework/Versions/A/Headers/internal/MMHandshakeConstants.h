//
//  MMHandshakeConstants.h
//  MMAdSDK
//
//  Created by Tom Poland on 4/26/17.
//  Copyright © 2017 Millennial Media. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface MMHandshakeConstants : NSObject

+(MMHandshakeConstants *)sharedInstance;


#ifdef DEBUG

-(void)reset;  // Only expose reset in DEBUG builds

#endif


#ifdef DEBUG

#define ACCESS readwrite  // DEBUG builds allow mutable floor/ceiling vlaues

#else

#define ACCESS readonly   // RELEASE builds have immutable handshake floor/ceiling values

#endif


// Floors
@property (nonatomic, ACCESS) NSInteger kMMHandshakeTtlMinimum;
@property (nonatomic, ACCESS) NSInteger kMMMinInlineRefreshRateMinimum;
@property (nonatomic, ACCESS) NSInteger kMMInterstitialExpirationDurationMinimum;
@property (nonatomic, ACCESS) NSInteger kMMNativeExpirationDurationMinimum;
@property (nonatomic, ACCESS) NSInteger kMMReportingBatchFrequencyMinimum;
@property (nonatomic, ACCESS) NSInteger kMMReportingBatchSizeMinimum;
@property (nonatomic, ACCESS) NSInteger kMMInlineTimeoutMinimum;
@property (nonatomic, ACCESS) NSInteger kMMInterstitialTimeoutMinimum;
@property (nonatomic, ACCESS) NSInteger kMMNativeTimeoutMinimum;
@property (nonatomic, ACCESS) NSInteger kMMClientMediationTimeoutMinimum;
@property (nonatomic, ACCESS) NSInteger kMMServerMediationTimeoutMinimum;
@property (nonatomic, ACCESS) NSInteger kMMExchangeTimeoutMinimum;
@property (nonatomic, ACCESS) NSInteger kMMVastSkipOffsetMinFloor;
@property (nonatomic, ACCESS) NSInteger kMMVastSkipOffsetMaxFloor;
@property (nonatomic, ACCESS) NSInteger kMMVpaidStartAdTimeoutFloor;
@property (nonatomic, ACCESS) NSInteger kMMVpaidSkipAdTimeoutFloor;
@property (nonatomic, ACCESS) NSInteger kMMVpaidAdUnitTimeoutFloor;
@property (nonatomic, ACCESS) NSInteger kMMVpaidHtmlEndCardTimeoutFloor;
@property (nonatomic, ACCESS) NSInteger kMMMinImpressionViewabilityPercentFloor;
@property (nonatomic, ACCESS) NSInteger kMMMinImpressionViewabilityPercentDefault;
@property (nonatomic, ACCESS) NSInteger kMMMinImpressionDurationMillisecondsFloor;
@property (nonatomic, ACCESS) NSInteger kMMMinImpressionDurationMillisecondsDefault;
@property (nonatomic, ACCESS) NSInteger kMMSuperAuctionCacheTimeoutFloor;
//TODO: remove SmartYield functionality MIK-1686
@property (nonatomic, ACCESS) NSInteger kMMSmartYieldTimeoutMinimum;

// Ceilings
@property (nonatomic, ACCESS) NSInteger kMMMinImpressionViewabilityPercentCeiling;
@property (nonatomic, ACCESS) NSInteger kMMMinImpressionDurationMillisecondsCeiling;
@property (nonatomic, ACCESS) NSInteger kMMSuperAuctionCacheTimeoutCeiling;

// Defaults
@property (nonatomic, ACCESS) NSInteger kMMVPAIDAdUnitTimeoutDefault;
@property (nonatomic, ACCESS) NSInteger kMMVPAIDSkipAdTimeoutDefault;
@property (nonatomic, ACCESS) NSInteger kMMVPAIDStartAdTimeoutDefault;
@property (nonatomic, ACCESS) NSInteger kMMVPAIDHTMLEndCardTimeoutDefault;
@property (nonatomic, ACCESS) NSInteger kMMSuperAuctionCacheTimeoutDefault;

//TODO: remove SmartYield functionality MIK-1686
@property (nonatomic, ACCESS) NSInteger kMMSmartYieldTimeoutDefault;

@property (nonatomic, ACCESS) BOOL kMMSDKEnabledDefault;
@property (nonatomic, ACCESS) BOOL kMMHandshakeMoatDefault;
@property (nonatomic, ACCESS) NSString* kMMHandshakeBaseURLDefault;
@property (nonatomic, ACCESS) NSString* kMMConfigDefault;
@property (nonatomic, ACCESS) NSInteger kMMMaxConsecutiveFailures;

@end
