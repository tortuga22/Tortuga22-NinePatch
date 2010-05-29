//
//  TUNinePatch.h
//  NinePatch
//
//  Copyright 2009 Tortuga 22, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>
#import "TUNinePatchProtocols.h"

@interface TUNinePatch : NSObject < NSCoding, NSCopying > {
	UIImage *_center;
	CGRect _contentRegion;
	BOOL _tileCenterVertically;
	BOOL _tileCenterHorizontally;
}

// Synthesized Properties
@property(nonatomic, retain, readonly) UIImage *center;
@property(nonatomic, assign, readonly) CGRect contentRegion;
@property(nonatomic, assign, readonly) BOOL tileCenterVertically;
@property(nonatomic, assign, readonly) BOOL tileCenterHorizontally;

// NSCoding
-(id)initWithCoder:(NSCoder *)coder;
-(void)encodeWithCoder:(NSCoder *)coder;

// NSCopying
-(id)copyWithZone:(NSZone *)zone;

// Init + Dealloc
-(id)initWithCenter:(UIImage *)center contentRegion:(CGRect)contentRegion;
-(id)initWithCenter:(UIImage *)center contentRegion:(CGRect)contentRegion tileCenterVertically:(BOOL)tileCenterVertically tileCenterHorizontally:(BOOL)tileCenterHorizontally;
-(void)dealloc;

// Convenience Constructors
+(id < TUNinePatch >)ninePatchWithNinePatchImage:(UIImage *)ninePatchImage;
+(id < TUNinePatch >)ninePatchWithImage:(UIImage *)image stretchableRegion:(CGRect)stretchableRegion;
+(id < TUNinePatch >)ninePatchWithImage:(UIImage *)image stretchableRegion:(CGRect)stretchableRegion contentRegion:(CGRect)contentRegion tileCenterVertically:(BOOL)tileCenterVertically tileCenterHorizontally:(BOOL)tileCenterHorizontally;

// Bundle Loading
+(id < TUNinePatch >)ninePatchNamed:(NSString *)filename;

// Nine Patch Image Manipulation - High Level
+(CGRect)rectFromHorizontalRange:(NSRange)horizontalRange verticalRange:(NSRange)verticalRange;
+(CGRect)stretchableRegionOfNinePatchImage:(UIImage *)ninePatchImage;
+(CGRect)contentRegionOfNinePatchImage:(UIImage *)ninePatchImage;
+(BOOL)shouldTileCenterHorizontallyForNinePatchImage:(UIImage *)ninePatchImage;
+(BOOL)shouldTileCenterVerticallyForNinePatchImage:(UIImage *)ninePatchImage;

// Drawing Utility
-(void)drawInRect:(CGRect)rect;

// Diagnostic Utilities
-(UIImage *)upperEdge;
-(UIImage *)lowerEdge;
-(UIImage *)leftEdge;
-(UIImage *)rightEdge;

-(UIImage *)upperLeftCorner;
-(UIImage *)lowerLeftCorner;
-(UIImage *)upperRightCorner;
-(UIImage *)lowerRightCorner;

// TUNinePatch Protocol Methods - Drawing
-(void)inContext:(CGContextRef)context drawAtPoint:(CGPoint)point forContentOfSize:(CGSize)contentSize;
-(void)inContext:(CGContextRef)context drawCenteredInRect:(CGRect)rect forContentOfSize:(CGSize)contentSize;
-(void)inContext:(CGContextRef)context drawInRect:(CGRect)rect;

// TUNinePatch Protocol Methods - Image Construction
-(UIImage *)imageOfSize:(CGSize)size;

// TUNinePatch Protocol Methods - Sizing
-(BOOL)stretchesHorizontally;
-(BOOL)stretchesVertically;
-(CGFloat)minimumWidth;
-(CGFloat)minimumHeight;
-(CGSize)minimumSize;
-(CGSize)sizeForContentOfSize:(CGSize)contentSize;
-(CGPoint)upperLeftCornerForContentWhenDrawnAtPoint:(CGPoint)point;

// TUNinePatch Protocol Methods - Geometry
-(CGFloat)leftEdgeWidth;
-(CGFloat)rightEdgeWidth;
-(CGFloat)upperEdgeHeight;
-(CGFloat)lowerEdgeHeight;

// Customized Description
-(NSString *)description;
-(NSString *)descriptionPostfix;

@end