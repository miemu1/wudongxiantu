// fishroom.c
// 4/16/2000 by lag

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
���߽�����ۣ��кö�������������ѽ����ʱ�Ĵ�����
�ܵĺ���������϶�������˭�����˴��㣬��������ææµµ��
�˷ܵ����ӣ��㻹��ʲôֵ����ԥ�ģ��Ͽ���ʰ�������ܿ�ʼ
����(diao)�ɣ�������һ����Ϣ�ҡ�
LONG );
        set("exits", ([
//                "enter" : __DIR__"xiuxi",
                "west" : "d/shaolin/hanshui1",
        ]));
	set("item_desc", ([
		"�����͡�": "�����������("ZJURL("cmds:diao")ZJSIZE(15)""HIY"����"NOR")��������˾�("ZJURL("cmds:halt")ZJSIZE(15)""HIY"����"NOR")�ɡ�\n",
	]) );
        set("no_steal", 1);
        set("no_sleep", 1);
        set("no_drop", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_draw", "draw");
        add_action("do_fish", "diao");
}

int do_fish(string arg)
{

	object yr;
	object ob;
	object me = this_player();

        if (me->query("combat_exp") > 1000000) {
                message_vision(HIG"����ʹ�ߵ���ӰͻȻ������һ������֮�С�\n" +
            HIR "����ʹ�߳���$N��ȣ���ȥ�����ң���ô���˻������㣬���߲���ѽ��\n\n\n"NOR,me);
                    me->move("/d/shaolin/hanshui1");
                     return 1;
                                               } else
  //      if ( !arg || ( arg != "��" ) ) return
   //                notify_fail("��Ҫ��ʲô��?������\n");


	if (me->is_busy() || me->is_fighting())
		return notify_fail("�㻹��æ����ͷ�ϵ�������˵�ɡ�\n");

	message_vision("$N�ͳ�һ���������ϸ�ķ��ڵ����ϣ�����һ˦�ˣ�ֻ��ˮ���ϵ�����һ����ԲȦ���м�ֻ��һ����ɫ�ĸ���������ˮ��������\n", me);
	//yr->add_amount(-1);
	me->start_busy((: call_other, __FILE__, "finishing" :),
		       (: call_other, __FILE__, "halt_finishing" :));
	set_temp("owner", me);
	me->set_temp("fishing", 0);
	me->set_temp("pending/auto_diao",1);
	me->set_temp("fishing_env", environment(me));
	return 1;
}

int finishing(object me)
{
	int stage;

	if (environment(me) != me->query_temp("fishing_env"))
	{
		me->delete_temp("fishing");
		me->delete_temp("fishing_env");
		return 0;
	}

	switch (stage = me->query_temp("fishing"))
	{
	case 1:
		if (random(3))
		{
			tell_object(me,  "����������𶯣�һ��һ�µ�ҡ�θ���ͣ��\n");
			break;
		}
			tell_object(me,  "���Ӻ�Ȼ���ҵ���������\n");
		stage++;
		break;

	case 2:
	case 3:
			tell_object(me, "������Ȼ����һ�ܣ�Ȼ��������ˮ��\n");
		stage++;
		break;

	default:
		if (random(3))
		{
			if (random(2)) return 1;
			tell_object(me, random(2) ? "ˮ�沨��������û��ʲô�仯��\n"
						  : "΢������Ĵ���ˮ�浴��һ���ϸ�ˣ�����û�����Ϲ���\n");
			break;
		}
		tell_object(me,  "��Ȼ��ĸ�������һ�¡�\n");
		stage = 1;
		break;
	}

	me->set_temp("fishing", stage);
	if(me->query_temp("pending/auto_diao")&&stage==2&&random(3))
	{
		tell_object(me,ZJFORCECMD("draw"));
	}
	return 1;
}

int halt_finishing(object me)
{
	delete_temp("owner");
	me->delete_temp("fishing");
	message_vision("$N������ͣ��������ǲ����ٵ��ˡ�\n",  me);
	return 1;
}

void auto_fish(object me)
{
	if(!interactive(me)) return;
	if(me->is_busy())
		call_out("auto_fish",1,me);
	else
		tell_object(me,ZJFORCECMD("diao"));
}

int do_draw(string arg)
{
	string *fish;
	object ob;
	object me;
	int stage;
	int exp;
	int pot;

	me = this_player();


	if (environment(me) != me->query_temp("fishing_env"))
		return 0;

	stage = me->query_temp("fishing");
	if (stage < 2)
	{
		tell_object(me,  "����æһ�����ͣ��߸ߵľ���������ȴ�����������Ȼ�����������ӣ�ֻ�ô�ͷɥ�������°Ѹ�˦�˳�ȥ����\n");
		//message_vision("$N��æһ�����ͣ��߸ߵľ���������ȴ�����������Ȼ�����������ӣ�ֻ�ô�ͷɥ�������°Ѹ�˦�˳�ȥ��\n", me);
		me->set_temp("fishing", 0);
		return 1;
	}

	fish = environment(me)->query("resource/fish");
	tell_object(me,  "�ּ��ۿ죬�͵�һ�յ��ͣ�ֻ���������һ��Ť��Ťȥ��˳��һ���ˣ���ʱ��һ���������������\n");
	//message_vision("$N�ּ��ۿ죬�͵�һ�յ��ͣ�ֻ���������һ��Ť��Ťȥ��˳��һ���ˣ���ʱ��һ�������������\n", me);
	delete_temp("owner");
	me->delete_temp("fishing");
	me->delete_temp("fishing_env");
/*
	if (me->query("combat_exp") < 10000000 || me->query("combat_exp") > 180000)
	{
		call_out("auto_fish",1,me);
		return 1;
	}
*/
	exp = 300 + random(100);
	pot = exp / 2;
	me->add("combat_exp", exp);
	if (me->query("potential") < me->query_potential_limit())
		me->add("potential", pot);
		tell_object(me, HIC "\n������" + chinese_number(exp) + "����Ϊ��" + chinese_number(pot) + "��Ǳ�ܡ�"NOR"\n");
	//tell_object(me, HIC "������΢΢һ��������ѧ�����������һ�㡣"NOR"\n");
	call_out("auto_fish",1,me);
	return 1;
}