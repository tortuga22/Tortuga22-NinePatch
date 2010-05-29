//
//  NPNinePatchDemoView.m
//  NinePatchDemo
//
//  Copyright 2009 Tortuga 22, Inc. All rights reserved.
//

#import "NPNinePatchDemoView.h"


@implementation NPNinePatchDemoView

#pragma mark Synthesized Properties
@synthesize ninePatch = _ninePatch;
@synthesize originalImage = _originalImage;
@synthesize shouldDrawOriginal = _shouldDrawOriginal;
@synthesize ninePatchSize = _ninePatchSize;

- (id)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        // Initialization code
		self.ninePatch = nil;
		self.ninePatchSize = CGSizeZero;
    }
    return self;
}


-(void)drawRect:(CGRect)rect {
    // Drawing code
	CGContextRef context = UIGraphicsGetCurrentContext();
	CGContextSetFillColorWithColor(context, [[UIColor whiteColor] CGColor]);
	CGContextFillRect(context, self.bounds);
	if ((!self.shouldDrawOriginal) && self.ninePatch) {
		CGSize npSize = self.ninePatchSize;
		CGSize selfSize = [self bounds].size;
		CGFloat xOffset = floorf((selfSize.width - npSize.width) * 0.5f);
		CGFloat yOffset = floorf((selfSize.height - npSize.height) * 0.5f);
		[self.ninePatch inContext:context 
					   drawInRect:CGRectMake(xOffset, yOffset, npSize.width, npSize.height)];
	} else if (self.originalImage && self.shouldDrawOriginal) {
		CGSize oiSize = [self.originalImage size];
		CGSize selfSize = [self bounds].size;
		CGFloat xOffset = floorf((selfSize.width - oiSize.width) * 0.5f);
		CGFloat yOffset = floorf((selfSize.height - oiSize.height) * 0.5f);
		[self.originalImage drawAtPoint:CGPointMake(xOffset, yOffset)];
	}
}


- (void)dealloc {
	self.originalImage = nil;
	self.ninePatch = nil;
    [super dealloc];
}

#pragma mark Utilities
-(void)setHeight:(CGFloat)height {
	CGSize currentSize = self.ninePatchSize;
	currentSize.height = height;
	self.ninePatchSize = currentSize;
	[self setNeedsDisplay];
}

-(void)setWidth:(CGFloat)width {
	CGSize currentSize = self.ninePatchSize;
	currentSize.width = width;
	self.ninePatchSize = currentSize;
	[self setNeedsDisplay];
}

-(void)updateToNinePatch:(TUNinePatch *)ninePatch originalImage:(UIImage *)originalImage {
	self.originalImage = originalImage;
	self.ninePatch = ninePatch;
	[self setNeedsDisplay];
}

-(void)toggleShouldDrawOriginal {
	self.shouldDrawOriginal = (self.shouldDrawOriginal)?(NO):(YES);
	[self setNeedsDisplay];
}

#pragma mark NSObject Override
-(NSString *)description {
	return [NSString stringWithFormat:@"<%@>:('%@')",[super description],[self ninePatch]];
}

@end
