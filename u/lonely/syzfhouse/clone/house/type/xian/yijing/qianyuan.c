// xiaoyuan.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "ǰԺ");
    set("long", @LONG
�����ƺ��ǳ�����������ʱ��ʱ����������������ĽС�Ժ�в�����
ľ��Ȼ������֮�ƣ����·ǳ���
LONG);

    set("exits",
    ([
        "south" : __DIR__"xiaoyuan",
        "north" : __DIR__"qianting",
    ]));

    set("owner_name", "ĳ��");
    set("owner", "OWNER");
    set("outdoors", "OUTDOORS");

    setup();
    restore();
}
