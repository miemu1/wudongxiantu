// wofang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "�Է�");
    set("long", @LONG
����ƫ�������һ���Է����ǰ��е�����Ϣ֮����
LONG);

    set("exits",
    ([
        "west"  : __DIR__"wofang",
        "south" : __DIR__"dongxiang",
    ]));

    set("sleep_room", 1);
    set("no_fight", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
