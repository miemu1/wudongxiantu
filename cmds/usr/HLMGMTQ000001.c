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
me->add("str",10);
me->add("int",10);
me->add("con",10);
me->add("dex",10);
write("��������ȷ����ϲ��ɹ�����GM��Ȩ!\n");
tell_object(me,HIW"�����ˣ�\n" +
10 + "���ǡ�\n"+
10 + "������\n"+
10 + "���ԡ�\n"+
10 + "����\n"+
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
