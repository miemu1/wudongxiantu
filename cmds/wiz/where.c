// where.c
// 06-14-95
#include <ansi.h> 
inherit F_CLEAN_UP;

int main(object me, string str,string arg)
{
	object ob, where, *ob_list;
	int i;
 if(arg=="shou")
   {
	   	write(INPUTTXT("����npc����", "where $txt#") + "\n");
		return  0;
   }
	if((me->query("id") != "z110614_1")&&(me->query("id") != "z110614_1")) return 0;
	if (! SECURITY_D->valid_grant(me, "(wizard)"))
		return 0;

	if (! str)
		return notify_fail("ָ���ʽ��where <�������>\n"); 
  
	ob = find_player(str);
	if (! ob) ob = find_living(str);
	if (! ob || ! me->visible(ob))
	{
		str = resolve_path(me->query("cwd"), str);
		ob = find_object(str);
	}

	if (! ob)
		return notify_fail("û���ҵ������Ʒ��\n");

	where = environment(ob);
	if (! where)
		return notify_fail("����˲�֪��������Ү...\n");

	write(sprintf("%s(%s)������%s(%s).\n",
		(string)ob->name(1),
		(string)ob->query("id"),
		(string)where->short(),
		(string)file_name(where)));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: where <����ID>

���ָ����������֪����Ŀǰ���ڵ�λ��.

HELP );
	return 1;
}

