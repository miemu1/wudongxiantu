
inherit "/inherit/room/house_base";

void create()
{
    set("short", "�Ϻ�����");
    set("long", @LONG
�������Ϻ�ˮ���������������̡��������¿ɼ��Ϻ��컷�⡣
��������������������ɴ����˿�������߲�Զ����һ�����߷�ǽ��
ո�´�Ժ�������ǽ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "south"  : "/d/fuzhou/nanhu1",
    ]));

    set("outdoors", "fuzhou");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
