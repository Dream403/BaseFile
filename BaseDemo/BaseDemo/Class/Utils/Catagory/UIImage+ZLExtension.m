//
//  UIImage+ZLExtension.m
//  BaseDemo
//
//  Created by snowlu on 2018/1/22.
//  Copyright © 2018年 LittleShrimp. All rights reserved.
//

#import "UIImage+ZLExtension.h"
#import <Accelerate/Accelerate.h>
@implementation UIImage (ZLExtension)

+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size cornerRadius:(CGFloat)radius {
    UIGraphicsBeginImageContextWithOptions(size, NO, 0);
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSaveGState(ctx);
    if (radius > 0.0f && radius <= size.width && radius <= size.height) {
        UIBezierPath *path = [UIBezierPath bezierPathWithRoundedRect:CGRectMake(0, 0, size.width, size.height) cornerRadius:radius];
        [color setFill];
        [path fill];
    } else {
        CGContextSetFillColorWithColor(ctx, color.CGColor);
        CGContextFillRect(ctx, CGRectMake(0, 0, size.width, size.height));
    }
    CGContextRestoreGState(ctx);
    UIImage *img = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return img;
}

+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size {
    return [UIImage imageWithColor:color size:size cornerRadius:0.0f];
}

+ (UIImage *)imageWithColor:(UIColor *)color {
    return [UIImage imageWithColor:color size:CGSizeMake(1, 1)];
}
+ (CGSize )imageWithOriginal:(UIImage *)originalImage {
    
    return CGSizeMake(originalImage.size.width / [UIScreen mainScreen].scale, originalImage.size.height / [UIScreen mainScreen].scale);
    ;
}
+(UIImage *)coreBlurImage:(UIImage *)image
           withBlurNumber:(CGFloat)blur {
    //博客园-FlyElephant
    CIContext *context = [CIContext contextWithOptions:nil];
    CIImage  *inputImage=[CIImage imageWithCGImage:image.CGImage];
    //设置filter
    CIFilter *filter = [CIFilter filterWithName:@"CIGaussianBlur"];
    [filter setValue:inputImage forKey:kCIInputImageKey];
    [filter setValue:@(blur) forKey: @"inputRadius"];
    //模糊图片
    CIImage *result=[filter valueForKey:kCIOutputImageKey];
    CGImageRef outImage=[context createCGImage:result fromRect:[result extent]];
    UIImage *blurImage=[UIImage imageWithCGImage:outImage];
    CGImageRelease(outImage);
    return blurImage;
}


+(UIImage *)boxblurImage:(UIImage *)image withBlurNumber:(CGFloat)blur {
    if (blur < 0.f || blur > 1.f) {
        blur = 0.5f;
    }
    int boxSize = (int)(blur * 40);
    boxSize = boxSize - (boxSize % 2) + 1;
    
    CGImageRef img = image.CGImage;
    
    vImage_Buffer inBuffer, outBuffer;
    vImage_Error error;
    
    void *pixelBuffer;
    //从CGImage中获取数据
    CGDataProviderRef inProvider = CGImageGetDataProvider(img);
    CFDataRef inBitmapData = CGDataProviderCopyData(inProvider);
    //设置从CGImage获取对象的属性
    inBuffer.width = CGImageGetWidth(img);
    inBuffer.height = CGImageGetHeight(img);
    inBuffer.rowBytes = CGImageGetBytesPerRow(img);
    
    inBuffer.data = (void*)CFDataGetBytePtr(inBitmapData);
    
    pixelBuffer = malloc(CGImageGetBytesPerRow(img) *
                         CGImageGetHeight(img));
    
    if(pixelBuffer == NULL)
        NSLog(@"No pixelbuffer");
    
    outBuffer.data = pixelBuffer;
    outBuffer.width = CGImageGetWidth(img);
    outBuffer.height = CGImageGetHeight(img);
    outBuffer.rowBytes = CGImageGetBytesPerRow(img);
    
    error = vImageBoxConvolve_ARGB8888(&inBuffer, &outBuffer, NULL, 0, 0, boxSize, boxSize, NULL, kvImageEdgeExtend);
    
    if (error) {
        NSLog(@"error from convolution %ld", error);
    }
    
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef ctx = CGBitmapContextCreate(
                                             outBuffer.data,
                                             outBuffer.width,
                                             outBuffer.height,
                                             8,
                                             outBuffer.rowBytes,
                                             colorSpace,
                                             kCGImageAlphaNoneSkipLast);
    CGImageRef imageRef = CGBitmapContextCreateImage (ctx);
    UIImage *returnImage = [UIImage imageWithCGImage:imageRef];
    
    //clean up
    CGContextRelease(ctx);
    CGColorSpaceRelease(colorSpace);
    
    free(pixelBuffer);
    CFRelease(inBitmapData);
    
    CGColorSpaceRelease(colorSpace);
    CGImageRelease(imageRef);
    
    return returnImage;
}

+(nullable __kindof UIImage *)imageWithGif:(nullable NSString *)resource
{
    NSString *path =[[NSBundle mainBundle] pathForResource:resource ofType:@"gif"];
    NSData *data =[NSData dataWithContentsOfFile:path];
    UIImage *image = [UIImage saka_animatedGIFWithData:data];
    return image;
}

+ (UIImage *)saka_animatedGIFWithData:(NSData *)data
{
    if (!data) {
        return nil;
    }
    
    CGImageSourceRef source = CGImageSourceCreateWithData((__bridge CFDataRef)data, NULL);
    
    size_t count = CGImageSourceGetCount(source);
    
    UIImage *staticImage;
    
    if (count <= 1) {
        staticImage = [[UIImage alloc] initWithData:data];
    } else {
        NSMutableArray *images =[NSMutableArray array];
        NSTimeInterval duration = 0.0f;
        for (size_t i =0; i <count; i ++)
        {
            CGImageRef image = CGImageSourceCreateImageAtIndex(source, i, NULL);
            if (!image) {
                continue;
            }
            duration +=[UIImage frameDurationAtIndex:i Source:source];
            [images addObject:[UIImage imageWithCGImage:image scale:[UIScreen mainScreen].scale orientation:UIImageOrientationUp]];
            CGImageRelease(image);
        }
        if (!duration) {
            duration = (1.0f / 10.0f) * count;
        }
        
        staticImage = [UIImage animatedImageWithImages:images duration:duration];
    }
    
    CFRelease(source);
    
    return staticImage;
}

+(CGFloat)frameDurationAtIndex:(NSInteger)index Source:(CGImageSourceRef)source
{
    CGFloat frameDuration = 0.1f;
    CFDictionaryRef frame = CGImageSourceCopyPropertiesAtIndex(source, index, NULL);
    NSDictionary *frameProperties =(__bridge NSDictionary *)(frame);
    NSDictionary *gifProperties = frameProperties[(NSString *)kCGImagePropertyGIFDictionary];
    NSNumber *delayTimeUnclampedProp = gifProperties[(NSString *)kCGImagePropertyGIFUnclampedDelayTime];
    if (delayTimeUnclampedProp) {
        frameDuration = [delayTimeUnclampedProp floatValue];
    }
    else {
        
        NSNumber *delayTimeProp = gifProperties[(NSString *)kCGImagePropertyGIFDelayTime];
        if (delayTimeProp) {
            frameDuration = [delayTimeProp floatValue];
        }
    }
    if (frameDuration < 0.011f) {
        frameDuration = 0.100f;
    }
    
    CFRelease(frame);
    return frameDuration;
}

+ (UIImage *)zlSizeImage:(UIImageView *)currentImageView zlSizeRefresh:(UIImage *)image
{
    //要加载的图片取其宽和高中较小的那个值
    CGFloat widthAndH = (image.size.height>image.size.width)?image.size.width:image.size.height;
    
    CGRect rect;
    
    //要加载图片的UIImageView宽和高中较大的那个值 然后按照等比例去截取图片使其被压缩时不变形
    if (currentImageView.frame.size.height > currentImageView.frame.size.width) {
        
        rect = CGRectMake(0, 0, currentImageView.frame.size.width*widthAndH/currentImageView.frame.size.height, widthAndH);
        
    }else{
        
        rect = CGRectMake(0, 0, widthAndH, currentImageView.frame.size.height*widthAndH/currentImageView.frame.size.width);
        
    }
    UIImage *imageRegresh = [UIImage imageWithCGImage:CGImageCreateWithImageInRect([image CGImage], rect)];
    
    UIImage *zlSizeImage;
    
    //要判断将要压缩的图片的尺寸大小是不是大于我们想要的那个尺寸 在做相应处理
    if (widthAndH>currentImageView.frame.size.width*2 && widthAndH>currentImageView.frame.size.height*2) {
        
        CGSize size = CGSizeMake(currentImageView.frame.size.width*2, currentImageView.frame.size.height*2);
        
        zlSizeImage = [self reSizeImage:imageRegresh toSize:size];
        
    }else{
        
        zlSizeImage = imageRegresh;
        
    }
    
    return zlSizeImage;
}
+ (UIImage *)reSizeImage:(UIImage *)image toSize:(CGSize)reSize
{
    UIGraphicsBeginImageContext(CGSizeMake(reSize.width, reSize.height));
    [image drawInRect:CGRectMake(0, 0, reSize.width, reSize.height)];
    UIImage *reSizeImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return reSizeImage;
}

@end
