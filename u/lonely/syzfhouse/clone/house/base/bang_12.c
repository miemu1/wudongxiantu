
inherit "/inherit/room/house_base";

void create()
{
    set("short", "���п���");
    set("long", @LONG
���п�������ʮ��ϡ�٣����澭���пڶ��У���ͨ���ذ�������
�֣�ͬ��Ҳ���˼�������һƬ���ɲ�����լԺ�����ڴˣ�����ȥ�ƺ�
��ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "south" : "/d/beijing/beishi-kou",
    ]));

    set("outdoors", "beijing");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
