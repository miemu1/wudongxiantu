
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ͤ�ֶ���");
    set("long", @LONG
����ʵ��һ���ȽϿ�����ӣ������ڽ��Ͼͽ�������ˣ�·�ϵ�ʯ
�嶼�����̵ģ��ȸɾ���ƽ���������߶�����լ��
LONG);

    set("exits",
    ([
        "west"  : __DIR__"wuxi_03",
        "south" : __DIR__"wuxi_02",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}
