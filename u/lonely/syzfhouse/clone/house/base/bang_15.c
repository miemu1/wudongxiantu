
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ɽ�嶫");
    set("long", @LONG
���Ż�ɽ���ڵ���ʯ·һֱ�򶫣��߳����СС���䲻��Զ��ȴ
�����кô�һƬլԺ�����ڴˣ�����ȥ�ƺ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "northwest" : "/d/village/eexit",
    ]));

    set("outdoors", "village");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
