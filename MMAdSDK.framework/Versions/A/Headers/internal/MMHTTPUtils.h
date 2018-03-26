//
//  MMHTTPUtils.h
//  MMAdSDK
//
//  Created on 4/1/15.
//  Copyright (c) 2015 Millennial Media. All rights reserved.
//
//  IMPORTANT: The Apps Team must be notified if the content of this file or any of the referenced headers changes.
//
//  This header and those referenced in the MMAdSDK+TestAppInterface folder define for the formal interface to MMAdSDK that is available to the Test App.
//
//  This confluence page provides background documentation and has a link to MMAdSDK git repo master version of the MMAdSDK+TestAppInterface folder:
//  https://confluence.corp.millennialmedia.com/pages/viewpage.action?spaceKey=SCRUM&title=MMAdSDK+Test+App+Interface

#import <Foundation/Foundation.h>

/**
 * All actions of the HTTP Utils are delegated through to a HTTP handler (in the private interface) -- this is a convenience class to
 * provide a global entry point into this instance. Test applications can gain access to the internal readwrite via a category
 * they create. They can then set a subclass with specialized behavior (local file routing, timeouts, etc.) for request/response
 * handling, as opposed to creating a mock (which makes passthrough to implementation methods difficult by design.)
 *
 * Note that this means MMHTTPUtils should not be subclassed: MMHTTPHandler should be, and then have an instance of that
 * set on the MMHTTPUtils shared instance.
 *
 * Also note that the MMHTTPUtils header is the *full declaration of the MMHTTPHandler interface.*  This is primarily
 * for convenience.
 */
@interface MMHTTPUtils : NSObject

+ (BOOL)transparentValueFromResponse:(NSURLResponse *)response;

+(MMHTTPUtils*)sharedInstance;

-(NSURLRequest*)postRequest:(NSURL*)url
                       body:(NSData*)data
                contentType:(NSString*)type
                    timeout:(NSTimeInterval)timeout
                cachePolicy:(NSURLRequestCachePolicy)cachePolicy;
-(NSURLRequest*)getRequest:(NSURL*)url
               queryParams:(NSDictionary*)params
                   timeout:(NSTimeInterval)timeout
               cachePolicy:(NSURLRequestCachePolicy)cachePolicy;

-(NSURLRequest*)postRequest:(NSURL*)url
                       body:(NSData*)data
                contentType:(NSString*)type
                    timeout:(NSTimeInterval)timeout;
-(NSURLRequest*)getRequest:(NSURL*)url
               queryParams:(NSDictionary*)params
                   timeout:(NSTimeInterval)timeout;

-(NSData*)synchronousRequest:(NSURLRequest*)request
                    response:(NSURLResponse* __autoreleasing*)response
                       error:(NSError* __autoreleasing*)error;

-(void)asynchRequest:(NSURLRequest*)request
      successHandler:(void (^)(NSData*, NSURLResponse*))successHandler
        errorHandler:(void (^)(NSError*, NSURLResponse*))errorHandler;

-(NSURLSessionTask*)downloadRequest:(NSURLRequest*)request
                     successHandler:(void (^)(NSURL*, NSURLResponse*))successHandler
                       errorHandler:(void (^)(NSError*, NSURLResponse*))errorHandler;

@end
