/********************************************************************
filename    :  ivs_type.h
author      :
created     :  2018/06/27
description :  本文件用于对基本数据类型进行定义
copyright   :  Copyright (c) 2012-2018 Huawei Tech.Co.,Ltd
history     :  2018/06/27 初始版本
*********************************************************************/

#ifndef _IVS_TYPE_
#define _IVS_TYPE_


typedef  char               IVS_INT8;
typedef  unsigned char      IVS_UINT8;

typedef  short              IVS_INT16;
typedef  unsigned short     IVS_UINT16;

typedef  int                IVS_INT32;
typedef  unsigned int       IVS_UINT32;

#ifdef _WIN64
    typedef  unsigned long long     IVS_ULONG;
    typedef  long long              IVS_LONG;
#else
    typedef  unsigned long          IVS_ULONG;
    typedef  long                   IVS_LONG;
#endif

#ifdef _MSC_VER
typedef __int64             IVS_INT64;
typedef unsigned __int64    IVS_UINT64;
#else
typedef long long           IVS_INT64;
typedef unsigned long long  IVS_UINT64;
#endif

typedef  char               IVS_CHAR;
typedef  unsigned char      IVS_UCHAR;

typedef  float              IVS_FLOAT;
typedef  double             IVS_DOUBLE;

typedef  short              IVS_SHORT;
typedef  unsigned short     IVS_USHORT;


#endif
