//
//  SCKAuthenticatedUser.h
//  SketchCloudKit
//
//  Created by Robin Speijer on 30-01-17.
//  Copyright © 2017 Awkward. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCKUser.h"
#import "SCKAPIAuthentication.h"

@class SCKEnvironment;

/// Notification name to be posted when the currently logged in user did change within a Cloud environment. Changing environments will not trigger such a notification. In the case of a logout, the posting object is nil. In the case of a login, the posting object is the logged in SCKAuthenticatedUser instance. Posted from the main thread, if all login/logout calls are also done from the main thread (which should be).
extern NSNotificationName _Nonnull const SCKAuthenticatedUserDidChangeNotification;

/// Notification name to be posted when user attributes of the currently logged in user has been updated. Posted from the main thread.
extern NSNotificationName _Nonnull const SCKAuthenticatedUserDidUpdateNotification;

/** 
 A user that contains authentication info for authenticating with the Cloud API. An instance of this object can be logged in by calling the login method. From now on, this instance will be stored in the `current` static variable. From now on, every time an authenticated user is parsed with the same objectID, this instance will be replaced by a new version to keep up-to-date.
 */
@interface SCKAuthenticatedUser : SCKUser <SCKAPIAuthentication>

/// The shared user instance that's currently logged in to cloud. This depends on the current Cloud environment. Thread safe.
+ (nullable instancetype)current;

/// Looks up the current user for the given environment in the keychain. This is not cached like current is.
+ (nullable instancetype)keychainUserForEnvironment:(nonnull SCKEnvironment *)environment;

/// Logs out the currently logged in user. As a result, the SCKAuthenticatedUser.current property will be erased as well. Should be called from the main thread.
+ (void)logout;

/// Logs in the receiving authenticated user. As a result, the SCKAuthenticatedUser.current will be changed to the receiver. Should be called from the main thread.
- (void)login;

/// Logs in the receiving authenticated user to the given environment. If the given environment is not the current environment, the current property doesn't change. Should be called from the main thread.
- (void)loginToEnvironment:(nonnull SCKEnvironment *)environment;

@end
