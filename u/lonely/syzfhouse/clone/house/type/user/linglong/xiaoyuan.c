// xiaoyuan.c

inherit "/inherit/room/house_door";

void create()
{
    set("short", "СԺ");
    set("long", @LONG
һ�������Ժ�ӣ�����Ժ�Ӿ���һ��С�ݣ����Ž����š�
LONG);

    set("exits",
    ([
//        "north"  : __DIR__"wofang",
        "out"    : __FILE__,
    ]));

    set("owner_name", "ĳ��");
    set("owner", "OWNER");
    set("huyuan", __DIR__"huyuan");
    set("outdoors", "OUTDOORS");
    set("set_exits", "north");
    set("set_entry", "wofang");
    set("max_laodu", 500);
    set("now_laodu", 500);

    setup();
    restore();
}
