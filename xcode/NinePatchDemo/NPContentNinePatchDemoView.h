//
//  NPContentNinePatchDemoView.h
//  NinePatchDemo
//
//  Copyright 2009 Tortuga 22, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TUNinePatch.h>

@class TUNinePatch;

@interface NPContentNinePatchDemoView : UIView {
	TUNinePatch *_ninePatch;
	CGFloat _fontSize;
}

@property(nonatomic, retain) TUNinePatch *ninePatch;
@property(nonatomic, assign) CGFloat fontSize;

-(void)redrawWithFontSize:(CGFloat)fontSize;

@end
