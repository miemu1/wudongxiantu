#include "seed.h"

mapping seed_info = ([
	"name" : "�Ͳ�����",		//��������
	"id" : "baicai",			//����ID������Զ���" seed"
	"value" : 1000,			//���Ӽ�ֵ
	"mature_name" : "�Ͳ�", //��������
	"time_need" : 1800,		//����ʱ��
]);

void create()
{
	create_seed(seed_info);
}