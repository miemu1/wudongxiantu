// wofang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "��԰");
    set("long", @LONG
������λ����ͥ�Ļ�԰����ֲ������������ĺ�����ɽ�󴨵��滨
��ݣ������ǳ���
LONG);

    set("exits",
    ([
        "north" : __DIR__"houting",
        "south" : __DIR__"qianting",
    ]));

    set("outdoors", "OUTDOORS");
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
