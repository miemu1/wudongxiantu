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
        "out"    : __FILE__,
    ]));

    set("owner_name", "ĳ��");
    set("owner", "OWNER");
    set("huyuan", __DIR__"huyuan");
    set("outdoors", "OUTDOORS");
    set("set_exits", "north");
    set("set_entry", "xiaoting");
    set("max_laodu", 1000);
    set("now_laodu", 1000);

    setup();
    restore();
}
