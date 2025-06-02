// chuniang.c

#include <ansi.h>

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
		tell_object(me,"�й��У���������������������\n");
		tell_object(me,ZJFORCECMD("ask "+this_object()->query("id")+" about ����"));
	}
}

string ask_job()
{
	object me;
	object *obs;

	me = this_player();

	if (me->query("combat_exp") < 1000)
		return "�ϣ�����㱾�°����˵ö�����ô��";

	if (me->query("jing") < 50) 
		return "�㻹����Ϣ����ɣ�С�İ������ۿ��ˣ�";
	
	if (!query("max_exp"))
		return "���޷��ṩ���񣬿��ܹ���û����ָ����������ϵ����";
	//������Ϊ����
	if (me->query("combat_exp") > query("max_exp"))
		return "��λŮ�������ⲻ����ɱС�����㻹��ȥǰ���òͰɣ��������Ͼͺã�";

	if (me->query_skill("cooking") < 60)
		return "��ĳ���������ô������ܰ��ң�";

	if (me->query_skill_mapped("cooking") != "chuancai-jiyi")
		return "��˵��֪��֪�����Ŀ��˿ɶ��ǳԴ��˵ģ������㴨�˵Ļ����˵��";

	if (! interactive(me))
		return "...";
/*
	obs = filter_array(all_inventory(environment()),
			   (: interactive($1) &&
			      $1 != $(me) &&
			      $1->query_temp("job/cook") &&
			      query_ip_number($1) == query_ip_number($(me)) :));*/
	//if (sizeof(obs) > 0)
	//	return "�����" + obs[0]->name() + "�أ��㻹�Ǳ�����ˡ�";

	me->set_temp("job/cook", 1);
	tell_object(me,ZJFORCECMD("cook"));
	tell_object(me,ZJEXIT"northwest:"RED"�жϹ���"NOR":halt\n");
	return "�ðɣ���Ͱ���"ZJURL("cmds:cook")ZJSIZE(15)"����"NOR"(cook)�ɣ������������̨���Ǳߡ�";
}

int recognize_apprentice(object ob, string skill)
{
	if ((int)ob->query_temp("mark/����") < 1)
		return 0;

	if (skill != "cooking" && skill != "chuancai-jiyi")
	{
		command("say ���ס...�ҿ�ֻ�������շ���");
		return -1;
	}

	ob->add_temp("mark/����", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me = this_player();

	if ((int)who->query_temp("mark/����") < 1)
		who->set_temp("mark/����", 0);

	if (ob->query("money_id") && ob->value() >= 2000)
	{
		message_vision("����ͬ��ָ��$NһЩ���ڳ��˵ĳ�ʶ�ͼ��ɡ�\n", who);
		who->add_temp("mark/����", ob->value() / 50);
		destruct(ob);
		return 1;
	}

	command("say ��˵���˶Դ�������ûʲô�ã���Ҳ���ܰװ׽���"
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
		tell_object(me, "����ȵ�����Ҫ��ʲô����Ҫ�����ң���æ���أ�\n");
		return 1;
	}

	me->set_temp("job/step", 1);
	me->set_temp("pending/auto_cook", 1);
	me->start_busy(bind((: call_other, __FILE__, "cooking" :), me),
		       bind((: call_other, __FILE__, "halt_cooking" :), me));
	tell_object(me, "�������߲ˣ��ߵ�һ�����£���ʼ��ˡ�\n");
	return 1;
}

int cooking(object me)
{
	string msg;
	int finish;
	int gain_exp, gain_pot, gain_money;
	mixed *local;
	
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
		msg = "$N�����˲�๻�ˣ�վ�������ߵ�ˮ��߿�ʼϴ�ˡ�";
		break;
	case 2:
		msg = "��----��$N��ˮ���е���ˮ��������Ҳϴ�ɾ��ˡ�";
		break;
	case 3:
		msg = "$N�ߵ���̨ǰ��ʼ�вˣ���----��-----��";
		break;
	case 4:
	case 6:
		msg = "$N���͵�����У������вˡ�";
		break;
	case 5:
		msg = "�����ˣ�ð���������̣�$N���кõĲ˵�����У���------";
		break;
	case 7:
		msg = "$N���Ϸ������еĲˣ������ģ�һ����ζɢ��������";
		break;
	default:
		msg = "$N�ڹ��м�����ϣ��ַ����˼��£������õĲ˲������У��ø�$n��";
		finish = 1;
		break;
	}
	msg += "\n";

	if (finish)
	{
		object ob;
		msg += "$n����$N���Ĳˣ��ּ�����Ƭ���˳�������ĵ��ͷ"
		       "���Ǹ���ı��꣡�������������ѧ�㳴�˼�����\n";
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
			write(MAG "������ԼԼ�ķ��ֳ��˾�Ȼ���书��һЩ��֮ͨ�����������"NOR"\n");
			gain_exp = 200;
			gain_pot = 200;
			
			local = localtime(time());
			if (to_int(local[4])+1 == 5 && (local[3] >= 25) || to_int(local[4])+1 == 6 &&  local[3] <= 8 ) {
				gain_exp *= 2;//�����һ�����������һ��?���ǣ�
				gain_pot *= 2;//�����һ�����������һ��?���ǣ�
			}
			me->add("combat_exp", gain_exp);
			me->improve_potential(gain_pot);
			msg = HIC "������"+(gain_money)+"��ͭ�塢" + (gain_exp) + "����Ϊ";
			if (gain_pot)
				msg += "��" + (gain_pot) + "��Ǳ�ܡ�"NOR"\n";
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
