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
	set_name(HIR"���� �� �� �ԡ�"NOR, ({"zhengdao diyu book"}));
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
		set("long","��������˵��\n");
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

	me->set_skill("badao", me->query_skill("badao",1) + 180);//�����ɾ�
	me->set_skill("lunhui-sword", me->query_skill("lunhui-sword",1) + 180);//�ֻؽ�
	me->set_skill("yinyangjiuzhuanshierchongtian", me->query_skill("yinyangjiuzhuanshierchongtian",1) + 280);//̫ʼ�۾�
	me->set_skill("wanmo-futi", me->query_skill("wanmo-futi",1) + 180);//̫Ԫ�۾�

	
	write(YEL"һ������ĺ������ӱ�����������"NOR"\n");
	
	add_amount(-1);
	return 1;
}