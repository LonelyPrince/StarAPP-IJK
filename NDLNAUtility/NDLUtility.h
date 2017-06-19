//
//  NDLUtility.h
//  DLNASample
//
//  Created by 田中 浩一 on 12/06/28.
//  Copyright (c) 2012 エヌエスプランニング株式会社. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CGUpnpDevice;
@class CGUpnpAvObject;

@interface NDLUtility : NSObject
//获取dms设备信息
+ (NSArray*)getDmsInfo:(CGUpnpDevice *)dev dmsNum:(int) dmsNum;
//Container 容器
+ (NSArray*)getContainer:(CGUpnpAvObject*)aAvObject objectId:(NSString*)aObjectId;
@end
