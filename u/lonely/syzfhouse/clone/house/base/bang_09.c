
inherit "/inherit/room/house_base";

void create()
{
    set("short", "������");
    set("long", @LONG
�˴�λ�ڲ������ⲻԶ��������ԭ����������ߣ���ɽ������
�򡣵�����������������ţ�����������ɲ�����һ��ƬլԺ������
ȥ�ƺ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "west" : "/d/ruzhou/cang-dong",
    ]));

    set("outdoors", "ruzhou");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
