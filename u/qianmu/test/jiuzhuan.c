// jiuzhuan.c ��ת��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "��ת��" NOR, ({ "jiuzhuan jindan2", "dan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�Ž�ɫ��"ZJURL("cmds:eat jiuzhuan jindan")ZJSIZE(20)"�ɵ�"NOR"����˵��̫���Ͼ�"
			    "�����������鵤��ҩ����������������ԡ�\n");
		set("spectxt", "��������������ԡ�\n");
		set("unit", "��");
		set("value", 5000000);
		set("no_sell", 1);
        set("no_put",1);
        set("do_no_clean_me", 1);
        set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        CHANNEL_D->do_channel(me, "chat",i + "������!\n");
    }
    me->unconcious();
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }