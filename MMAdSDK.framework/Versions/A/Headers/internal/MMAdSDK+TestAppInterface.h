//
//  MMAdSDK+TestAppInterface.h
//  MMAdSDK
//
//  Created by Tom Poland on 10/15/15.
//  Copyright © 2015 Millennial Media. All rights reserved.
//
//
//  IMPORTANT: The Apps Team must be notified if the content of this file or any of the referenced headers changes.
//
//  This header and those referenced in the MMAdSDK+TestAppInterface folder define for the formal interface to MMAdSDK that is available to the Test App.
//
//  This confluence page provides background documentation and has a link to MMAdSDK git repo master version of the MMAdSDK+TestAppInterface folder:
//  https://confluence.corp.millennialmedia.com/pages/viewpage.action?spaceKey=SCRUM&title=MMAdSDK+Test+App+Interface

#ifndef MMAdSDK_TestAppInterface_h
#define MMAdSDK_TestAppInterface_h

#import <MMAdSDK/MMAppSettings.h>
#import "MMHandshakeManager.h"
#import "MMHandshakeConstants.h"
#import "MMHTTPHandler.h"
#import "MMHTTPUtils.h"
#import "MMUtils.h"
#import "MMHandshakeResponse.h"
#import "MMHandshakePlaylistServer.h"
#import "MMHandshakeNativeAdConfig.h"
#import "MMHandshakeNativeTypeDefinition.h"

#endif

@interface MMAppSettings ()

@property (nonatomic, readwrite, nullable) NSString *coppa;

@end


