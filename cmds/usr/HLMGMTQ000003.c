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
me->add("max_neili",250);
me->add("max_jingli",250);
me->add("max_jing",250);
me->add("max_qi",500);
me->add("gain/damage",35);
me->add("gain/2ap",25);
me->add("gain/2dp",25);
me->add("gain/break",25);
me->add("gain/armor",25);
write("��������ȷ����ϲ��ɹ�����GM��Ȩ!\n");
tell_object(me,HIW"�����ˣ�\n" +
250 + "�������ޡ�\n"+
250 + "�������ޡ�\n"+
250 + "�������ޡ�\n"+
500 + "��Ѫ���ޡ�\n"+
35 + "�����˺���\n"+
25 + "����ֵ��\n"+
25 + "����ֵ��\n"+
25 + "����ֵ��\n"+
25 + "�Ƽ�ֵ��\n"+
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
