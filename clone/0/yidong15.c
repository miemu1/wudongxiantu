

inherit ITEM;

void create()
{
	set_name("迷宫第十五层", ({ "yingdong15"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是颗能传送("ZJURL("cmds:yidong lev15")ZJSIZE(15)""HIY"传送"NOR")到迷宫的宝珠。\n");
		set("value", 100);
		set("material", "stone");
				set("credit",250);

	}
	setup();
}



void init()
{
        add_action("do_go","yidong");
}

int do_go(string arg)
{
	string mapm;
	object *inv;
	int sizeinv;

	object me=this_player();

	while (sizeinv--)
	{
       	if (inv[sizeinv]->is_character())
     		return notify_fail("你背着人想给里面的怪物送点心去？\n");
	}
	if(arg=="lev15") {
		message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
		mapm="/d/migong/lev15/dong4";
		me->move(mapm);
		destruct(this_object());
	}
	return 1;
}