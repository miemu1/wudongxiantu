// xiaoyuan.c

inherit "/inherit/room/house_door";

void create()
{
    set("short", "����");
    set("long", @LONG
��ǰһƬ��լԺ����ͷ����������ɡ����������Ÿ��ǾžŰ�ʮһ
ֻ��ͭ������ڴ�Ļ�ͷ�ſ۷������ϡ����Ժ������ʯʨ������צ����
�Ʋ��������߰�ԫ���ߣ�Ժǽ���ѣ���֪ռ���ж���Ķ��
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
    set("max_laodu", 6000);
    set("now_laodu", 6000);

    setup();
    restore();
}
