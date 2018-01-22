//
//  ZLColorDefines.h
//  BaseDemo
//
//  Created by snowlu on 2018/1/22.
//  Copyright © 2018年 LittleShrimp. All rights reserved.
//

#ifndef ZLColorDefines_h
#define ZLColorDefines_h


/**
 *  字体
 *
 *  @param Size Size description
 *
 *  @return return value description
 */
#define FontPingFangSC(Size) [UIFont fontWithName:@"PingFangSC-Regular" size:Size*ZLSCALWIDTH]

#define FontPingFangBoldSC(Size) [UIFont fontWithName:@"PingFangSC-Bold" size:Size*ZLSCALWIDTH]
//
#define FontPingFangLG(Size) [UIFont fontWithName:@"PingFangSC-Light" size:Size*ZLSCALWIDTH]

#define FontHelFont(Size) [UIFont fontWithName:@"Helvetica" size:Size*ZLSCALWIDTH]

#define FontNormal(Size) [UIFont systemFontOfSize:Size*ZLSCALWIDTH]

#define  ColorRandom  [UIColor colorWithRed:arc4random_uniform(255)/255.0 green:arc4random_uniform(255)/255.0 blue:arc4random_uniform(255)/255.0 alpha:1]

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define UIColorFromRGBA(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:a]

#endif /* ZLColorDefines_h */
