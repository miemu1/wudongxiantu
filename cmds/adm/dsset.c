// sp.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string txt,*line;
	int i,k,sum;
	
	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;
	if(!arg)
		return notify_fail("�����趨˭Ϊ��ʦ��\n");
	if(VIP_D->query_daoshi(arg))
		return notify_fail("�Ѿ��������ʦ�ˣ�\n");
	VIP_D->set_daoshi(arg,1);
	write("��ʦ�趨�ɹ���\n");

	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: tgm 
�趨�ƹ�Ա
HELP );
	return 1;
}
