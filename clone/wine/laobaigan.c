
inherit COMBINED_ITEM_BANG;
inherit F_LIQUID;

void create()
{
	set_name(HIW"老白干"NOR, ({"lao baigan", "wine"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装酒的酒坛。\n");
		set("base_unit", "坛");
		set("base_weight",300);
		set("unit", "坛");
		set("base_value", 10000);
		set("max_liquid", 10);
		set("end",1);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "老白干",
		"bei": "暂无",
		
		"drunk_apply": 2,
	]));
	setup();
	set_amount(1);
}
