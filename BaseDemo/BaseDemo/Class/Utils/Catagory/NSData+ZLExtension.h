//
//  NSData+ZLExtension.h
//  BaseDemo
//
//  Created by snowlu on 2018/1/22.
//  Copyright © 2018年 LittleShrimp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonCryptor.h>
@interface NSData (ZLExtension)
/**
 *  加密
 *
 *  @param key key description
 *
 *  @return return value description
 */
-(NSData *) aes256_encrypt:(NSString *)key;
/**
 *  解密
 *
 *  @param key key description
 *
 *  @return return value description
 */
-(NSData *) aes256_decrypt:(NSString *)key;
/**
 *  加密
 *
 *  @param key key description
 *
 *  @return return value description
 */
- (NSData *)AES128EncryptWithKey:(NSString *)key;
/**
 *  解密
 *
 *  @param key key description
 *
 *  @return return value description
 */
- (NSData *)AES128DecryptWithKey:(NSString *)key;
/**
 *  Description
 *
 *  @return return value description
 */
- (NSData *)UTF8Data;
@end
