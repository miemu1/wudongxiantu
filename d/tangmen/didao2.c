//didao2.c		�Ĵ����š��ص�

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long",
"����һ���ص���������ȴ������һ����ͨ�ĵص������Ｋ�������\n"
"�м�ʮ������������Ϸʨ������������磬������ȴ�޷��ҵ����������\n"
"Դ���ص���ǰ���첻֪ͨ��δ��������������һ��Ī���Ŀ־壬������\n"
"���ĺá�\n"
);
	set("exits", ([
			"northup" : __DIR__"didao1",
			"southdown" : __DIR__"didao3",
	]));
	set("area", "����");
	setup();
}

void init()
{
	object me, killer;
	me = this_player();

	if ( wizardp(me) )
		return;

        if ( ( (string)me->query("family/family_name") == "��������" )  && me->query("family/master_id") == "tanglyz")
		return;
	else
	{
		if ( userp(me) )
		{
			message_vision("ͻȻ��ʯ���д���һ�����:���ô������ߣ���������\n", me);
			message_vision("�⻬��ʯ���ϳ�����һ��ʯ�ţ�һ��������ʿԾ�˳�������$N��������������\n", me);
			killer = new("/d/tangmen/npc/killer");
			killer->move(environment(me));
			killer->kill_ob(me);
			me->fight_ob(killer);
		}
	}
	return;
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if ( ((dir == "southdown")||(dir == "northup")) && objectp(present("killer", environment(me))) )
	{
                message_vision("��ʿһ�������������������ߣ�û��ô���ף�����\n", me);
		return notify_fail("\n");
	}
	return ::valid_leave(me, dir);
}
