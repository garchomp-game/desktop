//
//  SCKThumbnail.h
//  SketchCloudKit
//
//  Created by Robin Speijer on 01-02-17.
//  Copyright © 2017 Awkward. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import "SCKObject.h"

@interface SCKThumbnail : SCKObject

@property (nonatomic, nullable, readonly) NSURL *URL;
@property (nonatomic, readonly) CGSize dimensions;
@property (nonatomic, readonly) NSUInteger fileSize;

@end
