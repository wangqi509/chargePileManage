//
//  QCDataCacheTool.h
//  chargePileManage
//
//  Created by YuMing on 16/6/20.
//  Copyright © 2016年 shQianChen. All rights reserved.
//

#import <Foundation/Foundation.h>
@class QCPileListNumModel;
@class QCPileListDataMode;
@class QCPileListUserModel;

@class QCChargeRecordModel;
@class QCSupplyRecordModel;
@class QCFaultRecordModel;

@interface QCDataCacheTool : NSObject
/**
 *  缓存一条数据
 */
//- (void)addChargePileData:(NSString *)dbName sqlCmd:(NSString *)sqlCmd dict:(NSDictionary *)dict;
//+ (void) addChargePileData:(NSDictionary *) dict;
// 保存多条充电桩号码模型数据
- (void)addChargePileDatas:(NSString *)dbName sqlCmd:(NSString *)sqlCmd cpNumArray:(NSArray *)cpArray;
/**
 *  缓存N条数据
 */
//- (void)addChargePileDatas:(NSString *)dbName sqlCmd:(NSString *)sqlCmd array:(NSArray *)dictArray;
//+ (void)addChargePileDatas:(NSArray *)dictArray;
// 保存一条充电桩号码模型数据
- (void)addChargePileData:(NSString *)dbName sqlCmd:(NSString *)sqlCmd chargeNum:(QCPileListNumModel *)number;
- (void)addChargePileData:(NSString *)dbName sqlData:(NSString *)sqlCmd cpData:(QCPileListDataMode *)data;
- (void)addChargePileUser:(NSString *)dbName cpData:(QCPileListUserModel *)data;

/**
 *  初始化
 */
- (instancetype) initWithDBName:(NSString *)dbName sqlCmd:(NSString *)sqlCmd;

/**
 *  读取数据
 */
- (NSArray *)cpDataWithParam:(NSString *)dbName;
- (NSArray *)getCPListWithParam:(NSString *)dbName;
- (NSArray *)getChargePileUser:(NSString *) dbName;

#pragma - mark store and get cpid
- (NSArray *)getCPListNumberWithParam:(NSString *)dbName;
- (void) storeCPListNumberWithParam:(NSString *)dbName chargePileID:(QCPileListNumModel *)number;

#pragma - mark CHARGE_RECORD
- (void)addChargeRecordData:(NSString *)dbName cpData:(QCChargeRecordModel *)data;
- (NSArray *)getChargeRecordData:(NSString *)dbName;
#pragma - mark SUPPLY_RECORD
- (void)addSupplyRecordData:(NSString *)dbName cpData:(QCSupplyRecordModel *)data;
- (NSArray *)getSupplyRecordData:(NSString *)dbName;
#pragma - mark FAULT_RECORD
- (void)addFaultRecordData:(NSString *)dbName cpData:(QCFaultRecordModel *)data;
- (NSArray *)getFaultRecordData:(NSString *)dbName;
@end
