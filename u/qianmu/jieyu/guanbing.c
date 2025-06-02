inherit NPC;

string ask_baoxin();

void create()
{
	set_name("�ٱ�", ({"guan bing"}));
	set("long", "����������Ĺٱ���\n");
	set("gander", "����");
	set("combat_exp", 1000000);

	set("inquiry", ([
		"ͨ�籨��":(: ask_baoxin :),
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
			write("��������ϵ����Ա����\n");
			return 1;
		}

		player = filter_array(all_inventory(room), (: ($1)->query_temp("link_ob") && userp($1) && ($1)->query_time_to_leave() > 1 :));

		if (!sizeof(player))
		{
			write("���ڼ�������û����ѽ��\n");
			return 1;
		}

		foreach (temp in player)
		{
			str += temp->query("name") + ":jieyu " + temp->query("id") + ZJSEP;
		}

		write(ZJOBLONG + "����Ҫ��˭ͨ�籨�ţ�\n" + ZJOBACTS2 + str + "\n");
		return 1;
	}

	if (sscanf(arg , "%s %s", player_id, sign) != 2)
	{
		write(ZJOBLONG + "��ȷ��Ҫ��" + find_player(arg)->query("name") + "ͨ�籨����\n" + ZJOBACTS2 + "ȷ��:jieyu " + arg + " y\n");
		return 1;
	}

	if (!sign || sign != "y")
	{
		write("�����������������롣\n");
		return 1;
	}

	if (who->query("yuanbao") < 200)
	{
		write("�����ʯ����200��\n");
		return 1;
	}

	mem = new(__DIR__"mem");
	mem->set("player_id", player_id);
	if (!mem->start_jieyu(find_player(player_id)))
	{
		write("��ʼ����������ϵ����Ա����\n");
		return 1;
	}
	
	who->add("yuanbao", -200);

	return 1;
}