
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��༯����");
    set("long", @LONG
����λ�ں�༯�ϲ�һ������ϡ�ٵ��ĳ�С��֮�ڣ����ܾۼ���
�ܶ����լ�����������š��ֵ����໮�ֳ���һ�����ĵؿ飬������
���ص�Ӣ�ۺ������ڴ�������լ��Ժ��
LONG);

    set("exits",
    ([
        "west"  : __DIR__"houjianji_02",
        "east"  : __DIR__"houjianji_04",
        "south" : __DIR__"houjianji_07",
        "north" : "/d/houjianji/xiaoxiang3",
    ]));

    set("outdoors", "houjianji");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}
