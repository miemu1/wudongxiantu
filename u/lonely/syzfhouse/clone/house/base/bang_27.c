
inherit "/inherit/room/house_base";

void create()
{
    set("short", "ɽ��");
    set("long", @LONG
����������ɽ֮����һ��ɽ�£����ϳ������޺�ɫ�Ĳ�֪����Ұ
�������۵ķ���Ǵس�һ����æµ�š�������ɽ����һ���ֺ��Ժ��
�ƺ��ǽ������ĸ�����פ�����ڡ�
LONG);

    set("exits",
    ([
        "east"  : "/d/shaolin/xiaojing1",
    ]));

    set("outdoors", "shaolin");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
