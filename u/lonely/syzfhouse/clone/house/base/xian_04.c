//��������ޡ�������Աὡ����
inherit "/inherit/room/house_base";

void create()
{
    set("short", "СԱ�");
    set("long", @LONG
�˵ؾ��������쳣��������ȥ�������ز��ɴ䣬����ܷܷ���滨
��������ˮ����������ϣ�����ּ䡣��������¹�ɺ���û������
�����������ѡ�Զ��̨ͤ¥�����֣���������ʱ�ţ���Ȼ�����˼���
LONG);

    set("exits",
    ([
        "east" : "/d/city/sanxian-zhuang",
    ]));

    set("outdoors", "city");
    set("max_build", 2);
    set("can_build", "xian");

    setup();
    restore();
}
