#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "��Ԫ��" NOR, ({ "ju yuan", "dan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ�ų�����������������伢�ĵ�ҩ��\n");
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
      me->add("food", 5000);
      me->add("water", 5000);
      write("\n "HIR"�㲻�ٸе�������ڿʡ�"NOR);
     destruct(this_object());
	return 1;
}
