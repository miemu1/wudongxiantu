
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ͤ���Һ�");
    set("long", @LONG
����ʵ��һ���ȽϿ�����ӣ������ڽ��Ͼͽ�������ˣ�·�ϵ�ʯ
�嶼�����̵ģ��ȸɾ���ƽ���������߶�����լ��
LONG);

    set("exits",
    ([
        "west"  : __DIR__"wuxi_01",
        "north" : __DIR__"wuxi_04",
        "south" : "/d/wuxi/huangting-xi2",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}
