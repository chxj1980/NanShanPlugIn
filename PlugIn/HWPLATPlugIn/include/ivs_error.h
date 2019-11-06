/********************************************************************
filename    :    ivs_error.h
author      :    z00189721
created     :    2012/11/13
description :    ivs �����붨��
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2012/11/13 ��ʼ�汾
*********************************************************************/

#ifndef _IVS_ERROR_H_
#define _IVS_ERROR_H_

/************************************************************
*               IVSƽ̨���������嶨�����
*  ģ����루2λ��+ 91 + ���ܱ��루2λ��+ ������루3λ��
*************************************************************
*  ����ģ��������������ö�ٶ����е�ģ��ע�͡�
*  ���ܱ��붨�����£�
*      ����                       ���ܱ���
*  1����¼                            01
*  2��������                          02
*  3����֯����                        03
*  4����ɫ����                        04
*  5���û�����                        05
*  6���û�����-�����豸                06
*  7��ҵ��ڵ����                     07
*  8���豸����-���豸                  08
*  9����������豸                     09
*  10���������������豸                 10
*  11���豸����-������������豸         11
*  12���豸����-�������豸              12
*  13���豸����-�������豸              13
*  14���豸����                        14
*  15��ʵ��                            15
*  16���ƾ�����                        16
*  17��ʵ��-Ԥ��λ                     17
*  18��ʵ��-Ѳ���켣                   18
*  19��¼��ط�                        19
*  20���澯����                        20
*  21���ⲿ�澯����                    21
*  22��Ѳ������                        22
*  23���澯����                        23
*  24��¼��ռ�����                    24
*  25��¼��ƻ�����                    25
*  26���޸�����                        26
*  27�������                          27
*  28���洢����������                   28
*  29���豸����                        29
*  30����־����                        30
*  31��ϵͳά��                        31
*  32��License����                     32
*  33�����ܷ����ƻ�/�������            33
*  34��NVR����                         34
*  35����������                        35
*  36�������ƻ�����                     36
*  37���豸Ԥע��                       37
*  38��DCG����                         38
*  39���ⲿϵͳ����                     39
*  40��ǰ��¼��                         43
*  41��ǰ��¼��ƻ�                     44
*  42�������㲥                         45
*  43��ץ�Ĺ���                         46
*
*  99��BPͨ�ù���                       99
*****************************************************/

// ivs �����붨��
typedef enum enIvsError
{
    /************************************************************
     *   ϵͳͨ�ô����붨��
     ***********************************************************/
    IVS_SUCCEED                            = 0,           // �ɹ�
    IVS_FAIL                               = 1,           // ʧ��
    IVS_PARA_INVALID                       = 2,           // ��������Ƿ�

    /***********************************************************
     *   ϵͳ�������ڴ桢���ݿ��ͨ�ô����붨�壨ģ����룺10��
     ***********************************************************/
    IVS_PASSWORD_ERROR                     = 109100000,   // �û���������󣬵�¼ʱ������û������������
    IVS_USER_NOT_EXIST                     = 109100001,   // �û������ڣ�ע����û�ID��ע���򲻿���
    IVS_NO_ENOUGH_RIGHT                    = 109100002,   // Ȩ�޲��㣬�޴˲���Ȩ��
    IVS_NOT_INIT                           = 109100003,   // δ��ʼ��
    IVS_ALLOC_MEMORY_ERROR                 = 109100004,   // �����ڴ�ʧ��
    IVS_OPERATE_MEMORY_ERROR               = 109100005,   // �����ڴ�ʧ��
    IVS_NO_ENOUGH_BUF                      = 109100006,   // ������̫С���������ݵĻ������������ݵĻ���������
    IVS_SYS_NO_SUPPORT                     = 109100007,   // ϵͳ��֧��
    IVS_INIT_DB_ERROR                      = 109100008,   // ��ʼ�����ݿ�ʧ��
    IVS_CONNECT_DB_ERROR                   = 109100009,   // �������ݿ�ʧ�ܣ����ڻ�ȡ���ݿ�����ʧ�ܡ����ݿ�����ָ��ΪNULL��
    IVS_OPERATE_DB_ERROR                   = 109100010,   // ���ݿ����ʧ�ܣ����ڸ������ݿ����ʧ�ܡ����ݿ������ݲ����ڡ����ݿ�����ָ��Ϊ�յȣ�
    IVS_DIR_ERROR                          = 109100011,   // ·������
    IVS_CREATE_DIR_ERROR                   = 109100012,   // �����ļ�Ŀ¼ʧ��
    IVS_FILE_FORMAT_ERROR                  = 109100013,   // �ļ���ʽ����ȷ
    IVS_CREATE_FILE_ERROR                  = 109100014,   // �����ļ�ʧ��
    IVS_OPEN_FILE_ERROR                    = 109100015,   // ���ļ�ʧ��
    IVS_WRITE_FILE_ERROR                   = 109100016,   // д�ļ�ʧ��
    IVS_DISK_FULL                          = 109100017,   // Ӳ�̿ռ���
    IVS_DISK_ERROR                         = 109100018,   // Ӳ�̳���
    IVS_NET_CONNECT_ERROR                  = 109100019,   // ��������ʧ��,�����������߻�������ԭ���������ӳ�ʱ��
    IVS_NET_OVER_MAXLINK                   = 109100020,   // �����������������
    IVS_NET_SEND_ERROR                     = 109100021,   // ���緢������ʧ��
    IVS_NET_RECV_ERROR                     = 109100022,   // �����������ʧ��
    IVS_NET_RECV_TIMEOUT                   = 109100023,   // ����������ݳ�ʱ
    IVS_NET_DATA_ERROR                     = 109100024,   // ���紫�͵���������
    IVS_JOIN_MULTICAST_ERROR               = 109100025,   // ����ಥ��ʧ��
    IVS_CREATE_THREAD_ERROR                = 109100026,   // �����߳�ʧ��
    IVS_XML_INVALID                        = 109100027,   // XML��Ϣ��Ƿ�(����XML��Ϣ��ΪNULL��XML����ʧ��)
    IVS_XML_PACK_ERROR                     = 109100028,   // XML��װʧ��
    IVS_XML_DEV_TEMPLATE_INVALID           = 109100029,   // �豸ģ��XML�Ƿ�
    IVS_SECURITY_INIT_ERROR                = 109100030,   // ��ȫ�������ʼ��ʧ��
    IVS_BATCH_OPERATE_ALL_ERROR            = 109100031,   // ��������ȫ��ʧ��
    IVS_BATCH_OPERATE_PART_SUCCEED         = 109100032,   // �����������ֳɹ�
    IVS_MU_OFF_LINE                        = 109100033,   // MU������
    IVS_CMU_OFF_LINE                       = 109100034,   // CMU������
    IVS_DCG_OFF_LINE                       = 109100035,   // DCG������
    IVS_OMU_OFF_LINE                       = 109100036,   // OMU������
    IVS_SMU_OFF_LINE                       = 109100037,   // SMU������
    IVS_SCU_OFF_LINE                       = 109100038,   // SCU������
    IVS_MULM_OFF_LINE                      = 109100039,   // MULM������
    IVS_GET_LOCALIP_ERROR                  = 109100040,   // ��ȡ����IPʧ��
    IVS_SET_LOCALIP_ERROR                  = 109100041,   // ���ñ���IPʧ��
    IVS_SCRIPT_RUN_ERROR                   = 109100042,   // �ű�ִ�г���
    // ����У�������
    IVS_USERNAME_INVALID                   = 109100043,   // �û������ȷǷ�������Ƿ��ַ�
    IVS_PASSWORD_INVALID                   = 109100044,   // �û����볤�ȷǷ�������Ƿ��ַ�
    IVS_NAME_INVALID                       = 109100045,   // ���Ƴ��ȷǷ�������Ƿ��ַ��������豸���ƣ��ƻ����Ƶȣ�
    IVS_DESCRIBE_INVALID                   = 109100046,   // �������ȷǷ�������Ƿ��ַ�
    IVS_CODE_INVALID                       = 109100047,   // ���볤�ȷǷ�������Ƿ��ַ��������豸���룬�����ȣ�
    IVS_IP_INVALID                         = 109100048,   // IP��ַ�Ƿ�
    IVS_PORT_INVALID                       = 109100049,   // �˿ڷǷ�
    IVS_TIME_INVALID                       = 109100050,   // ʱ��Ƿ�
    IVS_EMAIL_INVALID                      = 109100051,   // e-mail�Ƿ�
    IVS_TELEPHONE_INVALID                  = 109100052,   // �绰�Ƿ�
    IVS_DATA_INVALID                       = 109100053,   // ��ֵ�Ƿ��򳬹�ȡֵ��Χ
    IVS_MAU_OFF_LINE                       = 109100054,   // MAU������
    IVS_URL_INVALID                        = 109100055,   // URL�Ƿ�
    IVS_DOWNLOAD_ERROR                     = 109100056,   // ����ʧ��
    IVS_DOMAIN_TYPE_ERROR                  = 109100057,   // ��ģʽ����
    IVS_DATA_ENCRYPT_ERROR                 = 109100058,   // ���ݼ���ʧ��
    IVS_DATA_DECRYPT_ERROR                 = 109100059,   // ���ݽ���ʧ��
    IVS_IP_INVALID_SAMEAS_PHYSICAL_IP      = 109100060,   // IP��ַ�Ƿ�:����ip������ip��ͬ
    IVS_IP_INVALID_BEING_USED              = 109100061,   // IP��ַ�Ƿ�:����ip��ַ��ͻ
    IVS_IP_INVALID_NETWORK_SEGMENT         = 109100062,   // IP��ַ�Ƿ�:����ip��ͬ����IP
    IVS_NOT_SUPPORT_MSG                    = 109100063,   // ��֧�ֵ���Ϣ����
    IVS_GET_RECORD_LIST_TIMEOUT            = 109100064,   // ��ѯ¼��ʱ������Сʱ�䷶Χ 
    IVS_LINK_NOT_AUTH                      = 109100065,   // ����Ϊ��Ȩ
    IVS_PASSWORD_WEAK                      = 109100066,   // ����������������������������
    IVS_PASSWD_EQUAL_LAST_N                = 109100067,   // ������ǰN����ͬ
    IVS_IMGU_OFF_LINE                      = 109100068,   // IMGU������
    IVS_SAFEVIDEO_OFF_LINE                 = 109100069,   // SAFEVIDEO������
    IVS_DMU_OFF_LINE                       = 109100070,   // DMU������
    IVS_OMU_GET_IP_ERROR                   = 109100071,   // OMUУ��ipʧ�ܣ��޷���ȡ���豸������ip
    IVS_START_CLUSTER_SERVER_ERROR         = 109100072,   // ��Ⱥ��������ʧ��
    IVS_CONNECT_CDB_ERROR                  = 109100073,   // �����������ݿ�ʧ��
    IVS_DISKLESSMODE_NOSUPPORT             = 109100074,   // ����ģʽ��֧�ָ�ҵ��
    IVS_INVALLID_JSON_BODY                 = 109100075,   // JSON����ʧ��
    IVS_NON_UNIQUE_NATIP_OR_PORT           = 109100076,   // Natӳ��IP��˿ںŲ�Ψһ
    
    /**************************************************************
     *   SMU�����붨�壨ģ����룺11��
     *************************************************************/
    IVS_SMU_XML_INVALID                    = 119108001,   // XML���ݲ��Ϸ�
    IVS_SMU_DEVICE_TIMEOUT                 = 119108002,   // �����豸����ҵ��ʱ
    IVS_SMU_GETURL_TIMEOUT                 = 119108003,   // ��ȡgeturl��ʱ
    IVS_SMU_RECORDINQUIRY_TIMEOUT          = 119108004,   // ¼���ѯ��ʱ
    IVS_SMU_DEVICE_EXIST                   = 119108005,   // �豸�Ѵ���
    IVS_SMU_DEVICE_NOTEXIST                = 119108006,   // �豸������
    IVS_SMU_DEVICE_UPDATEMAP_FAIL          = 119108007,   // �����ڴ�ʧ��
    IVS_SMU_DEVICE_ADDMAP_FAIL             = 119108008,   // ����ڴ�����ʧ��
    IVS_SMU_PTZ_CONTROL_TIMEOUT            = 119108009,   // �ƾ����Ƴ�ʱ
    IVS_SMU_ROUTE_NVR_FAIL                 = 119108010,   // ·��nvrʧ��
    IVS_DB_RESULT_SET_NULL_POINTER         = 119108011,   // ���ݿ�����ָ��Ϊ��
    IVS_SMU_CMD_XML_IS_NULL                = 119108012,   // cmd�е�xmlָ��Ϊ��
    IVS_SMU_DR_RELATON_TIMEOUT             = 119108013,   // ���ֱ��ݲ�����ʱ
    IVS_SMU_OPERATE_TIME_OUT               = 119108014,   // ������ʱ
    IVS_SMU_MD_DATA_TIME_OUT               = 119108015,   // ��ѯ�ƶ�������ݳ�ʱ
    IVS_SMU_LOAD_SQL_ERROR                 = 119108016,   // SMU�������ݿ����ʧ��
    IVS_SMU_SQL_DATA_NULL                  = 119108017,   // SMU��ѯ���ݿ�Ϊ��
    IVS_SMU_TRANSDOMAIN_NOT_EXIST          = 119108018,   // CU����ĵ�ǰ���Ѳ���ת����
    IVS_SMU_NO_AVAILABLE_NVR_ERROR         = 119108019,   // �Ҳ������õ�ת��������
    IVS_SMU_NO_AVAILABLE_MAU_NVR           = 119108020,   // �Ҳ������õ����ܷ���������
    IVS_SMU_DEVICE_CONNECT_CODE_EXIST      = 119108021,   // ���������Ѵ���
    IVS_SMU_INIT_INCOMPLETE                = 119108022,   // SMUδ��ɳ�ʼ��
    IVS_SMU_PARSE_RESOURCE_FILE_FAIL       = 119108023,   // SMU������Դ�ļ�ʧ��
    IVS_SMU_PARSE_JSON_FAIL                = 119108024,   // SMU����jsonʧ��
    IVS_SMU_UPDATE_MODULE_DATA_FAIL        = 119108025,   // SMU����ģ������ʧ��
    IVS_SMU_INPUT_PARAM_INVALID            = 119108026,   // ����Ƿ�����
    
    /* SMU:�豸����-�����豸+ͨ�á������룺119108XXX */
    IVS_SMU_DEV_TIMEOUT                    = 119108100,   // �����豸����ҵ��ʱ
    IVS_SMU_DEV_CMD_INVALID                = 119108101,   // CMD������
    IVS_SMU_DEV_REQ_XML_INVALID            = 119108102,   // �������XML�Ƿ�
    IVS_SMU_DEV_REQ_XML_GROUPID_NOEXIST    = 119108103,   // �������XML����GroupId�ڵ㲻����
    IVS_SMU_DEV_REQ_XML_GROUPNAME_NOEXIST  = 119108104,   // �������XML����GroupName�ڵ㲻����
    IVS_SMU_DEV_DB_CONNECT_ERROR           = 119108105,   // ���ݿ����Ӵ���
    IVS_SMU_DEV_DB_EXECUTE_ERROR           = 119108106,   // ���ݿ����ʧ��
    IVS_SMU_DEV_GROUPID_NOEXIST            = 119108107,   // �豸��ID������
    IVS_SMU_DEV_SAME_GROUPNAME_EXIST       = 119108108,   // ���豸���´���ͬ����������
    IVS_SMU_DEV_ADD_ALL_FAIL               = 119108109,   // ������豸ȫ��ʧ��
    IVS_SMU_DEV_ADD_PART_SUCCEED           = 119108110,   // ������豸���ֳɹ�
    IVS_SMU_DEV_TYPES_CHANGE_ERROR         = 119108111,   // �豸����ǿ��ת������
    IVS_SMU_DEV_XML_CHANNELNAME_NOEXIST    = 119108112,   // �������XML����ChannelName�ڵ㲻����
    IVS_SMU_DEV_XML_CHANNELTYPE_NOEXIST    = 119108113,   // �������XML����ChannelType�ڵ㲻����
    IVS_SMU_DEV_XML_CHANNELCODE_NOEXIST    = 119108114,   // �������XML����ChannelCode�ڵ㲻����
    IVS_SMU_DEV_CREATE_SUBDEVICE_FAIL      = 119108115,   // �������豸ʧ��
    IVS_SMU_DEV_GET_ROUTING_ERROR          = 119108116,   // ��ȡNVR·��ʧ��
    IVS_SMU_DEV_REQ_XML_TARGROUPID_NOEXIST = 119108117,   // �������XML����TargetGroup�ڵ㲻����
    IVS_SMU_DEV_DB_GROUPID_NOEXIST         = 119108118,   // ���ݿ�GroupId�޼�¼
    IVS_SMU_DEV_GROUP_LEVEL_EXCEED         = 119108119,   // Group Level�������ֵ
    IVS_SMU_DEV_ADD_TO_GROUP_ERROR         = 119108120,   // ����豸�����豸ʧ��
    IVS_SMU_DEV_NOEXIST                    = 119108121,   // �豸������
    IVS_SMU_DEV_FROM_GRP_ID_ZERO           = 119108122,   // ���豸���Ѿ�Ϊ����
    IVS_SMU_DEV_PROTOCOL_TYPE_ERROR        = 119108123,   // ���豸Э�����ʹ���
    IVS_SMU_DEV_NVRCODE_CANNOT_MOD         = 119108124,   // �����޸��豸��nvrcode
    IVS_SMU_DEV_XML_LOGINID_NOEXIST        = 119108125,   // �������XML����LoginId�ڵ㲻����
    IVS_SMU_DEV_CONNOT_DEL                 = 119108126,   // ���豸ֻ�ڸ����£������Ƴ�
    IVS_SMU_DEV_DELETE_FAIL                = 119108127,   // ɾ���豸ʧ��
    IVS_SMU_DEV_NVR_ROUTING_OFFLINE        = 119108128,   // NVR������
    IVS_SMU_DEV_GROUP_TARGET_SAME_FAIL     = 119108129,   // ��Ŀ���豸����ͬ
    IVS_SMU_DEV_NVR_NOT_EXIST              = 119108130,   // nvrcode������
    IVS_SMU_DEV_GROUP_TOTAL_EXCEED         = 119108131,   // �豸�������ﵽ���ֵ
    IVS_SMU_DEV_GROUP_CHILE_EXCEED         = 119108132,   // ���豸��ﵽ���ֵ
    IVS_SMU_DEV_GROUP_EXIST_RECU           = 119108133,   // �豸����ڵݹ�
    IVS_SMU_DEV_GROUPNAME_LENGTH_INVALID   = 119108134,   // �豸�鳤����Ч
    IVS_SMU_DEV_GROUPNAME_STRING_INVALID   = 119108135,   // �豸�����ư����Ƿ��ַ�
    IVS_SMU_DEV_XML_PARENRGROUPID_NOEXIST  = 119108136,   // �������PARENRGROUPID�ڵ㲻����
    IVS_SMU_DEV_GROUPREMARK_LENGTH_INVALID = 119108137,   // �豸�鳤����Ч
    IVS_SMU_DEV_GROUPREMARK_STRING_INVALID = 119108138,   // �豸�����ư����Ƿ��ַ�
    IVS_SMU_DEV_BUILD_DEVICE_CODE_FAIL     = 119108139,   // �����豸����ʧ��
    IVS_SMU_DEV_PART_NOEXIST               = 119108140,   // �豸�б��в����豸������
    IVS_SMU_DEV_DR_TABLE_IS_EMPTY          = 119108141,   // ���ֹ�ϵ��Ϊ��
    IVS_SMU_DEVICE_IP_EXIST                = 119108142,   // �豸IP�Ѵ���
    IVS_SMU_ONLY_SUPPORT_LOCAL_DOAMIN      = 119108143,   // ֻ֧�ֱ����豸
    IVS_SMU_QD_NO_LICENSE                  = 119108144,   // ��Ƶ���������license
    IVS_SMU_QD_NO_SUPPORT_SYSTEM           = 119108145,   // ��Ƶ������ϲ�֧�ֵ�ϵͳ(VCN500��֧��)
    IVS_SMU_NOT_ALLOWED_CLONE_SAME_CLUSTER = 119108149,   // ��������豸��¡��ԭʼ��Ⱥ��  
    IVS_SMU_NOT_ALLOWED_CLONE_DEV_AGAIN    = 119108150,   // ��������ͬһ�����ڿ�¡��ͬ���豸
    IVS_SMU_NOT_ALLOWED_CLONE_SAME_NODE    = 119108151,   // ��������豸��¡��ԭʼ�豸�Ľڵ���
    IVS_SMU_NOT_ALLOWED_CLONE_DEV_CLUSTER  = 119108152,   // ��������豸��¡����Ⱥ
    IVS_SMU_VCN500_NOT_SUPPORT_SHADOW_DEV  = 119108153,   // �ò�Ʒ��̬��֧�ֿ�¡�豸
    IVS_SMU_NOT_ALLOWED_CLONE_DEV          = 119108154,   // ��ǰֻ֧�ְ��豸��¡���ϼ������ƽ����
    IVS_SMU_MDU_NOT_SUPPORT_SHADOW_DEV     = 119108155,   // ��ת����������֧�ֿ�¡�豸
    IVS_SMU_SOFT_NOT_SUPPORT_SHADOW_DEV    = 119108156,   // �����������֧�ֿ�¡�豸
    IVS_SMU_CUR_SES_NO_SUPPORT_SHADOW_DEV  = 119108157,   // Ӱ���豸��֧�ֵ�ǰҵ��
    IVS_SMU_NOT_ALLOWED_BACKUP_NVR         = 119108158,   //��ǰֻ֧�ְ�ͼƬ���ݼƻ����õ��ϼ������ƽ����

    
    IVS_SMU_EXSIT_MAP_IN_GROUP             = 119108159,   //��֯���ε�ͼ
    IVS_SMU_FILE_NOT_EXIST                 = 119108160,   //�ļ�������
    IVS_SMU_MAP_NOT_EXIST                  = 119108161,   //
    IVS_SMU_REACH_MAP_MAX_COUNT            = 119108162,   //�ﵽ��ͼ����
    IVS_SMU_EX_DEV_NOT_ALLOWED_CLONE_DEV   = 119108163,   //��ǰ�����豸ֻ֧�ֿ�¡���Խ���
    IVS_SMU_NVRCODE_DOMAINCODE_EQUAL       = 119108164,   //NVRcode���������ͬ
    IVS_SMU_EXCEED_CHANGE_SUBSCRIBE_MAXNUM = 119108165,   //������������û��������֧�ֵĶ������������
    IVS_SMU_NO_CAMERA_CHANGE_SUBSCRIBER    = 119108166,   //����������豸����������
    IVS_SMU_LOAD_GB35114_CONF_FILE_FAIL    = 119108167,   //����GB35114�����ļ�ʧ��
    IVS_SMU_SAVE_GB35114_CONF_FILE_FAIL    = 119108168,   //����GB35114�����ļ�ʧ��

    IVS_SMU_CODE_RULE_REACH_MAX            = 119108165,   //�������ﵽ���ֵ,���ܼ������
    IVS_SMU_CODE_RULE_REACH_MIN            = 119108166,   //�������ﵽ��Сֵ,����ɾ��
    IVS_SMU_CODE_RULE_NAME_INVALID            = 119108167,   //����������Ʋ��Ϸ�
    IVS_SMU_CODE_RULE_CODE_INVALID            = 119108168,   //���������벻���Ϲ淶
    IVS_SMU_CODE_RULE_CODE_EXIST            = 119108169,   //��������������ظ�
	IVS_SMU_MAP_REACH_MAX_DEV_COUNT        =119108170,    //�ﵽ���ŵ��ӵ�ͼ�����ɵ�����豸��


    /* SMU:�豸����-����������豸�������룺119109XXX */


    /* SMU:�豸����-����������豸�������룺119109XXX */

    /* SMU:�û���¼Service�����룬ȡֵ��Χ��119101300 ~ 119101399 */
    IVS_SMU_USER_EXPIRED                   = 119101302,   // �˺��Ѿ�����
    IVS_SMU_USER_STOPPED                   = 119101303,   // �û���ͣ��
    IVS_SMU_USER_LOCKED                    = 119101304,   // �û�������
    IVS_SMU_USER_PWD_NEED_MOD              = 119101305,   // �û������ѹ��ڣ���Ҫ�޸�
    IVS_SMU_EXCEED_SAME_USER_ONLINE_MAXNUM = 119101306,   // ����ͬһ�˻�ͬʱ���ߵ�����û�����
    IVS_SMU_EXCEED_ONLINE_USER_MAXNUM      = 119101307,   // ͬʱ�������û�������ϵͳ֧�ֵ��������
    IVS_SMU_USER_FIRST_LOGIN               = 119101308,   // �û��״ε�¼��Ҫ�޸�����
    IVS_SMU_USER_OFF_LINE                  = 119101309,   // �û�������
    IVS_SMU_BASIC_LOGIN_NOT_NEED_DOMAIN_NAME = 119101310, // ������ݵ�¼���ܴ�������Ϣ
    IVS_SMU_DOMAIN_LOGIN_NEED_DOMAIN_NAME  = 119101311,   // ����ݵ�¼�����������Ϣ
    IVS_SMU_NO_MATCH_ACC_RULE              = 119101312,   // û�ҵ��˻�ƥ��Ľ�ɫ������Ϣ
    IVS_SMU_NO_MATCH_OPER_RIGHT            = 119101313,   // û�ҵ��˻�ƥ��Ĳ���Ȩ����Ϣ
    IVS_SMU_LOGIN_WITH_EXIST_LINKID        = 119101314,   // ����ʹ�þɵ�TCP�����ظ����͵�¼����
    IVS_SMU_VERIFY_WITH_DIFFERENT_LINKID   = 119101315,   // ��֤������ʹ�õ�TCP�����������û���TCP���Ӳ�ͬ
    IVS_SMU_PWD_IS_EMPTY                   = 119101316,   // ����Ϊ��
    IVS_SMU_CU_IP_IS_ILLEGAL               = 119101317,   // ��¼Xml��CU IP�Ƿ�
    IVS_SMU_CU_PORT_IS_ILLEGAL             = 119101318,   // ��¼Xml��CU�˿ڷǷ�
    IVS_SMU_LOGIN_TYPE_ILLEGAL             = 119101319,   // Login_Type�Ƿ�
    IVS_SMU_LDAP_INIT_FAIL                 = 119101320,   // ���˻���֤ʱ��LDAPЭ���ʼ��ʧ��
    IVS_SMU_LDAP_SEARCH_ACCOUNT_FAIL       = 119101321,   // ����������ϲ����˻�ʧ��
    IVS_SMU_MACHINE_NAME_ILLEGAL           = 119101322,   // �������Ƿ�
    IVS_SMU_CLIENT_TYPE_ILLEGAL            = 119101323,   // �ͻ������ͷǷ�
    IVS_SMU_SERVER_IP_IS_ILLEGAL           = 119101324,   // ��¼Xml�ķ�����IP�Ƿ�
    IVS_SMU_SERVER_PORT_IS_ILLEGAL         = 119101325,   // ��¼Xml�ķ������˿ڷǷ�
    IVS_SMU_DOMAIN_LOGIN_SERVER_DISCONNECT = 119101326,   // ���˺ŷ��������ڹ���
    IVS_SMU_CAN_NOT_SIGNOUT_USER_SELF      = 119101327,   // ����ǩ���Լ�
    IVS_SMU_RIGHT_LEN_NO_MATCH             = 119101328,   // Ȩ�޳��Ȳ�ƥ��
    IVS_SMU_ENCRYPT_FAIL                   = 119101329,   // ����ʧ��
    IVS_SMU_DECRYPT_FAIL                   = 119101331,   // ����ʧ��
    IVS_SMU_REQUEST_PUBLIC_KEY_FAIL        = 119101332,   // ����Կʧ��
    IVS_SMU_REQUEST_EXCHANGE_KEY_FAIL      = 119101333,   // ������Կʧ��
    IVS_SMU_SECURITY_CLIENT_INIT_FAIL      = 119101334,   // ��ȫClient��ʼ��ʧ��
    IVS_SMU_WAIT_ASYNC_RESPONSE            = 119101340,   // �ȴ��첽��Ӧ
    IVS_NULL_POINTER                       = 119101350,   // �������ڲ����󣬿�ָ���쳣;
    IVS_SMU_LINKID_FORMAT_ERROR            = 119101351,   // LinkID��ʽ����
    IVS_SMU_IP_LOCKED                      = 119101352,   // �û�IP������
    IVS_SMU_HAS_RESTARED                   = 119101353,   // SMU��������ԭ�����û��Ѳ����ڣ�����sdk����smu
    IVS_SMU_DNSCONFIG_NOT_SET              = 119101354,   //�������δ����
    IVS_SMU_USER_NOT_IN_VALID_TIME         = 119101355,   //�û�������Ч����
    IVS_SMU_DOMAIN_LOGIN_NOT_SUPPORT       = 119101356,   //��֧�����¼����ǰVCN500��֧��

    IVS_SMU_ADD_GROUP_ERROR                = 119105000,   // �����û���ʧ��
    IVS_SMU_MODIFY_GROUP_ERROR             = 119105001,   // �޸��û���ʧ��
    IVS_SMU_DELETE_GROUP_ERROR             = 119105002,   // ɾ���û���ʧ��
    IVS_SMU_MOVE_GROUP_ERROR               = 119105003,   // �ƶ��û���ʧ��
    IVS_SMU_ADD_GROUP_HAVE_REPEAT_GROUP    = 119105004,   // �����û���ʱ�ظ�
    IVS_SMU_ADD_GROUP_PARENT_NOT_EXIST     = 119105005,   // ���ڵ㲻����
    IVS_SMU_ADD_GROUP_PARENT_LEVEL_INVALID = 119105006,   // ���ڵ�㼶�Ƿ�
    IVS_SMU_MOIDFY_GROUP_GROUP_NOT_EXIST   = 119105007,   // ���޸ĵ��û��鲻����
    IVS_SMU_MOIDFY_GROUP_HAVE_REPEAT_GROUP = 119105008,   // �޸��û����������
    IVS_SMU_MOVE_GROUP_TARGET_NOT_EXIST    = 119105009,   // �����Ŀ�겻����
    IVS_SMU_MOVE_GROUP_TARGET_LEVEL_INVALID= 119105010,   // �ƶ���ᳬ��3��
    IVS_SMU_MOVE_GROUP_BEMOVED_NOT_EXIST   = 119105011,   // ���ƶ����û��鲻����
    IVS_SMU_MOVE_GROUP_HAVE_REPEAT_GROUP   = 119105012,   // �ƶ������������û���
    IVS_SMU_DEL_GROUP_GROUP_NOT_EXIST      = 119105013,   // Ҫ��ɾ�����û��鲻����
    IVS_SMU_CAN_NOT_DELETE_ROOT_GROUP      = 119105016,   // ����ɾ������
    IVS_SMU_OVER_MAX_GROUP_NUM             = 119105017,   // �û��������������޶�
    IVS_SMU_CAN_NOT_MOVE_ROOT_GROUP        = 119105018,   // ���鲻���ƶ�
    IVS_SMU_CAN_NOT_MOVE_TO_SELF           = 119105019,   // �鲻���ƶ����Լ�
    IVS_SMU_GROUP_NUM_OVER_MAX             = 119105020,   // �û�������ﵽ����,����1000
    IVS_SMU_GROUP_CHILDREN_NUM_OVER_MAX    = 119105021,   // ���û����������99
    IVS_SMU_PARAM_INVALID_FOR_GROUP        = 119105022,   // �û����������
    IVS_SMU_RESET_PWD_SWITCH_OFF           = 119105023,   // �������뿪�عر�
    IVS_SMU_CAN_NOT_DEL_USER_IN_SELFGRP    = 119105024,   // ����ɾ���Լ����ڵ��û���
    IVS_SMU_CAN_NOT_DEL_ROLE_IN_SELF       = 119105025,   // ����ɾ���Լ��Ľ�ɫ
    IVS_SMU_USER_GROUP_DESC_LENGTH_INVALID = 119105026,   // �û��鱸ע���ȷǷ�
    
    IVS_SMU_EXCEED_ONLINE_MOBILEUSER_MAXNUM= 119105027,   //�ƶ��û����߸�������ϵͳ֧�ֵ��������
    IVS_SMU_EXIST_CHILD_USER_IN_GROUP      = 119105028,   //��ɾ���û��������û������

    IVS_SMU_ADD_ROLE_ERROR                 = 119105100,   // ������ɫʧ��
    IVS_SMU_MODIFY_ROLE_ERROR              = 119105101,   // �޸Ľ�ɫʧ��
    IVS_SMU_DELETE_ROLE_ERROR              = 119105102,   // ɾ����ɫʧ��
    IVS_SMU_GET_ROLE_LIST_ERROR            = 119105103,   // ��ѯ��ɫʧ��
    IVS_SMU_ACC_PARAM_ERROR                = 119105104,   // �ʺŹ�������Ƿ�
    IVS_SMU_ADD_ROLE_HAVE_REPEAT_ROLE      = 119105105,   // ��ɫ������
    IVS_SMU_DELETE_ROLE_ROLE_NOT_EXIST     = 119105106,   // ɾ���Ľ�ɫ������
    IVS_SMU_DELETE_DEFAULT_ROLE_ERROR      = 119105107,   // ����ɾ��Ĭ�Ͻ�ɫ
    IVS_SMU_MODIFY_ROLE_ROLE_NOT_EXIST     = 119105108,   // �޸ĵĽ�ɫ������
    IVS_SMU_GET_DEFAULT_RULE_ERROR         = 119105109,   // ��ȡĬ���ʺŹ���ʧ��
    IVS_SMU_GET_ROLE_BY_ID_ERROR           = 119105110,   // ����id��ȡ��ɫʧ��
    IVS_SMU_GET_ROLE_BY_ID_ROLE_NOT_EXIST  = 119105111,   // ��ɫid��Ӧ�Ľ�ɫ������
    IVS_SMU_GET_USER_ROLE_USER_NOT_HAVE_ROLE= 119105112,  // �û�û�з����ɫ
    IVS_SMU_GET_USER_ROLE_USER_NOT_EXIST   = 119105113,   // �û�û�з����ɫ
    IVS_SMU_GET_USER_ROLE_OP_ERROR         = 119105114,   // ��ȡ��ɫ����Ȩ��ʧ��
    IVS_SMU_FILE_OP_ERROR                  = 119105116,   // �ϴ������ļ�ʧ��
    IVS_SMU_FILE_OVER_MAX                  = 119105117,   // �ļ���С̫�󣬳���20m
    IVS_SMU_FILE_BUILD_CMD_ERROR           = 119105118,   // ƴװcmdʱ����
    IVS_SMU_PARAM_INVALID_FOR_ROLE         = 119105119,   // ��ɫ��������
    IVS_SMU_ROLE_NUM_OVER_MAX              = 119105120,    // ��ɫ�����ﵽ����,����128
    IVS_SMU_GROUP_NUM_OVER_MAX_VCN500      = 119105121,    // VCN500�û�������ﵽ���ޣ�����16
    IVS_SMU_ROLE_NUM_OVER_MAX_VCN500       = 119105122,    // VCN500��ɫ�����ﵽ����,����32
    IVS_SMU_ROLE_WITH_USER_DELETE_ERROR    = 119105123,    // ɾ�������û��Ľ�ɫʧ�ܣ�������ɾ�������û��Ľ�ɫ
    IVS_SMU_LDU_CHILD_NOT_SUPPORT_CLUSTER  = 119105124,    //LDU��֧�ּ�Ⱥ��¼
     /* SMU:�û���������� */
    IVS_SMU_MODIFY_PWD_OLD_PWD_WRONG       = 119105200,   // �޸�����ʱ���������
    IVS_SMU_ADD_USER_ERROR                 = 119105201,   // �����û�����
    IVS_SMU_DELETE_USER_ERROR              = 119105202,   // ɾ���û�����
    IVS_SMU_MODIFY_USER_ERROR              = 119105203,   // �޸��û�����
    IVS_SMU_INQUIRY_USER_ERROR             = 119105204,   // ��ѯ�û�����
    IVS_SMU_INQUIR_ONLINE_USER_ERROR       = 119105205,   // ��ѯ�����û�����
    IVS_SMU_INQUIR_DEVLIST_ERROR           = 119105206,   // ��ѯ�û��豸����
    IVS_SMU_USER_NOT_EXIST                 = 119105207,   // �û�������
    IVS_SMU_USER_EXIST                     = 119105208,   // �û��Ѵ���
    IVS_SMU_EXIST_SAME_ITEM                = 119105211,   // ���ݿ��Ѵ�����ͬ������
    IVS_SMU_DB_NOT_EXIST_ITEM              = 119105212,   // ���ݿⲻ��������
    IVS_SMU_FROM_GREATERTHAN_INDEX_ERROR   = 119105214,   // �û���ѯFROM��������TO����
    IVS_SMU_XML_UNIFIEDQUERY_LIMIT_ERROR   = 119105215,   // ͳһ��ѯ�����е�limit����ȷ
    IVS_SMU_XML_UNIFIEDQUERY_INDEX_ERROR   = 119105216,   // ͳһ��ѯ�����е�Fromindex��Toindex����ȷ
    IVS_SMU_USER_ID_INVALID                = 119105218,   // ���ݿ�ID���Ϸ�
    IVS_SMU_ID_GENERATE_ERROR              = 119105222,   // ���ݿ�id���ɴ���
    IVS_SMU_ADD_USER_ROLE_RELATION_ERROR   = 119105223,   // ����û���ɫ���������
    IVS_SMU_ADD_USER_GROUP_RELATION_ERROR  = 119105224,   // ����û��û�����������
    IVS_SMU_ROLE_NOT_EXIST                 = 119105225,   // ��ɫ���н�ɫ������
    IVS_SMU_GROUP_NOT_EXIST                = 119105226,   // �û��鲻����
    IVS_SMU_DEV_EXIST_SAME_ITEM            = 119105227,   // �豸�Ѵ���
    IVS_SMU_DELETE_USER_USERGROUP_ERROR    = 119105228,   // ɾ���û��û�������
    IVS_SMU_DELETE_USER_ONLINE_ERROR       = 119105229,   // ɾ�������û�����
    IVS_SMU_DELETE_USER_ROLE_ERROR         = 119105230,   // ɾ���û���ɫ��Ӧ�����
    IVS_SMU_DELETE_USER_DEVICE_ERROR       = 119105231,   // ɾ���û��豸��Ӧ�����
    IVS_SMU_DELETE_USER_INFO_ERROR         = 119105232,   // ɾ���û����������
    IVS_SMU_MODIFY_USER_ROLE_ERROR         = 119105234,   // �޸��û���ɫ��Ӧ�����
    IVS_SMU_MODIFY_USER_USERGROUP_ERROR    = 119105235,   // �޸��û��û�������
    IVS_SMU_MODIFY_USER_USEINFO_ERROR      = 119105236,   // �û��޸Ļ�����Ϣ�����
    IVS_SMU_MODIFY_ADMIN_USEINFO_ERROR     = 119105237,   // ����Ա�޸Ļ�����Ϣ�����
    IVS_SMU_POINTER_IS_NULL                = 119105238,   // ָ��Ϊ��
    IVS_SMU_GET_TIMEZONE_ERROR             = 119105239,   // ��ȡʱ��ʧ��
    IVS_SMU_ADD_SBUSCRIBE_INFO_ERROR       = 119105240,   // ���Ӷ��ĸ澯��Ϣ����
    IVS_SMU_PAGEINFO_INVALID               = 119105241,   // ��ҳ��Ϣ���Ϸ�
    IVS_SMU_USER_TYPE_INVALID              = 119105246,   // �û����Ͳ��Ϸ�
    IVS_SMU_DB_ID_INVALID                  = 119105247,   // ���ݿ�id���Ϸ�
    IVS_SMU_USER_REGINSTER_DATE_INVALID    = 119105249,   // �û�ע��ʱ�䲻�Ϸ�
    IVS_SMU_USER_STATUS_INVALID            = 119105250,   // �û�״̬���Ϸ�
    IVS_SMU_USER_SEX_INVALID               = 119105253,   // �û�SEX���Ϸ�
    IVS_SMU_USER_ROLEID_INVALID            = 119105254,   // �û���ɫID���Ϸ�
    IVS_SMU_USER_GROUPID_INVALID           = 119105255,   // �û���ID���Ϸ�
    IVS_SMU_GET_USER_ID_NAME_ERROR         = 119105256,   // ��ȡ�û�id�͵�¼������
    IVS_SMU_SELECT_COUNT_ERROR             = 119105257,   // ��ȡ��ѯ��������
    IVS_SMU_OVER_MAX_USER_NUM              = 119105258,   // �����û������
    IVS_SMU_SEARCH_CODE_INVALID            = 119105259,   // ����������Ϣ���Ϸ�
    IVS_SMU_OVER_MAX_USER_NUM_VCN500       = 119105260,   // �����û������(VCN500)
    IVS_SMU_STATEMENT_FILE_OPEN_ERROR      = 119105262,   // �����ļ���ʧ��(�ļ�������)
    IVS_SMU_STATEMENT_FILE_TOO_LARGE       = 119105263,   // �����ļ�̫��
    IVS_SMU_STATEMENT_FILE_INVALID         = 119105264,   // �����ļ����Ϸ�
    IVS_SMU_READ_STATEMENT_ERROR           = 119105265,   // ��ȡ�����ļ�ʧ��
    IVS_SMU_PARSE_STATEMENT_FILE_TOO_LARGE = 119105266,   // ���������ļ�ʧ��
    IVS_SMU_DELETE_USERSELF_ERROR          = 119105267,   // �û�ɾ���û�����ʧ��(�Լ�ɾ���Լ�ʧ��)
    IVS_SMU_PARAMETER_INVALID              = 119105268,   // ��ҳ��Ϣ�е��û��������Ϸ�
    IVS_SMU_USERGROUP_NOT_EXIST            = 119105270,   // �û��鲻����
    IVS_SMU_USER_MODIFY_INFO_INVALID       = 119105271,   // �û��޸���Ϣ���Ϸ�
    IVS_SMU_ADD_USER_SUBSCRIBEINFO_ERROR   = 119105272,   // �����û����ı���Ϣʧ��
    IVS_SMU_DB_EXIST_SAME_ITEM             = 119105273,   // ���ݿ������ͬ��¼
    IVS_SMU_DELETE_SUBSCRIBE_LEVEL_ERROR   = 119105274,   // ɾ�����ļ���ʧ��
    IVS_SMU_DELETE_SUBSCRIBE_TYPE_ERROR    = 119105275,   // ɾ����������ʧ��
    IVS_SMU_SELF_LOCK_ERROR                = 119105276,   // �Լ������Լ�������
    IVS_SMU_SELF_DELETE_ERROR              = 119105277,   // �Լ�ɾ���Լ�������
    IVS_SMU_DEV_GROUP_DOMAIN_CODE_TOO_LONG = 119105284,   // �豸�������̫��
    IVS_SMU_DELETE_SUPER_INVALID           = 119105285,   // ɾ��super������
    IVS_SMU_RESET_SUPER_INVALID            = 119105286,   // ����super���벻����
    IVS_SMU_ADD_USER_DEV_ERROR             = 119105287,   // �����û��豸ʧ��
    IVS_SMU_DEV_NOT_EXIST                  = 119105288,   // �豸������
    IVS_SMU_PCRE_PATTERN_TOO_LONG          = 119105289,   // PCRE����̫��
    IVS_SMU_PCRE_TEXT_TOO_LONG             = 119105290,   // ��ҪPCRE�жϵ��ı�̫��
    IVS_SMU_PCRE_COMPILE_ERROR             = 119105291,   // PCRE�������
    IVS_SMU_PCRE_NOT_COMPELETLY_MATCH      = 119105292,   // PCRE������ȫƥ��
    IVS_SMU_PCRE_NOT_MATCH_OR_ERROR        = 119105293,   // PCRE��ȫ��ƥ����߳���
    IVS_SMU_PCRE_NOT_MATCH                 = 119105294,   // PCRE������ȫ��ƥ��
    IVS_SMU_PCRE_ERROR                     = 119105295,   // PCREִ�г���
    IVS_SMU_PCRE_TEXT_IS_NULL              = 119105296,   // ��ҪPCRE�жϵ��ı�Ϊ��
    IVS_SMU_READ_UNICODE_TXT_ERROR         = 119105297,   // ��Unicode�ļ�ʧ��
    IVS_SMU_SEARCH_CONDITION_TOO_LONG      = 119105298,   // ��������̫��
    IVS_SMU_XML_NVR_CODE_INVALID           = 119105299,   // �豸�������
    IVS_SMU_PWD_PCRE_INVALID               = 119105300,   // ���벻����PCRE����
    IVS_SMU_PWD_PCRE_NO_CAPTIAL            = 119105301,   // ������û�а�����д
    IVS_SMU_PWD_PCRE_NO_LOWERCASE          = 119105302,   // ������û�а���Сд
    IVS_SMU_PWD_PCRE_NO_FIGURE             = 119105303,   // ������û�а�������
    IVS_SMU_PWD_PCRE_NO_SPECIAL_CHAR       = 119105304,   // ������û�а��������ַ�
    IVS_SMU_IS_TOTAL_GROUP_INVALID         = 119105305,   // IS_TOTAL_GROUP��ǲ��Ϸ�
    IVS_SMU_GENERATE_PWD_ERROR             = 119105306,   // ��������ʧ��
    IVS_SMU_NEW_OLD_PWD_DIFF_NUM_INVALID   = 119105307,   // �¾����벻ͬ�ַ���Ŀ���Ϸ�
    IVS_SMU_USER_PWD_RESET_ERROR           = 119105308,   // �����������
    IVS_SMU_PWD_REVERSE_ERROR              = 119105313,   // ���뷴תʧ��
    IVS_SMU_PWD_LOGNINAME_REVERSE_SAME     = 119105314,   // �������¼����ת��ͬ
    IVS_SMU_PWD_LOGNINAME_SAME             = 119105315,   // �������¼����ͬ
    IVS_SMU_OLD_PWD_DIFFERENT              = 119105316,   // ����������ʵ���벻һ��
    IVS_SMU_DECRYPT_PWD_ERROR              = 119105317,   // �û��������ʧ��
    IVS_SMU_ENCRYPT_PWD_ERROR              = 119105318,   // �û��������ʧ��
    IVS_SMU_DOMAIN_USER_MODIFY_PWD_ERROR   = 119105319,   // ���û������޸�����
    IVS_SMU_USER_MODIFY_LOGINNAME_INVALID  = 119105322,   // �û���¼�������޸�
    IVS_SMU_USER_MODIFY_DOMAINNAME_INVALID = 119105323,   // �û����������޸�
    IVS_SMU_USER_ID_TOO_LONG               = 119105333,   // ID���Ȳ��Ϸ�
    IVS_SMU_GROUP_ID_NOT_NUMBER            = 119105334,   // ��ID������Ч����
    IVS_SMU_GROUP_ID_TOO_LONG              = 119105335,   // ��ID̫��
    IVS_SMU_USER_ROLE_ID_NOT_NUMBER        = 119105336,   // ��ɫID������Ч����
    IVS_SMU_ROLE_ID_TOO_LONG               = 119105337,   // ��ɫID̫��
    IVS_SMU_DELETE_USER_SUBINFO_ERROR      = 119105345,   // ɾ��������Ϣ����
    IVS_SMU_INQUIRY_USER_GROUP_LIST_ERROR  = 119105346,   // ��ȡ�û����б�ʧ��
    IVS_SMU_NO_LANGUAGE_EXIST              = 119105347,   // ϵͳ��֧�ָ�����
    IVS_SMU_STATEMENT_FILE_FSEEK_ERROR     = 119105348,   // �����ļ�fseek����ʧ��
    IVS_SMU_RESET_SELF_INVALID             = 119105349,   // �����������벻����
    IVS_SMU_ROLE_BEYOND_LIMITED            = 119105350,   // Ȩ�޲���
    IVS_SMU_OLD_NEW_PWD_THE_SAME           = 119105351,   // �����벻�ܺ�ԭ������ͬ


    /* SMU:�澯��������룬ȡֵ��Χ��119120000~119120999 */
    IVS_SMU_DB_HAD_SAME_ALARM_LEVEL        = 119120000,    // ���ݿ����Ѿ�������ͬ�ĸ澯������
    IVS_SMU_DB_MAX_ALARM_LEVEL_NUM         = 119120001,    // ���ݿ��и澯����ĸ����Ѿ��ﵽ���ֵ
    IVS_SMU_DB_ALARM_NO_DATA               = 119120002,    // �����ݿ���û�в鵽ƥ���ѯ����������
    IVS_SMU_DB_HAD_SAME_ALARM_HELP         = 119120003,    // ���ݿ����Ѿ�������ͬ�ĸ澯������
    IVS_SMU_ALARM_DB_NO_AREA               = 119120004,    // ���ݿ��в�����ָ���ķ���
    IVS_SMU_ALARM_AREA_HAS_GUARD_PLAN      = 119120005,    // ָ���ķ����Ѿ��з����ƻ���
    IVS_SMU_ALARM_DB_NO_ALARM_LEVEL        = 119120006,    // ���ݿ��в�����ָ���ĸ澯����
    IVS_SMU_ALARM_SUB_ALARM_TYPE_ERROR     = 119120007,    // ���澯���Ͷ��ģ��澯���Ͳ���Ϊ��
    IVS_SMU_ALARM_SUB_ALARM_LEVEL_ERROR    = 119120008,    // ���澯�����ģ��澯�����С����
    IVS_SMU_ALARM_SUB_OVER_MAX             = 119120009,    // �澯����������������1000
    IVS_SMU_ALARM_DB_NO_ALARM_TYPE         = 119120010,    // �����ݿ���û��ָ���ĸ澯����
    IVS_SMU_ALARM_CONFIRMED                = 119120011,    // �澯��ȷ��
    IVS_SMU_ALARM_REVOKED                  = 119120012,    // �澯�ѳ���
    IVS_SMU_ALARM_RECOVERY                 = 119120013,    // �澯�ѻָ�
    IVS_SMU_MSGBLOCK_INVALID               = 119120014,    // ����CMD���Ϸ�
    IVS_SMU_DEV_CODE_NOT_FOUND             = 119120015,    // �豸��ɾ���򲻴���
    IVS_SMU_ALARM_EVENT_ID_NOT_EXIST       = 119120016,    // �澯�¼�id������
    IVS_SMU_DB_HAD_SAME_ALARM_TYPE         = 119120017,    // ���ݿ����Ѿ�������ͬ�ĸ澯������
    IVS_SMU_DB_HAD_SAME_ALARM_TYPE_NAME    = 119120018,    // ���ݿ����Ѿ�������ͬ�ĸ澯����������
    IVS_SMU_ALL_USERS_OF_ALARM_COMMISSION_ILLEGAL = 119120019, //�澯��Ȩ�û�ȫ�����Ϸ�
    IVS_SMU_ALARM_AREA_NOTEXIST            = 119120020,    // �豸������
    IVS_SMU_ALARM_AREA_GUARD_OVER_MAX      = 119120021,    // ���������������(1000)
    IVS_SMU_ALARM_AREA_GUARD_DEV_OVER_MAX  = 119120022,    // �����豸�����������(128)
    IVS_SMU_ALARM_AREA_NAME_GUARD_EXIST    = 119120023,    // ���������Ѿ�����
    IVS_SMU_ALARM_SUB_STYLE_OVER_MAX       = 119120024,    // �澯�������ͳ����������(5000)
    IVS_SMU_ALARM_INFO_NOT_FOUND           = 119120025,    // δ���ҵ��澯��Ϣ
    IVS_SMU_LINKAGE_ACTION_NOT_EXIST       = 119120026,    // ��������������
    IVS_SMU_AREA_ID_NOT_EXIST              = 119120027,    // ��ʾ�÷����ѱ�ɾ��
    IVS_SMU_AREA_NO_DEV                    = 119120028,    // ָ��������û���豸
    IVS_SMU_PART_USERS_OF_ALARM_COMMISSION_ILLEGAL = 119120029, //�澯��Ȩ�û����ֲ��Ϸ�
    IVS_SMU_ALARM_AREA_DEVICE_INVALID      = 119120030,    // �����в�����������豸
    IVS_SMU_IMG_QUERY_DOMAIN_INVALID       = 119120031,    // ��������ʱ������ѯ��������ӻ��޿��������
    IVS_SMU_IMG_QUERY_TIME_OUT             = 119120032,    // ��������ʱ����ʱ����

    /* SMU:¼��ģ������룬ȡֵ��Χ��119125000 ~ 119125999 */
    IVS_SMU_CAMERA_CODE_NOT_EXIST          = 119125001,    // ��������벻����
    IVS_SMU_LINKID_NOT_EXIST               = 119125002,    // TCP���Ӳ�����
    IVS_SMU_RECORD_TIMEOUT                 = 119125003,    // ¼��ģ�鳬ʱ
    IVS_SMU_RECORD_LABEL_TIMEOUT           = 119125004,    // ¼����ǩ��ʱ
    IVS_SMU_RECORD_LOCK_TIMEOUT            = 119125005,    // ¼������ģ�鳬ʱ
    IVS_SMU_MEDIA_SAFE_TIMEOUT             = 119125006,    // ý�尲ȫ��ʱ
    IVS_SMU_BACK_RECORD_PLAN_TIMEOUT       = 119125007,    // ����¼��ƻ���ʱ
    IVS_SMU_GET_CLUSTER_RECORD_PLAN_FAIL   = 119125008,    // ��Ⱥ�²�ѯ¼��ƻ�ʧ��
    IVS_SMU_GET_RECORD_TASK_FAIL           = 119125009,    // ��ѯ¼������ʧ��
    IVS_SMU_GET_CLUSTER_RECORD_POLICY_FAIL = 119125010,    // ��Ⱥ�²�ѯ¼�����ʧ��
    IVS_SMU_GET_CLUSTER_RECORD_STATE_FAIL  = 119125011,    // ��Ⱥ�²�ѯƽ̨¼��״̬ʧ��
    IVS_SMU_CLUSTER_START_RECORD_FAIL      = 119125012,    // ��Ⱥ���ֶ�����¼��ʧ��
    IVS_SMU_CLUSTER_STOP_RECORD_FAIL       = 119125013,    // ��Ⱥ���ֶ�ֹͣ¼��ʧ��
    IVS_SMU_GET_BACK_MBU_TIMEOUT           = 119125014,    // ��ѯ���ݷ�������Ϣ��ʱ
    IVS_SMU_GET_PRERECORD_CAMERA_LIST_TIMEOUT = 119125015, // ��ѯ����Ԥ¼��������б�ʱ
    IVS_SMU_GET_PRERECORD_CAMERA_LIST_FAIL = 119125016,    // ��ѯ����Ԥ¼��������б�ȫ��ʧ��
    IVS_SMU_GET_CAMERA_BACKUP_CFG_FAIL     = 119125017,    // ��Ⱥ�²�ѯ��������ݲ���ʧ��
    IVS_SMU_BACKUP_SETTING_TIMEOUT         = 119125018,    // ����¼�������ʱ
    IVS_SMU_GET_BACKUP_PLAN_FAIL           = 119125019,    // ��Ⱥ�²�ѯ����¼��ƻ�ʧ��
    IVS_SMU_GET_MBU_CHANGE_HISTORY_FAIL    = 119125020,    // ��Ⱥ�²�ѯ���ݷ����������¼ʧ��
    IVS_SMU_TRANSPARENT_NOT_RUN            = 119125021,    // ͸��ͨ��û������
    IVS_SMU_GET_PRERECORD_CAMERA_LIST_PART_FAIL= 119125022,// ��ѯ����Ԥ¼��������б���ʧ��
    IVS_SMU_GET_RECORD_TASK_PART_FAIL      = 119125023,    // ��ѯ¼������ʧ��
    IVS_SMU_GET_RECORD_LIST_FAIL           = 119125024,    // ��ѯ¼���б�ʧ��
    IVS_SMU_MDU_NONSUPPORT_RECORD          = 119125025,    // ��ת��ģʽ��֧�ֱ���¼��
    IVS_SMU_BACK_IMG_PLAN_TIMEOUT          = 119125026,    // ͼƬ���ݼƻ���ʱ
    IVS_SMU_NOT_FOUND_FREE_MPU_T           = 119125027,    // ��ѯ����MPU-Tʧ��
    IVS_SMU_NOT_SUPPORT_HIGHSPEED_DOWNLOAD = 119125028,    // �ó�����֧�ָ�������

    /* SMU:��Ⱥģ������룬ȡֵ��Χ��119126000 ~ 119126999 */
    IVS_SMU_NVR_LIST_EMPTY                 = 119126000,    // NVR�б�Ϊ��
    IVS_SMU_NVR_SERVER_CNT_IS_ZERO         = 119126001,    // server NVR����Ϊ0
    IVS_SMU_NOT_FOUND_LEADER               = 119126002,    // û�ҵ�Leader
    IVS_SMU_GET_MEMBER_STATUS_TIME_OUT     = 119126003,    // ��ȡ��Ա״̬��ʱ
    IVS_SMU_BE_IN_CREATE_CLUSTER           = 119126004,    // �����齨��Ⱥ
    IVS_SMU_BE_IN_DISSOLVE_CLUSTER         = 119126005,    // ���ڽ�ɢ��Ⱥ
    IVS_SMU_CLUSTER_SYNCING                = 119126006,    // ���ڼ�Ⱥͬ����������Ⱥ����
    IVS_SMU_CLEAR_BLACK_LIST_IS_NULL       = 119126007,    // ClearBlackList���Ϊ��
    IVS_SMU_CREATE_CLUSTER_TIME_OUT        = 119126008,    // �齨��Ⱥ��ʱ
    IVS_SMU_NVR_LIST_NODE_NOT_EXIST        = 119126009,    // NvrList��㲻����
    IVS_SMU_NVR_INFO_NODE_NOT_EXIST        = 119126010,    // NvrInfo��㲻����
    IVS_SMU_NVR_CODE_OR_IP_INVALID         = 119126011,    // NvrCode��IP��㲻�Ϸ�
    IVS_SMU_NVR_ROLE_INVALID               = 119126012,    // Nvr��ɫ��㲻�Ϸ�
    IVS_SMU_NVR_INFO_CONTENT_INVALID       = 119126013,    // NvrInfo������ݲ��Ϸ�
    IVS_SMU_NODE_MAP_IS_EMPTY              = 119126014,    // NVR�б�Ϊ��
    IVS_SMU_FIND_NVR_TRANS_ID_NULL         = 119126015,    // ��ѯNVRʱ����IDΪ��
    IVS_SMU_FIND_NVR_CAMERA_LIST_EMPTY     = 119126016,    // ��ѯNVRʱ������б�Ϊ��
    IVS_SMU_CLUSTER_OFFLINE                = 119126017,    // ��Ⱥ������
    IVS_SMU_CLUSTER_ROLE_NOT_CLIENT        = 119126018,    // ��ɫ��ΪClient
    IVS_SMU_CLUSTER_SIZE_IS_MIN            = 119126019,    // ��Ⱥ�����Ѿ�����С
    IVS_SMU_NVR_CODE_NOT_EXIST             = 119126020,    // ��NVR������
    IVS_SMU_SEND_CLUSTER_FAIL              = 119126021,    // �·���Ⱥʧ��
    IVS_SMU_CLUSTER_CODE_HAS_EXIST         = 119126022,    // �ü�Ⱥ�����Ѿ�����
    IVS_SMU_NVR_NOT_CLEAR                  = 119126023,    // ��NVRδ����ɾ�
    IVS_SMU_CLUSTER_NOT_EXIST              = 119126024,    // �ü�Ⱥ������
    IVS_SMU_BE_IN_ADD_CLIENT               = 119126025,    // �������client
    IVS_SMU_BE_IN_DEL_CLIENT               = 119126026,    // ����ɾ��client
    IVS_SMU_CLUSTER_SCHEDULING             = 119126027,    // ��Ⱥ���ڵ��Ȼ���ɾ����Ա�����Ժ�����
    IVS_SMU_CLUSTER_CG_DEV_EXIST           = 119126028,    // ���������ϴ��ڽ����豸
    IVS_SMU_CLUSTER_CG_DEV_BEYOND_LIMITED  = 119126029,    // ���������ϵ��豸����������?
    IVS_SMU_CLUSTER_MEMBER_EXCEED_MAX      = 119126030,    // ��Ⱥ��Ա�������ֵ
    IVS_SMU_CLUSTER_SCHEDULING_RETRY       = 119126031,    // ���ڼ�Ⱥ������ԭ���������޷�Ǩ�Ƴ�ȥ
    IVS_SMU_CLUSTER_EXIST_CG_DEV           = 119126032,    // ��Ⱥ���������ϴ��ڸ������ؽ����豸

    /* SMU:����ģ������룬ȡֵ��Χ��119127000 ~ 119127999 */
    IVS_SMU_GET_CONFIG_PATH_ERROR          = 119127000,    // ��ȡ����·��ʧ��
    IVS_SMU_LOAD_NET_XML_ERROR             = 119127001,    // ����net.xmlʧ��
    IVS_SMU_NET_ELEMENTS_NODE_NOT_EXIST    = 119127002,    // NetElement��㲻����
    IVS_SMU_SAVE_NET_XML_ERROR             = 119127003,    // ����net.xmlʧ��
    IVS_SMU_LOCAL_IP_IS_NULL               = 119127004,    // ��������IPΪ��
    IVS_SMU_MEDIA_IP_IS_NULL               = 119127005,    // ����ý��IPΪ��
    IVS_SMU_DOMAIN_IS_NOT_ONLIE            = 119127006,    // ������
    IVS_SMU_GET_PWD_KEY_FAIL               = 119127007,    // ��ȡkey�ļ��е�keyʧ��

    /* SMU:��־��������룬ȡֵ��Χ��119130000 ~ 119130999 */
    IVS_SMU_SET_LOG_LEVEL_ERROR            = 119130000,    // ������־����ʧ��

    IVS_SMU_NO_PCG_NODE_ERROR              = 119139000,    // ��PCG������Ϣ

    /* SMU License���� ȡֵ��Χ��119132000 ~ 119132999 */
    IVS_SMU_LICENSE_FILE_NOEXIST           = 119132001,    // license�ļ�������
    IVS_SMU_LICENSE_ACCESS_LIMITED         = 119132002,    // License������������
    IVS_SMU_LICENSE_ESN_MISMATCH           = 119132003,    // License����ESN��ƥ��
    IVS_SMU_LICENSE_ACTIVATION_FAIL        = 119132004,    // License����ʧ��
    IVS_SMU_DEV_NOT_EXIST_OR_LICENSE_ACCESS_LIMITED = 119132005, //�豸�����ڻ���License����
    IVS_SMU_DEVICE_NUM_LIMITED             = 119132006,    //�豸����������
    IVS_SMU_DEVICE_NUM_MAY_LIMITED         = 119132007,    //�����û���������豸�����ܳ������������������Ժ�
    IVS_SMU_NO_LICENSE                     = 119132008,    //�뵼��license

    /* SMU  �ƻ��洢���� ȡֵ��Χ��119133000 ~ 119133999 */
    IVS_SMU_CLOUD_STORAGE_DOMAIN_ERROR     = 119133001,    // ��������
    IVS_SMU_CLOUD_STORAGE_DNS_ERROR        = 119133002,    // DNS����
    IVS_SMU_CLOUD_STORAGE_PATH_ERROR       = 119133003,    // ����·������
    IVS_SMU_CLOUD_STORAGE_STATUS_ERROR     = 119133004,    // ״̬����
    IVS_SMU_CLOUD_STORAGE_SPACE_LACK_ERROR = 119133005,    // ���ú�9000����������СС�ڸ����ȼ��ռ�
    IVS_SMU_CLOUD_STORAGE_SPACE_LESS_LIC_ERROR = 119133006, //���óɹ��������ܴ�СС��license���ƴ�С
    IVS_SMU_QUERY_CLOUD_STORAGE_FAIL       = 119133007,    //��ѯN9000״̬��Ϣʧ��
    IVS_SMU_STORAGE_IS_EMPTY               = 119133008,    //�洢�ռ䲻��


    /* SMU  ������� ȡֵ��Χ��119134000 ~ 119134999 */
    IVS_SMU_NAT_INSTANCE_EXIST             = 119134001,    //��������ʵ��ʧ�ܣ����иö˿ڶ�Ӧ��ʵ��
    IVS_SMU_NAT_IP_COVERED                 = 119134002,    //����Nat IP����ʾ��
    
    /******************************************************************
     *   SCU�����붨�壨ģ����룺12��
     *****************************************************************/
    IVS_SCU_LINKAGE_DEV_SIZE_ILLEGAL       = 129123002,    // �����豸�ĸ����Ƿ�(���ܳ���4��)
    IVS_SCU_LINKAGE_POLICY_ID_NOT_EXIST    = 129123003,    // ��������ID������
    IVS_SCU_LINKAGE_POLICY_ID_EXIST        = 129123004,    // ��������ID�Ѿ�����
    IVS_SCU_LINKAGE_POLICY_EXIST           = 129123005,    // ���������Ѿ�����
    IVS_SCU_LINKAGE_POLICY_COUNT_OVER      = 129123006,    // �澯�������Գ����������(3000)
    IVS_SCU_LINKAGE_ACTION_ILLEGAL         = 129123007,    // �澯�������������ظ�
    IVS_SCU_SEND_ALARM_CONFIRM_SMU_FAIL    = 129123008,    // ���͸澯ȷ������SMUʧ��
    IVS_SCU_LINKAGE_DEV_COUNT_ERROR        = 129123010,    // �����豸������������
    IVS_SCU_LINKAGE_DEV_NOT_EXIST          = 129123011,    // ����Ŀ���豸�����ڻ�����ɾ��
    IVS_SCU_LINKAGE_ACTION_NOT_EXIST       = 129123012,    // ��������������

    IVS_SCU_ONLINE_USER_EXPIRE             = 129105001,    // ��¼��Ϣ��ʧЧ�������µ�¼

    IVS_SCU_DEV_OFFLINE                    = 129108001,    // �豸������
    IVS_SCU_DEV_NOT_EXIST                  = 129108002,    // �豸�����ڻ�����ɾ��
    IVS_SCU_DEV_NOT_EXIST_CLUSTER          = 129108003,    // (��Ⱥʹ��)�豸�����ڵ�ǰNVR��������Ǩ��
    IVS_SCU_DEV_MODULE_ERROR               = 129108004,    // ģ��У��ʧ��
    IVS_SCU_DEV_PROTOCALTYPE_ERROR         = 129108005,    // �豸Э������У��ʧ��
    IVS_SCU_DEV_VENDORTYPE_ERROR           = 129108006,    // ��Ӧ������У��ʧ��
    IVS_SCU_DEV_FORMTYPE_ERROR             = 129108007,    // ��Ʒ��̬����У��ʧ��
    IVS_SCU_DEV_MODELTYPE_ERROR            = 129108008,    // �豸�ͺ�����У��ʧ��
    IVS_SCU_DEV_ALARMENABLE_ERROR          = 129108009,    // �澯ʹ��У��ʧ��
    IVS_SCU_DEV_VIDEOFORMAT_ERROR          = 129108010,    // ��Ƶ��ʽУ��ʧ��
    IVS_SCU_DEV_REGPASSWORD_ERROR          = 129108011,    // ע������Ϊ��
    IVS_SCU_DEV_MAXDIRCONNECTNUM_ERROR     = 129108012,    // ���ֱ����ʧ��
    IVS_SCU_DEV_NVRCODE_ERROR              = 129108013,    // NVRΪ���Ϸ�
    IVS_SCU_DCG_RESPONSE_FAIL              = 129108018,    // DCG��Ӧʧ��
    IVS_SCU_MAIN_DEV_GURAD_SET_FAIL        = 129108021,    // ���豸������ʧ��
    IVS_SCU_DEV_NOT_IN_WHITE_LIST_CLUSTER  = 129108022,    // �豸�����ڵ�ǰNVR���������Ƴ�,��Ⱥʹ��
    IVS_SCU_DEV_NOT_IN_WHITE_LIST          = 129108023,    // �豸�����ڵ�ǰNVR���������Ƴ�,�Ǽ�Ⱥʹ��
    IVS_SCU_VIDEO_STREAM_NUM_ERROR         = 129108024,    // ��Ƶ��������ȷ
    IVS_SCU_SENDTODCG_FAIL                 = 129108026,    // �·�DCGʧ��
    IVS_SCU_ADD_AUDIO_PARA_FAIL            = 129108027,    // ������Ƶ����ʧ��
    IVS_SCU_GET_LOGIN_ID_FAIL              = 129108029,    // ��ȡ�û�IDʧ��
    IVS_SCU_CHOWN_DEV_TEMPLATE_FAIL        = 129108030,    // �豸ģ���޸��û�ʧ��
    IVS_SCU_DEV_TEMPLATE_NONEXISTENT       = 129108031,    // �豸ģ�岻����
    IVS_SCU_DEV_IS_ONLINE                  = 129108032,    // �豸������
    IVS_SCU_SUB_DEV_INFO_NOT_EXIST         = 129108033,    // ���豸������Ϣ������
    IVS_SCU_CHMOD_DEV_TEMPLATE_FAIL        = 129108034,    // �޸��豸ģ��Ȩ��ʧ��
    IVS_SCU_ADD_SUBDEVICE_FAIL             = 129108035,    // ������豸ʧ��ʧ��
    IVS_SCU_SEND_MSG_TO_SMU_FAIL           = 129108036,    // ����smu��Ӧʧ��
    IVS_SCU_ADD_ENVR_SUBDEVICE_FAIL        = 129108037,    // ���ENVR�豸ʧ��
    IVS_SCU_ENVR_DEV_NOT_EXIST             = 129108038,    // eNVR�豸�����ڻ�����ɾ��
    IVS_SCU_MAIN_DEV_NOT_EXIST             = 129108039,    // ���豸�����ڻ�����ɾ��
    IVS_SCU_DEV_OFFLINE_CFG_NOT_EXIST      = 129108040,    // �豸�������ò�����
    IVS_SCU_DEV_TYPE_IS_NULL               = 129108041,    // �豸�豸��̬���Ϸ�
    IVS_SCU_DEV_OSD_PARA_NOT_EXIST         = 129108042,    // �豸OSD����������
    IVS_SCU_DEL_ENVR_DEVICE_FAIL           = 129108043,    // ɾ��ENVR�豸ʧ��
    IVS_SCU_SEL_SHARE_DEVICE_INVALID       = 129108044,    // ��ѯ�����豸�������Ϸ�
    IVS_SCU_MODEL_TEMPLATE_IS_NULL         = 129108045,    // �豸ģ������Ϊ��
    IVS_SCU_DR_MAIN_DEV_NOT_EXIST          = 129108046,    // �����豸��Ϣ������
    IVS_SCU_DEV_UPDATE_TEMPATE_MAIN_DEV    = 129108047,    // �豸ģ��������豸��Ϣʧ��
    IVS_SCU_PRE_RECORD_DEV_NOT_EXIST       = 129108048,    // ����Ԥ¼�豸������
    IVS_SCU_PU_NOT_SUPPORT_GET_PARAM       = 129108049,    // ǰ�˲�֧��ǰ�˲�����ȡ
    IVS_SCU_MOD_ENVR_SUBDEVICE_FAIL        = 129108050,    // �޸�ENVR�豸ʧ��
    IVS_SCU_MOD_T28181_LENGTH_INVALID      = 129108051,    // T28181���Ȳ��Ϸ�
    IVS_SCU_LOGIN_TYPE_INVALID             = 129108053,    // ��֤���Ͳ��Ϸ�
    IVS_SCU_BLANCE_SUPPORT_INVALID         = 129108054,    // �Ƿ�֧�ּ�Ⱥ�������Ϸ�
    IVS_SCU_DIRECTCONNECT_FIRST_INVALID    = 129108055,    // �Ƿ�֧��ֱ�����Ȳ������Ϸ�
    IVS_SCU_DECRYPT_PASSWORD_INVALID       = 129108056,    // smu�����������ʧ��
    IVS_SCU_DECRYPT_REGPASSWORD_INVALID    = 129108057,    // smu����ע���������ʧ��
    IVS_SCU_PASSWORD_LENGTH_INVALID        = 129108058,    // ���볤�Ȼ��߸��ӶȲ�����Ҫ��
    IVS_SCU_PARSE_CAMERA_TYPE_FAILED       = 129108060,    // ���������ת��ʧ��
    IVS_SCU_MAIN_DEV_SEQUENCE_TYPE_INVALID = 129108061,    // ���豸���кŲ��Ϸ�
    IVS_SCU_TAS_CODE_INVALID               = 129108062,    // TASCode���Ϸ�
    IVS_SCU_DEV_SN_INVALID                 = 129108063,    // DevSN���Ϸ�
    IVS_SCU_DEV_REG_PASSWORD_INVALID       = 129108064,    // ע�����벻�Ϸ�
    IVS_SCU_DEV_IP_TYPE_INVALID            = 129108065,    // �豸Ip���Ͳ��Ϸ�
    IVS_SCU_GET_DEV_LIST_FAILED            = 129108066,    // ��ȡ���豸�б�ʧ��
    IVS_SCU_PATCH_PARSE_MAIN_DEV_FAILED    = 129108067,    // �����������豸ȫ��ʧ��
    IVS_SCU_PWD_STRENGTH_WEAK              = 129108068,    // ����ǿ�Ȳ���
    IVS_SCU_DEVICE_IP_EXIST                = 129108069,    // �豸IP�Ѵ���
    IVS_SCU_DEV_REG_PWD_INVALID            = 129108070,    // ���븴�ӶȲ�����Ҫ������ر����븴�Ӷ�У�飬��鿴����ָ��
    IVS_SCU_SET_LOG_LEVEL_RSP_FAIL         = 129108071,    // �������ʱ��ȱ���ʱ��쵼�¸�ģ����־��������ʧ��   
    IVS_SCU_SHADOW_DEV_NAME_TOO_LONG       = 129108072,    // Ӱ�����������̫��
    IVS_SCU_SHADOW_CHANNEL_NAME_TOO_LONG   = 129108073,    // Ӱ���������Ƶ��ͨ������̫��
    IVS_SCU_RESOLUTION_TOO_LARGE           = 129108074,    // ������ֱ��ʹ����ݲ�֧��
    IVS_SCU_UNIFIEDCODE_IS_EXIST           = 129108075,    // �Ѵ�����ͬ��ͳһ����
    IVS_SCU_NULL_POINTER                   = 129108076,    // �������ڲ����󣬿�ָ���쳣;
    IVS_SCU_PARSE_RESOURCE_FILE_FAIL       = 129108077,    // ������Դ�ļ�ʧ��
    IVS_SCU_PARSE_JSON_FAIL                = 129108078,    // ����jsonʧ��
    IVS_SCU_UPDATE_MODULE_DATA_FAIL        = 129108079,    // SCU����ģ������ʧ��
    
    IVS_SCU_INPUT_PARAM_INVALID            = 129108087,    // SCU��δ���

    /* ���Эͬ������ */
    IVS_SCU_DCG_TIMEOUT                    = 129108077,    // DCG��Ӧ��ʱ
    IVS_SCU_DCG_OFF_LINE                   = 129108078,    // DCG������
    IVS_SCU_COOPERATION_PARA_INVALID       = 129108079,    // Э�����������Ϸ�
    IVS_SCU_DEL_COOPERATION_RSP_FAIL       = 129108080,    // ɾ��Э������Ӧʧ��
    IVS_SCU_XML_NODE_NOT_EXIST             = 129108081,    // xml�ڵ㲻����
    IVS_SCU_ENTRYIPC_OCCUPIED              = 129108082,    // ����Э����ʱ���IPC������Э����ռ��
    IVS_SCU_AllIPC_OCCUPIED                = 129108083,    // ����Э����ʱ����IPC������Э����ռ��
    IVS_SCU_FEWERIPC_OCCUPIED              = 129108084,    // ����Э����ʱ����IPC������Э����ռ��
    IVS_SCU_COOPERATION_REACH_MAX_COUNT    = 129108085,    // Э���������ﵽ����
    IVS_SCU_COOPER_IPC_REACH_MAX_COUNT     = 129108086,    // Э������IPC�����ﵽ����
    IVS_SCU_CONNECT_DB_ERROR               = 129108087,    // SCU�������ݿ�ʧ��

    IVS_SCU_INIT_INCOMPLETE                = 129108088,    // SCUδ��ɳ�ʼ��;

    IVS_SCU_CAMERA_NOT_EXIST               = 129109003,    // ��������豸�����ڻ�����ɾ��
    IVS_SCU_MOTION_DETECTION_NOT_EXIST     = 129109004,    // �ƶ������Ϣ������
    IVS_SCU_VIDEO_HIDE_NOT_EXIST           = 129109005,    // ͼ���ڵ���Ϣ������
    IVS_SCU_VIDEO_MASK_NOT_EXIST           = 129109006,    // ��˽������Ϣ������
    IVS_SCU_CONF_PTZ_DB_ERROR              = 129109007,    // ������̨�����ɹ������ݱ��浽���ݿ�ʧ��
    IVS_SCU_BROADCAST_IP_PORT_EXIST        = 129109008,    // �鲥IP�˿��Ѵ��ڻ��ѱ�ռ��

    IVS_SCU_CONF_VOICE_CHAN_TIMEOUT        = 129112001,    // ��������������ʱ
    IVS_SCU_CONF_VOICE_CHAN_DB_ERROR       = 129112002,    // �������������ɹ������ݱ��浽���ݿ�ʧ��

    IVS_SCU_GETURL_ERROR                   = 129115001,    // ��ȡý��URLʧ��
    IVS_SCU_GETURL_TIMEOUT                 = 129115002,    // ��ȡý��URL�Ự��ʱ
    IVS_SCU_GETURL_SESSION_EXIST           = 129115003,    // ��ȡý��URL�������Ѵ���

    IVS_SCU_PTZ_LOCKED                     = 129116001,    // ��̨������
    IVS_SCU_PTZ_CONTROLED                  = 129116002,    // ��̨��ͬ���ȼ����߸����ȼ��û�����
    IVS_SCU_PTZ_LEVEL_LOW_TO_UNLOCK        = 129116003,    // ��̨��ͬ���ȼ����߸����ȼ��û�����
    IVS_SCU_PTZ_LOCKED_BY_ALARM            = 129116004,    // ��̨���澯�����У����������
    IVS_SCU_PTZ_NOT_LOCKED                 = 129116005,    // ��̨δ�������������Զ�����
    IVS_SCU_PTZ_GET_USER_INFO_FAIL         = 129116006,    // ��ȡ�û���̨��Ϣʧ��
    IVS_SCU_PTZ_MODE_SET_RUN               = 129116007,    // ͬ���ȼ����߸����ȼ��û�����¼��PTZ�켣
    IVS_SCU_PTZ_LOCKE_NOT_SUPPORT          = 129116008,    // ����֧����̨��������
    IVS_SCU_PTZ_MODE_SET_NOT_SUPPORT       = 129116009,    // ����֧��ģʽ¼�Ʋ���
    IVS_SCU_PTZ_MODE_CRUISE_NOT_EXIST      = 129116010,    // ģʽ�켣����������

    IVS_SCU_PRESET_NUM_EXCEED_MAX          = 129117001,    // Ԥ��λ�Ѿ��ﵽ���ֵ
    IVS_SCU_PRESET_NUM_MAY_EXCEED_MAX      = 129117002,    // �����û�Ҳ�����Ԥ��λ�����ܳ��������������Ժ�
    IVS_SCU_PRESET_IN_CRUISE_TRACK         = 129117003,    // Ԥ��λ��Ѳ���켣�У��޷�ɾ��
    IVS_SCU_PRESET_NOT_EXIST               = 129117004,    // Ԥ��λ������
    IVS_SCU_PRESET_NAME_REPEAT             = 129117005,    // ��������Ѿ�������ͬ��Ԥ��λ����
    IVS_SCU_PRESET_IN_CRUISE_PLAN          = 129117006,    // Ԥ��λ��Ѳ���ƻ��У�����ɾ��
    IVS_SCU_PRESET_IS_GUARD_POS            = 129117007,    // Ԥ��λ�����ó����õĿ���λ������ɾ��
    IVS_SCU_PRESET_NOT_SUPPORT_FOCUS_SWITCH = 129117008,   // ���������֧��Ԥ��λ�Խ��ǿ��أ���������
    
    IVS_SCU_GUARD_POS_NOT_EXIST            = 129117101,    // ����λ������

    IVS_SCU_TRACK_NUM_EXCEED_MAX           = 129118001,    // Ѳ���켣�����Ѿ��ﵽ���ֵ
    IVS_SCU_TRACK_NUM_MAY_EXCEED_MAX       = 129118002,    // �����û�Ҳ�����Ѳ���켣�����ܳ��������������Ժ�
    IVS_SCU_TRACK_POINT_NUM_EXCEED_MAX     = 129118003,    // �켣�е�Ԥ��λ�������ܳ���20��
    IVS_SCU_TRACK_POINT_INVALID            = 129118004,    // �켣�е�Ԥ��λ�����ڻ����Ѿ�ɾ��
    IVS_SCU_TRACK_NOT_EXIST                = 129118005,    // Ѳ���켣������
    IVS_SCU_TRACK_NAME_REPEAT              = 129118006,    // ��������Ѿ�������ͬ��Ѳ���켣����
    IVS_SCU_GUARD_PLAN_NOT_EXIST           = 129118007,    // Ѳ���ƻ�������
    IVS_SCU_TRACK_IS_RUNNING               = 129118008,    // ��Ѳ���켣����ִ��
    IVS_SCU_TRACK_IS_IN_PLAN               = 129118009,    // �ù켣�ڼƻ��У��޷�ɾ��
    IVS_SCU_MODE_TRACK_NUM_EXCEED_MAX      = 129118010,    // ģʽѲ���켣�����Ѿ��ﵽ���ֵ
    IVS_SCU_MODE_TRACK_NUM_MAY_EXCEED_MAX  = 129118011,    // �����û�Ҳ�����ģʽѲ���켣�����ܳ��������������Ժ�

    IVS_SCU_NO_NVR_NOT_EXIST               = 129124001,    // �洢��Ϣ������
    IVS_SCU_DEV_RECORD_PARA_NOT_EXIST      = 129124002,    // �豸¼�������Ϣ������
    IVS_SCU_STORAGE_NOT_ALLOC              = 129124003,    // �洢�ռ�δ����
    IVS_SCU_STORAGE_CANT_LESSEN            = 129124004,    // �洢�ռ䲻����С��ֻ������
    IVS_SCU_STORAGE_IS_SCARCE              = 129124005,    // �洢�ռ䲻��
    IVS_SCU_CAMERA_BACKUP_CFG_NOT_EXIST    = 129124006,    // ��������ݲ�����¼������
    IVS_SCU_CAMERA_BACKUP_PLAN_NOT_EXIST   = 129124007,    // ��������ݼƻ�������
    IVS_SCU_NEW_MBU_ADD_BACKUP_PLAN_FAIL   = 129124008,    // ����MBUǨ�Ʊ��ݼƻ�ʧ��
    IVS_SCU_RECORD_MBU_CONTRAIL_NOT_EXIST  = 129124009,    // MBU�켣������
    IVS_SCU_BACKUP_RECORD_REGION_NOT_EXIST = 129124010,    // MBU¼�񱸷ݼ�¼����ֹ��Χ������
    IVS_SCU_ENCODEMODE_NOT_H264            = 129124011,    // ���������ʽ����H264

    /*���ֱ��ݴ����� begin*/
    IVS_SCU_DEVICE_STRATEGY_MAP_NOT_EXIST  = 129124021,    // �豸¼�����ӳ����¼������
    IVS_SCU_NVR_HAS_THIS_CAMERA            = 129124012,    // NVR���ڸ������
    IVS_SCU_OTHER_EXDOMAIN_HAS_THIS_CAMERA = 129124013,    // ���������Ѿ��ڸ�NVR�����˸������
    IVS_SCU_SEND_MSG_TO_MU_FAIL            = 129124014,    // �·���Ϣ��MUʧ��
    IVS_SCU_CAMERA_IS_NOT_PR               = 129124016,    // ���豸���������豸
    IVS_SCU_PR_CAMERA_IS_NOT_HAVE_PALN     = 129124017,    // δ�ƶ�¼����Ի�ƻ�
    IVS_SCU_PR_CAMERA_CAN_NOT_MOD_RECORD   = 129124018,    // ���豸�����޸�¼�����
    IVS_SCU_DR_CAMERA                      = 129124019,    // �����豸
    IVS_SCU_MBU_HAS_THIS_CAMERA            = 129124020,    // ��ͬ�������������ͻ
    /*���ֱ��ݴ����� end*/

    IVS_SCU_PU_MANUAL_RECORD_EXIST         = 129124015,    // ǰ���ֶ�¼���Ѵ���

    IVS_SCU_RECORD_PLAN_NOT_EXIST          = 129125001,    // ¼��ƻ�������
    IVS_SCU_WAIT_DCG_RSP                   = 129125002,    // �ȴ�DCG��Ӧ
    IVS_SCU_RECORD_STREAM_TYPE_NOT_EXIST   = 129125003,    // ¼��ƻ�,�������Ͳ�֧��
    IVS_SCU_PLAT_REVORD_PLAN_OVER_CAPACITY = 129125004,    // ƽ̨¼��ƻ��ﵽ������� 
    
    /* SCU:ҵ����ٴ����룬ȡֵ��Χ��129127050 ~ 129127100*/
    IVS_SCU_TRACE_NO_FIND                  = 129127050,    // ����TraceIDδ�ҵ�ҵ����Ϣ
    IVS_SCU_CREATE_TRACE_FAIL              = 129127052,    // ����ҵ�����ʧ��
    IVS_SCU_CANCLE_TRACE_FAIL              = 129127053,    // ȡ��ҵ�����ʧ��
    IVS_SCU_TRACE_TIME_MORE_THAN_MAX       = 129127054,    // ҵ�����ʱ�䳬�����ֵ

    /* SCU:�ⲿ�澯ϵͳ�����룬ȡֵ��Χ��129128000 ~ 129128100*/
    IVS_SCU_UNICODE_EXISTS                 = 129128000,    // ��ʶ���Ѵ���
    IVS_SCU_UNICODE_INVALID                = 129128001,    // ��ʶ�����ȷǷ�������Ƿ��ַ�
    IVS_SCU_LOCATION_INVALID               = 129128002,    // ��װλ�ó��ȷǷ�������Ƿ��ַ�
    IVS_SCU_EXDEV_NUM_EXCEED               = 129128003,    // �ⲿ�澯�豸���ﵽ���ֵ
    IVS_SCU_EXDEV_CODE_GEN_FAIL            = 129128004,    // �ⲿ�澯�豸��������ʧ��
    IVS_SCU_EXSYS_TYPE_INVALID             = 129128005,    // ϵͳ���ͳ��ȷǷ�������Ƿ��ַ�
    IVS_SCU_EXDEV_TYPE_INVALID             = 129128006,    // �豸���ͳ��ȷǷ�������Ƿ��ַ�
    IVS_SCU_EXDEV_TYPE_ERROR               = 129128007,    // �豸���ͷǷ�
	
	/* SCU:��Ⱥģʽ�����룬ȡֵ��Χ��129134101 ~ 129134200 */
    IVS_SCU_NOT_CLUSTER_MODE               = 129134101,    // ģʽ���󣬷Ǽ�Ⱥģʽ
    IVS_SCU_REDIRECTION_ERROR              = 129134102,    // �������ض��򣨼�Ⱥ���豸�ں�����ʱ�����ض���
    IVS_SCU_SCRIPT_RUN_FAIL                = 129134103,    // �ű�ִ�г���
    IVS_SCU_CLUSTER_SIZE_INVALID           = 129134104,    // ��Ⱥ��Ա��С���Ϸ�
    IVS_SCU_DEVLIST_VERSION_NOTSAME        = 129134105,    // ����DB���豸�汾��������DB��һ��
    IVS_SCU_MODE_NOT_SYNC                  = 129134106,    // ���δͬ��
    IVS_SCU_NOT_DB_NODE                    = 129134107,    // �����������ݿ�ڵ�
    IVS_SCU_NOT_CLUSTER_CG                 = 129134108,    // �Ǹ������ر���
    IVS_SCU_DEV_NOT_REG_CG                 = 129134109,    // ���豸ע��ƽ̨���豸
    IVS_SCU_CLUSTER_NO_CG                  = 129134110,    // ����ע�ᵽƽ̨���豸����ѡ�񸡶�����
    IVS_SCU_CLUSTER_CG_DEV_EXIST           = 129134111,    // ���������ϴ��ڽ����豸
    IVS_SCU_FCG_IP_EXIST                   = 129134112,    // ��������IP�Ѵ���
    IVS_SCU_CLUSTER_CDB_NO_SYNC            = 129134113,    // �������ݿ�δͬ����Ǩ��ʧ��
    IVS_SCU_CLUSTER_DEV_NOT_READY          = 129134114,    // �������ݿ��豸��Ϣ���������ݿⲻһ�£�Ǩ��ʧ��
	IVS_SCU_CLUSTER_IN_SWITCH              = 129134115,    // �������ݿ��������л��У�Ǩ��ʧ��
    IVS_SCU_CLUSTER_IN_RECORD              = 129134116,    // Ǩ��ɹ����ȴ�����¼��

    /* SCU:�޸��������չ�����ӿڴ����룬ȡֵ��Χ��129147000 ~ 129147100*/
    IVS_SCU_WATERMARK_SECURITY_FAIL        = 129147000,    // DCG֪ͨPU���ˮӡʧ�ܡ�MU�л�ý�尲ȫ����ʧ��
    IVS_SCU_WATERMARK_FAIL                 = 129147001,    // DCG֪ͨPU���ˮӡʧ��
    IVS_SCU_SECURITY_FAIL                  = 129147002,    // MU�л�ý�尲ȫ����ʧ��
    IVS_SCU_CACHERECORD_FAIL               = 129147003,    // DCG֪ͨPU���û��油¼����ʧ��
    IVS_SCU_SET_CAMERA_EXTEND_PARA_FAIL    = 129147004,    // �����������չ����ʧ��
    
    /********************************************
    *   SMU Portal�����붨�壨ģ����룺13��
    *******************************************/


    /******************************************
    *   CMU�����붨�壨ģ����룺14��
    *******************************************/
    IVS_CMU_FIND_LEADER_ERROR              = 149107001,    // ����Leaderʧ��
    IVS_CMU_ZNODE_NOT_EXIST                = 149107002,    // ��Ⱥ�ڵ㲻����

    IVS_CMU_PARAMETER_ERROR                = 149112016,    // ��������
    IVS_CMU_SCHEDULE_GET_IPC_LIST_ERROR    = 149112017,    // ����ʱ��ȡIPC�б�ʧ��
    IVS_CMU_SCHEDULE_LENS_MANAGE_ERROR     = 149112018,    // ���Ⱦ�ͷ����ʧ��
    IVS_CMU_SCHEDULE_SET_IPC_NVR_ERROR     = 149112019,    // ���ȳɹ�������IPC��NVR�󶨹�ϵʧ��
    IVS_CMU_SCHEDULE_SET_IPC_TRACK_ERROR   = 149112020,    // ���ȳɹ�������IPC��ʷ�켣ʧ��
    IVS_CMU_SCHEDULE_ARITHMETIC_ERROR      = 149112021,    // �����㷨ʧ��
    IVS_CMU_SEND_SYNC_MSG_PART_ERROR       = 149112022,    // ����ͬ����Ϣʧ��
    IVS_CMU_GET_NON_NVR_STUATUS_ERROR      = 149112023,    // δ���ҵ��κ�NVR ��״̬
    IVS_CMU_SET_CLUSTER_MEMBER_ERROR       = 149112024,    // ���ü�Ⱥ��Աʧ��
    IVS_CMU_SET_RIGHT_ERROR                = 149112025,    // ��Ⱥ���ò�����Ȩ�ޣ��������Leader��Ա���ͼ�Ⱥ������Ϣ���ش���
    IVS_CMU_SET_CLUSTER_INFO_ERROR         = 149112026,    // ���ü�Ⱥ��Ϣʧ��
    IVS_CMU_GET_USABLE_NVR_INFO_ERROR      = 149112027,    // ���� NVR �б�Ϊ��
    IVS_CMU_SEND_CLEAN_MSG_ERROR           = 149112028,    // �����������ʷ�켣��Ϣʧ��
    IVS_CMU_GET_DFS_LOCK_ERROR             = 149112029,    // ��ȡ�ֲ�ʽ�ļ���ʧ��
    IVS_CMU_GET_DFS_LOCK_TIMEOUT_ERROR     = 149112030,    // ��ȡ�ֲ�ʽ�ļ�����ʱʧ��
    IVS_CMU_PLUGIN_NOT_FOUND_ERROR         = 149112031,    // �Ҳ�����Ӧ�Ĳ��
    IVS_CMU_NO_AVAILABLE_CONTAINER_ERROR   = 149112032,    // ����ʱû�п�������
    IVS_CMU_DISCONNECT_WITH_ZK_ERROR       = 149112033,    // ��ZK�Ͽ�����
    IVS_CMU_TASK_SHIFT_IN_ERROR            = 149112034,    // ����Ǩ��ʧ�ܣ�����У�
    IVS_CMU_TASK_SHIFT_SAME_NODE_ERROR     = 149112035,    // �豸����Ǩ�Ƶ�Դ�ڵ㣬Ǩ��ʧ��
    IVS_CMU_TASK_SHIFT_NO_DEV_ERROR        = 149112036,    // �豸�Ѳ���Դ�ڵ㣬Ǩ��ʧ��
    IVS_CMU_TASK_SHIFT_NO_CONTAINER_ERROR  = 149112037,    // ��Ⱥ���ڵ����У����Ժ�
    IVS_CMU_TASK_SHIFT_SMART_DEV_OVERLOAD  = 149112038,    // �����豸�������Ǩ��ʧ��
    IVS_CMU_TASK_SHIFT_DEV_OVERLOAD        = 149112039,    // �豸�������Ǩ��ʧ��
    IVS_CMU_CLUSTER_INIT_ERROR             = 149112040,    // ��Ⱥ��ʼ����
    IVS_CMU_TASK_SHIFT_NOT_SUPPORT_ERROR   = 149112041,	   // �豸��֧��Ǩ�ƣ�Ǩ��ʧ��
	IVS_CMU_TASK_SHIFT_DISK_OVERLOAD       = 149112042,    // �洢�ռ䳬��񣬲�֧��¼�񼰿����豸Ǩ��
	IVS_CMU_TASK_SHIFT_NET_OVERLOAD        = 149112043,    // �������Ǩ��ʧ��
	IVS_CMU_TASK_SHIFT_TOTAL_OVERLOAD      = 149112044,    // �������������Ǩ��ʧ��
	IVS_CMU_TASK_SHIFT_RECORD_OVERLOAD     = 149112045,    // ¼������������Ǩ��ʧ��
    IVS_CMU_CONNECT_DB_ERROR               = 149112046,    // CMU�������ݿ�ʧ��
    IVS_CMU_CONTAINER_ABNORMAL_ERROR       = 149112047,   //����ʱ�����쳣��Ǩ��ʧ��

    //���ڼ�Ⱥ������豸ʧ�ܵĴ�����(���ܱ���~13)
    IVS_CMU_ADD_MAIN_DEV_OUT_OF_CONTENT    = 149113001,    // ������Ⱥ�����������֣��豸���ʧ��
    IVS_CMU_ADD_MAIN_DEV_WRITE_ZK_ERROR    = 149113002,    // �������ݳ����豸���ʧ��
    IVS_CMU_ADD_MAIN_DEV_SCHEDULE_ERROR    = 149113003,    // �����豸�����豸���ʧ��
    IVS_CMU_ADD_MAIN_DEV_READ_ZK_ERROR     = 149113004,    // ��ȡ���ݳ����豸���ʧ��
    IVS_CMU_ADD_MAIN_DEV_DUPLICATE         = 149113005,    // �豸�Ѵ��ڣ��豸���ʧ��
    IVS_CMU_ADD_DEV_ERROR                  = 149113006,    // ����豸ʧ��
    IVS_CMU_ADD_DEVS_ALL_ERROR             = 149113007,    // ��������豸ʧ��
    IVS_CMU_DEVICE_IP_EXIST                = 149113008,    // �豸IP�Ѵ��ڣ����ʧ��
    IVS_CMU_DEVICE_IP_DUPLICATE            = 149113009,    // �ظ����IP��ͬ���豸
    IVS_CMU_DEVICE_CODE_DUPLICATE          = 149113010,    // �ظ������ͬ������豸����ȷ����Ҫ��ӵ��豸

    //���ڶ�λ���������SMU�쳣ʱ��ʵ�����ض���ʧ�ܵĴ�����(���ܱ���~14)
    IVS_CMU_IPC_CODE_NOT_FOUND_ERROR       = 149114001,    // �������ɾ���򲻴���
    IVS_CMU_GET_NVR_ID_ERROR               = 149114002,    // ��ȡ���ݳ�����λ�����ʧ��
    IVS_CMU_GET_NVR_DATA_ERROR             = 149114003,    // ��ȡ���ݳ�����λ�����ʧ��

    //����OMUͳһ���ã���ѯ���޸������������־�����ʧ��ʱ�Ĵ�����(���ܱ���~15)
    IVS_CMU_CONFIG_TYPE_NOT_FOUND_ERROR    = 149115001,    // ���������Ͳ�����
    IVS_CMU_CONFIG_NAME_NOT_FOUND_ERROR    = 149115002,    // ���������Ʋ�����
    IVS_CMU_CONFIG_VALUE_INVALID_ERROR     = 149115003,    // �����������Ч
    IVS_CMU_READ_LOG_SFTP_CONF_ERROR       = 149115004,    // ��ȡ��־������ʧ��
    IVS_CMU_WRITE_LOG_SFTP_CONF_ERROR      = 149115005,    // �޸���־������ʧ��

    //���ڶ�λ�������ʷ�켣��¼�������ʧ�ܵĴ����루���ܱ���~16��
    IVS_CMU_CAMERA_CODE_NOT_FOUND_ERROR    = 149116001,    // �������ɾ���򲻴���
    IVS_CMU_GET_CAMERA_TRACE_ERROR         = 149116002,    // ��ȡ������켣��Ϣʧ��

    //���ڸ澯�����Ĵ����루���ܱ���~20��
    IVS_CMU_LINKAGE_ACTION_ILLEGAL         = 149120001,    // �澯�������������ظ�
    IVS_CMU_LINKAGE_POLICY_ID_EXIST        = 149120002,    // ��������ID�Ѿ�����
    IVS_CMU_LINKAGE_POLICY_EXIST           = 149120003,    // ���������Ѿ�����

    IVS_CMU_PTR_NULL_ERROR                 = 149131001,    // ���ָ��Ϊ��
    IVS_CMU_OBJ_TO_XML_ERROR               = 149131002,    // ��Ϣ��ת��xmlʧ��
    IVS_CMU_XML_TO_OBJ_ERROR               = 149131003,    // xmlת����Ϣ��ʧ��
    IVS_CMU_CAN_NOT_FIND_LINKID_ERROR      = 149131004,    // �Ҳ���LinkID
    IVS_CMU_NETELEMENT_TYPE_NULL_ERROR     = 149131005,    // ��Ԫ����Ϊ��
    IVS_CMU_NSS_ENCODE_ERROR               = 149131006,    // NSS��Ϣ����ʧ��
    IVS_CMU_NSS_DECODE_ERROR               = 149131007,    // NSS��Ϣ����ʧ��
    IVS_CMU_SEND_SYNC_MSG_ERROR            = 149131008,    // ����ͬ����Ϣʧ��
    IVS_CMU_SEND_MSG_ERROR                 = 149131009,    // �����첽��Ϣʧ��
    IVS_CMU_XML_PARSE_STREAM_ERROR         = 149131010,    // XML Parse��ʧ��
    IVS_CMU_DELETE_NET_LINK_ERROR          = 149131011,    // ɾ����Ԫlinkʧ��
    IVS_CMU_CREATE_LINK_ERROR              = 149131012,    // ��̬������Ԫ����ʧ��
    IVS_CMU_DELETE_TRANSID_ERROR           = 149131013,    // ���͸��Լ�����Ϣɾ�� TransIDʧ��
    IVS_CMU_SET_SCHEDUE_MODE_FAIL          = 149131014,    // ���Ƶ���ʧ����Ϣ������
    IVS_CMU_CREATE_SESSION_ERROR           = 149131015,    // �����Ựʧ��
    IVS_CMU_REMOVE_WAIT_IMPORT_DATA_FLAG_ERROR = 149131016,// ɾ�������ر�־�ļ�ʧ��;
    IVS_CMU_IMPORT_NVR_DATA_ERROR          = 149131018,    // ���������齨��Ⱥʧ��
    IVS_CMU_NOT_LEADER_ERROR               = 149131019,    // ��Leader��ҵ���͸���leader�ڵ��ʱ��
    IVS_CMU_TOO_LARGE_MEMORY               = 149131020,    // �ڴ�ռ�ÿռ����
    
    IVS_CMU_FCG_CODE_EXIST                 = 149132000,    // �������ر����Ѵ���
    IVS_CMU_FCG_IP_EXIST                   = 149132001,    // ��������IP�Ѵ���
    IVS_CMU_NODE_HAS_BEEN_CG               = 149132002,    // ��Ⱥ��Ա�Ѿ������óɸ�������
    IVS_CMU_FCG_EXCEED_MAX                 = 149132003,    // �������ص������Ѿ��ﵽ���ֵ
    IVS_CMU_CG_NODE_NOT_EXIST              = 149132004,    // �ڵ㲻����
    
     /******************************************
     *   OMU�����붨�壨ģ����룺15��
     *******************************************/
    IVS_OMU_FILE_NOT_FOUND                 = 159100000,    // OMU �ļ��Ҳ���
    IVS_OMU_PIPE_CREATION_FAILED           = 159100001,    // OMU �ܵ�����ʧ��
    IVS_OMU_FORK_ERROR                     = 159100002,    // OMU �����ӽ���ʧ��
    IVS_OMU_FILE_RENAME_ERROR              = 159100003,    // �ļ�������ʧ��
    //IVS_OMU_POINTER_ERROR                = 159100004,    // ��ָ�����
    //IVS_OMU_STRING_PARSE_ERROR           = 159100005,    // �ַ�����������
    IVS_OMU_FILE_EXIST_ERROR               = 159100016,    // �ϴ��ļ��Ѵ���
    //// ����:15+91+00(����)+���;
    //   IVS_OMU_CMD_ERROR                     = 159100000,    // ����Ƿ�;
    //   IVS_OMU_CMD_NULL                      = 159100001,    // ����Ϊ��;
    //   IVS_OMU_DECODE_ERROR                  = 159100002,    // ������Ϣ���������;
    //   IVS_OMU_MSGBLOCK_NULL                 = 159100003,    // ������Ϣ��Ϊ��;
    //   IVS_OMU_XML_PARSE_ERROR               = 159100004,    // XML��������;
    //   IVS_OMU_XML_PARAM_ERROR               = 159100005,    // XML��������;
    IVS_OMU_ROUTE_MSG_ERROR                = 159100006,    // ��Ϣ·��ʧ��;
    //IVS_OMU_MSG_NOTIFY_FAIL              = 159100007,    // ֪ͨ����ģ��ʧ��
    IVS_OMU_SESSION_TIME_OUT               = 159100008,    // session��ʱ;
    //IVS_OMU_NOTICE_FAIL_ERROR            = 159100009,    // OMU֪ͨ����ģ��ʧ��;
    // �豸����:15+91+01(�豸����)+���;
    IVS_OMU_NODE_OFFLINE                   = 159101001,    // �ڵ�����;
    IVS_OMU_MODULE_CFG_NOT_FOUND           = 159101005,    // OMU ģ�����ò�����
    IVS_OMU_MODULE_CMD_NOT_FOUND           = 159101006,    // OMU ģ��ָ�����
    IVS_OMU_MODULE_OPER_LIST_NOT_FOUND     = 159101007,    // OMU Ԫ������Ϊ��
    IVS_OMU_NOT_DOWN_DOMAIN                = 159101008,    // ��ǰ����������޷��齨��Ⱥ;
    IVS_OMU_HAS_NO_LICENSE                 = 159101009,    // ����Ȩ��ɣ������齨��Ⱥ

    IVS_OMU_NOT_SINGLE_MODE                = 159101010,    // ���ǵ���ģʽ���޷��л�
    IVS_OMU_CREATE_CLUSTER_PCG_ONLINE      = 159101011,    // VCN5X0 PCG����ʱ�����齨��Ⱥ

    IVS_OMU_MSG_TRACE_REPORT_FAIL          = 159147001,    // �����Ϣ���ٽ�����ϱ�����ʧ��;

    IVS_OMU_REGISTER_PWD_INVALID           = 159103001,    // OMU ע���������
    IVS_OMU_RE_REGISTER_INVALID            = 159103002,    // �������Լ����Լ�ע��
    IVS_OMU_REGISTER_LOOP_ERR              = 159103003,    // ע����ڻ�·��������ע��
    IVS_OMU_REGISTER_RULE_ERR              = 159103004,    // ע�᲻���Ϲ���
    IVS_OMU_MAX_MPU_COUNT_ERR              = 159103006,    // MPU�ﵽ�������
    IVS_OMU_MAX_VMU_COUNT_ERR              = 159103007,    // VMU�ﵽ�������
    IVS_OMU_MAX_PAS_COUNT_ERR              = 159103008,    // PAS�ﵽ�������
    IVS_OMU_NO_ACCEPT_NEW_NODE             = 159103009,    // ���������豸ע��
    IVS_OMU_CLUSTER_NOT_ALLOW_SUB_DOMAIN   = 159103010,    // ��Ⱥ�²�����Խ�����
    IVS_OMU_REPORT_PWD_ERR                 = 159103011,    // �����ѯ�������
    IVS_OMU_CLUSTER_SERVER_MUMBER_ERR      = 159103012,    // �齨��Ⱥserver��������
    IVS_OMU_CLUSTER_MUMBER_ERR             = 159103013,    // �齨��Ⱥ��NVR��������
    IVS_OMU_CLUSTER_SUBNODE_SUPPORT_ERR    = 159103014,    // �齨��Ⱥ,��Ӱ汾��֧��R2��Ⱥ
    IVS_OMU_CLUSTER_SUBNODE_SYSTIME_ERR    = 159103015,    // �齨��Ⱥ,��Ⱥ��Աϵͳʱ�����һ��������
    IVS_OMU_CLUSTER_ADDNODE_SYSTIME_ERR    = 159103016,    // ��Ӽ�Ⱥ��Ա������ӳ�Ա�뼯Ⱥʱ�����һ��������
    IVS_OMU_CLUSTER_ADDNODE_IP_ERR         = 159103017,    // ��Ӽ�Ⱥ��Աʧ�ܣ���ӳ�ԱIP ��ͬ����IP
    IVS_OMU_CLUSTER_RECREATE_ERR           = 159103018,    // ��Ⱥ����������м�Ⱥ���ڽ�������

    IVS_OMU_PORTAL_RESP_SUCCESS            = 159102001,    // ��¼�ɹ�
    IVS_OMU_PORTAL_PASSWD_WRONG            = 159102002,    // �û������������
    IVS_OMU_PORTAL_RESP_DB_ERROR           = 159102003,    // ���ݿ����
    IVS_OMU_PORTAL_RESP_XMLPRASE_ERROR     = 159102004,    // xml����ʧ��
    IVS_OMU_PORTAL_USER_LOCKED             = 159102005,    // �û�����
    IVS_OMU_PORTAL_RESP_SUCCESS_FIRST      = 159102006,    // ��ʼ��¼�ɹ�
    IVS_OMU_CAN_NOT_ADD_NVR_ERROR          = 159102007,    // ��������NVR
    IVS_OMU_CAN_NOT_ADD_I_ERROR            = 159102008,    // ����NVR�������Լ�

    IVS_OMU_CAN_NOT_READ_CFG_ERROR         = 159102009,    // �����������ļ���ȡʧ��

    IVS_OMU_PORTAL_PASS_TIMEOUT            = 159102010,    // ǿ���������

    IVS_OMU_VERSION_EXIST_ERR              = 159104001,    // �汾�ļ��Ѵ��ڴ���

    IVS_OMU_DIST_MONT_ISRUNNING            = 159128001,    // ���̹������ڻ�����

    IVS_OMU_CHANGE_NODE_TYPE_ERR           = 159129001,    // �����ϼ����¼�OMU��������ı�ڵ�����
    IVS_OMU_CHANGE_NODE_TYPE_MDU_ERR       = 159129002,    // ��ǰ���Ͳ������л�ת��ģʽ
    IVS_OMU_CHANGE_NODE_TYPE_MDU_SELF_ERR  = 159129003,    // ��ǰ����δ�������
    IVS_OMU_CHANGE_NODE_TYPE_CHANGING_ERR  = 159129004,    //�����л�

    IVS_OMU_PCG_OFF_LINE_ERR               = 159130001,    // PCG����
    IVS_OMU_MAUS_OFF_LINE_ERR              = 159130002,    // MAUS����
    IVS_OMU_HTTPS_OFF_LINE_ERR             = 159130003,    // HTTPS����

    IVS_OMU_IS_SUBDOMAIN_ERR               = 159140001,    // ����ӣ�������ı�IP
    IVS_OMU_IP_CONFIGING_ERR               = 159140002,    // IP��ַ�޸��У��������ٴ��޸�

    IVS_OMU_FAULT_RUNNING                  = 159140003,    //�����ռ���������
    IVS_OMU_NOT_SUPPORT_CLUSTER            = 159140004,    //��֧�ּ�Ⱥ
    IVS_OMU_QD_HAVE_LICENCE                = 159140005,    //QD��licence
    IVS_OMU_QD_HAVE_NO_LICENCE             = 159140006,    //QDû��licence
    IVS_OMU_FAIL_FOR_WITH_SLAVE            = 159140007,    //����Ӳ������е���
    IVS_OMU_WEAK_PASSWD                    = 159140008,    //������
    IVS_OMU_CLOSE_DOMAIN_BT_NTP            = 159140010,    //����ntp��ʱ�����ȹر�ȫ��ntp
    IVS_OMU_STOP_MU_FIRST                  = 159140011,    //ֹͣsmartdata��ʱ����ֹͣmu
    IVS_OMU_RECORD_PLAN_PART_SUCCESS       = 159140012,    //���¼��ƻ�ִ���ʣ�������Ӳ�ѯʧ��
    IVS_OMU_IP_LOCKED                      = 159140013,    //�������̫�࣬������IP
    IVS_OMU_CLUSTER_RESTORE_MGR_DATA_FAIL  = 159140014,    //��ԭ�������ݿ�ʧ��
    IVS_OMU_LICE_DISABLE_ALREADY           = 159140015,    //licence�Ѿ�ʧЧ
    IVS_OMU_NO_HALICE                      = 159140016,    //û��˫��licence
    IVS_OMU_EXCEED_MAX_FORM_NUM            = 159140017,    //���������¼���������Ŀ20����
    IVS_OMU_STOP_IMGU_FIRST                = 159140018,    //ֹͣsmartdata��ʱ����ֹͣimgu
    IVS_OMU_SAFEVIDEO_DISK_CAPACITY_ERR    = 159140019,    //raid���ݴ���������ƥ��
    IVS_OMU_NTP_VALUE_ERROR                = 159140020,    //portal�·�������ʱʱ�����쳣
    
    IVS_OMU_LICENSE_PRODUCT_MISMATCH       = 159140021,    // License����Product��ƥ��
    IVS_OMU_LICENSE_OUT_OF_DATE            = 159140022,    //License �ļ�����
    IVS_OMU_LICENSE_FILEFORMAT_ERROR       = 159140023,    //License ��ʽ�ƻ�
    IVS_OMU_LICENSE_ESN_MISMATCH           = 159140024,    //License ����ESN �Ų�ƥ��
    IVS_OMU_LICENSE_VERSION_MISMATCH       = 159140025,    //License ����Version �Ų�ƥ��
    
    IVS_OMU_RAID_ABNORMAL                  = 159150010,    // RAID״̬�쳣
    /* ���̹������*/
    IVS_OMU_DISK_MANAGE_NOFREE             =   159150001, 
    IVS_OMU_DISK_MANAGE_LESS_THEN_THREE    =   159150002, 
    IVS_OMU_DISK_MANAGE_INTERFACE_RETURN_ERROR  =   159150003, 
    IVS_OMU_DISK_MANAGE_FIGURE_ERROR       =   159150004, 
    IVS_OMU_DISK_MANAGE_CHANGING_ERR       = 159150005,    //�������������л���ϵͳ�̳�ʼ��������raid�顢raid��ɢ�̡�ɢ����raid��
    IVS_OMU_DISK_MANAGE_DISK_CAPACITY_ERROR= 159150006,    //����������ƥ��
    IVS_OMU_DISK_TEMPERATURE_HIGH_ERROR    = 159150007,    //�����¶ȹ��ߣ�����raidʧ��
    IVS_OMU_DISK_FAILURE_DISK_ERROR        = 159150008,    //�й�����
    IVS_OMU_DISK_MAX_SUPPORT_NUM_ERROR     = 159150009,    //��������raid�����֧�ֳ�Ա���� 24

    //Begin Added for ([VCN�ƻ�����]) 2017-8-26{
    IVS_OMU_APPLY_OUTER_IP_ERROR           = 159150008,    //��ȡ�ⲿIP��ַʧ��
    IVS_OMU_WAIT_UPDATE_OUTER_IP           = 159150009,    //�ȴ���ȡ����IP
    IVS_OMU_WATI_OM_BUILD_HACS             = 159150010,    //�ȴ�OM˫���齨
    IVS_OMU_WAIT_NODE_BUILD_HACS           = 159150011,    //�ȴ�ģ��˫���齨
    IVS_OMU_WAIT_SINGLE_TO_DOMAIN_MASTER   = 159150012,    //�ȴ�����������
    IVS_OMU_WAIT_SINGLE_TO_DOMAIN_SLAVE    = 159150013,    //�ȴ����������
    IVS_OMU_WAIT_OTHER_NODE_ONLINE         = 159150014,    //�ȴ������ڵ�����
    //End Added for ([VCN�ƻ�����]), 2017-8-26}
    IVS_OMU_RAID_CHECK_ERROR               = 159150015,     //RAID���ʧ��

    //GSDB&ZK��������-����У��ʧ��ԭ��ֵ����
    IVS_BMA_GSDB_ZK_PWD_CHK_USER_NAME_ERR           = 159150020, //У��ʧ��,���벻�ܰ����û������û����ĵ���
    IVS_BMA_GSDB_ZK_PWD_CHK_CHARACTER_TYPE_ERR      = 159150021, //У��ʧ��,�������ٰ���һ����д��ĸ(A-Z)��һ��Сд��ĸ(a-z)��һ�������ַ�(0-9)
    IVS_BMA_GSDB_ZK_PWD_CHK_LENGTH_ERR              = 159150022, //У��ʧ��,�������ٰ���10���ַ�������32���ַ�
    IVS_BMA_GSDB_ZK_PWD_CHK_SPECIAL_CHARATER_ERR    = 159150023, //У��ʧ��,�������ٰ���һ�������ַ�
    IVS_BMA_GSDB_ZK_PWD_CHK_CONTINUOUS_CHARATER_ERR = 159150024, //У��ʧ��,������ͬһ�ַ������������ֳ���2��
    IVS_BMA_GSDB_ZK_PWD_CHK_USED_BEFORE_ERR         = 159150025, //У��ʧ��,���벻���������3����ʷ�����ظ�
    IVS_BMA_GSDB_ZK_PWD_CHK_LESS_THAN_5MIN_ERR      = 159150026, //У��ʧ��,�����޸ĵ�ʱ������������5����
    IVS_BMA_GSDB_ZK_PWD_CHK_FAIL                    = 159150027, //У��ʧ��,�ڲ�����

    /**********************************************
    *   MU�����붨�壨ģ����룺16��
    ***********************************************/
    /* MU:bsm���ش����룬ȡֵ��Χ��169100001 ~ 169100100,errcode = IVS_MU_ERR_CODE + BSM_ERR_CODE*/
    IVS_MU_ERR_CODE_BEGIN                  = 169100001,    // BSM��������ʼֵ
    IVS_MU_EXIST_AUDIO                     = 169100044,    // ��Ƶͨ���ѱ�ʹ��
    IVS_MU_RESTOR_XFS_FAILED               = 169100045,    // �ָ�xfs�ļ�ϵͳʧ��
    IVS_MU_KEY_FILE_OPERATER_FAILED        = 169100046,    // �ؼ��ļ�����ʧ��
    IVS_MU_ERROR_BLOCK_STATUS              = 169100047,    // ��״̬����.
    IVS_MU_ERROR_INVALID_BLOCK             = 169100048,    // ��Ч���
    IVS_MU_DEVICE_STATUS_ERROR             = 169100049,    // �洢�豸״̬����ȷ
    IVS_MU_NEED_REBOOT_SYSTEM              = 169100050,    // ��Ҫ����������
    IVS_MU_DEVICE_EXISTS                   = 169100051,    // �豸�Ѵ���
    IVS_MU_UNKNOWN_FILE_SYSTEM             = 169100052,
    IVS_MU_MOUNT_ERROR                     = 169100053,    // bsm ������ʧ��
    IVS_MU_INVALID_PARAMETER               = 169100054,    // ��Ч���������
    IVS_MU_SCAN_SLOT_FAILED                = 169100055,    // BSMɨ���λ����
    IVS_MU_RAID_FAILED                     = 169100056,    // RAIDģ��δ����
    IVS_MU_SLEEPWAKEUPFAILED               = 169100057,    // ����ʧ��
    IVS_MU_RAIDREBUILDING                  = 169100058,    // raid �ع���
    IVS_MU_DB_DUP_ERROR                    = 169100059,    // ���ݿ�������ͻ
    IVS_MU_STREAM_PACKET_LEN_FAIL          = 169100060,    // ��Ƶ����֡������Ч
    IVS_MU_INVALID_DISKNUM                 = 169100061,    // ��Ч���̺�
    IVS_MU_LOCK_OTHER_ERROR                = 169100062,    // ������ʧ��
    IVS_MU_SAVE_INDEX_FAILED               = 169100063,    // ��������ʧ��
    IVS_MU_DISK_FAILED                     = 169100064,    // ���̴���(����ʧЧ)
    IVS_MU_NO_ENOUGH_RESERVESPACE          = 169100065,    // û���㹻��Ԥ���ռ�
    IVS_MU_INDEX_OUTDATED                  = 169100066,    // �Ѿ�ѭ�����ǵ�����
    IVS_MU_INDEX_UNFOUND                   = 169100067,    // save session��ѯ����ʧ��
    IVS_MU_DB_NO_DATA                      = 169100068,    // ���ݿ���û���������
    IVS_MU_DB_EXCEPTION                    = 169100069,    // ���ݿ�����쳣
    IVS_MU_INIT_DB_POLL_FAILED             = 169100070,    // ��ʼ���������ӳ�ʧ��
    IVS_MU_DELETE_DB_BLOCKINFO_ERROR       = 169100071,    // ɾ�������п���Ϣʧ��
    IVS_MU_OPERATING_RECLAIMED_IPC         = 169100072,    // ��ͼ������ɾ��������ͷ
    IVS_MU_LOCK_MULTI_LOCK                 = 169100073,    // ��ͼ��������ǵݹ���
    IVS_MU_LOCK_RECURSIVE_EXCEED           = 169100074,    // �̵߳ݹ����Ѿ��������ݹ�������
    IVS_MU_LOCK_NOT_INIT_OK                = 169100075,    // �̻߳�����û�г�ʼ��
    IVS_MU_TOO_LARGE_DATA_SIZE             = 169100076,    // ͼƬ�ߴ糬��1M, ����BSMԤ����1M
    IVS_MU_INVALID_ID                      = 169100077,    // ��Ч����ͷID
    IVS_MU_CREATE_FOLDER_FAILED            = 169100078,    // �����ļ���ʧ��
    IVS_MU_WRONG_SESSION_TYPE              = 169100079,    // ��Ҫ��Ĳ����͵�ǰ�Ự���Ͳ�ƥ��
    IVS_MU_INVALID_SESSION_ID              = 169100080,    // ��Ч�ĻỰID
    IVS_MU_INVALID_SESSION_TYPE            = 169100081,    // ��Ч�ĻỰ����
    IVS_MU_INVALID_POINTER                 = 169100082,    // ��Чָ��
    IVS_MU_NEW_FAILED                      = 169100083,    // new����ʧ��
    IVS_MU_NO_BLOCK                        = 169100084,    // Spaces�޷��������ݿ�
    IVS_MU_NO_PHOTO_DATA                   = 169100085,    // û�����ͼƬ����
    IVS_MU_INVALID_TIME                    = 169100086,    // ��Чʱ��
    IVS_MU_PHOTO_RTTI_ERROR                = 169100087,    // �洢ͼƬУ���־
    IVS_MU_END_FLAG_ERROR                  = 169100088,    // �洢�ռ�β��־����
    IVS_MU_START_FLAG_ERROR                = 169100089,    // �洢�ռ�ͷ��־����
    IVS_MU_INVALID_SIZE                    = 169100090,    // ��Ч����
    IVS_MU_BUFFER_NOT_ENOUGH               = 169100091,    // ����ռ䲻��
    IVS_MU_UNKNOW_EXCEPTION                = 169100092,    // δ֪�쳣
    IVS_MU_ISTREAM_CREATE_FAILED           = 169100093,    // ��������������
    IVS_MU_OSTREAM_CREATE_FAILED           = 169100094,    // �������������
    IVS_MU_SEEK_FAILED                     = 169100095,    // �ļ���λ����
    IVS_MU_OPEN_FAILED                     = 169100096,    // �򿪴洢�ļ�����
    IVS_MU_READ_FAILED                     = 169100097,    // �����̴���
    IVS_MU_WRITE_FAILED                    = 169100098,    // д���̴���

    IVS_MU_ERR_CODE                        = 169100100,    // BSM��������ʼֵ

    IVS_MU_RECORD_SEARCH_INDEX_ERROR       = 169100200,    // ¼�������������
    IVS_MU_FROM_TO_TIME_ERROR              = 169100201,    // ¼�������ʼ����ʱ�����
    IVS_MU_TIME_FORMAT_ERROR               = 169100202,    // ¼�����ʱ���ʽ����
    IVS_MU_RECORD_METHOD_ERROR             = 169100203,    // ¼�������ʽ����
    IVS_MU_CAMERA_CODE_ERROR               = 169100204,    // ¼�����������������
    IVS_MU_RECORD_SEARCH_NSS_ERROR         = 169100205,    // ¼�����NSS��Ϣ����
    IVS_MU_REPORT_DISK_RATE_ERROR          = 169100206,    // ��ѯ������Ϣʧ�ܴ���

    IVS_MU_MBU_OVERLOAD                    = 169100300,    // mbu�Ѿ�����
    IVS_MU_NOTENOUGH_BANDWIDTH             = 169100301,    //ý�������������

    IVS_MU_NOTENOUGH_CPU_DILE              = 169100302,    //CPU��Դ����90%
    
    IVS_MU_NO_ORI_IPC                      = 169100400,    //ԭʼ�豸�����ڻ��߱�ɾ��
    IVS_MU_PLAN_TYPE_DIFF                  = 169100401,    //ɾ���豸ʱ���ƻ����Ͳ�һ��
    IVS_MU_LOCK_ID_NOT_EXIST               = 169100402,    //������¼������
    IVS_MU_LOCK_TIME_NO_RECORD             = 169100403,    //����ʱ����û��¼��
    IVS_MU_NO_LOCK_SPACE                   = 169100404,    //�����ռ䳬����
    IVS_MU_LOCK_NUMS_OVER_LIMIT            = 169100405,    //������¼��������


    IVS_MU_BOOKMARK_ADD_ERROR            = 169100406,    //�޷������ǩ
    /******************************************
    *   SafeVideo�����붨�壨ģ����룺17��
    *******************************************/

    /******************************************
    *   DCG�����붨�壨ģ����룺18��
    *******************************************/
    //DCG:¼��ƻ����� ������ ���ܱ���-25
    IVS_DCG_SET_RECORD_ERROR              = 189125001,     // ����¼��ƻ�����
    IVS_DCG_GET_RECORD_ERROR              = 189125002,     // ��ȡ¼��ƻ�����
    IVS_DCG_SET_LAYER_CODE_ERROR          = 189125003,     // �ֲ�������ô���
    IVS_DCG_RECORD_PLAN_NOT_EXIST         = 189125004,     // ¼��ƻ�Ϊ��
    IVS_DCG_CREATE_RECORD_STREAM_SMP_ERROR= 189125005,     // ����¼�����������
    //DCG:�ƾ����� ������ ���ܱ���-16
    IVS_DCG_CONTROL_PTZ_ERROR             = 189116001,     // ��̨���ƴ���
    IVS_DCG_GET_PTZ_PARAM_ERROR           = 189116002,     // ��ȡ��̨��������
    IVS_DCG_SET_PTZ_PARAM_ERROR           = 189116003,     // ������̨��������
    IVS_DCG_GET_PTZ_PROTOCOL_ERROR        = 189116004,     // ��ȡ��̨������Э�����
    IVS_DCG_GET_CRUISE_TRACK_ERROR        = 189116005,     // ��ȡѲ���켣��������
    IVS_DCG_SET_CRUISE_TRACK_ERROR        = 189116006,     // ����Ѳ���켣��������
    IVS_DCG_CLEAL_CRUISE_TRACK_ERROR      = 189116007,     // ���Ѳ���б����
    IVS_DCG_TRACK_COMMAND_ERROR           = 189116008,     // ��̨PTZ�켣����ʧ��
    IVS_DCG_CRUISE_NUMBER_ERROR           = 189116009,     // ���õ�Ѳ���켣��ų����豸֧�ַ�Χ
    IVS_DCG_UNSUPPORT_PTZ_CMD             = 189116010,     // ��֧�ֵ���̨��������
    IVS_DCG_TRACK_INDEX_ERROR             = 189116011,     // ���õ�PTZ¼�ƹ켣��ų����豸֧�ַ�Χ
    IVS_DCG_GET_ABS_POSITION_ERROR        = 189116012,     // ��ȡ��̨�������
    IVS_DCG_CUISE_NAME_TOO_LONG           = 189116013,     // ����Ѳ���켣���Ƴ���
    IVS_DCG_SET_LINK_AGE_SWITCH_ERROR     = 189116014,     // ����ǹ���������ٲ�������
    IVS_DCG_SET_MANUAL_POS_SWITCH_ERROR   = 189116015,     // ����ǹ�������ֶ���λ��������
    IVS_DCG_LINKAGE_LOCATE_ERROR          = 189116016,     //����ǹ�����ֶ���λ����
    IVS_DCG_LINKAGE_TRACK_ERROR           = 189116017,     //����ǹ�����ֶ����ٴ���


    //DCG:Ԥ��λ,����λ���� ������ ���ܱ���-17
    IVS_DCG_SET_PRESET_ERROR              = 189117001,     // ����Ԥ��λ��������
    IVS_DCG_GET_PRESET_ERROR              = 189117002,     // ��ѯԤ��λ��������
    IVS_DCG_DEL_PRESET_ERROR              = 189117003,     // ɾ��Ԥ��λ��������
    IVS_DCG_SET_GUARD_ERROR               = 189117004,     // ���ÿ���λ�������
    IVS_DCG_GET_GUARD_ERROR               = 189117005,     // ��ѯ����λ�������
    IVS_DCG_CANNOT_OVERITE_HOME_POSITION  = 189117006,     // ��ǰλ�ÿ���Ϊ����Ԥ��λ���������óɿ���λ
    IVS_DCG_CANNOT_SET_HOME_POS_WHILE_PTZ_MOVING  = 189117007,     // ptz����ת��,�������ÿ���λ
    IVS_DCG_PRESET_NAME_TOO_LONG          = 189117008,      //����Ԥ��λ���Ƴ���
    IVS_DCG_CREAT_PRESETTOUR_NOT_ENOUGH_SPACE = 189117009,      //Ѳ���켣����������(TooManyPresetTours)	 

    //DCG:�澯���� ������ ���ܱ���-20
    IVS_DCG_SET_ALARM_GUARD_ERROR         = 189120001,     // ���ø澯����������
    IVS_DCG_GET_ALARM_GUARD_ERROR         = 189120002,     // ��ȡ��ͷ��������������
    IVS_DCG_MAIN_DEV_ALARM_GUARD_ERROR    = 189120003,     // ���豸�澯��������
    IVS_DCG_MAIN_DEV_ALARM_UNGUARD_ERROR  = 189120004,     // ���豸�澯��������
    IVS_DCG_MAIN_DEV_SET_ALARM_CALLBACK_ERROR = 189120005, // ���豸���ø澯�ص�����
    IVS_DCG_SET_VIDEO_MASK_ERROR          = 189120006,     // ������˽�����������
    IVS_DCG_GET_VIDEO_MASK_ERROR          = 189120007,     // ��ѯ��˽�����������
    IVS_DCG_SET_MOTION_DETECTION_ERROR    = 189120008,     // �����ƶ�����������
    IVS_DCG_GET_MOTION_DETECTION_ERROR    = 189120009,     // ��ѯ�ƶ�����������
    IVS_DCG_SET_MASK_PROTECT_ERROR        = 189120010,     // ������Ƶ�ڸ��������
    IVS_DCG_GET_MASK_PROTECT_ERROR        = 189120011,     // ��ѯ��Ƶ�ڸ��������
    IVS_DCG_SET_IGT_COMMEM_PARA_ERROR     = 189120012,     // �������ܷ���������������
    IVS_DCG_SET_IGT_TRIPWIRE_PARA_ERROR   = 189120013,     // �������ܷ������߹����������
    IVS_DCG_SET_IGT_INTRUSION_PARA_ERROR  = 189120014,     // �������ܷ������ּ���������
    IVS_DCG_SET_IGT_HOVER_PARA_ERROR      = 189120015,     // �������ܷ����ǻ�����������
    IVS_DCG_SET_IGT_LEGACY_PARA_ERROR     = 189120016,     // �������ܷ�����������������
    IVS_DCG_SET_IGT_REMOVE_PARA_ERROR     = 189120017,     // �������ܷ������߼���������
    IVS_DCG_GET_IGT_COMMEM_PARA_ERROR     = 189120018,     // ��ȡ���ܷ���������������
    IVS_DCG_GET_IGT_TRIPWIRE_PARA_ERROR   = 189120019,     // ��ȡ���ܷ������߹����������
    IVS_DCG_GET_IGT_INTRUSION_PARA_ERROR  = 189120020,     // ��ȡ���ܷ������ּ���������
    IVS_DCG_GET_IGT_HOVER_PARA_ERROR      = 189120021,     // ��ȡ���ܷ����ǻ�����������
    IVS_DCG_GET_IGT_LEGACY_PARA_ERROR     = 189120022,     // ��ȡ���ܷ�����������������
    IVS_DCG_GET_IGT_REMOVE_PARA_ERROR     = 189120023,     // ��ȡ���ܷ������߼���������
    IVS_DCG_SET_ALARM_LINK_PARAM_ERROR    = 189120024,     // ���ø澯�������Բ�������
    IVS_DCG_ALARM_LINK_CANT_FIND_CHANNEL  = 189120025,     // ����ͷ�����Ҳ�����Ӧ��ͨ��
    IVS_DCG_SET_ANALYTICS_ERROR           = 189120026,     // �������ܷ�������
    IVS_DCG_ANALYTICS_UNSUPPORT           = 189120027,     // ���豸���ܷ�����֧��ƽ̨���ã��뵽WEBҳ������
    IVS_DCG_SET_AUDIO_ALARM_PARAM_ERROR   = 189120028,     // ������Ƶ�澯����ʧ��
    IVS_DCG_GET_AUDIO_ALARM_PARAM_ERROR   = 189120029,

    //DCG:�豸���� ������ ���ܱ���-08
    IVS_DCG_FIND_MAIN_DEV_EXIST           = 189108001,     // �������豸�Ѿ�����
    IVS_DCG_ADD_MAIN_DEV_ERROR            = 189108002,     // ������豸����
    IVS_DCG_LOAD_PLUGIN_ERROR             = 189108003,     // �����豸�������
    IVS_DCG_GET_DEV_PORT_ERROR            = 189108004,     // ��ȡ�豸�˿ڴ���
    IVS_DCG_FIND_MAIN_DEV_ERROR           = 189108005,     // �������豸������
    IVS_DCG_DEL_SUB_DEV_ERROR             = 189108006,     // ɾ�����豸����
    IVS_DCG_DEL_MAIN_DEV_ERROR            = 189108007,     // ɾ�����豸����
    IVS_DCG_REBOOT_MAIN_DEV_ERROR         = 189108008,     // �������豸����
    IVS_DCG_OPEN_DLL_ERROR                = 189108009,     // Open��̬�����
    IVS_DCG_SYMBOL_DLL_ERROR              = 189108010,     // ��̬��symbol����
    IVS_DCG_CREATE_SDK_DLL_ERROR          = 189108011,     // ��̬��CreateSdk����
    IVS_DCG_SDK_INIT_ERROR                = 189108012,     // Sdk��ʼ������
    IVS_DCG_DEV_LOGIN_ERROR               = 189108013,     // ���豸��¼����
    IVS_DCG_DEV_LOGIN_PASSWORD_ERROR      = 189108014,     // ���豸��¼�������
    IVS_DCG_DEV_GET_ABILITY_ERROR         = 189108015,     // ���豸��ȡ�豸��������
    IVS_DCG_DEV_SDK_INIT_ERROR            = 189108016,     // ��ʼ���豸SDK����
    IVS_DCG_CREATE_LENS_ERROR             = 189108017,     // ������ͷʧ��
    IVS_DCG_GET_TIME_PARAM_ERROR          = 189108018,     // ��ȡʱ�����ʧ��
    IVS_DCG_SET_TIME_PARAM_ERROR          = 189108019,     // ����ʱ�����ʧ��
    IVS_DCG_GET_NET_PARAM_ERROR           = 189108020,     // ��ȡ�������ʧ��
    IVS_DCG_SET_NET_PARAM_ERROR           = 189108021,     // �����������ʧ��
    IVS_DCG_BIND_TRANSID_AND_SEARCHD_DEV_TASK_ERROR    = 189108022, //������ID������豸ҵ��ʧ��
    IVS_DCG_UNBIND_TRANSID_AND_SEARCHD_DEV_TASK_ERROR  = 189108023, //�������ID������豸ҵ���ʧ��
    IVS_DCG_SEARCH_DEVICE_ERROR           = 189108024,     // �����豸ʧ��
    IVS_DCG_CAN_NOT_FIND_SERACHDEVTASK    = 189108025,     // ���Ҳ��������豸������
    IVS_DCG_STOP_SEARCH_DEVICE_ERROR      = 189108026,     // ֹͣ�����豸ʧ��
    IVS_DCG_CREATE_VENDER_DEV_ERROR       = 189108027,     // ����������豸ʧ��
    IVS_DCG_UN_SUPPORT_PROTOCOL           = 189108028,     // ��֧�ֵ�Э������
    IVS_DCG_VERSION_NO_MATCH              = 189108029,     // SDK���豸�汾��ƥ��(�������SDK)
    IVS_DCG_DEV_DISCOVERY_RUNNING         = 189108030,     // �豸�Զ����ַ����Ѿ�������
    IVS_DCG_VENDOR_DEV_INVALID            = 189108031,     // ���豸�����Ч
    IVS_DCG_DEV_LOGIN_HANDLE_INVALID      = 189108032,     // �豸��¼�����Ч
    IVS_DCG_DEV_UN_SUPPORT                = 189108033,     // �豸��֧��
    IVS_DCG_DEV_UPDATE_ERROR              = 189108034,     // �豸����ʧ��
    IVS_DCG_UNAUTHORIZED                  = 189108035,     // δ��Ȩ
    IVS_DCG_HTTP_DIGEST_AUTHORIZE_ERROR   = 189108036,     // Http-Digest��Ȩ����
    IVS_DCG_WSSE_AUTHORIZE_ERROR          = 189108037,     // WSSE��Ȩ����
    IVS_DCG_ONVIF_SOAP_OBJECT_INVALID     = 189108038,     // SOAP������Ч
    IVS_DCG_ONVIF_SOAP_OPER_FAIL          = 189108039,     // SOAP����ʧ��
    IVS_DCG_REGIST_EVENT_CALL_BACK_ERROR  = 189108040,     // sdkע��ǰ���쳣�ص�����
    IVS_DCG_ONVIF_APP_OBJECT_INVALID      = 189108041,     // ONVIF App������Ч
    IVS_DCG_FIND_SUB_DEV_EXIST            = 189108042,     // �������豸�Ѿ�����
    IVS_DCG_HTTP_NOT_IMPLEMENTED          = 189108043,     // HTTP����501����
    IVS_DCG_SET_CONFIG_FILE_ERROR         = 189108044,     // ���������ļ�����
    IVS_DCG_GET_CONFIG_FILE_ERROR         = 189108045,     // ��ȡ�����ļ�����
    IVS_DCG_ONVIF_NO_CONF                 = 189108046,     // ONVIF�����������Ϣ
    IVS_DCG_MAIN_DEV_REBOOTING            = 189108047,     // ���豸������
    IVS_DCG_DEV_LOGIN_USER_LOCKED         = 189108048,     // ���豸��¼����
    IVS_DCG_TIMEZONE_SHIFT_INVALID        = 189108049,     // ʱ��ƫ�������Ϸ�
    IVS_DCG_FRAMERATE_INVALID             = 189108050,     // ֡�ʲ��Ϸ�
    IVS_DCG_BITRATE_INVALID               = 189108051,     // ���ʲ��Ϸ�
    IVS_DCG_RESOLUTION_INVALID            = 189108052,     // �ֱ��ʲ��Ϸ�
    IVS_DCG_PROFILE_INVALID               = 189108053,     // profile���Ϸ�
    IVS_DCG_IFRAMEINTERVAL_INVALID        = 189108054,     // I֡������Ϸ�
    IVS_DCG_PU_LOG_NOT_FOUND              = 189108055,     // ǰ����־δ�ҵ�
    IVS_DCG_PU_SET_VEDIO_FORMAT_ERROR     = 189108056,     // ����ǰ��PN��ʽʧ��
    IVS_DCG_HTTP_BASIC_AUTHORIZE_ERROR    = 189108057,     // Basic��Ȩ����
    IVS_DCG_SET_IPCA_PARAM_ERROR          = 189108058,     // ����IPCA����

    IVS_DCG_SET_CACHE_RECORD_ERROR        = 1891080059,    // ���û��油¼ʧ��
    IVS_DCG_GET_SDCARD_STATUS_ERROR       = 1891080060,    // ��ȡ�����SD��״̬ʧ��
    IVS_DCG_DEV_NET_CONNECT_ERROR         = 189108061,     // �������Ӵ������豸�����߻�IP���˿ڴ���
    IVS_DCG_DEV_UNREGISTER_ERROR          = 189108062,     // �豸δע��
    IVS_DCG_DEV_AUTHORIZE_ERROR           = 189108063,     // �豸��Ȩʧ��
    IVS_DCG_ENTRY_IPC_IS_OFFLINE          = 189108064,     // ���Эͬ���IPC����
    //DCG:ʵ�� ������ ���ܱ���-15
    IVS_DCG_ADD_STREAM_PARAM_ERROR        = 189115001,     // �������������������
    IVS_DCG_FIND_STREAM_PARAM_EXIST       = 189115002,     // �������������Ѿ�����
    IVS_DCG_FIND_STREAM_PARAM_ERROR       = 189115003,     // ���������������󡢲�����
    IVS_DCG_OPEN_SOCKET_ERROR             = 189115004,     // ��ʼ��socket����
    IVS_DCG_START_STREAM_ERROR            = 189115005,     // ��ʼȡ������
    IVS_DCG_TCP_OPEN_SOCKET_ERROR         = 189115006,     // TCP-socket�򿪴���
    IVS_DCG_TCP_SOCKET_CONNECT_ERROR      = 189115007,     // TCP-socket���Ӵ���
    IVS_DCG_UDP_OPEN_SOCKET_ERROR         = 189115008,     // UDP-socket�򿪴���
    IVS_DCG_STOP_REAL_STREAM_ERROR        = 189115009,     // ֹͣ������
    IVS_DCG_REQUEST_IFRAME_ERROR          = 189115010,     // ����I֡����
    IVS_DCG_STREAM_HANDLE_INVALID         = 189115011,     // �������Ч
    IVS_DCG_SEND_SIP_INVITE_ERROR         = 189115012,     // ��ǧ�����豸����sip invite����
    IVS_DCG_SIP_INVITE_RESPONSE_ERROR     = 189115013,     // ǧ�����豸�ظ�sip invite��Ӧ����
    IVS_DCG_MEDIA_BUF_WITH_RTP_INVALID    = 189115014,     // ��RTPͷ�ĺ�����������Ҫʹ�ø�ָ�룬Ϊ��ʱ����
    IVS_DCG_BIND_SERVICE_ID_AND_MU_LINK_ID_ERROR   = 189115015,   // ��ServiceID��MULinkID����
    IVS_DCG_UNBIND_SERVICE_ID_AND_MU_LINK_ID_ERROR = 189115016,   // �����ServiceID��MULinkID����
    IVS_DCG_BIND_SERVICE_ID_AND_MSGKEY_ERROR       = 189115017,   // ǧ�����������ʱ���ServiceID��MsgKey����
    IVS_DCG_UNBIND_SERVICE_ID_AND_MSGKEY_ERROR     = 189115018,   // ǧ�����������ʱ������ServiceID��MsgKey����
    IVS_DCG_BIND_SERVICE_ID_AND_SESSION_ID_ERROR   = 189115019,   // ǧ�����������ʱ���ServiceID��ǧ������Ϣ�еĻỰID����
    IVS_DCG_UNBIND_SERVICE_ID_AND_SESSION_ID_ERROR = 189115020,   // ǧ�����������ʱ������ServiceID��ǧ������Ϣ�еĻỰID����
    IVS_DCG_TRANSFER_PAYLOADTYPE_FAILED    = 189115021,     // payloadtypeת������
    IVS_DCG_STREAM_UNSTARTED               = 189115022,     // ��δ����
    IVS_DCG_SET_WATERMARK_ERROR            = 189115023,     // ����ˮӡ����
    IVS_DCG_TCP_SOCKET_ACCEPT_ERROR        = 189115024,     // TCP-SOCKET-Accept����
    IVS_DCG_TCP_SOCKET_ACCEPTOR_CLOSE_ERROR= 189115025,     // TCP-SOCKET-Acceptor close����
    IVS_DCG_REV_STREAM_REQUEST_ERROR       = 189115026,     // ���������������Ҫ��ǧ�����豸����Invt��Ϣ��ʱ�����
    IVS_DCG_UNSUPPORTED_ENCODE_MODE        = 189115028,     // ��֧�ֵı����ʽ
    IVS_DCG_UNSUPPORTED_PROFILE            = 189115029,     // ��֧�ֵ�Profile
    IVS_DCG_DECRYPT_SECURITY_ERROR         = 189115030,     // ����ʧ��
    IVS_DCG_STREAM_HAS_STOPED              = 189115031,     // ʵ������ֹͣ
    IVS_DCG_WRONG_STOPPING_STREAM_WITH_DEV = 189115032,     //�豸ͣ��ʧ��
    IVS_DCG_IS_IN_START                    = 189115033,     //����ҵ�񻹴����������ACK��
    IVS_DCG_IS_IN_STOP                     = 189115034,     //����ҵ�񻹴�����ֹͣ��
    IVS_DCG_USER_OVER_LIMIT                = 189115035,     //�û�������������

    //DCG:�������������豸          10
    IVS_DCG_GET_ALARM_IN_PARAM_ERROR      = 189110001,     // ��ȡ���������豸��������
    IVS_DCG_SET_ALARM_IN_PARAM_ERROR      = 189110002,     // ���ÿ��������豸��������

    //DCG:�豸����-������������豸  11
    IVS_DCG_GET_ALARM_OUT_PARAM_ERROR     = 189111001,     // ��ȡ���������豸��������
    IVS_DCG_SET_ALARM_OUT_PARAM_ERROR     = 189111002,     // ���ÿ��������豸��������
    IVS_DCG_GET_ALARM_OUT_STATE_ERROR     = 189111003,     // ��ȡ���������豸��������
    IVS_DCG_SET_ALARM_OUT_STATE_ERROR     = 189111004,     // ���ÿ��������豸��������

    //DCG:��������豸              09
    IVS_DCG_GET_CAMERA_STREAM_PARAM_ERROR = 189109001,     // ��ȡ�����������������
    IVS_DCG_SET_CAMERA_STREAM_PARAM_ERROR = 189109002,     // ���������������������
    IVS_DCG_GET_IMAGING_PARAM_ERROR       = 189109003,     // ��ȡ���������ͼ���������
    IVS_DCG_SET_IMAGING_PARAM_ERROR       = 189109004,     // �������������ͼ���������
    IVS_DCG_GET_VIDEO_PARAM_ERROR         = 189109005,     // ��ȡǰ����Ƶ���豸��������
    IVS_DCG_SET_VIDEO_PARAM_ERROR         = 189109006,     // ����ǰ����Ƶ���豸��������
    IVS_DCG_GET_VIDEO_EFFECT_PARAM_ERROR  = 189109007,     // ��ȡǰ����ƵЧ����������
    IVS_DCG_SET_VIDEO_EFFECT_PARAM_ERROR  = 189109008,     // ����ǰ����ƵЧ����������
    IVS_DCG_GET_VIDEO_ANALOG_FORMAT_ERROR = 189109009,     // ��ȡǰ����Ƶ��ʽ����
    IVS_DCG_SET_VIDEO_ANALOG_FORMAT_ERROR = 189109010,     // ����ǰ����Ƶ��ʽ����
    IVS_DCG_SET_OSD_ERROR                 = 189109011,     // ����OSD��������
    IVS_DCG_GET_OSD_ERROR                 = 189109012,     // ��ȡOSD��������
    IVS_DCG_GET_EXTIMAGING_PARAM_ERROR    = 189109013,     // ��ȡ�������չͼ���������
    IVS_DCG_SET_EXTIMAGING_PARAM_ERROR    = 189109014,     // �����������չͼ���������
    IVS_DCG_FIND_LENS_INVALID             = 189109015,     // δ���ҵ���������豸
    IVS_DCG_VENDOR_LENS_INVALID           = 189109016,     // ��������豸�����Ч
    IVS_DCG_SET_FEC_ERROR                 = 189109017,     // ����FEC��������
    IVS_DCG_GET_FEC_ERROR                 = 189109018,     // ��ȡFEC��������
    IVS_DCG_SET_VIDEO_ENCODE_FORMAT_ERROR = 189109019,     // ������Ƶ�����ʽ����

    IVS_DCG_SET_SEC_ERROR                 = 189109020,     // ����SEC��������
    IVS_DCG_GET_SEC_ERROR                 = 189109021,     // ��ȡSEC��������
    IVS_DCG_SET_DEVICE_CONFIG_ERROR         = 189109022,     // �����豸�������   
    IVS_DCG_GET_DEVICE_CONFIG_ERROR         = 189109023,     // ��ȡ�豸���ò�������    

    //DCG:�豸����-�������豸           12
    IVS_DCG_GET_AUDIO_PARAM_ERROR         = 189112001,     // ��ȡ��Ƶ���豸��������
    IVS_DCG_SET_AUDIO_PARAM_ERROR         = 189112002,     // ������Ƶ���豸��������

    //DCG:�豸����-�������豸           13
    IVS_DCG_GET_SERIAL_PARAM_ERROR        = 189113001,     // ��ȡ�������豸��������
    IVS_DCG_SET_SERIAL_PARAM_ERROR        = 189113002,     // ���ô������豸��������

    //DCG:�豸����-����           45
    IVS_DCG_START_VOICE_STREAM_ERROR      = 189145001,     // ��ʼ��Ƶ�Խ�����
    IVS_DCG_STOP_VOICE_STREAM_ERROR       = 189145002,     // ֹͣ��Ƶ�Խ�����
    IVS_DCG_START_REVERSE_AUDIO_THREAD_ERROR = 189145003,  // ��������CU�ͻ������������߳�ʧ��

    //DCG:��־����                  30
    IVS_DCG_SET_LOG_CONFIG_ERROR          = 189130001,     // ������־���ز�������
    IVS_DCG_GET_LOG_SFTP_CONF_ERROR       = 189130002,     // ��ȡ��־ͳһ���ô���
    IVS_DCG_SET_LOG_SFTP_CONF_ERROR       = 189130003,     // ������־ͳһ���ô���
    IVS_DCG_GET_PU_LOG_ERROR              = 189130004,     // ��ȡǰ����־ʧ��

    //DCG��ǰ��¼��   40
    IVS_DCG_START_PU_RECORD_ERROR         = 189140001,     // ����ǰ���ֶ�¼�����
    IVS_DCG_STOP_PU_RECORD_ERROR          = 189140002,     // ֹͣǰ���ֶ�¼�����
    IVS_DCG_GET_PU_RECORD_STATE_ERROR     = 189140003,     // ��ȡǰ��¼��״̬����
    IVS_DCG_GET_PU_RECORD_LIST_ERROR      = 189140004,     // ����ǰ��¼�����
    IVS_DCG_STOP_PLAYBACK_STREAM_ERROR    = 189140005,     // ֹͣǰ��¼��طŴ���
    IVS_DCG_START_PLAYBACK_STREAM_ERROR   = 189140006,     // ����ǰ��¼��طŴ���
    IVS_DCG_SET_RECORD_STREAM_ERROR       = 189140007,     // ����ǰ��¼���������ʹ���

    //DCG��¼��ط�             19
    IVS_DCG_PLAYBACK_BY_NAME_ERROR        = 189119001,     // ����¼���ļ�������
    IVS_DCG_SET_PLAYBACK_CALLBACK_ERROR   = 189119002,     // ����¼��طŻص���������
    IVS_DCG_PLAYBACK_START_PLAYBACK_ERROR = 189119003,     // ����¼��ص�����
    IVS_DCG_PLAYBACK_PLAYRESTART_ERROR    = 189119004,     // �طŻָ����Ŵ���
    IVS_DCG_PLAYBACK_PLAYPAUSE_ERROR      = 189119005,     // �ط���ͣ����
    IVS_DCG_PLAYBACK_PLAYFAST_ERROR       = 189119006,     // �طſ������
    IVS_DCG_PLAYBACK_PLAYSLOW_ERROR       = 189119007,     // �ط����Ŵ���
    IVS_DCG_PLAYBACK_PLAYSETTIME_ERROR    = 189119008,     // �ط����ò���ʱ�����
    IVS_DCG_PLAYBACK_LIST_IS_EMPTY_ERROR  = 189119009,     // ¼��ط�¼���±�listΪ�մ���
    IVS_DCG_PLAYBACK_INDEX_VALUE_ERROR    = 189119010,     // ��¼��list�ó�����index����
    IVS_DCG_STRTEAM_CONTROL_TIME_INVALID  = 189119011,     // ʱ���϶����·�ʱ�䳬��¼�񳤶�
    IVS_DCG_PLEASE_RESEARCH_RECORD_LIST   = 189119012,     // �����¼���¼��
    //DCG���޸�����             26
    IVS_DCG_MOD_DEV_PASSWORD_ERROR        = 189126001,     // �޸�ǰ���������

    //DCG��ץ�Ĺ���             46
    IVS_DCG_GET_SNAP_SHOT_ERROR           = 189146001,     // ƽ̨ץ��ʧ��
    IVS_DCG_PU_HAVE_NO_STORAGE_DEVICE     = 189146002,     // ǰ���豸û�д洢�豸

    //DCG: DCG����              38
    IVS_DCG_DEAL_SESSION_TIME_OUT         = 189138001,     //������Ϣ��ʱ

    //DCG:�ⲿϵͳ����          39
    IVS_DCG_GET_EXTERN_DEV_LIST_ERROR     = 189139001,     // ��ȡ�ⲿϵͳ�豸�б����
    IVS_DCG_SET_EXTERN_DEV_LIST_ERROR     = 189139002,     // �����ⲿϵͳ�豸�б����
    IVS_DCG_GET_SIPASS_UNIT_TABLE_ERROR   = 189139003,     // ��ȡ������unit�����
    IVS_DCG_GET_SIPASS_DEVICE_TABLE_ERROR = 189139004,     // ��ȡ������deviec�����
    IVS_DCG_GET_SIPASS_POINT_TABLE_ERROR  = 189139005,     // ��ȡ������point�����
    IVS_DCG_GET_SIPASS_FLN_TABLE_ERROR    = 189139006,     // ��ȡ������FLN�����
    IVS_DCG_FIND_EXT_DEV_ERROR            = 189139007,     // ��ȡmap�У��ⲿ�豸����
    IVS_DCG_ADD_EXTSUBDEV_ECHO_ERROR      = 189139008,     // ����ⲿ�豸ʱ���豸�Ѿ�����
    IVS_DCG_SIPASS_CON_SER_REG_ERROR      = 189139009,     // ���ӷ�����ע������
    IVS_DCG_SIPASS_OPERATE_REGEDIT_ERROR  = 189139010,     // ����ע������
    IVS_DCG_SIPASS_GET_LO_REG_CLSID_ERROR = 189139011,     // ��ȡ����ע���CLSID����
    IVS_DCG_SIPASS_CREATE_INSTANCE_ERROR  = 189139012,     // ����COM�������
    IVS_DCG_SIPASS_SET_ATL_ADVISE_ERROR   = 189139013,     // ���ø澯�ϱ��ӿڴ���
    IVS_DCG_EXT_SYS_IS_NOT_ONLINE_ERROR   = 189139014,     // �ⲿϵͳ��δע������
    /******************************************
    *   Transcodeת������붨�壨ģ����룺24��
    *******************************************/



    /******************************************
    *   HTTPS TS���ַ������붨�壨ģ����룺25��
    *******************************************/

    /******************************************
    *   RTSP�ַ������붨�壨ģ����룺26��
    *******************************************/

    /******************************************
    *   PCG�����붨�壨ģ����룺27��
    *******************************************/
    IVS_PCG_XML_DECODE_ERROR               = 279139001,     // xml��������
    IVS_PCG_ERROR                          = 279139000,     // �������ڲ�����
    IVS_PCG_PARA_ERROR                     = 279140000,     // ����У��ʧ��
    IVS_PCG_CONN_CODE_ALREADY_EXIST        = 279139003,     // ������Ѿ�����
    IVS_PCG_EXCEED_EXTERN_MAX_NUM          = 279139004,     // ������������128
    IVS_PCG_DEVICEID_REPEAT                = 279139005,     // �豸���������ظ�
    IVS_PCG_EXIST_EXTERN_DOMAIN_PROTOCOL   = 279139006,     // ���ڸ�Э�����͵�����
    IVS_PCG_SHARE_RES_ITSELF_FAIL          = 279139012,     // �����豸�����ٴι����������
    IVS_PCG_EXDOMAIN_PWD_VALIDATE          = 279139013,     // �������벻�����������ù���У��ʧ��
    IVS_PCG_NOT_SUPPORT_REQUEST_FUNCTION   = 279139014,     // �����豸��֧������Ĺ���
    IVS_PCG_SC_BUSY_HERE                   = 279142002,     // ����������������

    /******************************************
    *   MBU�����붨�壨ģ����룺28��
    *******************************************/

    /******************************************
    *   MAUS�����붨�壨ģ����룺29��
    *******************************************/
    IVS_MAU_ERR_CODE                       = 299133200,     // MAUͨ�ô�����ʼֵ
    IVS_MAU_FAILURE                        = 299133201,     // ��Ӧʧ��
    IVS_MAU_SUCCESS_FIRST                  = 299133210,     // �״ε�½�ɹ�
    IVS_MAU_USER_LOCKED                    = 299133211,     // �û�����
    IVS_MAU_NO_ANALYSIS_UNIT               = 299133212,     // MAUδ���ӷ�����Ԫ

    IVS_MAU_AUTHENTICATE_FAILURE           = 299133301,     // ��½��֤ʧ�ܣ�
    IVS_MAU_TRANS_NOT_EXIST                = 299133501,     // ���񲻴��ڣ�ָ�������񲻴��ڣ�
    IVS_MAU_FRONTDEV_NOT_EXIST             = 299133502,     // ���豸�����ڣ��ڲ�ѯ���豸����ʱ��������豸�����ڷ��أ��������������û���ر�˵���ģ�������
    IVS_MAU_LENS_NOT_EXIST                 = 299133503,     // ��ͷ�豸�����ڣ��ڲ�ѯ��ͷ�豸����ʱ�������ͷ�豸�����ڷ��أ��������������û���ر�˵���ģ�������
    IVS_MAU_OTHER_ERROR                    = 299133601,     // ��������
    IVS_MAU_DB_ERROR                       = 299133602,     // ���ݿ�����쳣
    IVS_MAU_PARAM_ERROR                    = 299133603,     // �����쳣
    IVS_MAU_RUNTIME_ERROR                  = 299133604,     // ����ʱ�쳣
    IVS_MAU_XMLPRASE_ERROR                 = 299133605,     // XML�����쳣
    IVS_MAU_OVERLOAD_ERROR                 = 299133607,     // �����쳣
    IVS_MAU_RULEGROUP_NOTEXIST             = 299133608,     // ���򲻴���
    IVS_MAU_PLANID_NOTEXIST                = 299133609,     // �ƻ���Ϣ������
    IVS_MAU_PLAN_TIME_CONFLICT             = 299133613,     // analyze Planʱ����ص�RESP_PLANANA_TSCONFL_ERROR
    IVS_MAU_PLAN_STARTORSTOPPING           = 299133614,     // �ƻ�������ͣRESP_PLAN_STARTSTOPING
    IVS_MAU_REPEAT_OPRATION_ERROR          = 299133615,     // �ظ�����

    IVS_MAU_FACEDBTYPE_NOT_EXIST           = 299133616,     // �������Ϳⲻ����
    IVS_MAU_FACEDBTYPE_EXIST               = 299133617,     // �����������Ѿ�����
    IVS_MAU_FACEDBNAME_EXIST               = 299133618,     // ���������������Ѿ�����
    IVS_MAU_FACE_NOT_DETECT                = 299133619,     // δ��⵽����
    IVS_MAU_REQ_ENROLL2FACESRV_FAIL        = 299133620,     // ������ת������ע������ģ��ʧ��
    IVS_MAU_REQ_ENROLL2FACESRV_EXCP        = 299133621,     // ������ת������ע������ģ���쳣
    IVS_MAU_REQ_DELFROMFACESRV_EXCP        = 299133622,     // ����ڵ������ɾ������ģ���쳣
    IVS_MAU_REQ_DELFROMFACESRV_FAIL        = 299133623,     // ����ڵ������ɾ������ģ��ʧ��
    IVS_MAU_IMAGE_FORMAT_INVALIDATE        = 299133624,     // ͼƬ��ʽ����
    IVS_MAU_REQ_UPDATE2FACESRV_EXCP        = 299133625,     // ������ת��������������ģ��ʧ��
    IVS_MAU_REQ_MEDIAANATYPE_ERR           = 299133626,     // ���ܷ����������Ͳ���ȷ
    IVS_MAU_NOT_FIND_MATCHD_FACE           = 299133628,     // δ�ҵ����Ƶ�����
    IVS_MAU_FACEID_EXIST                   = 299133629,     // ����ID�Ѵ���
    IVS_MAU_FACEID_NOEXIST                 = 299133630,     // ����ID������


    /******************************************
    *   MAUQD�����붨�壨ģ����룺30��
    *******************************************/

    /******************************************
    *   MAUBA�����붨�壨ģ����룺31��
    *******************************************/


    /******************************************
    *   MAUFR�����붨�壨ģ����룺32��
    *******************************************/
    
    /******************************************
    *   IMGU�����붨�壨ģ����룺33��
    *******************************************/
     IVS_IMGU_GETDOMAIN_FAIL               = 339190000,     //ͼƬ�������ػ�ȡDOMAINʧ��
     IVS_IMGU_GETDOWNLOADRATE_FAIL         = 339190001,     //ͼƬ�������ػ�ȡ������Ŀ��ʧ��
     IVS_IMGU_GETDOWNLOADURL_FAIL          = 339190002,     //ͼƬ�������ػ�ȡ����URLʧ��
     IVS_IMGU_MetaDataDOWNLOAD_FAIL        = 339190003,     //Ԫ��������ʧ��
     IVS_IMGU_PICTUREDOWNLOAD_FAIL         = 339190004,     //ͼƬ����ʧ��
     IVS_IMGU_TLV_ENCODE_FAIL              = 339190005,     //ץ��ͼƬTLV����ʧ��
     IVS_IMGU_TLV_DECODE_FAIL              = 339190006,     //ץ��ͼƬTLV����ʧ��
     IVS_IMGU_IPC_NOT_EXIST                = 339190007,     //IPC������
     IVS_IMGU_VCM_IP_REPEAT                = 339190008,     //�޸���Ϣ��IP�Ѵ���
     IVS_IMGU_VCM_IP_CODE_REPEAT           = 339190009,     //�����Ϣ��IP������Ѿ�����
     IVS_IMGU_OFFLINE_BUT_SET_SUCCESS      = 339190010,     //�������óɹ�����IMGU��������Ч
     IVS_IMGU_SENDING_META_OVER            =339190011,      //��ʷͼƬ���ؽ���
     IVS_IMGU_SPECIFICATION_EXCEED_FAIL    =339190012,      //��������
     /******************************************
     *   BP�����붨�壨ģ����룺97��
     *******************************************/
     IVS_BP_SUCCEED                       = 979199000,     // �ɹ�;
     IVS_BP_ERROR                         = 979199001,     // ʧ��;
     IVS_BP_PARA_INVALID                  = 979199002,     // ��������Ƿ�
     IVS_BP_THREAD_BUSY                   = 979199003,     // �̷߳�æ
     IVS_BP_NOT_SUPPORT                   = 979199004,     // ��Ϣ���Ͳ�֧��
     IVS_CBB_SERVER_NOT_EXIST             = 979199005,     // ������������
     IVS_CBB_PARSE_FILE_FAIL              = 979199006,     // �����ļ�ʧ��
     IVS_CBB_OPEN_FILE_FAIL               = 979199007,     // ���ļ�ʧ�ܣ��ļ������ڣ�
     IVS_CBB_PARSE_CONFIG_FAIL            = 979199008,     // ���������ļ�ʧ��
     IVS_CBB_GET_CONFIG_FAIL              = 979199009,     // ��ȡ�����ļ�ʧ��
     /******************************************
     *   VWU�����붨�壨ģ����룺98��
     *******************************************/



    /******************************************
    *   CU�����붨�壨ģ����룺99��
    *   ���������λ��ţ�OCX 000��199 SDK 200��399 MP 400��599
    *******************************************/
    // OCX 000��199
    //IVS_OCX_CU_XML_INVALID                 = 999115000,     // CU��OCX�Ĳ�ѯXML�Ƿ�;
    //IVS_OCX_ALLOC_MEMORY_ERROR             = 999115001,     // CU�ڴ�����ʧ��;
    //IVS_OCX_INTRINSIC_PTR_ERROR            = 999115002,     // CU�ڲ�ָ�����;
    IVS_OCX_SDK_INIT_FAIL                  = 999115003,     // OCX��ʼ��SDKʧ��;
    //IVS_OCX_XML_NODE_VALUE_ERROR           = 999115004,     // XML�ڵ�ֵ����ȷ
    IVS_OCX_RET_SET_DEVNAME_ERROR          = 999115005,     // �����豸����ʧ��
    IVS_OCX_RET_VIDEOPANE_IS_PLAYING_ERROR = 999115006,     // �������ڲ�����Ƶ����
    IVS_OCX_RET_GET_ACTIVE_WND_ID_ERROR    = 999115007,     // ��ȡ�����IDʧ��
    //IVS_OCX_RET_GET_WND_POINTER_ERROR      = 999115008,     // ��ȡ�����ָ��ʧ��
    //IVS_OCX_RET_ALREADY_INIT_ERROR         = 999115009,     // �ظ���ʼ��
    IVS_OCX_RET_RESET_PANE_INFO_ERROR      = 999115010,     // ��λ������Ϣʧ��
    IVS_OCX_RET_SET_WND_LAYOUT_ERROR       = 999115011,     // ���ô��񲼾�ʧ��
    //IVS_OCX_RET_NO_WRITE_AUTHORITY_ERROR   = 999115012,     // û��дȨ�ޣ������ļ��л�ץ��/¼���ļ�ʧ��
    //IVS_OCX_RET_VIDEOPANEMGR_NULL          = 999115013,     // ���������Ϊ��
    //IVS_OCX_RET_VIDEOPANE_NULL             = 999115014,     // ����Ϊ��
    //IVS_OCX_RET_START_LOG_ERROR            = 999115015,     // ������־ʧ��
    //IVS_OCX_RET_SETOCX_CTRL_ERROR          = 999115016,     // ���ÿؼ�ָ��ʧ��
    //IVS_OCX_RET_INITIAL_VIDEOPANEMGR_ERROR = 999115017,     // ��ʼ�����������ʧ��
    //IVS_OCX_RET_SETOCXLOG_ERROR            = 999115018,     // ������־����ʧ��
    //IVS_OCX_RET_PLAYSOUND_WITH_VIDEO_ERROR = 999115019,     // ��������ʧ��
    //IVS_OCX_RET_STOPSOUND_WITHVIDEO_ERROR  = 999115020,     // �ر�����ʧ��
    //IVS_OCX_RET_ADJUST_WAVE_AUDIO_ERROR    = 999115021,     // ��������ʧ��
    //IVS_OCX_RET_SET_WAVE_AUDIO_ERROR        = 999115022,     // ��������ʧ��
    //IVS_OCX_RET_SET_PAGENUMBER_ERROR        = 999115023,     // ����ҳ��ʧ��
    //IVS_OCX_RET_CAPTURE_HAS_STARTED_ERROR  = 999115024,     // ץͼ�ѿ�ʼ����
    IVS_OCX_RET_CAPTURE_CREATE_THREAD_ERROR = 999115025,    // ץͼ�����̴߳���
    IVS_OCX_RET_SET_WARN_STATE_ERROR         = 999115026,     // ���þ���״̬ʧ��
    //IVS_OCX_RET_VOICE_TALKBACK_HAS_PLAYED_ERROR     = 999115027,   //�����Խ��Ѿ�����
    //IVS_OCX_RET_VOICE_TALKBACK_IS_NOT_PLAYING_ERROR = 999115028,   //�����Խ�δ����
    //IVS_OCX_RET_SET_DISPLAY_SCALE_ERROR       = 999115029,     // ���ô�����ʾ����ʧ��
    IVS_OCX_RET_VIDEOPANE_ISNOT_PLAYING_ERROR = 999115030,     // ����û�в�����Ƶ
    //IVS_OCX_RET_PARSE_XML_FAIL                = 999115031,     // ����xmlʧ��
    //IVS_OCX_RET_VIDEOPANE_ISNOT_RECORD_ERROR  = 999115032,     // ����û����¼��
    //IVS_OCX_RET_IS_ALARM_WINDOW_ERROR       = 999115033,    // ����Ϊ�澯����
    //IVS_OCX_RET_VIDEOPANE_ISNOT_SOUND_ERROR = 999115034,    // ����û���ڴ�����
    IVS_OCX_RET_VIDEOPANE_ISNOT_ALARM_ERROR = 999115035,    // �����Ǹ澯����
    //IVS_OCX_RET_PLAYBACK_FILENAME_ERROR    = 999115036,    // �ط��ļ�������
    //IVS_OCX_RET_PTZ_NO_RIGHT_EXCEPTION     = 999115037,    // ����̨Ȩ���쳣
    IVS_OCX_RET_GET_INFO_ERROR             = 999115038,    // ��ȡ��Ϣʧ��
    //IVS_OCX_FILE_CREATE_ERROR              = 999115039,    // OCX�����ļ�����ʧ��
    //IVS_OCX_FILE_NOT_EXIST                 = 999115040,    // OCX�����ļ�������
    IVS_OCX_RET_SKIN_INIT_ERROR            = 999115041,    // OCX��ʼ��Ƥ��ʧ��
    IVS_OCX_RET_FIND_PLAY_HANDLE_ERROR     = 999115042,    // OCX�����ڸò��ž��
    //IVS_OCX_RET_REALTIMEBAR_ERROR_SOUND    = 999115043,    // ʵʱ��������
    IVS_OCX_RET_NO_PLAY_HANDLE             = 999115044,    // û�в��ž��
    //IVS_OCX_LOGO_XML_ERROR                 = 999115045,     // logoxml��ȡʧ��
    //IVS_OCX_EVENT_NO_CATCH                 = 999115046,     // δ�ػ��¼�
    IVS_OCX_RET_POINT_OUT_CLIENT             = 999115047,    // ������OCX����

    // SDK 200��399
    IVS_SDK_RET_INIT_RTSPCLIENT_ERROR        = 999115200,    // ��ʼ��RtspClient��ʧ��;
    IVS_SDK_RET_SET_LOG_LEVEL_ERROR          = 999115201,    // ������־����ʧ��
    //IVS_SDK_RET_MAIN_SERVICE_INIT_FAIL     = 999115301,    // SDK����BP��������ʧ��;
    //IVS_SDK_RET_INIT_THREA_FAIL            = 999115302,    // SDK��ʼ�����߳�ʧ��;
    //IVS_SDK_RET_INIT_LOG_FAIL              = 999115303,    // SDK��ʼ��LOG����ʧ��;
    //IVS_SDK_RET_SMU_SDK_XML_INVALD         = 999115304,    // SMU��SDK����ӦXML�Ƿ�;
    IVS_SDK_RET_BP_CMD_REQ_INVALID         = 999115305,    // SDK����BP��������Ƿ�;
    IVS_SDK_RET_BP_CMD_RSP_INVALID         = 999115306,    // SDK����BPӦ������Ƿ�;
    //IVS_SDK_RET_BP_CMD_RSP_XML_ERROR       = 999115307,    // SDK����BPӦ������XML�Ƿ�;
    //IVS_SDK_RET_INTRINSIC_PTR_ERROR        = 999115308,    // SDK�ڲ�ָ�����;
    //IVS_SDK_RET_ALLOC_MEMORY_ERROR         = 999115309,    // SDK�ڴ�����ʧ��;
    //IVS_SDK_RET_MEMORY_CHECK_ERROR         = 999115310,    // SDK�ڴ�У��ʧ��;
    //IVS_SDK_RET_INIT_ERROR                 = 999115311,    // SDK��ʼ��ʧ��;
    IVS_SDK_RET_INVALID_SESSION_ID         = 999115312,    // ��Ч��SessionID;
    IVS_SDK_ERR_FINDVIDEOHANDLE_FAILED     = 999115313,    // ��ȡ��Ƶ���ʧ��
    IVS_SDK_ERR_ERR_MAX_USERNUM            = 999115314,    // �ﵽ������û�
    //IVS_SDK_ERR_BUFFERSIZE_NOT_ENOUGH      = 999115315,    // ��ʾ�ⲿ�����ڴ治��(������ocxҲ�����ǵ�����)
    //IVS_SDK_ERR_FINDXMLNODE_FAILED         = 999115316,    // �޷��ҵ�xml����Ӧ��Ӧ�ڵ�;
    //IVS_SDK_ERR_WRITEFILE_FAILED           = 999115317,    // д�ļ�ʱ��������;
    //IVS_SDK_ERR_OPENFILE_FAILED            = 999115318,    // ��zip�ļ�ʱ��������;
    IVS_SDK_ERR_CHEACKMD5_FAILED           = 999115319,    // ���zip�ļ�ʱ��������;
    IVS_SDK_ERR_DELETEZIPFILE_FAILED       = 999115320,    // ɾ��zipʱ��������;
    IVS_SDK_ERR_CREATEZIPFILE_FAILED       = 999115321,    // ����zipʱ��������;
    IVS_SDK_ERR_DOMAINCODE_NOT_EXIST       = 999115322,    // ����벻����
    //IVS_SDK_ERR_GET_LOGO_FAILED            = 999115323,    // ��ȡlogoʧ��
    //IVS_SDK_ERR_FILE_NOT_EXIST             = 999115324,    // ��ȡlogoʧ��
    IVS_SDK_ERR_DECODER_NOT_SUPPORT_PATROL = 999115325,    //��������֧����Ѳ
    IVS_SDK_ERR_GETDOMAIN_FAIL               = 999115326,     //ͼƬ�������ػ�ȡDOMAINʧ��
    IVS_SDK_ERR_GETDOWNLOADURL_FAIL          = 999115327,     //ͼƬ�������ػ�ȡ����URLʧ��
    IVS_SDK_ERR_PICTUREDOWNLOAD_FAIL        = 999115328,     //ͼƬ����ʧ��

    //IVS_SDK_PLAYBACK_ERR_RSP_GETURL        = 999119200,    // ��ȡURL��Ӧ��Ϣ�쳣
    //IVS_SDK_PLAYBACK_ERR_STARTTIME_ZERO    = 999119201,    // �طſ�ʼʱ��Ϊ0�쳣
    //IVS_SDK_PLAYBACK_ERR_PORT_NOTEXIST_FAIL_FORSTOP = 999119202,   // ֹͣ�ط�port�ڲ�����
    //IVS_SDK_PLAYBACK_ERR_PLAYHANDLE        = 999119203,    // �ط�handle���Ϸ�
    //IVS_SDK_PLAYBACK_ERR_PLAT_SPEED_PARM   = 999119204,    // ƽ̨�ط������ٶȲ������Ϸ�
    //IVS_SDK_PLAYBACK_ERR_PU_SPEED_PARM     = 999119205,    // ǰ�˻ط������ٶȲ������Ϸ�
    //IVS_SDK_PLAYBACK_ERR_GET_REMOTE_STATUS = 999119206,    // ��ȡԶ�˲���״̬ʧ��
    //IVS_SDK_PLAYBACK_ERR_GET_REMOTE_SPEED  = 999119207,    // ��ȡԶ�˲����ٶ�ʧ��
    //IVS_SDK_PLAYBACK_ERR_GET_REMOTE_TIME   = 999119208,    // ��ȡԶ�˲���ʱ��ʧ��
    //IVS_SDK_PLAYBACK_ERR_STATUS_DOUDLE_STOP   = 999119209,     // �ظ�������ͣ״̬
    //IVS_SDK_PLAYBACK_ERR_STATUS_DOUDLE_RESUME = 999119210,     // �ظ����ûָ�״̬
    IVS_SDK_PLAYBACK_ERR_GET_REMOTE_DATAINFO  = 999119211,     // ��ȡԶ�˲�����Ϣʧ��
    //IVS_SDK_PLAYBACK_ERR_TIMESPAN             = 999119212,     // �ط�timespan���Ϸ�
    //IVS_SDK_PLAYBACK_ERR_GET_LOCAL_DATAINFO   = 999119213,     // ��ȡ���ز�����Ϣʧ��
    //IVS_SDK_PLAYBACK_ERR_LOCAL_RECORDING      = 999119214,     // �˴������ڽ���¼�ƣ���ʼ����¼��ʧ��
    //IVS_SDK_PLAYBACK_ERR_NOT_LOCAL_RECORDING  = 999119215,     // û�д������ڽ���¼�ƣ�ֹͣ����¼��ʧ��
    //IVS_SDK_RET_SMU_SERVER_NOT_RESPOND     = 999119216,     // SMU��Ϣ���س�ʱ
    //IVS_SDK_RET_SCU_SERVER_NOT_RESPOND     = 999119217,     // SCU��Ϣ���س�ʱ
    //IVS_SDK_RET_OMU_SERVER_NOT_RESPOND     = 999119218,     // OMU��Ϣ���س�ʱ
    IVS_SDK_SET_CLUSTER_MSG_FAILED           = 999119218,     // �·���Ⱥʧ��

    /*�Խ�������*/
    IVS_SDK_ERR_FINDAUDIOHANDLE_FAILED     = 999119219,       // ��ȡ�Խ����ʧ��
    IVS_SDK_TALKBACK_ERR_ALREADY_OPENED    = 999119220,       // �Ѿ�����һ·�Խ���㲥
//     IVS_SDK_TALKBACK_ERR_ALREADY_CLOSED    = 999119221,       // ��δ����
    IVS_SDK_BROADCASE_ERR_NO_DEVICE        = 999119222,       // �豸����û���豸
    IVS_SDK_BROADCASE_ERR_ALREADY_OPENED   = 999119223,       // �㲥�Ѿ�����
    IVS_SDK_BROADCASE_ERR_NOT_OPENED       = 999119224,       // �㲥û�п���
    IVS_SDK_VOICE_ERR_INVALID_USEROBJ      = 999119225,       // �û�����Ϊ�գ��޷���ȡ�û���Ϣ
    IVS_SDK_VOICE_ERR_INVALID_USERINFO     = 999119226,       // �û���ϢΪ��
    IVS_SDK_VOICE_ERR_GET_URL_FAIL         = 999119227,       // ��ȡURLʧ��
    IVS_SDK_VOICE_ERR_SET_IP_FAIL          = 999119228,       // ���ý���IPʧ��
    IVS_SDK_VOICE_ERR_CALL_MLIB_FAIL       = 999119229,       // ����Mlib��ӿڷ���ʧ��
    IVS_SDK_VOICE_ERR_DEV_ALREADY_IN       = 999119230,       // �豸�Ѽ����豸��
    IVS_SDK_VOICE_ERR_DEV_NOT_IN           = 999119231,       // �豸����û�и��豸
    IVS_SDK_VOICE_ERR_STOP_BROADCAST_FAIL  = 999119232,       // ɾ���豸ʱֹͣ��Ӧ�豸�Ĺ㲥ʧ��
    IVS_SDK_VOICE_ERR_TOO_MUCH_DEVICES     = 999119233,       // �㲥���е��豸���������ֵ256
    IVS_SDK_VOICE_ERR_GET_HANDLE_FAIL      = 999119234,       // �����豸ID���ҹ㲥handleʧ��
    IVS_SDK_VOICE_ERR_FILE_NOT_EXIST       = 999119235,       // �ļ�������
    IVS_SDK_VOICE_ERR_FILE_NOT_RIGHT_TYPE  = 999119236,       // ����wav��ʽ����Ƶ�ļ�
    IVS_SDK_VOICE_ERR_CANNOT_REPORT_FAIL   = 999119237,       // ��ȡ�û�����Ļص�����ʧ��
    IVS_SDK_VOICE_ERR_ALL_BROADCAST_FAIL   = 999119238,       // �㲥����\�ر�ȫ��ʧ��
    IVS_SDK_VOICE_ERR_AUDIO_TYPE_CONFLICT  = 999119239,       // ��Ƶ��ʽ��֮ǰ�ľ�ͷ��ͻ
    IVS_SDK_EXCHANGE_KEY_ERR_GET_KEY_FAIL  = 999119240,       // ��ԿЭ�̽���ʧ�ܡ���ȡ��Կʧ��
    IVS_SDK_LOCALRECORD_UNSUPPORTED_MJPEG = 999119241,       // ����¼��֧��MJPEG��ʽ
    IVS_SDK_LOCALRECORD_UNSUPPORTED_VIDEODECTYPE  = 999119242,       // ����¼��֧�ָ���Ƶ�����ʽ
    IVS_SDK_NOT_CLUSTER_MODE               = 999119243,       // �������쳣��ģʽ����
    IVS_SDK_NOT_PLAY_TVWALL                = 999119244,       // û�е�����ǽ(�ڹرյ�����ǽ��ʱ�򷵻�)
    IVS_SDK_NET_REDIRECT_FAILED            = 999119245,       // ������߷�����ԭ���ض���ʧ��
    IVS_SDK_PROXY_ROUTE_REDIRECT_FAILED    = 999119246,       // �ض���ʧ��,��������Ҫ�ض���
    IVS_SDK_HAVE_SAME_CHANNEL              = 999119247,       // ����ͬͨ��
    IVS_SDK_CUR_SES_NO_SUPPORT_SHADOW_DEV  = 999119248,       // Ӱ���豸��֧�ֵ�ǰҵ��
    IVS_SDK_DOWNLOAD_UNSUPPORTED_VIDEODECTYPE  = 999119249,       // ¼�����ز�֧�ָ���Ƶ�����ʽ
    IVS_SDK_QUERY_VEHICLE_LIST_ERROR       = 999119250,       // ���ַ�������Ӧʧ�ܣ����������״̬

    IVS_SDK_FORBID_DIFFERENT_CLUSTER_SHIFT = 999119254,      //��ǰ��֧����ͬһ����Ⱥ�½���Ǩ��
    IVS_SDK_QUERY_METADATA_EXCEED_FAIL = 999119255,          //����������Χ������С����ʱ���(һ������ѯ����SDKConfig.xml�е����þ���)
    IVS_SDK_PARAMETER_VALUE_ERROR          = 999119256,       //��β��Ϸ�

    // MP 400��599
    IVS_PLAYER_RET_GET_CHANNEL_ERROR       = 999115400,     // ��ȡͨ��ʧ��;
    IVS_PLAYER_RET_ALL_PORT_BUSY_ERROR     = 999115401,     // ���ж˿ھ���ռ��;
    IVS_PLAYER_RET_WSA_START_ERROR         = 999115402,     // ����SOCKET��DLL�����;
    IVS_PLAYER_RET_CONNECT_SOCKET_ERROR    = 999115403,     // ����socket����ʧ��;
    IVS_PLAYER_RET_ALLOC_MEM_ERROR         = 999115404,     // �������ʧ��;
    IVS_PLAYER_RET_RECV_DATA_ERROR         = 999115405,     // ����������;
    IVS_PLAYER_RET_RECV_DATA_TIMEOUT       = 999115406,     // ���ӳ�ʱ;
    IVS_PLAYER_RET_CREATE_THREAD_ERROR     = 999115407,     // �����߳�ʧ��;
    IVS_PLAYER_RET_CREATE_DECODER_ERROR    = 999115408,     // ���������ʧ��;
    IVS_PLAYER_RET_ORDER_ERROR             = 999115409,     // ����˳�򲻶�;
    IVS_PLAYER_RET_DECODER_ERROR           = 999115410,     // ����ʧ��;
    IVS_PLAYER_RET_WATER_MARK_OK           = 999115411,     // ˮӡ��������;
    IVS_PLAYER_RET_WATER_MARK_ERROR        = 999115412,     // ˮӡ���ݱ��۸�;
    IVS_PLAYER_RET_UNSUPPORT_OPERATION     = 999115413,     // ��ǰ�汾��֧�ִ˲���;
    IVS_PLAYER_RET_DECODER_BUFFER_FULL     = 999115414,     // ��������;

    IVS_PLAYER_RET_RTSP_GET_HANDLE_FAIL    = 999115415,     // ��ȡrtsp��handleʧ��;
    IVS_PLAYER_RET_RTSP_SEND_SETUP_FAIL    = 999115416,     // ����rtsp��Setup����ʧ��;
    IVS_PLAYER_RET_RTSP_SEND_PLAY_FAIL     = 999115417,     // ����rtsp��Play����ʧ��;
    IVS_PLAYER_RET_RTSP_SEND_PAUSE_FAIL    = 999115418,     // ����rtsp��Pause����ʧ��;
    IVS_PLAYER_RET_RTSP_SEND_TEARDOWN_FAIL = 999115419,     // ����rtsp��Teardown����ʧ��;
    IVS_PLAYER_RET_RTSP_NORMAL_STOP        = 999115420,     // RTSP�����յ���������
    IVS_PLAYER_RET_RTSP_ABNORMAL_STOP      = 999115421,     // RTSP�����յ��쳣����;
    IVS_PLAYER_RET_RTSP_DATA_ERROR         = 999115422,     // RTSP����������Ҫ��;
    IVS_PLAYER_RET_RTSP_DISCONNECT         = 999115423,     // RTSP�����Ͽ�;
    IVS_PLAYER_RET_NET_OPEN_STREAM_FAIL    = 999115424,     // ������������ʧ��;
    IVS_PLAYER_RET_MP_OPEN_STREAM_FAIL     = 999115425,     // ���ſ��������ʧ��;
    IVS_PLAYER_RET_MP_START_PLAY_FAIL      = 999115426,     // ���ſ���������ʧ��;
    IVS_PLAYER_RET_NET_START_RECEIVE_FAIL  = 999115427,     // �������������ʧ��;
    IVS_PLAYER_RET_INIT_NETSOURCE_ERROR    = 999115428,     // ��ʼ������������ʧ��;
    IVS_PLAYER_RET_INIT_PLAY_ERROR         = 999115429,     // ��ʼ������������ʧ��;
    IVS_PLAYER_RET_FILE_ACCESS_ERROR       = 999115430,     // �����ļ���Ŀ¼����;
    IVS_PLAYER_RET_DISK_SPACE_ERROR        = 999115431,     // ���̿ռ�������;
    IVS_PLAYER_RET_MIXER_OPEN_STATE_ERROR  = 999115432,     // ��������״̬����
    IVS_PLAYER_RET_MIXER_ERROR             = 999115433,     // ��������������
    IVS_PLAYER_RET_VOICE_TALKBACK_STATUS_ERROR = 999115434, // �����Խ�״̬ʧ��
    IVS_PLAYER_RET_BROADCAST_FILE_IS_END   = 999115435,     // �����㲥�ļ����Ž���
    IVS_PLAYER_RET_BROADCAST_NOT_SUPPORTED_FORMAT = 999115436, // �����㲥������ļ���ʽ��֧��
    IVS_PLAYER_RET_BROADCAST_OPEN_FILE_ERROR = 999115437,   // �����㲥���ļ�ʧ��
    IVS_PLAYER_RET_GET_STREAM_OPEN_MODE_ERROR = 999115438,  // ��ȡ��������ģʽʧ��
    IVS_PLAYER_RET_GET_AUDIO_VOLUMN_ERROR  = 999115439,     // ��ȡ����ʧ��
    IVS_PLAYER_RET_WAVE_OUT_ERROR          = 999115440,     // ����Ƶ���ʧ��
    IVS_PLAYER_RET_CAPTURE_OPEN_STATE_ERROR = 999115441,    // ��Ƶ�ռ�״̬����
    IVS_PLAYER_RET_WAVE_IN_ERROR           =  999115442,    // ����Ƶ����ʧ��
    IVS_PLAYER_RET_AUDIO_DEVICE_NOT_FIND   =  999115443,    // δ�ҵ���Ƶ�豸
    IVS_PLAYER_RET_MEDIA_TYPE_UNSUPPORT    =  999115444,    // ��֧�ָ�ý������
    IVS_PLAYER_RET_VOICE_BROADCAST_STATUS_ERROR = 999115445,// �����㲥״̬ʧ��
    IVS_PLAYER_RET_CHANNEL_NOT_EXIST_ERROR = 999115446,     // ͨ��������
    IVS_PLAYER_RET_RTSP_CHANGE_DECODER = 999115447,      //�޸�������ʽ��Ϣ

    IVS_PLAYER_RET_RTSP_ERR_NOT_EXIST      = 999115447,     // ���Ӿ��������
    IVS_PLAYER_RET_RTSP_ERR_DISCONNECT     = 999115448,     // ����ʧ��
    IVS_PLAYER_RET_RTSP_ERR_RESPONSE       = 999115449,     // ��Ӧ��Ϣ����
    IVS_PLAYER_RET_RTSP_ERR_TIMEOUT        = 999115450,     // ��Ӧ��ʱ
    IVS_PLAYER_RET_RTSP_ERR_STAUTS_ABNORMAL= 999115451,     // ����״̬�쳣
    IVS_PLAYER_RET_RTSP_ERR_SEND_FAIL      = 999115452,     // ���ͳ���
    IVS_PLAYER_RET_RTSP_ERR_RECV_FAIL      = 999115453,     // ���ճ���
    IVS_PLAYER_RET_RTSP_ERR_PARAMETER      = 999115454,     // ����������
    IVS_PLAYER_RET_RTSP_ERR_NORMAL_STOP    = 999115455,     // ����������ANNOUNCE������������
    IVS_PLAYER_RET_RTSP_ERR_ABNORMAL_STOP  = 999115456,     // �쳣������ANNOUNCE�쳣��������
    IVS_PLAYER_RET_RTSP_ERR_RET_SYS        = 999115457,      // ͨ��ϵͳ����
    IVS_PLAYER_RET_NET_BIND_PORT_FAIL       = 999115458,      // �󶨶˿�ʧ��;
    IVS_PLAYER_RET_RTSP_ERR_SERVICE_500_RSP= 999115459, // ������500��Ӧ;
    IVS_PLAYER_RET_RTSP_ERR_SERVICE_UNAVAILABLE_RSP=999115460,// ���񲻿���;
    IVS_PLAYER_RET_DISK_WRITE_ERROR=999115461,// ¼���ļ�д��ʧ�ܣ������ļ���Ȩ������;
    IVS_PLAYER_RET_ERR_FILE_NOT_EXIST       = 999115462,       // ¼���ļ�������
    IVS_PLAYER_RET_TALKBACK_OPENED_ERROR = 999115463,     // �����Խ��Ѿ�����
    IVS_PLAYER_RET_NOTENOUGH_BANDWIDTH   = 999115464,     // ý�������������
    IVS_PLAYER_RET_ERR_CAMERA_BEYOND_RANGE = 999115465,     // ǰ�˽����û�������������
    
    /**************************************************************
     *   LDU�����붨�壨ģ����룺33��
     *************************************************************/
     
    // LDU:��־��������룬ȡֵ��Χ��339100000 ~ 339100999 */
    IVS_LDU_SET_LOG_LEVEL_ERROR            = 339100000,    // ������־����ʧ��
    IVS_DECODER_EXCEED_DECODER_CAPABILITY      = 339100001, //������������
    IVS_DECODER_OFF_LINE                   = 339100002, //����������
    IVS_DECODER_PATROl_ONLINE              = 339100003, //�ô���������ѲPatrol
     /**************************************************************
     *   DSU�����붨�壨ģ����룺34��
     *************************************************************/
     IVS_DSU_LOGIN_LOCKED_ERROR            = 349100001,    // �˻�����
     IVS_DSU_LOGIN_OVER_MAX                = 349100002,     // ��½����������� 
     IVS_DSU_ALREADY_LOGIN                 = 349100003,    // �û��Ѿ���½
     IVS_DSU_NOCHG_LOGIN_PWD               = 349100004,     // ���ȵ�web���޸�CU��½������������   

} IVS_ERROR_E;


#endif //_IVS_ERROR_H_
