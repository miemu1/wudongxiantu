inherit COMBINED_ITEM;

/*
mapping seed_info = ([
	"name" : "����",		//��������
	"long" : "������\n",	//��������
	"id" : "seed",			//����ID
	"value" : 1,			//���Ӽ�ֵ
	"mature_name" : "��", //��������
	"mature" : 0,			//�������·��
	"time_need" : 0,		//����ʱ��
]);*/

void create_seed(mapping seed_info)
{
	set_name(seed_info["name"], ({seed_info["id"] + " seed"}));
	set("long", "����һ��" + seed_info["name"] + "��\n");
	set("base_unit", "��");
	set("base_value", seed_info["value"]);
	set("base_weight", 1);
	set("seed_info", ([
		"mature_name" : seed_info["mature_name"],
		"mature" : __DIR__"veg/" + seed_info["id"],
	]));
	set("time_need", seed_info["time_need"]);
		
	set("seed", 1);
	set_amount(1);
	setup();
}

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}