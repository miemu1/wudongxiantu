
inherit "/inherit/room/house_base";

void create()
{
    set("short", "�����ָ���");
    set("long", @LONG
��������λ�ھ���֮�ϣ��������ڴ�ֵĶ������ֵ����໮����
�ܶ�ؿ飬�����Ը��صĴ󸻺����ڴ�������լ��Ժ����ʯ���̾͵�
��·��Ϊ������ɨϴ�ù�ɼ��ˡ�·��������������ӳ������һ
������լ���Եð��������š�
LONG);

    set("exits",
    ([
        "south" : "/d/beijing/yongding-dongjie4",
        "west"  : __DIR__"beijings_05",
    ]));

    set("outdoors", "beijing-s");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}
