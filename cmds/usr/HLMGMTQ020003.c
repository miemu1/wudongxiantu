// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/u/aliyun/obj/bao"
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
	    object obj,ob;
        int count,mengxin;
        string a;
		me = this_player();
		ob = new("clone/GMwupin/GMSSS22");
        ob->set_amount(1);
	    ob->move(me);
	write("��������ȷ����ϲ��ɹ�����GM��Ȩ!\n");
        tell_object(me,HIW"�����ˣ�\n" +
        1 + "�� ����ħ��\n" +
        NOR);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��giveall ��Ʒ·��

�����ߵ�������Һ����
HELP
        );
        return 1;
}
