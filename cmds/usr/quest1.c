// quest.c

#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,obj;
	mapping q;
	string master,str;
	if (me->query_condition("jjfb"))
		tell_object(me, HIG"��Ŀ���ȸ���ʱ�仹��"+chinese_number(me->query_condition("jjfb")/6)+"���ӡ�"NOR"\n");
	if (me->query("shimen/today"))
		tell_object(me, HIG"�㱾���Ѿ�����"+chinese_number(me->query("shimen/today"))+"��ʦ�������ˡ�"NOR"\n");
	if (me->query_condition("db_jifen"))
		tell_object(me, HIG"���˫����ȯ��ʱ�仹��"+chinese_number(me->query_condition("db_jifen")/6)+"���ӡ�"NOR"\n");
	if (me->query_condition("db_exp"))
		tell_object(me, HIG"������鵤ʱ�仹��"+chinese_number(me->query_condition("db_exp")/6)+"���ӡ�"NOR"\n");
	if (me->query_condition("db_exp2"))
		tell_object(me, HIG"������鵤ʱ�仹��"+chinese_number(me->query_condition("db_exp2")/6)+"���ӡ�"NOR"\n");
	if (me->query_condition("db_exp3"))
		tell_object(me, HIG"������뵤ʱ�仹��"+chinese_number(me->query_condition("db_exp3")/6)+"���ӡ�"NOR"\n");

if (me->query("auto_kill_quest_npc") && me->query("quest/id")) {
	if (objectp(present(me->query("quest/id"),environment(me)))) {
		me->force_me("kill " + me->query("quest/id"));
		return 1;
	}
}






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
