//
//  MMHandshakeNativeTypeDefinition.h
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
#import <MMAdSDK/MMNativeAd.h>

// Values that are passed as component names
extern NSString* const kMMNativeComponentNameTitle;
extern NSString* const kMMNativeComponentNameBody;
extern NSString* const kMMNativeComponentNameIconImage;
extern NSString* const kMMNativeComponentNameMainImage;
extern NSString* const kMMNativeComponentNameCTA;
extern NSString* const kMMNativeComponentNameRating;
extern NSString* const kMMNativeComponentNameDisclaimer;

extern NSString* const kMMNativeAdvertiserRequiredKey;
extern NSString* const kMMNativePublisherRequiredKey;

@interface MMHandshakeNativeTypeDefinition : NSObject

+(MMNativeComponentTypeID)idForComponentName:(NSString*)name;
+(NSString*)componentNameForID:(MMNativeComponentTypeID)component;

@property (nonatomic, readonly) NSString* name;
@property (nonatomic, readonly) NSDictionary* components;

@end
