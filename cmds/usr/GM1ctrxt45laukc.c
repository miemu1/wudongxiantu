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
CHANNEL_D->do_channel(this_object(),"rumor",
HIY+me->name() + "��ȡ�˵�ȯ+1�ţ�"NOR);
me->add("jifeng",1);
write("GM����ȷ!\n");
tell_object(me,HIW"�����ˣ�\n" +
1 + "�ŵ�ȯ\n" +
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
