
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��������");
    set("long", @LONG
����������һ��������ֱ�Ĵ����ͨ�򱱾������Զ����·�ϵ�
��ɫ�Ե���ɪ����࣬���ǽ�������������ס���ͷ�����Ϸ�������
���������Ǹߴ�ĳ�ǽ����¥��������һƬլԺ������ȥ�ƺ���ĳ��
����פ�����ڡ�
LONG);

    set("exits",
    ([
        "east" : "/d/shanhai-guan/guandao1",
    ]));

    set("outdoors", "beijing");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
