
inherit COMBINED_ITEM_BANG;
inherit F_LIQUID;

void create()
{
	set_name(HIY"̫������"NOR, ({"tai bai", "wine"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�Ƶľƺ�����\n");
		set("base_unit", "��");
		set("base_weight",300);
		set("unit", "��");
		set("base_value", 50000);
		set("max_liquid", 10);
		set("end",1);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "̫������",
		"bei": "����",
		
		"drunk_apply": 5,
	]));
	setup();
	set_amount(1);
}
