//gudao2.c

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
            "northwest"    : __DIR__"tmdamen",
            "east"    : __DIR__"gudao1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
