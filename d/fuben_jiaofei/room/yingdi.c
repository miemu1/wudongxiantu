inherit ROOM;

void create()
{
	set("short", "Ӫ��");
	set("long", @LONG
Ϊ�˷��������ʱӪ�أ�ͨ��������С�
LONG);
	set("action_list", ([
		"����Ŀ¼" : "goto_city",
		"����ָ��" : "jiaofei",
		]));
	set("item_desc", ([
		"����˵��" : "��ɱ��ͽʱ��ȫ�ӳ�Ա����ͷ�ͽ��ͬһ����\n"
					  "��Ա�뿪�����ᵼ�¸�������\n"
					  "ʹ��׷ɱ��(�̳ǹ���)���Ի�÷�ͽλ��\n"
					  "ÿʮ�����һ����Ʒ���������ӳ���\n"
					  "ÿ����ʮ�����ٻ����ΪǱ��\n"
					  "��ͽ���Զ���ɱ���������\n",
		"���" : "�������ܵ��һ𰡣���һ�з��մ�����\n",
		]));
		
	setup();
}

void init()
{
	add_action("do_fuben_go", "fuben_go");
	add_action("do_goto_city", "goto_city");
}

int do_goto_city()
{
	int i;
	string area, str = "";
	mapping city;
	
	city = this_object()->query("fuben_exits");
	str += "����ȥ���\n" + ZJOBACTS2 + ZJMENUF(2,2,9,30);
	
	for(i = 0; i < sizeof(city); i++)
	{
		sscanf(city[sprintf("%d", i)], "/d/%s/%*s",area);
		str += MAP_D->query_map_short(area) + ":fuben_go " + i + ZJSEP;
	}
	
	tell_object(this_player(), ZJOBLONG + str +"\n");
	
	return 1;
}
int do_fuben_go(string arg)
{
	mapping exits;
	
	exits = this_object()->query("fuben_exits");
	
	if (!arg)
		return notify_fail("����ȥ���\n");
	
	if (exits[arg])
	{
		this_player()->move(exits[arg]);
		tell_object(this_player(), "��������" + exits[arg]->query("short") + "\n");
	}
	else
		return notify_fail("����ȥ���\n");
		
	return 1;
}