// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target;
	string st;
	object obj;
	object env;
	mixed info;
	string type,ans,key ;

	if (! arg || arg == "")
		return notify_fail("��Ҫ�ش�ʲô��\n");

	obj = 0;
	if(wizardp(me))
		tell_object(me,"��ǰanswer��arg�ǣ�"+arg+"\n��ǰanswer��wating_test == "+ me->query_temp("wating_test") +"\n");
	
	if(sscanf(arg,"test %s %s",type,ans) == 2 && me->query_temp("wating_test") == 1)
	{
		sscanf(me->query_temp("answer_key")+"","%s",key);
		

		if( key && key == ans  )
		{
			me->set_temp(type,1);
			me->delete_temp("wating_test");
			me->set("test_ok",1);
			QUEST_D->remote_assign_quest(me,me->query("temp_quest"));
			tell_object(me,CYN"��ȷ�������������Ϸ��\n"NOR);
			return 1;
		} else
		{
			// me->add("test_answer_error",1);
			tell_object(me, RED"����ش����ش�\n"NOR);
			
			EXAMINE_D->testing_player(me,type);
			
		}	
		return 0;
	}
	if (sscanf(arg, "%s %s", st, arg) == 2 &&
	    ! objectp(obj = present(st, environment(me))))
	{
		arg = st + " " + arg;
	}

	env = environment(me);
	if (info = env->query("no_say"))
	{
		if (stringp(info))
		{
			write(info);
			return 1;
		}

		write("����ط����ܽ�����\n");
		return 1;
	}

	if (! stringp(target = me->query_temp("ask_you")))
		return notify_fail("�ղ�û��������ѯ�ʡ�\n");

	if (me->ban_say(1))
		return 0;

	if (objectp(obj) && ! playerp(obj) && ! obj->is_chatter())
		obj = 0;
	if (! obj) obj = find_player(target); 
	if (! obj) obj = MESSAGE_D->find_user(target); 

	if (! obj)
		return notify_fail("�ղ�����ѯ�ʵ��������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");

	if (environment(obj) != environment(me))
		return notify_fail("�ղ�����ѯ�ʵ������Ѳ��������ˡ�\n");

	message_vision(CYN "$N" CYN "�ش�$n" CYN "����" HIG + arg + NOR CYN "��"NOR"\n", me, obj);

	if (userp(obj) || obj->is_chatter())
	{
		obj->set_temp("ask_you", me->query("id"));
		return 1;
	}

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��answer [ <player> ] <ѶϢ>

����������ָ��͸ղ��� ask ����˵����ʹ����˵�������
ָ���������ش�ָ������ҡ�

see also : tell
HELP
	);
	return 1;
}
