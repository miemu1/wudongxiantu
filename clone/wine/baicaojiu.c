
inherit COMBINED_ITEM_BANG;
inherit F_LIQUID;

void create()
{
	set_name(HIG"�ٲݾ�̳"NOR, ({"baicao jiu", "wine"}));
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
		"name": "�ٲݾ�",
		"bei": "���ٱ�",
		
		"drunk_apply": 6,
	]));
	setup();
	set_amount(1);

}
