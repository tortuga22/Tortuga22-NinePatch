//
//  TUCachingNinePatch.m
//  NinePatch
//
//  Copyright 2010 Tortuga 22, Inc. All rights reserved.
//

#import "TUCachingNinePatch.h"
#import "TUNinePatch.h"
#import "TUNinePatchCachingCategories.h"

@implementation TUCachingNinePatch

#pragma mark Synthesized Properties
@synthesize ninePatch = _ninePatch;
@synthesize ninePatchImageCache = _ninePatchImageCache;

#pragma mark Init + Dealloc
-(id)initWithNinePatchNamed:(NSString *)ninePatchName {
	return [self initWithNinePatch:[TUNinePatch ninePatchNamed:ninePatchName]];
}

-(id)initWithNinePatch:(id < TUNinePatch >)ninePatch {
	if (self = [super init]) {
		self.ninePatch = ninePatch;
		self.ninePatchImageCache = [NSMutableDictionary dictionaryWithCapacity:5];
	}
	return self;
}

#pragma mark -
+(id)ninePatchCacheWithNinePatchNamed:(NSString *)ninePatchName {
	return [[[self alloc] initWithNinePatchNamed:ninePatchName] autorelease];
}

+(id)ninePatchCacheWithNinePatch:(id < TUNinePatch >)ninePatch {
	return [[[self alloc] initWithNinePatch:ninePatch] autorelease];
}

#pragma mark -
-(void)dealloc {
	self.ninePatch = nil;
	self.ninePatchImageCache = nil;
	[super dealloc];
}

#pragma mark NSCoding
-(id)initWithCoder:(NSCoder *)aDecoder {
	NSParameterAssert(aDecoder != nil);
	if (self = [super init]) {
		self.ninePatch = [aDecoder decodeObjectForKey:@"ninePatch"];
		self.ninePatchImageCache = [aDecoder decodeObjectForKey:@"ninePatchImageCache"];
	}
	return self;
}

-(void)encodeWithCoder:(NSCoder *)anEncoder {
	NSParameterAssert(anEncoder != nil);
	[anEncoder encodeObject:self.ninePatch 
					 forKey:@"ninePatch"];
	[anEncoder encodeObject:self.ninePatchImageCache 
					 forKey:@"ninePatchImageCache"];
}

#pragma mark NSCopying
-(id)copyWithZone:(NSZone *)zone {
	id < TUNinePatch > copiedNinePatch = [self.ninePatch copyWithZone:zone];
	TUCachingNinePatch *another = [[[self class] allocWithZone:zone] initWithNinePatch:copiedNinePatch];
	return another;
}

#pragma mark Nib
-(void)awakeFromNib {
	[super awakeFromNib];
	if (!self.ninePatchImageCache) { self.ninePatchImageCache = [NSMutableDictionary dictionaryWithCapacity:5]; };
}

#pragma mark Cache Management
-(void)flushCachedImages {
	NPAssertPropertyNonNil(ninePatchImageCache);
	[self.ninePatchImageCache removeAllObjects];
}

#pragma mark Image Access - Utility Accessors
-(UIImage *)imageOfSize:(CGSize)size {
	UIImage *imageOfSize = [self cachedImageOfSize:size];
	if (!imageOfSize) {
		imageOfSize = [self constructImageOfSize:size];
		if (imageOfSize) {
			[self cacheImage:imageOfSize 
					  ofSize:size];
		}
	}
	return imageOfSize;
}

#pragma mark Cache Access
-(void)cacheImage:(UIImage *)image ofSize:(CGSize)size {
	NSAssert(self.ninePatchImageCache != nil, @"Should never have nil self.ninePatchImageCache.");
	NSAssert(image != nil, @"This code will checks if the passed-in image is nil, but we're trying to never wind up calling this method for nil images.");
	if (image) {
		[self.ninePatchImageCache setObject:image 
									forSize:size];
	}
}

-(UIImage *)cachedImageOfSize:(CGSize)size {
	NPAssertPropertyNonNil(ninePatchImageCache);
	//NSAssert(self.ninePatchImageCache != nil, @"Should never have nil self.ninePatchImageCache.");
	return [self.ninePatchImageCache objectForSize:size];
}

#pragma mark Image Construction
-(UIImage *)constructImageOfSize:(CGSize)size {
	return (!self.ninePatch)?(nil):([self.ninePatch imageOfSize:size]);
}

@end
