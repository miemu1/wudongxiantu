#include <ansi.h>
inherit ITEM;

void create()
{

        set_name(HIY"�ػ���"NOR, ({ "qinhuang door","door"}) );
        set_weight(99999);
        set("no_sun",1);
set("value", 5000);
set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"�������ڿ��Խ����ػ��ꡣ(enter door)\n"NOR);
                set("long","��սÿ����Ҫ300����300����"ZJURL("cmds:enter door")ZJSIZE(15)""HIR"����"NOR"��Ϊ��ͽ�������all sk > 150��!\n");
                set("unit", "��");
                set("lore",1);
        }
        setup();
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        int time;
        object me = this_player();
        if (arg!="door")
                return 0;
	if (me->query("score")<300)
             return notify_fail("��Ľ�������̫��,�޷����롣\n");
	if (me->query("combat_exp")<1000000)
             return notify_fail("�����Ϊ�������,��ȥ�����ˡ�\n");
	if (me->query("weiwang")<300)
             return notify_fail("��Ľ�������̫��,�޷����롣\n");

        me->add("score", -(300));
        me->add("weiwang", -(300));
        this_player()->delete_temp("maze");
        time = this_player()->query_temp("maze/time")+180-time();
        if(time>0)
                return notify_fail("�㻹��Ҫ��"+CHINESE_D->chinese_period(time)+"���ܽ��븱����\n");
        MAZE_D->enter_maze(this_player(), "qhl");
        return 1;
}

