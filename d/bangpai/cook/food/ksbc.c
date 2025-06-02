#include "food.h"

mapping food_info = ([
	"name" : "��ˮ�ײ�",
	"id" : "ksbc",
	"need" : (["baicai" : 5,]),
	"time" : 300,
	"unit" : "��",
	]);

void create()
{
	create_food(food_info);
}

int add_buff(object who)
{
	who->set_temp("eat_food", 1);
	who->add_temp("apply/damage", 50);
	who->add_temp("apply/unarmed_damage", 50);
	who->add_temp("apply/attack", 50);
	tell_object(who, "������˿�ˮ�ײˣ����50�����ӳɡ�\n");
	return 1;
}

void remove_buff(object who)
{
	who->delete_temp("eat_food");
	who->add_temp("apply/damage", -50);
	who->add_temp("apply/unarmed_damage", -50);
	who->add_temp("apply/attack", -50);
	tell_object(who, "�����ʳ�����ӵ�buff��ʧ�ˡ�\n");
}