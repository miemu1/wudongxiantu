
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ɽ����");
    set("long", @LONG
��·�ش��ɲԣ�����������͸�룬ƽ���˲��ٵ�����֮��������
���У��ɼ�һ��΢΢¡���ɽ�𣬵�������֮Ի��ɽ��ɽ����������
�ô��һƬլԺ������ȥ�ƺ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "north"  : "/d/linan/gushan-jiao",
    ]));

    set("outdoors", "linan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
