#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "����" NOR, ({ "liqi wan", "wan"}) );
	set_weight(200);
      set("suit_point", 100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ�ž�˵���˿��Լ��������ĵ�ҩ��\n");
                set("value", 10000);
		set("unit", "��");
		set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("total_hatred") < 0)
        {
                message_vision("$Nգգ�ۡ�\n", me);
                tell_object(me, "�������ҩûɶζ���������绨���óԡ�\n");
        return 0;
        } 
        if (me->query("total_hatred") > 49)
        {
                me->add("total_hatred", -50);
                 write("\n "+HIR+"��ϲ�㣺"+NOR+HIG+"��������50�㣡���� "+NOR);
        }else
        {
                tell_object(me, "��������ú���ûʲô���á�\n");
        }
        destruct(this_object());
	return 1;
}
