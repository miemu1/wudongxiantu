
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ɽ·�Һ�");
    set("long", @LONG
��ɽ·λ������֮�ϣ�����������·�����໮���˺ܶ�ؿ飬��
���Ը��صĴ󸻺����ڴ�������լ��Ժ�������ɽ·һ��Ҳ��������
��԰�����ơ���·�����Ǻܿ����������������Ӻ����صķ��飬ï
ʢ�����ڽ����շ�����ȫ�����������⣬�������Ψһ���������
����������
LONG);

    set("exits",
    ([
        "north" : "/d/linan/nanshan-lu1",
        "east"  : __DIR__"linan_04",
    ]));

    set("outdoors", "linan");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}
