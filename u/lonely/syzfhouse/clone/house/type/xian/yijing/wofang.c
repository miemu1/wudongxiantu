// wofang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "�Է�");
    set("long", @LONG
�������˵����ң���ʰ�þ����������ƿ��������Կ�������Ļ�԰��
�������ᵽ�����㣬�ǳ���⡣
LONG);

    set("exits",
    ([
        "down"  : __DIR__"houting",
    ]));

    set("sleep_room", 1);
    set("no_fight", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");

    setup();
    restore();
}
