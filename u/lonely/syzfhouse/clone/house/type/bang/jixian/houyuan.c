// houyuan.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "��Ժ");
    set("long", @LONG
һ���еȹ�ģ�ĺ�Ժ��
LONG);

    set("exits",
    ([
        "south" : __DIR__"wofang",
    ]));

    set("outdoors", "OUTDOORS");
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
