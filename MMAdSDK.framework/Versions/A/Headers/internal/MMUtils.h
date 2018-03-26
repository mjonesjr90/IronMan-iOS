//
//  MMUtils.h
//  MMAdSDK
//
//  Copyright (c) 2015 Millennial Media. All rights reserved.
//
//  IMPORTANT: The Apps Team must be notified if the content of this file or any of the referenced headers changes.
//
//  This header and those referenced in the MMAdSDK+TestAppInterface folder define for the formal interface to MMAdSDK that is available to the Test App.
//
//  This confluence page provides background documentation and has a link to MMAdSDK git repo master version of the MMAdSDK+TestAppInterface folder:
//  https://confluence.corp.millennialmedia.com/pages/viewpage.action?spaceKey=SCRUM&title=MMAdSDK+Test+App+Interface

#import <Foundation/Foundation.h>

extern NSString* const kMMCreativeIdKey;
extern NSString* const kMMSDKVersionKey;
extern NSString* const kMMAdSDKUserDefaultsSuiteName;

@interface MMUtils : NSObject

+(NSDictionary *)getVersionData;

@end
