
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ɽ����");
    set("long", @LONG
��ɽ����Ϊ����һ�������˴�λ����ɽ��ɽ��֮�£�һ����᫵�
ɽ·�������ۣ�ͨ��Զ���ô��һƬլԺ������ȥ�ƺ�������ɽ����
���������������ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "east" : "/d/dali/xishan-lu",
    ]));

    set("outdoors", "dali");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
