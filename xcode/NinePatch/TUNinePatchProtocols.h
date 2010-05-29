//
//  TUNinePatch.h
//  NinePatch
//
//  Copyright 2009 Tortuga 22, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>


#define TURGBABytesPerPixel (4)
typedef struct _TURGBAPixel {
	UInt8 red;
	UInt8 green;
	UInt8 blue;
	UInt8 alpha;	
} TURGBAPixel;

#define TURGBAPixelIsBlack(PIXEL) (((PIXEL.red == 0) && (PIXEL.green == 0) && (PIXEL.blue == 0) && (PIXEL.alpha != 0))?(YES):(NO))

@protocol TUNinePatch < NSObject, NSCoding, NSCopying >

// TUNinePatch Protocol Methods - Drawing
-(void)inContext:(CGContextRef)context drawAtPoint:(CGPoint)point forContentOfSize:(CGSize)size;
-(void)inContext:(CGContextRef)context drawCenteredInRect:(CGRect)containmentRect forContentOfSize:(CGSize)size;
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

@end