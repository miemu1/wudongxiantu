inherit "/inherit/room/house_base";

void create()
{
    set("short", "���Ͻֱ���");
    set("long", @LONG
����λ�����Ͻ��ϵ��±�סլ����������������������������
�������ֵ�������������Ϊ���ţ����׶����ʡ����Žֵ������˲���
�ؿ飬�����Ը��صĴ󸻺����ڴ�������լ��Ժ��
LONG);

    set("exits",
    ([
        "west"  : __DIR__"dali_04",
        "south" : __DIR__"dali_01",
    ]));

    set("outdoors", "dali");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}