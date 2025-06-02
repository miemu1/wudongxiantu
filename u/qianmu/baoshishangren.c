inherit NPC;

string ask_sell_gem();
string ask_buy_gem();

void create()
{
	set_name("��ʯ����", ({ "baoshi shangren" }));
	set("long", "��ʯ���ˡ�\n");
	set("gender", "����");
	set("combat_exp", 100000);

	set("inquiry", ([
		"���۱�ʯ" : (: ask_sell_gem :),
		"����ʯ" : (: ask_buy_gem :),
		]));

	setup();
}

string ask_sell_gem()
{
	object who = this_player();

	who->force_me("sell_gem");

	return "";
}

string ask_buy_gem()
{
	object who = this_player();

	who->force_me("buy_gem");

	return "";
}

void init()
{
	add_action("do_buy_gem", "buy_gem");
	add_action("do_sell_gem", "sell_gem");
}

int do_sell_gem(string arg)
{
	object who = this_player();
	object * gem_list;
	object temp;
	string str;
	string gem_object;
	object gem;
	int amount;
	string sign;

	if (!arg || arg == "")
	{
		gem_list = filter_array(all_inventory(who), (: ($1)->query("can_be_inlay") :));

		if (!sizeof(gem_list))
		{
			tell_object(who, "�������û�б�ʯ����\n");
			return 1;
		}
		else
		{
			str = ZJOBLONG + "��������ʲô��ʯ��\n" + ZJOBACTS2;
			foreach(temp in gem_list)
			{
				str += temp->query("name") + ":sell_gem " + file_name(temp) + ZJSEP;
			}

			tell_object(who, str + "\n");
			return 1;
		}
	}

	if (sscanf(arg, "%s %d %s", gem_object, amount, sign) == 3)
	{
		if ("y" != sign)
		{
			tell_object(who, "��������������������롣\n");
			return 1;
		}

		if (!objectp(gem = find_object(gem_object)) && environment(gem) == who)
		{
			tell_object(who, "���㲽���������ϵ����Ա����\n");
			return 1;
		}

		if (!gem->query("can_be_inlay"))
		{
			tell_object(who, "�ⶫ�����Ǳ�ʯ����\n");
			return 1;
		}

		if (amount > gem->query_amount())
		{
			tell_object(who, "��û����ô���" + gem->query("name") + "����\n");
			return 1;
		}

		tell_object(who, "�������" + amount + "��" + gem->query("name") + "\n");
		log_file("gem/sell", ctime(time()) + who->query("name") + "(" + who->query("id") + ")������" + amount + "��" + gem->query("name") + "��\n");
		gem->add_amount(-amount);
		who->add("gem_duihuan", amount);

		return 1;
	}

	if (sscanf(arg, "%s %s", gem_object, sign) == 2 && "piliang" == sign)
	{
		if (!objectp(gem = find_object(gem_object)) && environment(gem) == who)
		{
			tell_object(who, "�������۳�������ϵ����Ա����\n");
			return 1;
		}

		tell_object(who, INPUTTXT("��Ҫ���۶��ٸ�" + gem->query("name") + "��", "sell_gem " + gem_object + " $txt#") + "\n");
		return 1;
	}

	if (sscanf(arg, "%s %d", gem_object, amount) == 2)
	{
		if (!objectp(gem = find_object(gem_object)) && environment(gem) == who)
		{
			tell_object(who, "ȷ�ϲ����������ϵ����Ա����\n");
			return 1;
		}

		if (amount < 1)
		{
			tell_object(who, "������һ������һ������\n");
			return 1;
		}

		tell_object(who, ZJOBLONG + "��ȷ��Ҫ����" + amount + "��" + gem->query("name") + "��\n" + ZJOBACTS2 + "ȷ��:sell_gem " + gem_object + " " + amount + " y\n");
		return 1;
	}

	if (sscanf(arg, "%s", gem_object) == 1)
	{
		if (!objectp(gem = find_object(gem_object)) && environment(gem) == who)
		{
			tell_object(who, "��������ϵ����Ա����\n");
			return 1;
		}

		tell_object(who, ZJOBLONG + "������ӵ��" + gem->query_amount() + "��" + gem->query("name") + "��\n" + ZJOBACTS2 + 
						"����һ��:sell_gem " + gem_object + " 1" + ZJSEP + "��������:sell_gem " + gem_object + " piliang\n");
		return 1;
	}

	return 1;
}

int do_buy_gem(string arg)
{
	object who = this_player();
	string * gem_list;
	string temp;
	string gem_file;
	string sign;
	object gem;
	string str;

	if (!arg || arg == "")
	{
		str = ZJOBLONG + "��������" + who->query("gem_duihuan") + "��ʯ�һ�����Ҫ�һ�ʲô��ʯ��\n" + ZJOBACTS2;

		gem_list = list_dirs("/clone/gem/*.c");
		foreach(temp in gem_list)
		{
			str += load_object("/clone/gem/" + temp)->query("name") + ":buy_gem /clone/gem/" + temp + ZJSEP;
		}

		tell_object(who, str + "\n");
		return 1;
	}

	if (sscanf(arg, "%s %s", gem_file, sign) != 2)
	{
		tell_object(who, ZJOBLONG + "��ȷ��Ҫ�һ�" + load_object(arg)->query("name") + "��\n" + ZJOBACTS2 + "ȷ��:buy_gem " + arg + " y\n");
		return 1;
	}
	else
	{
		if (sign != "y")
		{
			tell_object(who, "����������������ԡ�\n");
			return 1;
		}

		if (who->query("gem_duihuan") < 5)
		{
			tell_object(who, "��ı�ʯ�һ��������š�\n");
			return 1;
		}

		if (!objectp(gem = new(gem_file)))
		{
			tell_object(who, "���Ʊ�ʯ��������ϵ����Ա����\n");
			return 1;
		}

		if (!gem->query("can_be_inlay"))
		{
			tell_object(who, "�ⶫ�����Ǳ�ʯ����\n");
			destruct(gem);
			return 1;
		}

		tell_object(who, "���������ʯ�һ���ͱ�ʯ���˶һ���" + gem->query("name") + "��\n");
		log_file("gem/buy", ctime(time()) + who->query("name") + "(" + who->query("id") + ")�һ���" + gem->query("name") + "��\n");
		who->add("gem_duihuan", -5);
		gem->move(who);
	}

	return 1;
}