//
//  PRJRect.h
//  Projection
//
//  Created by Mikey Lintz on 1/30/15.
//  Copyright (c) 2015 Mikey Lintz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/** A helper class for incrementally defining the frame for a view.

PRJRect will attempt to infer the value of left, right, etc based on what's previously been set.

For example, if rect.left and rect.right have been set, then PRJRect will infer the values of
rect.width and rect.centerX. Specifically, PRJRect can provide a value if it's been explicitly set,
or if exactly two values in the same direction (vertical or horizontal) have been set.

Usage:
    PRJRect *rect = [[PRJRect alloc] init];
    rect.centerX = 100;
    rect.right = 150;
    CGFloat left = rect.left;  // 50

    ...

    rect.height = 20;

    rect.centerY = 60.1234;

    ...

    someView.frame = rect.frame;  // origin = (x = 50, y = 50.1234),
                                  // size = (width = 100, height = 20);
    someView.frame = rect.integralFrame; // origin = (x = 50, y = 50),
                                         // size = (width = 100, height = 20);

Compound values like topLeft, center, and size are provided as convenience properties for
setting or reading multiple values at a time.


Warning: PRJRect will assert if it's overdefined (more than two values in the same direction are
set) or if it doesn't have enough definition to define a value.

    PRJRect *rect = [[PRJRect alloc] init];
    rect.centerX = 100;
    CGFloat centerx = rect.centerX;  // 100
    // CGFloat left = rect.left;  // Asserts b/c rect cannot infer left value

    ....

    rect.height = 20;
    rect.centerY = 60;
    // rect.top = 50;  // Asserts b/c two vertical values have already been set
    rect.height = 30;  // Fine b/c height has previously been set
*/

@interface PRJRect : NSObject<NSCopying>
NS_ASSUME_NONNULL_BEGIN

@property(nonatomic, assign) CGFloat left;
@property(nonatomic, assign) CGFloat right;
@property(nonatomic, assign) CGFloat centerX;
@property(nonatomic, assign) CGFloat width;

@property(nonatomic, assign) CGFloat top;
@property(nonatomic, assign) CGFloat bottom;
@property(nonatomic, assign) CGFloat centerY;
@property(nonatomic, assign) CGFloat height;

@property(nonatomic, assign) CGPoint topLeft;
@property(nonatomic, assign) CGPoint topRight;
@property(nonatomic, assign) CGPoint bottomLeft;
@property(nonatomic, assign) CGPoint bottomRight;
@property(nonatomic, assign) CGPoint center;

@property(nonatomic, assign) CGSize size;
@property(nonatomic, assign) CGRect frame;
/// Equivalent to applying CGRectIntegral to the receiver's frame.
@property(nonatomic, readonly) CGRect integralFrame;

/// YES if exactly two horizontal and two vertical values are set.
@property(nonatomic, readonly) BOOL isFullyDefined;

NS_ASSUME_NONNULL_END
@end
