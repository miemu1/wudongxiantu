
inherit "/inherit/room/house_base";

void create()
{
    set("short", "����ɽ��");
    set("long", @LONG
������������ɽ���ؽ磬һ��ɽ������ͨ��ɽ���������У�����
�·��ܿ���Ρ����������������һƬլԺ��ӳ�ڵ��Ե����ּ䣬����
ȥ�ƺ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "northwest" : "/d/quanzhen/shanjiao1",
    ]));

    set("outdoors", "quanzhen");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
