
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��Ȫɽ´");
    set("long", @LONG
��������Ȫɽ·���������߿���ͨ��ɽ�еĺ���̶������ȥ����
������ʯ���Թ���·�Բ��һ�����Ǻܳ���С������ͷ�кô��һƬ
լԺ������ȥ�ƺ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "south" : "/d/yunnan/hl-road1",
        "north" : "/d/yunnan/hl-tan",
    ]));

    set("outdoors", "yunnan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
