
inherit "/inherit/room/house_base";

void create()
{
    set("short", "ɽ������");
    set("long", @LONG
������ľ���죬�������󣬵����徲���ڡ�ɽ�߷����������д�
�У��Ծ���������ʱ�����������ʱ��Ϫˮ������ʱ���Ұ�Ÿ裬
ʱ�������ſգ���ʱ��ͬ�������һ��ׯԺ�������ǽ������ĸ���
���פ�����ڡ�
LONG);

    set("exits",
    ([
        "east"  : "/d/qingcheng/xionger-shan",
    ]));

    set("outdoors", "qingcheng");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
