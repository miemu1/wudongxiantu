// Room: /tangmen/zhongxin.c

inherit ROOM;

void create()
{
        set("short", "�Ƽ�������");
        set("long",
"�������Ƽ���������ģ�һ���ܿ����Ĺ㳡��������ʯ���档������\n"
"���˴������ŵĵ��ӣ������������ԭ���̼��������һЩС��������\n"
"�����ڣ�����һƬ������������ͨ���Ƽ���ĸ�����֡�\n"
);
        set("no_sleep_room",1);
        set("outdoors", "����");
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"edajie",
                "south" : __DIR__"ndajie",
                "west"  : __DIR__"xdajie",
                "north" : __DIR__"bdajie1",
        ]));
        set("objects", ([
                __DIR__"npc/shangren" : 1,
                __DIR__"npc/dizi" : 1,
                __DIR__"npc/boy" : 1,
        ]));
        setup();
}

