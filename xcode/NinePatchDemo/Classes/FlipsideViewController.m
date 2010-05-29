//
//  FlipsideViewController.m
//  NinePatchDemo
//
//  Copyright Tortuga 22, Inc 2009. All rights reserved.
//

#import "FlipsideViewController.h"
#import "NPContentNinePatchDemoView.h"


@implementation FlipsideViewController

@synthesize fullNinePatchDemoView = _fullNinePatchDemoView;
@synthesize slider = _slider;
@synthesize delegate;


- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor viewFlipsideBackgroundColor];      
	[self.fullNinePatchDemoView setNinePatch:[TUNinePatch ninePatchNamed:@"testButtonContent"]];
	[self.fullNinePatchDemoView redrawWithFontSize:floorf([self.slider value])];
}

-(IBAction)sliderValueDidChange:(id)sender {
	[self.fullNinePatchDemoView redrawWithFontSize:floorf([self.slider value])];
}

- (IBAction)done {
	[self.delegate flipsideViewControllerDidFinish:self];	
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)viewDidUnload {
	self.slider = nil;
	self.fullNinePatchDemoView = nil;
}


- (void)dealloc {
    [super dealloc];
}


@end
