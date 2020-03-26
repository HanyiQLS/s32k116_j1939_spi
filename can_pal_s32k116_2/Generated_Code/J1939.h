/*********************************************************************
 *
 *            J1939 Main Source Code
 *
 *********************************************************************
 *
 *	����������XieTongXueFlyMe�����е�J1939Э���ĵ��������Ͷ�ǰ���Ĺ����ܽ�,
 * д����һ�׿�Դ��J1939������
 *	��Э���ص㣺
 *		1.����ֲ��������ض���CANӲ����ֻҪ����CAN2.0B���ɣ�
 *		2.������������Ӧ�Ͷ˵�MCU��
 *		3.֧�ֶ�������ýӿڣ�������Ƕ��ʽϵͳ��
 *		4.˫ģʽ����ѯ�����жϣ��߼����Ӽ����ˣ�
 *		5.����֡�����ݲ����շ��жӻ��棩
 *
 *  Դ�������أ�
 *		https://github.com/XeiTongXueFlyMe/J1939
 *  Դ������ʱ�ֲ�Webվ�㣺
 *		https://xeitongxueflyme.github.io/j1939doc.github.io/
 *
 * Version     Date        Description
 * -------------------------------------------------------------------
 * v1.0.0     2017/06/04    �׸��汾 Version 1 ���԰淢��
 * v1.0.1     2017/08/04    ���ƹ���
 * v1.1.0     2017/11/22    Version 1 �ȶ�������
 * v2.0.1     2017/11/24    Version 2 ���԰淢��
 * v2.0.2     2018/01/03    ���V2.0.1 ��������
 * v2.1.0     2018/01/20    Version 2 �ȶ�������
 * Author               Date         changes
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *XeiTongXueFlyMe       7/06/04      �׸��汾
 *XeiTongXueFlyMe       7/08/04      ���Ӷ�TP��֧��
 *XeiTongXueFlyMe       7/11/24      ���ӶԶ�·CANӲ�����շ����ͱ��Ĵ���
 *XeiTongXueFlyMe       7/11/29      �����������ӦAPI
 *XeiTongXueFlyMe       7/12/07      ����TP����API����
 *XeiTongXueFlyMe       7/12/08      ���������˲���
 *XeiTongXueFlyMe       8/01/03      �������ܷ���API����Э��ջ��ʼ�������߼�
 **********************************************************************/
#ifndef __J1939_H
#define __J1939_H
/******************************��������*********************************/
#define FALSE 0
#define TRUE 1

/** ͳһ���Ͷ���
 *  ��ͬ�ĵ�Ƭ���ı������� int,short,long ��λ�����ܲ�ͬ
 *
 *  ����ֲJ1939Э��ջʱ������Ӧ����������
 */
typedef unsigned int   j1939_uint32_t;  /** < 32λ�޷�������*/
typedef int   		   j1939_int32_t;   /** < 32λ����*/
typedef unsigned short j1939_uint16_t;  /** < 16λ�޷�������*/
typedef unsigned char  j1939_uint8_t;   /** < 8λ�޷�������*/
typedef char           j1939_int8_t;    /** < 8λ�޷�������*/
#define J1939_NULL     0

//�������ش���
#define RC_SUCCESS			    0  /**< �ɹ�*/
#define RC_QUEUEEMPTY			1  /**< �ж�Ϊ��*/
#define RC_QUEUEFULL			1  /**< �ж���*/
#define RC_CANNOTRECEIVE		2  /**< ���ܽ���*/
#define RC_CANNOTTRANSMIT		2  /**< ���ܴ���*/
#define RC_PARAMERROR			3  /**< ��������*/

//�ڲ�����
#define J1939_FALSE				0  /**< �����������󷵻�*/
#define J1939_TRUE				1  /**< ����������ȷ����*/

// J1939 Ĭ�ϵ����ȼ����ο�J1939�ĵ���
#define J1939_CONTROL_PRIORITY			0x03 /**< J1939�ĵ�Ĭ�ϵ����ȼ�*/
#define J1939_INFO_PRIORITY			    0x06 /**< J1939�ĵ�Ĭ�ϵ����ȼ�*/
#define J1939_PROPRIETARY_PRIORITY		0x06 /**< J1939�ĵ�Ĭ�ϵ����ȼ�*/
#define J1939_REQUEST_PRIORITY			0x06 /**< J1939�ĵ�Ĭ�ϵ����ȼ�*/
#define J1939_ACK_PRIORITY			    0x06 /**< J1939�ĵ�Ĭ�ϵ����ȼ�*/
#define J1939_TP_CM_PRIORITY			0x07 /**< J1939�ĵ�Ĭ�ϵ����ȼ�*/
#define J1939_TP_DT_PRIORITY			0x07 /**< J1939�ĵ�Ĭ�ϵ����ȼ�*/

// J1939 ����ĵ�ַ
#define J1939_GLOBAL_ADDRESS			255 /**< ȫ�ֵ�ַ*/
#define J1939_NULL_ADDRESS			    254 /**< �յ�ַ*/

//J1939Э��ջ��PNG������Ӧ����صĶ���
#define J1939_PF_REQUEST2				201  /**< J1939Э��ջ������ PF */
#define J1939_PF_TRANSFER				202  /**< J1939Э��ջ��ת�� PF */

#define J1939_PF_REQUEST				234  /**< ���� �� �������ֻ���*/
#define J1939_PF_ACKNOWLEDGMENT			232  /**< ȷ������ �� �������ֻ���*/

#define J1939_ACK_CONTROL_BYTE			0    /**< ����TP(��֡����)������ȷ��*/
#define J1939_NACK_CONTROL_BYTE			1    /**< ����TP(��֡����)��PNG����֧�֡�����Ϣ*/
#define J1939_ACCESS_DENIED_CONTROL_BYTE	2/**< �ܾ����ʣ�������Ϣ�Ǳ�֧�֣���ʱ������Ӧ����Ҫ�ٴη�������*/
#define J1939_CANNOT_RESPOND_CONTROL_BYTE	3/**< ����������Ӧ���пյ��ǽ��ܵĻ��治������������Դ��ռ�죬��ʱ������Ӧ����Ҫ�ٴη�������*/

//TPЭ���һЩ�궨��
#define J1939_PF_DT				        235	    /**< Э�鴫��---���ݴ��� PF*/
#define J1939_PF_TP_CM				    236		/**< Э�鴫��---���ӹ��� PF*/

//TP�ĳ�ʱʱ�䣬��λ��ms��
#define J1939_TP_Tr						200 /**< �궨��TP�ĳ�ʱʱ��*/
#define J1939_TP_Th						500 /**< �궨��TP�ĳ�ʱʱ��*/
#define J1939_TP_T1						750 /**< �궨��TP�ĳ�ʱʱ��*/
#define J1939_TP_T2						1250 /**< �궨��TP�ĳ�ʱʱ��*/
#define J1939_TP_T3						1250 /**< �궨��TP�ĳ�ʱʱ��*/
#define J1939_TP_T4						1050 /**< �궨��TP�ĳ�ʱʱ��*/
#define J1939_TP_TIMEOUT_NORMAL			0    /**< δ��ʱ����*/
#define J1939_TP_TIMEOUT_ABNORMAL		1    /**< ��ʱ*/
#define J1939_RTS_CONTROL_BYTE			16	 /**< TP.CM_RTS*/
#define J1939_CTS_CONTROL_BYTE			17	 /**< TP.CM_CTS*/
#define J1939_EOMACK_CONTROL_BYTE		19	 /**< ��ϢӦ�����*/
#define J1939_BAM_CONTROL_BYTE			32	 /**< �㲥������Ϣ*/
#define J1939_CONNABORT_CONTROL_BYTE	255	 /**< �����жϿ����ֽڣ��������ӣ�*/
#define J1939_RESERVED_BYTE             0xFF /**< �����ı���λ��ֵ*/

//��J1939������йصĶ���
#define J1939_PGN2_REQ_ADDRESS_CLAIM	0x00
#define J1939_PGN1_REQ_ADDRESS_CLAIM	0xEA
#define J1939_PGN0_REQ_ADDRESS_CLAIM	0x00

#define J1939_PGN2_COMMANDED_ADDRESS	0x00
#define J1939_PGN1_COMMANDED_ADDRESS	0xFE	/**< �����ַ��Ϣ*/
#define J1939_PGN0_COMMANDED_ADDRESS	0xD8    /**< �ο�J1939-81 ��ַ��������*/

#define J1939_PF_ADDRESS_CLAIMED		238
#define J1939_PF_CANNOT_CLAIM_ADDRESS	238
#define J1939_PF_PROPRIETARY_A			239     /**< ר��A*/
#define J1939_PF_PROPRIETARY_B			255     /**< ר��B*/

/**< �Ƿ��TPЭ���֧�֣��Ƿ�֧�ֳ�֡������8�ֽڵ����ݣ��ķ�������ܣ�*/
#define J1939_TP_RX_TX J1939_TRUE
/**< TPЭ���֧�ֵ������ܷ�����Ϣ����(��������Ϊ1785)*/
#define J1939_TP_MAX_MESSAGE_LENGTH 240

/**CAN�ڵ��ѡ��ö��
*
* Ĭ��֧�����4·CANӲ��\n
*/
typedef enum
{
	Select_CAN_NODE_Null,	/**< ��ѡ���κ�CANӲ��*/
	Select_CAN_NODE_1,		/**< ѡ��CANӲ�� 1*/
	Select_CAN_NODE_2,		/**< ѡ��CANӲ�� 2*/
	Select_CAN_NODE_3,		/**< ѡ��CANӲ�� 3*/
	Select_CAN_NODE_4,		/**< ѡ��CANӲ�� 4*/
}CAN_NODE;

#if J1939_TP_RX_TX
/**TP��״̬����ö��
*
*/
typedef enum
{
	J1939_TP_NULL,  /**< �����ݴ��䴦�ڿ��У�ֻ��TPϵͳ���ڿ��У������ô�����һ�����ͣ��ͽ�������*/
	J1939_TP_RX,	/**< �����ݴ��䴦�ڽ���*/
	J1939_TP_TX,	/**< �����ݴ��䴦�ڷ���*/
	J1939_TP_OSBUSY,/**< �����ݴ��䴦�ڷ�æ������ս���һ���γ����ݣ�����CPUû���ô�������һ����������������Ϊ�����ݲ������ǣ���״̬��Ϊ��ֵ*/
}J1939_TP_State;
/**TP�ı�־λ�ṹ��
*
* ���ṹ���¼��TP��״̬��ʹ��TP���ͺͽ��ܵ�CANӲ�����
*/
typedef struct
{
	J1939_TP_State state;          /**< TP������״̬*/
	CAN_NODE       TP_RX_CAN_NODE; /**< TP������������� CANӲ�����*/
	CAN_NODE       TP_TX_CAN_NODE; /**< TP���ܷ��Ͳ����� CANӲ�����*/
}J1939_TP_Flags;
/**J1939��Ϣ����Ľṹ��
*
* ���ṹ��ʵ���� J1939����Ϣ����
*/
typedef struct
{
	j1939_uint32_t PGN ;  /**< J1939����Ϣ����� PGN*/
	j1939_uint8_t  data[J1939_TP_MAX_MESSAGE_LENGTH] ;/**< J1939����Ϣ����� ����*/
	j1939_uint16_t byte_count;/**< J1939����Ϣ����� ���ݴ�С*/
	j1939_uint8_t  SA;   /**< J1939����Ϣ����� Ŀ���ַ������Ŀ�ĵ�  ��  ������Դ�أ�*/

} J1939_MESSAGE_T ;
/**J1939��Ϣ����Ľṹ��
*
* ���ṹ��ʵ���� J1939�Ķ�֡��Ϣ����
*/
typedef struct
{
    j1939_uint8_t *data;        /**< ������ָ��*/
    j1939_uint16_t data_num;    /**< ��������С*/
    j1939_uint8_t SA;           /**< J1939����Ϣ����� ���� Դ��ַ*/
    j1939_uint16_t byte_count;  /**< J1939����Ϣ����� ���ݴ�С*/
    j1939_uint32_t PGN ;        /**< J1939����Ϣ����� PGN*/
}TP_RX_MESSAGE;
/**J1939_TP_Tx_Stepö��
*
* ʵ���˼�¼��֡����֡�������TX �Ĳ���
*/
typedef enum
{
	J1939_TP_TX_WAIT,
	J1939_TP_TX_CM_START,
	J1939_TP_TX_CM_WAIT,
	J1939_TP_TX_DT,
	J1939_TP_WAIT_ACK,
	J1939_TP_TX_ERROR,
	J1939_TX_DONE,
}J1939_TP_Tx_Step;//Э��ķ��Ͳ���
/**J1939_TRANSPORT_TX_INFO �ṹ��
*
* ʵ���˳�֡�����в�������ʱ���ݣ���һЩ���佻������
*/
typedef struct
{
	J1939_MESSAGE_T       tp_tx_msg;           /**< J1939����Ϣ����*/
	j1939_uint16_t        time;                /**< ʱ��*/
	j1939_uint8_t         packet_offset_p;     /**< ���ݰ�ƫ��ָ��*/
	j1939_uint8_t         packets_total;       /**< �ܹ��ж��ٸ����ݰ�*/
	j1939_uint8_t         packets_request_num; /**< �����͵����ݰ��������ܷ�׼�����ܵ����ݰ�����*/
	J1939_TP_Tx_Step      state ;              /**< Э��ķ��Ͳ���*/
} J1939_TRANSPORT_TX_INFO;
/**J1939_TP_Rx_Stepö��
*
* ʵ���˼�¼��֡����֡�������RX �Ĳ���
*/
typedef enum
{
	J1939_TP_RX_WAIT,
	J1939_TP_RX_READ_DATA,
	J1939_TP_RX_DATA_WAIT,
	J1939_TP_RX_ERROR,
	J1939_RX_DONE,
}J1939_TP_Rx_Step;//Э��Ľ��ղ���

/**J1939_TRANSPORT_RX_INFO �ṹ��
*
* ʵ���˳�֡�����в�������ʱ���ݣ���һЩ���佻������
*/
typedef struct
{
	J1939_MESSAGE_T    	 tp_rx_msg; /**< J1939����Ϣ����*/
	j1939_uint8_t		 osbusy;    /**< ��λ��1������ϵͳ��æ��cpu��Ҫ�������������ֱ�Ӿܾ�һ�е���������\n ������ڽ����У���λ��1����ᷢ�����ӱ�����Ϣ֡��*/
	j1939_uint16_t    	 time;		/**< ʱ��*/
	j1939_uint8_t        packets_total; /**< �ܹ��ж��ٸ����ݰ�*/
	j1939_uint8_t        packets_ok_num;/**< �Ѿ����ܵ����ݰ���*/
	J1939_TP_Rx_Step     state ;     /**< Э��Ľ��ܲ���*/
} J1939_TRANSPORT_RX_INFO;

#endif //J1939_TP_RX_TX

/**
* @note ʵ��Request_PGN ����Ӧ
*/
struct Request_List{
	j1939_uint8_t  *data;
	j1939_uint16_t lenght;
	j1939_uint32_t PGN;
	CAN_NODE       Can_Node;
	void (*update)();  /**< �ں�������Ҫ��data���£�������ø���data��ֵΪJ1939_NULL*/
	struct Request_List *next;   /**< ����ĩβ����Ҫһֱ����J1939_NULL*/
};

// J1939 Data Structures
// J1939_MESSAGE_STRUCTּ��J1939��Ϣ��ӳ�䵽�豸�ĵ�ַӳ�䡣 ֻ���ֶ�PDU��ʽ��ӳ�䵽�豸�Ĵ�����
// �ṹӦ�ü򵥵�ʹ��PDUFormat�ͺ���PDUFormat_Top���������������պʹ���֮ǰ��
// ע:�����������ṹ�ӵ�һ���λ�ø�һЩλ�ã����Կ��ܳ��ֲ�ƥ����豸�Ĵ�����
#define J1939_MSG_LENGTH	9  //��Ϣ����
#define J1939_DATA_LENGTH	8  //���ݳ���

/** J1939_MESSAGE_UNION �ṹ��
* ʵ����J1939��Ϣ����
*
*
*/
union J1939_MESSAGE_UNION
{
/** j1939 �� ID ��ɽṹ��
*
*/
	struct   j1939_PID
	{
		j1939_uint8_t	DataPage			: 1;  /**< ����ҳ*/
		j1939_uint8_t	Res					: 1;  /**< Resλ*/
		j1939_uint8_t	Priority			: 3;  /**< ���ȼ�*/
		j1939_uint8_t	Reserve				: 3;  /**< ����*/
		j1939_uint8_t	PDUFormat;				  /**< PF*/
		j1939_uint8_t	PDUSpecific; 			  /**< PS*/
		j1939_uint8_t	SourceAddress;            /**< SA*/
		j1939_uint8_t	DataLength 			: 4;  /**< ���ݳ���*/
		j1939_uint8_t	RTR					: 4;  /**< RTRλ*/
		j1939_uint8_t	Data[J1939_DATA_LENGTH];  /**< ����*/
		j1939_uint32_t  PGN					:24;  /**< ����Ⱥ���*/
		j1939_uint32_t  ReservePGN			: 8;  /**< ����*/
	};
	struct j1939_PID Mxe;  /**< j1939 �� ID ��ɽṹ��*/
	j1939_uint8_t		Array[J1939_MSG_LENGTH + J1939_DATA_LENGTH]; /**< ���������飬������ٴ����ṹ�帳ֵ*/
};

#define GroupExtension 		PDUSpecific
#define DestinationAddress 	PDUSpecific
/** һ���궨�壬�������������������
*
*/
typedef union J1939_MESSAGE_UNION J1939_MESSAGE;

union J1939_FLAGS_UNION
{
	struct
	{
		j1939_uint8_t	TransmitMessagesdCover				: 1;  //��������ʱ��J1939Э����ܻ��������ݸ���
		j1939_uint8_t	ReceivedMessagesdCoverOrDroppedNode	: 3;
		j1939_uint8_t	ReceivedMessagesdCover				: 1;  //��������ʱ��J1939Э����ܻ��������ݸ���
		j1939_uint8_t	ReceivedMessagesDropped				: 1;  //��������ʱ��J1939Э����ܻ������������
   };
	  j1939_uint8_t		FlagVal;
};

typedef union J1939_FLAGS_UNION J1939_FLAG;

/********************************************API**************************************************************/

//��ʼ������
extern void 			J1939_Initialization( );
//CAN�����շ��ж����
extern void			    J1939_ISR( );
//��������,��ʱ������
extern void 			J1939_Poll( );
//��ȡ��֡��Ϣ
extern j1939_uint8_t	J1939_Read_Message( J1939_MESSAGE *MsgPtr, CAN_NODE  _Can_Node);
//���͵�֡��Ϣ
extern j1939_uint8_t  	J1939_Send_Message( J1939_MESSAGE *MsgPtr, CAN_NODE  _Can_Node);
//��֡�����飩��Ϣ���ͺ���  (RTS/CTS����Э��)
extern j1939_int8_t 	J1939_TP_TX_Message(j1939_uint32_t PGN, j1939_uint8_t DA, j1939_uint8_t *data, j1939_uint16_t data_num, CAN_NODE  _Can_Node);
//��֡�����飩��Ϣ���ܺ���  (RTS/CTS����Э��)
extern j1939_int8_t 	J1939_TP_RX_Message(TP_RX_MESSAGE *msg, CAN_NODE _Can_Node);
//�����ȥһ��PGN
extern void             J1939_Request_PGN(j1939_uint32_t pgn ,j1939_uint8_t DA, CAN_NODE  _Can_Node);
//����һ��PGN��Ӧ
extern void             J1939_Create_Response(j1939_uint8_t data[], j1939_uint16_t dataLenght, j1939_uint32_t PGN, void (*dataUPFun)(), CAN_NODE  _Can_Node);


#endif //__J1939_H


