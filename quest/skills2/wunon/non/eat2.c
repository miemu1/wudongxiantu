// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���ܲ�", ({ "carrot" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����죬�����ִ�ĺ��ܲ�\n");
		set("unit", "��");


		set("value", 350);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
