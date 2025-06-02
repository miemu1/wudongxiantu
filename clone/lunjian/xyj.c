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
	set_name(HIR"��������", ({"xuanyin"}));	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10);
		set("coin", 1);
        set("base_unit", "��");    
		set("no_drop",1); 
		set("no_give",1);
        set("no_get",1);	
		set("no_steal",1);		
		set("base_weight", 10);
		set("gongxian",5000);
		set("long",HIW"����һ����������������ʹ�á�\n");
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

	me->set_skill("xuanyin-jian",360);
        

	write(HIW"������360+����������"NOR+HIG"��л���Ĵ���֧�֣�ף����Ϸ��죡"NOR"\n");

    return 1;
}
