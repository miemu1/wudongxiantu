// xixiang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "�ٷ�");
    set("long", @LONG
������������������֮�������ڳ�����Ϊ�򵥣�һ����������ٵʣ�
��һ�Ƿ�����¯��
LONG);

    set("exits",
    ([
        "east"  : __DIR__"houting",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
