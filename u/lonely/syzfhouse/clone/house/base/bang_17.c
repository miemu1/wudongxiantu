
inherit "/inherit/room/house_base";

void create()
{
    set("short", "̫ƽ��");
    set("long", @LONG
�˴�λ��̫ƽ�򱱽�֮�⣬ƽ�ճ���ϡ�١��˼�������ϡ�����
�ּ���ӳ�źô��һƬլԺ���ƺ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "south"  : "/d/wudang/caishi",
    ]));

    set("outdoors", "wudang");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
