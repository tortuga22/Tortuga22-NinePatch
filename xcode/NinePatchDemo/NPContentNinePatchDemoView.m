//
//  NPContentNinePatchDemoView.m
//  NinePatchDemo
//
//  Copyright 2009 Tortuga 22, Inc. All rights reserved.
//

#import "NPContentNinePatchDemoView.h"


@implementation NPContentNinePatchDemoView

@synthesize ninePatch = _ninePatch;
@synthesize fontSize = _fontSize;

- (void)drawRect:(CGRect)rect {
    // Drawing code
	if (self.ninePatch) {
		NSString *message = @"Testy";
		UIFont *font = [UIFont systemFontOfSize:self.fontSize];
		CGSize messageSize = [message sizeWithFont:font];
		CGContextRef context = UIGraphicsGetCurrentContext();
		if (context && self.ninePatch) {
			CGSize selfSize = [self bounds].size;
			[self.ninePatch inContext:context 
				   drawCenteredInRect:[self bounds] 
					 forContentOfSize:messageSize];
			[message drawAtPoint:CGPointMake(floorf((selfSize.width - messageSize.width) * .5f), floorf((selfSize.width - messageSize.height) * .5f))
						withFont:font];
		}
	}
}


- (void)dealloc {
	self.ninePatch = nil;
    [super dealloc];
}

-(void)redrawWithFontSize:(CGFloat)fontSize {
	self.fontSize = fontSize;
	DLog(@"self.fontSize: '%f', self.ninePatch.contentRegion: '%@'.",self.fontSize,NSStringFromCGRect(self.ninePatch.contentRegion));
	[self setNeedsDisplay];
}

@end
