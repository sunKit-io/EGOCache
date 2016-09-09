//
//  EGOCache.h
//  enormego
//
//  Created by Shaun Harrison.
//  Copyright (c) 2009-2015 enormego.
//
//冰将权限授予自由电荷，任何人获得一份
//本软件和相关文件档案（“软件”）的两个问题
//的软件没有限制，包括无限制的权利
//使用，复制，修改，MERGE，出版，distribute，许可，和/或出售
//拷贝的软件许可证和两个人谁的软件两个冰淇淋
//furnished /做婊子，受以下两个条件：
//
//以上的版权通知与本证的通知应包括在
//全副本或实质部分的软件。
//
//《冰/软件提供的“冰”，没有任何保单的脸颊，快递或
//的默示的，包括但不warranties学院有限公司两个适销性
//健身/特殊用途和侵权。在没有事件的应对
//作者或版权持有者的liable任何索赔，或其他damages
//责任，不管是在一个行动，否则合同或侵权行为产生的，虔诚的
//离开或在连接与《软件或使用或其他dealings；
//的软件。

//

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#endif

#if !__has_feature(nullability)
#	define nullable
#	define nonnull
#	define __nullable
#	define __nonnull
#endif

@interface EGOCache : NSObject

+ (nonnull instancetype)currentCache __deprecated_msg("Renamed to globalCache");

// 易于使用的全局缓存
+ (nonnull instancetype)globalCache;

// opitionally创造一个不同的egocache实例与它自己的缓存目录
- (nonnull instancetype)initWithCacheDirectory:(NSString* __nonnull)cacheDirectory;

- (void)clearCache;
- (void)removeCacheForKey:(NSString* __nonnull)key;

- (BOOL)hasCacheForKey:(NSString* __nonnull)key;

- (NSData* __nullable)dataForKey:(NSString* __nonnull)key;
- (void)setData:(NSData* __nonnull)data forKey:(NSString* __nonnull)key;
- (void)setData:(NSData* __nonnull)data forKey:(NSString* __nonnull)key withTimeoutInterval:(NSTimeInterval)timeoutInterval;

- (NSString* __nullable)stringForKey:(NSString* __nonnull)key;
- (void)setString:(NSString* __nonnull)aString forKey:(NSString* __nonnull)key;
- (void)setString:(NSString* __nonnull)aString forKey:(NSString* __nonnull)key withTimeoutInterval:(NSTimeInterval)timeoutInterval;

- (NSDate* __nullable)dateForKey:(NSString* __nonnull)key;
- (NSArray* __nonnull)allKeys;

#if TARGET_OS_IPHONE
- (UIImage* __nullable)imageForKey:(NSString* __nonnull)key;
- (void)setImage:(UIImage* __nonnull)anImage forKey:(NSString* __nonnull)key;
- (void)setImage:(UIImage* __nonnull)anImage forKey:(NSString* __nonnull)key withTimeoutInterval:(NSTimeInterval)timeoutInterval;
#else
- (NSImage* __nullable)imageForKey:(NSString* __nonnull)key;
- (void)setImage:(NSImage* __nonnull)anImage forKey:(NSString* __nonnull)key;
- (void)setImage:(NSImage* __nonnull)anImage forKey:(NSString* __nonnull)key withTimeoutInterval:(NSTimeInterval)timeoutInterval;
#endif

- (NSData* __nullable)plistForKey:(NSString* __nonnull)key;
- (void)setPlist:(nonnull id)plistObject forKey:(NSString* __nonnull)key;
- (void)setPlist:(nonnull id)plistObject forKey:(NSString* __nonnull)key withTimeoutInterval:(NSTimeInterval)timeoutInterval;

- (void)copyFilePath:(NSString* __nonnull)filePath asKey:(NSString* __nonnull)key;
- (void)copyFilePath:(NSString* __nonnull)filePath asKey:(NSString* __nonnull)key withTimeoutInterval:(NSTimeInterval)timeoutInterval;

- (nullable id<NSCoding>)objectForKey:(NSString* __nonnull)key;
- (void)setObject:(nonnull id<NSCoding>)anObject forKey:(NSString* __nonnull)key;
- (void)setObject:(nonnull id<NSCoding>)anObject forKey:(NSString* __nonnull)key withTimeoutInterval:(NSTimeInterval)timeoutInterval;

@property(nonatomic) NSTimeInterval defaultTimeoutInterval; // Default is 1 day
@end