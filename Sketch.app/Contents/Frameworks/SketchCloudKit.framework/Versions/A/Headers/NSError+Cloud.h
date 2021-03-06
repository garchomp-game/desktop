//
//  NSError+Cloud.h
//  SketchCloudKit
//
//  Created by Robin Speijer on 19-05-17.
//  Copyright © 2017 Awkward. All rights reserved.
//

#import <Foundation/Foundation.h>

/// The error domain for all errors that are generated by SketchCloudKit.
static NSString * const _Nonnull SCKErrorDomain = @"com.bohemiancoding.cloudkit.error";

static NSInteger const SCKErrorCodeNoContent = 204;

@interface NSError (Cloud)

/// Checks if the given response + data represents a server error. If this is the case, the error is constructed and returned.
+ (nullable NSError *)errorFromAPIResponse:(nullable NSURLResponse *)response data:(nullable NSData *)data;

/// Whether the receiver is a Cloud error that has been thrown because of an authorization issue.
@property (nonatomic, readonly, getter=isCloudNotAuthorized) BOOL cloudNotAuthorized;

@end
