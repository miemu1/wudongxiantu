#include "seed.h"

mapping seed_info = ([
	"name" : "С������",		//��������
	"id" : "xiaomai",			//����ID������Զ���" seed"
	"value" : 2000,			//���Ӽ�ֵ
	"mature_name" : "С��", //��������
	"time_need" : 2000,		//����ʱ��
]);

void create()
{
	create_seed(seed_info);
}