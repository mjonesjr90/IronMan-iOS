//
//  MMHTTPHandler.h
//  MMAdSDK
//
//  Created by Stephen Tramer on 4/29/15.
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
 * The backing object which implements all of the behavior behind MMHTTPUtils. This class' public interface is a
 * duplicate of the MMHTTPUtils interface - all methods are forwarded to this class.
 *
 * If you wish to modify the behavior of MMHTTPUtils without using a mock (such as being able to re-route URLs locally
 * or perform other request/response mangling) then you should subclass this class and set it as the `httpHandler` property
 * of the `MMHTTPUtils` singleton instance.
 *
 * However, it is *recommended* that where possible, you just configure the handler with a different NSURLSession. This
 * allows for handling most of the needs that would ordinarily require (potentially extensive) Handler subclassing. The
 * constructor of the handler is responsible for managing session finalization.
 */
@interface MMHTTPHandler : NSObject

-(instancetype)initWithSession:(NSURLSession*)session;

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

@property (nonatomic, readonly) NSURLSession* session;

@end
