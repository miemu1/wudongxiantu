// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "����");
    set("long", @LONG
һ��СС�Ŀ�����
LONG);

    set("exits",
    ([
        "south" : __DIR__"xiaoyuan",
        "north" : __DIR__"wofang",
        "west"  : __DIR__"xixiang",
        "east"  : __DIR__"dongxiang",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");
    set("resource/water", "��ˮ");

    setup();
    restore();
}
