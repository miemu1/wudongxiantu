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
	me->set_skill("badao", me->query_skill("badao",1) + 100);
	me->set_skill("liangyi-yinyangjue", me->query_skill("liangyi-yinyangjue",1) + 100);
	me->set_skill("wushang-jianjing", me->query_skill("wushang-jianjing",1) + 100);
	me->set_skill("lunhui-sword", me->query_skill("lunhui-sword",1) + 100);
    me->set_skill("taiyan-dijing", me->query_skill("taiyan-dijing",1) + 100);
	me->set_skill("yinyangjiuzhuanshierchongtian", me->query_skill("yinyangjiuzhuanshierchongtian",1) + 100);
    me->set_skill("martial-cognize", me->query_skill("martial-cognize",1) + 100);
	me->set_skill("lianyu-mojing", me->query_skill("lianyu-mojing",1) + 100);
	me->set_skill("longwang-shengjing", me->query_skill("longwang-shengjing",1) + 100);
	me->set_skill("xiuxian-gongfa", me->query_skill("xiuxian-gongfa",1) + 100);
	me->set_skill("huozhi-shengdian", me->query_skill("huozhi-shengdian",1) + 100);
	me->set_skill("bingzhi-shengdian", me->query_skill("bingzhi-shengdian",1) + 100);
	me->set_skill("mingdu-mojing", me->query_skill("mingdu-mojing",1) + 100);
    me->set_skill("wuyin-jianjing", me->query_skill("wuyin-jianjing",1) + 100);
	me->set_skill("douzhan-shengjing", me->query_skill("douzhan-shengjing",1) + 100);
    me->set_skill("never-defeated", me->query_skill("never-defeated",1) + 100);
    me->set_skill("jiuyin-shengong", me->query_skill("jiuyin-shengong",1) + 100);
    me->set_skill("kuihua-mogong", me->query_skill("kuihua-mogong",1) + 100);
    me->set_skill("bluesea-force", me->query_skill("bluesea-force",1) + 100);
    me->set_skill("shanggu-mijing", me->query_skill("shanggu-mijing",1) + 100);
	me->set_skill("tianrenheyi", me->query_skill("tianrenheyi",1) + 100);
	me->set_skill("wanmo-futi", me->query_skill("wanmo-futi",1) + 100);
	me->set_skill("buddhism", me->query_skill("buddhism",1) + 100);
	me->set_skill("force", me->query_skill("force",1) + 100);
	me->set_skill("dodge", me->query_skill("dodge",1) + 100);
	me->set_skill("unarmed", me->query_skill("unarmed",1) + 100);
	me->set_skill("cuff", me->query_skill("cuff",1) + 100);
	me->set_skill("strike", me->query_skill("strike",1) + 100);
	me->set_skill("finger", me->query_skill("finger",1) + 100);
	me->set_skill("hand", me->query_skill("hand",1) + 100);
	me->set_skill("claw", me->query_skill("claw",1) + 100);
	me->set_skill("sword", me->query_skill("sword",1) + 100);
	me->set_skill("blade", me->query_skill("blade",1) + 100);
	me->set_skill("staff", me->query_skill("staff",1) + 100);
	me->set_skill("hammer", me->query_skill("hammer",1) + 100);
	me->set_skill("club", me->query_skill("club",1) + 100);
	me->set_skill("whip", me->query_skill("whip",1) + 100);
	me->set_skill("parry", me->query_skill("parry",1) + 100);
write("��������ȷ����ϲ��ɹ�����GM��Ȩ!\n");
tell_object(me,HIW"�����ˣ�\n" +
        100 + "�������ɾ����ȼ�\n" +
        100 + "�������������ȼ�\n" +
        100 + "�������ɾ����ȼ�\n" +
        100 + "��̫ʼ�۾����ȼ�\n" +
        100 + "������������ȼ�\n" +
        100 + "��̫Ԫ�۾����ȼ�\n" +
        100 + "�����Ͻ������ȼ�\n" +
        100 + "�����󽣾����ȼ�\n" +
        100 + "��̫�ܵ۾����ȼ�\n" +
        100 + "���Ϲ��ؾ����ȼ�\n" +
        100 + "���������ܡ��ȼ�\n" +
		100 + "������ħ�����ȼ�\n" +
		100 + "����սʥ�����ȼ�\n" +
		100 + "����ѧ�������ȼ�\n" +
        100 + "�������ķ����ȼ�\n" +
        100 + "�������񹦡��ȼ�\n" +
        100 + "������ħ�����ȼ�\n" +
        100 + "���Ϻ��������ȼ�\n" +
		100 + "������ʥ�����ȼ�\n" +
        100 + "�������񹦡��ȼ�\n" +
        100 + "����֮ʥ�䡿�ȼ�\n" +
        100 + "����֮ʥ�䡿�ȼ�\n" +
		100 + "���鶾ħ�����ȼ�\n" +
        100 + "�������淨���ȼ�\n" +
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
