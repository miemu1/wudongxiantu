// emote.c (Mon  09-04-95)

#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string str)
{
	string *emotes,prefix,estr;
	string emote, id;
	object env, ob;
	mixed info;
	object *obj;
	int i, ok=0;

	if (me->ban_say())
		return 0;

	env = environment(me);
	if (info = env->query("no_say"))
	{
		if (stringp(info))
		{
			write(info);
			return 1;
		}

		write("����ط���������������\n");
		return 1;
	}

	if (! str)
	{
		emotes = EMOTE_D->query_all_emote();
		estr = ZJOBLONG+"��ǰƵ����"+me->query_temp("pindao/name")+"������ѡ����鶯����\n"ZJOBACTS2+ZJMENUF(3,3,8,30);
		i = 50;
		while(i--)
		{
			estr += emotes[i]+":emote "+emotes[i]+ZJSEP;
		}
		write(estr+"\n");
		return 1;
	} else
	if (sscanf(str, "%s %s", emote, id)==2) {
		if (!ob = find_object(id))
			return 1;
		
		id = ob->query("id");

		me->force_me(me->query_temp("pindao/id")+"* "+emote+" "+id);
		return 1;
	} else {
		emote = str;
		obj = all_inventory(env);
		if (sizeof(obj)>0) {
			estr = ZJOBLONG+"��ǰƵ����"+me->query_temp("pindao/name")+"����\n"ZJOBACTS2+ZJMENUF(2,2,8,30);
			for(i=0;i<sizeof(obj);i++)
			{
				if (me->is_fighting(obj[i]) || obj[i]->is_fighting(me)) continue;
				if (!obj[i]->is_character()) continue;
				if (obj[i]->is_corpse()) continue;
				if (me == obj[i]) continue;
					
				estr += "��"+obj[i]->name()+"ʹ�ã�"+emote+":emote "+emote+" "+file_name(obj[i])+ZJSEP;
				ok =1;
			}
			if (ok < 1) {
				estr = ZJOBLONG+"��ǰƵ����"+me->query_temp("pindao/name")+"����"+"\n"ZJOBACTS2+ZJMENUF(2,2,8,30);
				estr += "���ͱ��飺"+emote+":"+me->query_temp("pindao/id")+"* "+emote+ZJSEP;
			} else
				estr += "���ͱ��飺"+emote+":"+me->query_temp("pindao/id")+"* "+emote+ZJSEP;
			estr += CYN"����"NOR":emote";
		} else {
			estr = ZJOBLONG+"��ǰƵ����"+me->query_temp("pindao/name")+"����"+"\n"ZJOBACTS2+ZJMENUF(2,2,8,30);
			estr += "���ͱ��飺"+emote+":"+me->query_temp("pindao/id")+"* "+emote;
			estr += ZJSEP+CYN"����"NOR":emote";
		}
		write(estr+"\n");
		return 1;
	}
	
	prefix = me->query("env/no_prefix") ? "" : "��";
	write(CYN "��" + str + ""NOR"\n");
	tell_room(env, CYN + prefix + (string)me->name() +  str + ""NOR"\n", me);
	return 1;
}
 
int help(object me)
{
	write(@HELP
ָ���ʽ: emote <������>

���ָ�����������һ��ϵͳû��Ԥ��Ķ�����, ϵͳ�Ὣ��������
�����ּ��������������ʾ��������ͬһ���ط������￴��Ϊ�˱�����
������, ���������Ĵʾ�ǰ������ ~ �Թ�����

����: emote ����������
��ῴ��: ������������
�����˻ῴ��: ~��������������

����, ���Ӿ����������.

���ָ��: semote
HELP );
	return 1;
}
