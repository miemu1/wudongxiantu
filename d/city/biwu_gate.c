#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_look(string arg);

void create()
{
    set("short", HIY"�������"NOR);
        set("long", @LONG
����һ����ɫ�����ȣ�������һ�����������ȣ���ͷ���Ǳ����
�����䶯��;�Ķ�������ͨ����̨����һ���ߵͣ�����������䶯��;������
�����е�ʥ�ء�����ܹ�����ʮ����ֽ�񣬸������������������
����
LONG );

    set("no_fight",1);
    set("no_beg",1);
    set("no_steal",1);

    set("exits", ([
        "north" : "/d/city/biwu_road",
        "south" : "/d/city/wudao1",
    ]));

    set("no_clean_up", 0);
	set("coor/x", -60);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
        mapping conditions;
        object *inv;
 
        if (dir != "north") return 1;

        if (mapp(conditions = me->query_condition()))
               return notify_fail("�Բ����������״�����ã����ܽ��룡\n");

        if( me->query("eff_qi")<me->query("max_qi") )
               return notify_fail("�Բ��������Ѫ�����ˣ����ܽ��룡\n");

        if( me->query("eff_jing")<me->query("max_jing") )
               return notify_fail("�Բ�����ľ��������ˣ����ܽ��룡\n");

        inv = deep_inventory(me);
        for (i = 0; i < sizeof(inv); i++)
        {
                if (! userp(inv[i])) continue;
                tell_object(me, "�㱳����˭�����������£�\n");
                return 0;
        }

        inv = 0;
        return 1;
}