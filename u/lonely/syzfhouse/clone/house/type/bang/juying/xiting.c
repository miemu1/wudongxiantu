// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "������");
    set("long", @LONG
���ǰ����Ͱ�����Ҫ������������֮�������Ų������Ρ�
LONG);

    set("exits",
    ([
        "east"  : __DIR__"xiaoting",
        "north" : __DIR__"xixiang",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
