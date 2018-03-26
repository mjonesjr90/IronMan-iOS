//
//  MMHandshakeManager.h
//  MMAdSDK
//
//  Created by Mike Patzer on 4/1/15.
//  Copyright (c) 2015 Millennial Media. All rights reserved.
//
//
//  IMPORTANT: The Apps Team must be notified if the content of this file or any of the referenced headers changes.
//
//  This header and those referenced in the MMAdSDK+TestAppInterface folder define for the formal interface to MMAdSDK that is available to the Test App.
//
//  This confluence page provides background documentation and has a link to MMAdSDK git repo master version of the MMAdSDK+TestAppInterface folder:
//  https://confluence.corp.millennialmedia.com/pages/viewpage.action?spaceKey=SCRUM&title=MMAdSDK+Test+App+Interface

#import <Foundation/Foundation.h>

@class MMHandshakeResponse;

typedef void (^MMHandshakeCallback)(BOOL success);

@interface MMHandshakeManager : NSObject

/**
 * The shared instance of the handshake manager.
 */
+ (instancetype)sharedInstance;

/**
 * Initiates a new handshake with the server endpoint which results in an updated handshake response.
 * When the handshake completes, a callback is returned that indicates success or failure.
 */
- (void)performHandshake:(MMHandshakeCallback)callback;

/**
 * Forces a new handshake with the supplied testHandshakeData, which is an NSData object using the format defined here:
 * https://confluence.corp.millennialmedia.com/pages/viewpage.action?pageId=64751027
 * The result is an updated handshake response.
 * When the handshake completes, a callback is returned that indicates success or failure.
 */
-(void)performHandshake:(MMHandshakeCallback)callback withTestHandshakeData:(NSData *)testHandshakeData;

/**
 * The most up to date handshake response. This should be used to access settings configured by the handshake.
 */
@property (nonatomic, strong) MMHandshakeResponse *currentHandshakeResponse;

@end
