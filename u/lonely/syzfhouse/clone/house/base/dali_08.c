inherit "/inherit/room/house_base";

void create()
{
    set("short", "���Ͻ�����");
    set("long", @LONG
����λ�����Ͻ��ϵ��±�סլ����������������������������
�������ֵ�������������Ϊ���ţ����׶����ʡ����Žֵ������˲���
�ؿ飬�����Ը��صĴ󸻺����ڴ�������լ��Ժ��
LONG);

    set("exits",
    ([
        "east"  : __DIR__"dali_07",
        "north" : __DIR__"dali_06",
    ]));

    set("outdoors", "dali");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}