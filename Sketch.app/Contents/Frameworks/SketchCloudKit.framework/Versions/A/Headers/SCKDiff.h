//
//  SCKDiff.h
//  SketchCloudKit
//
//  Created by Robin Speijer on 07-02-17.
//  Copyright © 2017 Awkward. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SCKObject;
@protocol SCKDiffable;

@protocol SCKDiff <NSObject>

- (nonnull instancetype)initWithObject:(nonnull id)object comparedTo:(nonnull id)otherObject;

@property (nonatomic, copy, nonnull, readonly) id object;
@property (nonatomic, copy, nonnull, readonly) id comparedObject;

@end

@protocol SCKDiffable <NSObject>

- (nonnull id<SCKDiff>)diffComparedTo:(nonnull SCKObject<SCKDiffable> *)object;

@end
