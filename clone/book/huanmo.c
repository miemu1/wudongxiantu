// advance_dodge.c

inherit ITEM;

void create()
{
	set_name("幻魔身法", ({ "huanmo book", "book" }));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","封面上写著「幻魔身法」，曾经的绝版身法武功。\n");
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
