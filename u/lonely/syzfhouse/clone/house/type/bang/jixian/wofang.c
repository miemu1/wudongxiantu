// wofang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "�Է�");
    set("long", @LONG
�����ǰ�����ʿ��Ϣ���Է���
LONG);

    set("exits",
    ([
        "north" : __DIR__"houyuan",
        "south" : __DIR__"xiaoting",
    ]));

    set("sleep_room", 1);
    set("no_fight", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
