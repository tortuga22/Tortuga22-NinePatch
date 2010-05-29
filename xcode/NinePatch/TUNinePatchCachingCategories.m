//
//  TUNinePatchCachingCategories.m
//  NinePatch
//
//  Copyright 2010 Tortuga 22, Inc. All rights reserved.
//

#import "TUNinePatchCachingCategories.h"

@implementation NSString (NinePatchCaching)

+(NSString *)ninePatchKeyStringForSize:(CGSize)size {
	return [NSString stringWithFormat:@"ninePatchKeyString.%#.0f.%#.0f",size.width,size.height];
}

@end

@implementation NSDictionary (NinePatchCaching)

-(id)objectForSize:(CGSize)size {
	id object = nil;
	NSString *key = [NSString ninePatchKeyStringForSize:size];
	if (key) {
		object = [self objectForKey:key];
	}
	return object;
}

@end

@implementation NSMutableDictionary (NinePatchCaching)

-(void)setObject:(id)object forSize:(CGSize)size {
	if (object) {
		NSString *key = [NSString ninePatchKeyStringForSize:size];
		if (key) {
			[self setObject:object forKey:key];
		}
	}
}

@end
