
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��������");
    set("long", @LONG
�µ����������ߣ����Ż��Ǻ���һ�����ɫ����ʯ�̾͵�С·
����ǰ�У�Զ����Լ�ɼ��кô��һƬլԺ������ȥ�ƺ���ĳ�����
��פ�����ڡ�
LONG);

    set("exits",
    ([
        "west"  : "/d/wuxi/qiao3",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
