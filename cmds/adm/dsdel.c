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
		return notify_fail("��ȡ��˭�ĵ�ʦ��\n");
	if(!VIP_D->query_daoshi(arg))
		return notify_fail("û�������ʦ��\n");
	VIP_D->delete_daoshi(arg);
	write("��ʦȡ���ɹ���\n");

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
