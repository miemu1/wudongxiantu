// xixiang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "����");
    set("long", @LONG
һ��λ��������᷿��
LONG);

    set("exits",
    ([
        "east"  : __DIR__"zhongting",
        "south" : __DIR__"xiting",
        "north" : __DIR__"xiwo",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
