// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "����");
    set("long", @LONG
�����ǰ����д��˷����͵ĵط���
LONG);

    set("exits",
    ([
        "east"  : __DIR__"dongting",
        "west"  : __DIR__"xiting",
        "south" : __DIR__"wuchang",
        "north" : __DIR__"zhongting",
    ]));

    set("objects", __DIR__"board");

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");
    set("resource/water", "��ˮ");

    setup();
    restore();
}
