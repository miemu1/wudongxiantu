// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "������");
    set("long", @LONG
�����ǰ�����ʿ̽���书�ĵط���
LONG);

    set("exits",
    ([
        "west"  : __DIR__"xiaoting",
        "north" : __DIR__"dongxiang",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
