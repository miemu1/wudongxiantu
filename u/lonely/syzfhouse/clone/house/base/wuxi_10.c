
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ͤ�ֹ��");
    set("long", @LONG
����ʵ��һ���ȽϿ�����ӣ������ڽ��Ͼͽ�������ˣ�·�ϵ�ʯ
�嶼�����̵ģ��ȸɾ���ƽ���������кô�һƬլԺ���ƺ���ĳ�����
��פ�����ڡ�
LONG);

    set("exits",
    ([
        "east"  : "/d/wuxi/huangting-nanjie",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
