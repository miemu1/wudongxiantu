// shenliwan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "Ǳ�ܹ�ʵС" NOR, ({ "dan", "wan"}) );
        set_weight(200);
		set("no_drop", "�������������뿪�㡣\n");
		set("no_give", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�㡣\n");
		set("no_put", "�������������뿪�㡣\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ԲԲ�������裬��˵���˿�������Ǳ�ܡ�\n");
                set("xy_money", 1);

                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
int b,lvl;
lvl=me->query("level");
b= 400000+random(50000) + (400000+random(50000)*lvl)/10;
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
if (me->query("potential") < me->query_potential_limit() && me->query_skill("martial-cognize", 1) >= 400)	
{
	
      me->add("potential", b);
	tell_object(me, HIC "\n������" + chinese_number(b) + "��Ǳ�ܡ�"NOR"\n");
     destruct(this_object());
	      return 1;
	 }
             tell_object(me, HIC "\n�� ��ѧ��������400���������Ǳ������"NOR"\n");
        destruct(this_object());
        return 1;
}

