// xiaoyuan.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "���䳡");
    set("long", @LONG
һ��ƽ���ĳ��أ��ǰ��е�������ĵط���
LONG);

    set("exits",
    ([
        "south" : __DIR__"xiaoyuan",
        "north" : __DIR__"xiaoting",
    ]));

    set("owner_name", "ĳ��");
    set("owner", "OWNER");
    set("outdoors", "OUTDOORS");

    setup();
    restore();
}
