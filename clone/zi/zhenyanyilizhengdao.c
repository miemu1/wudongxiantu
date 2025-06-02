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
	set_name(HIR"��֤ �� �� �ԡ�"NOR, ({"zhengdao li book"}));
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

	me->set_skill("huagu-mianzhang", me->query_skill("huagu-mianzhang",1) + 180);//��������
	me->set_skill("fireice-strike", me->query_skill("fireice-strike",1) + 180);//���溮����
	me->set_skill("doomstrike", me->query_skill("doomstrike",1) + 180);//��������
	me->set_skill("chongyang-shenzhang", me->query_skill("chongyang-shenzhang",1) + 180);//��������

	
	write(YEL"������ص�������ѧ����Ͷ���һ����ʽ�����һ����ѧ��������������"NOR"\n");
	
	add_amount(-1);
	return 1;
}