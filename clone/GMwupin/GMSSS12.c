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
	set_name(HIR"���Ϲ��ؾ���", ({"sgmjs book"}));	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 100);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "��");
		set("base_weight", 1);
		set("base_value", 100);
		set("long"," �����Ϲ����������������������������أ�\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");
if(me->query_skill("shanggu-mijing") > 999)
			return notify_fail("��ȼ�̫�����Ѿ��޷������ˡ�\n");
		else {
	me->set_skill("shanggu-mijing", me->query_skill("shanggu-mijing",1) + 999);
	write(YEL"��ѧ�����Ϲ��ؾ���"NOR"\n");
	write(YEL"�����Ϲ����������������������������أ�"NOR"\n");
	
	add_amount(-1);
        return 1;}
}