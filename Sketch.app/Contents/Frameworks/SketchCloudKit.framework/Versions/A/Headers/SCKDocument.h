//
//  SCKDocument.h
//  SketchCloudKit
//
//  Created by Robin Speijer on 01-02-17.
//  Copyright © 2017 Awkward. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCKObject.h"

@class SCKPage, SCKArtboard;

typedef NS_OPTIONS(NSUInteger, SCKDocumentAttributes) {
    SCKDocumentNoAttribute = 0,
    SCKDocumentNameAttribute = 1 << 0,
    SCKDocumentSlugAttribute = 1 << 1,
    SCKDocumentDownloadURLAttribute = 1 << 2,
    SCKDocumentProcessingAttribute = 1 << 3,
    SCKDocumentMetaImageURLAttribute = 1 << 4,
    SCKDocumentPagesAttribute = 1 << 5
};

/// Represents a Sketch document.
@interface SCKDocument : SCKObject

/// A user readable document name. This might not be the same as the filename for the document.
@property (nonatomic, nullable, readonly) NSString *name;

/// All pages that are part of this document.
@property (nonatomic, nonnull, readonly) NSArray<SCKPage *> *pages;

/// Convenience method to lookup the artboard with the given objectID inside this document.
- (nullable SCKArtboard *)artboardWithID:(nullable SCKObjectID *)objectID NS_SWIFT_NAME(artboard(with:));

/// Convenience method to lookup the artboard described by a predicate within this document.
- (nullable SCKArtboard *)artboardWithPredicate:(nonnull NSPredicate *)predicate NS_SWIFT_NAME(artboard(with:));

/// Convenience method to lookup the page with the given objectID inside this document.
- (nullable SCKPage *)pageWithID:(nullable SCKObjectID *)objectID NS_SWIFT_NAME(page(with:));

@end
