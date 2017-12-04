//
//  SCKShareAPIRequest.h
//  SketchCloudKit
//
//  Created by Robin Speijer on 26-04-17.
//  Copyright © 2017 Awkward. All rights reserved.
//

#import "SCKAPIRequest.h"
#import "SCKShare.h"

@class SCKDocument, SCKShare;

NS_ASSUME_NONNULL_BEGIN
/// A request for Cloud share related content from the Cloud API.
@interface SCKShareAPIRequest : SCKAPIRequest

#pragma mark - Creation

/// A request to get a specific Cloud Share from the API, with the given objectID.
+ (instancetype)shareRequestWithID:(SCKObjectID *)shareID;

/// A request to get a specific Cloud Share from the API, with the given shortID.
+ (instancetype)shareRequestWithShortID:(NSString *)shortID;

/// A request to get an array of all Cloud Shares that were created by the current user.
+ (instancetype)userSharesListRequest;

/**
 Creates a new Cloud document on the server. The server is expected to respond with a SCKShareUploadSpecs object. This object will contain further upload information like S3 credentials and the required files to upload. The share will be created privately. The user can manually authorize others to view it, or mark it as public from web.

 @param manifest The document manifest to upload to Sketch Cloud. This is typically created by MSManifestMaker in the Sketch project.
 @return The request to be executed.
 */
+ (instancetype)shareCreationRequestWithManifest:(NSDictionary *)manifest;

/**
 Updates an existing Cloud document on the server. The server is expected to respond with a SCKShareUploadSpecs object. This object will contain further upload information like S3 credentials and the required files to upload.

 @param manifest The document manifest to upload to Sketch Cloud. This is typically created by MSManifestMaker in the Sketch project.
 @param share The existing share to add a new revision to.
 @return The request to be executed.
 */
+ (instancetype)shareUpdateRequestWithManifest:(NSDictionary *)manifest existingShare:(SCKShare *)share;

@end
NS_ASSUME_NONNULL_END
