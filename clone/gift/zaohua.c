
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "�컯��" NOR, ({ "zaohua", "dan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ�ų��˻�����۵ĵ�ҩ��\n");
                set("value", 100);
		set("unit", "��");
		set("only_do_effect", 1);
                set("suit_point",500);
	}
}

int do_effect(object me)
{
        int effect;
	 mapping my;

        log_file("static/using", sprintf("%s(%s) eat �컯�� at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);

        write(HIM "ͻȻһ���ھ����ܿ��ƴ����屬��������"NOR"\n");
        
	me->add("magic_points", 1000 + random(1000));

	write(HIY "��������þ���Ϊ֮һ��"NOR"\n");
        destruct(this_object());
	return 1;
}

