
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ͤ�ֱ���");
    set("long", @LONG
����ʵ��һ���ȽϿ�����ӣ������ڽ��Ͼͽ�������ˣ�·�ϵ�ʯ
�嶼�����̵ģ��ȸɾ���ƽ���������߶�����լ��
LONG);

    set("exits",
    ([
        "south" : __DIR__"wuxi_01",
        "east"  : __DIR__"wuxi_04",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}
