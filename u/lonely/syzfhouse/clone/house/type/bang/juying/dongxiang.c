// dongxiang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "����");
    set("long", @LONG
һ��λ�ڶ�����᷿��
LONG);

    set("exits",
    ([
        "west"  : __DIR__"zhongting",
        "south" : __DIR__"dongting",
        "north" : __DIR__"dongwo",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
