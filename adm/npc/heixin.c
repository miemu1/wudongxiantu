inherit NPC;

string ask_jiaoyi();
string ask_shangcheng();
string ask_huishou();
string ask_huan();
void create()
{
	set_name("��������", ({"heixin"}));
	set("long", "��ȫ����������Ӱ֮�£��޷����塣\n");
	set("combat_exp", 100000);
	set("age", 59);
	
	set("inquiry", ([
	//	"�����ס�" : (: ask_jiaoyi :),
		"���һ���" : (: ask_huan :),
		"�����ա�" : (: ask_huishou :),
		
		]));
	
	setup();
}

void init()
{
	add_action("do_heixin_jiaoyi", "heixin_jiaoyi");
	add_action("do_heixin_shop", "heixin_shop");
	add_action("do_duihuan", "duihuan");
}

string ask_shangcheng()
{
	this_player()->force_me("heixin_shop");
	return "";
}


string ask_huishou()
{
	this_player()->force_me("huishou");
	return "";
}

int do_heixin_shop(string arg)
{
	__DIR__"shop"->main(this_player(), arg);
	return 1;
}

string ask_jiaoyi()
{
	object who = this_player();
	
	if (who->query("yuanbao") < 100)
		return "�����ʯ������\n";
	else
	{
		write(ZJOBLONG + "��ȷ��Ҫ��100��ʯ���һ�500���ӣ�\n" + ZJOBACTS2 + "ȷ��:heixin_jiaoyi y\n");
		return "";
	}
}

int do_heixin_jiaoyi(string arg)
{
	object who = this_player();
	object money;
	
	if(arg != "y")
		return 1;
	
	if(who->query("combat_exp") < 1000000)
	{
	    write("�����Ϊ����100���޷��һ���\n");
		return 1;
	}
	
	if((who->query("heixin_time")/86400) != (time()/86400))
		who->delete("heixin_jiaoyi");
	
	if(who->query("heixin_jiaoyi"))
	{
	    write("������Ѿ��һ����ˣ��޷��ٴζһ���\n");
		return 1;
	}
	
	if (who->query("yuanbao") < 100)
	{
	    write("�����ʯ���㡣\n");
	    return 1;
	}
	
	if(who->query("heixin_jiaoyi") > 1)
		return 1;
	
	who->add("yuanbao", -100);
	money = new("/clone/money/gold");
	money->set_amount(500);
	money->move(who);
	write("�㻨����100��ʯ�һ���500���ӡ�\n");
	who->set("heixin_jiaoyi", 1);
	who->set("heixin_time", time());
	log_file("pay/duihuan", ctime(time()) + who->short() + "�һ��˻ƽ�\n");
	return 1;
}
















//�������һ�


string ask_huan()
{
	object me;
	string msg;

	me = this_player();

	msg = HIW "Ŀǰ�ṩ���³������һ���ʽ��" ZJBR
			  "һһһһһһһһһһһһһһһһһһһһһһһ" NOR "\n";
	msg += ZJOBACTS2 + ZJMENUF(3, 4, 9, 30);
	msg += sprintf(HIW "��Ʒ  " NOR "�һ�" + ZJBR + HIG "��Ʒ" NOR "  3��1 :%s" ZJSEP, "duihuan 1");
	msg += sprintf(HIW "��Ʒ  " NOR "�һ�" + ZJBR + HIR "��Ʒ" NOR "  5��1 :%s" ZJSEP, "duihuan 2");
	msg += sprintf(HIW "��Ʒ  " NOR "�һ�" + ZJBR + HIY "��Ʒ" NOR "  10��1 :%s" ZJSEP, "duihuan 3");

	msg += sprintf(HIG "��Ʒ  " NOR "�һ�" + ZJBR + HIW "��Ʒ" NOR "  1��2 :%s" ZJSEP, "duihuan 4");
	msg += sprintf(HIR "��Ʒ  " NOR "�һ�" + ZJBR + HIW "��Ʒ" NOR "  1��3 :%s" ZJSEP, "duihuan 5");
	msg += sprintf(HIY "��Ʒ  " NOR "�һ�" + ZJBR + HIW "��Ʒ" NOR "  1��6 :%s" ZJSEP, "duihuan 6");
	
	//msg += sprintf(HIY "��Ʒ  " NOR "�һ�" + ZJBR + HIW "200��ʯ" NOR "  7��1 :%s" ZJSEP, "duihuan 7");
	//msg += sprintf(HIY "��Ʒ  " NOR "�һ�" + ZJBR + HIW "200��ʯ" NOR "  5��1 :%s" ZJSEP, "duihuan 8");

	write(msg + "\n");
	return "�ã��㿴��������ô�һ���";
}

int do_duihuan(string arg)
{
	object me, ob1, ob2;
	string da, db, dname;
	int amount, i;
	me = this_player();

	amount = 1;
	i = 1;
	switch (arg)
	{
	case "1":
		da = "chongmai dan";
		db = "/clone/shizhe/dan_chongmai2";
		amount = 3;
		/* code */
		break;
	case "2":
		da = "chongmai dan";
		db = "/clone/shizhe/dan_chongmai3";
		amount = 5;
		/* code */
		break;
	case "3":
		da = "chongmai dan";
		db = "/clone/shizhe/dan_chongmai4";
		amount = 10;
		/* code */
		break;
	case "4":
		da = "chongmai dan2";
		db = "/clone/shizhe/dan_chongmai1";
		i = 2;
		/* code */
		break;
	case "5":
		da = "chongmai dan3";
		db = "/clone/shizhe/dan_chongmai1";
		i = 3;
		/* code */
		break;
	case "6":
		da = "chongmai dan4";
		db = "/clone/shizhe/dan_chongmai1";
		i = 6;
		break;
	case "7":
		da = "chongmai dan4";
		db = "/clone/yuanbaopiao2";
		amount = 7;
		break;
     case "8":
		da = "chongmai dan4";
		db = "/clone/yushipiao2";
		amount = 5;
		break;		
		
		
	
		
	default:
		break;
	}

	if (!objectp(ob1 = present(da, me)))
		return notify_fail("������û�����ֳ�������\n");
	if (amount > ob1->query_amount())
		return notify_fail("��û����ô���" + ob1->name() + "��\n");
	dname = ob1->name();

	ob1->set_amount((int)ob1->query_amount() - amount);

	ob2 = new (db);

	if (ob2->query_amount())
		ob2->set_amount(i);

	ob2->move(me);

	tell_object(me, "����" + chinese_number(amount) + "��" + dname + "�һ���" + chinese_number(i) + "��" + ob2->name() + "\n");

	call_out("ask_huan", 0.5, me);

	return 1;
}
