inherit ROOM;

void create()
{
	set("short", "���Է���");
	set("long", @LONG
���Է��䡣
LONG);
	set("is_huanjing", 1);
	set("item_desc", ([
		"����":"ǧ��Ҫ�ɳ�ȥ��Ҫ��Ȼ������úܲҡ�\n",
		]));

	set("action_list", ([
		"�뿪" : "likai",
		]));
	set("no_clean_up_fb", 1);
	setup();
}

void init()
{
	add_action("do_disable", ({"use", "fu", "eat", "exert", "fly", "walk", "flygo"}));
	add_action("do_likai", "likai");
}

int do_disable(string arg)
{
	object who = this_player();

	tell_object(who, "�����޷�ʹ�����ָ�\n");
	return 1;
}

int do_likai(string arg)
{
	if (!arg || arg == "")
	{
		write(ZJOBLONG + "��ȷ��Ҫ�뿪������\n" + ZJOBACTS2 + "ȷ��:likai y\n");
		return 1;
	}

	if (arg == "y")
	{
		query("mem")->end_fuben(query("mem"));
		return 1;
	}

	return 1;
}