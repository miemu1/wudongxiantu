// quest.c
#include <ansi.h> 
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	mapping q;
	string area;
	int times=time();
	
	        if (me->is_ghost()) 
        return notify_fail("���㻹������˵�ɡ�\n");                 
        if (me->is_in_prison())   
        return notify_fail("�����������ء�\n");
        if( me->query("doing") )
        return notify_fail("�㻹���ʲô����\n");
		if( me->is_net_dead()&& !me->query("zjvip/lxsm"))
        return notify_fail("�㲻����ʹ����������\n");
	
		 if (me->query("combat_exp")>=800000 && ! objectp(ob = present("tishen kuilei", me)))
                return notify_fail("��������û�п��ܣ�����զ�죡\n"); 

		if(me->query("shimen/today")<3)
			{
					me->force_me("refuse quest");
			}else
				me->force_me("accept quest");
	if(!mapp(q=me->query("quest")))
	{
      		return notify_fail("������û������ʹ���Զ�ʦ�Ÿ�ʲô?\n");  
	}
	
	 if (me->is_fighting()) 
		return notify_fail("����������ս����\n");

	if(q["type"]!="kill")
	{
      		return notify_fail("������û��ʦ��ɱ����������ʹ�á�\n");  
	}
	if(ob=find_living(""+q["id"]+""))
	{
		sscanf(base_name(environment(ob)),"/d/%s/%*s",area);
        message_vision(HIC"��������������������������"NOR"\n" , me);
		tell_object(me,HIR+q["name"]+NOR"��"+q["id"]+"��Ŀǰ����"HIW+MAP_D->query_map_short(area)+NOR"��"HIW+environment(ob)->query("short")+NOR"���\n");
me->move(environment(ob));
me->force_me("kill " + me->query("quest/id"));
	}
	else
	tell_object(me,"�޷��Զ���Ŀ�����������Ŀ�������ѱ�ɱ��������ʧ�ˡ�\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quest  ���ָ�����������������ɵ����Ż����ҳ���
��ȡ������������κβ�������ʾ���㵱ǰ������
HELP );
	return 1;
}

