
inherit "/inherit/room/house_base";

void create()
{
    set("short", "����");
    set("long", @LONG
�����Ǻ�����ʮ����ĺ�̲����Ҳ���ס���ĿԶ������������
���������֡�ϸ����˻��Ĵ���ɳ�أ��������졣̲��һ��֮�أ���
һ����Ժ�䣬�ƺ��ǽ������ĸ�����פ�����ڡ�
LONG);

    set("exits",
    ([
        "north"  : "/clone/room/matou/dg",
    ]));

    set("outdoors", "beijing");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
