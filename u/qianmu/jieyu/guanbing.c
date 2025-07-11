inherit NPC;

string ask_baoxin();

void create()
{
	set_name("官兵", ({"guan bing"}));
	set("long", "这是衙门里的官兵。\n");
	set("gander", "男性");
	set("combat_exp", 1000000);

	set("inquiry", ([
		"通风报信":(: ask_baoxin :),
		]));

	setup();
}

void init()
{
	add_action("do_jieyu", "jieyu");
}

string ask_baoxin()
{
	object who = this_player();

	who->force_me("jieyu");
	return "";
}

int do_jieyu(string arg)
{
	object who = this_player();
	object * player;
	object room;
	object temp;
	string str = "";
	string player_id;
	string sign;
	object mem;

	if (!arg || arg == "")
	{
		if (!objectp(room = load_object("/d/changan/prison")))
		{
			write("出错，请联系管理员处理。\n");
			return 1;
		}

		player = filter_array(all_inventory(room), (: ($1)->query_temp("link_ob") && userp($1) && ($1)->query_time_to_leave() > 1 :));

		if (!sizeof(player))
		{
			write("现在监狱里面没有人呀。\n");
			return 1;
		}

		foreach (temp in player)
		{
			str += temp->query("name") + ":jieyu " + temp->query("id") + ZJSEP;
		}

		write(ZJOBLONG + "你想要给谁通风报信？\n" + ZJOBACTS2 + str + "\n");
		return 1;
	}

	if (sscanf(arg , "%s %s", player_id, sign) != 2)
	{
		write(ZJOBLONG + "你确定要给" + find_player(arg)->query("name") + "通风报信吗？\n" + ZJOBACTS2 + "确定:jieyu " + arg + " y\n");
		return 1;
	}

	if (!sign || sign != "y")
	{
		write("参数错误，请重新输入。\n");
		return 1;
	}

	if (who->query("yuanbao") < 200)
	{
		write("你的灵石不足200。\n");
		return 1;
	}

	mem = new(__DIR__"mem");
	mem->set("player_id", player_id);
	if (!mem->start_jieyu(find_player(player_id)))
	{
		write("初始化错误，请联系管理员处理。\n");
		return 1;
	}
	
	who->add("yuanbao", -200);

	return 1;
}