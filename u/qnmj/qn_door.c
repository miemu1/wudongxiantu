#include <ansi.h>
inherit ITEM;

void create()
{
                
        set_name(HIY"����Ǳ��"NOR, ({ "qn1 door","door"}) );
        set_weight(99999);
        set("no_sun",1);
set("value", 5000);
set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"�������ڿ��Խ������Ǳ�ܡ�(enter door)\n"NOR); 
                set("long","��սÿ����Ҫ100��ȯ"ZJURL("cmds:enter door")ZJSIZE(15)""HIR"����"NOR"��Ϊ��ͽ���������ѧ���� > 400��!\n");
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

	if (me->query("combat_exp")<1000000) 
             return notify_fail("�����Ϊ����һ����,��ȥ�����ˡ�\n");
	if (me->query_skill("martial-cognize", 1) < 200)
             return notify_fail("��ѧ��������400,�޷����롣\n");
	if (me->query("suit_jifeng")<10) 
             return notify_fail("��ĵ�ȯ����,�޷����롣\n");
	//if (me->query("gongji")<30) 
            // return notify_fail("��Ĺ�������,�޷����롣\n");

	

        me->add("suit_point", -(100));
        me->add("gongji", -(30));
        this_player()->delete_temp("maze");
        time = this_player()->query_temp("maze/time")+180-time();
        if(time>0)
                return notify_fail("�㻹��Ҫ��"+CHINESE_D->chinese_period(time)+"���ܽ��븱����\n");
        MAZE_D->enter_maze(this_player(), "qnmj");
        return 1;
}

