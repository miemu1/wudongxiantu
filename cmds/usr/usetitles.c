// special

#include <ansi.h>
#define TITLE_D  "/adm/daemons/titled.c"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string  msg;
	mapping ss;
	string  title;
	object ob;
	string pro,sname;
	int i;
       
	if (wizardp(me) && stringp(arg) &&
	    objectp(ob = find_player(arg)))
		// �鿴������ҵ����⼼��
		arg = 0;
	else
		ob = me;

	pro = (ob == me) ? "��" : ob->name(1);

	if (! ob->query("born"))
		return notify_fail(pro + "��û�г����ţ�������ʲô�ɾ��أ�\n");

	if (! mapp(ss = ob->query("titles")) ||
	    ! sizeof(ss))
		return notify_fail(pro + "���ں���ʲô�ɾͶ�û��Ŷ���������Ͱɡ�\n");	
if (arg && (ob == me))
	{
		if (me->is_busy())
			return notify_fail("������æ���أ����ܸı�ƺš�\n");

			title = arg;					
			if (!ss[title])	
					return notify_fail("�����û������ƺ�...\n");
 else
 TITLE_D->use_title(me,title);
 return 1;
 }
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : usetitles <title> | <���ID>
ʹ������������������ӵ�еĳƺš�

HELP );
    return 1;
}
