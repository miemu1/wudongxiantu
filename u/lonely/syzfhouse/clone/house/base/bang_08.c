
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ʤɽ��");
    set("long", @LONG
���������ݵĶ����Ž��⣬���򶫱�ͨ���ʤɽ�ˡ������￴ȥ
ɽ��ɽ����ľ�����ر�ïʢ��ƽʱ����ϡ�١����������źô��һƬ
լԺ������ȥ�ƺ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "southeast" : "/d/city/jiaowai",
    ]));

    set("outdoors", "city");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
