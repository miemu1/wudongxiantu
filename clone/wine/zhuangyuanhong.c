
inherit COMBINED_ITEM_BANG;
inherit F_LIQUID;

void create()
{
	set_name(HIR"�񻨾�̳"NOR, ({"zhuangyuan hong", "wine"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�Ƶľ�̳��\n");
		set("base_unit", "̳");
		set("base_weight",300);
		set("unit", "̳");
		set("base_value", 100);
		set("max_liquid", 10);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "״Ԫ��",
		"bei": "�Ŵɱ�",
		
		"drunk_apply": 8,
	]));
	setup();
	set_amount(1);
}
