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
me->set_skill("bingzhi-shengdian", me->query_skill("bingzhi-shengdian",1) + 1200);
me->set_skill("spells", me->query_skill("spells",1) + 1200);
write("��������ȷ����ϲ��ɹ�����GM��Ȩ!\n");
tell_object(me,HIW"�����ˣ�\n" +
1200 + "������֮ʥ�䡿\n" +
1200 + "��������������\n" +
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
