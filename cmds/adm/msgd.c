// sp.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	mapping site;
	object *users,obj;
	string item, desc;
	string msg;
	int i;
	
	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	"/clone/misc/msgd"->on_time();
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: sp <class> <info>

��Ȩ������վ��ĳЩ�����ʹ��Ȩ�ޡ�info ���Ϊ�ջ��� clear ��
��ʾȡ�������ʹ��Ȩ�ޡ�
HELP );
	return 1;
}
