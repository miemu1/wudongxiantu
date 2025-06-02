inherit ROOM;

void create()
{
	set("short", "����㳡");
	set("long", @LONG
�����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������һ�ô��������ݴ�����ǧ������䣬���������е���ʷ��֤�����ɵײ���һ���ܴ�
��������
LONG );
	set("no_sleep_room",1);
	set("outdoors", "city");
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/tiaoz1" : 1,	
	]));
	set("item_desc", ([
		"��������" : "����һ���ڲ����еĴ󶴣����治֪����Щʲô�Ź֡�\n"
		ZJOBACTS2"�궴:enter dong\n",
		"�����桿" :HIY"��ӭ�����䶯��;��

1.�����ǵ��Ҹ�ʦ��Ŷ����סһ��Ҫ��ʦ��QQ�������û���һֱ��ʦ����ʦ������������ʽ𣬺�һЩ�������ʣ��ǵ�ллʦ����
Ȼ���Ⱥqq537803188������Ⱥ�￴�����ԣ�����������ҡ�

2.�ս�����Ϸ���㣬���������ѶȺܸߣ�������Ϊ�����Ϸ���ų����ߵ����ɶȣ�ֻҪ���������о�����֤��ᷢ��һ��ȫ�µ��������磡��

3.���߹һ����ģ������߹һ��ڡ�������ջ���ұߣ��ǵ����������ߣ�����ʱ�����ռ���Ϊ�ˡ�

4.�ǵü�Ⱥ���䶯��;��qq537803188"NOR"\n",
	//	 "����":HIR"ѪɫȾ�������\n"HIY"��������������߿�����ǿ��ִ�\n"HIM"Ȼ�ţ����տݹǱ������Ի֪����Ȫ�ԣ����䣬�²��ڣ��˴Ӱ������ǣ���������������춰������Ǻβ� ���������������ĭ�����������ڽ����������������ǿ�������"NOR"\n"ZJOBACTS2"�鿴����:lunsword\n",
		 "�����͡�" : "�������͹������������������鿴������Ϣ��\n"
					"���Ի�����������ң������Լ���\n" 
					"ֻ�����ߵ���Ҳſ��Ա����͡�\n" + 
					ZJOBACTS2 + "������Ϣ:look_board" + ZJSEP + "�������:xuanshang\n",					
	]));

	set("exits", ([
		"northeast" : __DIR__"shengxiantang",
		"northwest" : __DIR__"banghui",
		"southeast" : "/d/migong/migong1",
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
		"southwest" : __DIR__"lajichang",
		"up" : __DIR__"shiji",

	]));

	

	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_xuanshang", "xuanshang");
	add_action("do_look_board", "look_board");
	add_action("do_jiebang", "jiebang");
}

#define XUANSHANGD "/adm/daemons/xuanshangd"
#define ORDER "/clone/xuanshang/xuanshang_order"

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

int do_enter(string arg)
{
	object me;
	me = this_player();

	if (! arg || arg == "")
		return 0;

	if (arg == "dong")
	{
		if (me->is_busy())
			return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

		message("vision",
			me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
		me->move("/d/gaibang/inhole");
		message("vision",
			me->name() + "�Ӷ������˽�����\n",
			environment(me), ({me}) );
		return 1;
	}
}       
