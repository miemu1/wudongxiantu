inherit "/inherit/room/house_base";

void create()
{
    set("short", "���Ͻ��Һ�");
    set("long", @LONG
����λ�����Ͻ��ϵ��±�סլ����������������������������
�������ֵ�������������Ϊ���ţ����׶����ʡ����Žֵ������˲���
�ؿ飬�����Ը��صĴ󸻺����ڴ�������լ��Ժ��
LONG);

    set("exits",
    ([
        "east"  : __DIR__"dali_01",
        "north" : __DIR__"dali_04",
        "south" : "/d/dali/zhennan-jie2",
    ]));

    set("outdoors", "dali");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}