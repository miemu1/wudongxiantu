//luoyun 2016.7.14

inherit ROOM;

void create()
{
    set("short", "��̨");
    set("long", @LONG
����! ����! ����! ����! ����! ����! ����! ����! ����! ����! 
LONG 
    );
	/*
    set("exits", ([ 
        "down" : __DIR__"duobaoleitai",	
    ]));
	*/
	set("no_new_clean_up", 0);
	set("type", "yuanbao");
	set("fight_room", __DIR__"shangjinleitai");	//������һ��Ժ��Ƶ��÷���
	set("no_sleep_room",1);
	set("action_list", ([
		"�뿪":"outleitai",
	]));
	setup();
}
void init()
{
	add_action("out_leitai","outleitai");  
	
	remove_call_out("out_time");
	call_out("out_time", 180);
}
void out_time()
{
	object *obs, ob;
	int k, unit;
	
	obs = all_inventory(this_object());
	foreach(ob in obs) {
		if (userp(ob))
		{
			unit = ob->query("bet/yuanbao/unit");
			if (unit > 1) {
				ob->add("yuanbao", unit);
				ob->delete("bet/yuanbao/unit");
				tell_object(ob, ("ϵͳ�˻�����ʯ��"+unit+"��\n"));
			}
			if (ob->move("/d/city/shangjinleitai"))  {
				ob->set_temp("biwu_time", time() + 10);
				tell_object(ob, "�㳬ʱ��ϵͳ�Զ���������̨��\n");
			} else
				k++;
		}
	}
	if (k > 0) {
		remove_call_out("out_time");
		call_out("out_time", 5);
	}
}
/*
void relay_message(string msg)
{
	object look_fight_room;
	string *msgs;
	int i;

	if (!look_fight_room=find_object(__DIR__"duobaoleitai"))
		look_fight_room=load_object(__DIR__"duobaoleitai");
	msgs=explode(msg, "\n");
    for (i=0;i<sizeof(msgs);i++)
    if (strlen(msgs[i])>5)
	message("vision",NOR+"@@ -->"+msgs[i]+"\n",look_fight_room);
}*/
int out_leitai(string arg)
{
	object me = this_player();
	string str;
	int unit;
	
	if (me->is_fighting())
		return notify_fail("�������ӣ��Ǵ��ɷ���Ϊѽ��\n");
	
	if (me->is_busy())
		return notify_fail("����æ�أ�\n");
	
	if (!arg || sscanf(arg, "%s", arg) != 1) {
		str = sprintf("%s", "�뿪��̨:outleitai yes" + ZJSEP);
		str += sprintf("%s", "ȡ���뿪:outleitai no");
		tell_object(me, ZJOBLONG + "\n"+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
		return 1;
	}
	if (arg == "yes") {
		unit = me->query("bet/yuanbao/unit");
		if (unit >= 1) {
			//unit = unit /100 * 99;
			me->add("yuanbao", unit);
			me->delete("bet/yuanbao/unit");
			tell_object(me, ("ϵͳ�˻�����ʯ��"+unit+"��\n"));
		}
		tell_object(me, ("������뿪��̨��\n"));
		me->set_temp("biwu_time", time() + 10);
		me->move("/d/city/shangjinleitai");
	} else
	{
		tell_object(me, "���������������̨�ϡ�\n");
	}
	
	return 1;
}
