//
//  NDProtocols.h
//  NinePatchDemo
//
//  Copyright 2009 Tortuga 22, Inc. All rights reserved.
//


#import <UIKit/UIKit.h>

#define DEBUG

// DLog is almost a drop-in replacement for NSLog  
// DLog();  
// DLog(@"here");  
// DLog(@"value: %d", x);  
// Unfortunately this doesn't work DLog(aStringVariable); you have to do this instead DLog(@"%@", aStringVariable);  
#ifdef DEBUG  
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);  
#else  
#   define DLog(...)  
#endif  

// ALog always displays output regardless of the DEBUG setting  
#define ALog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);  

#define LLog(STR) DLog(@"%@",STR)
