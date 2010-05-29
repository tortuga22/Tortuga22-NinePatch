//
//  NPNinePatchDemoView.h
//  NinePatchDemo
//
//  Copyright 2009 Tortuga 22, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TUNinePatch.h>

@interface NPNinePatchDemoView : UIView {
	TUNinePatch *_ninePatch;
	UIImage *_originalImage;
	CGSize _ninePatchSize;
	BOOL _shouldDrawOriginal;
}

// Synthesized Properties
@property(nonatomic, retain) TUNinePatch *ninePatch;
@property(nonatomic, retain) UIImage *originalImage;
@property(nonatomic, assign) CGSize ninePatchSize;
@property(nonatomic, assign) BOOL shouldDrawOriginal;

// Convenience
-(void)setHeight:(CGFloat)height;
-(void)setWidth:(CGFloat)width;
-(void)updateToNinePatch:(TUNinePatch *)ninePatch originalImage:(UIImage *)originalImage;
-(void)toggleShouldDrawOriginal;

@end
