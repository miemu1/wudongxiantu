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
	me->set_skill("badao", me->query_skill("badao",1) + 9999);
	me->set_skill("liangyi-yinyangjue", me->query_skill("liangyi-yinyangjue",1) + 9999);
	me->set_skill("wushang-jianjing", me->query_skill("wushang-jianjing",1) + 9999);
	me->set_skill("lunhui-sword", me->query_skill("lunhui-sword",1) + 9999);
    me->set_skill("taiyan-dijing", me->query_skill("taiyan-dijing",1) + 9999);
	me->set_skill("yinyangjiuzhuanshierchongtian", me->query_skill("yinyangjiuzhuanshierchongtian",1) + 9999);
    me->set_skill("martial-cognize", me->query_skill("martial-cognize",1) + 9999);
	me->set_skill("lianyu-mojing", me->query_skill("lianyu-mojing",1) + 9999);
	me->set_skill("longwang-shengjing", me->query_skill("longwang-shengjing",1) + 100);
    me->set_skill("douzhan-shengjing", me->query_skill("douzhan-shengjing",1) + 9999);
    me->set_skill("never-defeated", me->query_skill("never-defeated",1) + 9999);
    me->set_skill("jiuyin-shengong", me->query_skill("jiuyin-shengong",1) + 9999);
    me->set_skill("kuihua-mogong", me->query_skill("kuihua-mogong",1) + 9999);
    me->set_skill("bluesea-force", me->query_skill("bluesea-force",1) + 9999);
    me->set_skill("shanggu-mijing", me->query_skill("shanggu-mijing",1) + 9999);
	me->set_skill("tianrenheyi", me->query_skill("tianrenheyi",1) + 9999);
	me->set_skill("wanmo-futi", me->query_skill("wanmo-futi",1) + 9999);
	me->set_skill("buddhism", me->query_skill("buddhism",1) + 9999);
	me->set_skill("force", me->query_skill("force",1) + 9999);
	me->set_skill("dodge", me->query_skill("dodge",1) + 9999);
	me->set_skill("unarmed", me->query_skill("unarmed",1) + 9999);
	me->set_skill("cuff", me->query_skill("cuff",1) + 9999);
	me->set_skill("strike", me->query_skill("strike",1) + 9999);
	me->set_skill("finger", me->query_skill("finger",1) + 9999);
	me->set_skill("hand", me->query_skill("hand",1) + 9999);
	me->set_skill("claw", me->query_skill("claw",1) + 9999);
	me->set_skill("sword", me->query_skill("sword",1) + 9999);
	me->set_skill("blade", me->query_skill("blade",1) + 9999);
	me->set_skill("staff", me->query_skill("staff",1) + 9999);
	me->set_skill("hammer", me->query_skill("hammer",1) + 9999);
	me->set_skill("club", me->query_skill("club",1) + 9999);
	me->set_skill("whip", me->query_skill("whip",1) + 9999);
	me->set_skill("parry", me->query_skill("parry",1) + 9999);

me->add("dajif",10000000);
me->add("balance",1000000000000);
me->add("yuanbao",100000000);
me->add("tianji1",100000000);
me->add("jifeng",100000000);
me->add("potential",10000000000);

	me->add("str",999);
	me->add("int",999);
	me->add("con",999);
	me->add("dex",999);
	me->add("per",999);
	me->add("kar",999);
	me->add("max_neili",10000000);
	me->add("max_jingli",10000000);
	me->add("max_jing",10000000);
	me->add("max_qi",10000000);
	me->add("gain/damage",1000);
	me->add("gain/2ap",1000);
	me->add("gain/2dp",1000);
	me->add("gain/break",1000);
	me->add("gain/armor",1000);
	me->add("max_food",1000);
	me->add("max_water",1000);
	me->add("combat_exp",100000000000);
	
	ob = new("clone/GMwupin/GMSSS11");
    ob->set_amount(1);
	ob->move(me);
	write("�ɹ�����GM��Ȩ!�����˺��ѱ��GM�˺�!\n");
        tell_object(me,HIW"�����ˣ�\n" +
        999 + "���ǡ�\n"+
        999 + "������\n"+
        999 + "���ԡ�\n"+
        999 + "����\n"+
        999 + "��ò��\n"+
        999 + "��Դ��\n"+
        10000000 + "�������ޡ�\n"+
        10000000 + "�������ޡ�\n"+
        10000000 + "�������ޡ�\n"+
        10000000 + "��Ѫ���ޡ�\n"+
        10000000 + "�������ޡ�\n"+
        10000000 + "ˮ�����ޡ�\n"+
        1000 + "�����˺���\n"+
        1000 + "����ֵ��\n"+
        1000 + "����ֵ��\n"+
        1000 + "����ֵ��\n"+
        1000 + "�Ƽ�ֵ��\n"+
        9999 + "�������ɾ����ȼ�\n" +
        9999 + "�������������ȼ�\n" +
        9999 + "�������ɾ����ȼ�\n" +
        9999 + "��̫ʼ�۾����ȼ�\n" +
        9999 + "������������ȼ�\n" +
        9999 + "��̫Ԫ�۾����ȼ�\n" +
        9999 + "�����Ͻ������ȼ�\n" +
        9999 + "��̫�ܵ۾����ȼ�\n" +
        9999 + "���Ϲ��ؾ����ȼ�\n" +
        9999 + "���������ܡ��ȼ�\n" +
		9999 + "������ħ�����ȼ�\n" +
		9999 + "����սʥ�����ȼ�\n" +
		9999 + "����ѧ�������ȼ�\n" +
        9999 + "�������ķ����ȼ�\n" +
        9999 + "�������񹦡��ȼ�\n" +
        9999 + "������ħ�����ȼ�\n" +
        9999 + "���Ϻ��������ȼ�\n" +
		9999 + "������ʥ�����ȼ�\n" +
        9999 + "�������񹦡��ȼ�\n" +
        1000 + "����Ϊ\n" +
		100 + "��Ǳ��\n" +		
        10 + "��ƽ�\n" +		
        10 + "����ʯ\n" +		
        10 + "����ʯ\n" +		
		10 + "���ȯ\n" +
        10 + "�����\n" +		
		1 + "�� �������ɵ�\n" +
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
