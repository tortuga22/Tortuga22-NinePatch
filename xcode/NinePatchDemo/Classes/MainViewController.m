//
//  MainViewController.m
//  NinePatchDemo
//
//  Copyright Tortuga 22, Inc 2009. All rights reserved.
//

#import "MainViewController.h"
#import "MainView.h"
#import "NPNinePatchDemoView.h"
#import "NDProtocols.h"

@implementation MainViewController

@synthesize fullNinePatchView = _fullNinePatchView;

@synthesize heightSlider = _heightSlider;
@synthesize widthSlider = _widthSlider;

@synthesize changeButton = _changeButton;
@synthesize cmtButton = _cmtButton;
@synthesize orgButton = _orgButton;

@synthesize upperLeftLabel = _upperLeftLabel;
@synthesize lowerLeftLabel = _lowerLeftLabel;
@synthesize leftLabel = _leftLabel;
@synthesize upperLabel = _upperLabel;
@synthesize lowerLabel = _lowerLabel;
@synthesize upperRightLabel = _upperRightLabel;
@synthesize lowerRightLabel = _lowerRightLabel;
@synthesize rightLabel = _rightLabel;
@synthesize centerLabel = _centerLabel;

@synthesize upperLeftImageView = _upperLeftImageView;
@synthesize lowerLeftImageView = _lowerLeftImageView;
@synthesize leftImageView = _leftImageView;
@synthesize upperImageView = _upperImageView;
@synthesize lowerImageView = _lowerImageView;
@synthesize upperRightImageView = _upperRightImageView;
@synthesize lowerRightImageView = _lowerRightImageView;
@synthesize rightImageView = _rightImageView;

@synthesize activeNinePatch = _activeNinePatch;
@synthesize activeBaseImage = _activeBaseImage;

#pragma mark Status Updating
-(void)updateToNinePatchNamed:(NSString *)ninePatchName {
	self.activeNinePatch = [TUNinePatch ninePatchNamed:ninePatchName];
	self.activeBaseImage = [UIImage imageNamed:[NSString stringWithFormat:@"%@.9.png",ninePatchName]];
	[self.fullNinePatchView updateToNinePatch:self.activeNinePatch 
								originalImage:self.activeBaseImage];
	[self updateImageView:nil 
				 andLabel:[self centerLabel] 
				 forImage:[self.activeNinePatch center]];
	[self updateImageView:[self upperLeftImageView]
				 andLabel:[self upperLeftLabel] 
				 forImage:[self.activeNinePatch upperLeftCorner]];
	[self updateImageView:[self upperRightImageView]
				 andLabel:[self upperRightLabel] 
				 forImage:[self.activeNinePatch upperRightCorner]];
	[self updateImageView:[self lowerLeftImageView]
				 andLabel:[self lowerLeftLabel] 
				 forImage:[self.activeNinePatch lowerLeftCorner]];
	[self updateImageView:[self lowerRightImageView]
				 andLabel:[self lowerRightLabel] 
				 forImage:[self.activeNinePatch lowerRightCorner]];
	[self updateImageView:[self leftImageView]
				 andLabel:[self leftLabel] 
				 forImage:[self.activeNinePatch leftEdge]];
	[self updateImageView:[self rightImageView]
				 andLabel:[self rightLabel] 
				 forImage:[self.activeNinePatch rightEdge]];
	[self updateImageView:[self upperImageView]
				 andLabel:[self upperLabel] 
				 forImage:[self.activeNinePatch upperEdge]];
	[self updateImageView:[self lowerImageView]
				 andLabel:[self lowerLabel] 
				 forImage:[self.activeNinePatch lowerEdge]];
}

-(void)updateImageView:(UIImageView *)imageView andLabel:(UILabel *)label forImage:(UIImage *)image {
	if (image) {
		if (imageView) {
			[imageView setImage:image];
		}
		if (label) {
			[label setText:[NSString stringWithFormat:@"<%.1f,%.1f>",[image size].width,[image size].height]];
		}
	} else {
		if (imageView) {
			[imageView setImage:nil];
		}
		if (label) {
			[label setText:@"n/a"];
		}
	}
}

#pragma mark IBActions
-(IBAction)heightSliderValueDidChange:(id)sender {
	CGFloat value = [self.heightSlider value];
	[self.fullNinePatchView setHeight:floorf(value)];
	DLog(@"self.fullNinePatchView: '%@'.",self.fullNinePatchView);
}

-(IBAction)widthSliderValueDidChange:(id)sender {
	CGFloat value = [self.widthSlider value];
	[self.fullNinePatchView setWidth:floorf(value)];
	DLog(@"self.fullNinePatchView: '%@'.",self.fullNinePatchView);
}

-(IBAction)changeButtonPushed:(id)sender {
	// TODO: throw up the picker
}

-(IBAction)cmtButtonPushed:(id)sender {
	UIViewContentMode newMode = ([self.upperLeftImageView contentMode] == UIViewContentModeCenter)?(UIViewContentModeScaleAspectFit):(UIViewContentModeCenter);
	[self.upperLeftImageView setContentMode:newMode];
	[self.upperRightImageView setContentMode:newMode];
	[self.lowerLeftImageView setContentMode:newMode];
	[self.lowerRightImageView setContentMode:newMode];
	[self.upperImageView setContentMode:newMode];
	[self.lowerImageView setContentMode:newMode];
	[self.rightImageView setContentMode:newMode];
	[self.leftImageView setContentMode:newMode];
}

-(IBAction)orgButtonPushed:(id)sender {
	[self.fullNinePatchView toggleShouldDrawOriginal];
}

#pragma mark Main View Controller
- (void)flipsideViewControllerDidFinish:(FlipsideViewController *)controller {
    
	[self dismissModalViewControllerAnimated:YES];
}


- (IBAction)showInfo {    
	
	FlipsideViewController *controller = [[FlipsideViewController alloc] initWithNibName:@"FlipsideView" 
																				  bundle:nil];
	controller.delegate = self;
	
	controller.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
	[self presentModalViewController:controller animated:YES];
	
	[controller release];
}


#pragma mark Lifecycle
-(void)viewDidLoad {
	[super viewDidLoad];
	// TODO: set up nine-patch images
	[self updateToNinePatchNamed:@"testButton"];
	[self.fullNinePatchView setNinePatchSize:CGSizeMake([self.widthSlider value], [self.heightSlider value])];
}

-(void)viewDidUnload {
	self.leftLabel = nil;
	self.rightLabel = nil;
	self.upperLabel = nil;
	self.lowerLabel = nil;
	self.upperLeftLabel = nil;
	self.upperRightLabel = nil;
	self.lowerLeftLabel = nil;
	self.lowerRightLabel = nil;
	self.leftImageView = nil;
	self.rightImageView = nil;
	self.upperImageView = nil;
	self.lowerImageView = nil;
	self.upperLeftImageView = nil;
	self.upperRightImageView = nil;
	self.lowerLeftImageView = nil;
	self.lowerRightImageView = nil;
	self.activeNinePatch = nil;
	self.activeBaseImage = nil;
	
	self.orgButton = nil;
	self.cmtButton = nil;
	self.changeButton = nil;
	
	self.fullNinePatchView = nil;
	self.heightSlider = nil;
	self.widthSlider = nil;
	[super viewDidUnload];
}

@end
