
inherit "/inherit/room/house_base";

void create()
{
    set("short", "������ܢ");
    set("long", @LONG
������ܢ��Ϊ�տ������޶��ٽ���������Ҳ����ϡ�١��ٵ�֮��
ȴ��һ����·�����������ף�·�ľ�ͷ�кô�һƬլԺ������ȥ�ƺ�
��ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "east"  : "/d/wuxi/qiao4",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
