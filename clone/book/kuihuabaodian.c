inherit ITEM;

#include <ansi.h>; 

void setup()
{}

void init()
{
	add_action("do_du", "du");
	add_action("do_du", "study");
}

void create()
{
	set_name(HIW "����������2��" NOR, ({ "kuihua baodian2", "baodian2", "book2", "kuihua2"}));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIR "��������ֵ�һ�ؼ�����������2�����ഫ��һλ����̫���������ֳ��漣�������"
				ZJURL("cmds:study kuihua baodian2")+ZJSIZE(22)+"�ж�"NOR+HIR"������"NOR"\n");
		set("value", 1);
		set("material", "paper");
		set("no_put", 1);
		set("no_sell", 1);
		set("no_save", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_give", 1);
	}
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob, obj;
	mapping skill;
	int plvl, con, improve;
	int neili_lost;

	if (! arg || ! id(arg))
		return 0;

	if (me->is_busy())
	{
		write("��������æ���ء�\n");
        return 1;
	}

	if (me->is_fighting())
	{
		write("���޷���ս����ר�������ж���֪��\n");
		return 1;
	}

	if (where->query("no_fight"))
	{
		write("���޷������ﾲ�������ж����䡣\n");
		return 1;
	}

	if ((string)me->query("gender") == "Ů��")
	{
		write("�Թ�û����˵Ů�˿��Զ�����������2���ġ�\n");
		return 1;
	}

	if ((string)me->query("gender") == "����")
	{
	       write("����������2���ĵ�һҳд�ţ������񹦣������Թ���\n");
	       return 1;
	}

	if (me->query_skill("pixie-jian", 1))
	{
		write("�㲻ɢ����а����û�취�ж��Ȿ�顣\n");
		return 1;
	}
	if (! me->query_skill("literate", 1))
	{
		write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}
	if (me->query_skill("kuihua-shengong", 1) >= 180)
	{
		write("�Ȿ�����Ѿ��о��ò���ˣ�ûʲô�ö����ˡ�\n");
		return 1;
	}

	if ((int)me->query("combat_exp") < 200000)
	{
			write("���ʵս��Ϊ���㣬����ô��Ҳû�á�\n");
			return 1;
	}

	if ((int)me->query("max_neili") < 500)
	{
			write("����������̫�ͣ��޷������˵��񹦡�\n");
			return 1;
	}

	if (me->query_skill("xixing-dafa", 1) > 1 || me->query_skill("tianmo-jian", 1) > 1) {
		tell_object(me, "���Ѿ�ѧ�����Ǵ󷨻�����ħ�������Ȿ���Ѿ���ȫ�������ˡ�\n");
		return 1;
	}
	if (me->query("family/master_id") == "ren woxing") {
		tell_object(me, "��ʦ��������������ľ��Ƕ���������ѧ�����书��̫���ʰɣ�\n");
		return 1;
	}
	
	switch (random(3))
	{
		case 0:
			message("vision", me->name() + "͵͵��������"
				"һ����������2�ڶ���\n", environment(me), me);
			break;
		case 1:
			message("vision", me->name() + "�߶����ɧ��"
				"Ū�ˣ�ģ��Ů�˼�ֱΩ��ΩФ��\n", environment(me), me);
			break;
		case 2:
			message("vision", me->name() + "�߶���߰���"
				"֫Ť��Ťȥ����������ͷ�������ѡ�\n", environment(me), me);
			break;
	}

	if ((int)me->query("jing") < 60)
	{
		if (  present("huxin dan", obj) )
		{
			tell_object(me, ZJFORCECMD("use huxin dan"));
			remove_call_out("do_lian3");
			call_out("do_lian3", 2, me);

			return 1;
		} else {
			write("�����ڹ���ƣ�룬�ȴ��ָ���...\n");
			remove_call_out("do_lian3");
			call_out("do_lian3", 20, me);

			return 1;
		}
	}

	plvl = me->query_skill("kuihua-shengong", 1);
	if (plvl > 165) neili_lost = 100; else
	if (plvl > 150) neili_lost = 60;  else
	if (plvl > 120) neili_lost = 40;  else
	if (plvl > 100) neili_lost = 30;  else
	if (plvl > 50)  neili_lost = 20;
		   else neili_lost = 10;

	con = me->query_con();

	if ((int)me->query("neili") < 200  || me->query("jing") < 120)
	{
		if (  present("huxin dan", obj) )
		{
			tell_object(me, ZJFORCECMD("use huxin dan"));
			remove_call_out("do_lian3");
			call_out("do_lian3", 2, me);

			return 1;
		} else {
			write("��״̬���ѣ��ȴ��ָ���...\n");
			remove_call_out("do_lian3");
			call_out("do_lian3", 20, me);
			return 1;
		}
	}

	if (! me->can_improve_skill("kuihua-shengong", 1))
	{
		write("���ʵս��Ϊ���㣬����ô��Ҳû�á�\n");
		return 1;
	}

	if ((plvl > 10) && (con / 2 + random(con) < 50) && random(80) == 1)
	{
		// ����֮�˶�����������2���������߻�
		if (me->query("special_skill/ghost") && random(3))
		{
			tell_object(me, HIR "�������ű�����ʾ��ת��Ϣ��ͻ"
					"Ȼ��Ϣ�������ϣ�ȴ���������κβ�"
					"�ס�"NOR"\n");
		}
		else
		{		
			tell_object(me, HIR "�������ű�����ʾ��ת��Ϣ��ͻ"
					"Ȼֻ����Ϣ�������ϣ���֫�������Ļ���\n"
					"�٣��Һ�һ�������˹�ȥ��"NOR"\n");
			message("vision", HIR + me->name() + "ͻȻ��"
					  "��һ����������˹�ȥ��"NOR"\n",
				environment(me), ({ me }));
	
			if ((int)me->query("max_neili") > 10)
			{
				me->add("max_neili", -10 - random(10));
			}
			remove_call_out("do_lian3");
			call_out("do_lian3", 2, me);
			//me->unconcious();
			return 1;
		}
	}

	me->receive_damage("jing", 20);
	me->add("neili", -neili_lost);
	me->improve_skill("kuihua-shengong", 12 + random(30));
	
	// ����֮��ѧϰ�����񹦸���
	if (me->query("special_skill/ghost"))
	{
		me->improve_skill("kuihua-shengong", 2 + random(10));
	}

	me->start_busy(random(1) + 1);
	write("���ж�����������2���������ĵá�\n");
	remove_call_out("do_lian3");
	call_out("do_lian3", 2, me);
	return 1;
}

void do_lian3(object me)
{
	if (! objectp(me))
		return;

	tell_object(me,ZJFORCECMD("du kuihua baodian2"));
}
