
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ƽ·��");
    set("long", @LONG
��ƽ·���ϣ�ֱ���������š�·��ʮ�ֵظɾ������Ž������˵�
���ϻ�����Ȼһ����Ҳ�������������Ǿ��ùֺ����ġ�·����������
�źô��һƬլԺ������ȥ�ƺ���ĳ������פ�����ڡ�
LONG);

    set("exits",
    ([
        "east"  : "/d/fuzhou/qingping-lu",
    ]));

    set("outdoors", "fuzhou");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
