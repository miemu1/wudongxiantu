#define XUANSHANGD "/u/qianmu/xuanshang/xuanshangd"

void init()
{
	add_action("do_xuanshang", "xuanshang");
	add_action("do_look_board", "look_board");
	add_action("do_jiebang", "jiebang");
}

int do_xuanshang(string arg)
{
	object who = this_player();
	object target;
	int amount;

	if (arg == "" || !arg)
	{
		tell_object(who, INPUTTXT("��Ҫ����˭��(����ID)", "xuanshang $txt#") + "\n");
		return 1;
	}

	if (sscanf(arg, "%s %d", arg, amount) != 2)
	{
		target = find_player(arg);
		if (!target || !userp(target))
		{
			tell_object(who, "�����Ŀǰ����ʱ�뿪������\n");
			return 1;
		}
		else
		{
			tell_object(who, INPUTTXT("��Ҫ����" + target->query("name") + "���ٽ���?", "xuanshang " + arg + " $txt#") + "\n");
			return 1;
		}
	}
	else
	{
		if (amount <= 0)
		{
			tell_object(who, "����������������\n");
			return 1;
		}

		target = find_player(arg);
		if (!target || !userp(target))
		{
			tell_object(who, "�����Ŀǰ����ʱ�뿪������\n");
			return 1;
		}
		else
		{

			if (XUANSHANGD->add_xuanshang(target->query("id"), amount))
			{
				tell_object(who, "�㻨��" + amount + "��������" + target->query("name") + "\n");
				return 1;
			}
			else
			{
				tell_object(who, "���ͳ�������ϵ����Ա����\n");
				return 1;
			}

			return 1;
		}
	}

	return 1;
}

int do_look_board(string arg)
{
	object who = this_player();
	string temp;
	string str = "";
	mapping xuanshang;

	if (!sizeof(xuanshang = XUANSHANGD->get_xuanshang()))
	{
		tell_object(who, "Ŀǰ������û�б����͵��ˡ�\n");
		return 1;
	}

	foreach (temp in keys(xuanshang))
	{
		str += xuanshang[temp][0] + "(" + xuanshang[temp][1] + ")" + ":jiebang " + temp + ZJSEP;
	}

	if (str == "")
		tell_object(who, ZJOBLONG + "Ŀǰ������û�б����͵��ˡ�\n");
	else
		tell_object(who, ZJOBLONG + "Ŀǰ�����б����͵����У�\n" + ZJOBACTS2 + str + "\n");

	return 1;
}

int do_jiebang(string arg)
{
	object who = this_player();

	string id;
	string sign;
	object order;
	mapping xuanshang;

	xuanshang = XUANSHANGD->get_xuanshang();
	
	if (sscanf(arg, "%s %s", id, sign) != 2)
	{
		if (undefinedp(xuanshang[arg]))
		{
			tell_object("Ŀǰû������������\n");
			return 1;
		}

		tell_object(who, ZJOBLONG + "��Ҫ����" + xuanshang[arg][0] + "����������\n" + ZJOBACTS2 + "ȷ��:jiebang " + arg + " y\n");
		return 1;
	}
	else
	{
		if (sign != "y")
		{
			tell_object(who, "��������������������롣\n");
			return 1;
		}

		if (undefinedp(xuanshang[id]))
		{
			tell_object("Ŀǰû������������\n");
			return 1;
		}

		if (!objectp(order = new(__DIR__"xuanshang_order")))
		{
			tell_object(who, "��������ϵ����Ա����\n");
			return 1;
		}

		order->set("xuanshang", id);
		order->set_name(xuanshang[id][0] + "������", ({ id + "-order" }));
		order->move(who);
		tell_object(who, "�������" + xuanshang[id][0] + "�������\n");

		return 1;
	}
}