
inherit "/inherit/room/house_base";

void create()
{
    set("short", "�������");
    set("long", @LONG
����ͨ���ɶ��Ĵ����֮�࣬·���Ƿ��ֵ�������Ÿ��ָ���
��ׯ�ڣ������ܿ���ũ�����������ڵĹ���������ң���������ɼ���
һ��ƬլԺ������ȥ�ƺ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "northeast" : "/d/sichuan/yidao1",
    ]));

    set("outdoors", "sichuan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
