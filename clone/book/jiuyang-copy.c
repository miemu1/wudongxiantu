// jiuyang.c

inherit ITEM;
 
void create()
{
	set_name("��������¼��", ({ "jiuyang milu" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ���������ֳ����������ǲ�֪���˴����ֲؾ���͵͵��¼������һ�ž����书��\n");
		set("value", 10);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_put", 1);
		set("material", "paper");
		set("skill", ([
			"name"	: "jiuyang-shengong",
			"exp_required":  100000,
			"jing_cost"   :  120,
			"difficulty"  :  40,
			"max_skill"   :  180,
			"min_skill"   :  30,
		]) );
	}
}

int query_autoload() { return 1; }

