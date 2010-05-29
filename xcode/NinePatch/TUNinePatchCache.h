//
//  TUNinePatchCache.h
//  NinePatch
//
//  Copyright 2010 Tortuga 22, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TUNinePatchProtocols.h"

@class TUCachingNinePatch;

@interface TUNinePatchCache : NSObject {
	NSMutableDictionary *_ninePatchCache;
}

// Synthesized Properties
@property(nonatomic, retain) NSMutableDictionary *ninePatchCache;

-(id)init;
+(id)shared;

// Getting Ninepatches Directly
-(id < TUNinePatch >)ninePatchNamed:(NSString *)ninePachName;

-(TUCachingNinePatch *)cachingNinePatchNamed:(NSString *)ninePatchName;
-(void)cacheCachingNinePatch:(TUCachingNinePatch *)cachingNinePatch named:(NSString *)ninePatchName;
-(TUCachingNinePatch *)cachedCachingNinePatchNamed:(NSString *)ninePatchName;
-(TUCachingNinePatch *)constructCachingNinePatchNamed:(NSString *)ninePatchName;

// Getting Images Directly
-(UIImage *)imageOfSize:(CGSize)size forNinePatchNamed:(NSString *)ninePatchName;

// Getting Ninepatches - Convenience
+(id < TUNinePatch >)ninePatchNamed:(NSString *)ninePatchName;

// Getting Images - Convenience
+(UIImage *)imageOfSize:(CGSize)size forNinePatchNamed:(NSString *)ninePatchName;

// Cache Management - Direct
-(void)flushCache;
-(void)flushCacheForNinePatchNamed:(NSString *)name;

// Cache Management - Convenience
+(void)flushCache;
+(void)flushCacheForNinePatchNamed:(NSString *)name;

@end
