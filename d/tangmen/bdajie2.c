// Room: /tangmen/bdajie2.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",
"һ����ֱ�Ĵ���ʯ�ֵ���ֱͨ���ţ�����û��ʲô���̣�ֻ����¶�\n"
"��Ӱ�Ӱ������㡣�˴�һ�߾Ϳɴ��������ˣ�û��ǣ�ҵ����һ·ƽ����\n"
"��Ҫ�Լ����С���ˡ�һ·���أ�\n"
);
        set("outdoors", "����");
        set("no_clean_up", 0);
        set("exits", ([
                "north" : "/d/xuedao/sroad1",
                "south" : __DIR__"bdajie1",
        ]));

        setup();
        replace_program(ROOM);
}

