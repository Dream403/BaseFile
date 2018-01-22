//
//  ZLCommonDefines.h
//  BaseDemo
//
//  Created by snowlu on 2018/1/22.
//  Copyright © 2018年 LittleShrimp. All rights reserved.
//

#ifndef ZLCommonDefines_h
#define ZLCommonDefines_h

#define  ZLWMImageNamed(imageName)   [UIImage imageNamed:imageName]

#define  ZLWMUserDefaults        [NSUserDefaults standardUserDefaults]

#define  ZLWMNotificationCenter      [NSNotificationCenter defaultCenter]

#define delay(block)\
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{\
block();\
});\

#define AppVersion  [[[NSBundle mainBundle] infoDictionary] valueForKey:@"CFBundleShortVersionString"]

#define AppBuildVersion  [[[NSBundle mainBundle] infoDictionary] valueForKey:@"CFBundleVersion"]

// 格式化字符串
#define FormatString(string, args...)       [NSString stringWithFormat:string, args]

#define URLFromString(str)                      [NSURL URLWithString:str]

#define ZLWMLocalString(key) NSLocalizedStringFromTable(key, @"Localizable", nil)

#define ALERT(msg) [[[UIAlertView alloc] initWithTitle:nil message:msg delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil] show]

//防止循环引用
#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

#define WSSTRONG(strongSelf) __strong typeof(weakSelf) strongSelf = weakSelf;

#define iOS7                                ((floor(NSFoundationVersionNumber) <= NSFoundationVersionNumber_iOS_6_1)? NO:YES)

#define iOS11 @available(iOS 11.0, *)

#define IS_RETINA ([[UIScreen mainScreen] scale] >= 2.0)

#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)

#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)

#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))

#define SCREEN_MIN_LENGTH (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))


#define iOS11Later ([UIDevice currentDevice].systemVersion.floatValue >= 11.0f)

#define ZLSCALWIDTH (SCREEN_WIDTH/375.0)

#define ZLSCALHEIGHT (SCREEN_HEIGHT/667.0)

#define StatusBar_HEIGHT [[UIApplication sharedApplication] statusBarFrame].size.height

// iPhone X
#define  ZL_iPhoneX (SCREEN_WIDTH == 375.f && SCREEN_HEIGHT == 812.f ? YES : NO)
// Tabbar height.
#define  ZL_TabbarHeight         (ZL_iPhoneX ? (49.f+34.f) : 49.f)
// Tabbar safe bottom margin.
#define  ZL_TabbarSafeBottomMargin         (ZL_iPhoneX ? 34.f : 0.f)

#define NavBarHeight                        (iOS7 ? (ZL_iPhoneX ? 88.f : 64.f) : 44.0)

#define HS_iPhoneXStatusBarHeight                      (ZL_iPhoneX ? 44.f : 0)

#define StatusBarHeight                     (iOS7 ? (ZL_iPhoneX ? 44.f : 20.f) : 0.0)

#define Number(num)                      (num*LSSCALWIDTH)

#define NumberHeight(num)                      (num*LSSCALHEIGHT)

#define AutomaticallyAdjustsScrollViewInsetsNO(view) if (@available(iOS 11.0, *)) {view.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;}else{self.automaticallyAdjustsScrollViewInsets = NO;}

#define ZL_ViewSafeAreInsets(view) ({UIEdgeInsets insets; if(@available(iOS 11.0, *)) {insets = view.safeAreaInsets;} else {insets = UIEdgeInsetsZero;} insets;})
// UTF8 字符串
#define UTF8Data(str) [str dataUsingEncoding:NSUTF8StringEncoding]

#ifdef __OBJC__
#ifdef DEBUG
# define NSLog(fmt, ...) NSLog((@"[文件名:%s]\n" "[函数名:%s]\n" "[行号:%d] \n" fmt), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
# define NSLog(...);
#endif

#endif


#endif /* ZLCommonDefines_h */
