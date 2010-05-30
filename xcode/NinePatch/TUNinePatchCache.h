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
/**
 
 This class is included to make it easy to work with NinePatches if (1) all you want are static images (you don't care much about drawing into CGContextRefs) and (2) . Its semantics are probably non-optimal but are very straightforward: it caches every single request you make to it (both NinePatches and the rendered images). If you're only generating a handful of images and/or you're not super memory-constrained you should probably use this class. It has functionality for flushing the cache with various levels of granularity if you need such functionality.
 
 */
@interface TUNinePatchCache : NSObject {
	NSMutableDictionary *_ninePatchCache;
}

// Synthesized Properties
/** 
 This is where the NinePatches get cached. You should pretty much never look at or manipulate this directly. If I believed in private instance variables this's be private. Maybe I'll make it private soon.
 */
@property(nonatomic, retain, readonly) NSMutableDictionary *ninePatchCache;

-(id)init;
/**
 Gets at the application's shared instance, creating it if it doesn't exist.
 */
+(id)shared;

// Getting Ninepatches Directly
/**
 Use this method to get at the actual NinePatch you want to interact with (if eg you're using this cache but need finer-grained control than just generating images). Will load the NinePatch (from the app's main bundle) if it doesn't exist yet.
 
 @param ninePatchName The name of the NinePatch you're trying to get at.
 @returns The NinePatch object you wanted. Can return nil if problems were encountered.
 */
-(id < TUNinePatch >)ninePatchNamed:(NSString *)ninePachName;

// These methods should be private, if I believed in private methods
-(TUCachingNinePatch *)cachingNinePatchNamed:(NSString *)ninePatchName;
-(void)cacheCachingNinePatch:(TUCachingNinePatch *)cachingNinePatch named:(NSString *)ninePatchName;
-(TUCachingNinePatch *)cachedCachingNinePatchNamed:(NSString *)ninePatchName;
-(TUCachingNinePatch *)constructCachingNinePatchNamed:(NSString *)ninePatchName;

// Getting Images Directly
/**
 This method renders the image at the requested size using the NinePatch with the passed-in name. Tries to use a cached image and/or NinePatch as possible, otherwise loading from scratch. Any NinePatch or image it loads is subsequently cached.

 @param size The size the output image should be rendered at.
 @param ninePatchName the name of the NinePatch you want to use to render the image. Don't include @".9.png" in the name.
 @returns An image rendered from the specified ninePatchName at the requested size. Can return nil if difficulties were encountered. Image should be retained if it is important it be held onto by the recipient, but should not be released by the recipient.
 */
-(UIImage *)imageOfSize:(CGSize)size forNinePatchNamed:(NSString *)ninePatchName;

// Getting Ninepatches - Convenience
/**
 Semantics same as instance-level method of same name, but calls through to the singleton instance.
 */
+(id < TUNinePatch >)ninePatchNamed:(NSString *)ninePatchName;

// Getting Images - Convenience
/**
 This is a convenience method; calls instance method of the same name on the singleton. Easiest way to use this in your code.
 */
+(UIImage *)imageOfSize:(CGSize)size forNinePatchNamed:(NSString *)ninePatchName;

// Cache Management - Direct
/**
 Flushes all cached content (NinePatches AND their cached rendered images, if any).
 */
-(void)flushCache;
/**
 Flushes only the content for the NinePatch with the passed-in name. Won't complain if there's no cached NinePatch with the passed-in name.
 */
-(void)flushCacheForNinePatchNamed:(NSString *)name;

// Cache Management - Convenience
/**
 Flushes all cached content from the singleton.
 */
+(void)flushCache;

/**
 Flushes the NinePatch with the passed-in name from the singleton (which also flushes any cached images).
 */
+(void)flushCacheForNinePatchNamed:(NSString *)name;

@end
