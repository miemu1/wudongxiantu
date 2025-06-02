#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
void create()
{
	set_name(HIR"���� �� �� �ԡ�"NOR, ({"zhengdao jian book"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 9500000);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "��");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","���� �� ֤ ����\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+name()+"��\n");

	me->set_skill("liuyue-jian", me->query_skill("liuyue-jian",1) + 180);//��Ӱ���½�
	me->set_skill("canxin-jian", me->query_skill("canxin-jian",1) + 180);//���Ľ�
	me->set_skill("lonely-sword", me->query_skill("lonely-sword",1) + 180);//���¾Ž�
	me->set_skill("xuantie-jian", me->query_skill("xuantie-jian",1) + 180);//��������"
	me->set_skill("chuixue-jian", me->query_skill("chuixue-jian",1) + 180);//���촵ѩ����
	
	write(YEL"�˼���ص���ѧΪ���׺���֮������ѧ"NOR"\n");
	
	add_amount(-1);
	return 1;
}