//by ��ʼ�� qsh ednpc tools.
// yixiantian.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","һ����");
	set("long","������һ���죬����Ա��δ�趨������ϸ������");
	set("exits", ([
		"east" : __DIR__"shidong1",
	]));
	set("item_desc", ([
		"ʯ��" : "����һ�����ʯ��ɵ�ʯ�ڣ������������ġ�\n"
		ZJOBACTS2"�ж�:study1 table\n",	
		]));
	set("objects", ([
	]));
	setup();
}

void init()
{
	add_action("do_study", "study1");
}

int do_study(string arg)
{
	object me;
	string msg;

	me = this_player();

	if (arg != "table")
		return notify_fail("��Ҫ��ʲô��\n");
		
	if ((me->query("potential") - me->query("learned_points")) < 10)
		return notify_fail("��Ŀǰ��Ǳ�ܲ��㣬�޷���ʯ���ϸ��򵽸������ݡ�\n");
		
	if (me->query_skill("literate"))
		return notify_fail("���������д�ĺ��е���\n");

	if (me->query_temp("stone_learned"))
		return notify_fail("�㲻���Ѿ����ж����𣿻��ǽ�̤ʵ����������ҪȥͶ��ȡ�ɡ�\n");

	if (me->is_busy()) {
		call_out("do_lian3", 3, me);
		return notify_fail("����æµ�С�\n");
	}

	if (me->query("jing") < 95)
	{
		write("�����ڹ���ƣ�룬�ȴ��ָ���...\n");
                tell_object(me,ZJFORCECMD("use huxin dan"));
	        call_out("do_lian3", 10, me);
		return 1;
	}

	me->receive_damage("jing", 90);
	msg = "����ר���ж�ʯ���ϵĹŹ�����ġ�\n";


		if ((int)me->query_skill("taixuan-gong", 1) < 180 && me->can_improve_skill("taixuan-gong"))
		{
			me->add("learned_points", 10);
	        me->improve_skill("taixuan-gong", 10 + random(me->query("int")*8));
			msg += "�㿴��һ�ض����ƺ���̫�����е��ĵá�\n";
			me->set_temp("stone_learned", 1);
		}

	if (! me->query_temp("stone_learned"))
		msg += "�����ʯ����ĥ��һ�����ȷû���κ��ջ񣬻����������Ϊ���㣬���������еĿ��ּ��ܶ�����100���ˡ�\n";

	write(msg);
	call_out("do_lian3", 1, me);
	return 1;
}

void do_lian3(object me)
{
	if (! objectp(me))
		return;
	me->delete_temp("stone_learned");
    me->force_me("exert regenerate");
	me->force_me("study1 table");
}