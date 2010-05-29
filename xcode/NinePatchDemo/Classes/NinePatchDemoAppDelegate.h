//
//  NinePatchDemoAppDelegate.h
//  NinePatchDemo
//
//  Copyright Tortuga 22, Inc 2009. All rights reserved.
//

@class MainViewController;

@interface NinePatchDemoAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    MainViewController *mainViewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) MainViewController *mainViewController;

@end

