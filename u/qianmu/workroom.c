inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "������\n");

	set("action_list", ([
		"����" : "test",
		]));

	set("item_desc", ([
		"������" : "�������͹������������������鿴������Ϣ��\n"
					"���Ի�����������ң������Լ���\n" 
					"ֻ�����ߵ���Ҳſ��Ա����͡�\n" + 
					ZJOBACTS2 + "������Ϣ:look_board" + ZJSEP + "�������:xuanshang\n",
		]));

	set("objects", ([
		__DIR__"/xuanshang/board" : 1,
		]));
	
	setup();
}

void init()
{
	add_action("do_test", "test");
	add_action("do_dest_item", "dest_item");
	add_action("do_xuanshang", "xuanshang");
	add_action("do_look_board", "look_board");
	add_action("do_jiebang", "jiebang");
}

#define XUANSHANGD "/adm/daemons/xuanshangd"
#define ORDER "/clone/xuanshang/xuanshang_order"

// void init()
// {
// 	add_action("do_xuanshang", "xuanshang");
// 	add_action("do_look_board", "look_board");
// 	add_action("do_jiebang", "jiebang");
// }

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
			tell_object(who, "�����Ŀǰ���ڽ���֮�С�\n");
			return 1;
		}
		else
		{
			tell_object(who, INPUTTXT("��Ŀǰ��" + (who->query("balance") / 10000) + "���ƽ����Ҫ����" + target->query("name") + "���ٽ���?", "xuanshang " + arg + " $txt#") + "\n");
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

		if (who->query("balance") < amount * 10000)
		{
			tell_object(who, "��Ĵ���" + amount + "���ƽ�\n");
			return 1;
		}

		target = find_player(arg);
		if (!target || !userp(target))
		{
			tell_object(who, "�����Ŀǰ���ڽ���֮�С�\n");
			return 1;
		}
		else
		{
			who->add("balance", -amount * 10000);
			if (XUANSHANGD->add_xuanshang(target->query("id"), amount))
			{
				log_file("xuanshang/pay", ctime(time()) + who->query("name") + "(" + who->query("id") + ")����" + amount + "��������" + target->query("name") + 
					"(" + target->query("id") + ")��Ŀǰ�ܼ�" + XUANSHANGD->get_xuanshang()[target->query("id")][1] + "�ƽ�\n");
				tell_object(who, "�㻨��" + amount + "��������" + target->query("name") + "��\n");
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

		if (present(id + "-order", who))
		{
			tell_object(who, "��������Ѿ�������������ˡ�\n");
			return 1;
		}

		if (!objectp(order = new(ORDER)))
		{
			tell_object(who, "��������ϵ����Ա����\n");
			return 1;
		}

		order->set("xuanshang_id", id);
		order->set("xuanshang_name", xuanshang[id][0]);
		order->set_name(xuanshang[id][0] + "������", ({ id + "-order" }));
		order->move(who);
		tell_object(who, "�������" + xuanshang[id][0] + "�������\n");

		return 1;
	}
}

















int do_test(string arg)
{
	object who = this_player();
    object room;

mapping id = ([

"1�˺�" : "micen",
"2�˺�" : "dysy2123",
"3�˺�" : "qlili",
"4�˺�" : "yeluo1435",
"5�˺�" : "jijiu3279465885",
"6�˺�" : "apollo",
"7�˺�" : "sorryo",
"8�˺�" : "q929733198",
"9�˺�" : "qq3522246229",
"10�˺�" : "whz520",
"11�˺�" : "array",
"12�˺�" : "wana",
"13�˺�" : "a947456225",
"14�˺�" : "a15112695790",
"15�˺�" : "tashuone",
"16�˺�" : "zxc2580",
"17�˺�" : "wjxzw12345",
"18�˺�" : "lza0823",
"19�˺�" : "qwouvst",
"20�˺�" : "zxc555",
"21�˺�" : "li812939754",
"22�˺�" : "pppppppppppp",
"23�˺�" : "xxxxxx",
"24�˺�" : "momo5201314",
]);
    string temp;

    foreach(temp in values(id))
    {
        log_file("id_buchang", "\"" + temp + "\",\n");
    }


    
	// who->start_busy((: call_other, __FILE__, "start" :),
	// 				(: call_other, __FILE__, "end" :));
    //room = new("/d/jingjichang/room");
    //who->move(room);
	//"/d/fuben_huanjing/huanjing"->start_fuben(who);
	return 1;
}

int start()
{
	return 1;
}

int end()
{
	write("��ֹͣ�ˡ�\n");
	return 1;
}

int do_dest_item(string arg)
{
    object * obs;
    object temp;
    
    obs = children(arg);
    foreach(temp in obs)
    {
        log_file("xxxxxxxxx", "�������" + sprintf("%O\n",all_inventory(temp)) + "��\n");
        
        //temp->end_fuben_moku();
        //destruct(temp);
    }
}