//
//  NinePatchDemoAppDelegate.m
//  NinePatchDemo
//
//  Copyright Tortuga 22, Inc 2009. All rights reserved.
//

#import "NinePatchDemoAppDelegate.h"
#import "MainViewController.h"

@implementation NinePatchDemoAppDelegate


@synthesize window;
@synthesize mainViewController;


- (void)applicationDidFinishLaunching:(UIApplication *)application {
    
	MainViewController *aController = [[MainViewController alloc] initWithNibName:@"MainView" bundle:nil];
	self.mainViewController = aController;
	[aController release];
	
    mainViewController.view.frame = [UIScreen mainScreen].applicationFrame;
	[window addSubview:[mainViewController view]];
    [window makeKeyAndVisible];
}


- (void)dealloc {
    [mainViewController release];
    [window release];
    [super dealloc];
}

@end
