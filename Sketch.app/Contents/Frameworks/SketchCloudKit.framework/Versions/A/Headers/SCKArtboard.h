//
//  SCKArtboard.h
//  SketchCloudKit
//
//  Created by Robin Speijer on 01-02-17.
//  Copyright © 2017 Awkward. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import "SCKObject.h"

@class SCKFile, SCKPage;

typedef NS_OPTIONS(NSUInteger, SCKArtboardAttributes) {
    SCKArtboardNoAttribute = 0,
    SCKArtboardNameAttribute = 1 << 0,
    SCKArtboardSlugAttribute = 1 << 1,
    SCKArtboardOrderAttribute = 1 << 2,
    SCKArtboardUnreadAttribute = 1 << 3,
    SCKArtboardSizeAttribute = 1 << 4,
    SCKArtboardFilesAttribute = 1 << 5
};

/// An artboard inside a SCKPage.
@interface SCKArtboard : SCKObject

/// The page that this artboard is part of.
@property (nonatomic, nullable, readonly) SCKPage *page;

/// The user readable name for the artboard.
@property (nonatomic, nullable, readonly) NSString *name;

/// A uniquely artboard-identifying string within the page.
@property (nonatomic, nullable, readonly) NSString *slug;

/// An integer to define the artboard order in the document.
@property (nonatomic, readonly) NSUInteger order;

/// Whether the artboard has unread notifications. Those notifications might notify the user about unread comments.
@property (nonatomic, readonly) NSUInteger unread;

/// The artboard size in points.
@property (nonatomic, readonly) CGSize size;

/// The possible files that represent the artboard's image. Generally, those files only differ in scales.
@property (nonatomic, nonnull, readonly) NSArray<SCKFile *> *files;

/**
 Looks up the most suitable image file in the files attribute at the given screen scale.

 @param scale The optimal scale to use for the image file.
 @return An image file.
 */
- (nullable SCKFile *)fileAtScale:(CGFloat)scale NS_SWIFT_NAME(file(atScale:));

@end
