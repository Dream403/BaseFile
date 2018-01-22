//
//  UIImage+ZLExtension.h
//  BaseDemo
//
//  Created by snowlu on 2018/1/22.
//  Copyright © 2018年 LittleShrimp. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (ZLExtension)
/**
 *   根据颜色生成图片
 *
 *  @param color  color description
 *  @param size   size description
 *  @param radius radius description
 *
 *  @return return value description
 */
+ (UIImage  *  )imageWithColor:(UIColor *)color size:(CGSize)size cornerRadius:(CGFloat)radius;
/**
 *  根据颜色生成图片
 *
 *  @param color color description
 *  @param size  size description
 *
 *  @return return value description
 */
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;
/**
 *  根据颜色生成图片
 *
 *  @param color color description
 *
 *  @return return value description
 */
+ (UIImage *)imageWithColor:(UIColor *)color;
/**
 *  根据图片获取大小
 *
 *  @param originalImage originalImage description
 *
 *  @return return value description
 */
+ (CGSize )imageWithOriginal:(UIImage *)originalImage ;

/**
 *  CoreImage图片高斯模糊
 *
 *  @param image 图片
 *  @param blur  模糊数值(默认是10)
 *
 *  @return 重新绘制的新图片
 */

+(UIImage *)coreBlurImage:(UIImage *)image withBlurNumber:(CGFloat)blur;
/**
 *  vImage模糊图片
 *
 *  @param image 原始图片
 *  @param blur  模糊数值(0-1)
 *
 *  @return 重新绘制的新图片
 */
+(UIImage *)boxblurImage:(UIImage *)image withBlurNumber:(CGFloat)blur;

/**
 *  加载Gif图片
 *
 *  @param resource bundle地址
 *
 *  @return 返回要加载的Gif图片
 */
+(nullable __kindof UIImage *)imageWithGif:(nullable NSString *)resource;
/**
 *   压缩图片
 *
 *  @param currentImageView currentImageView description
 *  @param image            image description
 *
 *  @return return value description
 */
+ (UIImage *)zlSizeImage:(UIImageView *)currentImageView zlSizeRefresh:(UIImage *)image;

@end
