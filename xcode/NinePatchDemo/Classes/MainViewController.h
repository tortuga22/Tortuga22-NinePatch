//
//  MainViewController.h
//  NinePatchDemo
//
//  Copyright Tortuga 22, Inc 2009. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TUNinePatch.h>
#import "FlipsideViewController.h"


@class NPNinePatchDemoView;

@interface MainViewController : UIViewController <FlipsideViewControllerDelegate> {
	NPNinePatchDemoView *_fullNinePatchView;
	
	UISlider *_heightSlider;
	UISlider *_widthSlider;
	
	UIButton *_changeButton;
	UIButton *_cmtButton;
	UIButton *_orgButton;
	
	UILabel *_upperLeftLabel;
	UILabel *_lowerLeftLabel;
	UILabel *_leftLabel;
	UILabel *_upperLabel;
	UILabel *_lowerLabel;
	UILabel *_upperRightLabel;
	UILabel *_lowerRightLabel;
	UILabel *_rightLabel;
	UILabel *_centerLabel;
	
	UIImageView *_upperLeftImageView;
	UIImageView *_lowerLeftImageView;
	UIImageView *_leftImageView;
	UIImageView *_upperImageView;
	UIImageView *_lowerImageView;
	UIImageView *_upperRightImageView;
	UIImageView *_lowerRightImageView;
	UIImageView *_rightImageView;
	
	TUNinePatch *_activeNinePatch;
	UIImage *_activeBaseImage;
	
	BOOL _usingNGramBackplate;
}

// Synthesized Properties
@property(nonatomic, retain) IBOutlet NPNinePatchDemoView *fullNinePatchView;

@property(nonatomic, retain) IBOutlet UISlider *heightSlider;
@property(nonatomic, retain) IBOutlet UISlider *widthSlider;

@property(nonatomic, retain) IBOutlet UIButton *changeButton;
@property(nonatomic, retain) IBOutlet UIButton *cmtButton;
@property(nonatomic, retain) IBOutlet UIButton *orgButton;

@property(nonatomic, retain) IBOutlet UILabel *upperLeftLabel;
@property(nonatomic, retain) IBOutlet UILabel *lowerLeftLabel;
@property(nonatomic, retain) IBOutlet UILabel *leftLabel;
@property(nonatomic, retain) IBOutlet UILabel *upperLabel;
@property(nonatomic, retain) IBOutlet UILabel *lowerLabel;
@property(nonatomic, retain) IBOutlet UILabel *upperRightLabel;
@property(nonatomic, retain) IBOutlet UILabel *lowerRightLabel;
@property(nonatomic, retain) IBOutlet UILabel *rightLabel;
@property(nonatomic, retain) IBOutlet UILabel *centerLabel;

@property(nonatomic, retain) IBOutlet UIImageView *upperLeftImageView;
@property(nonatomic, retain) IBOutlet UIImageView *lowerLeftImageView;
@property(nonatomic, retain) IBOutlet UIImageView *leftImageView;
@property(nonatomic, retain) IBOutlet UIImageView *upperImageView;
@property(nonatomic, retain) IBOutlet UIImageView *lowerImageView;
@property(nonatomic, retain) IBOutlet UIImageView *upperRightImageView;
@property(nonatomic, retain) IBOutlet UIImageView *lowerRightImageView;
@property(nonatomic, retain) IBOutlet UIImageView *rightImageView;

@property(nonatomic, retain) TUNinePatch *activeNinePatch;
@property(nonatomic, retain) UIImage *activeBaseImage;

@property(nonatomic, assign) BOOL usingNGramBackplate; 

// Status Updating
-(void)updateToNinePatchNamed:(NSString *)ninePatchName;
-(void)updateImageView:(UIImageView *)imageView andLabel:(UILabel *)label forImage:(UIImage *)image;

// IBActions
-(IBAction)showInfo;

-(IBAction)heightSliderValueDidChange:(id)sender;
-(IBAction)widthSliderValueDidChange:(id)sender;
-(IBAction)changeButtonPushed:(id)sender;
-(IBAction)cmtButtonPushed:(id)sender;
-(IBAction)orgButtonPushed:(id)sender;

// Lifecycle + Utilities
-(void)viewDidLoad;
-(void)viewDidUnload;

@end
