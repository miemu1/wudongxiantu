// huanshou_di.c

inherit ITEM;

void create()
{
	set_name("������",({ "shou shao", "shao" }) );
	set_weight(1);
	set("no_sell", "���ǻ��޵Ļ������������ġ�\n");
	set("no_drop", "�������������뿪�㡣\n");
	set("no_give","�ⶫ�������Ը����ˡ� \n");
	set("no_put",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 10);
		set("material", "bamboo");
		set("long", "�����ٻ�����ʹ�õ����ӡ�\n");
	}
	setup();
}

