inherit "/inherit/room/house_base";

void create()
{
    set("short", "���Ͻּ���");
    set("long", @LONG
����λ�����Ͻ��ϵ��±�סլ����������������������������
�������ֵ�������������Ϊ���ţ����׶����ʡ����Žֵ������˲���
�ؿ飬�����Ը��صĴ󸻺����ڴ�������լ��Ժ��
LONG);

    set("exits",
    ([
        "east"  : __DIR__"dali_05",
        "south" : __DIR__"dali_08",
        "north" : "/d/dali/zhennan-jie2",
    ]));

    set("outdoors", "dali");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}