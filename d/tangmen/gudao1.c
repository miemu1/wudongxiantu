//gudao1.c

inherit ROOM;
void create()
{
        set("short","�ŵ�");
        set("long",
"һ��ʯ��ŵ���������ľ�Դ䣬ɽ��ƽ�����������Ƽ����С���֡�\n"
"Զ����һƬ��ΰ������һ�������ĺ�ǽ������Խ��ǽͷ�ɼ�һ����¥��\n"
"�������������������ŵ���¥��\n"
);
        set("outdoors", "����");
        set("exits",([ 
            "west"    : __DIR__"gudao2",
            "southdown"    : __DIR__"ximenroad2",
			 "east"    : "/d/tangmen/jingji/enter",
        ]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
        ]));
        setup();
        replace_program(ROOM);
}

