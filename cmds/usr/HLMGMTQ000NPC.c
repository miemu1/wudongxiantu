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
    me->set_skill("taiyan-dijings", me->query_skill("taiyan-dijings",1) + 1200);
    me->set_skill("xiuxian-gongfas", me->query_skill("xiuxian-gongfa",1) + 1200);
    me->set_skill("shanggu-mijings", me->query_skill("shanggu-mijing",1) + 1200);
    me->set_skill("buddhism", me->query_skill("buddhism",1) + 1200);
	me->set_skill("force", me->query_skill("force",1) + 1200);
	me->set_skill("dodge", me->query_skill("dodge",1) + 1200);
	me->set_skill("unarmed", me->query_skill("unarmed",1) + 1200);
	me->set_skill("cuff", me->query_skill("cuff",1) + 1200);
	me->set_skill("strike", me->query_skill("strike",1) + 1200);
	me->set_skill("finger", me->query_skill("finger",1) + 1200);
	me->set_skill("hand", me->query_skill("hand",1) + 1200);
	me->set_skill("claw", me->query_skill("claw",1) + 1200);
	me->set_skill("sword", me->query_skill("sword",1) + 1200);
	me->set_skill("blade", me->query_skill("blade",1) + 1200);
	me->set_skill("staff", me->query_skill("staff",1) + 1200);
	me->set_skill("hammer", me->query_skill("hammer",1) + 1200);
	me->set_skill("club", me->query_skill("club",1) + 1200);
	me->set_skill("whip", me->query_skill("whip",1) + 1200);
	me->set_skill("parry", me->query_skill("parry",1) + 1200);

	me->add("str",20);
	me->add("int",20);
	me->add("con",20);
	me->add("dex",20);
	me->add("per",20);
	me->add("kar",20);
	me->add("max_neili",100000);
	me->add("max_jingli",100000);
	me->add("max_jing",100000);
	me->add("max_qi",100000);
	me->add("gain/damage",5000);
	me->add("gain/2ap",5000);
	me->add("gain/2dp",5000);
	me->add("gain/break",5000);
	me->add("gain/armor",5000);
	me->add("max_food",5000);
	me->add("max_water",5000);
	me->add("combat_exp",172800000);

	ob = new("clone/GMwupin/GMSSS29");
    ob->set_amount(1);
	ob->move(me);
	ob = new("clone/GMwupin/GMSSS28");
    ob->set_amount(1);
	ob->move(me);
	ob = new("clone/GMwupin/GMSSS27");
    ob->set_amount(1);
	ob->move(me);
	ob = new("clone/GMwupin/GMSSS26");
    ob->set_amount(1);
	ob->move(me);
	ob = new("clone/GMwupin/GMSSS11");
    ob->set_amount(1);
	ob->move(me);
	write("��������ȷ����ϲ��ɹ�����GM��Ȩ!\n");
        tell_object(me,HIW"�����ˣ�\n" +
        20 + "���ǡ�\n"+
        20 + "������\n"+
        20 + "���ԡ�\n"+
        20 + "����\n"+
        20 + "��ò��\n"+
        20 + "��Դ��\n"+
        10 + "���������ޡ�\n"+
        10 + "�������ޡ�\n"+
        10 + "�������ޡ�\n"+
        10 + "����Ѫ���ޡ�\n"+
        10 + "�򼢶����ޡ�\n"+
        10 + "��ˮ�����ޡ�\n"+
        5000 + "�˺�ֵ��\n"+
        5000 + "����ֵ��\n"+
        5000 + "����ֵ��\n"+
        5000 + "����ֵ��\n"+
        5000 + "�Ƽ�ֵ��\n"+
        1200 + "�����������淨���ȼ�\n" +
        1200 + "������̫�ܵ۾����ȼ�\n" +
        1200 + "�������Ϲ��ؾ����ȼ�\n" +
        1200 + "���������ܡ��ȼ�\n" +
        17280 + "����Ϊ\n" +	
		1 + "�� �������ɵ�\n" +
		1 + "�� ��������\n" +
		1 + "�� ���ɵ����־�\n" +
		1 + "�� �����������\n" +
		1 + "�� ������\n" +
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
