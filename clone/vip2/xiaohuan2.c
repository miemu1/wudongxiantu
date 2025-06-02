#include <ansi.h>
inherit COMBINED_ITEM;
int do_use(string arg);
string query_autoload()
 { return query_amount() + ""; }

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
	set_name(HIM"�󻹵�S"NOR, ({"xiaohuan danS"}));
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("value", 100000);
		set("yuanbao", 888);
        set("no_sell",1);
		set("unit", "��");
		set("long","����һ�Ŵ󻹵���"ZJURL("cmds:fu xiaohuan danS")ZJSIZE(22)"����"NOR"֮��������1000��������Ϊ��ע�������������ã����ܳ���������������ޡ�\n");
	    set("base_weight", 200);
	}
	setup();
}

void init()
{
    if (environment()==this_player())
    	add_action("do_use","fu");
}

int do_use(string arg)
{
	object me=this_player();
	object ob1;
    int times;
    mixed *local,*last;
	
	if (arg!="xiaohuan danS")
      		return notify_fail("��Ҫ����ʲô��\n");  

        if (me->query("max_neili") > me->query_neili_limit())
      		return notify_fail("���Ѿ�����ʹ�ô󻹵�S������������Ϊ�ˡ�\n"); 
 
	me->add("max_neili", 1000);

        message_vision(me->query("name")+"����һ��"HIM"�󻹵�S"NOR"���پ�����������"NOR"\n",me);
		
	add_amount(-1);
	return 1;
}
