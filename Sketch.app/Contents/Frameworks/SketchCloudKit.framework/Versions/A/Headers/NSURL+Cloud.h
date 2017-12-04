//
//  NSURL+Cloud.h
//  SketchCloudKit
//
//  Created by Robin Speijer on 03-03-17.
//  Copyright © 2017 Awkward. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SCKArtboard, SCKPage;

/// Helpers to identify Sketch Cloud URLs and their components.
@interface NSURL (Cloud)

/// Checks the URL's components if it is a valid Cloud share.
@property (nonatomic, readonly) BOOL isCloudShare;

/// The URL of only the cloud share itself, if the receiver is a Cloud share. This might come in handy if the receiver contains additional path components like a page and artboard slug.
@property (nonatomic, nullable, readonly) NSURL *cloudShareURL NS_SWIFT_NAME(cloudShareURL);

/// The Cloud share's shortID, if the receiver is a Cloud share.
@property (nonatomic, nullable, readonly) NSString *cloudShareShortID;

/// The Cloud share's page slug, if the receiver is a Cloud share deeplink and contains a reference to a page.
@property (nonatomic, nullable, readonly) NSString *cloudPageSlug;

/// The Cloud share's artboard slug, if the receiver is a Cloud share deeplink and contains a reference to a artboard.
@property (nonatomic, nullable, readonly) NSString *cloudArtboardSlug;

/**
 Constructs a URL by appending Cloud deeplink components to a given artboard inside the document. To create a valid Cloud URL, the following conditions must be met:
 - The receiver must be a valid non-deeplink Cloud URL to a share. If not, this method returns nil.
 - The artboard must have a page as parent. If not, this method returns nil.
 - The document of the artboard must be the same document that is contained by the share. This is not checked.

 @param artboard The artboard to deeplink to.
 @return A newly constructed URL, if all information is correct.
 */
- (nullable NSURL *)appendingCloudDeeplinkComponentsToArtboard:(nullable SCKArtboard *)artboard;

/**
 Constructs a URL by appending Cloud deeplink components to a given artboard, inside its page. To create a valid Cloud URL, the following conditions must be met:
 - The receiver must be a valid non-deeplink Cloud URL to a share. If not, this method returns nil.
 - The artboard must have a page as parent. If not, this method returns nil.
 - The document of the artboard must be the same document that is contained by the share. This is not checked.
 
 @param artboard The artboard to deeplink to.
 @return A newly constructed URL, if all information is correct.
 */
- (nullable NSURL *)appendingCloudDeeplinkComponentsInPageToArtboard:(nullable SCKArtboard *)artboard;

@end
