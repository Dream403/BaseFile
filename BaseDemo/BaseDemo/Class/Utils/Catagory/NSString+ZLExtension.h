//
//  NSString+ZLExtension.h
//  BaseDemo
//
//  Created by snowlu on 2018/1/22.
//  Copyright © 2018年 LittleShrimp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NSData+ZLExtension.h"
@interface NSString (ZLExtension)
/**
 *  转化字符串
 *
 *  @param object object description
 *
 *  @return return value description
 */
NSString *convertToString(id object);
/**
 *  是为空对象
 *
 *  @param object object description
 *
 *  @return return value description
 */
BOOL is_null(id object);

/**
 *  是为空字符串
 *
 *  @param str str description
 *
 *  @return return value description
 */
BOOL isEmpty(NSString* str);

/**
 *
 *
 *  @param font  字体
 *  @param maxW  最大宽度
 *
 *
 */
- (CGSize)sizeWithFont:(UIFont *)font maxW:(CGFloat)maxW;
/**
 *
 *
 *   @param font  字体
 *
 *
 */
- (CGSize)sizeWithFont:(UIFont *)font;
/**
 *  计算大小
 *
 *  @param contentLength contentLength description
 *
 *  @return return value description
 */
NSString * calculateFileSizeInUnit(unsigned long long contentLength);

/**
 * bas64加密
 *
 *  @param content content description
 *
 *
 */
NSString *base64EncodeWith(NSString * content);
/**
 *  解密
 *
 *  @param content content description
 *
 *  @return return value description
 */
NSString *base64DecodeWith(NSString * content);
/**
 *  字符转化JSON
 *
 *  @param jsonString jsonString description
 *
 *  @return return value description
 */
+(NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;
/**
 *  JSON 转化字符串
 *
 *  @param dic dic description
 *
 *  @return return value description
 */
+(NSString*)dictionaryToJson:(NSDictionary *)dic;

/**
 *  返回为空
 *
 *  @param content 通过内容
 *
 *
 */
NSString *defaultValueEmpty(NSString * content);
/**
 *  返回自定义默认值
 *
 *  @param content 通过内容
 *
 *
 */
NSString *defaultValueContent(NSString * content ,NSString * defaultValue);
/**
 *  转变字符串颜色
 *
 *  @param string         string description
 *  @param textColor        myColor 颜色
 *  @param originalString 原字符串
 *
 *  @return return value description
 */
+(NSAttributedString *)converToColorString:(NSString *)string textColor:(UIColor *)textColor withString:(NSString *)originalString;

/**
 *  md5
 *
 *  @param input input description
 *
 *  @return return value description
 */
NSString* md5(NSString* input);

/**
 Description
 
 @param input input description
 @return return value description
 */
NSString* Md532BitUpper(NSString* input);

/**
 MD532
 
 @param input input description
 @return return value description
 */
NSString* Md532BitLower(NSString* input);
/**
 *  解密
 *
 *  @param key key description
 *
 *  @return return value description
 */
-(NSString *) aes256_decrypt:(NSString *)key;

/**
 *  加密
 *
 *  @param plainText plainText description
 *  @param key       key description
 *
 *  @return return value description
 */
+(NSString *)AES128Encrypt:(NSString *)plainText key:(NSString *)key;
/**
 *  解密
 *
 *  @param encryptText <#encryptText description#>
 *  @param key         <#key description#>
 *
 *  @return <#return value description#>
 */
+(NSString *)AES128Decrypt:(NSString *)encryptText key:(NSString *)key;

/**
 *  加密
 *
 *  @param key <#key description#>
 *
 *  @return <#return value description#>
 */
-(NSString *) aes256_encrypt:(NSString *)key;
/**
 *  获取当前时间
 *
 *  @return return value description
 */
+(NSString*)getCurrentTimestamp;
/**
 *  检测电话号码
 *
 *  @param phone phone description
 
 *
 *  @return return value description
 */
+(BOOL)phoneNumberValidity:(NSString *)phone;

/**
 *  检测座机
 *
 *  @param phone phone description
 *
 *  @return return value description
 */
+(BOOL)landlinePhoneNumber:(NSString *)phone;
/**
 *   转变电话格式
 * 136*****8676
 *
 *  @param phone phone description
 *
 *  @return return value description
 */
+(NSString *)ChangedHandsImmediately:(NSString *)phone;
/**
 *  检测身份证
 *
 *  @param value value description
 *
 *  @return return value description
 */

+ (BOOL)accurateVerifyIDCardNumber:(NSString *)value;
/**
 *  转化点次数
 *
 *  @param PlayCount PlayCount description
 *
 *  @return return value description
 */
+(NSString *)convertToStringWtihPlayCount:(NSString *) PlayCount;
/**
 *  URL encode
 *
 *  @param input input description
 *
 *  @return return value description
 */

+(NSString *)encodeToPercentEscapeString: (NSString *) input;
/**
 *  URL decode
 *
 *  @param input input description
 *
 *  @return return value description
 */
+(NSString *)decodeFromPercentEscapeString: (NSString *) input;

/**
 *  时间转化 00：00:00
 *
 *  @param totalSeconds totalSeconds description
 *
 *  @return return value description
 */
+(NSString *)timeFormatted:(int)totalSeconds ;
/**
 *  获取getDocumentsFilePath
 *
 *  @param fileName fileName description
 *
 *  @return return value description
 */
NSString* getDocumentsFilePath(const NSString* fileName);
/**
 *  检测文档
 *
 *  @param filePath filePath description
 *
 *  @return return value description
 */
BOOL checkPathAndCreate(NSString *filePath);
/**
 *  删除文件
 *
 *  @param filePath filePath description
 *
 *  @return return value description
 */
BOOL removeItemAtPath(NSString *filePath);
/**
 *  根据H5标签转化字符串
 *
 *  @param object object description
 *
 *  @return return value description
 */
NSAttributedString *htmlConvertToString( NSString *object);

@end
