
inherit "/inherit/room/house_base";

void create()
{
    set("short", "�������");
    set("long", @LONG
һƬ������Ұ�г��������֣����ɸߴ�ֱͦ��֦Ҷϡ�裬�ּ���
��С·���Ѵ�Խ��ͨ��Զ����һƬլԺ�ڲ�������֮�ڣ�����ȥ�ƺ�
��ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "east" : "/d/houjianji/shulin2",
    ]));

    set("outdoors", "houjianji");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
