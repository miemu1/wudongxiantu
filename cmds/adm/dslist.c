// sp.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string str,*list;
	int i;
	
	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	if(!list = VIP_D->list_daoshi())
		return notify_fail("��ǰ��Ϸ�л�û�е�ʦ��\n");

	str = ZJOBLONG"��ǰ��Ϸ����"+sizeof(list)+"λ��ʦ��";
	for(i=0;i<sizeof(list);i++)
	{
		str += ZJBR + list[i];
	}

	write(str + "\n");
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
