
inherit "/inherit/room/house_base";

void create()
{
    set("short", "ɽ��");
    set("long", @LONG
��������ڲ����Сɽ�ȣ������ұڹ�ʯ��ᾣ�����ֲ����Զ��
����ɽ������ǧ�Ⱥɽ������嶥��ѩ�������겻��������ɽ����
��ɽ����һ����Ժ�����������ǽ������ĸ�����פ�����ڡ�
LONG);

    set("exits",
    ([
        "east"  : "/d/kunlun/kunlun-shankou",
    ]));

    set("outdoors", "kunlun");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
