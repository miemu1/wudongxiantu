// work.c modified by snow
#include <ansi.h>
inherit ROOM;

int cot;
void create()
{
	set("short", "����ӹ���");
	set("long", @LONG
����һ�����ӹ����������ǹ����ѿǳ��׵ĵط����׳��ϰ���һ
��һ����֪����ʮ�־����ĸ��ݵ������ˣ����Ǵ���һ����Ц�������
�������������ææµµ�Ĺ����ţ��ſڹ���һ������(sign)��
LONG
	);
	set("no_sleep_room",1);
	set("no_fight",1);	
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"beidajie1",
	]));
	set("item_desc", ([
		"����ʾ��": "���������ֽ�ȱ�������Ӷһ���̹����ɻ�Ͻ�work����ʼ�����ɣ�\n"
		ZJOBACTS2"��ʼ��:work auto\n",
	]) );
	set("no_magic", 1);
	setup();
}
void init()
{
	add_action("do_work", "work");
	if (!wizardp(this_user()))
	add_action("discmds",({"duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","fly","scribe","surrender"}));
}
int discmds()
{
	tell_object(this_player(),"��������ʵʵ�����ɣ���\n");
	return 1;
}
int do_work(string arg)
{
	int time;
	object me;
	me = this_player();

	time = 100/(int)me->query("str");
	if (time <15) time = 15;

//	if (me->query("combat_exp") > 5000000)
//		return notify_fail("�������Ҳ̫�������˰ɡ�\n");

	if (me->query_temp("job/step"))
		return notify_fail("�Ͻ��ɻ�ɣ�˭�������أ�\n");
	if( me->is_net_dead())
        return notify_fail("�㲻����ʹ����������\n");

	if ((int)me->query("jing")<30 || (int)me->query("qi")<30) return notify_fail("��������ˣ�ҪǮ��Ҫ������\n");

	if (cot>22) {
		write("�ϰ�ٺ�һЦ�������������Ѿ����ˣ����幤��û��Ǯ��Ӵ��\n");
		me->start_busy(4);
		return 1;
	}

	if ((int)me->query("jing")<10 || (int)me->query("qi")<10)
	{
		message_vision("$N��ʼ����ع���......\n", me);
		write("��ͻȻ�е�ͷ���ۻ�������������\n");
		tell_room(environment(me), RED+me->name() +"��ɫ�����������ͷ������ĺ�������ϻ���������\n��,����һ��ҪǮ��Ҫ����..!"NOR"\n", ({me}));
		me->unconcious();
		return 1;
	 }

	if(arg&&arg=="auto")
	{
		tell_object(me,ZJEXIT"northwest:"RED"ֹͣ����"NOR":halt\n");
		me->set_temp("pending/auto_work",1);
	}

	message_vision("$N��ʼ����ع���......\n", me);
	cot++;
	me->set_temp("job/step", 1);
	me->start_busy((: call_other, __FILE__, "working" :),
			(: call_other, __FILE__, "halt_working" :));
	return 1;
}

void auto_work(object me)
{
	if(!me||!me->query_temp("pending/auto_work"))
		return;
	if(me->is_busy())
		call_out("auto_work",1,me);
	else if( (int)me->query("jing") < 50)
	{
		if (SKILL_D("force/regenerate")->exert(me, me))
		{
			if( (int)me->query("jing") < 50)
			{
				tell_object(me,"���񲻼ѣ��ȴ��ָ��С�����\n");
				call_out("auto_work",10,me);
			}
			else
			{
				call_out("auto_work",1,me);
			}
		}
		else
		{
			tell_object(me,"���񲻼ѣ��ȴ��ָ��С�����\n");
			call_out("auto_work",10,me);
		}
	}
	else if( (int)me->query("qi") < 50)
	{
		if (SKILL_D("force/recover")->exert(me, me))
		{
			if( (int)me->query("qi") < 50)
			{
				tell_object(me,"��Ѫ���㣬�ȴ��ָ��С�����\n");
				call_out("auto_work",10,me);
			}
			else
			{
				call_out("auto_work",1,me);
			}
		}
		else
		{
			tell_object(me,"��Ѫ���㣬�ȴ��ָ��С�����\n");
			call_out("auto_work",10,me);
		}
	}
	else
	{
		tell_object(me,"�й��У���������������������\n");
		tell_object(me,ZJFORCECMD("work auto"));
	}
}

int working(object me)
{
	object ob;
	int num,exp,pot,yb;
	string msg;
	int finish;

	if(!me->query_temp("job/step"))
		me->set_temp("job/step", 1);

	if(!living(me))
	{
		me->delete_temp("job/step");
		return 0;
	}

	finish = 0;
	me->receive_damage("qi", 0);
	me->receive_damage("jing", 0);
	switch (me->query_temp("job/step"))
	{
	case 1:
		msg = "���ĥ�ɷ۵Ĺ���ʢ��һֻ���ӡ�";
		break;
	default:
		msg = "�Ѵ��ӱ���ǽ�Ƿźá�";
		finish = 1;
		break;
	}
	msg += "\n";
	
	msg = replace_string(msg, "$N", "��");
	tell_object(me, msg);

	if (finish)
	{
		if (me->query_temp("work_times")>=199||me->query("id")=="xiaoyaoyou")
		{
			message("vision",YEL"������ӹ�����"YEL": "HIW+ZJSIZE(22)+me->name()+NOR+YEL"���ڹ������ͣ�������ϰ�ļν�!"NOR"\n",users()); 		
			message_vision("�ϰ��$N˵���ţ����Ĳ������Ǹ���Ľ�����\n",me);
			ob = new("/clone/money/gold"); 			
			ob->set_amount(5);	
			ob->move(me);
			yb=3;
			me->add("combat_exp",300);
			me->add("potential",500);
			me->add("yuanbao",yb);
			tell_object(me,HIY"��õ���" + chinese_number(1) + "���ƽ�\n"
				"��õ���" + chinese_number(300) + "����Ϊ��\n"
				"��õ���" + chinese_number(yb) + "����ʯ��\n"
				"��õ���" + chinese_number(500) + "��Ǳ�ܡ�"NOR"\n");
            log_file("guwu",sprintf("%s��%s�ڹ���ӹ�����������%s��ʯ��\n",ctime(time()),me->query("id"),chinese_number(yb)));
			me->delete_temp("work_times");
			me->set_temp("working",0);
			cot--;
			me->delete_temp("job/step");
			if(me->query_temp("pending/auto_work"))
			{
				call_out("auto_work",1,me);
			}
			return 0;
		}

		message_vision("$N���ڰ���Χ�Ĺ��ﶼ�ӹ���ϣ�����Ҳ�۵İ�����\n", me);
		exp=10+random(30);
		me->add("combat_exp",exp);

	if (me->query("zjvip/times") >1)
	{
pot=20+random(20);
}
else
       pot=10+random(10);

		me->add("potential",pot);
	//	me->add("combat_exp",1);
                me->add_temp("work_times",1);

		ob = new("/clone/money/silver");	
		num=1;
		ob->set_amount(num);
		ob->move(me);
if (me->query("zjvip/times") >1)
{
		message_vision("�ϰ��$N˵��������Ĺ�Ǯ����Ϊ����vip��Ա�����Ի��2�ɼӳɡ�\n", me);
}
else
message_vision("�ϰ������$N˵��������Ĺ�Ǯ��\n", me);
		tell_object(me,HIW"��õ���" + chinese_number(num) + "�����ӡ�\n"
		//	HIM"��õ���" + chinese_number(pot) + "����Ϊ��\n"
			HIM"��õ���" + chinese_number(pot) + "��Ǳ�ܡ�\n"
			HIY"���Ѿ�����������"+ chinese_number(me->query_temp("work_times")) +"�Ρ�"NOR"\n");
		me->set_temp("working",0);
		cot--;
		me->delete_temp("job/step");
		if(me->query_temp("pending/auto_work"))
		{
			call_out("auto_work",5,me);
		}
		return 0;
	}
	me->add_temp("job/step", 1);
	return 1;
}

int halt_working(object me)
{
	message_vision("$N�������еĹ���е��������ˣ��治���˸ɵĻ����\n", me);
	tell_object(me,ZJEXITRM"northwest\n");
	me->delete_temp("pending/auto_work");
	me->delete_temp("job/step");
	me->delete_temp("work_times");
	return 1;
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("job/step")){
		me->delete_temp("work_times");
	        me->delete_temp("job/step");
		tell_object(me,GRN"��͵͵����˹���ӹ�����"NOR"\n");
	}
	return ::valid_leave(me, dir);
}
void reset()
{
	cot=0;
	::reset();
}

