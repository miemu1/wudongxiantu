inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIC"������"NOR, ({"zbei card"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000000);
		set("tongbao", 600);
		set("jifeng", 10000);
                set("no_sell",1);
		set("unit", "��");
		set("no_give",1);
		 set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);
		set("only_do_effect", 1);
		set("long","��������һ�ű����Ӵ󿨣�"ZJURL("cmds:use zengrong card")ZJSIZE(20)"ʹ��"NOR"֮�����������������200��!\n");
		set("spectxt", "ʹ�ú󱳰���������������ٸ�\n");
	}
}
/*
void init()
{
    if (environment()==this_player())
    	add_action("do_use","duihuan");
}
*/
//int do_use(string arg)

int do_effect(object me)
{
	me=this_player();

	//if (arg!="zengrong card")
      	//	return notify_fail("��Ҫʹ��ʲô?\n");  

	//if ( me->query("zengrong"))
      		//return notify_fail("���Ѿ�ʹ�ù���������!\n");  

        me->set("zengrong",200);
	write(YEL"ʹ�óɹ�����ı�������������200��"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }