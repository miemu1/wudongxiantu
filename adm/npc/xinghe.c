// chuniang.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

string ask_job();

int  do_cook(string arg);
int  cooking(object me);
int  halt_cooking(object me);

void create()
{
	set_name("��빫��", ({"xinghe", "xing", "he"}));
	set("long", "�����÷������룬է�����������д���
	��ͥ��������ʱ��Ӱ�Ȼ��ȡ�����էƮ�⣬�����֮�����
	���������⣬������֮��ϡ���Ц�����⣬�ƶѴ��٣�����ӣ���⣬
	��ݺ��㡣����֮�����⣬�ط���ѩ�����֮�Ի��⣬�����ơ���û�����⣬
	������ϲ���ǻ������⣬���������ü�Ц�⣬���Զ�δ�����է���⣬��ֹ�����С�
	�۱�֮�����⣬��������Ľ��֮�����⣬�������¡�����֮ò���⣬��������������̬֮���⣬
	�������衣�������Σ���÷��ѩ��������Σ���ձ�˪���侲���Σ������չȡ��������Σ�ϼӳ������
	�������Σ��������ӡ��������Σ����亮����Ӧ�����ӣ�ʵ�����͡�" );
	set("gender", "Ů��");
	set("age", 14);
	set("no_get", 1);
	set("attitude", "friendly");

	set("inquiry",([
		"˫��" : (: ask_job :),
	]));

	set("age", 30);

	set("str", 21);
	set("skill_chuniang", 1);
	set("int", 22);
	set("con", 30);
	set("dex", 21);

	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);

	set("vendor_goods", ({
		"/clone/misc/TT",
	}));

	setup();
}

void init()
{
	add_action("do_cook", "cook");
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void auto_cook(object me)
{
	if(!me||!interactive(me)) return;
	if(!me->query_temp("pending/auto_cook"))
		return;
	if(me->is_busy())
		call_out("auto_cook",1,me);
	else if( (int)me->query("jing") < me->query("eff_jing"))
	{
		if (SKILL_D("force/regenerate")->exert(me, me))
		{
			if( (int)me->query("jing") < me->query("eff_jing"))
			{
				tell_object(me,"�������㣬�ȴ��ָ��С�����\n");
				call_out("auto_cook",1,me);
			}
			else
			{
				call_out("auto_cook",1,me);
			}
		}
		else
		{
			tell_object(me,"�������㣬�ȴ��ָ��С�����\n");
			call_out("auto_cook",1,me);
		}
	}
	else
	{
		tell_object(me,"�й��У�����˫�ޡ�����������\n");
		tell_object(me,ZJFORCECMD("ask "+this_object()->query("id")+" about ˫��"));
	}
}

string ask_job()
{
	object me;
	object *obs;

	me = this_player();

	if (me->query("combat_exp") < 1000)
		return "�ϣ�����㱾�°������ܶ���ô��";

	if (me->query("jing") < 50) 
		return "�㻹����Ϣ����ɣ�С�İ������ۿ��ˣ�";

	if (me->query("combat_exp") > 2500000)
		return "��λŮ�������ⲻ����ɱС����";

	if (me->query_skill("cooking") < 30)
		return "��ļ�����ô������ܰ��ң�";

	if (me->query_skill_mapped("cooking") != "chuancai-jiyi")
		return "��˵��֪��֪���ҿ��Ǻ����޵ģ������������˵��";

	if (! interactive(me))
		return "...";

	obs = filter_array(all_inventory(environment()),
			   (: interactive($1) &&
			      $1 != $(me) &&
			      $1->query_temp("job/cook") &&
			      query_ip_number($1) == query_ip_number($(me)) :));
	//if (sizeof(obs) > 0)
	//	return "�����" + obs[0]->name() + "�أ��㻹�Ǳ�����ˡ�";

	me->set_temp("job/cook", 1);
	tell_object(me,ZJFORCECMD("cook"));
	tell_object(me,ZJEXIT"northwest:"RED"�ж�˫��"NOR":halt\n");
	return "�ðɣ���Ͱ���"ZJURL("cmds:cook")ZJSIZE(15)"���һ�°�"NOR"(cook)�ɣ�TT������������Ǳߡ�";
}

int recognize_apprentice(object ob, string skill)
{
	if ((int)ob->query_temp("mark/�Ǻ�") < 1)
		return 0;

	if (skill != "cooking" && skill != "chuancai-jiyi")
	{
		command("say ���ס��");
		return -1;
	}

	ob->add_temp("mark/�Ǻ�", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me = this_player();

	if ((int)who->query_temp("mark/�Ǻ�") < 1)
		who->set_temp("mark/�Ǻ�", 0);

	if (ob->query("money_id") && ob->value() >= 2000)
	{
		message_vision("�Ǻ�ͬ��ָ��$NһЩ����˫�޳�ʶ�ͼ��ɡ�\n", who);
		who->add_temp("mark/�Ǻ�", ob->value() / 50);
		destruct(ob);
		return 1;
	}

	command("say ��˵�Դ�������ûʲô�ã���Ҳ���ܰװ׽���"
		"���������������������ʮ����ͯ�����ۣ�");
	return 0;
}

int do_cook(string arg)
{
	object me;

	me = this_player();
	if (me->is_busy())
		return notify_fail("����æ���أ����ż���\n");

	if (! me->query_temp("job/cook"))
	{
		tell_object(me, "�ǺӺȵ�����Ҫ��ʲô����Ҫ�����ң���æ���أ�\n");
		return 1;
	}

	me->set_temp("job/step", 1);
	me->set_temp("pending/auto_cook", 1);
	me->start_busy(bind((: call_other, __FILE__, "cooking" :), me),
		       bind((: call_other, __FILE__, "halt_cooking" :), me));
	tell_object(me, "��˫�ֻ������Ǻӣ�������һ������������ǡ�\n");
	return 1;
}

int cooking(object me)
{
	string msg;
	int finish;
	int gain_exp, gain_pot, gain_money;

	if (! me->query_temp("job/step"))
		me->set_temp("job/step", 1);

	if (! living(me))
	{
		me->delete_temp("job/cook");
		me->delete_temp("job/step");
		return 0;
	}

	finish = 0;
	me->receive_damage("jing", 8);
	switch (me->query_temp("job/step"))
	{
	case 1:
		msg = "$N�������ȥ�Ǻӵ����ѡ�";
		break;
	case 2:
		msg = "���˫������İ�������������............��";
		break;
	case 3:
		msg = "$N�����ķ�����ȥ........��";
		break;
	case 4:
	case 6:
		msg = "$N��ʼ�����Ǽ��ֵĸо���";
		break;
	case 5:
		msg = "���𽥼ӿ��ٶ�";
		break;
	case 7:
		msg = "$N��ˬ�Ļ��˹�ȥ";
		break;
	default:
		msg = "$N���ˣ�����Ŀ���$n��";
		finish = 1;
		break;
	}
	msg += "\n";

	if (finish)
	{
		object ob;
		msg += "$n����$N������ĸ�����һ���ǣ�����ĵ��ͷ"
		       "���Ǹ���ı��꣡�������������ѧ�㼼����\n";
		me->delete_temp("job/cook");
		me->delete_temp("job/step");
		gain_money = 2+random(6);
		me->add_temp("mark/����", random(30));
		me->improve_skill("cooking", 10 + random(10));

		// ��������ΪΪ10��20����������϶ࣩ�� moneyΪ100�ӳ��˼�
		// ���ĵȼ�ȡ��������϶ࣩ��Ǳ��Ϊ������3�㣬��Ҫ�����Լ�
		// silverΪ����
		ob = new("/clone/money/coin");
		ob->set_amount(gain_money);
		ob->move(me, 1);
		call_out("auto_cook",2,me);
	}

	msg = replace_string(msg, "$N", "��");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

	if (finish)
	{
		if (me->query("combat_exp") >= 50000)
		{
			write(MAG "������ԼԼ�ķ��־�Ȼ���书��һЩ��֮ͨ�����������"NOR"\n");
			gain_exp = 150 + random(11);
			gain_pot = (gain_exp);
			me->add("combat_exp", gain_exp);
			me->improve_potential(gain_pot);
			msg = HIC "������"+chinese_number(gain_money)+"��ͭ�塢" + chinese_number(gain_exp) + "����Ϊ";
			if (gain_pot)
				msg += "��" + chinese_number(gain_pot) + "��Ǳ�ܡ�"NOR"\n";
			else
				msg += "��"NOR"\n";
			tell_object(me,  msg);
		}
		return 0;
	}

	me->add_temp("job/step", 1);
	return 1;
}

int halt_cooking(object me)
{
	message_vision("$N������������Ť��Ť��̾������Ҳ̫���ˣ��һ���ȥ���������ɣ�\n", me);
	me->delete_temp("job/cook");
	me->delete_temp("pending/auto_cook");
	me->delete_temp("job/step");
	return 1;
}
