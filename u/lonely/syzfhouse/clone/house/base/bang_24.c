
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ʯƺ");
    set("long", @LONG
��������ɽ·���һ��ƽ̨����ƽ̹�Ĵ�С��ʯƴ�ն��ɡ�ʯ��
ͦ���������أ�����ż������Ъ�ŵĽ�����ˡ�һ���峺���׵�С
Ϫ��ƺǰ�ƹ�����������ƺ��ĺ��ׯԺ��ǰ���������ǽ�����ĳ��
����פ�����ڡ�
LONG);

    set("exits",
    ([
        "north"  : "/d/emei/qing-shijie1",
    ]));

    set("outdoors", "emei");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
