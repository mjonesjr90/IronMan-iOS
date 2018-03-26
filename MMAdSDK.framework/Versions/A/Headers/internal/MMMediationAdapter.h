//
//  MMMediationAdapter.h
//  MMAdSDK
//
//  Created by Fedor Kudrys on 7/14/17.
//  Copyright © 2017 Millennial Media. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MMAdSDK/mediation/MMCustomEventRequest.h>

@class MMAd;
@class MMAdWrapperMediation;
@protocol MMCustomEvent;

@interface MMMediationAdapter : NSObject

@property (nonatomic, strong, nullable) id<MMCustomEvent> customEvent;
@property (nonatomic, weak, nullable) id eventForwarder;
@property (nonatomic, copy, nullable) void (^getAdCallback)(BOOL success, NSError * _Nullable error);

+ (nullable MMMediationAdapter *)adapterForPlacementType:(MMPlacementType)placementType;

- (void)notifyEventForwarderThatAdIsLoaded;

@end
