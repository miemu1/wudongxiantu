// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "ǰ��");
    set("long", @LONG
����������ӭ�Ӱ˷����͵ĵط����󷲿������ݼ����ˣ��ٲ�������
�ﺮ���𻰣��˾���Ľ֮�顣�����������һ���᷿��
LONG);

    set("exits",
    ([
        "east"  : __DIR__"dongxiang",
        "west"  : __DIR__"xixiang",
        "south" : __DIR__"qianyuan",
        "north" : __DIR__"huayuan",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");
    set("resource/water", "��ˮ");
    setup();
    restore();
}
