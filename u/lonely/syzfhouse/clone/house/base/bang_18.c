
inherit "/inherit/room/house_base";

void create()
{
    set("short", "ɽ��ƽ̨");
    set("long", @LONG
������ɽ·�Ա���һƬ����ƽ̨��վ��������Ը���˫�����ȫ
�����ع�ͷȥ����������������ɽ�����֪������ɽ���������ˡ���
��������ʱ����֮��ѩ��ƽ̨�ڲ���һ���ֺ�լԺ��������ĳ�����
��פ�ء�
LONG);

    set("exits",
    ([
        "east"  : "/d/baituo/guangchang",
    ]));

    set("outdoors", "baituo");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
