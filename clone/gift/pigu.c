#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "�ٹȵ�" NOR, ({ "pigu dan", "dan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ�ž�˵����һ�겻���ĵ�ҩ��\n");
		set("no_drop", "�������������뿪�㡣\n");
		set("no_put",1);
		set("no_sell",1);
		set("no_save",1);
		set("no_give",1);
		set("nopaimai",1);
                set("value", 100);
		set("unit", "��");
		set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("food") > 1000)
        {
                message_vision("$Nգգ�ۡ�\n", me);
                tell_object(me, "�������ҩûɶζ���������绨���óԡ�\n");
        return 0;
        } 
        if (me->query("water") > 1000)
        {
                tell_object(me, "��������ú���ûʲô���á�\n");
        return 0;
        }
      me->add("food", 10000);
      me->add("water", 10000);
      write("\n "+HIR+"��ϲ�㣺"+NOR+HIG+"��ʱ�������ˣ����� "+NOR);
     destruct(this_object());
	return 1;
}
