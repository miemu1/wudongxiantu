// advance_dodge.c

inherit ITEM;

void create()
{
	set_name("��ħ��", ({ "huanmo book", "book" }));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","������д������ħ�����������ľ������书��\n");
		set("material", "paper");
		set("skill", ([
			"name": 	"huanmo-shenfa",
			"exp_required":	1000,
			"jing_cost":	30,
			"difficulty":	25,
			"max_skill":	180,
            //"min_skill":    20,
		]));
	}
}
