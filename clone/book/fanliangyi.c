// yljianpu.c

inherit ITEM;

void create()
{
        set_name("�����ǵ���", ({ "shu", "book" }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�������ǵ��ף����ⲻ�ϴӷ�����͸����\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name": "fanliangyi-dao",  //name of the skill
			"exp_required": 200000 , //minimum combat experience required
			"jing_cost": 20+random(20),// jing cost every time study this
			"difficulty":	30,	// the base int to learn this skill
			"max_skill":	180,	// the maximum level you can learn
			"min_skill":	1	// the minimum level you can learn
		]) );
	}
}
