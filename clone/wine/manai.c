
inherit COMBINED_ITEM_BANG;
inherit F_LIQUID;

void create()
{
	set_name(HIW"马奶酒壶"NOR, ({"ma nai", "wine"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装酒的酒壶·。\n");
		set("base_unit", "壶");
		set("base_weight",300);
		set("unit", "壶");
		set("base_value", 20000);
		set("max_liquid", 10);
		set("end",1);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "马奶酒",
		"bei": "暂无",
		
		"drunk_apply": 3,
	]));
	setup();
	set_amount(1);
}
