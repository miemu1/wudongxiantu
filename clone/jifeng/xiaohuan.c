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
	set_name(HIM"С����"NOR, ({"xiaohuan dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("value", 100000);
		set("jifeng", 12);
                set("no_sell",1);
				set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("unit", "��");
		set("long","����һ��С������"ZJURL("cmds:fu xiaohuan dan")ZJSIZE(22)"����"NOR"֮��������10��������Ϊ��ע�������������ã����ܳ���������������ޡ�\n");
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
	
	if (arg!="xiaohuan dan")
      		return notify_fail("��Ҫ����ʲô��\n");  

        if (me->query("max_neili") > me->query_neili_limit())
      		return notify_fail("���Ѿ�����ʹ��С����������������Ϊ�ˡ�\n"); 
 
	me->add("max_neili", 10);

        message_vision(me->query("name")+"����һ��"HIM"С����"NOR"���پ�����������"NOR"\n",me);
		
	add_amount(-1);
	return 1;
}
