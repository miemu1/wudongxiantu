// wofang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "�Է�");
    set("long", @LONG
һ��СС���Է���
LONG);

    set("exits",
    ([
        "south" : __DIR__"xiaoyuan",
    ]));

    set("sleep_room", 1);
    set("no_fight", 1);
    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
