//
//  FlipsideViewController.h
//  NinePatchDemo
//
//  Copyright Tortuga 22, Inc 2009. All rights reserved.
//

@protocol FlipsideViewControllerDelegate;

@class NPContentNinePatchDemoView;

@interface FlipsideViewController : UIViewController {
	id <FlipsideViewControllerDelegate> delegate;
	
	NPContentNinePatchDemoView *_fullNinePatchDemoView;
	UISlider *_slider;
}

@property(nonatomic, retain) IBOutlet NPContentNinePatchDemoView *fullNinePatchDemoView;
@property(nonatomic, retain) IBOutlet UISlider *slider;

@property (nonatomic, assign) id <FlipsideViewControllerDelegate> delegate;
- (IBAction)done;

-(IBAction)sliderValueDidChange:(id)sender;

@end


@protocol FlipsideViewControllerDelegate
- (void)flipsideViewControllerDidFinish:(FlipsideViewController *)controller;
@end

