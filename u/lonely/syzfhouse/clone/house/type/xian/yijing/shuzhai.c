// dongxiang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "��ի");
    set("long", @LONG
����������ƽ�ض���д�ֵĵط����ɾ��������ķ��ı���������İ�
���������档
LONG);

    set("exits",
    ([
        "west"  : __DIR__"houting",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
