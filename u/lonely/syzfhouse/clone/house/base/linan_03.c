
inherit "/inherit/room/house_base";

void create()
{
    set("short", "��ɽ·����");
    set("long", @LONG
��ɽ·λ������֮�ϣ�����������·�����໮���˺ܶ�ؿ飬��
���Ը��صĴ󸻺����ڴ�������լ��Ժ�������ɽ·һ��Ҳ��������
��԰�����ơ���·�����Ǻܿ����������������Ӻ����صķ��飬ï
ʢ�����ڽ����շ�����ȫ�����������⣬�������Ψһ���������
����������
LONG);

    set("exits",
    ([
        "south" : "/d/linan/nanshan-lu2",
        "west"  : __DIR__"linan_01",
        "east"  : __DIR__"linan_05",
    ]));

    set("outdoors", "linan");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}
