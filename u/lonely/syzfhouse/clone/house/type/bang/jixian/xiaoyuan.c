// xiaoyuan.c

inherit "/inherit/room/house_door";

void create()
{
    set("short", "����");
    set("long", @LONG
��ǰһƬլԺ����ͷ��Լ���ɣ����������Ÿ��ǰ˰���ʮ��ֻ��ͭ
������ڴ�Ļ�ͷ�ſ۷������ϡ�����ʯʨ������צ���������ˡ����߰�
ԫ���ߣ�Ժǽ���ѣ���֪ռ���ж���Ķ��
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
    set("set_entry", "wuchang");
    set("max_laodu", 3000);
    set("now_laodu", 3000);

    setup();
    restore();
}
