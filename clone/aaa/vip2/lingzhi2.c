inherit COMBINED_ITEM;
#include <ansi.h>
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
	set_name(HIM"С����[��]"NOR, ({"xiaohuan dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100000);
		set("yuanbao", 20);
        set("no_sell",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1); 
        set("base_weight", 10);
        set("base_value", 100);
        set("base_unit", "��");
		set("unit", "��");
		set("long","����һ��С����������֮��������10��������Ϊ��ע�������������ã����ܳ���������������ޡ�\n");
		set("only_do_effect", 1);
	}
   setup();
}

do_effect(object me)
{
	object ob1;
    int times;

	
    if (me->query("max_neili") > me->query_neili_limit())
      		return notify_fail("���Ѿ�����ʹ��С����������������Ϊ�ˡ�\n"); 
 
	me->add("max_neili", 10);
    message_vision(me->query("name")+"����һ��"HIM"С����"NOR"���پ�����������"NOR"\n",me);
	add_amount(-1);
	return 1;
}
