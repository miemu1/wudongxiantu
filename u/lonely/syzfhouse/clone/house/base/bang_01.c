
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ɽ����");
    set("long", @LONG
�˴�λ�ڻ�ɽ�������࣬ɽ·�������ۣ���ɽ���ɴ�Լ�����ܻ�
�ݳɴԣ�����ïʢ��������ӳ�䣬�����ɼ��кô�һƬլԺ���ƺ���
ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "west"  : "/d/wuxi/shanlu",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
