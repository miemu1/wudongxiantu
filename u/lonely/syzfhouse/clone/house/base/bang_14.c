
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ɽ����");
    set("long", @LONG
������ɽ�����С��·һֱ���У�������ȳ��ߵĴ�ͷ��ȴ����
�кô�һƬլԺ�����ڴˣ�����ȥ�ƺ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "east" : "/d/shanhai-guan/chundao3",
    ]));

    set("outdoors", "shanhai-guan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
