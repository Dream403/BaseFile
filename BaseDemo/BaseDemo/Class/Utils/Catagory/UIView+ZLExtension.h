//
//  UIView+ZLExtension.h
//  BaseDemo
//
//  Created by snowlu on 2018/1/22.
//  Copyright © 2018年 LittleShrimp. All rights reserved.
//

#import <UIKit/UIKit.h>
// 理想线宽
#define LINE_WIDTH 1
// 实际应该显示的线宽
#define SINGLE_LINE_WIDTH           floor((LINE_WIDTH / [UIScreen mainScreen].scale)*100) / 100

//偏移的宽度
#define SINGLE_LINE_ADJUST_OFFSET   floor(((LINE_WIDTH / [UIScreen mainScreen].scale) / 2)*100) / 100

typedef NS_ENUM(NSInteger,UILayoutCornerRadiusType) {
    /**
     *  圆角顶部
     */
    UILayoutCornerRadiusTop = 0,
    /**
     *  圆角左边
     */
    UILayoutCornerRadiusLeft = 1,
    /**
     *  圆角底部
     */
    UILayoutCornerRadiusBottom = 2,
    /**
     *  圆角右边
     */
    UILayoutCornerRadiusRight = 3,
    /**
     *  圆角四边
     */
    UILayoutCornerRadiusAll = 4,
};

@interface UIView (ZLExtension)

@property (nonatomic, assign) CGFloat x;

@property (nonatomic, assign) CGFloat y;

@property (nonatomic, assign) CGFloat centerX;

@property (nonatomic, assign) CGFloat centerY;

@property (nonatomic, assign) CGFloat width;

@property (nonatomic, assign) CGFloat height;

@property (nonatomic, assign) CGSize size;

@property (nonatomic, assign) CGPoint origin;

@property (nonatomic,assign) CGFloat cornerRadius;
/**
 *   画底部线
 *
 *  @param color       颜色
 *  @param borderWidth 宽度
 */

- (void)addBottomBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth;
/**
 *   画底部线
 *
 *  @param color       color description
 *  @param borderWidth borderWidth description
 *  @param viewWidth   viewWidth description
 */
- (void)addBottomBorderWithColor:(UIColor *)color andWidth:(CGFloat) borderWidth andViewWidth:(CGFloat)viewWidth;
/**
 *   画底左边线
 *
 *  @param color       color description
 *  @param borderWidth borderWidth description
 */
- (void)addLeftBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth;
/**
 *  画底左右边
 *
 *  @param color       color description
 *  @param borderWidth borderWidth description
 */
- (void)addRightBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth;
/**
 *  画底顶部线
 *
 *  @param color       color description
 *  @param borderWidth borderWidth description
 */
- (void)addTopBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth;
/**
 *  画底顶部线
 *
 *  @param color       color description
 *  @param borderWidth borderWidth description
 *  @param viewWidth   viewWidth description
 */
- (void)addTopBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth andViewWidth:(CGFloat) viewWidth;
/**
 *
 *  设置不同边的圆角
 *
 *  @param sideType 圆角类型
 *  @param cornerRadius 圆角半径
 */
- (void)UILayoutCornerRadiusType:(UILayoutCornerRadiusType)sideType withCornerRadius:(CGFloat)cornerRadius;


@end
