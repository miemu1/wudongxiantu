inherit "/inherit/room/house_base";

void create()
{
    set("short", "���Ͻָ���");
    set("long", @LONG
����λ�����Ͻ��ϵ��±�סլ����������������������������
�������ֵ�������������Ϊ���ţ����׶����ʡ����Žֵ������˲���
�ؿ飬�����Ը��صĴ󸻺����ڴ�������լ��Ժ��
LONG);

    set("exits",
    ([
        "west"  : __DIR__"dali_08",
        "north" : __DIR__"dali_05",
    ]));

    set("outdoors", "dali");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}