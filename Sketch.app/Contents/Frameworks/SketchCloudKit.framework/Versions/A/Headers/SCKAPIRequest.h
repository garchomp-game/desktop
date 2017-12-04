//
//  SCKAPIRequest.h
//  SketchCloudKit
//
//  Created by Robin Speijer on 26-04-17.
//  Copyright © 2017 Awkward. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SCKAPISignable.h"
#import "SCKAPIAuthentication.h"

@class SCKEnvironment;

NS_ASSUME_NONNULL_BEGIN
/// A Cloud API request that can be performed by a URLSession. This is an abstract class and should be subclassed by requests against specific Cloud APIs (with separate baseURLs).
@interface SCKAPIRequest : NSMutableURLRequest

/// The baseURL of the API request. To be overridden by a subclass. The default baseURL is based on the environment's host.
+ (NSURL *)baseURLForEnvironment:(SCKEnvironment *)environment;

/// Creates a new instance with the given path and environment. This two parameters define the request URL.
+ (instancetype)requestWithPath:(NSString *)path
                     queryItems:(nullable NSDictionary<NSString *, NSString *> *)parameters
                    environment:(SCKEnvironment *)environment;

/// Creates a new instance with the given path and environment. This two parameters define the request URL.
+ (instancetype)requestWithPath:(NSString *)path environment:(SCKEnvironment *)environment;

/// Creates a new instance with the given path and the current environment.
+ (instancetype)requestWithPath:(NSString *)path;

/// The Cloud environment that's used to perform the request to. The default will be [SCKEnviroment current]. Changing this property will reset the authentication property to the default authenticated user for the new environment.
@property (nonatomic, copy) SCKEnvironment *environment;

/// The API authentication that should be added to the request. By default, this is an instance of SCKAuthenticatedUser. This could be used to modify the authentication of the request, which could be handy for unit tests.
@property (nonatomic, strong) id<SCKAPIAuthentication> authentication;

/// The HTTPBody of the Cloud request. This must be SCKAPISignable, so that the Cloud request can be signed. When changing this property, the signature will be changed as well.
@property (nonatomic, strong) id<SCKAPISignable> body;

/// The object type(s) that is expected to be returned by the API. This should be a subclass of SCKObject or null if the request doesn't expect any object to be returned.
@property (nonatomic, nullable, assign) Class expectedObjectType;

/// The application version to inlude to the API request.
@property (nonatomic, copy) NSString *applicationVersion;

/// The application build to include to the API request.
@property (nonatomic, copy) NSString *applicationBuild;

@end
NS_ASSUME_NONNULL_END
